

#ifndef __header
  #define _pc_lisp_read2_c
#endif

#ifndef _pc_lisp_read2_h
  #define _pc_lisp_read2_h
  #define __header

#ifdef __header

// HEADER

#include "pc-lisp-mem.c"
#include "pc-lisp-gc.c"
#include "pc-lisp-pair.c"
#include "pc-lisp-test.c"
#include "pc-lisp-print.c"
#include "pc-lisp-adt.c"

#include <wchar.h>

#define CR       ( '\n' )
#define TAB      ( '\t' )
#define ESC      ( '\\' )
#define SP       ( ' '  )
#define HASH     ( '#'  )
#define DOT      ( '.'  )
#define APOS     ( '\'' )
#define BACK     ( '`' )
#define AT       ( '@' )
#define COMMA    ( ',' )
#define QUOTE    ( '"'  )
#define SEMI     ( ';'  )
#define NUL      ( '\0' )
#define BUF_SIZE ((1<<8)-1)  //make 2^N-1 for efficiency

#define EOL          MAKE_CHR( ')' )
#define EOP          MAKE_CHR( DOT )
#define END          MAKE_CHR( EOF )

enum {POS=1, NEG=-1};

extern int     line;             // line being processed
extern int     pos;              // character on line
extern char    buf[BUF_SIZE+1];  // input buffer for nicer error messages
//extern wchar_t    buf[BUF_SIZE+1];  // input buffer for nicer error messages
extern int     nextc;            // my own ungetch storage
extern int     next2c;
extern char   *reads;            // reading from this string if not NULL
extern char   *readp;            // cursor for reads
//extern wchar_t   *reads;            // reading from this string if not NULL
//extern wchar_t   *readp;            // cursor for reads

extern FILE  *in;  // added for (load ...)

extern ATOM    kw_quote, kw_lambda, kw_closure;
extern ATOM    kw_primitive, kw_exit;
extern ATOM    kw_define, kw_set;
extern ATOM    kw_read, kw_load, kw_eval, kw_eval1, kw_eval_macro, kw_apply;
extern ATOM    kw_if, kw_cond;
extern ATOM    kw_progn;
extern ATOM    kw_display, kw_print;
extern ATOM    kw_cons, kw_list;

       void    _strcpy( char *d,char *s,int n );
       void    _strncpy( char *d,char *s,int n );

extern ATOM    tag_env;
static int   (*readch)();
       int     readchNormal();
       int     readchString();
static int     getch();
static void  (*ungetch)( int c );
static void    ungetchNormal( int c );
static void    ungetchString( int c );
static int     getSYMch();
static ATOM    readSYM     ();
//static ATOM    readSYMc    ( int c );
static int     reuse_str( char *buf,int len );
static int     getSTRch();
static ATOM    readSTR     ();
static int     getNUMch();
static ATOM    readNUM     ( int m,int c );
static int     getCOMch();
static ATOM    readCOM     ();
static int     getCHRch();

//static void readExit( char *m );
static ATOM    readLST     ();
static ATOM    readSYMorNUM( int c );
       ATOM    read        ();
static ATOM    read_raw    ();
static ATOM    read_token  ();
static ATOM    readQUOTE   ();
static ATOM    let_star_to_let( ATOM kvps,ATOM body );
       ATOM    eval_macros( ATOM exp );
       ATOM    readString( char *s );

// END HEADER

#endif

#if defined(_pc_lisp_read2_c)

// CODE

int    line              = 1;     // track lines
int    pos               = 0;
char   buf[BUF_SIZE+1]   = "";    // buffer input for nicer error mssages
//wchar_t   buf[BUF_SIZE+1]   = "";    // buffer input for nicer error mssages
int    nextc             = 0;
int    next2c            = 0;
char  *reads             = NULL;  // reading from this string
char  *readp             = NULL;  // reading cursor for reads
//wchar_t  *reads             = NULL;  // reading from this string
//wchar_t  *readp             = NULL;  // reading cursor for reads
ATOM   kw_quote          = NIL;
ATOM   kw_lambda         = NIL;
ATOM   kw_closure        = NIL;
ATOM   kw_primitive      = NIL;
ATOM   kw_exit           = NIL;
ATOM   kw_define         = NIL;
ATOM   kw_set            = NIL;
ATOM   kw_read           = NIL;
ATOM   kw_load           = NIL;
ATOM   kw_eval           = NIL;
ATOM   kw_eval1          = NIL;
ATOM   kw_eval_macro     = NIL;
ATOM   kw_apply          = NIL;
ATOM   kw_if             = NIL;
ATOM   kw_cond           = NIL;
ATOM   kw_progn          = NIL;
ATOM   kw_display        = NIL;
ATOM   kw_print          = NIL;
ATOM   kw_cons           = NIL;
ATOM   kw_list           = NIL;

