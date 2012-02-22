
#ifndef __header
  #define _pc_lisp_mem_c
#endif

#ifndef _pc_lisp_mem_h
  #define _pc_lisp_mem_h
  #define __header

#ifdef __header

// HEADER

#define SIZE     80000       // max size of cell storage
#define SYM_SIZE 10000       // max symbol list size
#define SYM_LEN  32          // max symbol length including NUL
#define STR_SIZE 10000       // max symbol list size
#define STR_LEN  65536       // max string for now including NUL


typedef union{ 
  struct{ unsigned int partag:3; int parval:29; };
  struct{ unsigned int memtag:3; int memval:29; };
  struct{ unsigned int baktag:3; int bakval:29; };
  struct{ unsigned int strtag:3; int strval:29; };
  struct{ unsigned int symtag:3; int symval:29; };
  struct{ unsigned int pfntag:8; int pfnval:24; };
  struct{ unsigned int chrtag:8; int chrval:24; };
  struct{ unsigned int contag:8; int conval:24; };
  struct{ unsigned int numtag:1; int numval:31; };
  int atm; 
} ATOM;


typedef unsigned char CHAR;

typedef struct{
  ATOM car;
  ATOM cdr;
  ATOM mem;
  ATOM bak;
  //CHAR gcm;
  CHAR mrk;
  CHAR lop;
  CHAR pmk; 
  int  ref;
} PAIR;

extern PAIR   pairs[SIZE];
extern ATOM   freePairs;
extern ATOM   usedPairs;
extern ATOM   lastUsedPair;

       void pair_init();
       void string_init();

// Strings and Symbols
//
typedef struct{
  char *text;
  int len;
  int hash;
  int ref;
} STRING;

extern STRING strings[STR_SIZE];
extern int    freeStr;
       void   string_init();
       ATOM   sym_to_str( ATOM sym );
       ATOM   str_to_sym( ATOM str );
       int    get_str_len( ATOM str );
       ATOM   str_ref( ATOM str,ATOM num );

static void _cm_mark_all_pairs( int m );
static void _cm_ensure_all_pairs_not_marked( int m );
static void _cm_clear_marks_on_free_pairs( int m );
static void _cm_clear_marks_on_used_pairs( int m );
static void _cm_clear_marks_on_atom( ATOM a,int m );

       void _cm_check_mem();
       void _cm_check_mem_leak();

// Primitive functions
//
       ATOM  (*primFns[SIZE])();
       ATOM _bad_primative_fn();

       void  primitive_init();

/*
typedef union{
  struct{ unsigned int strtag:3; unsigned int strlen:2; char str[3]; };
  int atm;
} SHORTSTR;
*/

enum TAGS {PAR=0, MEM=0, BAK=0, NUM=1, SYM=2, RE3=3, CHR=4, RE5=5, STR=6, RE7=7, CON=12, PFN=29};

/*
  (1)------0--(2)----0--(3)--0--> PAR/MEM/BAK (0)
     \           \         `-1--(4)--0--(5)--0--(6)--0--(7)--0--(8)--0--> CHR (4)
      \           \                +-1--(5)--0--(6)--0--(7)--0--(8)--0--> CON (12)
       \           \               +-0--(5)--1--(6)--0--(7)--0--(8)--0--> FIL (20)
        \           \              '-1--(5)--1--> ???
         \           -1--(3)--0--> SYM (2)
          \                 `-1--> STR (6)
           -1--> NUM (1)      
*/   

//#include "pc-lisp-read2.c"
#include "pc-lisp-misc.c"
#include "pc-lisp-test.c"

#undef MAKE_ATOM_ADT

#define MAKE_ATOM_ADT( type,enum )  \
  ATOM make_##type( int i );        \
  int get_##type( ATOM a );         \
  int is_##type( ATOM a );

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );
MAKE_ATOM_ADT( bak,BAK );

