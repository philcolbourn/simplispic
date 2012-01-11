
#ifndef __header
  #define _pc_lisp_test_c
#endif

#ifndef _pc_lisp_test_h
  #define _pc_lisp_test_h
  #define __header

#ifdef __header

// HEADER
#include "pc-lisp-print.c"

#define LOG(m)        fprintf( stderr,"<%s>\n",m )
#define FORMAT(a)     printFormat[ get_tag(a) ][DUMP]
#define TAG_FORMAT(t) printFormat[ t ][DUMP]

#define DUMP_ATOM(a)                                          \
  switch ( get_tag(a) ){                                      \
  case SYM:                                                   \
    if ( get_sym(a)<0 )                                       \
      fprintf( stderr,TAG_FORMAT(CHR),-get_sym(a) );          \
    else                                                      \
      fprintf( stderr,FORMAT(a),symbols[ get_sym(a) ].name ); \
    break;                                                    \
  case STR:                                                   \
    fprintf( stderr,FORMAT(a),strings[ get_str(a) ] );        \
    break;                                                    \
  default:                                                    \
    fprintf( stderr,FORMAT(a),get_val(a) );                   \
  }

/*
FIXME: no longer used

// test if atoms e and r are same value

#define TESTa(e,r)                             \
  fprintf(stderr, "Testing %s==%s: ", #e, #r); \
  if ( is_eq( (e),(r) ) ){                     \
    fputs("passed.\n", stderr);                \
  }                                            \
  else{                                        \
    fputs("FAILED: ", stderr);                 \
    printa(e);                                 \
    fputs("!=", stderr);                       \
    printa(r);                                 \
    fputs(".\n", stderr);                      \
    exit(1);                                   \
  }

// test if e==r
  
#define TESTb(e,r)                             \
  fprintf(stderr, "Testing %s==%s: ", #e, #r); \
  if ( (e)==(r) ){                             \
    fputs("passed.\n", stderr);                \
  }                                            \
  else{                                        \
    fputs("FAILED.\n", stderr);                \
    exit(0);                                   \
  }
*/
//void evalExit(char *m, ATOM exp, ATOM env){
//FIXME: no longer used void _test();

#include "pc-lisp-mem.c"

// END HEADER

#endif

#if defined(_pc_lisp_test_c)

// CODE



/*
void evalExit(char *m, ATOM exp, ATOM env){
  fprintf(stderr, "\nEval Error: %s evaluating ", m);
  fprinta(stderr, exp);  fprintf(stderr, " in environment ");
  fprinta(stderr, env);  fprintf(stderr, "\n");
  exit(1);
}
*/

/*
void _test(){
  ATOM a,b;
  //ATOM gEnv=NIL;  // private test environment - like chroot!
  // does not work since env is passed as a parameter - how to make a local env?
  fputs("<_test>\n",stderr);

  TESTb( equal( readString(""),END ) , TRUE );
  TESTb( equal( readString("()"),readString("()") ) , TRUE );
  TESTb( equal( NIL,NIL ) , TRUE );
  TESTb( equal( readString("123"),readString("123") ) , TRUE );
  TESTb( equal( readString("abc"),readString("123") ) , FALSE);
  TESTa( car( cons(NIL,NIL)   ) , NIL );
  TESTa( cdr( cons(NIL,NIL)   ) , NIL );
  TESTa( car( cons(a=readString("123"),NIL)  ) , a );
  TESTa( cdr( cons(a,NIL)  ) , NIL );
  TESTa( cdr( cons(a,b=readString("123")) ) , b );
  TESTa( cdr( cons(NIL,b)  ) , b );
  TESTa( car( cons(NIL,b)  ) , NIL );
  TESTb( equal( readString("abcdef"),readString("abcdef") ) , TRUE );

  ATOM x1=readString("1");
  ATOM x2=readString("2");
  ATOM x3=readString("3");
  ATOM x4=readString("4");
  ATOM x5=readString("5");
  ATOM x6=readString("6");
  TESTb( equal( readString("(1 2 (3 4) 5 6)"),cons(x1,cons(x2,cons( cons(x3,cons(x4,NIL)) , cons(x5, cons(x6,NIL)) )))) , TRUE );
  
  TESTb( equal( readString("(1 . 2)"),cons(readString("1"),readString("2"))) , TRUE );
  // this should fail bad since 3 is not a pair
  // TESTa( eval(readString("(car 3)"),NIL),MTY );
  TESTb( equal( eval(readString("(car (quote (1 2)))"),NIL),readString("1") ) , TRUE );
  TESTb( equal( eval(readString("(cdr (quote (1 2)))"),NIL),readString("(2)") ) , TRUE );
  eval( readString("(define x 3)"),gEnv );  
  eval( readString("(define q (quote (1 2 3)))"),gEnv );  
  eval( readString("x"),gEnv );
  eval( readString("(define x (quote (car (quote (1 2 3)))))"),gEnv );
  fprinta( stderr, eval( readString("x"),gEnv ) );
  fprinta( stderr, eval( readString("(x)"),gEnv ) );

  fputs("\n</_test>\n",stderr);
}
*/

#endif
#endif