ATOM   tag_env           = NIL;
 
// readString sets these to readchString and ungetchString
static int  (*readch)()         = readchNormal;
static void (*ungetch)( int c ) = ungetchNormal;

FILE  *in;  // added for (load ...)

// FIXME: put something like this back

#define READEXIT( pred,mess,atom ){                                       \
  if ( pred ){                                                            \
        /*FILELINE;/**/                                                   \
    fprintf( stderr,"\nRead error: %s on input string at position %d.\n", \
            mess,(int)(readp-reads) );                                    \
    fprintf( stderr,"%s\n",reads );                                      \
    fprintf( stderr,"%*s\n",(int)(readp-reads+2),"^" );                  \
    exit(1);                                                              \
  }                                                                       \
}

#define READWARN( pred,mess,atom ){                                       \
  if ( pred ){                                                            \
        /*FILELINE;/**/                                                   \
    fprintf( stderr,"\nRead warning: %s on input string at position %d.\n", \
            mess,(int)(readp-reads) );                                    \
    fprintf( stderr,"%s\n",reads );                                      \
    fprintf( stderr,"%*s\n",(int)(readp-reads+2),"^" );                  \
  }                                                                       \
}

/*
void readExit(char *m){
  if ( reads!=NULL ){                 // if reading from a string
    fprintf(stderr, "\nRead error: %s on input string at position %d.\n",
            m, (int)(readp-reads));
    fprintf(stderr, "%s\n",  reads);
    fprintf(stderr, "%*s\n", (int)(readp-reads+2), "^");
    exit(1);
  }
  fprintf(stderr, "\nRead error: %s on line %d position %d.\n", m, line, pos);
  fprintf(stderr, "%.*s\n", pos & BUF_SIZE, buf);
  fprintf(stderr, "%*s\n",  pos & BUF_SIZE, "^");
  exit(1);
}
*/


int readchNormal(){
  int c;
  c = nextc;                                    // assume an ungetted char
  if ( c==0 ){                                  // wrong assumption
    c = fgetc( in );  // changed for (loa ...) c = getchar();
    if ( c==EOF ) return c;
    if ( c==CR  ) { line++; pos=0; return c; }  // track lines and position
  }
  else{
    nextc = next2c;  // we support 2 ungetted chars
    next2c = 0;
  }           
  pos++;
  //fputc( c,stderr );  // does not print CR or EOF
  //if ( c<0 || c>127 ) fprintf( stderr,"%c[%3d]  ",c,c );
  return c;
}

int readchString(){
  int c = *readp;  
  if ( c==0 ) return EOF;  // fake an EOF if end of string
  readp++;
  //fputc( c,stderr );     // does not print EOF
  return c;
}

void ungetchNormal( int c ){
  READEXIT( next2c!=0,"Can't ungetch more than 2 characters",NIL );
  next2c = nextc;
  nextc = c;
}

void ungetchString( int c ){
  READEXIT( readp==reads,"Can't ungetch - have not read anything",NIL );
  if ( c==EOF ) return;     // no need to ungetch a EOF
  readp--;                  // wind string pointer back 1
}

int getch(){
  int c;
  while ( ( c=readch() ) ){  // clang bug fixed
    //fputc( c,stderr );
    if ( c>=SP || c==CR || c==TAB || c==EOF )  return c;
  }
  READEXIT( TRUE,"NUL not expected",NIL );  // clang bug fixed
  return NUL;
}

