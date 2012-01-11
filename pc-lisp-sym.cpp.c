# 1 "pc-lisp-sym.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "pc-lisp-sym.c"

# 1 "pc-lisp.h" 1
# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 323 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/predefs.h" 1 3 4
# 324 "/usr/include/features.h" 2 3 4
# 356 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 353 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 354 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 357 "/usr/include/features.h" 2 3 4
# 388 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 5 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4




# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 389 "/usr/include/features.h" 2 3 4
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 212 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 131 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 132 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 37 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 203 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 416 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 490 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4




typedef __gnuc_va_list va_list;
# 91 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 103 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 161 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 162 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) __attribute__ ((__nothrow__));

extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));




extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));








extern FILE *tmpfile (void) ;
# 206 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 224 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 249 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 263 "/usr/include/stdio.h" 3 4






extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;




extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 292 "/usr/include/stdio.h" 3 4

# 303 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
# 316 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 414 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;




extern int scanf (__const char *__restrict __format, ...) ;

extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 445 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__))

                      ;
# 465 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 496 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 524 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 552 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 563 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 596 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;






extern char *gets (char *__s) ;

# 658 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 730 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 766 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 785 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 808 "/usr/include/stdio.h" 3 4

# 817 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;








extern void perror (__const char *__s);






# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 847 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 866 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 906 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 936 "/usr/include/stdio.h" 3 4

# 2 "pc-lisp.h" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 324 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 3 4
typedef int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 43 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 65 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 61 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 62 "/usr/include/endian.h" 2 3 4
# 66 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 2 3 4

union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 44 "/usr/include/stdlib.h" 2 3 4
# 68 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 96 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 140 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;




extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

# 311 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;


extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 61 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 99 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;
# 116 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 147 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 148 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 195 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 220 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 32 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 75 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 109 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 121 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);



# 221 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
# 224 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 271 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 50 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


typedef union
{
  char __size[56];
  long int __align;
} pthread_attr_t;



typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
# 76 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    int __spins;
    __pthread_list_t __list;
# 101 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long int __pad1;
    unsigned long int __pad2;


    unsigned int __flags;
  } __data;
# 187 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 272 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 321 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));







extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__));



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__));






# 498 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 531 "/usr/include/stdlib.h" 3 4





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
# 554 "/usr/include/stdlib.h" 3 4






extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));






extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__));
# 606 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 620 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 642 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 663 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 712 "/usr/include/stdlib.h" 3 4





extern int system (__const char *__command) ;

# 734 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);
# 752 "/usr/include/stdlib.h" 3 4



extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 771 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

# 808 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));







extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));

extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));








extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 896 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *__const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 948 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 964 "/usr/include/stdlib.h" 3 4

# 3 "pc-lisp.h" 2
# 1 "/usr/include/string.h" 1 3 4
# 29 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/4.6.1/include/stddef.h" 1 3 4
# 35 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 95 "/usr/include/string.h" 3 4
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 126 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));






# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 163 "/usr/include/string.h" 2 3 4


extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));





extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 210 "/usr/include/string.h" 3 4

# 235 "/usr/include/string.h" 3 4
extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 262 "/usr/include/string.h" 3 4
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 281 "/usr/include/string.h" 3 4



extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 314 "/usr/include/string.h" 3 4
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 342 "/usr/include/string.h" 3 4
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 397 "/usr/include/string.h" 3 4


extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

# 427 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__))

                        __attribute__ ((__nonnull__ (2)));
# 445 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 489 "/usr/include/string.h" 3 4
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 517 "/usr/include/string.h" 3 4
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 536 "/usr/include/string.h" 3 4
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 559 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__));


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
# 646 "/usr/include/string.h" 3 4

# 4 "pc-lisp.h" 2
# 26 "pc-lisp.h"
typedef union{
  struct{ unsigned int partag:3; int parval:29; };
  struct{ unsigned int memtag:3; int memval:29; };
  struct{ unsigned int strtag:3; int strval:29; };
  struct{ unsigned int symtag:3; int symval:29; };
  struct{ unsigned int pfntag:8; int pfnval:24; };
  struct{ unsigned int chrtag:8; int chrval:24; };
  struct{ unsigned int contag:8; int conval:24; };
  struct{ unsigned int numtag:1; int numval:31; };
  int atm;
} ATOM;






typedef union{
  struct{
    unsigned int gc:2;
    unsigned int mark:10;
  };
  int val;
} FLAGS;

typedef unsigned char CHAR;

typedef struct{
  ATOM car;
  ATOM cdr;
  ATOM mem;
  CHAR gcm;
  CHAR mrk;
  CHAR pmk;
} PAIR;

extern PAIR pairs[30000];
extern ATOM freePairs;
extern ATOM usedPairs;
extern ATOM freePair;
extern ATOM usedPair;

extern FLAGS sar[30000];


typedef struct{
  char name[32];
} SYMBOL;
extern SYMBOL symbols[30000];
extern int freeSym;


extern char *strings[30000];
extern int freeStr;


extern ATOM (*primFns[30000])();
extern int freeFun;

enum TAGS {PAR=0, MEM=0, NUM=1, SYM=2, RE3=3, CHR=4, RE5=5, STR=6, RE7=7, CON=12, PFN=29};
# 100 "pc-lisp.h"
int get_tag( ATOM a );
int get_val( ATOM a );
# 119 "pc-lisp.h"
static inline ATOM make_num( int i ) { return (ATOM){ .numval=i, .numtag=NUM }; } static inline int get_num( ATOM a ) { return a.numval; } static inline int is_num( ATOM a ) { return a.numtag == NUM; };
static inline ATOM make_par( int i ) { return (ATOM){ .parval=i, .partag=PAR }; } static inline int get_par( ATOM a ) { return a.parval; } static inline int is_par( ATOM a ) { return a.partag == PAR; };
static inline ATOM make_chr( int i ) { return (ATOM){ .chrval=i, .chrtag=CHR }; } static inline int get_chr( ATOM a ) { return a.chrval; } static inline int is_chr( ATOM a ) { return a.chrtag == CHR; };
static inline ATOM make_con( int i ) { return (ATOM){ .conval=i, .contag=CON }; } static inline int get_con( ATOM a ) { return a.conval; } static inline int is_con( ATOM a ) { return a.contag == CON; };
static inline ATOM make_sym( int i ) { return (ATOM){ .symval=i, .symtag=SYM }; } static inline int get_sym( ATOM a ) { return a.symval; } static inline int is_sym( ATOM a ) { return a.symtag == SYM; };
static inline ATOM make_str( int i ) { return (ATOM){ .strval=i, .strtag=STR }; } static inline int get_str( ATOM a ) { return a.strval; } static inline int is_str( ATOM a ) { return a.strtag == STR; };
static inline ATOM make_pfn( int i ) { return (ATOM){ .pfnval=i, .pfntag=PFN }; } static inline int get_pfn( ATOM a ) { return a.pfnval; } static inline int is_pfn( ATOM a ) { return a.pfntag == PFN; };
static inline ATOM make_mem( int i ) { return (ATOM){ .memval=i, .memtag=MEM }; } static inline int get_mem( ATOM a ) { return a.memval; } static inline int is_mem( ATOM a ) { return a.memtag == MEM; };
# 271 "pc-lisp.h"
extern ATOM gEnv;

extern int line;
extern int pos;
extern char buf[((1<<8)-1)+1];
extern int nextc;
extern int next2c;
extern char *reads;
extern char *readp;

typedef char *STRING;
extern ATOM _global_save;

extern ATOM kw_quote, kw_lambda, kw_closure;
extern ATOM kw_let, kw_let_star, kw_letrec;
extern ATOM kw_primitive, kw_exit;
extern ATOM kw_define, kw_set;
extern ATOM kw_read, kw_load, kw_eval, kw_eval1, kw_apply;
extern ATOM kw_if, kw_cond;
extern ATOM kw_progn, kw_begin, kw_delay ,kw_force;
extern ATOM kw_display, kw_print;
extern ATOM kw_cons, kw_list, kw_cons_stream;

extern ATOM tag_env;


void boot();

ATOM make_kvp( ATOM key,ATOM val );
int is_kvp ( ATOM kvp );
ATOM kvp_key ( ATOM kvp );
ATOM kvp_val ( ATOM kvp );

ATOM make_taglist ( ATOM tag,ATOM lst );
int is_taglist ( ATOM lst );
int match_taglist( ATOM lst,ATOM tag );
ATOM taglist_list ( ATOM tl );
ATOM taglist_tag ( ATOM tl );

ATOM make_tenv( ATOM env );
int is_tenv ( ATOM tenv );
ATOM tenv_env ( ATOM tenv );

ATOM make_lambda( ATOM form,ATOM body );
int is_lambda ( ATOM lamb );
ATOM lambda_form( ATOM lamb );
ATOM lambda_body( ATOM lamb );

ATOM make_proc ( ATOM lamb,ATOM env );
int is_proc ( ATOM proc );
ATOM proc_lambda( ATOM proc );
ATOM proc_env ( ATOM proc );

ATOM make_primitive( ATOM form,ATOM cfun );
int is_primitive ( ATOM prim );
ATOM primitive_form( ATOM prim );
ATOM primitive_cfun( ATOM prim );

ATOM make_alist ( ATOM keys,ATOM vals );
ATOM extend_alist( ATOM kvp,ATOM alst );
int is_alist ( ATOM alst );
ATOM alist_assoc ( ATOM key,ATOM alst );
ATOM alist_find ( ATOM key,ATOM alst );
ATOM alist_keys ( ATOM alst );
ATOM alist_vals ( ATOM alst );
ATOM alist_car_vals ( ATOM alst );


void peek( char *m,ATOM a );
void peekPair( char *m,ATOM p );


enum {DUMP=0, PRINT=1, DISPLAY=2};

extern STRING printFormat[][3];
extern int pmark;

void fprinta ( FILE *f,ATOM a );
void fprinta1( FILE *f,ATOM a,char *lsep,int fmt );
void fprintp ( FILE *f,ATOM p,char sep,char *lsep,int fmt );


