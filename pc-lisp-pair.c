
#ifndef __header
  #define _pc_lisp_pair_c
#endif

#ifndef _pc_lisp_pair_h
  #define _pc_lisp_pair_h
  #define __header

#ifdef __header

// HEADER

#include "pc-lisp-mem.c"
#include "pc-lisp-gc.c"
#include "pc-lisp-misc.c"

int          is_pair  ( ATOM p );
int          is_atom  ( ATOM a );
int          is_list  ( ATOM l );
int          is_symbol( ATOM s );
int          is_null  ( ATOM a );
int          is_eq    ( ATOM a,ATOM b );

int          get_tag( ATOM a );
int          get_val( ATOM a );

// END HEADER

#endif

#if defined(_pc_lisp_pair_c)

// CODE

// predicates

int is_eq( ATOM a,ATOM b ){
  return a.atm==b.atm;
}

int is_pair( ATOM p ){
  //when ()=NIL return is_par(p) && ( ! is_null(p) );  // how did I make this mistake?
  return is_par(p);
}

// FIXME: scheme says a list must have cdr=nil or cdr=pair
int is_list( ATOM p ){
  //return is_par(p);
  //return is_par(p) && is_pair( cdr(p) );  // breaks pc-list
  return is_null(p) || is_par(p);  // FIXME: does not work for circular lists
  //return is_null(p) || ( is_par(p) && is_list( cdr(p) ) );
}

int is_atom( ATOM p ){
  //when ()=NIL return is_null(p) || ( ! is_par(p) );
  return ! is_par(p);
}

int is_symbol( ATOM a ){ return is_sym(a); }

int is_null( ATOM a ){ return is_eq( a,NIL ); }

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

int is_in( ATOM p,ATOM l ){
LOOP:
  if ( is_null(l) ) return FALSE;
  if ( ! is_pair(l) ) return FALSE;  // l not list
  if ( _mrk(l)==1 ){  // been here
    PEEK( "LOOP",l );
    return FALSE;
  }
  _set_mrk( l,1 );  // mark pair
  if ( is_eq(p,l) ) return TRUE;  // p in l
  if ( is_in( p,car(l) ) ) return TRUE;
  l = cdr( l );
  goto LOOP;
}

#endif
#endif