ATOM read_token(){
  int c;
  SKIP:
  c = getch();
  //fputc( c,stderr );        // print leading token character
  //if ( c<0 || c>127 ) fprintf( stderr,"%c[%3d]  ",c,c );
  if ( c==EOF )            return make_chr(EOF);
  if ( c=='(' )            return make_chr(c);
  if ( c<=SP  )            goto   SKIP;            // skip whitespace
  if ( c==')' )            return make_chr(c);     // end-of-list
  //if ( c=='@' )            return readCON();       // constant
  if ( c==HASH ){
    int c2 = getch();                           // test next character
    if ( c2==ESC )         return make_chr( getCHRch() );
    if ( c2=='t' )         return TRU;
    if ( c2=='f' )         return FAL;
    // other special values go here
    ungetch(c2);                                   // put back for symbol
    ungetch(c);
    return readSYM();
  }
  if ( c>='0' && c<='9' )  return readNUM(POS,c);
  if ( c=='-' || c=='+' )  return readSYMorNUM(c);
  if ( c==DOT ){                                   // DOT or symbol
    int c2 = getSYMch();                           // test next character
    if ( c2<=SP )          return make_chr(DOT);   // DOT
    ungetch(c2);                                   // put back for symbol
    ungetch(c);
    return readSYM();
  }
  if ( c==QUOTE )          return readSTR();       // "get\ string\n"
  if ( c==SEMI ){
    c = getCOMch();
    if ( c==DOT )          return make_chr(EOF);   // ;. means force EOF
    ungetch(c);  // bug: missing to ate next character. if \n, it ate next line!!!
    readCOM();
    goto SKIP;
  }         
  if ( c==APOS )           return make_chr(APOS);
  if ( c==BACK )           return make_chr(BACK);
  if ( c==COMMA )          return make_chr(COMMA);
  ungetch(c);              // put back since readSYM accepts escape codes
  return readSYM();        // anything else is a symbol
}

// FIXME: is this a read macro? no
ATOM readQUOTE(){
  ATOM atm = read();  // was read_raw();
  ATOM lst = cons( atm,NIL );
  ATOM res = cons( kw_quote,lst );
  return res;
}



/*
ATOM read_raw(){
  ATOM t = read_token();
  if ( is_eq( t,make_chr(EOF) ) )   return t;
  if ( is_sym(t) )                  return t;
  if ( is_num(t) )                  return t;
  if ( is_str(t) )                  return t;
  if ( is_eq( t,make_chr(APOS) ) )  return readQUOTE();  // FIXME: can this be macro?
  if ( is_eq( t,make_chr('(') )  )  return readLST();
  if ( is_eq( t,make_chr(')') )  )  return t;
  if ( is_eq( t,make_chr(DOT) ) )   return t;
  if ( is_chr(t) )                  return t;
  if ( is_con(t) )                  return t;  // for constants
  EXIT( "What is that?",t );
  return NIL;
}
*/

ATOM read(){
  ATOM t = read_token();
      //PEEK( "",t );  
      //_mem_print_used_pairs( "gEnv",gEnv,_global_save );

  if ( is_eq( t,make_chr(EOF) ) )   return t;
  if ( is_sym(t) )                  return t;
  if ( is_num(t) )                  return t;
  if ( is_str(t) )                  return t;
  if ( is_eq( t,make_chr(APOS) ) )  return readQUOTE();  // FIXME: can this be macro?
  if ( is_eq( t,make_chr('(') )  )  return readLST();  //eval_macros( readLST() );
  if ( is_eq( t,make_chr(')') )  )  return t;
  if ( is_eq( t,make_chr(DOT) ) )   return t;
  if ( is_chr(t) )                  return t;
  if ( is_con(t) )                  return t;  // for constants
  READEXIT( TRUE,"What is that?",t );
  return NIL;
}

/*
(define space #\ )
#\space ->#\ 
if len >1 lookup symbol 
*/
/*
UTF-8
1 byte: 0xxxxxxx 128   0-127          ASCII
Continuation bytes: 
        10xxxxxx  64 128-191 -128--65 never first
2 byte: 110xxxxx  32 192-223  -64--33
3 byte: 1110xxxx  16 224-239  -32--17
4 byte: 11110xxx   8 240-247  -16- -9 defined but RFC3629 stops at 10FFFF
5 byte: 111110xx   4 248-251   -8- -5 defined but not for RFC3629
6 byte: 1111110x   2 252-253   -4- -3 defined but not for RFC3629
7 byte: 11111110     254       -2     available but not used
8 byte: 11111111     255       -1     available but not used

EOF = -1 which is not UTF-8

*/

int getCHRch(){
  int c = readch();
  if ( c>=SP  )          return c;
  READEXIT( TRUE,"Illegal chararacter name '\\'",make_chr(c) );
}

