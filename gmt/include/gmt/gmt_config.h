/*
 * $Id: gmt_config.h.in 17451 2017-01-16 21:36:06Z pwessel $
 *
 *  Copyright (c) 1991-2017 by P. Wessel, W. H. F. Smith, R. Scharroo,
 *  F. Wobbe, and J. Luis
 * See LICENSE.TXT file for copying and redistribution conditions.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3 or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * Contact info: gmt.soest.hawaii.edu
 *--------------------------------------------------------------------
 *
 * This include file contains ifdefs that tell us if this system has
 * some of the several functions that are not part of POSIX but are
 * often distributed anyway as part of ANSI C.  The set of defines
 * below is automatically assigned by CMake and determines if the
 * required functions are present or not.  These macros are then used
 * to choose between a function prototype (if found), an alternative
 * GMT function, or simply a macro.  The purpose is to take advantage
 * of the built-in functions if they exist and provide alternative
 * definitions otherwise.
 *
 * HAVE_<func> is undefined or defined as 1 depending on
 * whether or not <func> is available on this system.
 *
 * Version: GMT 5.4.2_r18202
 */

#pragma once
#ifndef _GMT_CONFIG_H
#define _GMT_CONFIG_H

#include "config.h"


/* which regex library <pcre.h>, <regex.h> */
#define HAVE_PCRE
/* #undef HAVE_POSIX_ERE */

/* compile with GDAL support <gdal.h> */
#define HAVE_GDAL

/* compile with LAPACK support */
/* #undef HAVE_LAPACK */

/* compile with FFTW3 support <fftw3.h> */
/* #undef HAVE_FFTW3F */
/* #undef HAVE_FFTW3F_THREADS */

/* compile with ZLIB support <zlib.h> */
#define HAVE_ZLIB

/* compile with GLIB GThread support <glib.h> */
#define HAVE_GLIB_GTHREAD

/* compile with pthreads support <pthread.h> */
/* #undef HAVE_PTHREAD */

/* shared library */
#define BUILD_SHARED_LIBS

/* set license restrictions */
/* #undef LICENSE_RESTRICTED */
#ifndef LICENSE_RESTRICTED
	/* enable Shewchuk's triangle routine */
#	define TRIANGLE_D
#endif

/* applies only #ifdef _WIN32 */
/* #undef USE_MEM_ALIGNED */

/* if NetCDF is static; applies only #ifdef _WIN32 */
/* #undef NETCDF_STATIC */

/* system specific headers */

#define HAVE_ASSERT_H_
/* #undef HAVE_DIRENT_H_ */
#define HAVE_ERRNO_H_
/* #undef HAVE_EXECINFO_H_ */
#define HAVE_FCNTL_H_
#define HAVE_SIGNAL_H_
/* #undef HAVE_SYS_DIR_H_ */
/* #undef HAVE_SYS_RESOURCE_H_ */
#define HAVE_SYS_STAT_H_
/* #undef HAVE_SYS_TIME_H_ */
/* #undef HAVE_SYS_UCONTEXT_H_ */
/* #undef HAVE_UNISTD_H_ */

/* system specific functions */

#define HAVE_ACCESS
#define HAVE__ACCESS
/* #undef HAVE_BASENAME */
/* #undef HAVE_DLADDR */
/* #undef HAVE_FCNTL */
#define HAVE_FILENO
#define HAVE__FILENO
/* #undef HAVE_FSEEKO */
/* #undef HAVE_FTELLO */
#define HAVE__FSEEKI64
#define HAVE__FTELLI64
/* #undef HAVE___FUNC__ */
#define HAVE___FUNCTION__
#define HAVE__GETCWD
/* #undef HAVE_GETPID */
#define HAVE__GETPID
/* #undef HAVE_GETPWUID */
#define HAVE_LLABS
/* #undef HAVE_MEMALIGN */
#define HAVE__MKDIR
/* #undef HAVE_PCLOSE */
#define HAVE__PCLOSE
/* #undef HAVE_POPEN */
#define HAVE__POPEN
/* #undef HAVE_POSIX_MEMALIGN */
/* #undef HAVE_QSORT_R_GLIBC */
#define HAVE_SETLOCALE
#define HAVE__SETMODE
/* #undef HAVE_SNPRINTF_ */
#define HAVE__SNPRINTF_
#define HAVE_VSNPRINTF_
#define HAVE__VSNPRINTF_
#define HAVE__STAT
#define HAVE__STATI64
/* #undef HAVE_STRCASECMP */
/* #undef HAVE_STRNCASECMP */
#define HAVE_STRICMP
#define HAVE_STRNICMP
#define HAVE_STRDUP
/* #undef HAVE_STRSEP */
#define HAVE_STRTOD
#define HAVE_STRTOF_
/* #undef HAVE_STRTOK_R */
#define HAVE_STRTOK_S
#define DECLARED_STRDUP
/* #undef DECLARED_STRSEP */