#define MAKE_CON( val )    ( (ATOM){.conval=(val), .contag=CON} )
#define MAKE_PAR( val )    ( (ATOM){.parval=(val), .partag=PAR} )
#define MAKE_MEM( val )    ( (ATOM){.memval=(val), .memtag=MEM} )
#define MAKE_CHR( val )    ( (ATOM){.chrval=(val), .chrtag=CHR} )
//#define MAKE_NUM( val )    ( (ATOM){.numval=(val), .numtag=NUM} )

#define EFL          MAKE_CON( 32 )    // end of free list
#define EUL          MAKE_MEM( 0 )    // start and end of used list
#define MTY          MAKE_CON( -9 )     // eMpTY cell in memory
#define NMT          MAKE_CON( 31 )     // pair is unlnked from free and used lists

#define NIL          MAKE_CON( -1 )     // NIL is an empty list - int=0
#define FAL          MAKE_CON( 0 )     // !=0
#define TRU          MAKE_CON( 1 )     // !=0

// ADTs

#define ASSERT_PAIR( p )                                       \
  EXITIF( is_null( p ),"NIL",p );                              \
  EXITIF( _is_end_free_list( p ),"end free list",p );          \
  EXITIF( _is_end_used_list( p ),"end used list",p );          \
  EXITIF( ! is_par( p ),"ASSERT_PAIR! requires a pair",p );    \
  EXITIF( get_val( p )<0,"Negative pair index",p );            \
  EXITIF( get_val( p )>=SIZE,"Pair index >= SIZE",p );

#define PAIRS( p ) pairs[ get_par(p) ]

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )  \
  type _set_##name( ATOM par,type name );   \
  type _##name( ATOM par );

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );
MAKE_PAIR_SET_AND_GET( ATOM,mem );
MAKE_PAIR_SET_AND_GET( ATOM,bak );
//MAKE_PAIR_SET_AND_GET( CHAR,gcm );
MAKE_PAIR_SET_AND_GET( CHAR,mrk );
MAKE_PAIR_SET_AND_GET( CHAR,lop );
MAKE_PAIR_SET_AND_GET( CHAR,pmk );
MAKE_PAIR_SET_AND_GET(  int,ref );

extern int  _freePairCount;
       int  _is_end_free_list( ATOM p );
       int  _is_end_used_list( ATOM p );
       ATOM _free_unlink();
       ATOM _free_append( ATOM p );

extern int  _usedPairCount;
extern int  _usedPairMaxCount;
       ATOM _used_unlink( ATOM p );
       ATOM _used_append( ATOM p );

       ATOM _remove_next_free();
       int  _is_free( ATOM p );
       int  _is_used( ATOM p );

//static ATOM _remove_next_used( ATOM p );
//static ATOM _move_next_used_last( ATOM p );

// END HEADER

#endif

#if defined(_pc_lisp_mem_c)

// CODE

#undef MAKE_ATOM_ADT

#define MAKE_ATOM_ADT( type,enum )                         \
  ATOM make_##type( int i ) {                              \
    return (ATOM){ .type##val=i, .type##tag=enum };        \
  }                                                        \
  int get_##type( ATOM a ) { return a.type##val; }         \
  int is_##type( ATOM a ) { return a.type##tag == enum; }

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );
MAKE_ATOM_ADT( bak,BAK );

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )        \
  type _set_##name( ATOM par,type name ){         \
    /*ASSERT_PAIR( par );/**/                     \
    return PAIRS( par ).name = name;              \
  }                                               \
  type _##name( ATOM par ){  /* no null check */  \
    /*ASSERT_PAIR( par );/**/                     \
    return PAIRS( par ).name;                     \
  }

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );
MAKE_PAIR_SET_AND_GET( ATOM,mem );
MAKE_PAIR_SET_AND_GET( ATOM,bak );
//MAKE_PAIR_SET_AND_GET( CHAR,gcm );
MAKE_PAIR_SET_AND_GET( CHAR,mrk );
MAKE_PAIR_SET_AND_GET( CHAR,lop );
MAKE_PAIR_SET_AND_GET( CHAR,pmk );
MAKE_PAIR_SET_AND_GET(  int,ref );

// pair storage

PAIR   pairs[SIZE];

ATOM   freePairs;
ATOM   usedPairs;
ATOM   lastUsedPair;