ATOM printa ( ATOM a );
ATOM display ( ATOM a );
void printp ( ATOM p,char sep );
ATOM printerr( ATOM a );

ATOM consFatal ( ATOM a,ATOM b );
ATOM consNormal( ATOM a,ATOM b );
ATOM (*cons)( ATOM a,ATOM b );
# 385 "pc-lisp.h"
ATOM _recycle_next( ATOM sp,int force );
void _gc( ATOM p,ATOM a );
void _mark( ATOM a );

int (*readch)();
int readchNormal();
int readchString();
int getch();
void (*ungetch)( int c );
void ungetchNormal( int c );
void ungetchString( int c );
int getSYMch();
int getSTRch();
int getNUMch();
int getCOMch();

ATOM readLST ();
ATOM readNUM ( int m,int c );
ATOM readSYMorNUM( int c );
ATOM readSYM ();

ATOM readSTR ();
ATOM readCOM ();
ATOM read ();
ATOM read_token ();
ATOM readQUOTE ();
ATOM readCON ();



int equal ( ATOM a,ATOM b );
int is_pair ( ATOM p );
int is_atom ( ATOM a );
int is_list ( ATOM l );
int is_symbol( ATOM s );
int is_null ( ATOM a );
int is_eq ( ATOM a,ATOM b );
int not ( int a );



ATOM pair ( ATOM key,ATOM val );
ATOM assoc( ATOM sym,ATOM env );
ATOM eval ( ATOM exp,ATOM env );
ATOM apply( ATOM exp,ATOM env );
ATOM exita( ATOM val );


