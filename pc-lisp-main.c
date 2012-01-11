
#ifndef __header
  #define _pc_lisp_main_c
#endif

#ifndef _pc_lisp_main_h
  #define _pc_lisp_main_h
  #define __header

#ifdef __header

// HEADER

//#include "pc-lisp.h"
#include "pc-lisp-mem.c"
#include "pc-lisp-test.c"
#include "pc-lisp-read2.c"
#include "pc-lisp-print.c"
#include "pc-lisp-primitives.c"
#include "pc-lisp-adt.c"
#include "pc-lisp-eval-adt.c"

#define BOOL( pred ) ( (pred) ? (TRU) : (NIL) )
#define RET_BOOL( pred ) return BOOL( pred )
#define EQ_TAG(a,b)  ( get_tag(a)==get_tag(b) )
#define NE_TAG(a,b)  ( ! EQ_TAG(a,b) )


//typedef unsigned char CHAR;

// Primitive procedures
extern ATOM (*primFns[SIZE])();
extern int    freeFun;


//#define MAKE_ATOM(tag,val) (ATOM){.val=(val), .tag=(tag)}
//#define MAKE_PRIM(cfn)  (ATOM){.pfnval=(cfn), .pfntag=PFN}



#define FALSEIF( pred )  if ( pred ) return FALSE;
#define TRUEIF( pred )   if ( pred ) return TRUE;
extern ATOM    gEnv;             // global environment



void    boot();            // warm-boot interpreter
// predicates

int     equal    ( ATOM a,ATOM b );
int     not      ( int a );

//int     isNIL( ATOM a );

ATOM    pair ( ATOM key,ATOM val );
ATOM    assoc( ATOM sym,ATOM env );
ATOM    eval ( ATOM exp,ATOM env );
ATOM    apply( ATOM proc,ATOM args );
ATOM    exita( ATOM val );

//ATOM    readLoop();
ATOM    repl();
ATOM    readString( char *s );
void    _strcpy( char *d,char *s,int n );

ATOM assoc2( ATOM sym,ATOM env );
ATOM assoc_kvp( ATOM sym,ATOM env );
ATOM make_env();
ATOM extend_env( ATOM env );
ATOM env_find_kvp( ATOM env );
ATOM evallst( ATOM lst,ATOM env );
ATOM evalseq( ATOM seq,ATOM env );
ATOM make_frame( ATOM alst,ATOM env );
ATOM addKVPair3( ATOM kvp,ATOM env );
int loop;
ATOM _global_save;

ATOM repl();
int main();

// END HEADER
#endif

#if defined(_pc_lisp_main_c)

// CODE

ATOM (*primFns[SIZE])();


ATOM _bad_primative_fn(){
  fprintf( stderr, "ERROR: Undefined primitive function.\n" );
  exit(1);
}



