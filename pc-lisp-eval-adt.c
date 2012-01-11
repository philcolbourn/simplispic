
#ifndef __header
  #define _pc_lisp_eval_adt_c
#endif

#ifndef _pc_lisp_eval_adt_h
  #define _pc_lisp_eval_adt_h
  #define __header    

#ifdef __header

#include "pc-lisp-mem.c"
#include "pc-lisp-read2.c"
#include "pc-lisp-main.c"

int is_application( ATOM exp );
int is_progn      ( ATOM exp );
int is_display    ( ATOM exp );
int is_print      ( ATOM exp );
int is_eval       ( ATOM exp );
int is_eval1      ( ATOM exp );
int is_apply      ( ATOM exp );
int is_load       ( ATOM exp );
int is_read       ( ATOM exp );
//int is_cons_stream( ATOM exp ){ return match_taglist( exp,kw_cons_stream ); }
int is_delay      ( ATOM exp );
int is_eval_list  ( ATOM exp );
int is_if         ( ATOM exp );
int is_cond       ( ATOM exp );
int is_quoted     ( ATOM exp );
int is_definition ( ATOM exp );
int is_variable   ( ATOM exp );
int is_set        ( ATOM exp );
int is_self_eval  ( ATOM exp );
ATOM quoted_value( ATOM exp );
/*
if expression ADT
(if pred con alt)
*/
ATOM if_pred( ATOM exp );
ATOM if_con( ATOM exp );
ATOM if_alt( ATOM exp );
// (if p? con alt) special form since only con or alt is evaluated
ATOM eval_if( ATOM exp,ATOM env );
/*
((pred1 con1) (pred1 con2) ... (else alt))

(cond (pred1 con1) (pred2 con2) (else alt)) 
(define eval-cond (lambda (conds bindings)
  (if ((eval (car (car conds)) env)
      (eval (car (cdr (car conds))) env))
      (eval-cond (cdr conds) env)  )  ))
*/
int is_cond_clause( ATOM clau );
ATOM cond_clause_pred( ATOM clau );
ATOM cond_clause_con( ATOM clau );
ATOM eval_cond_clauses( ATOM lst,ATOM env );

// (progn e1 e2 ... en)  eg. (progn (car x) (car y))
// FIXME: what if one exp is a define? - seems to work
ATOM eval_progn( ATOM seq,ATOM env );
ATOM eval_list( ATOM exp,ATOM env );

/*
definition ADT

(define variable value)
(define (<name> <formals>) <body>)
  -> (define <variable> (lambda (<formals>) <body>) in macro
*/

ATOM definition_variable( ATOM exp );

ATOM definition_value( ATOM exp );

// (define sym val) special form since sym is not evaluated
ATOM eval_definition( ATOM exp,ATOM env );

// (set! sym val) special form since sym is not evaluated
ATOM eval_set( ATOM exp,ATOM env );
ATOM variable_value( ATOM var,ATOM env );

/*
ATOM variable_kvp(ATOM var, ATOM env);
*/



#endif

#if defined(_pc_lisp_eval_adt_c)

int is_application( ATOM exp ){ return is_app( exp )                      ; }
int is_progn      ( ATOM exp ){ return match_taglist( exp,kw_progn )      ; }
int is_display    ( ATOM exp ){ return match_taglist( exp,kw_display )    ; }
int is_print      ( ATOM exp ){ return match_taglist( exp,kw_print )      ; }
int is_eval       ( ATOM exp ){ return match_taglist( exp,kw_eval )       ; }
int is_eval1      ( ATOM exp ){ return match_taglist( exp,kw_eval1 )      ; }
int is_apply      ( ATOM exp ){ return match_taglist( exp,kw_apply )      ; }
int is_load       ( ATOM exp ){ return match_taglist( exp,kw_load )       ; }
int is_read       ( ATOM exp ){ return match_taglist( exp,kw_read )       ; }
//int is_cons_stream( ATOM exp ){ return match_taglist( exp,kw_cons_stream ); }
int is_delay      ( ATOM exp ){ return match_taglist( exp,kw_delay )      ; }
int is_eval_list  ( ATOM exp ){ return match_taglist( exp,kw_list )       ; }
int is_if         ( ATOM exp ){ return match_taglist( exp,kw_if )         ; }
int is_cond       ( ATOM exp ){ return match_taglist( exp,kw_cond )       ; }
int is_quoted     ( ATOM exp ){ return match_taglist( exp,kw_quote )      ; }
int is_definition ( ATOM exp ){ return match_taglist( exp,kw_define )     ; }
int is_variable   ( ATOM exp ){ return is_sym( exp )                      ; }
int is_set        ( ATOM exp ){ return match_taglist( exp,kw_set        )     ; }
int is_self_eval  ( ATOM exp ){
  return is_null(exp) || is_num(exp) || is_chr(exp) || is_str(exp) || is_con(exp);
}

ATOM quoted_value( ATOM exp ){
  return car( taglist_list( exp ) );
}

/*
if expression ADT
(if pred con alt)
*/
ATOM if_pred( ATOM exp ){
  EXITIF( ! is_if( exp ),"Not an if expression",exp );
  EXITIF( is_null( _Rfrom2(exp) ),"No predicate and consequent terms",exp );
  return _2ND( exp );
}

ATOM if_con( ATOM exp ){
  EXITIF( ! is_if( exp ),"Not an if expression",exp );
  EXITIF( is_null( _Rfrom3(exp) ),"No consequent term",exp );
  return _3RD( exp );
}