/*
get name
if lebgth 1 -> ch
else lookup
ATOM readCHR(){
  ATOM sym = readSYM();  // FIXME: make special readNAM
  if 
  ATOM a = assoc( sym );
  int i=0, c, l;
  // exit if EOF
  while ( c=getCHRch() , c>0 ){
    symbols[freeSym].name[i++] = c;
    EXITIF( i==(SYM_LEN-1),"Symbol too long",NIL );
    l = c;
  }
  c = getch();
  EXITIF( c<0,"EOF",NIL );
  
  if ( c!=EOF ) ungetch(-c);
  if ( i==1 ){            // FIXME: 1-3 chars in a short symbol?
    return make_sym(-l);  //use char instead of symbol
  }
  //if ( c!=EOF ) ungetch(-c);
  return reuse_sym();
}
*/

void _strcpy( char *d,char *s,int n ){
  int i = 0;
  while( s[i]!=(char) 0 ){
    d[i] = s[i];
    i++;
  }
  d[i] = s[i];  // EOS
  READEXIT( i+1!=n,"Copied more then n chracters!",make_num(n) );
}

void _strncpy( char *d,char *s,int n ){
  int i;
  for ( i=0;i<n;i++ ){
    d[i] = s[i];
  }
  READEXIT( i!=n,"Copied more then n chracters!",make_num(n) );
}

// FIXME: combine? getDelimitedch(from,first delim,second delim)
int getSYMch(){ // return -char on non symbol except for escaped chars
  int c = readch();
  if ( c==ESC ){
    c = readch();
    if ( c=='n' )        return CR;
    if ( c=='t' )        return TAB;
    if ( c>=SP  )        return c;   // place after n and t
    if ( c==EOF )        return c;
    READEXIT( TRUE,"Illegal escaped char following '\\'",make_chr(c) );
  }
  if ( c>')'  )          return c;   // above )
  if ( c>SP && c<'(' )   return c;   // space to below (
  if ( c==EOF )          return c;   // -1
  return -c;                         // else -c eg. SP, CR, TAB, (, )
}

int getSTRch(){          // return -char on " except for escaped chars
  int c = readch();
  if ( c==ESC ){
    c = readch();
    if ( c=='n' )        return CR;
    if ( c=='t' )        return TAB;
    if ( c>=SP  )        return c;   // place after n and t - includes "
    if ( c==EOF )        return c;
    READEXIT( TRUE,"Illegal escaped char following '\\'",make_chr(c) );
  }
  if ( c>QUOTE )         return c;   // above "
  if ( c>0 && c<QUOTE )  return c;   // space to below "
  if ( c==EOF )          return c;   // -1
  return -c;                         // else -c eg. NUL, "
}

/*
int make_short_string( char *buf,int i ){
  int s = i << (3*8);                 // encode size of short string
  _strncpy( (char *)&s,buf,i );       // copy short string to atom
  return -s;
}
*/

ATOM readSYM(){
  char *buf = strings[0].text;
  int i=0, c;
  while ( c=getSYMch(),c>0 ){
    buf[i++] = (char) c;
    //buf[i] = (char) 0;
    //strings[0].len = i;
    READEXIT( i==(SYM_LEN-1),"Symbol too long",NIL);
  }    
  buf[i] = (char) 0;
  //strings[0].siz = i;
  //wchar_t wbuf[SYM_LEN];
  //strings[0].len = mbstowcs( wbuf,buf,i );
  //strings[0].wid = wcswidth( wbuf,i );
  //if ( strings[0].len!=strings[0].wid ){
  //  fprintf( stderr,"%s:  len=%d  siz=%d  wid=%d\n",
  //                  strings[0].text,
  //                  strings[0].len,
  //                  strings[0].siz,
  //                  strings[0].wid );
  //  exit(1);
  //}
  if ( c!=EOF ) ungetch(-c);
      //PEEK( "",make_num(i) );
  //if ( i<=3 )  return make_sym( make_short_string( buf,i ) );
  return make_sym( reuse_str( buf,i ) );
}

