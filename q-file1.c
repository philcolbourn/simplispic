/*
Stand-alone compile

On entry: nothing is defined
_file_c is defined
_file_h is defined
__header is defined
File is processed as a header file
File is also processed as a code file
main will be compiled if __main has specified value

Header file mode - included from another file

On entry: __header is defined
_file_h is defined
File is processed as a header file

Multiple include mode - included from another file again

On entry: __header and _file_h are defined
File is skipped

*/

#ifndef __header         // must be compiling c file
  #define _q_file1_c     // compile code and not others that are included
#endif

#ifndef _q_file1_h       // only load once
  #define _q_file1_h     // dont reload this file
  #define __header       // tell included files we only want header parts

#ifdef __header          // normal header part

#include <stdio.h>
#include "q-file1.c"     // this file will skip itself
#include "q-file2.c"
#include "q-file3.c"

void f1( char *m );

#endif // __header

#if defined(_q_file1_c)  // compile this code

void f1( char *m ){
  printf( "f1: %s\n",m );
}

#if __main==1            // we want main for this one
int main(){
  f1( "main" );
  f2( "main" );
  f3( "main" );
}
#endif

#endif  // not processed as code
#endif  // skip file is loaded as a header before

