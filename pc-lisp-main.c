
#ifndef __header
  #define _pc_lisp_main_c
#endif

#ifndef _pc_lisp_main_h
  #define _pc_lisp_main_h
  #define __header

#ifdef __header

// HEADER
#include <string.h>

#include "pc-lisp-mem.c"
#include "pc-lisp-gc.c"
#include "pc-lisp-test.c"
#include "pc-lisp-misc.c"
#include "pc-lisp-read2.c"
#include "pc-lisp-print.c"
#include "pc-lisp-primitives.c"
#include "pc-lisp-adt.c"
#include "pc-lisp-eval-adt.c"

#define TRUE             ( 1==1 )  // 1 or non-zero
#define FALSE            ( 1==0 )  // 0

#define BOOL( pred )     ( (pred) ? (TRU) : (FAL) )
#define RET_BOOL( pred ) return BOOL( pred )
#define EQ_TAG(a,b)      ( get_tag(a)==get_tag(b) )
#define NE_TAG(a,b)      ( ! EQ_TAG(a,b) )

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

ATOM    pair ( ATOM key,ATOM val );
ATOM    eval ( ATOM exp,ATOM env );
ATOM    apply( ATOM proc,ATOM args );
ATOM    exita( ATOM val );

//ATOM    readLoop();
ATOM    repl();
ATOM    readString( char *s );
//void   _strcpy( char *d,char *s,int n );

ATOM    assoc( ATOM sym,ATOM env );
ATOM    local_assoc( ATOM sym,ATOM env );
//ATOM    assoc_kvp( ATOM sym,ATOM env );
ATOM    make_env();
ATOM    extend_env( ATOM env );
ATOM    env_find_kvp( ATOM env );
ATOM    evallst( ATOM lst,ATOM env );
ATOM    evalseq( ATOM seq,ATOM env );
ATOM    make_frame( ATOM alst,ATOM env );
ATOM    addKVPair3( ATOM kvp,ATOM env );

extern int loop;

extern ATOM   _global_save;

ATOM    repl();
int     main();

// END HEADER

#endif

#if defined(_pc_lisp_main_c)

// CODE

ATOM   gEnv    = NIL;     // global environment

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

  //symbol_init();
  string_init();
  for (i=0; i<SIZE; i++){
    ATOM p = make_par(i);       
    _set_car( p,MTY );  // do before chaining into freelist
    _set_cdr( p,MTY );
    _set_gcm( p,0 );                       // mark all in use
    _set_mrk( p,0 );
    _set_ref( p,0 );
    _set_mem( p,make_mem( (i+1)%SIZE ) );  // chain free cells
    //_set_bak( p,make_bak( (i-1)%SIZE ) );
    //symbols[i].name[0] = 0;
    //symbols[i].len = 0;
    //_strcpy( symbols[i].name,"UNDEF SYM",10 );
    //strings[i]         = "UNDEF STR";
    primFns[i]         = _bad_primative_fn;
    //sar[i].val         = 0;
    //if ( i==1 ) exit(1);
  }
  //_set_mem( make_par(i-1), NIL );  // last one -> NIL, not make_mem(0)
  usedPairs = MEM0;               // [0] is used from begining
  _set_mem( usedPairs,usedPairs );  // make circular
  _set_bak( usedPairs,usedPairs );
  //recycleSweeper = usedPairs;
  lastUsedPair = usedPairs;
  fputs( "Create global environment...\n",stderr );
  gEnv    = cons( NIL,NIL );  // global environment -> empty environment 
  _inc_ref( gEnv );  // interpreter hold ref on environment
  GLOBAL_MARK3;
  lastUsedPair = gEnv;  // hack?
  _mem_print_used_pairs( "gEnv",gEnv,_global_save );
  // can't do this now with distinst NIL
  //_set_car( usedPairs,readString( "\"*used pairs*\"" ) );

  fputs( "Create keyword symbols...\n",stderr );
  kw_quote       = readString( "quote"       );  
  kw_lambda      = readString( "lambda"      );  
  kw_closure     = readString( "closure"     );  
  kw_primitive   = readString( "primitive"   );
  kw_define      = readString( "define"      );
  kw_set         = readString( "set!"        );
  kw_read        = readString( "read"        );  
  kw_load        = readString( "load"        );  
  kw_exit        = readString( "exit"        );  
  kw_eval        = readString( "eval"        );
  kw_eval1       = readString( "eval1"       );
  kw_eval_macro  = readString( "eval-macro"  );
  kw_apply       = readString( "apply"       );
  kw_if          = readString( "if"          );  
  kw_cond        = readString( "cond"        );
  kw_progn       = readString( "progn"       );
  kw_cons        = readString( "cons"        );
  kw_list        = readString( "list"        );

  tag_env        = readString( "env"         );
  //null_env       = readString( "(define null-environment )" );

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
  REGISTER_PRIMITIVES_1( 31,procp   );
  REGISTER_PRIMITIVES_2( 32,set_car );
  REGISTER_PRIMITIVES_2( 33,set_cdr );
  //REGISTER_PRIMITIVES_1( 34,set     );
  REGISTER_PRIMITIVES_1( 34,printerr);
  REGISTER_PRIMITIVES_1( 35,exita   );
  REGISTER_PRIMITIVES_1( 36,disperr );
  REGISTER_PRIMITIVES_1( 37,charp   );
  REGISTER_PRIMITIVES_1( 38,numberp   );
  REGISTER_PRIMITIVES_1( 39,symbolp   );
  REGISTER_PRIMITIVES_1( 40,constantp   );
  REGISTER_PRIMITIVES_1( 41,stringp   );
  REGISTER_PRIMITIVES_1( 42,sym_to_str   );
  REGISTER_PRIMITIVES_2( 43,str_ref   );
  REGISTER_PRIMITIVES_1( 44,string_length   );
  
  fputs( "Booted.\n",stderr );
  //KEEP3(gEnv);  // FAILS
  //KEEP3( cdr(pcar) );  // correct, assuming all these will be defines
  _cm_check_mem();  // OK
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
  if ( is_pair(a) ){
    if ( equal( car(a),car(b) ) ){ 
      a = cdr(a);  
      b = cdr(b);  
      goto EQUAL;                     // tail-call equal( CDR(a),CDR(b) );
    }  
  }
  return FALSE;
}

