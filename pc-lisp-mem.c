
#ifndef __header
  #define _pc_lisp_mem_c
#endif

#ifndef _pc_lisp_mem_h
  #define _pc_lisp_mem_h
  #define __header

#ifdef __header

// HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "pc-lisp-main.c"

#define GC_ON                // GC ON
#define GC_CHECK             // check all pairs are not marked after GC
#define SIZE     30000         // max size of cell storage
#define SYM_SIZE 30000         // max symbol list size
#define SYM_LEN  32          // max symbol length including NUL
#define STR_LEN  65536       // max string for now including NUL

#define TRUE     ( 1==1 )
#define FALSE    ( 1==0 )

typedef union{ 
  struct{ unsigned int partag:3; int parval:29; };
  struct{ unsigned int memtag:3; int memval:29; };
  struct{ unsigned int strtag:3; int strval:29; };
  struct{ unsigned int symtag:3; int symval:29; };
  struct{ unsigned int pfntag:8; int pfnval:24; };
  struct{ unsigned int chrtag:8; int chrval:24; };
  struct{ unsigned int contag:8; int conval:24; };
  struct{ unsigned int numtag:1; int numval:31; };
  int atm; 
} ATOM;

#include "pc-lisp-test.c"
//#include "pc-lisp-.c"


typedef union{
  struct{
    unsigned int gc:2;
    unsigned int mark:10;
  };
  int  val;
} FLAGS;

typedef unsigned char CHAR;

typedef struct{
  ATOM car;
  ATOM cdr;
  ATOM mem;
  CHAR gcm;
  CHAR mrk;
  CHAR pmk; 
} PAIR;

extern PAIR   pairs[SIZE];
extern ATOM   freePairs;
extern ATOM   usedPairs;
extern ATOM   freePair;
extern ATOM   usedPair;

extern FLAGS  sar[SIZE];
// Symbols
typedef struct{
  char name[SYM_LEN];
} SYMBOL;
extern SYMBOL symbols[SYM_SIZE];
extern int    freeSym;

// Strings
extern char  *strings[SIZE];
extern int    freeStr;
enum TAGS {PAR=0, MEM=0, NUM=1, SYM=2, RE3=3, CHR=4, RE5=5, STR=6, RE7=7, CON=12, PFN=29};

/*
  (1)------0--(2)----0--(3)--0--> PAR/MEM (0)
     \           \         `-1--(4)--0--(5)--0--(6)--0--(7)--0--(8)--0--> CHR (4)
      \           \                +-1--(5)--0--(6)--0--(7)--0--(8)--0--> CON (12)
       \           \               +-0--(5)--1--(6)--0--(7)--0--(8)--0--> PFN (20)
        \           \              '-1--(5)--1--> ???
         \           -1--(3)--0--> SYM (2)
          \                 `-1--> STR (6)
           -1--> NUM (1)      
*/   
int get_tag( ATOM a );
int get_val( ATOM a );
void peekPair( char *m,ATOM p );
void dump( int s );
void peek( char *m,ATOM a );
int     is_pair  ( ATOM p );
int     is_atom  ( ATOM a );
int     is_list  ( ATOM l );
int     is_symbol( ATOM s );
int     is_null  ( ATOM a );
int     is_eq    ( ATOM a,ATOM b );

#define FILE_LINE  fprintf( stderr,"%s line %d ",__FILE__,__LINE__ )


#define PEEK( mess,atom ){                                               \
  {                                                                      \
    FILE_LINE;                                                           \
    /*fprintf( stderr,"%s line %d ",__FILE__,__LINE__ );/**/             \
    fprintf( stderr,"%s(): ",__func__ );                                 \
    peek( mess " " #atom,(atom) );                                         \
  }                                                                      \
}
  
