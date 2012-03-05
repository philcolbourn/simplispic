
#ifndef __header
  #define _pc_lisp_adt_c
#endif

#ifndef _pc_lisp_adt_h
  #define _pc_lisp_adt_h
  #define __header    

#ifdef __header

#include "pc-lisp-mem.c"

ATOM    make_kvp( ATOM key,ATOM val );
int     is_kvp  ( ATOM kvp );
ATOM    kvp_key ( ATOM kvp );
ATOM    kvp_val ( ATOM kvp );

ATOM    make_taglist ( ATOM tag,ATOM lst );
int     is_taglist   ( ATOM lst );
int     match_taglist( ATOM lst,ATOM tag );
ATOM    taglist_list ( ATOM tl );
ATOM    taglist_tag  ( ATOM tl );

ATOM    make_tenv( ATOM env );
int     is_tenv  ( ATOM tenv );
ATOM    tenv_env ( ATOM tenv );

ATOM    make_lambda( ATOM form,ATOM body );
int     is_lambda  ( ATOM lamb );
ATOM    lambda_form( ATOM lamb );
ATOM    lambda_body( ATOM lamb );

ATOM    make_proc  ( ATOM lamb,ATOM env );
int     is_proc    ( ATOM proc );
ATOM    proc_lambda( ATOM proc );
ATOM    proc_env   ( ATOM proc );

ATOM    make_primitive( ATOM form,ATOM name,ATOM cfun );
int     is_primitive  ( ATOM prim );
ATOM    primitive_form( ATOM prim );
ATOM    primitive_name( ATOM prim );
ATOM    primitive_cfun( ATOM prim );

ATOM    make_alist    ( ATOM keys,ATOM vals );
ATOM    extend_alist  ( ATOM kvp,ATOM alst );
int     is_alist      ( ATOM alst );
ATOM    alist_assoc   ( ATOM key,ATOM alst );
ATOM    alist_find    ( ATOM key,ATOM alst );
ATOM    alist_keys    ( ATOM alst );
ATOM    alist_vals    ( ATOM alst );
ATOM    alist_car_vals( ATOM alst );

ATOM    make_app( ATOM proc,ATOM args );
int     is_app  ( ATOM app );
ATOM    app_proc( ATOM app );
ATOM    app_args( ATOM app );

#endif

#if defined(_pc_lisp_adt_c)

/*
key value pair ADT

  kvp-->[k][v]
*/
// x,99 -> (x . 99)
// x,(a b c) -> (x . (a b c)) = (x a b c) 
ATOM make_kvp( ATOM key,ATOM val ){
  // FIXME: key could be a list
  EXITIF( ! is_atom( key ),"key is not an atom",key );
  ATOM kvp = cons( key,val );
  return kvp;
}

int is_kvp( ATOM kvp ){
  return is_pair( kvp ) && is_atom( car( kvp ) );
}

// (x . 99) -> x
ATOM kvp_key( ATOM kvp ){
  EXITIF( ! is_kvp( kvp ),"kvp is not a key-value pair",kvp );
  ATOM key = car( kvp );
  return key;
}

// (x . 99) -> 99
ATOM kvp_val( ATOM kvp ){
  EXITIF( ! is_kvp( kvp ),"kvp is not a key-value pair",kvp );
  ATOM val = cdr( kvp );
  return val;
}

// alist ADT
// will use this eventually for environment
/*
  alist-->[o][o]
           |  |
           v  v
      [k][v]  [o][o]
               |  |
               v  v
          [k][v]  [o][o]

(a b),(1 2) -> ( (a . 1) (b . 2) )
a,(1 2) -> ( (a . (1 2)) )
(a . b),(1 2 3 4 5) -> ( (a . 1) (b . (2 3 4 5)) )
*/

