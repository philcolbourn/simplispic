
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


#define REGISTER_PRIMITIVES_0(i,name,sim_name){                            \
  MARK3;                                                                   \
  primFns[i] = prim_##name;                                                \
  ATOM prim = eval( readString(                                            \
    "(define " sim_name " (primitive " sim_name " () " #i "))"             \
    ),gEnv );                                                              \
      PEEK( "",prim );/**/                                                     \
  KEEP3( NIL );                                                            \
}

#define REGISTER_PRIMITIVES_1(i,name,sim_name){                            \
  MARK3;                                                                   \
  primFns[i] = prim_##name;                                                \
  ATOM prim = eval( readString(                                            \
    "(define " sim_name " (primitive " sim_name " (a) " #i "))"            \
    ),gEnv );                                                              \
      PEEK( "",prim );/**/                                                     \
  KEEP3( NIL );                                                            \
}

#define REGISTER_PRIMITIVES_2(i,name,sim_name){                            \
  MARK3;                                                                   \
  primFns[i] = prim_##name;                                                \
  ATOM prim = eval( readString(                                            \
    "(define " sim_name " (primitive " sim_name " (a b) " #i "))"          \
    ),gEnv );                                                              \
      PEEK( "",prim );/**/                                                     \
  KEEP3( NIL );                                                            \
}

void boot(){
  //int i;
  fputs( "Booting...\n",stderr );
  pair_init();
  string_init();
  primitive_init();
  fputs( "Create global environment...",stderr );
  gEnv    = cons( NIL,NIL );  // global environment -> empty environment 
      PEEK( "A",gEnv );
  //exit(1);
  _inc_ref( gEnv );  // interpreter hold ref on environment
  _mem_print_used_pairs( "gEnv",gEnv,_global_save );
  fputs( "Done.\n",stderr );
  MARK3;
  //lastUsedPair = gEnv;  // hack?
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
  fputs( "Created keyword symbols.\n",stderr );
 
  fputs( "Create primitive procedures...\n",stderr );
  REGISTER_PRIMITIVES_1(  1,car           ,"car"             );
  REGISTER_PRIMITIVES_1(  2,cdr           ,"cdr"             );
  REGISTER_PRIMITIVES_2(  3,cons          ,"cons"            );
  REGISTER_PRIMITIVES_2(  4,iadd          ,"int+"            );
  REGISTER_PRIMITIVES_2(  5,isub          ,"int-"            );
  REGISTER_PRIMITIVES_2(  6,imul          ,"int*"            );
  REGISTER_PRIMITIVES_2(  7,idiv          ,"int/"            );
  REGISTER_PRIMITIVES_2(  8,eqp           ,"eq?"             );
//REGISTER_PRIMITIVES_2(  9,equalp        ,"equal?"          );
//REGISTER_PRIMITIVES_1( 10,pairp         ,"pair?"           );
  REGISTER_PRIMITIVES_1( 11,listp         ,"list?"           );  // FIXME: make native
  REGISTER_PRIMITIVES_2( 12,ilt           ,"int<"            );
  REGISTER_PRIMITIVES_2( 13,igt           ,"int>"            );
  REGISTER_PRIMITIVES_2( 14,ilte          ,"int<="           );
  REGISTER_PRIMITIVES_2( 15,igte          ,"int>="           );
  REGISTER_PRIMITIVES_2( 16,ieq           ,"int="            );
//REGISTER_PRIMITIVES_1( 17,atomp         ,"atom?"           );
//REGISTER_PRIMITIVES_2( 18,and           ,"and"             );
//REGISTER_PRIMITIVES_2( 19,or            ,"or"              );
  REGISTER_PRIMITIVES_2( 20,eval          ,"eval"            );
//REGISTER_PRIMITIVES_1( 21,eval1         ,"eval1"           );
  REGISTER_PRIMITIVES_0( 22,read          ,"read"            );
  REGISTER_PRIMITIVES_1( 23,display       ,"display"         );
  REGISTER_PRIMITIVES_1( 24,printa        ,"print"           );
//REGISTER_PRIMITIVES_1( 25,nullp         ,"null?"           );
  REGISTER_PRIMITIVES_2( 26,imod          ,"int%"            );
  REGISTER_PRIMITIVES_2( 27,ishl          ,"<<"              );  // prob. not std.
  REGISTER_PRIMITIVES_2( 28,ishr          ,">>"              );
//REGISTER_PRIMITIVES_1( 31,procp         ,"proc?"           );
  REGISTER_PRIMITIVES_2( 32,set_car       ,"set-car!"        );
  REGISTER_PRIMITIVES_2( 33,set_cdr       ,"set-cdr!"        );
//REGISTER_PRIMITIVES_1( 34,set           ,"set"             );
  REGISTER_PRIMITIVES_1( 34,printerr      ,"printerr"        );
  REGISTER_PRIMITIVES_1( 35,exita         ,"exit"            );
  REGISTER_PRIMITIVES_1( 36,disperr       ,"disperr"         );
//REGISTER_PRIMITIVES_1( 37,charp         ,"char?"           );
//REGISTER_PRIMITIVES_1( 38,numberp       ,"number?"         );
//REGISTER_PRIMITIVES_1( 39,symbolp       ,"symbol?"         );
//REGISTER_PRIMITIVES_1( 40,constantp     ,"constant?"       );
//REGISTER_PRIMITIVES_1( 41,stringp       ,"string?"         );
  REGISTER_PRIMITIVES_1( 42,sym_to_str    ,"symbol->string"  );
  REGISTER_PRIMITIVES_1( 43,str_to_sym    ,"string->symbol"  );
  REGISTER_PRIMITIVES_2( 44,str_ref       ,"string-ref"      );
  REGISTER_PRIMITIVES_1( 45,string_length ,"string-length"   );
  REGISTER_PRIMITIVES_1( 46,get_num_tag   ,"tag"             );
  REGISTER_PRIMITIVES_1( 47,get_num_val   ,"val"             );
  fputs( "Created primitive procedures.\n",stderr );

  PEEK( "",gEnv );  
  fputs( "Booted.\n",stderr );

  fputs( "Checking memory consistency...",stderr );
  KEEP3( gEnv );
  _cm_check_mem();
  _cm_check_mem_leak();
  fputs( "Done.\n",stderr );

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
        //TRACE( res,TVAL );
    return res;
  }
  ATOM ignore = eval( car(seq),env );  // ignore result
  ATOM res = evalseq( cdr(seq),env );
        //TRACE( res,TVAL );
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