ATOM repl();
ATOM readString( char *s );
void _strcpy( char *d,char *s,int n );
# 478 "pc-lisp.h"
static inline ATOM _car( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",478 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].car; } static inline ATOM car( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",478 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",478 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].car; };
static inline ATOM _cdr( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",479 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].cdr; } static inline ATOM cdr( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",479 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",479 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].cdr; };
static inline ATOM _mem( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",480 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].mem; } static inline ATOM mem( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",480 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",480 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mem; };
static inline CHAR _gcm( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",481 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].gcm; } static inline CHAR gcm( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",481 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",481 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].gcm; };
static inline CHAR _mrk( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",482 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].mrk; } static inline CHAR mrk( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",482 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",482 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mrk; };
static inline CHAR _pmk( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",483 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; return pairs[ get_par( par ) ].pmk; } static inline CHAR pmk( ATOM par ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",483 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",483 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].pmk; };

static inline ATOM _set_car( ATOM par,ATOM car ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",485 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",485 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].car = car; } static inline ATOM set_car( ATOM par,ATOM car ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",485 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",485 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",485 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].car = car; };
static inline ATOM _set_cdr( ATOM par,ATOM cdr ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",486 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",486 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].cdr = cdr; } static inline ATOM set_cdr( ATOM par,ATOM cdr ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",486 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",486 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",486 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].cdr = cdr; };
static inline ATOM _set_mem( ATOM par,ATOM mem ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",487 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",487 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mem = mem; } static inline ATOM set_mem( ATOM par,ATOM mem ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",487 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",487 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",487 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mem = mem; };
static inline CHAR _set_gcm( ATOM par,CHAR gcm ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",488 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",488 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].gcm = gcm; } static inline CHAR set_gcm( ATOM par,CHAR gcm ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",488 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",488 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",488 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].gcm = gcm; };
static inline CHAR _set_mrk( ATOM par,CHAR mrk ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",489 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",489 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mrk = mrk; } static inline CHAR set_mrk( ATOM par,CHAR mrk ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",489 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",489 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",489 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].mrk = mrk; };
static inline CHAR _set_pmk( ATOM par,CHAR pmk ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",490 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",490 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].pmk = pmk; } static inline CHAR set_pmk( ATOM par,CHAR pmk ){ { if ( ! is_par( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",490 ); fprintf( stderr,"EXITIF: " "! is_par( par )" "\n" ); fprintf( stderr,"requires a pair" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } };; { if ( is_null( par ) ){ fprintf( stderr,"%s line %d ","pc-lisp.h",490 ); fprintf( stderr,"EXITIF: " "is_null( par )" "\n" ); fprintf( stderr,"par is NIL" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; { if ( get_val(par)<0 || get_val(par)>=30000 ){ fprintf( stderr,"%s line %d ","pc-lisp.h",490 ); fprintf( stderr,"EXITIF: " "get_val(par)<0 || get_val(par)>=SIZE" "\n" ); fprintf( stderr,"Illegal pair index" " in c-function %s().\n",__func__ ); peek( "par",(par) ); exit(1); } }; return pairs[ get_par( par ) ].pmk = pmk; };
# 3 "pc-lisp-sym.c" 2

ATOM kw_quote, kw_lambda, kw_closure, kw_let, kw_let_star, kw_letrec;
ATOM kw_primitive, kw_exit;
ATOM kw_define, kw_set;
ATOM kw_read, kw_load, kw_eval, kw_eval1, kw_apply, kw_if, kw_cond;
ATOM kw_progn, kw_begin, kw_delay ,kw_force;
ATOM kw_display, kw_print;
ATOM kw_cons, kw_list, kw_cons_stream;

ATOM tag_env;
# 35 "pc-lisp-sym.c"
PAIR pairs[30000];
FLAGS sar[30000];
ATOM freePairs;
ATOM usedPairs;


SYMBOL symbols[30000];
char *strings[30000];
ATOM (*primFns[30000])();


int freeSym = 1;
int freeStr = 1;
int freeFun = 1;

ATOM gEnv=( (ATOM){.parval=(0), .partag=PAR} );


int get_tag(ATOM a){
  if ( is_num(a) ) return NUM;
  if ( is_par(a) ) return PAR;
  if ( is_sym(a) ) return SYM;
  if ( is_str(a) ) return STR;
  if ( is_chr(a) ) return CHR;
  if ( is_con(a) ) return CON;
  if ( is_pfn(a) ) return PFN;
  return -1;
}
int get_val(ATOM a){
  if ( is_num(a) ) return a.numval;
  if ( is_par(a) ) return a.parval;
  if ( is_sym(a) ) return a.symval;
  if ( is_str(a) ) return a.strval;
  if ( is_chr(a) ) return a.chrval;
  if ( is_con(a) ) return a.conval;
  if ( is_pfn(a) ) return a.pfnval;
  return 0;
}

ATOM _bad_primative_fn(){
  fprintf( stderr, "ERROR: Undefined primitive function.\n" );
  exit(1);
}


# 1 "pc-lisp-primitives.c" 1
# 10 "pc-lisp-primitives.c"
ATOM prim_read( ATOM args,ATOM env ){ ATOM res = read(); return res; };
# 21 "pc-lisp-primitives.c"
ATOM prim_car( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = car( a ); return res; };
ATOM prim_cdr( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = cdr( a ); return res; };
ATOM prim_display( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = display( a ); return res; };
ATOM prim_printa( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = printa( a ); return res; };
ATOM prim_printerr( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = printerr( a ); return res; };


ATOM prim_exita( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = exita( a ); return res; };
# 78 "pc-lisp-primitives.c"
ATOM prim_cons( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = cons( a,b ); return res; };
ATOM prim_eval( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = eval( a,b ); return res; };
ATOM prim_set_car( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = set_car( a,b ); return res; };
ATOM prim_set_cdr( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = set_cdr( a,b ); return res; };
# 94 "pc-lisp-primitives.c"
ATOM iadd( ATOM a,ATOM b ); ATOM inline iadd( ATOM a,ATOM b ){ return make_num( get_num(a) + get_num(b) ); } ATOM prim_iadd( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = iadd( a,b ); return res; };
ATOM isub( ATOM a,ATOM b ); ATOM inline isub( ATOM a,ATOM b ){ return make_num( get_num(a) - get_num(b) ); } ATOM prim_isub( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = isub( a,b ); return res; };
ATOM imul( ATOM a,ATOM b ); ATOM inline imul( ATOM a,ATOM b ){ return make_num( get_num(a) * get_num(b) ); } ATOM prim_imul( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = imul( a,b ); return res; };
ATOM idiv( ATOM a,ATOM b ); ATOM inline idiv( ATOM a,ATOM b ){ return make_num( get_num(a) / get_num(b) ); } ATOM prim_idiv( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = idiv( a,b ); return res; };
ATOM imod( ATOM a,ATOM b ); ATOM inline imod( ATOM a,ATOM b ){ return make_num( get_num(a) % get_num(b) ); } ATOM prim_imod( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = imod( a,b ); return res; };
ATOM ishl( ATOM a,ATOM b ); ATOM inline ishl( ATOM a,ATOM b ){ return make_num( get_num(a) << get_num(b) ); } ATOM prim_ishl( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = ishl( a,b ); return res; };
ATOM ishr( ATOM a,ATOM b ); ATOM inline ishr( ATOM a,ATOM b ){ return make_num( get_num(a) >> get_num(b) ); } ATOM prim_ishr( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = ishr( a,b ); return res; };
# 109 "pc-lisp-primitives.c"
ATOM ilt( ATOM a,ATOM b ); ATOM inline ilt( ATOM a,ATOM b ){ return ( (get_num(a) < get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_ilt( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = ilt( a,b ); return res; };
ATOM igt( ATOM a,ATOM b ); ATOM inline igt( ATOM a,ATOM b ){ return ( (get_num(a) > get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_igt( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = igt( a,b ); return res; };
ATOM ilte( ATOM a,ATOM b ); ATOM inline ilte( ATOM a,ATOM b ){ return ( (get_num(a) <= get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_ilte( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = ilte( a,b ); return res; };
ATOM igte( ATOM a,ATOM b ); ATOM inline igte( ATOM a,ATOM b ){ return ( (get_num(a) >= get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_igte( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = igte( a,b ); return res; };
ATOM ieq( ATOM a,ATOM b ); ATOM inline ieq( ATOM a,ATOM b ){ return ( (get_num(a) == get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_ieq( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = ieq( a,b ); return res; };
ATOM and( ATOM a,ATOM b ); ATOM inline and( ATOM a,ATOM b ){ return ( (get_num(a) && get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_and( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = and( a,b ); return res; };
ATOM or( ATOM a,ATOM b ); ATOM inline or( ATOM a,ATOM b ){ return ( (get_num(a) || get_num(b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_or( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = or( a,b ); return res; };
# 124 "pc-lisp-primitives.c"
ATOM atomp( ATOM a ); inline ATOM atomp( ATOM a ){ return ( (is_atom(a)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_atomp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = atomp( a ); return res; };
ATOM listp( ATOM a ); inline ATOM listp( ATOM a ){ return ( (is_list(a)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_listp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = listp( a ); return res; };
ATOM pairp( ATOM a ); inline ATOM pairp( ATOM a ){ return ( (is_pair(a)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_pairp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = pairp( a ); return res; };
ATOM nullp( ATOM a ); inline ATOM nullp( ATOM a ){ return ( (is_null(a)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_nullp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = nullp( a ); return res; };
ATOM procp( ATOM a ); inline ATOM procp( ATOM a ){ return ( (is_proc(a)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_procp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM res = procp( a ); return res; };
# 138 "pc-lisp-primitives.c"
ATOM eqp( ATOM a,ATOM b ); inline ATOM eqp( ATOM a,ATOM b ){ return ( (is_eq(a,b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_eqp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = eqp( a,b ); return res; };
ATOM equalp( ATOM a,ATOM b ); inline ATOM equalp( ATOM a,ATOM b ){ return ( (equal(a,b)) ? (( (ATOM){.conval=(1), .contag=CON} )) : (( (ATOM){.parval=(0), .partag=PAR} )) ); } ATOM prim_equalp( ATOM args,ATOM env ){ ATOM a = car( args ); ATOM b = car( cdr( args ) ); ATOM res = equalp( a,b ); return res; };
# 81 "pc-lisp-sym.c" 2
# 118 "pc-lisp-sym.c"
void boot(){
  int i;
  fputs( "Booting...\n",stderr );
  freePairs = make_par(1);
  usedPairs = make_par(0);
  for (i=0; i<30000; i++){
    ATOM p = make_par(i);
    _set_mem( p,make_mem( (i+1)%30000 ) );

      _set_car( p,( (ATOM){.conval=(-9), .contag=CON} ) );
      _set_cdr( p,( (ATOM){.conval=(-9), .contag=CON} ) );
      _set_gcm( p,0 );
      _set_mrk( p,0 );

    symbols[i].name[0] = 0;
    _strcpy( symbols[i].name,"UNDEF SYM",10 );
    strings[i] = "UNDEF STR";
    primFns[i] = _bad_primative_fn;
    sar[i].val = 0;
  }
  _set_car( usedPairs,readString( "\"*used pairs*\"" ) );
  _set_mem( usedPairs,( (ATOM){.parval=(0), .partag=PAR} ) );
# 161 "pc-lisp-sym.c"
  fputs( "Create global environment...\n",stderr );
  MARK3;
  gEnv = cons( ( (ATOM){.parval=(0), .partag=PAR} ),( (ATOM){.parval=(0), .partag=PAR} ) );

  fputs( "Create keyword symbols...\n",stderr );
  kw_quote = readString( "quote" );
  kw_lambda = readString( "lambda" );
  kw_closure = readString( "closure" );
  kw_let = readString( "let" );
  kw_let_star = readString( "let*" );
  kw_letrec = readString( "letrec" );
  kw_primitive = readString( "primitive" );
  kw_define = readString( "define" );
  kw_set = readString( "set!" );
  kw_read = readString( "read" );
  kw_load = readString( "load" );
  kw_exit = readString( "exit" );
  kw_eval = readString( "eval" );
  kw_eval1 = readString( "eval1" );
  kw_apply = readString( "apply" );
  kw_if = readString( "if" );
  kw_cond = readString( "cond" );
  kw_delay = readString( "delay" );
  kw_progn = readString( "progn" );
  kw_begin = readString( "begin" );
  kw_cons = readString( "cons" );
  kw_cons_stream = readString( "cons-stream" );
  kw_list = readString( "list" );

  tag_env = readString( "env" );

  fputs( "Create primitive procedures...\n",stderr );
  { MARK3; primFns[1] = prim_car; ATOM prim = eval( readString("(define " "car" " (primitive (a) " "1" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[2] = prim_cdr; ATOM prim = eval( readString("(define " "cdr" " (primitive (a) " "2" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[3] = prim_cons; ATOM prim = eval( readString( "(define " "cons" " (primitive (a b) " "3" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[4] = prim_iadd; ATOM prim = eval( readString( "(define " "iadd" " (primitive (a b) " "4" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[5] = prim_isub; ATOM prim = eval( readString( "(define " "isub" " (primitive (a b) " "5" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[6] = prim_imul; ATOM prim = eval( readString( "(define " "imul" " (primitive (a b) " "6" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[7] = prim_idiv; ATOM prim = eval( readString( "(define " "idiv" " (primitive (a b) " "7" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[8] = prim_eqp; ATOM prim = eval( readString( "(define " "eqp" " (primitive (a b) " "8" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[9] = prim_equalp; ATOM prim = eval( readString( "(define " "equalp" " (primitive (a b) " "9" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[10] = prim_pairp; ATOM prim = eval( readString("(define " "pairp" " (primitive (a) " "10" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[11] = prim_listp; ATOM prim = eval( readString("(define " "listp" " (primitive (a) " "11" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[12] = prim_ilt; ATOM prim = eval( readString( "(define " "ilt" " (primitive (a b) " "12" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[13] = prim_igt; ATOM prim = eval( readString( "(define " "igt" " (primitive (a b) " "13" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[14] = prim_ilte; ATOM prim = eval( readString( "(define " "ilte" " (primitive (a b) " "14" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[15] = prim_igte; ATOM prim = eval( readString( "(define " "igte" " (primitive (a b) " "15" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[16] = prim_ieq; ATOM prim = eval( readString( "(define " "ieq" " (primitive (a b) " "16" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[17] = prim_atomp; ATOM prim = eval( readString("(define " "atomp" " (primitive (a) " "17" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[18] = prim_and; ATOM prim = eval( readString( "(define " "and" " (primitive (a b) " "18" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[19] = prim_or; ATOM prim = eval( readString( "(define " "or" " (primitive (a b) " "19" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[20] = prim_eval; ATOM prim = eval( readString( "(define " "eval" " (primitive (a b) " "20" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };

  { MARK3; primFns[22] = prim_read; ATOM prim = eval( readString("(define " "read" " (primitive () " "22" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[23] = prim_display; ATOM prim = eval( readString("(define " "display" " (primitive (a) " "23" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[24] = prim_printa; ATOM prim = eval( readString("(define " "printa" " (primitive (a) " "24" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[25] = prim_nullp; ATOM prim = eval( readString("(define " "nullp" " (primitive (a) " "25" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[26] = prim_imod; ATOM prim = eval( readString( "(define " "imod" " (primitive (a b) " "26" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[27] = prim_ishl; ATOM prim = eval( readString( "(define " "ishl" " (primitive (a b) " "27" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[28] = prim_ishr; ATOM prim = eval( readString( "(define " "ishr" " (primitive (a b) " "28" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };


  { MARK3; primFns[31] = prim_procp; ATOM prim = eval( readString("(define " "procp" " (primitive (a) " "31" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[32] = prim_set_car; ATOM prim = eval( readString( "(define " "set_car" " (primitive (a b) " "32" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3 ; primFns[33] = prim_set_cdr; ATOM prim = eval( readString( "(define " "set_cdr" " (primitive (a b) " "33" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };

  { MARK3; primFns[34] = prim_printerr; ATOM prim = eval( readString("(define " "printerr" " (primitive (a) " "34" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };
  { MARK3; primFns[35] = prim_exita; ATOM prim = eval( readString("(define " "exita" " (primitive (a) " "35" "))"), gEnv ); ; KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) ); };

  fputs( "Booted.\n",stderr );
  KEEP3(gEnv);

  _check_mem();

  _check_mem_leak();
  fputs( "Booted and memory checked.\n",stderr );
}


STRING printFormat[][3]={
  [PAR] = { "%d@  " , "%d@" , "%d@" },
  [NUM] = { "%d  " , "%d" , "%d" },
  [RE3] = { "%d  " , "%d" , "%d" },
  [RE5] = { "%d  " , "%d" , "%d" },
  [RE7] = { "%d  " , "%d" , "%d" },
  [SYM] = { "%s$  " , "%s" , "%s" },
  [CHR] = { "%c  " , "%c" , "%c" },
  [CON] = { "%d  " , "%d" , "%d" },
  [STR] = { "\"%s\"  ", "\"%s\"", "%s" },
  [PFN] = { "%x  " , "%x" , "%x" }
};

ATOM exita( ATOM val ){
  exit( get_val(val) );
  return ( (ATOM){.parval=(0), .partag=PAR} );
}

# 1 "pc-lisp-read2.c" 1
# 18 "pc-lisp-read2.c"
int line = 1;
int pos = 0;
char buf[((1<<8)-1)+1] = "";
int nextc = 0;
int next2c = 0;
char *reads = ((void *)0);
char *readp = ((void *)0);

int (*readch)() = readchNormal;
void (*ungetch)( int c ) = ungetchNormal;
FILE *in;

int readchNormal(){
  int c;
  c = nextc;
  if ( c==0 ){
    c = fgetc( in );
    if ( c==(-1) ) return c;
    if ( c==( '\n' ) ) { line++; pos=0; return c; }
  }
  else{
    nextc = next2c;
    next2c = 0;
  }
  pos++;

  return c;
}

int readchString(){
  int c = *readp;
  if ( c==0 ) return (-1);
  readp++;

  return c;
}



void ungetchNormal( int c ){
  { if ( next2c!=0 ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",58 ); fprintf( stderr,"EXITIF: " "next2c!=0" "\n" ); fprintf( stderr,"Can't ungetch more than 2 characters" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  next2c = nextc;
  nextc = c;
}

void ungetchString( int c ){
  { if ( readp==reads ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",64 ); fprintf( stderr,"EXITIF: " "readp==reads" "\n" ); fprintf( stderr,"Can't ungetch - have not read anything" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  if ( c==(-1) ) return;
  readp--;
}

int getch(){
  int c;
  while ( ( c=readch() ) ){

    if ( c>=( ' ' ) || c==( '\n' ) || c==( '\t' ) || c==(-1) ) return c;
  }
  { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",75 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"NUL not expected" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  return ( '\0' );
}

int getSYMch(){
  int c = readch();
  if ( c==( '\\' ) ){
    c = readch();
    if ( c=='n' ) return ( '\n' );
    if ( c=='t' ) return ( '\t' );
    if ( c>=( ' ' ) ) return c;
    if ( c==(-1) ) return c;
    { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",87 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Illegal escaped char following '\\'" " in c-function %s().\n",__func__ ); peek( "make_chr(c)",(make_chr(c)) ); exit(1); } };
  }
  if ( c>')' ) return c;
  if ( c>( ' ' ) && c<'(' ) return c;
  if ( c==(-1) ) return c;
  return -c;
}

int getSTRch(){
  int c = readch();
  if ( c==( '\\' ) ){
    c = readch();
    if ( c=='n' ) return ( '\n' );
    if ( c=='t' ) return ( '\t' );
    if ( c>=( ' ' ) ) return c;
    if ( c==(-1) ) return c;
    { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",103 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Illegal escaped char following '\\'" " in c-function %s().\n",__func__ ); peek( "make_chr(c)",(make_chr(c)) ); exit(1); } };
  }
  if ( c>( '"' ) ) return c;
  if ( c>0 && c<( '"' ) ) return c;
  if ( c==(-1) ) return c;
  return -c;
}

int getNUMch(){
  int c = readch();
  if ( c>='0' && c<='9' ) return c;
  if ( c==(-1) ) return c;
  return -c;
}

enum {POS=1, NEG=-1};

ATOM read_token(){
  int c;
  SKIP:
  c = getch();

  if ( c==(-1) ) return make_chr((-1));
  if ( c=='(' ) return make_chr(c);
  if ( c<=( ' ' ) ) goto SKIP;
  if ( c==')' ) return make_chr(c);
  if ( c=='@' ) return readCON();
  if ( c>='0' && c<='9' ) return readNUM(POS,c);
  if ( c=='-' || c=='+' ) return readSYMorNUM(c);
  if ( c==( '.' ) ){
    int c2 = getSYMch();
    if ( c2<=( ' ' ) ) return make_chr(( '.' ));
    ungetch(c2);
    ungetch(c);
    return readSYM();
  }
  if ( c==( '"' ) ) return readSTR();
  if ( c==( ';' ) ){
    c = getCOMch();
    if ( c==( '.' ) ) return make_chr((-1));
    readCOM();
    goto SKIP;
  }
  if ( c==( '\'' ) ) return make_chr(( '\'' ));
  ungetch(c);
  return readSYM();
}
# 161 "pc-lisp-read2.c"
ATOM eval_macros( ATOM exp );

ATOM let_star_to_let( ATOM kvps,ATOM body ){
  if ( is_null(kvps) ) return body;
  ATOM exp = let_star_to_let( cdr(kvps),body );
  ATOM kvp = cons( car(kvps),( (ATOM){.parval=(0), .partag=PAR} ) );
  ATOM let = cons( kw_let,cons( kvp,exp ) );
  { { fprintf( stderr,"%s line %d ","pc-lisp-read2.c",168 ); fprintf( stderr,"%s(): ",__func__ ); peek( "" " " "let",(let) ); } };
  ATOM res = eval_macros( let );
  { { fprintf( stderr,"%s line %d ","pc-lisp-read2.c",170 ); fprintf( stderr,"%s(): ",__func__ ); peek( "" " " "res",(res) ); } };
  return res;
}

ATOM eval_macros( ATOM exp ){

  if ( match_taglist( exp,kw_define ) ){
    if ( is_list( car( cdr( exp ) ) ) ){
      { { fprintf( stderr,"%s line %d ","pc-lisp-read2.c",178 ); fprintf( stderr,"%s(): ",__func__ ); peek( "found define" " " "exp",(exp) ); } };
      ATOM name = car( car( cdr( exp ) ) );
      ATOM form = cdr( car( cdr( exp ) ) );

      ATOM body = cdr( cdr( exp ) );
      ATOM lamb = make_lambda( form,body );

      ATOM defn = cons( kw_define, cons( name,cons( lamb,( (ATOM){.parval=(0), .partag=PAR} )) ) );

      return defn;
    }

  }

  if ( match_taglist( exp,kw_let ) ){

      { { fprintf( stderr,"%s line %d ","pc-lisp-read2.c",194 ); fprintf( stderr,"%s(): ",__func__ ); peek( "found let" " " "exp",(exp) ); } };
      ATOM form = alist_keys( car( cdr( exp ) ) );



      ATOM args = alist_car_vals( car( cdr( exp ) ) );


      ATOM body = cdr( cdr( exp ) );

      ATOM lamb = make_lambda( form,body );

      ATOM lexp = cons( lamb,args );

      return lexp;


  }



  if ( match_taglist( exp,kw_let_star ) ){

      { { fprintf( stderr,"%s line %d ","pc-lisp-read2.c",217 ); fprintf( stderr,"%s(): ",__func__ ); peek( "found let*" " " "exp",(exp) ); } };
      ATOM kvps = car( cdr( exp ) );
      ATOM body = cdr( cdr( exp ) );
      ATOM res = let_star_to_let( kvps,body );
      return res;


  }

  if ( match_taglist( exp,kw_cons_stream ) ){
    ;
    ATOM body = cdr( cdr( exp ) );
    ATOM dely = cons( kw_delay,body );
    ATOM args = cons( car( cdr( exp ) ),cons( dely,( (ATOM){.parval=(0), .partag=PAR} )) );
    ATOM res = cons( kw_cons,args );
    return res;
  }

  if ( match_taglist( exp,kw_begin ) ){
    ;
    ATOM body = cdr(exp);
    ATOM res = cons( kw_progn,body );
    return res;
  }





  return exp;
}

ATOM read(){
  ATOM t = read_token();

  if ( is_eq( t,make_chr((-1)) ) ) return t;
  if ( is_sym(t) ) return t;
  if ( is_num(t) ) return t;
  if ( is_str(t) ) return t;
  if ( is_eq( t,make_chr(( '\'' )) ) ) return readQUOTE();
  if ( is_eq( t,make_chr('(') ) ) return eval_macros( readLST() );
  if ( is_eq( t,make_chr(')') ) ) return t;
  if ( is_eq( t,make_chr(( '.' )) ) ) return t;
  if ( is_chr(t) ) return t;
  if ( is_con(t) ) return t;
  { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",262 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"What is that?" " in c-function %s().\n",__func__ ); peek( "t",(t) ); exit(1); } };
  return ( (ATOM){.parval=(0), .partag=PAR} );
}


ATOM reuse_sym(){
  int i;
  for ( i=1 ; i<freeSym ; i++ ){
    if ( strcmp( symbols[i].name,symbols[freeSym].name )==0 ){
      ATOM a = make_sym( i );
      return a;
    }
  }
  ATOM a = make_sym( freeSym );
  freeSym++;
  return a;
}


ATOM readSYM(){
  int i=0, c, l;
  while ( c=getSYMch() , c>0 ){
    symbols[freeSym].name[i++] = c;
    { if ( i==(32 -1) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",285 ); fprintf( stderr,"EXITIF: " "i==(SYM_LEN-1)" "\n" ); fprintf( stderr,"Symbol too long" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
    l = c;
  }
  symbols[freeSym].name[i] = (char) 0;
  if ( c!=(-1) ) ungetch(-c);
  if ( i==1 ){
    return make_sym(-l);
  }

  return reuse_sym();
}



ATOM readSYMorNUM(int sign){
  int c=getNUMch();
  if ( c<=0 ){
    if ( c!=(-1) ) ungetch(abs(c));
    ungetch(sign);
    return readSYM();
  }

  if ( sign=='-' ) return readNUM(NEG,c);
  return readNUM(POS,c);
}

void _strcpy( char *d,char *s,int n ){
  int i = 0;
  while( s[i]!=(char) 0 ){
    d[i] = s[i];
    i++;
  }
  d[i] = s[i];
  { if ( i+1!=n ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",318 ); fprintf( stderr,"EXITIF: " "i+1!=n" "\n" ); fprintf( stderr,"Copied more then n chracters!" " in c-function %s().\n",__func__ ); peek( "make_num(n)",(make_num(n)) ); exit(1); } };
}

ATOM readSTR(){
  char buf[65536];
  int i=0,c;
  while ( c=getSTRch(),c>0 ){
    buf[i++] = (char) c;

    { if ( i==(65536 -1) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",327 ); fprintf( stderr,"EXITIF: " "i==(STR_LEN-1)" "\n" ); fprintf( stderr,"String too long" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  }
  buf[i] = (char) 0;
  int j;
  for ( j=1 ; j<freeStr ; j++ ){
    if ( strcmp( strings[j],buf )==0 ){
      ATOM a = make_str( j );
      return a;
    }
  }

  strings[ freeStr ] = malloc( i+1 );
  { if ( strings[ freeStr ]==((void *)0) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",339 ); fprintf( stderr,"EXITIF: " "strings[ freeStr ]==NULL" "\n" ); fprintf( stderr,"malloc returned NULL!" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };

  _strcpy( strings[ freeStr ],buf,i+1 );
  ATOM a = make_str( freeStr );
  freeStr++;
  return a;
}


ATOM readNUM(int m, int c){
  int n=0;
  n=m*(c-'0');
  while (c=getNUMch(), c>0 )
    n = n*10 + m*(c-'0');
  if ( c!=(-1) ) ungetch(-c);
  ATOM a=make_num(n);
  return a;
}

int getCOMch(){
  int c;
  while ( ( c=readch() ) )
    if ( c>=( ' ' ) || c==( '\n' ) || c==(-1) ) return c;
  { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",362 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"This character is not allowed in a comment" " in c-function %s().\n",__func__ ); peek( "make_chr(c)",(make_chr(c)) ); exit(1); } };
  return ( '\0' );
}

ATOM readCOM(){
  int c;
  while ( c=getCOMch(),c>=( ' ' ) );
  return ( (ATOM){.parval=(0), .partag=PAR} );
}

ATOM readCON(){
  int c;
  ATOM a;
  c = getch();
  { if ( c==(-1) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",376 ); fprintf( stderr,"EXITIF: " "c==EOF" "\n" ); fprintf( stderr,"Got EOF - need an integer for a constant" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  if ( c>='0' && c<='9' ) return ( (ATOM){.conval=(get_num( readNUM( POS,c ) )), .contag=CON} );
  if ( c=='-' || c=='+' ){
    a = readSYMorNUM(c);

    if ( get_tag(a)==NUM ){
      ATOM res = ( (ATOM){.conval=(get_num( a )), .contag=CON} );

      return res;
    }
    { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",386 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Digits expected after '+' or '-', got" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
  }
  { { fprintf( stderr,"%s  %d  ","pc-lisp-read2.c",388 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Integer expected, got" " in c-function %s().\n",__func__ ); peek( "make_chr(c)",(make_chr(c)) ); exit(1); } };
  ungetch(c);
  ungetch('#');
  ATOM sym = readSYM();
  fprinta( stderr,sym );
  return sym;
}


ATOM readLST(){
  ATOM t = read();
  if ( is_eq( t,( (ATOM){.chrval=(')'), .chrtag=CHR} ) ) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  { if ( is_eq( t,( (ATOM){.chrval=((-1)), .chrtag=CHR} ) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",400 ); fprintf( stderr,"EXITIF: " "is_eq( t,END )" "\n" ); fprintf( stderr,"Got EOF after '('" " in c-function %s().\n",__func__ ); peek( "NIL",(( (ATOM){.parval=(0), .partag=PAR} )) ); exit(1); } };
  ATOM a = cons( t,( (ATOM){.parval=(0), .partag=PAR} ) );
  ATOM x = a;
  { if ( is_null(a) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",403 ); fprintf( stderr,"EXITIF: " "is_null(a)" "\n" ); fprintf( stderr,"No cell storage to start this list or pair" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
  while ( ! is_eq( t=read(),( (ATOM){.chrval=(')'), .chrtag=CHR} ) ) ){
    { if ( is_eq( t,( (ATOM){.chrval=((-1)), .chrtag=CHR} ) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",405 ); fprintf( stderr,"EXITIF: " "is_eq( t,END )" "\n" ); fprintf( stderr,"Got EOF -need ')' or something" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
    if ( is_eq( t,( (ATOM){.chrval=(( '.' )), .chrtag=CHR} ) ) ){
      t = read();
      { if ( is_eq( t,( (ATOM){.chrval=((-1)), .chrtag=CHR} ) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",408 ); fprintf( stderr,"EXITIF: " "is_eq( t,END )" "\n" ); fprintf( stderr,"Got EOF - need cdr of pair" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
      set_cdr( x,t );
      t = read();
      { if ( ! is_eq( t,( (ATOM){.chrval=(')'), .chrtag=CHR} ) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",411 ); fprintf( stderr,"EXITIF: " "! is_eq( t,EOL )" "\n" ); fprintf( stderr,"Need ')' to close list or pair" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
      return a;
    }
    ATOM q = cons( t,( (ATOM){.parval=(0), .partag=PAR} ) );
    { if ( is_null(q) ){ fprintf( stderr,"%s line %d ","pc-lisp-read2.c",415 ); fprintf( stderr,"EXITIF: " "is_null(q)" "\n" ); fprintf( stderr,"No cell storage left for this list" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
    set_cdr( x,q );
    x = q;
  }
  return a;
}

ATOM readQUOTE(){
  ATOM atm = read();
  ATOM lst = cons( atm,( (ATOM){.parval=(0), .partag=PAR} ) );
  ATOM res = cons( kw_quote,lst );
  return res;
}
# 259 "pc-lisp-sym.c" 2

int is_eq( ATOM a,ATOM b ){
  return a.atm==b.atm;
}

int equal( ATOM a,ATOM b ){
EQUAL:
  if ( is_eq( a,b ) ) return ( 1==1 );
  if ( ! ( get_tag(a)==get_tag(b) ) ) return ( 1==0 );
  if ( is_str(a) ){
    if ( strcmp( strings[ get_str(a) ],strings[ get_str(b) ] )==0 ) return ( 1==1 );
    return ( 1==0 );
  }
  if ( is_par(a) ){
    if ( equal( car(a),car(b) ) ){
      a = cdr(a);
      b = cdr(b);
      goto EQUAL;
    }
  }
  return ( 1==0 );
}







int is_pair( ATOM p ){
  return is_par(p) && ( ! is_null(p) );
}


int is_list( ATOM p ){
  return is_par(p);

}

int is_atom( ATOM p ){
  return is_null(p) || ( ! is_par(p) );
}
int not( int a ){ return !a; }
int is_symbol( ATOM a ){ return is_sym(a); }
int is_null( ATOM a ){ return is_eq( a,( (ATOM){.parval=(0), .partag=PAR} ) ); }
# 314 "pc-lisp-sym.c"
ATOM pair( ATOM keys,ATOM vals ){


  return make_alist( keys,vals );
}


ATOM assoc( ATOM sym,ATOM env ){
ASSOC:


  if ( is_null(env) ) return ( (ATOM){.parval=(0), .partag=PAR} );

  ATOM first = car( env );


  if ( is_kvp(first) ){

    if ( is_eq( sym,kvp_key(first) ) ){
      ATOM val = kvp_val( first );

      return val;
    }

    ATOM res = assoc( sym,cdr(env) );
    return res;
  }





  ATOM res = assoc( sym,first );
  if ( ! is_null(res) ) return res;
  return assoc( sym,cdr(env) );
}

ATOM assoc2( ATOM sym,ATOM env ){
ASSOC2:
  if ( is_null(env) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  ATOM frame = car( env );
  ATOM kvp = alist_assoc( sym,frame );
  if ( ! is_null(kvp) ){
    return kvp;
  }

  env = cdr( env );
  goto ASSOC2;
}

ATOM assoc_kvp( ATOM sym,ATOM env ){
ASSOC:
  if ( is_null(env) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  ATOM first = car( env );
  if ( is_kvp(first) ){
    if ( is_eq( sym,kvp_key(first) ) ){
      ATOM val = first;
      return val;
    }
    ATOM res = assoc_kvp( sym,cdr(env) );
    return res;
  }
  ATOM res = assoc_kvp( sym,first );
  if ( ! is_null(res) ) return res;
  return assoc_kvp( sym,cdr(env) );
}
# 434 "pc-lisp-sym.c"
ATOM evallst( ATOM lst,ATOM env ){

  if ( is_null(lst) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  ATOM this = eval( car(lst),env );
  ATOM rest = evallst( cdr(lst),env );
  ATOM res = cons( this,rest );
  return res;
}




ATOM evalseq( ATOM seq,ATOM env ){
  ;
  if ( is_null(seq) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  if ( is_null( cdr(seq) ) ){
    ;
    ATOM res = eval( car(seq),env );
    ;
    return res;
  }
  ATOM ignore = eval( car(seq),env );
  ;
  ;
  ATOM res = evalseq( cdr(seq),env );
  ;
  return res;
}
# 504 "pc-lisp-sym.c"
ATOM make_frame( ATOM alst,ATOM env ){

  ATOM fra = cons( alst,env );

  return fra;
}





ATOM addKVPair3( ATOM kvp,ATOM env ){

  { if ( ! is_kvp( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",517 ); fprintf( stderr,"EXITIF: " "! is_kvp( kvp )" "\n" ); fprintf( stderr,"kvp is not a key-value-pair" " in c-function %s().\n",__func__ ); peek( "kvp",(kvp) ); exit(1); } };

  ATOM oldlist = car( env );


  { if ( ! is_alist( oldlist ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",522 ); fprintf( stderr,"EXITIF: " "! is_alist( oldlist )" "\n" ); fprintf( stderr,"oldlist is not an alist" " in c-function %s().\n",__func__ ); peek( "oldlist",(oldlist) ); exit(1); } };

  ATOM newlist = extend_alist( kvp,oldlist );
  set_gcm( newlist,2 );
  set_car( env,newlist );
  return newlist;
}

# 1 "pc-lisp-adt.c" 1







ATOM make_kvp( ATOM key,ATOM val ){

  { if ( ! is_atom( key ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",10 ); fprintf( stderr,"EXITIF: " "! is_atom( key )" "\n" ); fprintf( stderr,"key is not an atom" " in c-function %s().\n",__func__ ); peek( "key",(key) ); exit(1); } };

  ATOM kvp = cons( key,val );
  return kvp;
}

int is_kvp( ATOM kvp ){


  return is_pair( kvp ) && is_atom( car( kvp ) );
}


ATOM kvp_key( ATOM kvp ){
  { if ( ! is_kvp( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",24 ); fprintf( stderr,"EXITIF: " "! is_kvp( kvp )" "\n" ); fprintf( stderr,"kvp is not a key-value pair" " in c-function %s().\n",__func__ ); peek( "kvp",(kvp) ); exit(1); } };
  ATOM key = car( kvp );
  return key;
}


ATOM kvp_val( ATOM kvp ){
  { if ( ! is_kvp( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",31 ); fprintf( stderr,"EXITIF: " "! is_kvp( kvp )" "\n" ); fprintf( stderr,"kvp is not a key-value pair" " in c-function %s().\n",__func__ ); peek( "kvp",(kvp) ); exit(1); } };
  ATOM val = cdr( kvp );
  return val;
}
# 61 "pc-lisp-adt.c"
ATOM make_alist( ATOM keys,ATOM vals ){
  ;
  ;
  if ( is_null(keys) )
    if ( is_null(vals) ) return ( (ATOM){.parval=(0), .partag=PAR} );
    else { { fprintf( stderr,"%s  %d  ","pc-lisp-adt.c",66 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Not enough keys for values" " in c-function %s().\n",__func__ ); peek( "vals",(vals) ); exit(1); } };



  if ( is_atom(keys) )
    return cons( make_kvp( keys,vals ),( (ATOM){.parval=(0), .partag=PAR} ) );
  if ( is_null(vals) ){
    ATOM kvp = make_kvp( car(keys),( (ATOM){.parval=(0), .partag=PAR} ) );
    ATOM alst = cons( kvp,make_alist( cdr(keys),( (ATOM){.parval=(0), .partag=PAR} ) ) );
    return alst;
  }

  ATOM kvp = make_kvp( car(keys),car(vals) );
  ATOM alst = cons( kvp,make_alist( cdr(keys),cdr(vals) ) );
  ;
  { if ( ! is_alist( alst ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",81 ); fprintf( stderr,"EXITIF: " "! is_alist( alst )" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  return alst;
}

ATOM extend_alist( ATOM kvp,ATOM alst ){
  ;
  { if ( ! is_kvp( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",87 ); fprintf( stderr,"EXITIF: " "! is_kvp( kvp )" "\n" ); fprintf( stderr,"kvp is not a key-value pair" " in c-function %s().\n",__func__ ); peek( "kvp",(kvp) ); exit(1); } };
# 100 "pc-lisp-adt.c"
  ;
  { if ( ! is_alist( alst ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",101 ); fprintf( stderr,"EXITIF: " "! is_alist( alst )" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  ATOM res = cons( kvp,alst );
  { if ( ! is_alist( res ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",103 ); fprintf( stderr,"EXITIF: " "! is_alist( res )" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "res",(res) ); exit(1); } };
  ;
  return res;
}

int is_alist( ATOM alst ){

  if ( is_null(alst) ) return ( 1==1 );
  if ( is_atom(alst) ) return ( 1==0 );
  if ( ! is_kvp( car(alst) ) ) return ( 1==0 );

  if ( ! is_alist( cdr(alst) ) ) return ( 1==0 );
  return ( 1==1 );
}

ATOM alist_keys( ATOM alst ){

  if ( is_null(alst) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  { if ( ! is_alist(alst) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",121 ); fprintf( stderr,"EXITIF: " "! is_alist(alst)" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  return cons( kvp_key( car(alst) ),alist_keys( cdr(alst) ) );
}

ATOM alist_vals( ATOM alst ){

  if ( is_null(alst) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  { if ( ! is_alist(alst) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",128 ); fprintf( stderr,"EXITIF: " "! is_alist(alst)" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  return cons( kvp_val( car(alst) ),alist_vals( cdr(alst) ) );
}

ATOM alist_car_vals( ATOM alst ){

  if ( is_null(alst) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  { if ( ! is_alist(alst) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",135 ); fprintf( stderr,"EXITIF: " "! is_alist(alst)" "\n" ); fprintf( stderr,"alst is not an associative list" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  return cons( car( kvp_val( car(alst) ) ),alist_car_vals( cdr(alst) ) );
}
# 146 "pc-lisp-adt.c"
ATOM alist_assoc( ATOM key,ATOM alst ){
  ;

  { if ( ! is_atom(key) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",149 ); fprintf( stderr,"EXITIF: " "! is_atom(key)" "\n" ); fprintf( stderr,"key is not an atom" " in c-function %s().\n",__func__ ); peek( "key",(key) ); exit(1); } };
  { if ( ! is_alist(alst) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",150 ); fprintf( stderr,"EXITIF: " "! is_alist(alst)" "\n" ); fprintf( stderr,"alst is not an alist" " in c-function %s().\n",__func__ ); peek( "alst",(alst) ); exit(1); } };
  if ( is_null(alst) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  if ( equal( key,kvp_key( car(alst) ) ) ) return car( alst );
  return alist_assoc( key,cdr(alst) );
}

ATOM alist_find( ATOM key,ATOM alst ){


  return alist_assoc( key,alst );
}
# 179 "pc-lisp-adt.c"
ATOM make_table( ATOM tag ){
  { if ( ! is_atom(tag) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",180 ); fprintf( stderr,"EXITIF: " "! is_atom(tag)" "\n" ); fprintf( stderr,"tag is not an atom" " in c-function %s().\n",__func__ ); peek( "tag",(tag) ); exit(1); } };
  ATOM res = make_taglist( tag,( (ATOM){.parval=(0), .partag=PAR} ) );
  return res;
}

int is_table( ATOM table ){
  return is_taglist( table );
}

ATOM table_tag( ATOM table ){
  return taglist_tag( table );
}


ATOM table_insert_kvp( ATOM table,ATOM kvp ){
  ATOM next = cdr( table );
  ATOM new = cons( kvp,next );
  set_cdr( table,new );
  return table;
}

ATOM table_find( ATOM key,ATOM table ){
  return alist_find( key,cdr( table ) );
}
# 223 "pc-lisp-adt.c"
ATOM make_taglist( ATOM tag,ATOM lst ){
  { if ( ! is_atom( tag ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",224 ); fprintf( stderr,"EXITIF: " "! is_atom( tag )" "\n" ); fprintf( stderr,"tag is not an atom" " in c-function %s().\n",__func__ ); peek( "tag",(tag) ); exit(1); } };


  { if ( ! is_pair( lst ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",227 ); fprintf( stderr,"EXITIF: " "! is_pair( lst )" "\n" ); fprintf( stderr,"lst is not () or a list" " in c-function %s().\n",__func__ ); peek( "lst",(lst) ); exit(1); } };
  ATOM taglist = cons( tag,lst );
  return taglist;
}

int match_taglist( ATOM lst,ATOM tag ){
  if ( ! is_pair(lst) ) return ( 1==0 );
  return is_eq( car(lst),tag );
}
int is_taglist( ATOM taglist ){
  return is_pair(taglist) && is_atom( car(taglist) );
}

ATOM taglist_list( ATOM taglist ){
  { if ( ! is_pair( taglist ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",241 ); fprintf( stderr,"EXITIF: " "! is_pair( taglist )" "\n" ); fprintf( stderr,"taglist is not a list" " in c-function %s().\n",__func__ ); peek( "taglist",(taglist) ); exit(1); } };
  { if ( ! is_atom( car(taglist) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",242 ); fprintf( stderr,"EXITIF: " "! is_atom( car(taglist) )" "\n" ); fprintf( stderr,"taglist is not a list" " in c-function %s().\n",__func__ ); peek( "taglist",(taglist) ); exit(1); } };
  return cdr( taglist );
}

ATOM taglist_tag( ATOM taglist ){
  { if ( ! is_pair( taglist ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",247 ); fprintf( stderr,"EXITIF: " "! is_pair( taglist )" "\n" ); fprintf( stderr,"taglist is not a list" " in c-function %s().\n",__func__ ); peek( "taglist",(taglist) ); exit(1); } };
  { if ( ! is_atom( car(taglist) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",248 ); fprintf( stderr,"EXITIF: " "! is_atom( car(taglist) )" "\n" ); fprintf( stderr,"tag is not an atom" " in c-function %s().\n",__func__ ); peek( "car( taglist )",(car( taglist )) ); exit(1); } };
  return car( taglist );
}

ATOM taglist_insert( ATOM taglist,ATOM item ){
  { if ( ! is_taglist( taglist ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",253 ); fprintf( stderr,"EXITIF: " "! is_taglist( taglist )" "\n" ); fprintf( stderr,"taglist is not a tagged list" " in c-function %s().\n",__func__ ); peek( "taglist",(taglist) ); exit(1); } };
  ATOM new = cons( item,taglist_list(taglist) );
  set_cdr( taglist,new );
  return taglist;
}




ATOM make_tenv( ATOM env ){ return make_taglist( tag_env,env ); }
int is_tenv( ATOM tenv ){ return match_taglist( tenv,tag_env ); }


ATOM tenv_env( ATOM tenv ){
  { if ( ! is_tenv( tenv ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",267 ); fprintf( stderr,"EXITIF: " "! is_tenv( tenv )" "\n" ); fprintf( stderr,"tenv is not a tagged environment" " in c-function %s().\n",__func__ ); peek( "tenv",(tenv) ); exit(1); } };
  ATOM env = taglist_list( tenv );
  return env;
}




ATOM make_primitive( ATOM form,ATOM cfun ){
  ATOM left = cons( form,cfun );
  ATOM prim = cons( kw_primitive,left );
  return prim;
}

int is_primitive( ATOM prim ){
  return match_taglist( prim,kw_primitive );
}

ATOM primitive_form( ATOM prim ){
  { if ( ! is_primitive( prim ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",286 ); fprintf( stderr,"EXITIF: " "! is_primitive( prim )" "\n" ); fprintf( stderr,"prim not a primitive procedure" " in c-function %s().\n",__func__ ); peek( "prim",(prim) ); exit(1); } };

  ATOM form = car( cdr( prim ) );

  return form;
}

ATOM primitive_cfun( ATOM prim ){
  { if ( ! is_primitive( prim ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",294 ); fprintf( stderr,"EXITIF: " "! is_primitive( prim )" "\n" ); fprintf( stderr,"prim not a primitive procedure" " in c-function %s().\n",__func__ ); peek( "prim",(prim) ); exit(1); } };
  ATOM cfun = car( cdr( cdr( prim ) ) );
  return cfun;
}




ATOM make_lambda( ATOM form,ATOM body ){
  MARK3;



  ATOM left = cons( form,body );
  ATOM lamb = cons( kw_lambda,left );


  RETURN3( lamb );
}

int is_lambda( ATOM lamb ){
  return match_taglist( lamb,kw_lambda );
}

ATOM lambda_form( ATOM lamb ){
  { if ( ! is_lambda( lamb ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",319 ); fprintf( stderr,"EXITIF: " "! is_lambda( lamb )" "\n" ); fprintf( stderr,"lamb is not a lambda expression" " in c-function %s().\n",__func__ ); peek( "lamb",(lamb) ); exit(1); } };
  ATOM form = car( cdr( lamb ) );
  return form;
}

ATOM lambda_body( ATOM lamb ){
  { if ( ! is_lambda( lamb ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",325 ); fprintf( stderr,"EXITIF: " "! is_lambda( lamb )" "\n" ); fprintf( stderr,"lamb is not a lambda expression" " in c-function %s().\n",__func__ ); peek( "lamb",(lamb) ); exit(1); } };

  ATOM body = cdr( cdr( lamb ) );
  return body;
}







ATOM make_proc( ATOM func,ATOM env ){
  { if ( ! ( is_lambda(func) || is_primitive(func) ) ){ fprintf( stderr,"%s line %d ",
 "pc-lisp-adt.c"
# 338 "pc-lisp-adt.c"
  ,
 339
# 338 "pc-lisp-adt.c"
  ); fprintf( stderr,"EXITIF: " "! ( is_lambda(func) || is_primitive(func) )" "\n" ); fprintf( stderr,"func is not a lambda nor primitive" " in c-function %s().\n",__func__ ); peek( "func",(func) ); exit(1); } }
                                               ;

  ATOM tenv = make_tenv( env );
  ATOM clos = cons( func,tenv );
  ATOM proc = make_taglist( kw_closure,clos );
  return proc;
}

int is_proc( ATOM proc ){
  return match_taglist( proc,kw_closure )
    && ( match_taglist( car( cdr( proc ) ),kw_lambda )
      || match_taglist( car( cdr( proc ) ),kw_primitive ) );
}




ATOM proc_lambda( ATOM proc ){
  { if ( ! is_proc( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",357 ); fprintf( stderr,"EXITIF: " "! is_proc( proc )" "\n" ); fprintf( stderr,"proc is not a procedure" " in c-function %s().\n",__func__ ); peek( "proc",(proc) ); exit(1); } };
  ATOM lamb = car( cdr( proc ) );
  return lamb;
}




ATOM proc_env( ATOM proc ){
  { if ( ! is_proc( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",366 ); fprintf( stderr,"EXITIF: " "! is_proc( proc )" "\n" ); fprintf( stderr,"proc is not a procedure" " in c-function %s().\n",__func__ ); peek( "proc",(proc) ); exit(1); } };
  ATOM tenv = cdr( cdr( proc ) );
  ATOM env = tenv_env( tenv );
  return env;
}
# 379 "pc-lisp-adt.c"
ATOM make_app( ATOM proc,ATOM args ){
  { if ( ! ( is_symbol(proc) || is_proc(proc) ) ){ fprintf( stderr,"%s line %d ",
 "pc-lisp-adt.c"
# 380 "pc-lisp-adt.c"
  ,
 381
# 380 "pc-lisp-adt.c"
  ); fprintf( stderr,"EXITIF: " "! ( is_symbol(proc) || is_proc(proc) )" "\n" ); fprintf( stderr,"proc is not a symbol or procedure" " in c-function %s().\n",__func__ ); peek( "proc",(proc) ); exit(1); } }
                                              ;
  ATOM app = cons( proc,args );
  return app;
}

int is_app( ATOM app ){

  if ( ! is_pair(app) ) return ( 1==0 );
  ATOM proc = car( app );
  if ( is_symbol(proc) ) return ( 1==1 );
  if ( is_lambda(proc) ) return ( 1==1 );
  if ( is_primitive(proc) ) return ( 1==1 );
  return ( 1==0 );
}

ATOM app_proc( ATOM app ){
  { if ( ! is_app( app ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",397 ); fprintf( stderr,"EXITIF: " "! is_app( app )" "\n" ); fprintf( stderr,"app is not an application" " in c-function %s().\n",__func__ ); peek( "app",(app) ); exit(1); } };
  return car( app );
}

ATOM app_args( ATOM app ){
  { if ( ! is_app( app ) ){ fprintf( stderr,"%s line %d ","pc-lisp-adt.c",402 ); fprintf( stderr,"EXITIF: " "! is_app( app )" "\n" ); fprintf( stderr,"app is not an application" " in c-function %s().\n",__func__ ); peek( "app",(app) ); exit(1); } };
  return cdr( app );
}
# 531 "pc-lisp-sym.c" 2
# 1 "pc-lisp-eval-adt.c" 1

int is_application( ATOM exp ){ return is_app( exp ) ; }
int is_progn ( ATOM exp ){ return match_taglist( exp,kw_progn ) ; }
int is_display ( ATOM exp ){ return match_taglist( exp,kw_display ) ; }
int is_print ( ATOM exp ){ return match_taglist( exp,kw_print ) ; }
int is_eval ( ATOM exp ){ return match_taglist( exp,kw_eval ) ; }
int is_eval1 ( ATOM exp ){ return match_taglist( exp,kw_eval1 ) ; }
int is_apply ( ATOM exp ){ return match_taglist( exp,kw_apply ) ; }
int is_load ( ATOM exp ){ return match_taglist( exp,kw_load ) ; }
int is_read ( ATOM exp ){ return match_taglist( exp,kw_read ) ; }

int is_delay ( ATOM exp ){ return match_taglist( exp,kw_delay ) ; }
int is_eval_list ( ATOM exp ){ return match_taglist( exp,kw_list ) ; }
int is_if ( ATOM exp ){ return match_taglist( exp,kw_if ) ; }
int is_cond ( ATOM exp ){ return match_taglist( exp,kw_cond ) ; }
int is_quoted ( ATOM exp ){ return match_taglist( exp,kw_quote ) ; }
int is_definition ( ATOM exp ){ return match_taglist( exp,kw_define ) ; }
int is_variable ( ATOM exp ){ return is_sym( exp ) ; }
int is_set ( ATOM exp ){ return match_taglist( exp,kw_set ) ; }
int is_self_eval ( ATOM exp ){
  return is_null(exp) || is_num(exp) || is_chr(exp) || is_str(exp) || is_con(exp);
}

ATOM quoted_value( ATOM exp ){
  return car( taglist_list( exp ) );
}





ATOM if_pred( ATOM exp ){
  { if ( ! is_if( exp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",33 ); fprintf( stderr,"EXITIF: " "! is_if( exp )" "\n" ); fprintf( stderr,"Not an if expression" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  { if ( is_null( cdr(exp) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",34 ); fprintf( stderr,"EXITIF: " "is_null( _Rfrom2(exp) )" "\n" ); fprintf( stderr,"No predicate and consequent terms" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  return car( cdr( exp ) );
}

ATOM if_con( ATOM exp ){
  { if ( ! is_if( exp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",39 ); fprintf( stderr,"EXITIF: " "! is_if( exp )" "\n" ); fprintf( stderr,"Not an if expression" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  { if ( is_null( cdr( cdr( exp ) ) ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",40 ); fprintf( stderr,"EXITIF: " "is_null( _Rfrom3(exp) )" "\n" ); fprintf( stderr,"No consequent term" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  return car( cdr( cdr( exp ) ) );
}

ATOM if_alt( ATOM exp ){
  { if ( ! is_if( exp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",45 ); fprintf( stderr,"EXITIF: " "! is_if( exp )" "\n" ); fprintf( stderr,"Not an if expression" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  if ( is_null( cdr( cdr( cdr( exp ) ) ) ) ) return ( (ATOM){.parval=(0), .partag=PAR} );
  return car( cdr( cdr( cdr( exp ) ) ) );
}


ATOM eval_if( ATOM exp,ATOM env ){
  ATOM pred = if_pred(exp);

  ATOM epred = eval( pred,env );

  if ( ! is_null(epred) ){
    ATOM con = if_con(exp);

    ATOM res = eval( con,env );

    return res;
  }
  ATOM alt = if_alt(exp);

  ATOM res = eval( alt,env );

  return res;
}
# 79 "pc-lisp-eval-adt.c"
int is_cond_clause( ATOM clau ){
  return is_pair( clau );
}

ATOM cond_clause_pred( ATOM clau ){
  { if ( ! is_cond_clause( clau ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",84 ); fprintf( stderr,"EXITIF: " "! is_cond_clause( clau )" "\n" ); fprintf( stderr,"Not an cond clause" " in c-function %s().\n",__func__ ); peek( "clau",(clau) ); exit(1); } };
  return car( clau );
}

ATOM cond_clause_con( ATOM clau ){
  { if ( ! is_cond_clause( clau ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",89 ); fprintf( stderr,"EXITIF: " "! is_cond_clause( clau )" "\n" ); fprintf( stderr,"Not an cond clause" " in c-function %s().\n",__func__ ); peek( "clau",(clau) ); exit(1); } };
  return cdr( clau );
}

ATOM eval_cond_clauses( ATOM lst,ATOM env ){
  ATOM clau = car( lst );
  ATOM pred = cond_clause_pred( clau );
  if ( ! is_null( eval(pred,env) ) ){
    ATOM con = cond_clause_con( clau );
    return evalseq( con,env );
  }
  else{
    return eval_cond_clauses( cdr(lst),env );
  }
}



ATOM eval_progn( ATOM seq,ATOM env ){
  MARK3;

  ATOM res = evalseq( seq,env );
  RETURN3( res );
}



ATOM eval_list( ATOM exp,ATOM env ){
  ATOM args = app_args( exp );
  ATOM list = evallst( args,env );
  return list;
}
# 132 "pc-lisp-eval-adt.c"
ATOM definition_variable( ATOM exp ){
  if ( is_symbol( car( cdr( exp ) ) ) ) return car( cdr( exp ) );
  { { fprintf( stderr,"%s  %d  ","pc-lisp-eval-adt.c",134 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Unknown define structure" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  return car( car( cdr( exp ) ) );
}

ATOM definition_value( ATOM exp ){
  if ( is_symbol( car( cdr( exp ) ) ) ) return car( cdr( cdr( exp ) ) );
  { { fprintf( stderr,"%s  %d  ","pc-lisp-eval-adt.c",140 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Unknown define structure" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
  ATOM form = cdr( car( cdr( exp ) ) );

  ATOM body = car( cdr( cdr( exp ) ) );
  ATOM lamb = make_lambda( form,body );
  return lamb;
}


ATOM eval_definition( ATOM exp,ATOM env ){
  MARK3;


  ATOM sym = car( cdr( exp ) );

  ATOM val = eval( car( cdr( cdr( exp ) ) ),env );

  ATOM kvp = make_kvp( sym,val );

  _mark_assignments_as_special( kvp );
  ATOM fra = addKVPair3( kvp,env );



  RETURN3( sym );
}


ATOM eval_set( ATOM exp,ATOM env ){
  MARK3;


  ATOM sym = car( cdr( exp ) );
  ATOM val = eval( car( cdr( cdr( exp ) ) ),env );


  ATOM kvp = assoc_kvp( sym,env );

  { if ( is_null( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",178 ); fprintf( stderr,"EXITIF: " "is_null( kvp )" "\n" ); fprintf( stderr,"sym not found in environment" " in c-function %s().\n",__func__ ); peek( "sym",(sym) ); exit(1); } };
  ATOM res = set_cdr( kvp,val );
  _mark_assignments_as_special( res );



  RETURN3( sym );
}



ATOM variable_value( ATOM var,ATOM env ){

  ATOM kvp = assoc2( var,env );
  { if ( is_null( kvp ) ){ fprintf( stderr,"%s line %d ","pc-lisp-eval-adt.c",192 ); fprintf( stderr,"EXITIF: " "is_null( kvp )" "\n" ); fprintf( stderr,"var not found in environment" " in c-function %s().\n",__func__ ); peek( "var",(var) ); exit(1); } };
  ATOM res = kvp_val(kvp);
  return res;
}
# 532 "pc-lisp-sym.c" 2



int loop=0;
ATOM eval(ATOM exp, ATOM env){
  ATOM e;



  if ( is_self_eval(exp) ) return exp;
  if ( is_variable(exp) ) return variable_value( exp,env );
  if ( is_quoted(exp) ) return quoted_value( exp );
  MARK3;

  if ( is_definition(exp))
    RETURN3( eval_definition( exp,env ) );

  if ( is_set(exp) )
    RETURN3( eval_set( exp,env ) );

  if ( is_if(exp) )
    RETURN3( eval_if( exp,env ) );

  if ( is_cond(exp) )
    RETURN3( eval_cond_clauses( cdr(exp),env ) );

  if ( is_eval_list(exp) )
    RETURN3( eval_list( exp,env ) );


  if ( is_load(exp) ){
# 572 "pc-lisp-sym.c"
    FILE *f = fopen( strings[ get_str( car( cdr( exp ) ) ) ],"r" );
    { if ( f==((void *)0) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",573 ); fprintf( stderr,"EXITIF: " "f==NULL" "\n" ); fprintf( stderr,"Could not open file" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
    FILE *old = in;
    int old_pos=pos;
    int old_line=line;
    in = f;






    GLOBAL_KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) );
    ATOM ret = repl();

    fclose(f);
    in = old;


    line=old_line;
    pos=old_pos;

    return readString( "\"File loaded.\"" );
  }

  if ( is_eval(exp) ){
    ATOM exp1 = car( cdr( exp ) );
    ATOM env1 = car( cdr( cdr( exp ) ) );
    ATOM res = eval( exp1,env1 );
    RETURN3( res );
  }

  if ( is_eval1(exp) ){
    ATOM exp1 = eval( car( cdr( exp ) ),env );
    ATOM res = eval( exp1,env );
    RETURN3( res );
  }

  if ( is_apply(exp) ){

    ATOM proc = eval ( car( cdr( exp ) ),env );

    { if ( is_null( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",614 ); fprintf( stderr,"EXITIF: " "is_null( proc )" "\n" ); fprintf( stderr,"User function not defined in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
    { if ( is_atom( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",615 ); fprintf( stderr,"EXITIF: " "is_atom( proc )" "\n" ); fprintf( stderr,"User function returned an atom in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };

    ATOM args = eval( car( cdr( cdr( exp ) ) ),env );

    ATOM res = apply( proc,args );

    RETURN3( res );
  }
# 632 "pc-lisp-sym.c"
  if ( is_delay(exp) ){

    ATOM body = cdr(exp);
    ATOM form = ( (ATOM){.parval=(0), .partag=PAR} );
    ATOM lamb = make_lambda( form,body );
    ATOM proc = make_proc( lamb,env );


    RETURN3( proc );
  }

  if ( is_lambda(exp) ){
    ATOM proc = make_proc( exp,env );
    ;

    RETURN3( proc );
  }

  if ( is_progn(exp) ){
    ATOM res = eval_progn( cdr(exp),env );
    RETURN3( res );
  }

  if ( is_primitive(exp) ){



    ATOM proc = make_proc( exp,env );

    RETURN3( proc );
  }



  if ( is_application(exp) ){
    ATOM proc = eval( app_proc(exp),env );

    { if ( is_null( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",669 ); fprintf( stderr,"EXITIF: " "is_null( proc )" "\n" ); fprintf( stderr,"User function not defined in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
    { if ( is_atom( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",670 ); fprintf( stderr,"EXITIF: " "is_atom( proc )" "\n" ); fprintf( stderr,"User function returned an atom in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };


    ATOM args = app_args(exp);

    ATOM vals = evallst(args,env);

    ATOM res = apply( proc,vals );
    RETURN3( res );
  }

  { { fprintf( stderr,"%s line %d ","pc-lisp-sym.c",681 ); fprintf( stderr,"%s(): ",__func__ ); peek( "SPECIAL APPLICATION" " " "exp",(exp) ); } };
    ATOM proc = eval( car(exp),env );

    { if ( is_null( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",684 ); fprintf( stderr,"EXITIF: " "is_null( proc )" "\n" ); fprintf( stderr,"User function not defined in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };
    { if ( is_atom( proc ) ){ fprintf( stderr,"%s line %d ","pc-lisp-sym.c",685 ); fprintf( stderr,"EXITIF: " "is_atom( proc )" "\n" ); fprintf( stderr,"User function returned an atom in environment" " in c-function %s().\n",__func__ ); peek( "exp",(exp) ); exit(1); } };


    ATOM args = evallst(cdr(exp),env);

    ATOM res = apply( proc,args );
    RETURN3( res );

  { { fprintf( stderr,"%s  %d  ","pc-lisp-sym.c",693 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"I can't do this for some reason." " in c-function %s().\n",__func__ ); peek( "cons( exp,env )",(cons( exp,env )) ); exit(1); } };
  return ( (ATOM){.parval=(0), .partag=PAR} );
}

ATOM apply(ATOM proc, ATOM args){
  MARK3;


  if ( is_proc(proc) ){
    ATOM func = proc_lambda( proc );

  if ( is_primitive( func ) ){




    ATOM form = primitive_form( func );
    ATOM cfun = primitive_cfun( func );

    ATOM fEnv = proc_env( proc );

    ATOM alst = pair( form,args ) ;

    ATOM eEnv = make_frame( alst,fEnv );

    ATOM (*fn)() = primFns[ get_num(cfun) ];
    ATOM res = (*fn)( args,eEnv );

    RETURN3( res );
  }


  if ( is_lambda(func) ){

    ATOM form = lambda_form( func );
    ATOM body = lambda_body( func );

    ATOM fEnv = proc_env( proc );

    ATOM alst = pair( form,args ) ;

    ATOM eEnv = make_frame( alst,fEnv );

    ATOM res = evalseq( body,eEnv );


    RETURN3( res );
  }
  { { fprintf( stderr,"%s  %d  ","pc-lisp-sym.c",741 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Unknown function" " in c-function %s().\n",__func__ ); peek( "func",(func) ); exit(1); } };
  }

  { { fprintf( stderr,"%s  %d  ","pc-lisp-sym.c",744 ); fprintf( stderr,"EXIT: " "\n" ); fprintf( stderr,"Unknown" " in c-function %s().\n",__func__ ); peek( "proc",(proc) ); exit(1); } };
}

ATOM _global_save;

ATOM repl(){
  ATOM ret;
  fprintf( stderr,"\nStart REPL...\n" );
  while ( 1==1 ){
    GLOBAL_MARK3;

    ATOM exp = read();

    if ( is_eq( exp,( (ATOM){.chrval=((-1)), .chrtag=CHR} ) ) ){
      fputs( "EOF\n", stderr );
      break;
    }
    fputs( "========================================\n", stderr );

    { { fprintf( stderr,"%s line %d ","pc-lisp-sym.c",763 ); fprintf( stderr,"%s(): ",__func__ ); peek( "Read: " " " "exp",(exp) ); } };

    ATOM r = eval( exp,gEnv );
# 808 "pc-lisp-sym.c"
      ret = r;
      printa( ret );

      GLOBAL_KEEP3( ( (ATOM){.parval=(0), .partag=PAR} ) );





    _check_mem();

    puts( "" );
  }

  GLOBAL_KEEP3( gEnv );
  _ms( gEnv );

  return ret;
}

ATOM readString(char *s){
  reads = readp = s;
  readch = readchString;
  ungetch = ungetchString;
  ATOM x=read();
  readch = readchNormal;
  ungetch = ungetchNormal;
  return x;
}

int main(){


  boot();

  in = stdin;
  setvbuf(in, buf, 1, ((1<<8)-1));

  repl();




  _check_mem_leak();


  fprintf( stderr,"Done.\n" );
  fprintf( stderr,"Pairs     =%d\n",consCount );
  fprintf( stderr,"Max Pairs =%d\n",consMaxCount );
  fprintf( stderr,"  Recycled=%d\n",_recyclePairCount );
  fprintf( stderr,"     Swept=%d\n",_sweepPairCount );
  fprintf( stderr,"Symbols   =%d\n",freeSym );
  fprintf( stderr,"Strings   =%d\n",freeStr );
  fprintf( stderr,"  Recycled=%d\n",_recycleStrCount );
  return 0;
}
