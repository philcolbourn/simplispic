
#ifndef __header
  #define _pc_lisp_misc_c
#endif

#ifndef _pc_lisp_misc_h
  #define _pc_lisp_misc_h
  #define __header

#ifdef __header

// HEADER

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "pc-lisp-mem.c"
#include "pc-lisp-gc.c"
#include "pc-lisp-pair.c"

void         peekPair( char *m,ATOM p );
void         dump( int s );
void         peek( char *m,ATOM a );

#define FILE_LINE  \
  fprintf( stderr,"\n%s  %s %d",__func__,__FILE__,__LINE__ )

#define PEEK( mess,atom ){                                               \
    FILE_LINE;                                                           \
    fprintf( stderr,"  __" mess "__  " );                                \
    peek( #atom,(atom) );                                                \
}

#define MESS_PEEK( name,pred,mess,atom)                                  \
    fprintf( stderr,"=====" name " :  " #pred "  " );                    \
    PEEK( mess,atom );
  
#define EXITIF( pred,mess,atom ){                                        \
  if ( pred ){                                                           \
    MESS_PEEK( "EXITIF",pred,mess,atom );                                \
    exit(1);                                                             \
  }                                                                      \
}

#define RETNIF( pred,mess,atom ){                                        \
  if ( pred ){                                                           \
    MESS_PEEK( "RETNIF",pred,mess,atom );                                \
    return atom;                                                         \
  }                                                                      \
}

#define WARNIF( pred,mess,atom ){                                        \
  if ( pred ){                                                           \
    MESS_PEEK( "WARNIF",pred,mess,atom );                                \
  }                                                                      \
}

#define WARN( mess,atom ){                                               \
    MESS_PEEK( "*WARN*","",mess,atom );                                \
}
  
#define EXIT( mess,atom ){                                               \
    MESS_PEEK( "*EXIT*","",mess,atom );                                  \
    exit(1);                                                             \
}

static void _cm_mark_all_pairs( int m );
static void _cm_ensure_all_pairs_not_marked( int m );
static void _cm_clear_marks_on_free_pairs( int m );
static void _cm_clear_marks_on_used_pairs( int m );
static void _cm_clear_marks_on_atom( ATOM a,int m );

void _cm_check_mem();
void _cm_check_mem_leak();

void _mem_print_used_pairs( char *m,ATOM p,ATOM save );

// END HEADER

#endif

#if defined(_pc_lisp_misc_c)

// CODE
void peekPair( char *m,ATOM p ){
  if ( is_atom(p) ){
    fprintf( stderr,"%8s = %3d: tag=%d val=%d\n",m,p.atm,get_tag(p),get_val(p) );
    return;
  }
  fprintf( stderr,"%8s = %3d (",m,get_par(p) );
  DUMP_ATOM( car(p) );
  DUMP_ATOM( cdr(p) );
  DUMP_ATOM( _mem(p) );
  fprintf( stderr,"gcm=%3hhd mrk=%3hhd)\n",_gcm(p),_mrk(p) );
}

void dump( int s ){
  LOG("dump");
  fprintf( stderr,"freePairs = %d\n",get_par(freePairs) );
  fprintf( stderr,"usedPairs = %d\n",get_par(usedPairs) );
  
  int i;                      // i is an index here, not an ATOM
  for (i=0; i<s; i++){
    peekPair( "",make_par(i) );
  }
  LOG("/dump");
}

void peek( char *m,ATOM a ){
  fprintf( stderr,"[ %s = %3d:",m,get_par(a) );  
  fprinta( stderr,a );
  fprintf( stderr," ]\n" );
}


// ======================