#define EXITIF( pred,mess,atom ){                                        \
  if ( pred ){                                                           \
    fprintf( stderr,"%s line %d ",__FILE__,__LINE__ );                  \
    fprintf( stderr,"EXITIF: " #pred "\n" );                             \
    fprintf( stderr,mess " in c-function %s().\n",__func__ );            \
    peek( #atom,(atom) );                                                  \
    exit(1);                                                             \
  }                                                                      \
}

#define RETIF( pred,mess,atom ){                                         \
  if ( pred ){                                                           \
    fprintf( stderr,"%s  %d  ",__FILE__,__LINE__ );                  \
    fprintf( stderr,"RETIF: " #pred "\n" );                              \
    fprintf( stderr,mess " in c-function %s().\n",__func__ );            \
    peek( #atom,(atom) );                                                  \
    return ERR;                                                          \
  }                                                                      \
}

#define WARNIF( pred,mess,atom ){                                        \
  if ( pred ){                                                           \
    fprintf( stderr,"%s  %d  ",__FILE__,__LINE__ );                  \
    fprintf( stderr,"WARNIF: " #pred "\n" );                             \
    fprintf( stderr,mess " in c-function %s().\n",__func__ );            \
    peek( #atom,(atom) );                                                  \
  }                                                                      \
}
  
#define EXIT( mess,atom ){                                               \
  {                                                                      \
    fprintf( stderr,"%s  %d  ",__FILE__,__LINE__ );                  \
    fprintf( stderr,"EXIT: " "\n" );                                     \
    fprintf( stderr,mess " in c-function %s().\n",__func__ );            \
    peek( #atom,(atom) );                                                  \
    exit(1);                                                             \
  }                                                                      \
}


#undef MAKE_ATOM_ADT

#define MAKE_ATOM_ADT( type,enum )                                \
ATOM make_##type( int i );\
int get_##type( ATOM a );        \
int    is_##type( ATOM a );

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );

#define MAKE_CON( val )    ( (ATOM){.conval=(val), .contag=CON} )
#define MAKE_PAR( val )    ( (ATOM){.parval=(val), .partag=PAR} )
#define MAKE_CHR( val )    ( (ATOM){.chrval=(val), .chrtag=CHR} )
#define MAKE_NUM( val )    ( (ATOM){.numval=(val), .numtag=NUM} )

#define EOL          MAKE_CHR( ')' )
#define EOP          MAKE_CHR( DOT )
#define END          MAKE_CHR( EOF )

#define MTY          MAKE_CON( -9 )     // eMpTY cell in memory
#define REC          MAKE_CON( -10)     // recycled pair
#define ERR          MAKE_CON( -99)     // error value
/*
go with () being false and not () being true
but to make c implemetation same as simplispic
need to make true!=0 and false=(0==1)=0
MAKE_CONST(0) = MAKE_PAR(0) = 0 by nature of PAR tag = 0
MAKE_CONST(-1) = -1, by nature of NUM tag = 1
*/
#define NIL          MAKE_PAR( 0 )     // NIL is an empty list - int=0
#define FAL          NIL
#define TRU          MAKE_CON( 1 )     // !=0
#define CAR(a)       car(a)
#define CDR(a)       cdr(a)
#define _1ST(a)      car(a)     // [1,1]
#define _2ND(a)      cadr(a)    // [2,1]
#define _3RD(a)      caddr(a)   // [3,1]
#define _4TH(a)      cadddr(a)  // [4,1]

#define _1of1(a)     caar(a)     // _1ST of _1ST
#define _1of2(a)     caadr(a)    // _1ST of _2ND
#define _1of3(a)     caaddr(a)   // _1ST of _3RD
#define _1of4(a)     caadddr(a)  // _1ST of _4TH

#define _Rof1(a)     cdar(a)     // rest of _1ST
#define _Rof2(a)     cdadr(a)    // rest of _2ND
#define _Rof3(a)     cdaddr(a)   // rest of _3RD
#define _Rof4(a)     cdadddr(a)  // rest of _4TH

#define _REST(a)     cdr(a)      // rest after _1ST, rest from 2nd
#define _Rfrom2(a)   cdr(a)    // rest from _2ND
#define _Rfrom3(a)   cddr(a)   // rest from _3RD
#define _Rfrom4(a)   cdddr(a)  // rest from _4TH

#define caar(a)      car( car( a ) )  // _2ND down [1,2]
#define cadr(a)      car( cdr( a ) )  // _2ND [2,1]

#define cdar(a)      cdr( car( a ) )  // _Rof1 rest of _1ST
#define cddr(a)      cdr( cdr( a ) )  // rest from 3rd rest after _2ND

#define caaar(a)     car( caar( a ) )  // _3RD down
#define caadr(a)     car( cadr( a ) )  // _1of2 _1ST of _2ND [2,2]
#define cadar(a)     car( cdar( a ) )
#define caddr(a)     car( cddr( a ) )  // _3RD

#define cdaar(a)     cdr( caar( a ) )  // rest of _2ND down
#define cdadr(a)     cdr( cadr( a ) )  // _Rof2 rest of _2ND
#define cddar(a)     cdr( cdar( a ) )
#define cdddr(a)     cdr( cddr( a ) )  // rest after _3RD

#define caaaar(a)    car( caaar( a ) )  // _4TH down
#define caaadr(a)    car( caadr( a ) )
#define caadar(a)    car( cadar( a ) )
#define caaddr(a)    car( caddr( a ) )  // _1of3 _1ST of _3RD 
#define cadaar(a)    car( cdaar( a ) )
#define cadadr(a)    car( cdadr( a ) )
#define caddar(a)    car( cddar( a ) )
#define cadddr(a)    car( cdddr( a ) )  // _4TH

#define cdaaar(a)    cdr( caaar( a ) )
#define cdaadr(a)    cdr( caadr( a ) )
#define cdadar(a)    cdr( cadar( a ) )
#define cdaddr(a)    cdr( caddr( a ) )  // _Rof3 rest of _3RD
#define cddaar(a)    cdr( cdaar( a ) )
#define cddadr(a)    cdr( cdadr( a ) )
#define cdddar(a)    cdr( cddar( a ) )
#define cddddr(a)    cdr( cdddr( a ) )  // rest after _4TH


extern ATOM   _global_save;     // repl needs to use a global used pair value
//ATOM    consFatal ( ATOM a,ATOM b );
//ATOM    consNormal( ATOM a,ATOM b );
//ATOM  (*cons)( ATOM a,ATOM b );
/*

ATOM    _car( ATOM par );  // these don't check for NIL
ATOM    _cdr( ATOM par );
ATOM    _mem( ATOM par );
CHAR    _gcm( ATOM par );
CHAR    _mrk( ATOM par );
ATOM    car( ATOM par );
ATOM    cdr( ATOM par );
ATOM    mem( ATOM par );
CHAR    gcm( ATOM par );
CHAR    mrk( ATOM par );
ATOM    _set_car( ATOM par,ATOM car );  // these don't check for NIL
ATOM    _set_cdr( ATOM par,ATOM cdr );
ATOM    _set_mem( ATOM par,ATOM mem );
CHAR    _set_gcm( ATOM par,CHAR gcm );
CHAR    _set_mrk( ATOM par,CHAR mrk );
ATOM    set_car( ATOM par,ATOM car );
ATOM    set_cdr( ATOM par,ATOM cdr );
ATOM    set_mem( ATOM par,ATOM mem );
CHAR    set_gcm( ATOM par,CHAR gcm );
CHAR    set_mrk( ATOM par,CHAR mrk );
/**/
// ADTs


#define ASSERT_PAIR( par )                             \
  EXITIF( ! is_par( par ),"requires a pair",par );

#define PAIRS( p ) pairs[ get_par( p ) ]

#define MAKE_PAIR_GETTER( type,name )                  \
type _##name( ATOM par ); \
type name( ATOM par )

#define MAKE_PAIR_SETTER( type,name )                  \
type _set_##name( ATOM par,type name );\
type set_##name( ATOM par,type name );

MAKE_PAIR_GETTER( ATOM,car );
MAKE_PAIR_GETTER( ATOM,cdr );
MAKE_PAIR_GETTER( ATOM,mem );
MAKE_PAIR_GETTER( CHAR,gcm );
MAKE_PAIR_GETTER( CHAR,mrk );
MAKE_PAIR_GETTER( CHAR,pmk );

MAKE_PAIR_SETTER( ATOM,car );
MAKE_PAIR_SETTER( ATOM,cdr );
MAKE_PAIR_SETTER( ATOM,mem );
MAKE_PAIR_SETTER( CHAR,gcm );
MAKE_PAIR_SETTER( CHAR,mrk );
MAKE_PAIR_SETTER( CHAR,pmk );

//#define MEM_DEBUG

#ifdef MEM_DEBUG                                         
  #define MEM_DEBUG_LINE( m ) \
    fprintf( stderr,m " %s line %d\n",__FILE__,__LINE__ );
  #define MEM_PEEK( m,a ) PEEK( m,a )
#else
  #define MEM_DEBUG_LINE( m )
  #define MEM_PEEK( m,a )
#endif

#define MARK3                                                          \
  MEM_DEBUG_LINE( "MARK3.1" );                                         \
  ATOM _save = _mem( usedPairs );                                      \
  MEM_PEEK( "",_save );                                                \
  MEM_DEBUG_LINE( "MARK3.2" );                                         
  
#define GLOBAL_MARK3 _global_save = _mem( usedPairs )

#define RETURN3(a) {                                                   \
  ATOM _ret = (a);                                                     \
  MEM_DEBUG_LINE( "RETURN3.1" );                                       \
  _gc( _save,_ret );                                                   \
  MEM_DEBUG_LINE( "RETURN3.2" );                                       \
  return _ret;                                                         \
}

#define KEEP3(a) {                                                     \
  MEM_DEBUG_LINE( "KEEP3.1" );                                         \
  _gc( _save,(a) );                                                    \
  MEM_DEBUG_LINE( "KEEP3.2" );                                         \
}

