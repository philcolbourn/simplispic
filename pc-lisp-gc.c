
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
#define REC          MAKE_CON( -10)     // recycled pair
#define FOR          MAKE_CON( -11)     // Forced recycled pair

typedef union{
  struct{
    unsigned int gc:2;
    unsigned int mark:10;
  };
  int  val;
} FLAGS;

extern FLAGS  sar[SIZE];

#include "pc-lisp-misc.c"

extern int   _sweepPairCount;
extern int   _recycleStrCount;

extern int   _trace_enter;
extern ATOM  _keep;

// ADTs

       ATOM   set_car( ATOM p,ATOM a );
       ATOM   set_cdr( ATOM p,ATOM a );
       ATOM   car( ATOM p );
       ATOM   cdr( ATOM p );

       void  _inc_ref( ATOM p );

extern int   _recyclePairCount;
       void  _recycle( ATOM p );

extern int   _decRecyclePairCount;
       void  _dec_ref( ATOM p );
//extern ATOM (*cons)( ATOM a,ATOM b );
extern int   _reusedPairCount;
//       ATOM   consNormal( ATOM a,ATOM b );
       ATOM   cons( ATOM a,ATOM b );
       void  _gc( ATOM f,ATOM t,ATOM k );

#define TVAL 3009 // 4022 //3992

