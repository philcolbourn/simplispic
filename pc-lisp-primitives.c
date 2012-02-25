
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

#define MAKE_PRIMITIVE_0( proc )           \
  ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_0( read );

#define MAKE_PRIMITIVE_1( proc )           \
  ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_1( car         );
MAKE_PRIMITIVE_1( cdr         );
MAKE_PRIMITIVE_1( display     );
MAKE_PRIMITIVE_1( printa      );
MAKE_PRIMITIVE_1( printerr    );
MAKE_PRIMITIVE_1( disperr     );
//MAKE_PRIMITIVE_1( list        );  // FIXME: how to do vargs?
//MAKE_PRIMITIVE_1( eval1       );
MAKE_PRIMITIVE_1( exita       );
MAKE_PRIMITIVE_1( sym_to_str  );
MAKE_PRIMITIVE_1( str_to_sym  );


#define MAKE_PRIMITIVE_2( proc )           \
  ATOM prim_##proc( ATOM args,ATOM env );

MAKE_PRIMITIVE_2( cons    );
MAKE_PRIMITIVE_2( eval    );
MAKE_PRIMITIVE_2( set_car );
MAKE_PRIMITIVE_2( set_cdr );
//MAKE_PRIMITIVE_2( set     );
MAKE_PRIMITIVE_2( apply   );
MAKE_PRIMITIVE_2( str_ref );

#define MAKE_NUM_PRIMITIVE_1( proc,cfun )                           \
  ATOM proc( ATOM a );                                 \
  MAKE_PRIMITIVE_1( proc )  /* register is as well */

MAKE_NUM_PRIMITIVE_1( string_length,get_str_len );
MAKE_NUM_PRIMITIVE_1( get_num_tag,get_tag      );
MAKE_NUM_PRIMITIVE_1( get_num_val,get_val      );

#define MAKE_OP_2( proc,op )                           \
  ATOM proc( ATOM a,ATOM b );                          \
  MAKE_PRIMITIVE_2( proc )  /* register is as well */

// make basic operators
MAKE_OP_2( iadd,+  );
MAKE_OP_2( isub,-  );
MAKE_OP_2( imul,*  );
MAKE_OP_2( idiv,/  );
MAKE_OP_2( imod,%  );
MAKE_OP_2( ishl,<< );
MAKE_OP_2( ishr,>> );

#define MAKE_PRED_OP( proc,op )  \
  ATOM proc( ATOM a,ATOM b );    \
  MAKE_PRIMITIVE_2( proc )

MAKE_PRED_OP( ilt ,<    );
MAKE_PRED_OP( igt ,>    );
MAKE_PRED_OP( ilte,<=   );
MAKE_PRED_OP( igte,>=   );
MAKE_PRED_OP( ieq ,==   );
//MAKE_PRED_OP( and ,&&   );
//MAKE_PRED_OP( or  ,||   );

// wrap a c predicate function so it returns an atom
#define MAKE_PRED_1( pred,cfun )                    \
  ATOM pred( ATOM a );                              \
  MAKE_PRIMITIVE_1( pred )  /* register as well */

MAKE_PRED_1( atomp    ,is_atom   );
MAKE_PRED_1( listp    ,is_list   );
//MAKE_PRED_1( pairp    ,is_pair   );
//MAKE_PRED_1( nullp    ,is_null   );
MAKE_PRED_1( procp    ,is_proc   );
//MAKE_PRED_1( charp    ,is_chr    );
//MAKE_PRED_1( numberp  ,is_num    );
//MAKE_PRED_1( symbolp  ,is_symbol );
//MAKE_PRED_1( constantp,is_con    );
//MAKE_PRED_1( stringp  ,is_str    );

#define MAKE_PRED_2( pred,cfun )                    \
  ATOM pred( ATOM a,ATOM b );                       \
  MAKE_PRIMITIVE_2( pred )  /* register as well */

MAKE_PRED_2( eqp   ,is_eq    );
//MAKE_PRED_2( equalp,equal    );

#endif

#if defined(_pc_lisp_primitive_c)

// make primitive c functions using templates

#undef MAKE_PRIMITIVE_0

#define MAKE_PRIMITIVE_0( proc )                                    \
  ATOM prim_##proc( ATOM args,ATOM env ){                           \
    ATOM res = proc();                                              \
    return res;                                                     \
  }

MAKE_PRIMITIVE_0( read );

#undef MAKE_PRIMITIVE_1