#define GLOBAL_KEEP3(a) {                                              \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.1" );                                  \
  _gc( _global_save,(a) );                                             \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.2" );                                  \
  _global_save = _mem( usedPairs );                                    \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.3" );                                  \
}

#define VOID3() {                                                      \
  MEM_DEBUG_LINE( "VOID3.1" );                                         \
  _gc( _save,NIL );                                                    \
  MEM_DEBUG_LINE( "VOID3.2" );                                         \
  return;                                                              \
}

extern int  consCount;
extern int  consMaxCount;
extern int _recyclePairCount;
extern int _sweepPairCount;
extern int _recycleStrCount;

extern ATOM (*cons)( ATOM a,ATOM b );

ATOM consFatal( ATOM a,ATOM b );
static ATOM _remove_next_free();
static ATOM _remove_next_used( ATOM p );
static void _mark_all_pairs( int m );
static void _ensure_all_pairs_not_marked(int m);
static void _clear_marks_on_free_pairs( int m );
    
static void _clear_marks_on_used_pairs( int m );
static void _clear_marks_on_atom( ATOM a,int m );
void _check_mem();
void _check_mem_leak();

static ATOM consNormal(ATOM a, ATOM b);


static ATOM _recycle_next(ATOM this, int force);
static void _mark( ATOM stop );
static void _recycle_pairs( ATOM stop,int force );
static ATOM _ms_sweep_next( ATOM this,int m );
static void _ms_sweep_all_pairs( int m );
static void _ms_mark_all_used_pairs( int m );
void _ms( ATOM env );
static void _gc_ensure_all_used_pairs_not_marked();
void _gc( ATOM stop,ATOM keep );
static void _clear( ATOM pair );
void _mark_assignments_as_special( ATOM pair );

