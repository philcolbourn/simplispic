
#ifndef __header
  #define _pc_lisp_gc_c
#endif

#ifndef _pc_lisp_gc_h
  #define _pc_lisp_gc_h
  #define __header

#ifdef __header

/*

Interface: car, cdr, cons, set_car, set_cdr

Managed Memory with garbage collection 

Interface: _car, _cdr, _set_car, _set_cdr, _cons

Memory - Pairs
*/

// HEADER

#include "pc-lisp-mem.c"

#define GC_ON                // GC ON
#define GC_CHECK             // check all pairs are not marked after GC
#define MTY          MAKE_CON( -9 )     // eMpTY cell in memory
#define REC          MAKE_CON( -10)     // recycled pair

typedef union{
  struct{
    unsigned int gc:2;
    unsigned int mark:10;
  };
  int  val;
} FLAGS;

extern FLAGS  sar[SIZE];

#include "pc-lisp-misc.c"

extern int  _sweepPairCount;
extern int  _recycleStrCount;


// ADTs

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )  \
  type set_##name( ATOM par,type name );    \
  type name( ATOM par );

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );

void _inc_ref( ATOM p );

extern int  _recyclePairCount;
void _recycle( ATOM p );

extern int _decRecyclePairCount;
void _dec_ref( ATOM p );

//#define MEM_DEBUG

#ifdef MEM_DEBUG                                         
  #define MEM_DEBUG_LINE( m ) \
    fprintf( stderr,"-- %s  " m "  %s %d\n",__func__,__FILE__,__LINE__ );
  #define MEM_PEEK( m,a ) PEEK( m,a )
#else
  #define MEM_DEBUG_LINE( m )
  #define MEM_PEEK( m,a )
#endif

#define MARK3                                                          \
  MEM_DEBUG_LINE( "MARK3.1" );                                         \
  FILE_LINE;                                                           \
  /*ATOM _save = _mem( usedPairs );/**/                                \
  //MEM_PEEK( "",_save );                                              \
  MEM_DEBUG_LINE( "MARK3.2" );                                         
  
#define GLOBAL_MARK3 _global_save = _mem( usedPairs )

#define RETURN3(a) {                                                   \
  /*ATOM _ret = (a);/**/                                               \
  MEM_DEBUG_LINE( "RETURN3.1" );                                       \
  /*_gc( _save,_ret );/**/                                             \
  /*_mem_print_used_pairs( "RETURN3",usedPairs,_save );/**/            \
  MEM_DEBUG_LINE( "RETURN3.2" );                                       \
  return a;/*_ret;/**/                                                 \
}

#define KEEP3(a) {                                                     \
  MEM_DEBUG_LINE( "KEEP3.1" );                                         \
  /*_gc( _save,(a) );/**/                                              \
  /*_mem_print_used_pairs( "KEEP3",usedPairs,_save );/**/              \
  MEM_DEBUG_LINE( "KEEP3.2" );                                         \
}

#define GLOBAL_KEEP3(a) {                                              \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.1" );                                  \
  /*_gc( _global_save,(a) );/**/                                       \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.2" );                                  \
  /*_global_save = _mem( usedPairs );/**/                              \
  MEM_DEBUG_LINE( "GLOBAL_KEEP3.3" );                                  \
}

#define VOID3() {                                                      \
  MEM_DEBUG_LINE( "VOID3.1" );                                         \
  /*_gc( _save,NIL );/**/                                              \
  MEM_DEBUG_LINE( "VOID3.2" );                                         \
  return;                                                              \
}

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

//#define cdaaar(a)    cdr( caaar( a ) )
//#define cdaadr(a)    cdr( caadr( a ) )
//#define cdadar(a)    cdr( cadar( a ) )
//#define cdaddr(a)    cdr( caddr( a ) )  // _Rof3 rest of _3RD
//#define cddaar(a)    cdr( cdaar( a ) )
//#define cddadr(a)    cdr( cdadr( a ) )
//#define cdddar(a)    cdr( cddar( a ) )
//#define cddddr(a)    cdr( cdddr( a ) )  // rest after _4TH


//extern int  _freePairCount;
//ATOM _free_unlink();
//ATOM _free_append( ATOM p );
//extern int  _usedPairCount;
//extern int  _usedPairMaxCount;
//ATOM _used_unlink( ATOM p );
//ATOM _used_append( ATOM p );

extern ATOM (*cons)( ATOM a,ATOM b );
extern int  _reusedPairCount;
ATOM consNormal( ATOM a,ATOM b );


//static ATOM _gc_recycle_next( ATOM this,int force );
//static void _gc_mark( ATOM stop );
//static void _gc_recycle_pairs( ATOM stop,int force );
//static ATOM _ms_sweep_next( ATOM this,int m );
static void _ms_sweep_all_pairs( int m );
//static void _ms_mark_all_used_pairs( int m );
void _ms( ATOM env );
//static void _gc_ensure_all_used_pairs_not_marked();
//void _gc( ATOM stop,ATOM keep );
//static void _gc_clear( ATOM pair );


// END HEADER

#endif

#if defined(_pc_lisp_gc_c)