#define MAKE_PRIMITIVE_1( proc )                                    \
  ATOM prim_##proc( ATOM args,ATOM env ){  /* arguments in list */  \
    /*peek( "prim_" #proc ": args",args );/**/                      \
    ATOM a = car( args );                                           \
    ATOM res = proc( a );                                           \
    /*peek( "prim_" #proc ": res",res );/**/                        \
    return res;                                                     \
  }

MAKE_PRIMITIVE_1( car         );
MAKE_PRIMITIVE_1( cdr         );
MAKE_PRIMITIVE_1( display     );
MAKE_PRIMITIVE_1( printa      );
MAKE_PRIMITIVE_1( printerr    );
MAKE_PRIMITIVE_1( disperr     );
//MAKE_PRIMITIVE_1( list        );  // FIXME: how to do vargs?
//MAKE_PRIMITIVE_1( eval1       );
MAKE_PRIMITIVE_1( exita       );
MAKE_PRIMITIVE_1( sym_to_str  );
MAKE_PRIMITIVE_1( str_to_sym  );

#undef MAKE_PRIMITIVE_2

#define MAKE_PRIMITIVE_2( proc )                                    \
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
MAKE_PRIMITIVE_2( apply   );
MAKE_PRIMITIVE_2( str_ref );
//MAKE_PRIMITIVE_2( sym_ref );

#undef MAKE_NUM_PRIMITIVE_1

#define MAKE_NUM_PRIMITIVE_1( proc,cfun )                           \
  ATOM inline proc( ATOM a ){                                 \
    return make_num( cfun(a) );       \
  }                                                    \
  MAKE_PRIMITIVE_1( proc )  /* register is as well */

MAKE_NUM_PRIMITIVE_1( string_length,get_str_len );
MAKE_NUM_PRIMITIVE_1( get_num_tag,get_tag      );
MAKE_NUM_PRIMITIVE_1( get_num_val,get_val      );


#undef MAKE_OP_2

#define MAKE_OP_2( proc,op )                           \
  ATOM inline proc( ATOM a,ATOM b ){                   \
    return make_num( get_num(a) op get_num(b) );       \
  }                                                    \
  MAKE_PRIMITIVE_2( proc )  /* register is as well */

// make basic operators
MAKE_OP_2( iadd,+  );
MAKE_OP_2( isub,-  );
MAKE_OP_2( imul,*  );
MAKE_OP_2( idiv,/  );
MAKE_OP_2( imod,%  );
MAKE_OP_2( ishl,<< );
MAKE_OP_2( ishr,>> );

#undef MAKE_PRED_OP

#define MAKE_PRED_OP( proc,op )            \
  ATOM inline proc( ATOM a,ATOM b ){       \
    /*RET_BOOL( get_num(a) op get_num(b) );/**/  \
    RET_BOOL( get_val(a) op get_val(b) );  \
  }                                        \
  MAKE_PRIMITIVE_2( proc )

MAKE_PRED_OP( ilt ,<    );
MAKE_PRED_OP( igt ,>    );
MAKE_PRED_OP( ilte,<=   );
MAKE_PRED_OP( igte,>=   );
MAKE_PRED_OP( ieq ,==   );
//MAKE_PRED_OP( and ,&&   );
//MAKE_PRED_OP( or  ,||   );

// wrap a c predicate function so it returns an atom
#undef MAKE_PRED_1

#define MAKE_PRED_1( pred,cfun )                    \
  inline ATOM pred( ATOM a ){                       \
    RET_BOOL( cfun(a) ); }                          \
  MAKE_PRIMITIVE_1( pred )  /* register as well */

MAKE_PRED_1( atomp    ,is_atom   );
MAKE_PRED_1( listp    ,is_list   );
//MAKE_PRED_1( pairp    ,is_pair   );
//MAKE_PRED_1( nullp    ,is_null   );
MAKE_PRED_1( procp    ,is_proc   );
//MAKE_PRED_1( charp    ,is_chr    );
//MAKE_PRED_1( numberp  ,is_num    );
//MAKE_PRED_1( symbolp  ,is_symbol );
//MAKE_PRED_1( constantp,is_con    );
//MAKE_PRED_1( stringp  ,is_str    );


#undef MAKE_PRED_2

#define MAKE_PRED_2( pred,cfun )      \
  inline ATOM pred( ATOM a,ATOM b ){  \
    RET_BOOL( cfun(a,b) );            \
  }                                   \
  MAKE_PRIMITIVE_2( pred )  /* register as well */

MAKE_PRED_2( eqp   ,is_eq    );
//MAKE_PRED_2( equalp,equal    );

#endif
#endif