// freePairs -> [|].mem->[|].mem->...->0:[|]
//
void pair_init(){
  int i;
      PEEK( "",MTY );
      PEEK( "",EFL );
      PEEK( "",EUL );
      PEEK( "",NIL );
      PEEK( "",TRU );
      PEEK( "",FAL );
      PEEK( "",FOR );
      PEEK( "",REC );
      PEEK( "",NMT );
      //exit(1);
  fputs( "Initialize free pairs...",stderr );
  for (i=1; i<SIZE; i++){
    ATOM p = make_par(i);       
    _set_car( p,MTY );  // do before chaining into freelist
    _set_cdr( p,MTY );
    //_set_gcm( p,0 );                       // mark all in use
    _set_mrk( p,0 );
    _set_lop( p,0 );
    _set_ref( p,0 );
    _set_mem( p,make_mem( (i+1)%SIZE ) );  // chain free cells
  }
  fputs( "Done.\n",stderr );
  fputs( "freePairs --> [1] --> [2] --> ... --> [SIZE-1] --> EFL\n",stderr );
  freePairs = make_par(1);               // [1] is first free pair
  _set_mem( make_mem(SIZE-1),EFL );  // end free list

  //recycleSweeper = usedPairs;

  fputs( "usedPairs <==> [0] - circular doubly-linked list.\n",stderr );
  usedPairs = EUL;               // [0] is used from begining
  lastUsedPair = usedPairs;
  _set_mem( usedPairs,usedPairs );  // make circular
  _set_bak( usedPairs,usedPairs );
  fputs( "Initialize pairs Done.\n",stderr );
}

ATOM (*primFns[SIZE])();

ATOM _bad_primative_fn(){
  fprintf( stderr, "ERROR: Undefined primitive function.\n" );
  exit(1);
}

void primitive_init(){
  int i;
  fputs( "Initialize primitive storage...",stderr );
  for (i=0; i<SIZE; i++){
    primFns[i] = _bad_primative_fn;
  }
  fputs( "Done.\n",stderr );
}

// type storage

STRING strings[STR_SIZE];

// free storage indexes - by convention reserve [0]

int    freeStr=0;
//int    freeFun = 1;

void string_init(){
  int i;
  fputs( "Initialize string and symbol storage...",stderr );
  for ( i=0;i<STR_SIZE;i++ ){
    strings[i].text = "UNDEF STR";
    strings[i].len  = 9;
    strings[i].hash = 0;
    strings[i].ref  = 0;
    //sar[i].val      = 0;
  }
  fputs( "Done.\n",stderr );
  fputs( "Creating string and symbol read buffer...",stderr );
  strings[ 0 ].text = malloc( STR_LEN );
  strings[ 0 ].len  = 0;
  strings[ 0 ].ref  = 1; // never gc?
      EXITIF( strings[ 0 ].text==NULL,"malloc returned NULL!",NIL );
  fputs( "Done.\n",stderr );
  freeStr = 1;  // first free string or symbol storage
  //strings[ freeStr ].len = 0;  // FIXME: why?
}

ATOM sym_to_str( ATOM sym ){ return make_str( get_sym(sym) ); }
ATOM str_to_sym( ATOM str ){ return make_sym( get_str(str) ); }

inline int get_str_len( ATOM str ){
  int s = get_str(str);
  if ( s<=0 ) return (-s) >> (3*8);
  return strings[ s ].len;

}

ATOM str_ref( ATOM str,ATOM ref ){
  //PEEK( "",str );
  //PEEK( "",ref );
  //EXITIF( get_num(ref)<0,"Negative String or symbol ref",ref );
  //EXITIF( get_num(ref)>=get_str_len(str),"String or symbol ref out of range",ref );
  int s = get_str(str);
  if ( s<=0 ){
    s = -s;
    return make_chr( ((char *)&s)[ get_num(ref) ] );
  }
  return make_chr( strings[ s ].text[ get_num(ref) ] );
}

/*
Fundemental memory management functions

freePairs starts at 1, singly linked using mem
usedPairs starts at 0, circular doubly linked
usedPairs is always NIL
mem(usedPairs) points to newest pair
*/