int reuse_str( char *buf,int n ){
  int j;
  for ( j=1 ; j<freeStr ; j++ ){
    if ( strings[j].siz==n && strcmp( strings[j].text,buf )==0 ){
      //fprintf( stderr,"Reused \"%s\"\n",strings[j].text );
      return j;
    }
  }
  freeStr++;
  strings[ j ].text = malloc( n+1 );
  READEXIT( strings[ j ].text==NULL,"malloc returned NULL!",NIL );
  _strcpy( strings[ j ].text,buf,n+1 );
  //strings[ j ].len = len;
  //strings[ j ].len = mbstowcs( NULL,buf,0 );
  //wchar_t wbuf[SYM_LEN];
  strings[j].siz = n;
  strings[j].len = mbstowcs( NULL,buf,0 );
  strings[j].wid = strings[j].len;  // need mbswidth( wbuf );
  /*
  if ( strings[j].siz!=strings[j].wid ){
    fprintf( stderr,"%s:  len=%d  siz=%d  wid=%d\n",
                    strings[j].text,
                    strings[j].len,
                    strings[j].siz,
                    strings[j].wid );
    //exit(1);
  }
  */
  return j;
}

ATOM readSTR(){
  STRING *s = &strings[0];
  char *buf = s->text;  //strings[0].text;  // large string buffer
  int i=0,c;
  while ( c=getSTRch(),c>0 ){         // terminated by NUL or "
    buf[i++] = (char) c;  // added (char) valgrind help
    //s->len = i;
    //buf[i] = (char) 0;  // FIXME: not really required
    READEXIT( i==(STR_LEN-1),"String too long",NIL);
  }
  buf[i] = (char) 0;  // needed to terminate all strings
  //s->len = mbstowcs( NULL,s->text,0 );
      //fprintf( stderr,"%s\n",buf );
      //PEEK( "",make_num(i) );
  //if ( i<=3 )  return make_str( make_short_string( buf,i ) );
  return make_str( reuse_str( buf,i ) );
}

// FIXME: could have signed number read
// read a signed number starting with + or -
ATOM readSYMorNUM(int sign){
  int c=getNUMch();
  if ( c<=0 ){  // not number so must be symbol
    if ( c!=EOF ) ungetch(abs(c));  // put pack if not EOF
    ungetch(sign);
    return readSYM();
  }
  // c is first digit
  if ( sign=='-' ) return readNUM(NEG,c);
  return readNUM(POS,c);
}

int getNUMch(){
  int c = readch();
  if ( c>='0' && c<='9' ) return c;
  if ( c==EOF )           return c;  // -1
  return -c;
}

// read number, m is -1 or 1 for - or + numbers and c is first digit
ATOM readNUM(int m, int c){
  int n=0;
  n=m*(c-'0');
  while (c=getNUMch(), c>0 )
    n = n*10 + m*(c-'0');
  if ( c!=EOF ) ungetch(-c);
  ATOM a=make_num(n);
  return a;
}

int getCOMch(){
  int c;
  while ( ( c=readch() ) )  // clang bug fixed
    if ( c>=SP || c==CR || c==EOF )  return c;
  READEXIT( TRUE,"This character is not allowed in a comment",make_chr(c) );
  return NUL;
}

ATOM readCOM(){
  int c;
  while ( c=getCOMch(),c>=SP );  // really this could be simplified
  return NIL;            // no need to unget terminating CR or EOF
}

/*
(define (readLST)
  (let ((t (read)))
    (cond ( (is_close_paren? t) nil)
          ( (is_dot? t) (let ((cdr (read)) (read) cdr)))
          (else (cons t (readLST)) ))  )
)
*/
ATOM readLST(){
  ATOM t = read();
  if ( is_eq( t,EOL ) )  return NIL;  // got EOL
  if ( is_eq( t,EOP ) ){  // got '.' of pair
    ATOM cdr = read();
    READEXIT( is_eq( cdr,END ),"Got EOF after '.'",NIL );
    READWARN( is_eq( cdr,EOL ),"Got ')' after '.' - assumed ')'",NIL );
    ATOM ignore = read();
    READEXIT( ! is_eq( ignore,EOL ),"Expecting ')' after cdr",cdr );
    //PEEK( "",cdr );
    return cdr;
  }  
  READEXIT( is_eq( t,END ),"Got EOF - expecting ')'",NIL );
  ATOM rest = readLST();
  //PEEK( "",rest );
  ATOM ret = cons( t,rest );
  READEXIT( is_null(ret),"No free pairs for this list or pair",rest );
  //PEEK( "",ret );
  return ret;
}

ATOM readString( char *s ){  // read eval string and return
  reads = readp = s;
  readch = readchString;
  ungetch = ungetchString;
  //PEEK( "",NIL );
  ATOM x = read();
  //PEEK( "",x );
  readch = readchNormal;
  ungetch = ungetchNormal;
  return x;
}

#endif
#endif