/* sysconf/sysctl */
/* #undef HAVE_SC_NPROC_ONLN */
/* #undef HAVE_SC_NPROCESSORS_ONLN */
/* #undef HAVE_SYSCTL_HW_NCPU */

/* support for inline functions */
/* #undef HAVE_C_inline */
#define HAVE_C___inline
/* #undef HAVE_C___inline__ */
#ifndef HAVE_C_inline
#	if defined(HAVE_C___inline)
#		define inline __inline
#	elif defined(HAVE_C___inline__)
#		define inline __inline__
#	else
#		define inline /* not supported */
#	endif
#endif /* !HAVE_C_inline */

/* windows specific */

#define HAVE_DIRECT_H_
#define HAVE_IO_H_
#define HAVE_PROCESS_H_

/* C types; C99 exact-width integer types <inttypes.h>, <stdint.h>; etc */

#define HAVE_CTYPE_H_
#define HAVE_STDDEF_H_
#define HAVE_SYS_TYPES_H_

/* We prefer to use extensions (e.g., strdup, sincos) when available */
#ifdef __GNUC__
#	define _GNU_SOURCE
#endif
#if defined(__sun) || defined(__sun__)
#	ifndef __EXTENSIONS__
#		define __EXTENSIONS__
#	endif
#endif

/* Math headers */

/* #undef HAVE_FLOATINGPOINT_H_ */
/* #undef HAVE_IEEEFP_H_ */

/* Math related */

#define HAVE_ACOSF
#define HAVE_ACOSH
#define HAVE_ACOSHF
#define HAVE_ASINF
#define HAVE_ASINH
#define HAVE_ASINHF
#define HAVE_ATANF
#define HAVE_ATANH
#define HAVE_ATANHF
#define HAVE_ATAN2F
/* #undef HAVE_COPYSIGNF */
#define HAVE_COPYSIGN
#define HAVE__COPYSIGN
#define HAVE_CEILF
#define HAVE_COSF
#define HAVE_COSHF
#define HAVE_ERF
#define HAVE_ERFF
#define HAVE_ERFC
#define HAVE_ERFCF
#define HAVE_EXPF
#define HAVE_FABSF
#define HAVE_FLOORF
#define HAVE_FMODF
#define HAVE__FINITE
#define HAVE__FPCLASS
#define HAVE_HYPOT
#define HAVE_HYPOTF
#define HAVE_ISFINITE
#define HAVE_ISINF
#define HAVE_ISNAN
/* #undef HAVE_ISNAND */
/* #undef HAVE_ISNANF */
#define HAVE__ISNAN
#define HAVE_ISNORMAL
#define HAVE_J0
#define HAVE_J1
#define HAVE_JN
#define HAVE_LRINT
#define HAVE_LRINTF
#define HAVE_LOGF
#define HAVE_LOG10F
#define HAVE_LOG1P
#define HAVE_LOG1PF
#define HAVE_LOG2
#define HAVE_LOG2F
#define HAVE_POWF
#define HAVE_RINT
#define HAVE_RINTF
#define HAVE_SINF
#define HAVE_SINHF
/* #undef HAVE_SINCOS */
#define HAVE_SQRTF
#define HAVE_TANF
#define HAVE_TANHF
#define HAVE_Y0
#define HAVE_Y1
#define HAVE_YN

