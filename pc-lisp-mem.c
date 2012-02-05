
#ifndef __header
  #define _pc_lisp_mem_c
#endif

#ifndef _pc_lisp_mem_h
  #define _pc_lisp_mem_h
  #define __header

#ifdef __header

// HEADER

#define SIZE     800000       // max size of cell storage
#define SYM_SIZE 10000       // max symbol list size
#define SYM_LEN  32          // max symbol length including NUL
#define STR_SIZE 10000       // max symbol list size
#define STR_LEN  65536       // max string for now including NUL


typedef union{ 
  struct{ unsigned int partag:3; int parval:29; };
  struct{ unsigned int memtag:3; int memval:29; };
  struct{ unsigned int baktag:3; int bakval:29; };
  struct{ unsigned int strtag:3; int strval:29; };
  struct{ unsigned int symtag:3; int symval:29; };
  struct{ unsigned int pfntag:8; int pfnval:24; };
  struct{ unsigned int chrtag:8; int chrval:24; };
  struct{ unsigned int contag:8; int conval:24; };
  struct{ unsigned int numtag:1; int numval:31; };
  int atm; 
} ATOM;


typedef unsigned char CHAR;

typedef struct{
  ATOM car;
  ATOM cdr;
  ATOM mem;
  ATOM bak;
  CHAR gcm;
  CHAR mrk;
  CHAR pmk; 
  int  ref;
} PAIR;

extern PAIR   pairs[SIZE];
extern ATOM   freePairs;
extern ATOM   usedPairs;
extern ATOM   lastUsedPair;


// Strings and Symbols
typedef struct{
  char *text;
  int len;
  int hash;
  int ref;
} STRING;

extern STRING strings[STR_SIZE];
extern int     freeStr;
void string_init();
ATOM sym_to_str( ATOM sym );
int get_str_len( ATOM str );
ATOM str_ref( ATOM str,ATOM num );

/*
typedef union{
  struct{ unsigned int strtag:3; unsigned int strlen:2; char str[3]; };
  int atm;
} SHORTSTR;
*/

enum TAGS {PAR=0, MEM=0, BAK=0, NUM=1, SYM=2, RE3=3, CHR=4, RE5=5, STR=6, RE7=7, CON=12, PFN=29};

/*
  (1)------0--(2)----0--(3)--0--> PAR/MEM/BAK (0)
     \           \         `-1--(4)--0--(5)--0--(6)--0--(7)--0--(8)--0--> CHR (4)
      \           \                +-1--(5)--0--(6)--0--(7)--0--(8)--0--> CON (12)
       \           \               +-0--(5)--1--(6)--0--(7)--0--(8)--0--> FIL (20)
        \           \              '-1--(5)--1--> ???
         \           -1--(3)--0--> SYM (2)
          \                 `-1--> STR (6)
           -1--> NUM (1)      
*/   

//#include "pc-lisp-read2.c"
#include "pc-lisp-misc.c"
#include "pc-lisp-test.c"

#undef MAKE_ATOM_ADT

#define MAKE_ATOM_ADT( type,enum )  \
  ATOM make_##type( int i );        \
  int get_##type( ATOM a );         \
  int is_##type( ATOM a );

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );
MAKE_ATOM_ADT( bak,BAK );

#define MAKE_CON( val )    ( (ATOM){.conval=(val), .contag=CON} )
#define MAKE_PAR( val )    ( (ATOM){.parval=(val), .partag=PAR} )
#define MAKE_CHR( val )    ( (ATOM){.chrval=(val), .chrtag=CHR} )
//#define MAKE_NUM( val )    ( (ATOM){.numval=(val), .numtag=NUM} )

//#define ERR          MAKE_CON( -99)     // error value

#define MEM0         MAKE_PAR( 0 )
#define NIL          MAKE_CON( -1 )     // NIL is an empty list - int=0
#define FAL          MAKE_CON( 0 )     // !=0
#define TRU          MAKE_CON( 1 )     // !=0

// ADTs

#define ASSERT_PAIR( par )                                       \
  EXITIF( ! is_par( par ),"ASSERT_PAIR! requires a pair",par );  \
  EXITIF( get_val( par )<0,"Negative pair index",par );          \
  EXITIF( is_null( par ),"Pair is NIL",par );                    \
  EXITIF( get_val( par )>=SIZE,"Pair index > SIZE",par );

#define PAIRS( p ) pairs[ get_par(p) ]

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )  \
  type _set_##name( ATOM par,type name );   \
  type _##name( ATOM par );

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );
MAKE_PAIR_SET_AND_GET( ATOM,mem );
MAKE_PAIR_SET_AND_GET( ATOM,bak );
MAKE_PAIR_SET_AND_GET( CHAR,gcm );
MAKE_PAIR_SET_AND_GET( CHAR,mrk );
MAKE_PAIR_SET_AND_GET( CHAR,pmk );
MAKE_PAIR_SET_AND_GET(  int,ref );


extern int  _freePairCount;
ATOM _free_unlink();
ATOM _free_append( ATOM p );

extern int  _usedPairCount;
extern int  _usedPairMaxCount;
ATOM _used_unlink( ATOM p );
ATOM _used_append( ATOM p );

ATOM _remove_next_free();
//static ATOM _remove_next_used( ATOM p );
//static ATOM _move_next_used_last( ATOM p );

// END HEADER

#endif

#if defined(_pc_lisp_mem_c)

// CODE

#undef MAKE_ATOM_ADT