/*
(define make-alist (lambda (keys vals)
  (cond ((null? keys) (if (null? vals) '() (warn "Not enough keys for values" 'vals vals)))
        ((atom? keys) (list (make-kvp keys vals)) )
        ((null? vals) (list (make-kvp (car keys) '())
                            (make-alist (cdr keys) '())) )
        (else (list (make-kvp (car keys) (car vals))
                            (make-alist (cdr keys) (cdr vals)))  )) 
))
*/
ATOM make_alist( ATOM k,ATOM v ){  // (a b),(1 2) -> ((a . 1)(b . 2))
  if ( is_null(k) )
    if ( is_null(v) ) return NIL;
    else EXIT( "Not enough keys for values",v );

  if ( is_atom(k) )   // handle list-arg and dot pair case
    return cons( make_kvp( k,v ),NIL );
    
/* changed to atom
  if ( is_null(v) ){
    ATOM p = make_kvp( car(k),NIL );
    ATOM a = cons( p,make_alist( cdr(k),NIL ) );
    return a;
  }
*/

  if ( is_atom(v) ){
    ATOM p = make_kvp( car(k),v );
    ATOM a = cons( p,make_alist( cdr(k),NIL ) );
    return a;
  }
    
  ATOM p = make_kvp( car(k),car(v) );
  ATOM a = cons( p,make_alist( cdr(k),cdr(v) ) );
      //ALIST_PEEK( "",a );
      EXITIF( ! is_alist( a ),"not an associative list",a );  
  return a;
}

ATOM extend_alist( ATOM p,ATOM a ){
      //PEEK( "",p );
      EXITIF( ! is_kvp( p ),"not a key-value pair",p );
/*
  FILE *old = in;
  FILE *f = fopen( "/dev/tty" ,"r" );
      EXITIF( f==NULL,"Could not open /dev/tty",cons( p,a ) );
  in = f;
      //peek( "eval.load: exp",exp );
  GLOBAL_KEEP3( NIL );   // get rid of all debugging
  ATOM r = repl();
  PEEK( "",r );
  fclose(f);
  in = old;
/**/
      //PEEK( "",a );
      EXITIF( ! is_alist( a ),"not an associative list",a );
  ATOM r = cons( p,a );
      EXITIF( ! is_alist( r ),"not an associative list",r );
      //PEEK( "",r );
  return r;  
}

int is_alist( ATOM a ){
      //PEEK( "",a );
  if ( is_null(a) ) return TRUE;  // FIXME: is NIL an alist?
  if ( is_atom(a) ) return FALSE;
  if ( ! is_kvp( car(a) ) ) return FALSE;
  // FIXME: turned on
      //PEEK( "",a );
  //if ( ! is_alist( cdr(a) ) ) return FALSE;  // test whole alist
  return TRUE;
}

ATOM alist_keys( ATOM a ){
      //ALIST_PEEK( "",a );
  if ( is_null(a) ) return NIL;
      EXITIF( ! is_alist(a),"not an associative list",a );
  return cons( kvp_key( car(a) ),alist_keys( cdr(a) ) );
}

ATOM alist_vals( ATOM a ){
      //ALIST_PEEK( "",a );
  if ( is_null(a) ) return NIL;
      EXITIF( ! is_alist(a),"not an associative list",a );
  return cons( kvp_val( car(a) ),alist_vals( cdr(a) ) );
}

ATOM alist_car_vals( ATOM a ){
      //ALIST_PEEK( "",a );
  if ( is_null(a) ) return NIL;
      EXITIF( ! is_alist(a),"not an associative list",a );
  return cons( car( kvp_val( car(a) ) ),alist_car_vals( cdr(a) ) );
}

/*
(define (assoc x a)
  (cond ((null? a) #f)
    ((equal? (caar a) x) (car a))
    (else (assoc x (cdr a)))))
*/
// return kvp
//
ATOM alist_assoc( ATOM k,ATOM a ){
      //ALIST_PEEK( "",k );
      //ALIST_PEEK( "",a );
      EXITIF( ! is_atom(k),"not an atom",k );
      EXITIF( ! is_alist(a),"not an alist",a );
  if ( is_null(a) ) return FAL;
  if ( equal( k,kvp_key( car(a) ) ) ) return car( a );
  return alist_assoc( k,cdr(a) );  
}

ATOM alist_find( ATOM k,ATOM a ){ 
  return alist_assoc( k,a ); 
}

