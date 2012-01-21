

#ifndef __header
  #define _pc_lisp_read2_c
#endif

#ifndef _pc_lisp_read2_h
  #define _pc_lisp_read2_h
  #define __header

#ifdef __header

// HEADER

//#include "pc-lisp.h"
#include "pc-lisp-test.c"
#include "pc-lisp-print.c"
#include "pc-lisp-adt.c"

#define CR       ( '\n' )
#define TAB      ( '\t' )
#define ESC      ( '\\' )
#define SP       ( ' '  )
#define HASH     ( '#'  )
#define DOT      ( '.'  )
#define APOS     ( '\'' )
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
extern int     nextc;            // my own ungetch storage
extern int     next2c;
extern char   *reads;            // reading from this string if not NULL
extern char   *readp;            // cursor for reads

extern FILE  *in;  // added for (load ...)

extern ATOM    kw_quote, kw_lambda, kw_closure;
extern ATOM    kw_let, kw_let_star, kw_letrec;
extern ATOM    kw_primitive, kw_exit;
extern ATOM    kw_define, kw_set;
extern ATOM    kw_read, kw_load, kw_eval, kw_eval1, kw_apply;
extern ATOM    kw_if, kw_cond;
extern ATOM    kw_progn, kw_begin, kw_delay ,kw_force;
extern ATOM    kw_display, kw_print;
extern ATOM    kw_cons, kw_list, kw_cons_stream;

extern ATOM    tag_env;
static int   (*readch)();
int     readchNormal();
int     readchString();
static int     getch();
static void  (*ungetch)( int c );
static void    ungetchNormal( int c );
static void    ungetchString( int c );
static int     getSYMch();
static int     getSTRch();
static int     getNUMch();
static int     getCOMch();

//static void readExit( char *m );
static ATOM    readLST     ();
static ATOM    readNUM     ( int m,int c );
static ATOM    readSYMorNUM( int c );
static ATOM    readSYM     ();
//static ATOM    readSYMc    ( int c );
static ATOM    readSTR     ();
static ATOM    readCOM     ();
ATOM    read        ();
static ATOM    read_token  ();
static ATOM    readQUOTE   ();
static ATOM    readCON     ();

// END HEADER
#endif

#if defined(_pc_lisp_read2_c)

// CODE

int    line              = 1;     // track lines
int    pos               = 0;
char   buf[BUF_SIZE+1]   = "";    // buffer input for nicer error mssages
int    nextc             = 0;
int    next2c            = 0;
char  *reads             = NULL;  // reading from this string
char  *readp             = NULL;  // reading cursor for reads
ATOM    kw_quote, kw_lambda, kw_closure;
ATOM    kw_let, kw_let_star, kw_letrec;
ATOM    kw_primitive, kw_exit;
ATOM    kw_define, kw_set;
ATOM    kw_read, kw_load, kw_eval, kw_eval1, kw_apply;
ATOM    kw_if, kw_cond;
ATOM    kw_progn, kw_begin, kw_delay ,kw_force;
ATOM    kw_display, kw_print;
ATOM    kw_cons, kw_list, kw_cons_stream;

ATOM    tag_env;
 
// readString sets these to readchString and ungetchString
static int  (*readch)()         = readchNormal;
static void (*ungetch)( int c ) = ungetchNormal;

FILE  *in;  // added for (load ...)

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
  EXITIF( next2c!=0,"Can't ungetch more than 2 characters",NIL );
  next2c = nextc;
  nextc = c;
}

void ungetchString( int c ){
  EXITIF( readp==reads,"Can't ungetch - have not read anything",NIL );
  if ( c==EOF ) return;     // no need to ungetch a EOF
  readp--;                  // wind string pointer back 1
}

int getch(){
  int c;
  while ( ( c=readch() ) ){  // clang bug fixed
    //fputc( c,stderr );
    if ( c>=SP || c==CR || c==TAB || c==EOF )  return c;
  }
  EXIT( "NUL not expected",NIL );  // clang bug fixed
  return NUL;
}

