
#ifndef __header
  #define _q_file2_c
#endif

#ifndef _q_file2_h
  #define _q_file2_h
  #define __header    

#ifdef __header
#include <stdio.h>
#include "q-file1.c"
#include "q-file2.c"
#include "q-file3.c"

void f2( char *m );

#endif

#if defined(_q_file2_c)

void f2( char *m ){
  printf( "f2: %s\n",m );
}

#if __main==2
int main(){
  f1( "not main" );
  f2( "not main" );
  f3( "not main" );
}
#endif

#endif
#endif