#define MAKE_ATOM_ADT( type,enum )                         \
  ATOM make_##type( int i ) {                              \
    return (ATOM){ .type##val=i, .type##tag=enum };        \
  }                                                        \
  int get_##type( ATOM a ) { return a.type##val; }         \
  int is_##type( ATOM a ) { return a.type##tag == enum; }

MAKE_ATOM_ADT( num,NUM );
MAKE_ATOM_ADT( par,PAR );
MAKE_ATOM_ADT( chr,CHR );
MAKE_ATOM_ADT( con,CON );
MAKE_ATOM_ADT( sym,SYM );
MAKE_ATOM_ADT( str,STR );
MAKE_ATOM_ADT( pfn,PFN );
MAKE_ATOM_ADT( mem,MEM );
MAKE_ATOM_ADT( bak,BAK );

#undef MAKE_PAIR_SET_AND_GET

#define MAKE_PAIR_SET_AND_GET( type,name )        \
  type _set_##name( ATOM par,type name ){         \
    ASSERT_PAIR( par );                           \
    return PAIRS( par ).name = name;              \
  }                                               \
  type _##name( ATOM par ){  /* no null check */  \
    ASSERT_PAIR( par );                           \
    return PAIRS( par ).name;                     \
  }

MAKE_PAIR_SET_AND_GET( ATOM,car );
MAKE_PAIR_SET_AND_GET( ATOM,cdr );
MAKE_PAIR_SET_AND_GET( ATOM,mem );
MAKE_PAIR_SET_AND_GET( ATOM,bak );
MAKE_PAIR_SET_AND_GET( CHAR,gcm );
MAKE_PAIR_SET_AND_GET( CHAR,mrk );
MAKE_PAIR_SET_AND_GET( CHAR,pmk );
MAKE_PAIR_SET_AND_GET(  int,ref );

// pair storage

PAIR   pairs[SIZE];

ATOM   freePairs;
ATOM   usedPairs;
ATOM   lastUsedPair;

// type storage

STRING strings[STR_SIZE];

// free storage indexes - by convention reserve [0]

int    freeStr = 1;
//int    freeFun = 1;

void string_init(){
  int i;
  for ( i=0;i<STR_SIZE;i++ ){
    strings[i].text = "UNDEF STR";
    strings[i].len  = 9;
    strings[i].hash = 0;
    strings[i].ref  = 0;
    //sar[i].val      = 0;
  }
  strings[ 0 ].text = malloc( STR_LEN );
  strings[ 0 ].len  = 0;
  strings[ 0 ].ref  = 1; // never gc?
  EXITIF( strings[ 0 ].text==NULL,"malloc returned NULL!",NIL );
  strings[ freeStr ].len = 0;  // FIXME: why?
}

ATOM sym_to_str( ATOM sym ){
  return make_str( get_sym(sym) );
}

inline int get_str_len( ATOM str ){
  int s = get_str(str);
  if ( s<=0 ) return (-s) >> (3*8);
  return strings[ s ].len;

}

ATOM str_ref( ATOM str,ATOM ref ){
  PEEK( "",str );
  PEEK( "",ref );
  EXITIF( get_num(ref)<0,"Negative String ref",ref );
  EXITIF( get_num(ref)>=get_str_len(str),"String ref out of range",ref );
  int s = get_str(str);
  if ( s<=0 ){
    s = -s;
    return make_chr( ((char *)&s)[ get_num(ref) ] );
  }
  return make_chr( strings[ s ].text[ get_num(ref) ] );
}

/*
Fundemental memory management functions

freePairs starts at 1, singly linked using mem
usedPairs starts at 0, circular doubly linked
usedPairs is always NIL
???mem(usedPairs) points to newest pair
*/

int _freePairCount    = SIZE-1;

ATOM _free_unlink(){
  _freePairCount--;
  ATOM p = freePairs;             // next free pair 
  freePairs = _mem( p );          // unlink from free list
  //_set_mem( p,NIL );        // optional for now
  _set_mem( p,MEM0 );        // optional for now
  return p;
}

ATOM _free_append( ATOM p ){
  _freePairCount++;
  _set_mem( p,freePairs );
  freePairs = p;
  return p;
}

int _usedPairCount    = 1;      // [0] is always used as circular list ref

ATOM _used_unlink( ATOM p ){  // must be circular list
  _usedPairCount--;
  _set_mem( _bak(p),_mem(p) );  // remove from mem list
  _set_bak( _mem(p),_bak(p) );  // remove from bak list
  return p;
}

int _usedPairMaxCount = 0;

ATOM _used_append( ATOM p ){  // append p after usedPairs
  _usedPairCount++;
  if ( _usedPairCount > _usedPairMaxCount )  _usedPairMaxCount=_usedPairCount;
  _set_mem( p,_mem(usedPairs) );
  _set_bak( p,usedPairs );
  _set_mem( usedPairs,p );
  _set_bak( _mem(p),p );
  return p;
}

ATOM _remove_next_free(){
  ATOM p = _free_unlink();          // next free pair 
  //RETNIF( is_null( freePairs ),"All pairs are used!",freePairs );
  RETNIF( is_eq( freePairs,MEM0 ),"All pairs are used!",NIL );
  _used_append( p );
  return p;
}

/*
ATOM makeString(char *buf, int len){
  strings[ freeStr ] = malloc( len+1 );        // storage for string
  strcpy( strings[ freeStr ],buf );       // copy
  //fprintf( stderr,"readSTR=%s\n",strings[freeStr] );
  ATOM a = make_str( freeStr );           // new string
  //peek( "makeString=",a );
  freeStr++;  
  //_push(a);
  return a;
}
*/

#endif
#endif