int getSYMch(){ // return -char on non symbol except for escaped chars
  int c = readch();
  if ( c==ESC ){
    c = readch();
    if ( c=='n' )        return CR;
    if ( c=='t' )        return TAB;
    if ( c>=SP  )        return c;   // place after n and t
    if ( c==EOF )        return c;
    EXIT( "Illegal escaped char following '\\'",make_chr(c) );
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
    EXIT( "Illegal escaped char following '\\'",make_chr(c) );
  }
  if ( c>QUOTE )         return c;   // above "
  if ( c>0 && c<QUOTE )  return c;   // space to below "
  if ( c==EOF )          return c;   // -1
  return -c;                         // else -c eg. NUL, "
}

int getNUMch(){
  int c = readch();
  if ( c>='0' && c<='9' ) return c;
  if ( c==EOF )           return c;  // -1
  return -c;
}


ATOM read_token(){
  int c;
  SKIP:
  c = getch();
  //fputc( c,stderr );        // print leading token character
  if ( c==EOF )            return make_chr(EOF);
  if ( c=='(' )            return make_chr(c);
  if ( c<=SP  )            goto   SKIP;            // skip whitespace
  if ( c==')' )            return make_chr(c);     // end-of-list
  if ( c=='@' )            return readCON();       // constant
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
    readCOM();
    goto SKIP;
  }         
  if ( c==APOS )           return make_chr(APOS);  // quote
  ungetch(c);              // put back since readSYM accepts escape codes
  return readSYM();        // anything else is a symbol
}

ATOM eval_macros( ATOM exp );
// FIXME: no good for (let () (e)) -> ((e)) instead of (e)
ATOM let_star_to_let( ATOM kvps,ATOM body ){
  if ( is_null(kvps) )  return body;
  ATOM exp = let_star_to_let( cdr(kvps),body );
  ATOM kvp = cons( car(kvps),NIL );  // -> ((k v))
  ATOM let = cons( kw_let,cons( kvp,exp ) );
  PEEK( "",let );
  ATOM res = eval_macros( let );
  PEEK( "",res );
  return res;
}

ATOM eval_macros( ATOM exp ){
  // (define (<name> <form>) <body>) -> (define <name> (lambda (<form>) <body>))
  if ( match_taglist( exp,kw_define ) ){
    if ( is_list( _2ND( exp ) ) ){
      PEEK( "found define",exp );
      ATOM name = car( _2ND( exp ) );
      ATOM form = cdr( _2ND( exp ) );
      ATOM body = _Rfrom3( exp );
      ATOM lamb = make_lambda( form,body );
      //ATOM defn = list( kw_define,name,lamb,NIL );
      ATOM defn = cons( kw_define, cons( name,cons( lamb,NIL) ) );
      //peek( "eval_macro: defn",defn );
      return defn;
    }
    //peek( "eval_macro: lst",lst );
  }
  // (let ((x 1) (y 2)) <body>) -> ((lambda (x y) <body>) 1 2)
  if ( match_taglist( exp,kw_let ) ){
    //if ( is_alist( _2ND(exp) ) ){
      PEEK( "found let",exp );
      ATOM form = alist_keys( _2ND(exp) );  // get formal parameter names
      //PEEK( "",form );
      // FIXME: i don't like let's syntax: when read ((a 1) (b 2)) are lists
      // but pair would result in ((a . 1) (b . 2))
      ATOM args = alist_car_vals( _2ND(exp) );  // get arguement expressions
      //PEEK( "",args );
      //ATOM body = _3RD( exp );
      ATOM body = _Rfrom3( exp );
      //PEEK( "",body );
      ATOM lamb = make_lambda( form,body );
      //PEEK( "",lamb );
      ATOM lexp = cons( lamb,args );
      //PEEK( "",lexp );
      return lexp;
    //}
    //peek( "eval_macro: lst",lst );
  }
/*
(let* ((x 1) (y 2)) <body>) -> (let ((x 1)) (let ((y 2)) <body>))
*/
  if ( match_taglist( exp,kw_let_star ) ){
    //if ( is_alist( _2ND(exp) ) ){
      PEEK( "found let*",exp );
      ATOM kvps = _2ND( exp );
      ATOM body = _Rfrom3( exp );
      ATOM res = let_star_to_let( kvps,body );
      return res;
    //}
    //PEEK( "bad let*",exp );
  }
  // (cons-stream a <body>) -> (cons a (delay <body>))
  if ( match_taglist( exp,kw_cons_stream ) ){
    //READ_PEEK( "found cons-stream",exp );
    ATOM body = _Rfrom3( exp );
    ATOM dely = cons( kw_delay,body );
    ATOM args = cons( _2ND(exp),cons( dely,NIL) );
    ATOM res = cons( kw_cons,args );
    return res;
  }
  // (begin <body>) -> (progn <body>))
  if ( match_taglist( exp,kw_begin ) ){
    //READ_PEEK( "found begin",exp );
    ATOM body = _Rfrom2( exp );
    ATOM res = cons( kw_progn,body );
    return res;
  }
//  if ( is_cons_stream( exp ) ){           // exp = (cons a b)
//    ATOM a = eval( _2ND(exp),env );  // (eval a)
//    ATOM b = make_proc( make_lambda( NIL,_3RD(exp) ),env );  // (eval b)
//    RETURN3( cons( a,b ) );
//  }
  return exp;  // no change
}