void _mem_print_used_pairs( char *m,ATOM p,ATOM save ){
  ATOM i = p;
  if ( is_null(i) ) i=_mem(p);
  fprintf( stderr,"==================\n" );    
  fprintf( stderr,"usedPairs    = %d\n",get_val( _mem(usedPairs) ) );    
  fprintf( stderr,"lastUsedPair = %d\n",get_val( lastUsedPair )    );    
  fprintf( stderr,"global save  = %d\n",get_val( _global_save )    );    
  fprintf( stderr,"save         = %d\n",get_val( save )            );    
  fprintf( stderr,"%s",m );    
  while ( ! is_null(i) ){
    if ( is_eq( i,_mem(usedPairs) ) ) fprintf( stderr,"\n\nUSED" );    
    if ( is_eq( i,lastUsedPair ) )    fprintf( stderr,"\n\nLAST" );    
    if ( is_eq( i,_global_save ) )    fprintf( stderr,"\n\nGLOB" );    
    if ( is_eq( i,save ) )            fprintf( stderr,"\n\nSAVE" );    

    if ( _ref(i)==0 ) fprintf( stderr," --\nZERO--> %d [",get_val(i) );    
    else if ( _ref(i)<0 ) fprintf( stderr," --\n\n!!! %d !!!--> %d [",_ref(i),get_val(i) );    
    else fprintf( stderr," --%d--> %d [",_ref(i),get_val(i) );    
    if ( is_atom( car(i) ) ) fprinta( stderr,car(i) );
    else fprintf( stderr,"->%d", get_val( car(i) ) ); 
    fprintf( stderr," " );
    if ( is_atom( cdr(i) ) ) fprinta( stderr,cdr(i) );
    else fprintf( stderr,"->%d", get_val( cdr(i) ) ); 
    fprintf( stderr,"]" );
    i = _mem(i);
  }
  fprintf( stderr,"-->\n" );    
  fprintf( stderr,"==================\n" );    
}



// ========================

void _cm_mark_all_pairs( int m ){
  int i;
  for ( i=0; i<SIZE; i++ ){
    _set_mrk( make_par(i),m );  
  }
}

void _cm_ensure_all_pairs_not_marked( int m ){
  int i,mCount=0,cCount=0;
  for (i=0; i<SIZE; i++){
    //WARNIF( _gcm( make_par(i) )==2,"Special pair",make_par(i) );
    if ( _mrk( make_par(i) )==m ) mCount++;
    if ( _mrk( make_par(i) )!=0 ) cCount++;

    //WARNIF( _mrk( make_par(i) )==m,"A pair is still marked!",make_par(i) );
    //WARNIF( _mrk( make_par(i) )!=0,"A pair is not cleared!",make_par(i) );
  }
  EXITIF( mCount>0,"Pairs still marked",make_num(mCount) )
  EXITIF( cCount>0,"Pairs not cleared",make_num(cCount) )
}


void _cm_clear_marks_on_free_pairs( int m ){
  int c = 0;
  ATOM f = freePairs;
  while ( ! is_null(f) ){
    WARNIF( _mrk(f)!=m,"Free pair not marked!",f );
    if ( _mrk(f)!=m ) c++;
    _set_mrk( f,0 );
    f = _mem(f);
  }
  //EXITIF( c>0,"Free pairs not marked!",NIL );
}
    
void _cm_clear_marks_on_used_pairs( int m ){
  ATOM u = usedPairs;
  do{
    EXITIF( _mrk(u)!=m,"Used pair not marked!",u);
    _set_mrk( u,0 );
    u = _mem(u);
  }while ( ! is_null(u) );
}

void _cm_clear_marks_on_atom( ATOM a,int m ){
  while ( is_pair(a) ){
    if ( _mrk(a)!=m ) return;    // no need to go further to avoid loops
    _set_mrk( a,0 );                     // unmark - keep
    //EXITIF( is_null(a),"",a );
    _cm_clear_marks_on_atom( car(a),m );  // follow car tree
    a = cdr(a);
  }
}

// these should only use mrk to check pair allocations and gc performance
void _cm_check_mem(){
  //PEEK( "start",NIL );
  //EXITIF( ! is_null(usedPairs),"usedPairs should be NIL!",usedPairs );
  WARNIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );  // is null when no more free pairs!
  _cm_mark_all_pairs(99);
  _cm_clear_marks_on_free_pairs(99);
  _cm_clear_marks_on_used_pairs(99);
  _cm_ensure_all_pairs_not_marked(99);  // any leaks?
  //PEEK( "done",NIL );
}

void _cm_check_mem_leak(){  // only run in repl after gc
  PEEK( "start",NIL );
  WARNIF( is_null(freePairs),"freePairs should never be NIL!",freePairs );
  _cm_mark_all_pairs(23);
  _cm_clear_marks_on_atom( gEnv,23 );  // clear marks in environment
  _set_mrk( make_par(0),0 );  // required? yes, but why did it work without it for so long?
  _cm_clear_marks_on_free_pairs(23);  // fails if a free pair has no mark
  _cm_ensure_all_pairs_not_marked(23);  // any leaks?
  PEEK( "done",NIL );
}

#endif
#endif