int _freePairCount    = SIZE-1;

// FIXME: wht happens when last pair is unlinked?
// Returns next free pair or MEM0 if no free pairs.
// freePairs = MEM0 when last pair allocated.
//
ATOM _free_unlink(){
  _freePairCount--;
  ATOM p = freePairs;             // next free pair 
      //EXITIF( _freePairCount==0,"Last free pair!",p );
  freePairs = _mem( p );          // unlink from free list
      //EXITIF( is_eq( freePairs,MEM0 ),"Last free pair!",p );
      //EXITIF( get_par(p)==(SIZE-1),"Last free pair!",p );
  _set_mem( p,NMT );        // optional for now
  _set_bak( p,NMT );        // optional for now
      //EXITIF( _is_free(p),"New free pair is still on free list!",p );
      //EXITIF( _is_used(p),"New free pair is already on used list!",p );
  return p;
}

ATOM _free_append( ATOM p ){
      //EXITIF( _is_free(p),"New free pair is already on free list!",p );
      //EXITIF( _is_used(p),"New free pair is still on used list!",p );
  _freePairCount++;
  _set_mem( p,freePairs );
  freePairs = p;
  _set_bak( p,MTY );  // FIXME: do something better
      //EXITIF( ! _is_free(p),"New free pair not added to free list!",p );
      //EXITIF( _is_used(p),"New free pair still on used list!",p );
  return p;
}

int _usedPairCount    = 1;      // [0] is always used as circular list ref

ATOM _used_unlink( ATOM p ){  // must be circular list
      //EXITIF( _is_free(p),"Old used pair is already on free list!",p );
      //EXITIF( ! _is_used(p),"Old used pair not on used list!",p );
  _usedPairCount--;
  _set_mem( _bak(p),_mem(p) );  // remove from mem list
  _set_bak( _mem(p),_bak(p) );  // remove from bak list
      //EXITIF( _is_free(p),"Old free pair is already on free list!",p );
      //EXITIF( _is_used(p),"Old free pair still on used list!",p );
  return p;
}

int _usedPairMaxCount = 0;
// Append pair to used list
// Afterwards, _mem(usedPairs) --> latest pair - not really append
// usedPairs should never change
//
ATOM _used_append( ATOM p ){  // append p after usedPairs
      //EXITIF( _is_free(p),"New used pair still on free list!",p );
      //EXITIF( _is_used(p),"New used pair already on used list!",p );
  _usedPairCount++;
  if ( _usedPairCount > _usedPairMaxCount )  _usedPairMaxCount=_usedPairCount;
  _set_mem( p,_mem(usedPairs) );
  _set_bak( p,usedPairs );
  _set_mem( usedPairs,p );
  _set_bak( _mem(p),p );
      //EXITIF( _is_free(p),"New used pair still on free list!",p );
      //EXITIF( ! _is_used(p),"New used pair not on used list!",p );
  return p;
}

int _is_end_free_list( ATOM p ){
  return is_eq( p,EFL );
}

int _is_end_used_list( ATOM p ){
  return is_eq( p,EUL );
}

ATOM _remove_next_free(){
  ATOM p = _free_unlink();          // next free pair 
      //EXITIF( _is_free(p),"New free pair still on free list!",p );
      //EXITIF( _is_used(p),"New free pair already on used list!",p );
      EXITIF( _is_end_free_list( freePairs ),"All pairs are used!",EFL );
      //RETNIF( is_eq( freePairs,MEM0 ),"All pairs are used!",MEM0 );
  _used_append( p );
      //TRACE( p,TVAL );
      //EXITIF( _is_free(p),"New used pair still on free list!",p );
      //EXITIF( ! _is_used(p),"New used pair not on used list!",p );
  return p;
}

int _is_free( ATOM p ){
  if ( ! is_par(p) ) return FALSE;
  ATOM f = freePairs;
  while ( ! _is_end_free_list( f ) ){
    if ( is_eq( f,p ) ) return TRUE;
    f = _mem(f);
  }
  return FALSE;
}