ATOM read(){
  ATOM t = read_token();
  //PEEK( "",t );  
  //_mem_print_used_pairs( "gEnv",gEnv,_global_save );

  if ( is_eq( t,make_chr(EOF) ) )   return t;
  if ( is_sym(t) )                  return t;
  if ( is_num(t) )                  return t;
  if ( is_str(t) )                  return t;
  if ( is_eq( t,make_chr(APOS) ) )  return readQUOTE();
  if ( is_eq( t,make_chr('(') )  )  return eval_macros( readLST() );
  if ( is_eq( t,make_chr(')') )  )  return t;
  if ( is_eq( t,make_chr(DOT) ) )   return t;
  if ( is_chr(t) )                  return t;
  if ( is_con(t) )                  return t;  // for constants
  EXIT( "What is that?",t );
  return NIL;
}

// common code to reuse already defined symbols - uses freeSym 
ATOM reuse_sym(){
  int i;
  for ( i=1 ; i<freeSym ; i++ ){  // lookup symbol in rest of environment
    if ( strcmp( symbols[i].name,symbols[freeSym].name )==0 ){  // match
      ATOM a = make_sym( i );     // reuse prevous symbol storage
      return a; 
    }
  }
  ATOM a = make_sym( freeSym );   // new symbol
  freeSym++;
  return a;
}