// END HEADER

#endif

#if defined(_pc_lisp_mem_c)

// CODE

#undef MAKE_ATOM_ADT


#define MAKE_ATOM_ADT( type,enum )                                \
ATOM make_##type( int i )  {                               \
  return (ATOM){ .type##val=i, .type##tag=enum }; }               \
int get_##type( ATOM a ) { return a.type##val; }         \
int    is_##type( ATOM a ) { return a.type##tag == enum; }

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );

#undef MAKE_PAIR_GETTER

#define MAKE_PAIR_GETTER( type,name )                  \
type _##name( ATOM par ){  /* no null check */  \
  ASSERT_PAIR( par );                                  \
  return PAIRS( par ).name;                            \
}                                                      \
type name( ATOM par ){                          \
  ASSERT_PAIR( par );                                  \
  EXITIF( is_null( par ),"par is NIL",par );           \
  return PAIRS( par ).name;                            \
}

#undef MAKE_PAIR_SETTER

#define MAKE_PAIR_SETTER( type,name )                  \
type _set_##name( ATOM par,type name ){         \
  ASSERT_PAIR( par );                                  \
  EXITIF( get_val(par)<0 || get_val(par)>=SIZE,        \
    "Illegal pair index",par );                        \
  return PAIRS( par ).name = name;                     \
}                                                      \
type set_##name( ATOM par,type name ){          \
  ASSERT_PAIR( par );                                  \
  EXITIF( is_null( par ),"par is NIL",par );           \
  EXITIF( get_val(par)<0 || get_val(par)>=SIZE,        \
    "Illegal pair index",par );                        \
  return PAIRS( par ).name = name;                     \
}


