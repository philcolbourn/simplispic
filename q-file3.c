
#ifndef __header
  #define _q_file3_c
#endif

#ifndef _q_file3_h
  #define _q_file3_h
  #define __header    

#ifdef __header
#include <stdio.h>
#include "q-file1.c"
#include "q-file2.c"
#include "q-file3.c"

void f3( char *m );

#endif

#if defined(_q_file3_c)

void f3( char *m ){
  printf( "f3: %s\n",m );
}

#if __main==3
int main(){
  f1( "3rd" );
  f2( "3rd" );
  f3( "3rd" );
}
#endif

#endif
#endif