// symbols are imutable
ATOM readSYM(){
  int i=0, c, l;
  while ( c=getSYMch() , c>0 ){         // terminated by whitespace or ()
    symbols[freeSym].name[i++] = c;
    EXITIF( i==(SYM_LEN-1),"Symbol too long",NIL );
    l = c;
  }
  symbols[freeSym].name[i] = (char) 0;  // terminate string with NUL
  if ( c!=EOF ) ungetch(-c);
  if ( i==1 ){            // FIXME: 1-3 chars in a short symbol?
    return make_sym(-l);  //use char instead of symbol
  }
  //if ( c!=EOF ) ungetch(-c);
  return reuse_sym();
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

void _strcpy( char *d,char *s,int n ){
  int i = 0;
  while( s[i]!=(char) 0 ){
    d[i] = s[i];
    i++;
  }
  d[i] = s[i];  // EOS
  EXITIF( i+1!=n,"Copied more then n chracters!",make_num(n) );
}

ATOM readSTR(){
  char buf[STR_LEN];  // large string buffer
  int i=0,c;
  while ( c=getSTRch(),c>0 ){         // terminated by NUL or "
    buf[i++] = (char) c;  // added (char) valgrind help
    //buf[i] = (char) 0;  // FIXME: terminate string with NUL for error message
    EXITIF( i==(STR_LEN-1),"String too long",NIL);
  }    
  buf[i] = (char) 0;  // terminate string with NUL
  int j;  // I reused i!! had to write my own strcpy to find it
  for ( j=1 ; j<freeStr ; j++ ){         // match existing string?
    if ( strcmp( strings[j],buf )==0 ){  // match
      ATOM a = make_str( j );            // reuse prevous string storage
      return a; 
    }
  }
  // new string
  strings[ freeStr ] = malloc( i+1 );        // storage for string
  EXITIF( strings[ freeStr ]==NULL,"malloc returned NULL!",NIL );
  //strcpy( strings[freeStr],buf );       // copy
  _strcpy( strings[ freeStr ],buf,i+1 );       // copy
  ATOM a = make_str( freeStr );           // new string
  freeStr++;
  return a;
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
  EXIT( "This character is not allowed in a comment",make_chr(c) );
  return NUL;
}

ATOM readCOM(){
  int c;
  while ( c=getCOMch(),c>=SP );  // really this could be simplified
  return NIL;            // no need to unget terminating CR or EOF
}

ATOM readCON(){
  int c;
  ATOM a;
  c = getch();
  EXITIF( c==EOF,"Got EOF - need an integer for a constant",NIL );
  if ( c>='0' && c<='9' )   return MAKE_CON( get_num( readNUM( POS,c ) ) );
  if ( c=='-' || c=='+' ){
    a = readSYMorNUM(c);
    //PEEK( "",a );
    if ( get_tag(a)==NUM ){
      ATOM res = MAKE_CON( get_num( a ) );
      //PEEK( "",res );
      return res;
    }
    EXIT( "Digits expected after '+' or '-', got",a );
  }
  EXIT( "Integer expected, got",make_chr(c) );  // FIXME: why exit here?
  ungetch(c);
  ungetch('#');
  ATOM sym = readSYM();
  fprinta( stderr,sym );
  return sym;
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
    EXITIF( is_eq( cdr,END ),"Got EOF after '.'",NIL );
    WARNIF( is_eq( cdr,EOL ),"Got ')' after '.' - assumed ')'",NIL );
    ATOM ignore = read();
    EXITIF( ! is_eq( ignore,EOL ),"Expecting ')' after cdr",cdr );
    //PEEK( "",cdr );
    return cdr;
  }  
  EXITIF( is_eq( t,END ),"Got EOF - expecting ')'",NIL );
  ATOM rest = readLST();
  //PEEK( "",rest );
  ATOM ret = cons( t,rest );
  EXITIF( is_null(ret),"No free pairs for this list or pair",rest );
  //PEEK( "",ret );
  return ret;
}

ATOM readLST_old(){
  ATOM t = read();
  if ( is_eq( t,EOL ) )  return NIL;
  EXITIF( is_eq( t,END ),"Got EOF after '('",NIL );
  ATOM a = cons( t,NIL );     // make cell, x tracks last cell in list 
  ATOM x = a;
  EXITIF( is_null(a),"No cell storage to start this list or pair",a );
  while ( ! is_eq( t=read(),EOL ) ){
    EXITIF( is_eq( t,END ),"Got EOF -need ')' or something",a );
    if ( is_eq( t,EOP ) ){          // got '.' of pair
      t = read();            // get cdr
      EXITIF( is_eq( t,END ),"Got EOF - need cdr of pair",a );
      set_cdr( x,t );
      t = read();     // get EOL
      EXITIF( ! is_eq( t,EOL ),"Need ')' to close list or pair",a );
      return a;
    }  
    ATOM q = cons( t,NIL );  // make pair   
    EXITIF( is_null(q),"No cell storage left for this list",a );
    set_cdr( x,q );  // append new cell to a
    x = q;          // hack to track last cell of this list
  }
  return a;
}
// FIXME: is this a read macro?
ATOM readQUOTE(){
  ATOM atm = read();
  ATOM lst = cons( atm,NIL );
  ATOM res = cons( kw_quote,lst );
  return res;
}

ATOM readString(char *s){  // read eval string and return
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