MAKE_PAIR_GETTER( ATOM,car );
MAKE_PAIR_GETTER( ATOM,cdr );
MAKE_PAIR_GETTER( ATOM,mem );
MAKE_PAIR_GETTER( CHAR,gcm );
MAKE_PAIR_GETTER( CHAR,mrk );
MAKE_PAIR_GETTER( CHAR,pmk );

MAKE_PAIR_SETTER( ATOM,car );
MAKE_PAIR_SETTER( ATOM,cdr );
MAKE_PAIR_SETTER( ATOM,mem );
MAKE_PAIR_SETTER( CHAR,gcm );
MAKE_PAIR_SETTER( CHAR,mrk );
MAKE_PAIR_SETTER( CHAR,pmk );


// pair storage
PAIR   pairs[SIZE];
FLAGS  sar[SIZE];         // string garbage markage
ATOM   freePairs;
ATOM   usedPairs;

// type storage
SYMBOL symbols[SYM_SIZE];
char  *strings[SIZE];

// free storage indexes - by convention reserve [0]
int    freeSym = 1;
int    freeStr = 1;
int    freeFun = 1;

ATOM   gEnv=NIL;     // global environment

int is_eq( ATOM a,ATOM b ){
  return a.atm==b.atm;
}
/*
 NIL  par  atom  pair  list
  0    0    X     X     X
  0    1    0     1    cdr=par
  1    0    X     0     X
  1    1    1     0     1
*/
int is_pair( ATOM p ){
  return is_par(p) && ( ! is_null(p) );  // how did I make this mistake?
}

// FIXME: scheme says a list must have cdr=nil or cdr=pair
int is_list( ATOM p ){
  return is_par(p);
  //return is_par(p) && is_pair( cdr(p) );  // breaks pc-list
}

int is_atom( ATOM p ){
  return is_null(p) || ( ! is_par(p) );
}
int is_symbol( ATOM a ){ return is_sym(a); }
int is_null( ATOM a ){ return is_eq( a,NIL ); }  //IS_NIL(p); }

int get_tag(ATOM a){
  if ( is_num(a) ) return NUM;
  if ( is_par(a) ) return PAR;
  if ( is_sym(a) ) return SYM;
  if ( is_str(a) ) return STR;
  if ( is_chr(a) ) return CHR;
  if ( is_con(a) ) return CON;
  if ( is_pfn(a) ) return PFN;
  return -1;
}
int get_val(ATOM a){
  if ( is_num(a) ) return a.numval;
  if ( is_par(a) ) return a.parval;
  if ( is_sym(a) ) return a.symval;
  if ( is_str(a) ) return a.strval;
  if ( is_chr(a) ) return a.chrval;
  if ( is_con(a) ) return a.conval;
  if ( is_pfn(a) ) return a.pfnval;
  return 0;
}

ATOM (*cons)( ATOM a,ATOM b ) = consNormal;

ATOM consFatal( ATOM a,ATOM b ){
  fputs("Cons FATAL: All cells used.\n", stderr);
  fputs("This should never happen. It means I ignored previous error.\n", stderr);
  fputs("I'll exit now to avoid an infinite loop.\n", stderr);
  exit(1);
}

void peekPair( char *m,ATOM p ){
  if ( is_atom(p) ){
    fprintf( stderr,"%8s = %3d: tag=%d val=%d\n",m,p.atm,get_tag(p),get_val(p) );
    return;
  }
  fprintf( stderr,"%8s = %3d (",m,get_par(p) );
  DUMP_ATOM( car(p) );
  DUMP_ATOM( cdr(p) );
  DUMP_ATOM( mem(p) );
  fprintf( stderr,"gcm=%3hhd mrk=%3hhd)\n",gcm(p),mrk(p) );
}

void dump( int s ){
  LOG("dump");
  fprintf( stderr,"freePairs = %d\n",get_par(freePairs) );
  fprintf( stderr,"usedPairs = %d\n",get_par(usedPairs) );
  
  int i;                      // i is an index here, not an ATOM
  for (i=0; i<s; i++){
    peekPair( "",make_par(i) );
  }
  LOG("/dump");
}