/* Sizes */
#define SIZEOF__BOOL       1
/* #undef SIZEOF_BOOL */
#define SIZEOF_INT         4
/* #undef SIZEOF_GREG_T */
#define SIZEOF_LONG        4
#define SIZEOF_LONG_LONG   8
#define SIZEOF_LONG_DOUBLE 8
/* #undef SIZEOF_MODE_T */
#define SIZEOF_OFF_T       4
#define SIZEOF_SIZE_T      4
#define SIZEOF_WCHAR_T     2
#define SIZEOF_VOID_P      4
/* #undef WORDS_BIGENDIAN */

/* Must redefine some sizes manually to allow for universal builds on OSX */
#ifdef __APPLE__
#	undef SIZEOF_LONG
#	undef SIZEOF_SIZE_T
#	undef SIZEOF_VOID_P
#	ifdef __LP64__
#		define SIZEOF_LONG      8
#		define SIZEOF_SIZE_T    8
#		define SIZEOF_VOID_P    8
#	else /* !__LP64__ */
#		define SIZEOF_LONG      4
#		define SIZEOF_SIZE_T    4
#		define SIZEOF_VOID_P    4
#	endif /* __LP64__ */
#endif /* __APPLE__ */

/* Byte swapping functions */
/* #undef HAVE___BUILTIN_BSWAP16 */
/* #undef HAVE___BUILTIN_BSWAP32 */
/* #undef HAVE___BUILTIN_BSWAP64 */
#define HAVE__BYTESWAP_USHORT /* for 16 bit */
#define HAVE__BYTESWAP_ULONG /* for 32 bit */
#define HAVE__BYTESWAP_UINT64 /* for 64 bit */

#if 0	/* PW: Commented out; see issue # 614 */
/* Architecture type (32/64 bits) */
#if !defined(__x86_64__) && !defined(__i386__) && SIZEOF_VOID_P == 4 /* on i386 */
#	define __i386__ 1
#elif !defined(__x86_64__) && !defined(__i386__) && SIZEOF_VOID_P == 8 /* on x86_64 */
#	define __x86_64__ 1
#endif
#endif

#if !(defined(__LP64__) || defined(__LLP64__)) && defined(__x86_64__) && \
		defined(SIZEOF_LONG_LONG) && defined(SIZEOF_LONG) && defined(SIZEOF_INT)
#	if SIZEOF_LONG == 8 && SIZEOF_INT == 4 /* 64 bit longs and pointers (most UNIX) */
#		ifndef __LP64__
#			define __LP64__ 1
#		endif
#	elif SIZEOF_LONG_LONG == 8 && SIZEOF_LONG == 4 /* Win X64/IA-64 */
#		ifndef __LLP64__
#			define __LLP64__ 1
#		endif
#	endif
#endif /* !(defined(__LP64__) || defined(__LLP64__)) && defined(__x86_64__) &&
		defined(SIZEOF_LONG_LONG) && defined(SIZEOF_LONG) && defined(SIZEOF_INT) */

/* Enable 32 bit systems to use files of sizes beyond the usual limit of 2GB */
#if defined(__i386__) && !defined _WIN32 /* on i386 with LFS support */
#	ifdef _LARGEFILE_SOURCE
#		undef _LARGEFILE_SOURCE
#	endif
#	define _LARGEFILE_SOURCE
#	ifdef _FILE_OFFSET_BITS
#		undef _FILE_OFFSET_BITS
#	endif
#	define _FILE_OFFSET_BITS 64
#endif

/* Check whether conditions for sighandler are met */
#if !(defined(HAVE_SIGNAL_H_) && defined(HAVE_SYS_RESOURCE_H_) && \
			defined(HAVE_SYS_TIME_H_) && defined(HAVE_SYS_UCONTEXT_H_))
#	define NO_SIGHANDLER
#endif

#endif /* !_GMT_CONFIG_H */

/* vim: set ft=c: */
