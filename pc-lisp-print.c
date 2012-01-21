
#ifndef __header
  #define _pc_lisp_print_c
#endif

#ifndef _pc_lisp_print_h
  #define _pc_lisp_print_h
  #define __header

#ifdef __header

// HEADER

#include <stdio.h>
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

ATOM    fprinta ( FILE *f,ATOM a );
ATOM    fprinta1( FILE *f,ATOM a,char *lsep,int fmt );
ATOM    fprintp ( FILE *f,ATOM p,char sep,char *lsep,int fmt );
//void    fprintpn( FILE *f,ATOM p,char sep,int n );

ATOM    printa  ( ATOM a );
ATOM    display ( ATOM a );
ATOM    printp  ( ATOM p,char sep );
ATOM    printerr( ATOM a );
ATOM    disperr ( ATOM a );

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

// how to do stdin stdout stderr?
// (define f (open "filename"))

/*
ATOM write( ATOM f,ATOM a ){
  int fd = dup( get_num(f) );  // duplicate file descriptor
  FILE file = fdopen( fd,"w" );
  fprinta( file,a );
  return a;
}
*/
ATOM fprinta( FILE *f,ATOM a ){
  pmark = (pmark+1)%256;
  fprinta1( f,a,"\n  ",PRINT );
  return a;
}

ATOM printa( ATOM a ){ 
  pmark = (pmark+1)%256;
  fprinta1( stdout,a,"",PRINT ); 
  return a;
}

ATOM printerr( ATOM a ){ 
  pmark = (pmark+1)%256;
  fprinta1( stderr,a,"",PRINT ); 
  return a;
}

ATOM disperr( ATOM a ){ 
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
  //if ( pmk(p)!=pmark ) fprintf( f,"{%d}",pmk(p) );
  if ( _gcm(p)==1 ) fputc( '*',f );
  if ( _gcm(p)==2 ) fputc( '_',f );
  if ( _gcm(p)==2 ) fputc( '!',f );
}

ATOM fprinta1( FILE *f,ATOM a,char *lsep,int fmt ){
  switch ( get_tag(a) ){

  case CON:
    if ( is_eq( a,TRU ) ){ fprintf( f,"#t"         ); return a; }
    if ( is_eq( a,END ) ){ fprintf( f,"?END?"      ); return a; }
    if ( is_eq( a,MTY ) ){ fprintf( f,"?UNDEF?"    ); return a; }
    if ( is_eq( a,REC ) ){ fprintf( f,"!RECYCLED!" ); return a; }
    fprintf( f,printFormat[ get_tag(a) ][fmt],get_val(a) );
    return a;
    
  case CHR:
    //if ( is_eq( a,EOP ) ){ fprintf( f,"?.?"        ); return a; }
    //if ( is_eq( a,EOL ) ){ fprintf( f,"?)?"        ); return a; }
    fprintf( f,printFormat[ get_tag(a) ][fmt],get_val(a) );
    return a;
    
  case PAR: 
    if ( is_eq( a,NIL ) ){ fprintf( f,"()"         ); return a; }
    EXITIF( get_val(a)<=0,"Negative list index",a );
    if ( is_lambda(a) ){  // (lambda (x) (car x) env G)
      fputs( "<",f ); 
      fprintp( f,a,SP,"",fmt );
      fputc( '>',f ); 
      return a;
    }
    if ( is_primitive(a) ){ // (primitive (x) 1 env G)
      fputs( "{",f ); 
      fprintp( f,a,SP,"",fmt ); 
      fputc( '}',f ); 
      return a;
    }
    if ( match_taglist( a,kw_quote) ){  // FIXME: hack
      fputc( '\'',f );
      fprinta1( f,cadr(a),"",fmt );
      return a;
    }
    fputs( lsep,f );  // separator between atoms and lists
    fputs( "(",f ); 
    char buf[110]=""; // was "\0";
    if ( lsep[0]>0 )  // if more than NUL, indent
      snprintf( buf,99,"%s  %c",lsep,(char)0 );
    fprintp( f,a,SP,buf,fmt ); 
    fputs( ")",f ); 
    return a; 

//  case STR: fprintf( f,"\"%s\"[%d]",strings[ get_str(a) ],sar[ get_str(a) ].gc  ); return;

  case STR:
    EXITIF( get_val(a)<=0,"Negative string index",a );
    fprintf( f,printFormat[ get_tag(a) ][fmt],strings[ get_str(a) ] ); 
    return a;
    //{ fputc('"',f); fprintp( f,a,0  ); fputc('"',f); return; }
    // old SYM fprintp( f,a,0 ); return;  // SYM

  case SYM:
    if ( get_val(a)<0 )    
      fprintf( f,printFormat[ CHR ][fmt],-get_sym(a),f ); 
    else
      fprintf( f,printFormat[ get_tag(a) ][fmt],symbols[ get_sym(a) ].name,f ); 
    return a;

  default:  
    fprintf( f,printFormat[ get_tag(a) ][fmt],get_val(a) );
  }
  return a;
}

// print pairs (1 2 3) or (1 . 2)
ATOM fprintp( FILE *f,ATOM p,char sep,char *lsep,int fmt ){
  ATOM t;                     // FIXME: could use p instead of t
LOOP:
  _print_flag( f,p );
  fprinta1( f,car(p),lsep,fmt );        // print (car p)
  _set_pmk( p,pmark );
  t = cdr(p);                 // get (cdr p)
  if ( is_null(t) ) return p;        // end of list so done
  if ( sep>0 ) fputc( sep,f );  // otherwise print separator
  if ( is_pair(t) ){  // handle special list elements ((l) env . (E))
    if ( is_eq( t,gEnv ) ){  // don't print global env if cdr of pair 
      _print_flag( f,t );
      fputs( "G",f ); 
      return p; 
    }  // global env
    if ( is_tenv(t) ){  // don't loop from a procedure's env pointer
      //fputc( '[',f );
      if ( _pmk(t)==pmark ){  //been here recently
        _print_flag( f,t );
        fputc( '@',f ); 
      }
      else
        fprintp( f,t,SP,"",fmt ); 
      //fputc( ']',f ); 
      return p; 
    }
    p = t;
    goto LOOP;                // tail-call printp(cdr[p.val], sep)
  }
  fputc( '.',f );              // dotted pair
  fputc( sep,f );
  fprinta1( f,t,lsep,fmt );             // print (cdr p)
  return p;
}

#endif
#endif