void peek( char *m,ATOM a ){
  fprintf( stderr,"[%s = %3d:",m,get_par(a) );  
  fprinta( stderr,a );
  fprintf( stderr,"]\n" );
}


/*
Fundemental memory management functions

freePairs starts at 1=[MTY][MTY][<next free pair>]
  <last free pair>=[MTY][MTY][/]
UsedPairs starts at 0=["used"][][/]
usedPairs is always NIL
mem(usedPairs) points to newest pair

*/

ATOM _remove_next_free(){
  ATOM p = freePairs;             // next free pair 
  freePairs = _mem( p );          // unlink from free list
  RETIF( is_null( freePairs ),"All pairs are used!",freePairs );
  _set_mem( p,_mem(usedPairs) );  // move new pair to used list
  _set_mem( usedPairs,p );        // mem(usedPairs) -> new pair
  return p;
}

ATOM _remove_next_used( ATOM p ){
  ATOM n = _mem( p );       // next in used list - remove this, not p
  EXITIF( is_null( n ),"No next used cell",p );  // end of list
  ATOM n2 = _mem( n );      // FIXME: why n2? pair following n
  _set_mem( p,n2 );         // unlink n
  _set_mem( n,freePairs );  // insert n on to free list
  freePairs = n;            // n will be next free pair
  return p;                 // return to redo p since it has new next
}

/*
*/

void _mark_all_pairs( int m ){
  int i;
  for ( i=0; i<SIZE; i++ ){
    _set_mrk( make_par(i),m );  
  }
}

void _ensure_all_pairs_not_marked(int m){
  int i;
  for (i=0; i<SIZE; i++){
    //WARNIF( _gcm( make_par(i) )==2,"Special pair",make_par(i) );

    EXITIF( _mrk( make_par(i) )==m,"A pair is still marked!",make_par(i) );
    EXITIF( _mrk( make_par(i) )!=0,"A pair is not cleared!",make_par(i) );
  }
}


void _clear_marks_on_free_pairs( int m ){
  int c = 0;
  ATOM f = freePairs;
  while ( ! is_null(f) ){
    WARNIF( _mrk(f)!=m,"Free pair not marked!",f );
    if ( _mrk(f)!=m ) c++;
    _set_mrk( f,0 );
    f = _mem(f);
  }
  EXITIF( c>0,"Free pairs not marked!",NIL );
}
    
void _clear_marks_on_used_pairs( int m ){
  ATOM u = usedPairs;
  do{
    EXITIF( _mrk(u)!=m,"Used pair not marked!",u);
    _set_mrk( u,0 );
    u = _mem(u);
  }while ( ! is_null(u) );
}

void _clear_marks_on_atom( ATOM a,int m ){
  while ( is_pair(a) ){
    if ( _mrk(a)!=m ) return;           // no need to go further to avoid loops
    _set_mrk( a,0 );                     // unmark - keep
    EXITIF( is_null(a),"",a );
    _clear_marks_on_atom( car(a),m );  // follow car tree
    a = cdr(a);
  }
}
// these should only use mrk to check pair allocations and gc performance
void _check_mem(){
  MEM_PEEK( "start",(NIL) );
  EXITIF( ! is_null(usedPairs),"usedPairs should be NIL!",usedPairs );
  EXITIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  _mark_all_pairs(99);
  _clear_marks_on_free_pairs(99);
  _clear_marks_on_used_pairs(99);
  _ensure_all_pairs_not_marked(99);  // any leaks?
}

void _check_mem_leak(){  // only run in repl after gc
  EXITIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  _mark_all_pairs(23);
  _clear_marks_on_atom( gEnv,23 );  // clear marks in environment
  _set_mrk( make_par(0),0 );  // required? yes, but why did it work without it for so long?
  _clear_marks_on_free_pairs(23);  // fails if a free pair has no mark
  _ensure_all_pairs_not_marked(23);  // any leaks?
}

int consCount = 0;
int consMaxCount = 0;