/*
table ADT

  table-->[o][o]
           |  |
           v  v
       table  [o][o]
               |  |
               v  v
          [k][v]  [o][o]
                   |  |
                   v  v
              [k][v]  [o][/]
                       |
                       v
                  [k][v]
*/
ATOM make_table( ATOM tag ){
  EXITIF( ! is_atom(tag),"tag is not an atom",tag );
  ATOM res = make_taglist( tag,NIL );
  return res;  
}

int is_table( ATOM table ){
  return is_taglist( table );
}

ATOM table_tag( ATOM table ){ 
  return taglist_tag( table ); 
}

// insert a new element onto list
ATOM table_insert_kvp( ATOM table,ATOM kvp ){
  ATOM next = cdr( table );
  ATOM new = cons( kvp,next );
  set_cdr( table,new );
  return table; 
}

ATOM table_find( ATOM key,ATOM table ){
  return alist_find( key,cdr( table ) );
}

/*
tagged list ADT

  taglist-->[o][o]
             |  |
             v  v
           tag  [o][o]
                 |  |
                 v  v
                 ?  [o][o]
                     |  |
                     v  v
                     ?  [o][/]
                         |
                         v
                         ?
*/
// (tag,(some list)) -> (tag some list)
ATOM make_taglist( ATOM tag,ATOM lst ){
  EXITIF( ! is_atom( tag ),"tag is not an atom",tag );
  // FIXME: is_list here, is_pair in seletors???
  //EXITIF( ! is_list( lst ),"lst is not () or a list",lst );
  EXITIF( ! is_pair( lst ),"lst is not () or a list",lst );
  ATOM taglist = cons( tag,lst );
  return taglist;
}

int match_taglist( ATOM lst,ATOM tag ){
  if ( ! is_pair(lst) ) return FALSE;
  return is_eq( car(lst),tag );
}
int is_taglist( ATOM taglist ){
  return is_pair(taglist) && is_atom( car(taglist) );
}

ATOM taglist_list( ATOM taglist ){
  EXITIF( ! is_pair( taglist ),"taglist is not a list",taglist );
  EXITIF( ! is_atom( car(taglist) ),"taglist is not a list",taglist );
  return cdr( taglist );
}

ATOM taglist_tag( ATOM taglist ){
  EXITIF( ! is_pair( taglist ),"taglist is not a list",taglist );
  EXITIF( ! is_atom( car(taglist) ),"tag is not an atom",car( taglist ) );
  return car( taglist );
}

ATOM taglist_insert( ATOM taglist,ATOM item ){
  EXITIF( ! is_taglist( taglist ),"taglist is not a tagged list",taglist );
  ATOM new = cons( item,taglist_list(taglist) );
  set_cdr( taglist,new );
  return taglist;
}

// tagged environment ADT

// G -> (env . G)
ATOM make_tenv( ATOM env ){ return make_taglist( tag_env,env ); }
int is_tenv( ATOM tenv ){ return match_taglist( tenv,tag_env ); }

// (env . G) -> G
ATOM tenv_env( ATOM tenv ){
  EXITIF( ! is_tenv( tenv ),"tenv is not a tagged environment",tenv );
  ATOM env = taglist_list( tenv );
  return env;
}

// primitive ADT

// (x),car,3 -> (primitive car (x) 3)  
ATOM make_primitive( ATOM form,ATOM name,ATOM cfun ){
  ATOM left = cons( form,cfun );
  ATOM temp = cons( name,left );
  ATOM prim = cons( kw_primitive,temp );
  return prim;
}

int is_primitive( ATOM prim ){ 
  return match_taglist( prim,kw_primitive ); 
}

ATOM primitive_name( ATOM prim ){
  EXITIF( ! is_primitive( prim ),"prim not a primitive procedure",prim ); 
  ATOM form = _2ND( prim );
  return form;
}

ATOM primitive_form( ATOM prim ){
  EXITIF( ! is_primitive( prim ),"prim not a primitive procedure",prim ); 
  ATOM form = _3RD( prim );
  return form;
}