#define REGISTER_PRIMITIVES_0(i,n)                               \
{                                                                \
  /**/MARK3;/**/                                                 \
  primFns[i] = prim_##n;                                         \
  ATOM prim = eval(                                              \
    readString("(define " #n " (primitive () " #i "))"),         \
    gEnv );                                                      \
  /**/PEEK( "",prim );/**/                                   \
  /*KEEP3( cdr( prim ) );/**/   /* correct off all are defines*/ \
  /**/KEEP3( NIL );/**/         /* correct iff all are defines*/ \
}

#define REGISTER_PRIMITIVES_1(i,n)                               \
{                                                                \
  /**/MARK3;/**/                                                 \
  primFns[i] = prim_##n;                                         \
  ATOM prim = eval(                                              \
    readString("(define " #n " (primitive (a) " #i "))"),        \
    gEnv );                                                      \
  /**/PEEK( "",prim );/**/                                   \
  /*KEEP3( cdr( prim ) );/**/  /* correct iff all are defines*/  \
  /**/KEEP3( NIL );/**/        /* correct iff all are defines*/  \
}

#define REGISTER_PRIMITIVES_2(i,n)                               \
{                                                                \
  /**/MARK3/**/;                                                 \
  primFns[i] = prim_##n;                                         \
  ATOM prim = eval(                                              \
    readString( "(define " #n " (primitive (a b) " #i "))"),     \
    gEnv );                                                      \
  /**/PEEK( "",prim );/**/                                   \
  /*KEEP3( cdr( prim ) );/**/  /* correct iff all are defines*/  \
  /**/KEEP3( NIL );/**/        /* correct iff all are defines*/  \
}

void boot(){
  int i;
  fputs( "Booting...\n",stderr );
  freePairs = make_par(1);               // [1] is first free pair
  usedPairs = make_par(0);               // [0] is used from begining
  for (i=0; i<SIZE; i++){
    ATOM p = make_par(i);       
    _set_mem( p,make_mem( (i+1)%SIZE ) );  // chain free cells
    //if ( i>=2 ){
      _set_car( p,MTY );
      _set_cdr( p,MTY );
      _set_gcm( p,0 );                       // mark all in use
      _set_mrk( p,0 );
    //}
    symbols[i].name[0] = 0;
    _strcpy( symbols[i].name,"UNDEF SYM",10 );
    strings[i]         = "UNDEF STR";
    primFns[i]         = _bad_primative_fn;
    sar[i].val         = 0;
  }
  _set_car( usedPairs,readString( "\"*used pairs*\"" ) );
  _set_mem( usedPairs,NIL );  // need to fix used ist
/*
  // test free and used lists
  dump(5);
  ATOM test1 = _remove_next_free();
  setcar( test1,readString("test1") );
  dump(5);
  ATOM test2 = _remove_next_free();
  setcar( test2,readString("test2") );
  dump(5);
  _remove_next_used(usedPairs);
  dump(5);
  _remove_next_used(usedPairs);
  dump(5);
  // should be same as when started
  //exit(1);
*/
  // since all cells are erased, global environment should be empty
  //   ie a NIL frame
  //ATOM globals = readString("globals" );  // make a globals symbol
  // FIXME: make frame ADT?

  fputs( "Create global environment...\n",stderr );
  MARK3;
  gEnv    = cons( NIL,NIL );  // global environment -> empty environment 

  fputs( "Create keyword symbols...\n",stderr );
  kw_quote       = readString( "quote"       );  
  kw_lambda      = readString( "lambda"      );  
  kw_closure     = readString( "closure"     );  
  kw_let         = readString( "let"         );  
  kw_let_star    = readString( "let*"        );  
  kw_letrec      = readString( "letrec"      );  
  kw_primitive   = readString( "primitive"   );
  kw_define      = readString( "define"      );
  kw_set         = readString( "set!"        );
  kw_read        = readString( "read"        );  
  kw_load        = readString( "load"        );  
  kw_exit        = readString( "exit"        );  
  kw_eval        = readString( "eval"        );
  kw_eval1       = readString( "eval1"       );
  kw_apply       = readString( "apply"       );
  kw_if          = readString( "if"          );  
  kw_cond        = readString( "cond"        );
  kw_delay       = readString( "delay"       );  
  kw_progn       = readString( "progn"       );
  kw_begin       = readString( "begin"       );
  kw_cons        = readString( "cons"        );
  kw_cons_stream = readString( "cons-stream" );
  kw_list        = readString( "list"        );

  tag_env        = readString( "env"         );

  fputs( "Create primitive procedures...\n",stderr );
  REGISTER_PRIMITIVES_1(  1,car     );
  REGISTER_PRIMITIVES_1(  2,cdr     );
  REGISTER_PRIMITIVES_2(  3,cons    );
  REGISTER_PRIMITIVES_2(  4,iadd    );
  REGISTER_PRIMITIVES_2(  5,isub    );
  REGISTER_PRIMITIVES_2(  6,imul    );
  REGISTER_PRIMITIVES_2(  7,idiv    );
  REGISTER_PRIMITIVES_2(  8,eqp     );
  REGISTER_PRIMITIVES_2(  9,equalp  );
  REGISTER_PRIMITIVES_1( 10,pairp   );
  REGISTER_PRIMITIVES_1( 11,listp   );
  REGISTER_PRIMITIVES_2( 12,ilt     );
  REGISTER_PRIMITIVES_2( 13,igt     );
  REGISTER_PRIMITIVES_2( 14,ilte    );
  REGISTER_PRIMITIVES_2( 15,igte    );
  REGISTER_PRIMITIVES_2( 16,ieq     );
  REGISTER_PRIMITIVES_1( 17,atomp   );
  REGISTER_PRIMITIVES_2( 18,and     );
  REGISTER_PRIMITIVES_2( 19,or      );
  REGISTER_PRIMITIVES_2( 20,eval    );
  //REGISTER_PRIMITIVES_1( 21,eval1   );
  REGISTER_PRIMITIVES_0( 22,read    );
  REGISTER_PRIMITIVES_1( 23,display );
  REGISTER_PRIMITIVES_1( 24,printa  );
  REGISTER_PRIMITIVES_1( 25,nullp   );
  REGISTER_PRIMITIVES_2( 26,imod    );
  REGISTER_PRIMITIVES_2( 27,ishl    );
  REGISTER_PRIMITIVES_2( 28,ishr    );
  //REGISTER_PRIMITIVES_2( 29,list    );
  //REGISTER_PRIMITIVES_2( 29,apply   );
  REGISTER_PRIMITIVES_1( 31,procp   );
  REGISTER_PRIMITIVES_2( 32,set_car );
  REGISTER_PRIMITIVES_2( 33,set_cdr );
  //REGISTER_PRIMITIVES_1( 34,set     );
  REGISTER_PRIMITIVES_1( 34,printerr);
  REGISTER_PRIMITIVES_1( 35,exita   );
  
  fputs( "Booted.\n",stderr );
  KEEP3(gEnv);  // FAILS
  //KEEP3( cdr(pcar) );  // correct, assuming all these will be defines
  _check_mem();  // OK
  //exit(1);
  _check_mem_leak();  
  fputs( "Booted and memory checked.\n",stderr );
}


ATOM exita( ATOM val ){
  exit( get_val(val) );
  return NIL;
}




int equal( ATOM a,ATOM b ){            // are these atoms equivalent?
EQUAL:
  if ( is_eq( a,b ) ) return TRUE;   // identical atoms are equal
  if NE_TAG( a,b )    return FALSE;  // different types are not equal
  if ( is_str(a) ){
    if ( strcmp( strings[ get_str(a) ],strings[ get_str(b) ] )==0 ) return TRUE;
    return FALSE;
  }
  if ( is_par(a) ){
    if ( equal( car(a),car(b) ) ){ 
      a = cdr(a);  
      b = cdr(b);  
      goto EQUAL;                     // tail-call equal( CDR(a),CDR(b) );
    }  
  }
  return FALSE;
}

int not( int a ){ return !a; }

/*
ATOM set( ATOM var,ATOM val,ATOM env ){
  ATOM kvp = assoc-kvp( var,env );
  EXITIF( is_null( kvp ),"var not found in environment",var );
  ATOM res = setcdr( kvp,val );
  return res;
}
*/

ATOM pair( ATOM keys,ATOM vals ){
  //PEEK( "",keys );
  //PEEK( "",vals );
  return make_alist( keys,vals );
}

// environments are circular: global.fn->(proc fEnv) -> ... -> global
ATOM assoc( ATOM sym,ATOM env ){         // eg. ( (k.v) ((k.v) (k.v)) (k.v) )
ASSOC:
  //peek( "assoc: sym",sym );
  //peek( "assoc: env",env );
  if ( is_null(env) ) return NIL;    // reached end of environment
  //if ( ! is_pair( env ) ) return NIL;   // () reached end of environment
  ATOM first = car( env );              // first key-value pair (k.v)
  //peekPair( "assoc: match? first",first );
  //if ( is_atom( first ) ) return NIL;   // atom
  if ( is_kvp(first) ){               // (a . b) car is pair - process car 
    //peek( "assoc: is kvp",first );
    if ( is_eq( sym,kvp_key(first) ) ){
      ATOM val = kvp_val( first );
      //peek( "assoc: found! val",val );
      return val;          // symbol found return value
    }
    
    ATOM res = assoc( sym,cdr(env) );     // else to search rest of list
    return res;
  }
  //peek( "assoc: not kvp first",first );
  
  // ( (k.v) (k.v) ...) must be a list here
  //if ( is_proc( first ) ) return NIL;   // ((lambda (x) (car x)) env . G) don't look for sym in procedures
  // no (k.v) so search list
  ATOM res = assoc( sym,first );     // car is pair - process car tree
  if ( ! is_null(res) )  return res;
  return assoc( sym,cdr(env) );
}
// env is list of frames, a frame is an alist
ATOM assoc2( ATOM sym,ATOM env ){         // eg. ( (k.v) ((k.v) (k.v)) 
ASSOC2:
  if ( is_null(env) ) return NIL;    // reached end of environment
  ATOM frame = car( env );              // first frame
  ATOM kvp = alist_assoc( sym,frame );
  if ( ! is_null(kvp) ){  // found
    return kvp;
  }
  // try next frame
  env = cdr( env );
  goto ASSOC2;
}

ATOM assoc_kvp( ATOM sym,ATOM env ){         // eg. ( (k.v) ((k.v) (k.v)) (k.v) )
ASSOC:
  if ( is_null(env) ) return NIL;    // reached end of environment
  ATOM first = car( env );              // first key-value pair (k.v)
  if ( is_kvp(first) ){         // (a . b) car is pair - process car 
    if ( is_eq( sym,kvp_key(first) ) ){
      ATOM val = first;
      return val;          // symbol found return value
    }
    ATOM res = assoc_kvp( sym,cdr(env) );  // else search rest of list
    return res;
  }
  ATOM res = assoc_kvp( sym,first );  // first is list so search it
  if ( ! is_null(res) )  return res;
  return assoc_kvp( sym,cdr(env) );
}

/*
ATOM make_env(){
  // env is a tagged list with name "G"
  // (G)
  return make_taglist( readString("G") );
}

ATOM extend_env( ATOM env ){
  // (G 
  ATOM fram = make_taglist( readString("env") );
  ATOM eenv = cons( fram,env );
  return eenv;
}

ATOM env_find_kvp( ATOM env ){
  //
  ATOM fram = taglist_list( env );
  table_find();
}
*/
// this was hack that seemed to work
/*
ATOM assoc2(ATOM sym, ATOM env){         // eg. ( (k.v) ((k.v) (k.v)) (k.v) )
ASSOC2:
  if IS_NIL( env )                   return NIL;    // reached end of environment
  ATOM first = car( env );                          // first key-value pair (k.v)
  if EQ( sym,car( first ) )    return cdr( first );  // symbol found return v pair
  if ( is_pair( car( first ) ) ){                   // car is pair - do car tree
    ATOM ret = assoc2( sym,first );
    if NOT_NIL( ret )                return ret;    // found sym in car list
    env = cdr( env );           
    goto ASSOC2;       // tail-call assoc2( s,CDR(e) );
  }
  peek( "sym",sym );
  peek( "env",env );
  //exit(1);
  //if ( ! is_proc( env ) ){  // don't look for sym in procedures
    env = cdr( env );           
    goto ASSOC2;       // tail-call assoc2( s,CDR(e) );
  //}
  //else{
    //printf( "assoc2: skipping function" );
    //exit(1);
  //}
  return NIL;
}
*/

//ATOM map(ATOM f, ATOM l){
//  if IS_NIL(l) return NIL;
//  return cons( eval( f,CAR(l) ),map( f,CDR(l)) ); cons(f,CAR(l))???
//}

ATOM evallst( ATOM lst,ATOM env ){
  //fprintf(stderr,"."     );
  if ( is_null(lst) ) return NIL; //RETURN( NIL );
  ATOM this = eval( car(lst),env );
  ATOM rest = evallst( cdr(lst),env );
  ATOM res = cons( this,rest );
  return res;
}
// FIXME: evalseq may allow define and set! and set-car! and set-cdr!
// these make add pairs to env that need to be kept.
// need to specially make defined and set! pairs for gc

ATOM evalseq( ATOM seq,ATOM env ){
  //SYM_PEEK( "----------start",seq );
  if ( is_null(seq) )  return NIL;  // r4rs test bug 
  if ( is_null( cdr(seq) ) ){
    //SYM_PEEK( "last",car(seq) );
    ATOM res = eval( car(seq),env );
    //SYM_PEEK( "last",res );
    return res;
  }
  ATOM ignore = eval( car(seq),env );  // ignore result
  //SYM_PEEK( "mid",ignore );
  //SYM_PEEK( "rest",cdr(seq) );
  ATOM res = evalseq( cdr(seq),env );
  //SYM_PEEK( "rest",res );
  return res;
}
/*
global env should be a table eg. (global ((k v) (k v) ...) . empty-env)
extended env should be tables eg. (extenv () global)
*/

// environment is list of frames
/*
ATOM extendEnv( ATOM env ){
  ATOM eEnv = cons( NIL,env );
  return eEnv;
}
*/

//#define ENV_FRAME(env) CAR(env)
//#define ENV_BASE(env) CDR(env)
/*
a frame should also be a table eg. (frame (k.v) (k.v) ...)
*/
// frames are lists of key.value pairs

// e-->[x][?]
//      |
//      '--------------->[x][o]
//                        |  '--->[x][?]
//          p-->[k][v]    v  
//                       [k][v]

// e-->[x][?]
//      '------>[x][o]
//               |  '--->[x][o]
//               v        |  '--->[x][?]
//          p-->[k][v]    v  
//                       [k][v]


/*
ATOM addKVPair( ATOM kvp,ATOM env ){
  ATOM fra = cons( kvp,car(env) );
  setcar( env,fra );
  return fra;
}
*/
ATOM make_frame( ATOM alst,ATOM env ){
  //ATOM fra = cons( alst,car(env) );
  ATOM fra = cons( alst,env );
  //setcar( env,alst );
  return fra;
}
/*
  ATOM oldlist = car( env );
  ATOM newlist = cons( kvp,oldlist );
  setcar( env,newlist );
*/
ATOM addKVPair3( ATOM kvp,ATOM env ){
  //PEEK( "",env );
  EXITIF( ! is_kvp( kvp ),"kvp is not a key-value-pair",kvp );
  //PEEKEXITIF( ! is_alist( env ),"kvp is not a key-value-pair",kvp );
  ATOM oldlist = car( env );
  //PEEK( "",kvp );
  //PEEK( "",oldlist );
  EXITIF( ! is_alist( oldlist ),"oldlist is not an alist",oldlist );
  //exit(1);
  ATOM newlist = extend_alist( kvp,oldlist );
  set_gcm( newlist,2 );  // FIXME: hack!
  set_car( env,newlist );
  return newlist;
}


#define LIST_OF_VALUES(exp,env) evallst(exp,env)

int loop=0;
ATOM eval(ATOM exp, ATOM env){
  ATOM e;
  //PEEK( "**********",exp );
  //SYM_PEEK( "",env );
  //loop++;
  if ( is_self_eval(exp) ) return exp;                        // () -3 "str" c
  if ( is_variable(exp)  ) return variable_value( exp,env );  // x -> 4
  if ( is_quoted(exp)    ) return quoted_value( exp );        // (quote (1 2))
  MARK3;

  if ( is_definition(exp))   // (define x 3)
    RETURN3( eval_definition( exp,env ) );
    
  if ( is_set(exp)       )   // (set! x y)
    RETURN3( eval_set( exp,env ) );
    
  if ( is_if(exp)        )   // (if (eq? n 0) "zero" "non zero"))
    RETURN3( eval_if( exp,env ) );
    
  if ( is_cond(exp)      )   // (cond ((eq? n 0) "z") (else "nz"))
    RETURN3( eval_cond_clauses( cdr(exp),env ) );

  if ( is_eval_list(exp) )   // (list 1 (car x))
    RETURN3( eval_list( exp,env ) );


  if ( is_load(exp)      ){  // (load "filename")
    /*
    here, (load "filename") has been created in pairs
    we dont want it so we dont call KEEP3
    we can't get rid of it since we done have it in our list
    of pairs created.
    by makeing repl special and having a global pair list we get
    around this issue
    */
    //peek( "eval.load: eret(define",ret );
    FILE *f = fopen( strings[ get_str( _2ND(exp) ) ],"r" );
    EXITIF( f==NULL,"Could not open file",exp );
    FILE *old = in;
    int old_pos=pos;  // FIXME: I don't think this works
    int old_line=line;
    in = f;
  //setvbuf(in, buf, _IOLBF, BUF_SIZE);  // make file use my buffer
    //buf[0]=0;
    // FIXME: may have off effects here
    // assume previous input was 100% ok up to (load )

    //SYM_PEEK( "",exp );
    GLOBAL_KEEP3( NIL );   // get rid of (load "filename" )
    ATOM ret = repl();
    //SYM_PEEK( "",ret );
    fclose(f);
    in = old;
  //setvbuf(in, buf, _IOLBF, BUF_SIZE);  // make file use my buffer
    //buf[0]=0;
    line=old_line;
    pos=old_pos;
    //RETURN3( readString("loaded") );  // could do this but repl has done all work
    return readString( "\"File loaded.\"" );
  }
  // (eval exp env) special form since no need to evaluate env
  if ( is_eval(exp) ){       // exp = (eval exp env)
    ATOM exp1 = _2ND( exp );
    ATOM env1 = _3RD( exp );
    ATOM res = eval( exp1,env1 );
    RETURN3( res );
  }
  // (eval1 exp) special form since need to evaluate exp in this env
  if ( is_eval1(exp) ){       // exp = (eval1 exp)
    ATOM exp1 = eval( _2ND(exp),env );
    ATOM res = eval( exp1,env );
    RETURN3( res );
  }
  // (apply proc args) special form since no need to evaluate anything
  if ( is_apply(exp) ){
    //SYM_PEEK( "Apply",exp );
    ATOM proc = eval ( _2ND(exp),env );
    //SYM_PEEK( "Apply",proc );
    EXITIF( is_null( proc ),"User function not defined in environment",exp );
    EXITIF( is_atom( proc ),"User function returned an atom in environment",exp );
    //ATOM args = evallst( ARGLIST(exp),env ) ;  // eg. (cons 1 2) -> (1 2)
    ATOM args = eval( _3RD(exp),env );
    //SYM_PEEK( "Apply",args );
    ATOM res = apply( proc,args );
    //SYM_PEEK( "Apply",res );
    RETURN3( res );
  }
/*
  // (cons-stream a b) primative -> (a . (delay b)) - special form
  if ( is_cons_stream( exp ) ){           // exp = (cons a b)
    ATOM a = eval( _2ND(exp),env );  // (eval a)
    ATOM b = make_proc( make_lambda( NIL,_3RD(exp) ),env );  // (eval b)
    RETURN3( cons( a,b ) );
  }
*/
  // (delay p) special form since no eval
  if ( is_delay(exp) ){
    //ATOM body = _2ND( exp );
    ATOM body = _REST( exp );
    ATOM form = NIL;
    ATOM lamb = make_lambda( form,body );
    ATOM proc = make_proc( lamb,env );
    //PEEK( "delay",proc );
    //exit(1);
    RETURN3( proc ); 
  }
  // (lambda (x) (car x)) special form since no eval
  if ( is_lambda(exp) ){
    ATOM proc = make_proc( exp,env );  // eg. ((lambda (x) (car x)) env G)
    //SYM_PEEK( "lambda",proc );
    //exit(1);
    RETURN3( proc );
  }
  // (progn e1 e2 ... en)  eg. (progn (car x) (car y))
  if ( is_progn(exp) ){
    ATOM res = eval_progn( _REST(exp),env );
    RETURN3( res );
  }
  // (primitive (x) n) special form since no eval
  if ( is_primitive(exp) ){
    //PEEK( "Primitive",exp );
    //ATOM proc = make_proc( exp,env );  // eg. ((primitive (x) 1) env G)
    //ATOM proc = make_prim_proc( exp,env );  // eg. ((primitive (x) 1) env G)
    ATOM proc = make_proc( exp,env );  // eg. ((primitive (x) 1) env G)
    //PEEK( "Primitive",proc );
    RETURN3( proc );
  }
  // must be user defined funtion so expand it eg. (kar (cons 1 2))
  // eg. ( (lambda (x) (car x)) (quote (1 2)) )
  //PEEK( "app?",exp );
  if ( is_application(exp) ){
    ATOM proc = eval( app_proc(exp),env );
    //PEEK( "",proc );
    EXITIF( is_null( proc ),"User function not defined in environment",exp );
    EXITIF( is_atom( proc ),"User function returned an atom in environment",exp );
    // args are evaluated in current env
    //ATOM args = evallst( ARGLIST(exp),env ) ;  // eg. (cons 1 2) -> (1 2)
    ATOM args = app_args(exp);
    //PEEK( "",args );
    ATOM vals = LIST_OF_VALUES( args,env );
    //PEEK( "",vals );
    ATOM res = apply( proc,vals );
    RETURN3( res );
  }
  // FIXME: try an application
  PEEK( "SPECIAL APPLICATION",exp );
    ATOM proc = eval( car(exp),env );
    //PEEK( "",proc );
    EXITIF( is_null( proc ),"User function not defined in environment",exp );
    EXITIF( is_atom( proc ),"User function returned an atom in environment",exp );
    // args are evaluated in current env
    //ATOM args = evallst( ARGLIST(exp),env ) ;  // eg. (cons 1 2) -> (1 2)
    ATOM args = LIST_OF_VALUES( cdr(exp),env );
    //PEEK( "",args );
    ATOM res = apply( proc,args );
    RETURN3( res );
  // what about labels? other forms?
  EXIT( "I can't do this for some reason.",cons( exp,env ) );
  return NIL;  // silence clang warning
}

ATOM apply(ATOM proc, ATOM args){  // ((lambda (x) (car x)) env .. G)
  MARK3;
  //PEEK( "",proc );
  //PEEK( "",args );
  if ( is_proc(proc) ){  // FIXME: not a lambda, but a closure
    ATOM func = proc_lambda( proc );
  //if ( is_primitive( car(proc) ) ){
  if ( is_primitive( func ) ){
    //PEEK( "Primitive",proc );
    //PEEK( "Primitive",args );
    //ATOM prim = prim_proc_primitive( proc );
    //ATOM prim = proc_lambda( proc );
    ATOM form = primitive_form( func );
    ATOM cfun = primitive_cfun( func );
    //ATOM fEnv = prim_proc_env( proc );
    ATOM fEnv = proc_env( proc );
    //PEEK( "Primitive",fEnv );
    ATOM alst = pair( form,args ) ; // make (k.v) pairs for formal arguements
    //PEEK( "Primitive",alst );
    ATOM eEnv = make_frame( alst,fEnv );  // extend procedure's env
    //PEEK( "Primitive",eEnv );
    ATOM (*fn)() = primFns[ get_num(cfun) ];  // cfun is index to primitive table
    ATOM res = (*fn)( args,eEnv );  // special primitive function must process args
    //PEEK( "Primitive",res );
    RETURN3( res );
  }
//  if ( is_lambda( car(proc)) ){  // FIXME: not a lambda, but a closure
  //if ( is_proc(proc) ){  // FIXME: not a lambda, but a closure
  if ( is_lambda(func) ){  // FIXME: not a lambda, but a closure
    //ATOM lamb = proc_lambda( func );
    ATOM form = lambda_form( func );  // (x)
    ATOM body = lambda_body( func );  // (car x) FIXME: single or list?
    //PEEK( "",body );
    ATOM fEnv = proc_env( proc );  // get env procedure was defined in
    //PEEK( "Procedure",fEnv );
    ATOM alst = pair( form,args ) ; // make ((k.v)...) pairs for formal arguements
    //PEEK( "Procedure",alst );
    ATOM eEnv = make_frame( alst,fEnv );  // extend procedure's env
    //PEEK( "Procedure",eEnv );
    ATOM res  = evalseq( body,eEnv  );  // eval sequence in extended env
    //ATOM res = eval( body,eEnv  );  // was, eval procedure in extended env
    //PEEK( "Procedure",res );
    RETURN3( res );
  }
  EXIT( "Unknown function",func );
  }
  // FIXME: could do something special here like assume quoted
  EXIT( "Unknown",proc );
}

ATOM _global_save;

ATOM repl(){                            // read eval print loop
  ATOM ret;  // return value
  fprintf( stderr,"\nStart REPL...\n" );
  while TRUE{            // read here
    GLOBAL_MARK3;
    //PEEK( "1",NIL );
    ATOM exp = read();
    //PEEK( "2",exp );
    if ( is_eq( exp,END ) ){
      fputs( "EOF\n", stderr );
      break;
    }
    fputs( "========================================\n", stderr );
    //PEEK( "Env  : ",gEnv );
    PEEK( "Read: ",exp );
    //peek( "Read : ",exp );
    ATOM r = eval( exp,gEnv );
    //fputs( "Print: ", stderr );
    //PEEK( "3",r );

    /* logic here is that only (define ...) results in new pairs added
       to environment so only check these
       ah! but adding (load "filename") may add many things to gEnv
       KEEP3( gEnv ) should work here but it is wasteful since
       if eval calls repl, repl has already processed each new define
       so it should be able to pass back an atom that says it 'i have done that'
       it also should end up elegent
       what if MARK3 was a global? 
    */
    //fputs( "A",stderr );
/* FIXME: delete
    if ( match_taglist( r,kw_define )){
      //fputs( "DEF",stderr );
      ret = caadr(r);
      printa( ret );  // just print name of variable not whole expression
      peek( "Define: ",ret );
      //GLOBAL_KEEP3( cdr(r) );  // keep cdr of (define ...)      
    }
*/
/* FIXME: delete
   else if ( match_taglist( r,kw_set )){  // (set! var val)
      PEEK( "set1",r);
      ret = cadr(r);
      PEEK( "set2",r);
      printa( ret );  // just print name of variable not whole expression
      peek( "Set!: ",ret );
      //GLOBAL_KEEP3( cddr(r) );  // keep val
    }
*/
/* FIXME: delete
    else if ( is_taglist( r,kw_load )){
      ret = CAADR(r);
      //printa( ret );  // just print name of variable not whole expression
      peek( "Print: ",ret );
      GLOBAL_KEEP3( CDR(r) );  // keep cdr of (load ...)      
    }
*/
// FIXME: delete
//   else{
      ret = r;
      printa( ret );                        // this is read-eval-print bit
      //PEEK( "Print:",ret );
      GLOBAL_KEEP3( NIL );
      // FIXME: maybe keep first kvp in env? and pair?
//    }
    //GLOBAL_KEEP3( gEnv );
    //exit(1);
    //PEEK( "4",NIL );
    _check_mem();
    //PEEK( "5",NIL );
    puts( "" );
  }
  //PEEK( "6",NIL );
  GLOBAL_KEEP3( gEnv );  // FIXME: redundant now?
  _ms( gEnv );
  //PEEK( "7",NIL );
  return ret;                             // return last thing
}


int main(){  // clang bug
  //boot();  _test();
  boot();
  in = stdin;
  setvbuf(in, buf, _IOLBF, BUF_SIZE);  // make stdin use my buffer
  repl();
  /*
  may be only place for this since all atoms must be ???
  */
  _check_mem_leak();

  fprintf( stderr,"Done.\n" );
  fprintf( stderr,"Pairs     =%d\n",consCount  );
  fprintf( stderr,"Max Pairs =%d\n",consMaxCount  );
  fprintf( stderr,"  Recycled=%d\n",_recyclePairCount );
  fprintf( stderr,"     Swept=%d\n",_sweepPairCount );
  fprintf( stderr,"Symbols   =%d\n",freeSym );
  fprintf( stderr,"Strings   =%d\n",freeStr );
  fprintf( stderr,"  Recycled=%d\n",_recycleStrCount );
  return 0;
}

#endif
#endif


