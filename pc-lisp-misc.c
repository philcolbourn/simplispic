
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
    MESS_PEEK( "*WARN*","",mess,atom );                                  \
}
  
#define EXIT( mess,atom ){                                               \
    MESS_PEEK( "*EXIT*","",mess,atom );                                  \
    exit(1);                                                             \
}

       void _mem_print_used_pairs( char *m,ATOM p,ATOM save );
       void _mem_print_used_pairs_to_save( char *m,ATOM ret,ATOM save );


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
  //fprintf( stderr,"gcm=%3hhd mrk=%3hhd)\n",_gcm(p),_mrk(p) );
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
  if ( is_eq( a,EUL ) || is_eq( a,EFL ) || is_eq( a,NMT ) ){
    fprintf( stderr,"%8s = %3d: tag=%d val=%d [",m,a.atm,get_tag(a),get_val(a) );
    //fprinta( stderr,a );
    //fprintf( stderr,"]\n" );
    return;
  }
  if ( ! is_pair( a ) ){
    fprintf( stderr,"%8s === %3d: tag=%d val=%d [",m,a.atm,get_tag(a),get_val(a) );
    fprinta( stderr,a );
    fprintf( stderr,"]\n" );
    return;
  }
  fprintf( stderr,"[ %s = %3d:",m,get_val(a) );  
  fprinta( stderr,a );
  fprintf( stderr," ]\n" );
}

// ======================
// Print memory from p
// If p is usedPairs, use most recent pair.
// Highlight most recent used, global save and given pair
//
void _mem_print_used_pairs( char *m,ATOM p,ATOM save ){
  ATOM i = p;
  if ( is_eq( i,usedPairs ) ) i = _mem(p);
  fprintf( stderr,"==================\n" );    
  fprintf( stderr,"usedPairs    = %d\n",get_val( _mem(usedPairs) ) );    
  fprintf( stderr,"lastUsedPair = %d\n",get_val( lastUsedPair )    );    
  fprintf( stderr,"global save  = %d\n",get_val( _global_save )    );    
  fprintf( stderr,"save         = %d\n",get_val( save )            );    
  fprintf( stderr,"%s",m );    
  while ( ! is_eq( i,EUL ) ){
    if ( is_eq( i,_mem(usedPairs) ) ) fprintf( stderr,"\n\nUSED" );    
    if ( is_eq( i,lastUsedPair ) )    fprintf( stderr,"\n\nLAST" );    
    if ( is_eq( i,_global_save ) )    fprintf( stderr,"\n\nGLOB" );    
    if ( is_eq( i,save ) )            fprintf( stderr,"\n\nSAVE" );    

    if ( _ref(i)==0 )  fprintf( stderr," --\nZERO--> %d [",get_val(i) );    
    else 
      if ( _ref(i)<0 ) fprintf( stderr," --\n\n!!! %d !!!--> %d [",_ref(i),get_val(i) );    
      else             fprintf( stderr," --%d--> %d [",_ref(i),get_val(i) );    

    if ( is_atom( car(i) ) ) fprinta( stderr,car(i) );
    else                     fprintf( stderr,"->%d", get_val( car(i) ) ); 

    fprintf( stderr," " );
    
    if ( is_atom( cdr(i) ) ) fprinta( stderr,cdr(i) );
    else                     fprintf( stderr,"->%d", get_val( cdr(i) ) ); 
    fprintf( stderr,"]" );
    i = _mem(i);
  }
  fprintf( stderr,"-->\n" );    
  fprintf( stderr,"==================\n" );    
}

// Print memory from p to save inclusive
// If p is usedPairs, use most recent pair.
// Highlight most recent used, global save and given pair
//
void _mem_print_used_pairs_to_save( char *m,ATOM ret,ATOM save ){
  //int col = 0;
  ATOM i = _mem(usedPairs);
  fprintf( stderr,"==================\n" );    
  fprintf( stderr,"usedPairs    = %d\n",get_val( _mem(usedPairs) ) );    
  fprintf( stderr,"lastUsedPair = %d\n",get_val( lastUsedPair )    );    
  fprintf( stderr,"return       = %d\n",get_val( ret          )    );    
  fprintf( stderr,"global save  = %d\n",get_val( _global_save )    );    
  fprintf( stderr,"save         = %d\n",get_val( save )            );    
  fprintf( stderr,"%s",m );    

      EXITIF( ! is_pair(save),"save not pair",save );
  
  while ( ! is_eq( i,_mem(save) ) ){  // do save as well
    if ( is_eq( i,_mem(usedPairs) ) ){ fprintf( stderr,"\n\nUSED" );}    
    if ( is_eq( i,lastUsedPair ) )    fprintf( stderr,"\n\nLAST" );    
    if ( is_eq( i,_global_save ) )    fprintf( stderr,"\n\nGLOB" );    
    if ( is_eq( i,save ) )            fprintf( stderr,"\n\nSAVE" );    
    if ( is_eq( i,ret ) )             fprintf( stderr,"\n\nRETN" );    

    if ( _ref(i)==0 )  fprintf( stderr," \n  ZERO REF-> %d [",get_val(i) );    
    else 
      if ( _ref(i)<0 ) fprintf( stderr," \n  !!! %d !!!-> %d [",_ref(i),get_val(i) );    
      else             fprintf( stderr,"   %d-> %d [",_ref(i),get_val(i) );    

    if ( is_atom( car(i) ) ) fprinta( stderr,car(i) );
    else                     fprintf( stderr,"<%d>", get_val( car(i) ) ); 

    fprintf( stderr," " );
    
    if ( is_atom( cdr(i) ) ) fprinta( stderr,_cdr(i) );
    else                     fprintf( stderr,"<%d>", get_val( cdr(i) ) ); 
    fprintf( stderr,"]" );
    //if ( col%4==3 ) printf( stderr,"\n");
    //col++;
    i = _mem(i);
  }
  fprintf( stderr,"\n" );    
  fprintf( stderr,"==================\n" );    
}
#endif
#endif