ATOM primitive_cfun( ATOM prim ){
  EXITIF( ! is_primitive( prim ),"prim not a primitive procedure",prim ); 
  ATOM cfun = _4TH( prim );
  return cfun;
}

// lambda ADT

// (x),((car x)) -> (lambda (x) (car x))  
ATOM make_lambda( ATOM form,ATOM body ){
  MARK3;
  //PEEK( "",body );
  //exit(1);
  //ATOM left = cons( form,cons( body,NIL ) );  // FIXME: SICP does not cons(body,NIL)
  ATOM left = cons( form,body );  // FIXME: SICP does not cons(body,NIL)
  ATOM lamb = cons( kw_lambda,left );
  //PEEK( "",lamb );
  //exit(1);
  RETURN3( lamb );  //return lamb;
}

int is_lambda( ATOM lamb ){ 
  return match_taglist( lamb,kw_lambda ); 
}

ATOM lambda_form( ATOM lamb ){
  EXITIF( ! is_lambda( lamb ),"lamb is not a lambda expression",lamb ); 
  ATOM form = _2ND( lamb );
  return form;
}

ATOM lambda_body( ATOM lamb ){
  EXITIF( ! is_lambda( lamb ),"lamb is not a lambda expression",lamb ); 
  //ATOM body = _3RD( lamb );
  ATOM body = _Rfrom3( lamb );  // as a list
  return body;
}


// procedure ADT

// (lambda (x) (car x)),G -> (closure (lambda (x) (car x) env G)  
// (primitive (x) 1),G -> (closure (lambda (x) (car x) env G)  

ATOM make_proc( ATOM func,ATOM env ){
  EXITIF( ! ( is_lambda(func) || is_primitive(func) ),
    "func is not a lambda nor primitive",func );
  //PEEK( "",lamb );
  ATOM tenv = make_tenv( env );
  ATOM clos = cons( func,tenv ); //PEEK( "",clos );
  ATOM proc = make_taglist( kw_closure,clos ); //PEEK( "",proc );
  return proc;
}

int is_proc( ATOM proc ){
  return match_taglist( proc,kw_closure ) 
    && ( match_taglist( _2ND(proc),kw_lambda ) 
      || match_taglist( _2ND(proc),kw_primitive ) ); 
}

// (closure (lambda (x) (car x)) env G) -> (lambda (x) (car x)) 
// (closure (primitive (x) 1) env G) -> (primitive (x) 1) 

ATOM proc_lambda( ATOM proc ){
  EXITIF( ! is_proc( proc ),"proc is not a procedure",proc ); 
  ATOM lamb = _2ND( proc );
  return lamb;
}

// (closure (lambda (x) (car x)) env G) -> G 
// (closure (primitive (x) 1) env G) -> G 

ATOM proc_env( ATOM proc ){
  EXITIF( ! is_proc( proc ),"proc is not a procedure",proc ); 
  ATOM tenv = _Rfrom3( proc );
  ATOM env = tenv_env( tenv );
  return env;
}

/*
application ADT
( car '(1 2) )
( (closure (lambda (x) (car x)) env G) '(1 2) )
( (closure (primitive (x) 1) env G) '(1 2) )
*/

ATOM make_app( ATOM proc,ATOM args ){
  EXITIF( ! ( is_symbol(proc) || is_proc(proc) ),
    "proc is not a symbol or procedure",proc );
  ATOM app = cons( proc,args );
  return app;
}

int is_app( ATOM app ){
  //PEEK( "",app );
  if ( ! is_pair(app)     ) return FALSE;
  ATOM proc = car( app );
  if ( is_symbol(proc)    ) return TRUE;
  if ( is_lambda(proc)    ) return TRUE;
  if ( is_primitive(proc) ) return TRUE;
  return FALSE;
}

ATOM app_proc( ATOM app ){
  EXITIF( ! is_app( app ),"app is not an application",app );
  return car( app );
}

ATOM app_args( ATOM app ){
  EXITIF( ! is_app( app ),"app is not an application",app );
  return cdr( app );
}
#endif
#endif