ATOM if_alt( ATOM exp ){
  EXITIF( ! is_if( exp ),"Not an if expression",exp );
  if ( is_null( _Rfrom4(exp) ) )  return NIL;
  return _4TH( exp );
}

// (if p? con alt) special form since only con or alt is evaluated
ATOM eval_if( ATOM exp,ATOM env ){
  ATOM pred = if_pred(exp);  // predicate
  //PEEK( "",pred );
  ATOM epred = eval( pred,env );  // eval predicate
  //PEEK( "",epred );
  if ( ! is_null(epred) ){
    ATOM con = if_con(exp);
    //PEEK( "",con );
    ATOM res = eval( con,env );
    //PEEK( "",res );
    return res;
  }
  ATOM alt = if_alt(exp);
  //PEEK( "",alt );
  ATOM res = eval( alt,env );
  //PEEK( "",res );
  return res;
}

/*
((pred1 con1) (pred1 con2) ... (else alt))

(cond (pred1 con1) (pred2 con2) (else alt)) 
(define eval-cond (lambda (conds bindings)
  (if ((eval (car (car conds)) env)
      (eval (car (cdr (car conds))) env))
      (eval-cond (cdr conds) env)  )  ))
*/
int is_cond_clause( ATOM clau ){
  return is_pair( clau );
}

ATOM cond_clause_pred( ATOM clau ){
  EXITIF( ! is_cond_clause( clau ),"Not an cond clause",clau );
  return car( clau );
}

ATOM cond_clause_con( ATOM clau ){
  EXITIF( ! is_cond_clause( clau ),"Not an cond clause",clau );
  return cdr( clau );
}

ATOM eval_cond_clauses( ATOM lst,ATOM env ){
  ATOM clau = car( lst );
  ATOM pred = cond_clause_pred( clau );
  if ( ! is_null( eval(pred,env) ) ){
    ATOM con = cond_clause_con( clau );
    return evalseq( con,env );  // FIXME: is this right?
  }
  else{
    return eval_cond_clauses( _REST(lst),env );
  }
}

// (progn e1 e2 ... en)  eg. (progn (car x) (car y))
// FIXME: what if one exp is a define? - seems to work
ATOM eval_progn( ATOM seq,ATOM env ){
  MARK3;
  //PEEK( "",seq );
  ATOM res = evalseq( seq,env );
  RETURN3( res );
}



ATOM eval_list( ATOM exp,ATOM env ){
  ATOM args = app_args( exp );
  ATOM list = evallst( args,env );
  return list;
}



/*
definition ADT

(define variable value)
(define (<name> <formals>) <body>)
  -> (define <variable> (lambda (<formals>) <body>) in macro
*/

ATOM definition_variable( ATOM exp ){
  if ( is_symbol( _2ND(exp) ) )  return _2ND( exp );
  EXIT( "Unknown define structure",exp );
  return car( _2ND(exp) );  //return caadr( exp );
}

ATOM definition_value( ATOM exp ){
  if ( is_symbol( _2ND(exp) ) )  return _3RD( exp );
  EXIT( "Unknown define structure",exp );
  ATOM form = _Rof2( exp );  //cdadr( exp );  //_Ro2
  //ATOM body = cddr( exp );  // FIXME: SICP-but this is list of body???
  ATOM body = _3RD( exp );
  ATOM lamb = make_lambda( form,body );
  return lamb;
}

// (define sym val) special form since sym is not evaluated
ATOM eval_definition( ATOM exp,ATOM env ){
  MARK3;
  //PEEK( "",exp );
  //PEEK( "",env );
  ATOM sym    = _2ND( exp );
  //PEEK( "",sym );
  ATOM val    = eval( _3RD(exp),env ); // we must (eval value)
  //PEEK( "",val );
  ATOM kvp    = make_kvp( sym,val );
  //PEEK( "",kvp );
  _mark_assignments_as_special( kvp );
  ATOM fra = addKVPair3( kvp,env );
  //ATOM def = cons( kw_define,fra );  // need special return to keep all
  //PEEK( "",fra );  
  //RETURN3( def );
  RETURN3( sym );
}

// (set! sym val) special form since sym is not evaluated
ATOM eval_set( ATOM exp,ATOM env ){
  MARK3;
  //PEEK( "",exp );
  //PEEK( "",env );
  ATOM sym    = _2ND( exp );
  ATOM val    = eval( _3RD(exp),env ); // we must (eval value)
  //PEEK( "",sym );
  //PEEK( "",val );
  ATOM kvp    = assoc_kvp( sym,env );
  //PEEK( "",kvp );
  EXITIF( is_null( kvp ),"sym not found in environment",sym );
  ATOM res = set_cdr( kvp,val );
  _mark_assignments_as_special( res );
  //PEEK( "",kvp );
//  ATOM set = cons( kw_set,kvp );  // need special return to keep all
//  PEEK( "",set );  
  RETURN3( sym );
}

// eval helpers

ATOM variable_value( ATOM var,ATOM env ){
  //ATOM res = assoc( var,env );
  ATOM kvp = assoc2( var,env );
  EXITIF( is_null( kvp ),"var not found in environment",var );
  ATOM res = kvp_val(kvp);
  return res;
}

/*
ATOM variable_kvp(ATOM var, ATOM env){
  return assoc2( var,env );
}
*/

#endif
#endif