#define TRACE_PEEK( m,a ){  \
  PEEK( m,a );                \
  EXITIF( ! _is_used( a ),#a " is not used",a );                   \
  if ( ! _is_used( a ) ) PEEK( #a " is not used",a );                   \
  if ( _is_free( a ) ) PEEK( #a " is free",a );                   \
}  

#define TRACE( a,t ){                                               \
  if ( _trace_enter==0 ){  \
    _trace_enter = 1;\
    if ( a.atm==t ) PEEK( #a ".atm=" #t,a );                        \
         if ( is_eq( a,make_par(t) ) ) TRACE_PEEK( "par(" #a ")=" #t,a )   \
    else if ( is_eq( a,make_num(t) ) ) PEEK( "num(" #a ")=" #t,a   )   \
    else if ( is_eq( a,make_sym(t) ) ) PEEK( "sym(" #a ")=" #t,a   )   \
    else if ( is_eq( a,make_str(t) ) ) PEEK( "str(" #a ")=" #t,a   )   \
    else if ( is_eq( a,make_con(t) ) ) PEEK( "con(" #a ")=" #t,a   )   \
    else if ( is_eq( a,make_chr(t) ) ) PEEK( "chr(" #a ")=" #t,a   );  \
                                                                    \
         if ( is_eq( a,EFL ) ) TRACE_PEEK( #a " is EFL!",a )            \
    else if ( is_eq( a,EUL ) ) TRACE_PEEK( #a " is EUL!",a );            \
    _trace_enter = 0;\
  }                                                                 \
}

//#define MEM_DEBUG

#ifdef MEM_DEBUG                                         
  #define MEM_DEBUG_LINE( m ) \
    fprintf( stderr,"-- %s  " m "  %s %d\n",__func__,__FILE__,__LINE__ );
  #define MEM_PEEK( m,a ) PEEK( m,a )
#else
  #define MEM_DEBUG_LINE( m )
  #define MEM_PEEK( m,a )
#endif

#define MARK3                                                           \
      MEM_DEBUG_LINE( "MARK3.1" );                                      \
      /*FILE_LINE;/**/                                                  \
  ATOM _save = _mem( usedPairs );                                       \
      /*MEM_PEEK( "",_save );/**/                                       \
      MEM_DEBUG_LINE( "MARK3.2" );                                       
  
#define REMARK3                                                         \
      MEM_DEBUG_LINE( "REMARK3.1" );                                    \
  _save = _mem( usedPairs );                                            \
      MEM_DEBUG_LINE( "REMARK3.2" );                                       


#define RETURN3(a) {                                                    \
  ATOM _ret = (a);                                                      \
      MEM_DEBUG_LINE( "RETURN3.1" );                                    \
  /*EXITIF( is_eq( car(_save),REC ),"SAVE POINT RECYCLED!",_save );/**/ \
  _gc( _mem(usedPairs),_save,_ret );                                    \
  /*_mem_print_used_pairs( "RETURN3",usedPairs,_save );/**/             \
      MEM_DEBUG_LINE( "RETURN3.2" );                                    \
  return _ret;                                                          \
}

#define KEEP3(a) {                                                      \
      MEM_DEBUG_LINE( "KEEP3.1" );                                      \
  /*EXITIF( is_eq( car(_save),REC ),"SAVE POINT RECYCLED!",_save );/**/ \
  _gc( _mem(usedPairs),_save,NIL );                                     \
  /*_mem_print_used_pairs( "KEEP3",usedPairs,_save );/**/               \
      MEM_DEBUG_LINE( "KEEP3.2" );                                      \
}

//#define VOID3() {                                                       \
//      MEM_DEBUG_LINE( "VOID3.1" );                                      \
//  _ms_sweep_new_pairs( _save,NIL,15 );                                  \
//      MEM_DEBUG_LINE( "VOID3.2" );                                      \
//  return;                                                               \
//}

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

//#define caaaar(a)    car( caaar( a ) )  // _4TH down
//#define caaadr(a)    car( caadr( a ) )
//#define caadar(a)    car( cadar( a ) )
//#define caaddr(a)    car( caddr( a ) )  // _1of3 _1ST of _3RD 
//#define cadaar(a)    car( cdaar( a ) )
//#define cadadr(a)    car( cdadr( a ) )
//#define caddar(a)    car( cddar( a ) )
#define cadddr(a)    car( cdddr( a ) )  // _4TH

//#define cdaaar(a)    cdr( caaar( a ) )
//#define cdaadr(a)    cdr( caadr( a ) )
//#define cdadar(a)    cdr( cadar( a ) )
//#define cdaddr(a)    cdr( caddr( a ) )  // _Rof3 rest of _3RD
//#define cddaar(a)    cdr( cdaar( a ) )
//#define cddadr(a)    cdr( cdadr( a ) )
//#define cdddar(a)    cdr( cddar( a ) )
//#define cddddr(a)    cdr( cdddr( a ) )  // rest after _4TH


// END HEADER

#endif

#if defined(_pc_lisp_gc_c)

// CODE

int _trace_enter = 0;

// Initialize car of pair - only used legally by cons
//
ATOM init_car( ATOM p,ATOM a ){
      //EXITIF( is_eq( p,EUL ),"p is EUL",p );
  _set_car( p,a );
  if ( is_pair(a) ) _inc_ref( a );  // no need to mark this
  return a;
}

ATOM init_cdr( ATOM p,ATOM a ){
  _set_cdr( p,a );
  if ( is_pair(a) ) _inc_ref( a );
  return a;
}

ATOM car( ATOM p ){ return _car( p ); }
ATOM cdr( ATOM p ){ return _cdr( p ); }

ATOM set_car( ATOM p,ATOM a ){
      //TRACE( p,TVAL );
      //TRACE( a,TVAL );
      //ASSERT_PAIR( p );
  ATOM o = _car(p);
  if ( is_eq( a,o ) ) return a;  // nothing to do
  if ( is_pair(a) ) {  // indicate possible loop
    // if a is younger, then loop detected?
    // (cons a b) mean make a pair of a and b
    // a and b must already exist therefore they are older
    // a pair's age is it's position in used list
    // just need to check if a is newer.
    // if it is, mark as possible circular list
    //if ( _is_newer( a,p ) ){
    //  _set_lop( p,1 );
      // now if p is reachable from a we have a circular list
    //}
    _set_car( p,a );  // make_par( -get_par(a))
    _inc_ref( a );  // avoid race, inc b4 dec
  }
  else{
    _set_car( p,a );
  }
      //EXITIF( _is_end_free_list( a ),"end free list",p );
      //EXITIF( _is_end_used_list( a ),"end used list",p );
      //EXITIF( is_eq( a,NMT ),"car NOT PAIR is NMT",p )
  if ( is_pair(o) ) _dec_ref( o );
  return a;
}

ATOM set_cdr( ATOM p,ATOM a ){
  ATOM o = _cdr(p);
  if ( is_eq( a,o ) ) return a;  // nothing to do
  if ( is_pair(a) ) {  // indicate possible loop
    _set_cdr( p,a );  // make_par( -get_par(a))
    _inc_ref( a );  // avoid race, inc b4 dec
  }
  else{
    _set_cdr( p,a );
  }
  if ( is_pair(o) ) _dec_ref( o );
  return a;
}

// increase ref count on p
// ignore if global environment (except first time)
//
void _inc_ref( ATOM p ){
      //TRACE( p,TVAL );
      EXITIF( _ref(p)<0,"Reference count sub zero - should never happen!",p );
      //EXITIF( ! _is_used(p),"Pair not on used list!",p );
      //_mem_print_used_pairs( "rec",p,NIL );
  //if ( ! is_pair(p) ) return;
  if ( is_eq( p,gEnv ) ){
         //PEEK( "hit gEnv",make_num(_ref(p)) );
    if ( _ref(p)>0 ) return;  // only do once for gEnv
  }
  _set_ref( p,_ref(p)+1 );
}

// all unreferenced pairs MUST be recycled this way
int _recyclePairCount = 0;

// Recycle a pair
// This should only be called when a pair's reference
// count reduces to zero.
//
void _recycle( ATOM p ){
        //TRACE( p,TVAL );
        EXITIF( _ref(p)!=0,"Reference count not zero - should never happen!",p );
    // swapped order to gc car and cdr before moving to free list
    set_car( p,REC );  // these force recursive recycling
    set_cdr( p,REC );
    //_set_lop( p,0 );  // reset any loop flag
    _used_unlink( p );
    _free_append( p );
    _recyclePairCount++;
}

int _decRecyclePairCount = 0;

// decrease ref count on p
// gEnv is ignored as well
//
void _dec_ref( ATOM p ){
  //if ( ! is_pair(p) ) return;
  if ( is_eq( p,gEnv ) ) return;
      EXITIF( _ref(p)==0,"Reference count already 0 - something badly wrong!",p );
  _set_ref( p,_ref(p)-1 );
  if ( _ref(p)==0 ){
    _decRecyclePairCount++;
        //WARN( "Reference count is 0 - GC'd",p );
    //  _recycle( p );  // don't do this anymore
  }
}

FLAGS  sar[SIZE];         // string garbage markage

//ATOM (*cons)( ATOM a,ATOM b ) = consNormal;

int _reusedPairCount  = 0;

//ATOM consNormal( ATOM a,ATOM b ){
ATOM cons( ATOM a,ATOM b ){
  ATOM c = _remove_next_free();   // remove from free list

      EXITIF( _is_end_free_list( freePairs ),"Cons FATAL: All cells used",NIL );
  if ( is_eq( car(c),MTY ) ){
        EXITIF( _ref(c)!=0,"GC reference count not zero on fresh pair"
                           " - should be impossible.",make_num(_ref(c)) );
  }
  if ( is_eq( car(c),REC ) ){
        EXITIF( _ref(c)!=0,"GC reference count not zero on recycled pair"
                           " - should be impossible.",c );  // printing this cell could be bad
    _reusedPairCount++;
        //WARN( "Using recycled pair",c );
  }
      EXITIF( _ref(c)!=0,"GC reference count not zero"
                         " - this should never happen.",make_num(_ref(c)) );  // printing this cell could be bad

  init_car( c,a );
  init_cdr( c,b );
  return c;
}

int _sweepPairCount   = 0;

// GC from f to t, not processing t or k
// GC is ref count is zero

void _gc( ATOM f,ATOM t,ATOM k ){
#ifndef GC_ON
  return;
#endif
LOOP:
  if ( is_eq( f,t ) ) return;                 // done
  ATOM n = _mem(f);
  if ( ! is_eq( f,k ) ){                       // not k 
    if ( _ref(f)==0 ){                          // recycle this
      _sweepPairCount++;
      _recycle(f);                              // only allowed to recycle f
      //n = _mem(usedPairs );  // only required if recycle is recursive
    }
  }
  f = n;
  goto LOOP;                                      // try next
}

#endif
#endif