ATOM consNormal(ATOM a, ATOM b){
  _check_mem();
  ATOM c = _remove_next_free();   // remove from free list
  if ( is_null(c) ){
    fputs("Cons FATAL: All cells used.\n", stderr);
    cons = consFatal;
    exit(1);
    return c;
  }
  set_car( c,a );
  set_cdr( c,b );
  EXITIF( gcm(c)!=0,"GC mark not zero",c );
  consCount++;
  if ( consCount>consMaxCount ) consMaxCount = consCount; 
  return c;
}

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

// symbols never recycled

int _recyclePairCount=0;
int _sweepPairCount=0;
int _recycleStrCount=0;


ATOM _recycle_next(ATOM this, int force){   // recycle pairs and strings
  MEM_PEEK( "start",this );
  ATOM next = _mem( this );                       // pair to make head of free list
  switch ( get_tag(next) ){
  case PAR:
    if ( _gcm(next)==2 ){  // special case for define and set*
      //PEEK( "special",next );  // don't recycle
      return next;
    }
    if ( _gcm(next)==1 || force ){            // marked so recycle
      MEM_PEEK( "next",next );
      //setcar( next,REC );                    // clear car
      _set_gcm( next,0 );                      // clear gc marks
      _recyclePairCount++;
      return _remove_next_used( this );
    }
    //peekPair( "_recycle.keep: next",next );
    MEM_PEEK( "return",next );
    return next;
  case STR:
    exit(1);  // no longer does strings
    if ( (sar[ get_str( next ) ].gc==1) || force ){           // marked so recycle
      peekPair( "_recycle: string: ",make_str( get_str( next ) ) );
      free( strings[ get_str( next ) ] ); // free's string storage but does not fix freeStr
      strings[ get_str( next ) ] = "!RECYCLED!";
      if ( freeStr == get_str( next )+1 )      // can shrink string in this case
        freeStr--;
      sar[ get_str( next ) ].val = 0;
      _recycleStrCount++;
    }
    return next;
  }
  EXITIF( TRUE,"Can only recycle pairs",next );
}

//void _clear( ATOM a );

// mark all new used pairs that could be recycled right now
// stop marking at stop
void _mark( ATOM stop ){
  ATOM i = usedPairs;
  while ( ! is_eq( _mem(i),stop )){  //was NE   // mark all for recycling
    ATOM a = _mem(i);
    MEM_PEEK( "set marks",a );
    switch ( get_tag(a) ){
    case PAR: 
      MEM_PEEK( "set pair mark",a );
      if ( _gcm(a)!=2 )  _set_gcm( a,1 );  // only mark is not define or set*
      break;                               // recycle unless cleared
    case STR: 
      //peekPair( "_mark: mark string",a ); 
      sar[ get_str(a) ].gc = 1; 
      break;
    default:
      EXITIF( TRUE,"Can't set mark for",a );
       //fprintf( stderr,"_gc: Can't set mark for %d\n",a.atm ); exit(1);  
    }
    MEM_PEEK( "get next",i );
    i = _mem(i);
    MEM_PEEK( "next",i );
  }
  MEM_PEEK( "done",NIL );
}

void _recycle_pairs( ATOM stop,int force ){
  ATOM i = usedPairs;
  while ( ! is_eq( _mem(i),stop ) ){
    i = _recycle_next( i,force );
  }
}

/*
Mark-Sweep GC for simply clearing up defines and set! leaks
Run in REPL or cons when no more pairs
Uses mrk not gcm flags
*/

ATOM _ms_sweep_next( ATOM this,int m ){
  ATOM next = _mem( this );      // pair to make head of free list
  if ( _mrk(next)==m ){          // marked so recycle
    MEM_PEEK( "Normal GC missed this",next );
    _set_mrk( next,0 );          // clear gc marks
    _sweepPairCount++;
    return _remove_next_used( this );
  }
  return next;
}

void _ms_sweep_all_pairs( int m ){
  ATOM i = usedPairs;
  while ( ! is_null( _mem(i) ) ){
    ATOM a = _mem(i);
    i = _ms_sweep_next( i,m );
  }
}

void _ms_mark_all_used_pairs( int m ){
  ATOM i = usedPairs;
  while ( ! is_null( _mem(i) ) ){  // mark all for recycling
    ATOM a = _mem(i);
    _set_mrk( a,m );  
    i = _mem(i);
  }
}