// CODE

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )                     \
  type set_##name( ATOM par,type name ){                       \
    ASSERT_PAIR( par );                                        \
    EXITIF( is_null( par ),"par is NIL",par );                 \
    if ( is_pair( _##name(par) ) )  _dec_ref( _##name(par) );  \
    _set_##name( par,name );                                   \
    if ( is_pair(name) )  _inc_ref( name );                    \
    return name;                                               \
  }                                                            \
  type name( ATOM par ){                                       \
    EXITIF( is_null( par ),"par is NIL",par );                 \
    return _##name( par );                                     \
  }

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );

void _inc_ref( ATOM p ){
  _set_ref( p,_ref(p)+1 );
}

// all unreferenced pairs MUST be recycled this way
int _recyclePairCount = 0;

void _recycle( ATOM p ){
    //WARN( "Reference count is 0 - GC'd",p );
    _used_unlink( p );
    _free_append( p );
    set_car( p,REC );  // these force recursive recycling
    set_cdr( p,REC );
    _recyclePairCount++;
}
int _decRecyclePairCount = 0;

void _dec_ref( ATOM p ){
  int c = _ref( p );
  EXITIF( c==0,"Reference count already 0",p );
  _set_ref( p,c-1 );
  if ( c==1 ){
    _decRecyclePairCount++;
    //WARN( "Reference count is 0 - GC'd",p );
    _recycle( p );
  }
}

FLAGS  sar[SIZE];         // string garbage markage

ATOM (*cons)( ATOM a,ATOM b ) = consNormal;

int _reusedPairCount  = 0;

ATOM consNormal( ATOM a,ATOM b ){
  _cm_check_mem();
  ATOM c = _remove_next_free();   // remove from free list
  EXITIF( is_null(c),"Cons FATAL: All cells used",NIL );
  if ( is_eq( car(c),REC ) ){
    _reusedPairCount++;
    //WARN( "Using recycled pair",c );
  }
  set_car( c,a );
  set_cdr( c,b );
  EXITIF( _gcm(c)!=0,"GC mark not zero",c );
  //PEEK( "done",c );
  //_cm_check_mem();  // may not be able to do this here since
  // nothing refs this new pair yet.
  return c;
}
int _sweepPairCount   = 0;

void _ms_sweep_all_pairs( int m ){
  //PEEK( "start",NIL );
  ATOM i = _mem( usedPairs );
  ATOM p = i;
  while ( ! is_null( p ) ){
    i = _mem( p );
    if ( _ref(p)==0 ){
      _sweepPairCount++;
      _recycle( p );
      i = _mem( usedPairs );
    }
    p = i;
  }
}

void _ms( ATOM env ){
#ifndef GC_ON
  return;
#endif
  //PEEK( "start",NIL );
  //WARNIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  //_ms_mark_all_used_pairs(24);
  //_cm_clear_marks_on_atom( env,24 );  // clear marks in environment
  //_cm_check_mem();
  _ms_sweep_all_pairs( 24 );
  _cm_check_mem();
  //_cm_check_mem_leak();
  //PEEK( "done",NIL );
}

/*

ATOM _gc_recycle_next(ATOM this, int force){
  exit(1);
  ATOM next = _mem( this );     // pair to make head of free list
  if ( _gcm(next)==1 || force ){            // marked so recycle
    MEM_PEEK( "next",next );
//    if ( is_pair( car(a) ) _dec_ref( car(a) );
//    if ( is_pair( cdr(a) ) _dec_ref( cdr(a) );
    _set_car( next,REC );                    // clear car
    _set_gcm( next,0 );                      // clear gc marks
    _recyclePairCount++;
    return _remove_next_used( this );
  }
  return next;
}

// mark all new used pairs that could be recycled right now
// stop marking at stop
void _gc_mark( ATOM stop ){
  exit(1);
  ATOM i = _mem(usedPairs);
  while ( ! is_eq( i,stop )){            // mark all for recycling
    //if ( _gcm(i)!=2 )  
    _set_gcm( i,1 );  // mark if not define or set*
    i = _mem(i);
  }
}

// recycles pairs from mem(usedpairs) downto but not including stop
void _recycle_pairs( ATOM stop,int force ){
  exit(1);
  ATOM i = usedPairs;
  while ( ! is_eq( _mem(i),stop ) ){
    i = _gc_recycle_next( i,force );
  }
}

void _gc( ATOM stop,ATOM keep ){
#ifndef GC_ON
  return;
#endif
  // keep may not have a refcount so skip it
  //PEEK( "",NIL );
  //PEEK( "inc",keep );
  //if ( is_pair(keep) ) _inc_ref( keep );
  //PEEK( "ms",keep );
  //_ms( gEnv );
  //PEEK( "dec",keep );
  //if ( is_pair(keep) ) _dec_ref( keep );
  //PEEK( "done",keep );
  //_mem_print_used_pairs( "gEnv",gEnv,stop );
  return;
}
*/

// ===================

/*
ATOM _ms_sweep_next( ATOM this,int m ){
  ATOM next = _mem( this );
  if ( _ref(next)==0 ){          // no refs now
    //PEEK( "Ref == 0",next );
    //_set_mrk( next,0 );          // clear gc marks
    _sweepPairCount++;
    return _remove_next_used( this );
  }
  return next;
}
*/


#endif
#endif

