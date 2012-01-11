# 1 "pc-lisp-print.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "pc-lisp-print.c"



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
# 5 "pc-lisp-print.c" 2

int pmark = 0;

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
  if ( is_eq( a,( (ATOM){.parval=(0), .partag=PAR} ) ) ){ fprintf( f,"()" ); return; }
  if ( is_eq( a,( (ATOM){.chrval=((-1)), .chrtag=CHR} ) ) ){ fprintf( f,"?END?" ); return; }
  if ( is_eq( a,( (ATOM){.conval=(-9), .contag=CON} ) ) ){ fprintf( f,"?UNDEF?" ); return; }
  if ( is_eq( a,( (ATOM){.conval=(-10), .contag=CON} ) ) ){ fprintf( f,"!RECYCLED!" ); return; }
  if ( is_eq( a,( (ATOM){.chrval=(')'), .chrtag=CHR} ) ) ){ fprintf( f,"?)?" ); return; }
  if ( is_eq( a,( (ATOM){.chrval=(( '.' )), .chrtag=CHR} ) ) ){ fprintf( f,"?.?" ); return; }
  if ( is_eq( a,( (ATOM){.conval=(1), .contag=CON} ) ) ){ fprintf( f,"#t" ); return; }

  switch ( get_tag(a) ){
  case PAR:
    { if ( get_val(a)<=0 ){ fprintf( stderr,"%s line %d ","pc-lisp-print.c",47 ); fprintf( stderr,"EXITIF: " "get_val(a)<=0" "\n" ); fprintf( stderr,"Negative list index" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };

    if ( is_tenv(a) ){
      if ( is_eq( tenv_env(a),gEnv ) )
        fputs( "g",f );
      else
        fprintp( f,a,( ' ' ),"",fmt );
      return;
    }
    if ( is_lambda(a) ){
      fputs( "<",f );
      fprintp( f,a,( ' ' ),"",fmt );
      fputc( '>',f );
      return;
    }
    if ( is_primitive(a) ){
      fputs( "{",f );
      fprintp( f,a,( ' ' ),"",fmt );
      fputc( '}',f );
      return;
    }
    if ( match_taglist( a,kw_quote) ){
      fputc( '\'',f );
      fprinta1( f,car( cdr( a ) ),"",fmt );
      return;
    }
    fputs( lsep,f );
    fputs( "(",f );
    char buf[110]="";
    if ( lsep[0]>0 )
      snprintf( buf,99,"%s  \0",lsep );
    fprintp( f,a,( ' ' ),buf,fmt );
    fputs( ")",f );
    return;


  case STR:
    { if ( get_val(a)<=0 ){ fprintf( stderr,"%s line %d ","pc-lisp-print.c",84 ); fprintf( stderr,"EXITIF: " "get_val(a)<=0" "\n" ); fprintf( stderr,"Negative string index" " in c-function %s().\n",__func__ ); peek( "a",(a) ); exit(1); } };
    fprintf( f,printFormat[ get_tag(a) ][fmt],strings[ get_str(a) ] );
    return;


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


void fprintp( FILE *f,ATOM p,char sep,char *lsep,int fmt ){
  ATOM t;
LOOP:
  _print_flag( f,p );
  fprinta1( f,car(p),lsep,fmt );
  set_pmk( p,pmark );
  t = cdr(p);
  if ( is_null(t) ) return;
  if ( sep>0 ) fputc( sep,f );
  if ( is_pair(t) ){
    if ( is_eq( t,gEnv ) ){
      _print_flag( f,t );
      fputs( "G",f );
      return;
    }
    if ( is_tenv(t) ){

      if ( pmk(t)==pmark ){
        _print_flag( f,t );
        fputc( '@',f );
      }
      else
        fprintp( f,t,( ' ' ),"",fmt );

      return;
    }
    p = t;
    goto LOOP;
  }
  fputc( '.',f );
  fputc( sep,f );
  fprinta1( f,t,lsep,fmt );
}