int _is_used( ATOM p ){
  if ( ! is_par(p) ) return FALSE;
  ATOM f = _mem( usedPairs );
  while ( ! _is_end_used_list( f ) ){
    if ( is_eq( f,p ) ) return TRUE;
    f = _mem(f);
  }
  return FALSE;
}


/*
ATOM makeString(char *buf, int len){
  strings[ freeStr ] = malloc( len+1 );        // storage for string
  strcpy( strings[ freeStr ],buf );       // copy
  //fprintf( stderr,"readSTR=%s\n",strings[freeStr] );
  ATOM a = make_str( freeStr );           // new string
  //peek( "makeString=",a );
  freeStr++;  
  //_push(a);
  return a;
}
*/

// ========================

void _cm_mark_all_pairs( int m ){
  int i;
  for ( i=1; i<SIZE; i++ ){
    _set_mrk( make_par(i),m );  
  }
}

// detects used pairs not linked to environment
// uncollected garbage
//
void _cm_ensure_all_pairs_not_marked( int m ){
  int i,mCount=0,cCount=0;
  for (i=1; i<SIZE; i++){
    if ( _mrk( make_par(i) )==m ) mCount++;
    else
      if ( _mrk( make_par(i) )!=0 ) cCount++;

        WARNIF( _mrk( make_par(i) )==m,"A pair is still marked!",make_par(i) );
        //WARNIF( _mrk( make_par(i) )!=0,"A pair is not cleared!",make_par(i) );
        //EXITIF( mCount>10,"Pairs still marked",make_par(i) );
        //EXITIF( cCount>10,"Pairs not cleared",make_par(i) );
  }
      //EXITIF( mCount>0,"Pairs still marked",make_num(mCount) );
      //EXITIF( cCount>0,"Pairs not cleared",make_num(cCount) );
}


void _cm_clear_marks_on_free_pairs( int m ){
  ATOM f = freePairs;
  while ( ! _is_end_free_list( f ) ){
        // were WARNIF
        EXITIF( _ref(f)!=0,"Free pair has non-zero reference count!",f );
        WARNIF( _mrk(f)!=m,"Free pair not marked!",f );
    _set_mrk( f,0 );
    f = _mem(f);
  }
}
    
void _cm_clear_marks_on_used_pairs( int m ){
  ATOM u = _mem( usedPairs );
      EXITIF( _is_end_used_list( u ),"No used pairs!",u);
  while ( ! _is_end_used_list( u ) ){
        //PEEK( "",u );
        EXITIF( _mrk(u)!=m,"Used pair not marked!",u);
    _set_mrk( u,0 );
    u = _mem(u);
  };
}

// clear marks on all pairs connected to a
// Stop if a pair is cleared
//
void _cm_clear_marks_on_atom( ATOM a,int m ){
  while ( is_pair(a) ){
    if ( _mrk(a)!=m ) return;    // no need to go further to avoid loops
    _set_mrk( a,0 );                     // unmark - keep
    _cm_clear_marks_on_atom( car(a),m );  // follow car tree
    a = cdr(a);
  }
}

// these should only use mrk to check pair allocations and gc performance
void _cm_check_mem(){
      PEEK( "start",NIL );
      //WARNIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );  // is null when no more free pairs!
  _cm_mark_all_pairs(99);
  _cm_clear_marks_on_free_pairs(99);
  _cm_clear_marks_on_used_pairs(99);
  _cm_ensure_all_pairs_not_marked(99);  // any leaks?
      //PEEK( "done",NIL );
}

void _cm_check_mem_leak(){  // only run in repl after gc
      PEEK( "start",NIL );
      //WARNIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  _cm_mark_all_pairs(23);
  _cm_clear_marks_on_atom( gEnv,23 );  // clear marks in environment
  //_set_mrk( make_par(0),0 );  // required? yes, but why did it work without it for so long?
  _cm_clear_marks_on_free_pairs(23);  // fails if a free pair has no mark
  _cm_ensure_all_pairs_not_marked(23);  // any leaks?
      PEEK( "done",NIL );
}


#endif
#endif