void _ms( ATOM env ){
#ifndef GC_ON
  return;
#endif
  EXITIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  // mark all used
  _ms_mark_all_used_pairs(24);
  // clear mark on all reachable from env
  _clear_marks_on_atom( env,24 );  // clear marks in environment
  // sweep up garbage
  _ms_sweep_all_pairs( 24 );
  // check
  _check_mem();
  _check_mem_leak();
}

void _gc_ensure_all_used_pairs_not_marked(){ // this works with gcm not mrk
  ATOM i = usedPairs;
  while ( ! is_null(i) ){  //NOT_NIL( i ){
    // only check strings and pairs
    EXITIF( is_str(i) && ( sar[ get_str(i) ].gc==1 ),
      "String should not have sar=1",i );
    EXITIF( is_par(i) && ( gcm(i)==1 ),"Pair should not have gcm=1",i );
    i = _mem(i);
  }
}

void _gc( ATOM stop,ATOM keep ){  // clear stack to p, but not p
#ifndef GC_ON
  return;
#endif
  //fprintf( stderr, "freePairs = %d\n",get_par(freePairs) );
  //fprintf( stderr, "usedPairs = %d\n",get_par(usedPairs) );
  MEM_PEEK( "start",keep ); 
  if ( is_eq( keep,gEnv ) ){  // global env
    set_gcm( gEnv,1 );  // to stop marking here
    //peek( "_gc: keeping gEnv",keep ); 
  }
//  if ( IS_NIL( keep ) || is_num( keep ) || is_chr( keep ) 
//  || is_sym( keep ) || is_str( keep ) ){
  MEM_PEEK( "1",stop );
  if ( is_atom(keep) ){
    _recycle_pairs( stop,TRUE );  // recycle all if returning an atom
    return;
  }
  MEM_PEEK( "2",NIL );
  EXITIF( is_null( keep ),"keep is ()",keep );
  if ( is_eq( _mem(usedPairs),stop ) ){  // correct since MARK3 uses mem(usedPairs)
  //if EQ( usedPairs,p ){  // FAILS I think
    //peek( "_gc: nothing to do: stop",stop ); 
    //peek( "_gc: nothing to do: keep",keep ); 
    return;
  }
  //peekPair( "_gc: something to do: a",a );
  //peek( "_gc: working on a",a );
  MEM_PEEK( "3 mark",NIL );
  _mark( stop );
  //PEEK( "mark",keep );
  //peek( "_gc: Before clearing gEnv",gEnv );
  MEM_PEEK( "4 clear",NIL );
  _clear( keep );                          // clear marks for returned pairs
  //peek( "_gc: After clearing gEnv",gEnv );
  MEM_PEEK( "5 recycle",NIL );
  _recycle_pairs( stop,FALSE );
#ifdef GC_CHECK
  // here, all created pairs should be marked 0
  MEM_PEEK( "6 ensure",NIL );
  _gc_ensure_all_used_pairs_not_marked();
#endif
  MEM_PEEK( "done",NIL );
}


void _clear( ATOM pair ){  // mark returned result to avoid recycling
  do{
    if ( is_null(pair) ) return;
    switch ( get_tag(pair) ){
    case NUM: case CHR: case SYM: case CON: return;
    case STR: sar[ get_str(pair) ].gc = 0; return;
    }
    // FIXME: how might adding to environments work????
    //if EQ( pair,gEnv ) return;                 // no need into to go further
    if ( _gcm(pair)==0 || _gcm(pair)==2 ) return;  // no need to go further
    _set_gcm( pair,0 );
    _clear( car(pair) );                       // follow car tree
    pair = cdr(pair);
  }while TRUE;                // tail-call _clear( CDR(a) );
}

// FIXME: do we need to mark all of tree or just first?
void _mark_assignments_as_special( ATOM pair ){  // gcm=2
  do{
    if ( is_null(pair) ) return;
    switch ( get_tag(pair) ){
    case NUM: case CHR: case SYM: case CON: return;
    case STR: sar[ get_str(pair) ].gc = 0; return;
    }
    if ( is_eq( pair,gEnv ) ) return;                 // no need to go further
    if ( _gcm(pair)==2 )  return;  // no need to go further
    set_gcm( pair,2 );  // define and set* are special
    _mark_assignments_as_special( car(pair) ); // follow car tree
    pair = cdr(pair);
  }while TRUE;                // tail-call fn( CDR(a) );
}


#endif
#endif


