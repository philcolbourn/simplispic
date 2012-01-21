
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

#endif
#endif
