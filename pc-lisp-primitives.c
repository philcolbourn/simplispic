
#ifndef __header
  #define _pc_lisp_primitive_c
#endif

#ifndef _pc_lisp_primitive_h
  #define _pc_lisp_primitive_h
  #define __header    

#ifdef __header
#include "pc-lisp-mem.c"
#include "pc-lisp-read2.c"
#include "pc-lisp-print.c"

#define MAKE_PRIMITIVE_0( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_0( read );

#define MAKE_PRIMITIVE_1( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_1( car );
MAKE_PRIMITIVE_1( cdr );
MAKE_PRIMITIVE_1( display );
MAKE_PRIMITIVE_1( printa );
MAKE_PRIMITIVE_1( printerr );
//MAKE_PRIMITIVE_1( list );  // FIXME: how to do vargs?
//MAKE_PRIMITIVE_1( eval1 );
MAKE_PRIMITIVE_1( exita );

/*
MAKE_PRIMITIVE_1( caar );
MAKE_PRIMITIVE_1( cadr );

MAKE_PRIMITIVE_1( cdar );
MAKE_PRIMITIVE_1( cddr );

MAKE_PRIMITIVE_1( caaar );
MAKE_PRIMITIVE_1( caadr );
MAKE_PRIMITIVE_1( cadar );
MAKE_PRIMITIVE_1( caddr );

MAKE_PRIMITIVE_1( cdaar );
MAKE_PRIMITIVE_1( cdadr );
MAKE_PRIMITIVE_1( cddar );
MAKE_PRIMITIVE_1( cdddr );

MAKE_PRIMITIVE_1( caaaar );
MAKE_PRIMITIVE_1( caaadr );
MAKE_PRIMITIVE_1( caadar );
MAKE_PRIMITIVE_1( caaddr );

MAKE_PRIMITIVE_1( cadaar );
MAKE_PRIMITIVE_1( cadadr );
MAKE_PRIMITIVE_1( caddar );
MAKE_PRIMITIVE_1( cadddr );

MAKE_PRIMITIVE_1( cdaaar );
MAKE_PRIMITIVE_1( cdaadr );
MAKE_PRIMITIVE_1( cdadar );
MAKE_PRIMITIVE_1( cdaddr );

MAKE_PRIMITIVE_1( cddaar );
MAKE_PRIMITIVE_1( cddadr );
MAKE_PRIMITIVE_1( cdddar );
MAKE_PRIMITIVE_1( cddddr );
*/

#define MAKE_PRIMITIVE_2( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_2( cons    );
MAKE_PRIMITIVE_2( eval    );
MAKE_PRIMITIVE_2( set_car );
MAKE_PRIMITIVE_2( set_cdr );
//MAKE_PRIMITIVE_2( set     );
//MAKE_PRIMITIVE_2( apply   );


#define MAKE_OP( proc,op )                       \
ATOM proc( ATOM a,ATOM b );                      \
MAKE_PRIMITIVE_2( proc )  /* register is as well */

// make basic operators
MAKE_OP( iadd,+  );
MAKE_OP( isub,-  );
MAKE_OP( imul,*  );
MAKE_OP( idiv,/  );
MAKE_OP( imod,%  );
MAKE_OP( ishl,<< );
MAKE_OP( ishr,>> );

#define MAKE_PRED_OP( proc,op )          \
ATOM proc( ATOM a,ATOM b );              \
MAKE_PRIMITIVE_2( proc )

MAKE_PRED_OP( ilt,<   );
MAKE_PRED_OP( igt,>   );
MAKE_PRED_OP( ilte,<= );
MAKE_PRED_OP( igte,>= );
MAKE_PRED_OP( ieq,==  );
MAKE_PRED_OP( and,&&  );
MAKE_PRED_OP( or,||   );

// wrap a c predicate function so it returns an atom
#define MAKE_PRED_1( pred,cfun )                  \
ATOM pred( ATOM a );                              \
MAKE_PRIMITIVE_1( pred )  /* register as well */

MAKE_PRED_1( atomp,is_atom );
MAKE_PRED_1( listp,is_list );
MAKE_PRED_1( pairp,is_pair );
MAKE_PRED_1( nullp,is_null );
MAKE_PRED_1( procp,is_proc );


#define MAKE_PRED_2( pred,cfun )    \
ATOM pred( ATOM a,ATOM b );         \
MAKE_PRIMITIVE_2( pred )  /* register as well */

MAKE_PRED_2( eqp,is_eq    );
MAKE_PRED_2( equalp,equal );

#endif

#if defined(_pc_lisp_primitive_c)

// make primitive c functions using templates

#undef MAKE_PRIMITIVE_0

#define MAKE_PRIMITIVE_0( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env ){                           \
  ATOM res = proc();                                              \
  return res;                                                     \
}

MAKE_PRIMITIVE_0( read );

#undef MAKE_PRIMITIVE_1

#define MAKE_PRIMITIVE_1( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env ){  /* arguments in list */  \
  /*peek( "prim_" #proc ": args",args );/**/                      \
  ATOM a = car( args );                                           \
  ATOM res = proc( a );                                           \
  /*peek( "prim_" #proc ": res",res );/**/                        \
  return res;                                                     \
}