int not( int a ){ return ( (a) ? FALSE : TRUE ); }

/* 
ATOM set( ATOM var,ATOM val,ATOM env ){
  ATOM kvp = assoc-kvp( var,env );
  EXITIF( is_null( kvp ),"var not found in environment",var );
  ATOM res = setcdr( kvp,val );
  return res;
}
*/

ATOM pair( ATOM keys,ATOM vals ){ return make_alist( keys,vals ); }

/*
(define assoc (lambda (sym env)
  
))
*/

// env is list of frames, a frame is an alist
ATOM assoc( ATOM sym,ATOM env ){         // eg. ( ((k.v)) ((k.v) (k.v)) )
ASSOC2:
  //PEEK( "",sym );
  //PEEK( "",env );
  if ( is_null(env) ) return FAL;    // reached end of environment
  ATOM frame = car( env );              // first frame
  //PEEK( "",frame );
  ATOM kvp = alist_assoc( sym,frame );
  //PEEK( "",kvp );
  if ( ! is_eq( kvp,FAL ) ){  // found
    return kvp;
  }
  // try next frame
  env = cdr( env );
  goto ASSOC2;
}

// search local frame only
ATOM local_assoc( ATOM sym,ATOM env ){         // eg. ( ((k.v)) ((k.v) (k.v)) )
  //PEEK( "",sym );
  //PEEK( "",env );
  // required?
  if ( is_null(env) ) return FAL;    // reached end of environment
  ATOM frame = car( env );              // first frame
  //PEEK( "",frame );
  //if ( ! is_null( cdr(env) ) ) PEEK( "",cadr( env ) );
  ATOM kvp = alist_assoc( sym,frame );
  //PEEK( "",kvp );
  if ( ! is_eq( kvp,FAL ) ){  // found
    return kvp;
  }
  return FAL;
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

ATOM evallst( ATOM lst,ATOM env ){
  if ( is_null(lst) ) return NIL; //RETURN( NIL );
  if ( is_atom(lst) ) return eval( lst,env ); // added for (fn . arglist)
  ATOM this = eval( car(lst),env );
  ATOM rest = evallst( cdr(lst),env );
  ATOM res = cons( this,rest );
  return res;
}

ATOM evalseq( ATOM seq,ATOM env ){
  if ( is_null(seq) )  return NIL;  // r4rs test bug 
  if ( is_null( cdr(seq) ) ){
    ATOM res = eval( car(seq),env );
    return res;
  }
  ATOM ignore = eval( car(seq),env );  // ignore result
  ATOM res = evalseq( cdr(seq),env );
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
// add kvp to frame
ATOM addKVPair3( ATOM kvp,ATOM env ){
  //PEEK( "",kvp );
  //PEEK( "",env );
  EXITIF( ! is_kvp( kvp ),"kvp is not a key-value-pair",kvp );
  ATOM oldlist = car( env );
  EXITIF( ! is_alist( oldlist ),"oldlist is not an alist",oldlist );
  ATOM newlist = extend_alist( kvp,oldlist );
  set_car( env,newlist );
  return newlist;
}

#define LIST_OF_VALUES(exp,env) evallst(exp,env)

int loop=0;
ATOM eval( ATOM exp,ATOM env ){
  ATOM e;
  //display( exp );
  //PEEK( "**********",exp );
  //PEEK( "**********",env );
  //loop++;
  if ( is_self_eval(exp) ) return exp;
  if ( is_variable(exp)  ) return variable_value( exp,env );
  if ( is_quoted(exp)    ) return quoted_value( exp );
  MARK3;

  if ( is_definition(exp)) RETURN3( eval_definition( exp,env ) );
  if ( is_set(exp)       ) RETURN3( eval_set( exp,env ) );
  if ( is_if(exp)        ) RETURN3( eval_if( exp,env ) );
  if ( is_cond(exp)      ) RETURN3( eval_cond_clauses( cdr(exp),env ) );
  if ( is_eval_list(exp) ) RETURN3( eval_list( exp,env ) );
  if ( is_load(exp)      ) RETURN3( eval_load( exp,env ) );
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
  // (lambda (x) (car x)) special form since no eval
  if ( is_lambda(exp) ){
    ATOM proc = make_proc( exp,env );  // eg. ((lambda (x) (car x)) env G)
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
  //PEEK( "SPECIAL APPLICATION",exp );
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
  if ( is_primitive( func ) ){
    //PEEK( "Primitive",proc );
    //PEEK( "Primitive",args );
    ATOM form = primitive_form( func );
    ATOM cfun = primitive_cfun( func );
    ATOM fEnv = proc_env( proc );
    ATOM alst = pair( form,args ) ; // make (k.v) pairs for formal arguements
    ATOM eEnv = make_frame( alst,fEnv );  // extend procedure's env
    ATOM (*fn)() = primFns[ get_num(cfun) ];  // cfun is index to primitive table
    ATOM res = (*fn)( args,eEnv );  // special primitive function must process args
    RETURN3( res );
  }
  if ( is_lambda(func) ){  // FIXME: not a lambda, but a closure
    ATOM form = lambda_form( func );  // (x)
    ATOM body = lambda_body( func );  // (car x) FIXME: single or list?
    ATOM fEnv = proc_env( proc );  // get env procedure was defined in
    ATOM alst = pair( form,args ) ; // make ((k.v)...) pairs for formal arguements
    ATOM eEnv = make_frame( alst,fEnv );  // extend procedure's env
    ATOM res  = evalseq( body,eEnv  );  // eval sequence in extended env
    RETURN3( res );
  }
  EXIT( "Unknown function",func );
  }
  // FIXME: could do something special here like assume quoted
  EXIT( "Unknown",proc );
}

int size( ATOM a ){
  int s = 0;
  if ( is_eq( a,gEnv ) )  return 0;  // dont loop
  if ( ! is_pair(a) )  return 0;
  //PEEK( "",a );
  if ( is_eq( car(a),tag_env ) )  return 1;  // dont process environments
  return 1 + size( car(a) ) + size( cdr(a) );
}

ATOM _global_save;
int _prevMaxCount = 0;

ATOM repl(){                            // read eval print loop
  ATOM ret;
  fprintf( stderr,"\nStart REPL...\n" );
  while TRUE{
    int _used = _usedPairCount;
    GLOBAL_MARK3;
    ATOM exp = read();
    if ( is_eq( exp,END ) ){
      fputs( "EOF\n", stderr );
      break;
    }
    fputs( "========================================\n", stderr );
    printa( exp );
    puts( "" );
    //PEEK( "Env  : ",gEnv );
    PEEK( "Read: ",exp );
    ATOM ret = eval( exp,gEnv );
    //fputs( "Print: ", stderr );
    printa( ret );
    PEEK( "Print:",ret );
    //fprintf( stderr,"Result size = %d\n",size( ret ) );
    /*
    if ( is_symbol( ret ) ){
      PEEK( "symbol ",ret );
      ATOM kvp = assoc( ret,gEnv );
      PEEK( "",kvp );
      if ( ! is_eq( kvp,FAL ) ){
        PEEK( "found ",kvp );
        fprintf( stderr,"Result true size = %d\n",size( kvp ) );
      }
    }
    */
    GLOBAL_KEEP3( NIL );
    //int _deltaUsed = _usedPairCount-_used;
    //fprintf( stderr,"Pairs increased by %d\n",_deltaUsed );
    //_ms( gEnv );
    //_deltaUsed = _usedPairCount-_used;
    //fprintf( stderr,"Pairs after GC sweep %d\n",_deltaUsed );
    _ms( gEnv );
    //_cm_check_mem();
    puts( "" );
  }
  return ret;                             // return last thing
}

int main(){
  fprintf( stderr,"\n\n\n\n\n\n\n\n\n\nStart\n" );
  boot();
  in = stdin;
  setvbuf( in,buf,_IOLBF,BUF_SIZE );  // make stdin use my buffer
  repl();
  //PEEK( "",gEnv );
  /*
  may be only place for this since all atoms must be ???
  */
  //_cm_check_mem_leak();

  fprintf( stderr,"Done.\n" );
  fprintf( stderr,"Free+Used =%d\n",_freePairCount+_usedPairCount  );
  fprintf( stderr,"      Free=%d\n",_freePairCount  );
  fprintf( stderr,"      Used=%d\n",_usedPairCount  );
  fprintf( stderr,"  Max Used=%d\n",_usedPairMaxCount  );
  fprintf( stderr,"Recycled  =%d\n",_recyclePairCount );
  fprintf( stderr,"    Inline=%d\n",_decRecyclePairCount );
  fprintf( stderr,"     Swept=%d\n",_sweepPairCount );
  fprintf( stderr,"    Reused=%d\n",_reusedPairCount );
  fprintf( stderr,"Strings   =%d\n",freeStr );
  //fprintf( stderr,"  Recycled=%d\n",_recycleStrCount );
  return 0;
}

#endif
#endif

