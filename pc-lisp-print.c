
#ifndef __header
  #define _pc_lisp_print_c
#endif

#ifndef _pc_lisp_print_h
  #define _pc_lisp_print_h
  #define __header

#ifdef __header

// HEADER
#include <stdio.h>
//#include "pc-lisp.h"
#include "pc-lisp-mem.c"
//#include "pc-lisp-test.c"
#include "pc-lisp-read2.c"
//#include "pc-lisp-primitives.c"
//#include "pc-lisp-adt.c"
//#include "pc-lisp-eval-adt.c"
#include "pc-lisp-main.c"

enum   {DUMP=0, PRINT=1, DISPLAY=2};
typedef char  *STRING;
extern STRING  printFormat[][3];  // how we format ATOMs when printing
extern int pmark;

void    fprinta ( FILE *f,ATOM a );
void    fprinta1( FILE *f,ATOM a,char *lsep,int fmt );
void    fprintp ( FILE *f,ATOM p,char sep,char *lsep,int fmt );
//void    fprintpn( FILE *f,ATOM p,char sep,int n );

ATOM    printa  ( ATOM a );
ATOM    display ( ATOM a );
void    printp  ( ATOM p,char sep );
ATOM    printerr( ATOM a );

// END HEADER
#endif

#if defined(_pc_lisp_print_c)

// CODE


int pmark = 0;  // to stop looping while printing hack

//{dump,print,display}
STRING printFormat[][3]={ 
  [PAR] = { "%d@  "   , "%d@"   , "%d@" },
  [NUM] = { "%d  "    , "%d"    , "%d"  },
  [RE3] = { "%d  "    , "%d"    , "%d"  },
  [RE5] = { "%d  "    , "%d"    , "%d"  },
  [RE7] = { "%d  "    , "%d"    , "%d"  },
  [SYM] = { "%s$  "   , "%s"    , "%s"  },
  [CHR] = { "%c  "    , "%c"    , "%c"  },
  [CON] = { "%d  "    , "%d"    , "%d"  },
  [STR] = { "\"%s\"  ", "\"%s\"", "%s"  },
  [PFN] = { "%x  "    , "%x"    , "%x"  }    // FIXME: remove?
};

void fprinta( FILE *f,ATOM a ){
  pmark = (pmark+1)%256;
  fprinta1( f,a,"\n  ",PRINT );
}

ATOM printa( ATOM a ){ 
  pmark = (pmark+1)%256;
  fprinta1( stdout,a,"",PRINT ); 
  return a;
}

ATOM printerr( ATOM a ){ 
  pmark = (pmark+1)%256;
  fprinta1( stderr,a,"",DISPLAY ); 
  return a;
}

ATOM display( ATOM a ){ 
  pmark = (pmark+1)%256;
  fprinta1( stdout,a,"",DISPLAY );
  return a;
}

void _print_flag( FILE *f,ATOM p ){
  if ( gcm(p)==1 ) fputc( '*',f );
  if ( gcm(p)==2 ) fputc( '_',f );
}

void fprinta1( FILE *f,ATOM a,char *lsep,int fmt ){
  if ( is_eq( a,NIL ) ){ fprintf( f,"()"         ); return; }
  if ( is_eq( a,END ) ){ fprintf( f,"?END?"      ); return; }
  if ( is_eq( a,MTY ) ){ fprintf( f,"?UNDEF?"    ); return; }
  if ( is_eq( a,REC ) ){ fprintf( f,"!RECYCLED!" ); return; }
  if ( is_eq( a,EOL ) ){ fprintf( f,"?)?"        ); return; }
  if ( is_eq( a,EOP ) ){ fprintf( f,"?.?"        ); return; }
  if ( is_eq( a,TRU ) ){ fprintf( f,"#t"         ); return; }

  switch ( get_tag(a) ){
  case PAR: 
    EXITIF( get_val(a)<=0,"Negative list index",a );
    // here is atom is (env ...) - rare
    if ( is_tenv(a) ){
      if ( is_eq( tenv_env(a),gEnv ) ) 
        fputs( "g",f );
      else
        fprintp( f,a,SP,"",fmt );  
      return; 
    }
    if ( is_lambda(a) ){  // (lambda (x) (car x) env G)
      fputs( "<",f ); 
      fprintp( f,a,SP,"",fmt );
      fputc( '>',f ); 
      return;
    }
    if ( is_primitive(a) ){ // (primitive (x) 1 env G)
      fputs( "{",f ); 
      fprintp( f,a,SP,"",fmt ); 
      fputc( '}',f ); 
      return;
    }
    if ( match_taglist( a,kw_quote) ){  // FIXME: hack
      fputc( '\'',f );
      fprinta1( f,cadr(a),"",fmt );
      return;
    }
    fputs( lsep,f );  // separator between atoms and lists
    fputs( "(",f ); 
    char buf[110]=""; // was "\0";
    if ( lsep[0]>0 )  // if more than NUL, indent
      snprintf( buf,99,"%s  %c",lsep,(char)0 );
    fprintp( f,a,SP,buf,fmt ); 
    fputs( ")",f ); 
    return; 

//  case STR: fprintf( f,"\"%s\"[%d]",strings[ get_str(a) ],sar[ get_str(a) ].gc  ); return;
  case STR:
    EXITIF( get_val(a)<=0,"Negative string index",a );
    fprintf( f,printFormat[ get_tag(a) ][fmt],strings[ get_str(a) ] ); 
    return;
    //{ fputc('"',f); fprintp( f,a,0  ); fputc('"',f); return; }
    // old SYM fprintp( f,a,0 ); return;  // SYM
  case SYM:
    if ( get_val(a)<0 )    
      fprintf( f,printFormat[ CHR ][fmt],-get_sym(a),f ); 
    else
      fprintf( f,printFormat[ get_tag(a) ][fmt],symbols[ get_sym(a) ].name,f ); 
    return;
  default:  
    fprintf( f,printFormat[ get_tag(a) ][fmt],get_val(a) );
  }
  return;
}

// print pairs (1 2 3) or (1 . 2)
void fprintp( FILE *f,ATOM p,char sep,char *lsep,int fmt ){
  ATOM t;                     // FIXME: could use p instead of t
LOOP:
  _print_flag( f,p );
  fprinta1( f,car(p),lsep,fmt );        // print (car p)
  set_pmk( p,pmark );
  t = cdr(p);                 // get (cdr p)
  if ( is_null(t) ) return;        // end of list so done
  if ( sep>0 ) fputc( sep,f );  // otherwise print separator
  if ( is_pair(t) ){  // handle special list elements ((l) env . (E))
    if ( is_eq( t,gEnv ) ){  // don't print global env if cdr of pair 
      _print_flag( f,t );
      fputs( "G",f ); 
      return; 
    }  // global env
    if ( is_tenv(t) ){  // don't loop from a procedure's env pointer
      //fputc( '[',f );
      if ( pmk(t)==pmark ){  //been here recently
        _print_flag( f,t );
        fputc( '@',f ); 
      }
      else
        fprintp( f,t,SP,"",fmt ); 
      //fputc( ']',f ); 
      return; 
    }
    p = t;
    goto LOOP;                // tail-call printp(cdr[p.val], sep)
  }
  fputc( '.',f );              // dotted pair
  fputc( sep,f );
  fprinta1( f,t,lsep,fmt );             // print (cdr p)
}

#endif
#endif