ATOM make_frame( ATOM a,ATOM e ){
  ATOM f = cons( a,e );
  return f;
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

  if ( is_definition(exp)){
        //PEEK( "do",exp );
    RETURN3( eval_definition( exp,env ) );
  }
  if ( is_set(exp)       ) RETURN3( eval_set( exp,env ) );
  if ( is_if(exp)        ) RETURN3( eval_if( exp,env ) );
  if ( is_cond(exp)      ) RETURN3( eval_cond_clauses( cdr(exp),env ) );
  if ( is_eval_list(exp) ) RETURN3( eval_list( exp,env ) );
  if ( is_load(exp)      ){
        //PEEK( "",exp );
    ATOM res = eval_load( exp,env );
        //PEEK( "",res );
    RETURN3( res );
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
    PEEK( "Primitive",proc );
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
        //TRACE( res,TVAL );
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
        //TRACE( res,TVAL );
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
      //TRACE( res,4022 );
      RETURN3( res );
    }
    if ( is_lambda(func) ){  // FIXME: not a lambda, but a closure
      ATOM form = lambda_form( func );  // (x)
      ATOM body = lambda_body( func );  // (car x) FIXME: single or list?
      ATOM fEnv = proc_env( proc );  // get env procedure was defined in
      ATOM alst = pair( form,args ) ; // make ((k.v)...) pairs for formal arguments
      ATOM eEnv = make_frame( alst,fEnv );  // extend procedure's env
      ATOM res  = evalseq( body,eEnv  );  // eval sequence in extended env
      //TRACE( res,4022 );
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
  ATOM ret = readString( "????" );
  fprintf( stderr,"\nStart REPL...\n" );
  MARK3;  // catches redefines of primitives
  while TRUE{
    //REMARK3;  // if updated, redefines wont be gcd. with=6281,1:26 without=6164,1:26
    int _used = _usedPairCount;
    ATOM exp = read();
    if ( is_eq( exp,END ) ){
      KEEP3( ret );
      //_cm_check_mem();
      //_cm_check_mem_leak();
      fputs( "EOF\n", stderr );
      break;
    }
    fputs( "========================================\n", stderr );
    printa( exp );
    puts( "" );
        //PEEK( "Env  : ",gEnv );
        PEEK( "Read: ",exp );
    ret = eval( exp,gEnv );
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
    KEEP3( ret );
    int _deltaUsed = _usedPairCount-_used;
    fprintf( stderr,"Pairs increased by %d\n",_deltaUsed );
    _deltaUsed = _usedPairCount-_used;
    fprintf( stderr,"Pairs after GC sweep %d\n",_deltaUsed );
    fprintf( stderr,"      Used=%d\n",_usedPairCount  );
    //_deltaUsed = _usedPairCount-_used;
    //fprintf( stderr,"Pairs after GC sweep %d\n",_deltaUsed );
    //fprintf( stderr,"      Used=%d\n",_usedPairCount  );
    //_cm_check_mem();
    //_cm_check_mem_leak();
    puts( "" );
  }
  // we don't get here
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
  _cm_check_mem_leak();

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