MAKE_PRIMITIVE_1( car );
MAKE_PRIMITIVE_1( cdr );
MAKE_PRIMITIVE_1( display );
MAKE_PRIMITIVE_1( printa );
MAKE_PRIMITIVE_1( printerr );
//MAKE_PRIMITIVE_1( list );  // FIXME: how to do vargs?
//MAKE_PRIMITIVE_1( eval1 );
MAKE_PRIMITIVE_1( exita );

/*
MAKE_PRIMITIVE_1( caar );
MAKE_PRIMITIVE_1( cadr );

MAKE_PRIMITIVE_1( cdar );
MAKE_PRIMITIVE_1( cddr );

MAKE_PRIMITIVE_1( caaar );
MAKE_PRIMITIVE_1( caadr );
MAKE_PRIMITIVE_1( cadar );
MAKE_PRIMITIVE_1( caddr );

MAKE_PRIMITIVE_1( cdaar );
MAKE_PRIMITIVE_1( cdadr );
MAKE_PRIMITIVE_1( cddar );
MAKE_PRIMITIVE_1( cdddr );

MAKE_PRIMITIVE_1( caaaar );
MAKE_PRIMITIVE_1( caaadr );
MAKE_PRIMITIVE_1( caadar );
MAKE_PRIMITIVE_1( caaddr );

MAKE_PRIMITIVE_1( cadaar );
MAKE_PRIMITIVE_1( cadadr );
MAKE_PRIMITIVE_1( caddar );
MAKE_PRIMITIVE_1( cadddr );

MAKE_PRIMITIVE_1( cdaaar );
MAKE_PRIMITIVE_1( cdaadr );
MAKE_PRIMITIVE_1( cdadar );
MAKE_PRIMITIVE_1( cdaddr );

MAKE_PRIMITIVE_1( cddaar );
MAKE_PRIMITIVE_1( cddadr );
MAKE_PRIMITIVE_1( cdddar );
MAKE_PRIMITIVE_1( cddddr );
*/
#undef MAKE_PRIMITIVE_2

#define MAKE_PRIMITIVE_2( proc )                                  \
ATOM prim_##proc( ATOM args,ATOM env ){  /* arguments in list */  \
  /*peek( "prim_" #proc ": args",args );/**/                      \
  ATOM a = car( args );                                           \
  ATOM b = cadr( args );                                          \
  ATOM res = proc( a,b );                                         \
  /*peek( "prim_" #proc ": res",res );/**/                        \
  return res;                                                     \
}

MAKE_PRIMITIVE_2( cons    );
MAKE_PRIMITIVE_2( eval    );
MAKE_PRIMITIVE_2( set_car );
MAKE_PRIMITIVE_2( set_cdr );
//MAKE_PRIMITIVE_2( set     );
//MAKE_PRIMITIVE_2( apply   );

#undef MAKE_OP

#define MAKE_OP( proc,op )                       \
ATOM inline proc( ATOM a,ATOM b ){               \
  return make_num( get_num(a) op get_num(b) );   \
}                                                \
MAKE_PRIMITIVE_2( proc )  /* register is as well */

// make basic operators
MAKE_OP( iadd,+  );
MAKE_OP( isub,-  );
MAKE_OP( imul,*  );
MAKE_OP( idiv,/  );
MAKE_OP( imod,%  );
MAKE_OP( ishl,<< );
MAKE_OP( ishr,>> );

#undef MAKE_PRED_OP

#define MAKE_PRED_OP( proc,op )          \
ATOM inline proc( ATOM a,ATOM b ){       \
  RET_BOOL( get_num(a) op get_num(b) );  \
}                                        \
MAKE_PRIMITIVE_2( proc )

MAKE_PRED_OP( ilt,<   );
MAKE_PRED_OP( igt,>   );
MAKE_PRED_OP( ilte,<= );
MAKE_PRED_OP( igte,>= );
MAKE_PRED_OP( ieq,==  );
MAKE_PRED_OP( and,&&  );
MAKE_PRED_OP( or,||   );

// wrap a c predicate function so it returns an atom
#undef MAKE_PRED_1

#define MAKE_PRED_1( pred,cfun )                  \
inline ATOM pred( ATOM a ){                       \
  RET_BOOL( cfun(a) ); }                          \
MAKE_PRIMITIVE_1( pred )  /* register as well */

MAKE_PRED_1( atomp,is_atom );
MAKE_PRED_1( listp,is_list );
MAKE_PRED_1( pairp,is_pair );
MAKE_PRED_1( nullp,is_null );
MAKE_PRED_1( procp,is_proc );

#undef MAKE_PRED_2

#define MAKE_PRED_2( pred,cfun )    \
inline ATOM pred( ATOM a,ATOM b ){  \
  RET_BOOL( cfun(a,b) );            \
}                                   \
MAKE_PRIMITIVE_2( pred )  /* register as well */

MAKE_PRED_2( eqp,is_eq    );
MAKE_PRED_2( equalp,equal );

#endif
#endif

