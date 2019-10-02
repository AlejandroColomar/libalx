/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/statistics/mean.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include <gsl/gsl_statistics_uchar.h>
#include <gsl/gsl_statistics_char.h>
#include <gsl/gsl_statistics_ushort.h>
#include <gsl/gsl_statistics_short.h>
#include <gsl/gsl_statistics_uint.h>
#include <gsl/gsl_statistics_int.h>

#include "libalx/base/assert/assert.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_stdint_types();


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define gsl_stats_mean_ldbl(nmemb, arr)	 alx_gsl_stats_mean_ldbl(nmemb, arr)
#define gsl_stats_mean_flt(nmemb, arr)	 alx_gsl_stats_mean_flt(nmemb, arr)
#define gsl_stats_mean_u8(nmemb, arr)	 alx_gsl_stats_mean_u8(nmemb, arr)
#define gsl_stats_mean_s8(nmemb, arr)	 alx_gsl_stats_mean_s8(nmemb, arr)
#define gsl_stats_mean_u16(nmemb, arr)	 alx_gsl_stats_mean_u16(nmemb, arr)
#define gsl_stats_mean_s16(nmemb, arr)	 alx_gsl_stats_mean_s16(nmemb, arr)
#define gsl_stats_mean_u32(nmemb, arr)	 alx_gsl_stats_mean_u32(nmemb, arr)
#define gsl_stats_mean_s32(nmemb, arr)	 alx_gsl_stats_mean_s32(nmemb, arr)
#define gsl_stats_mean_u64(nmemb, arr)	 alx_gsl_stats_mean_u64(nmemb, arr)
#define gsl_stats_mean_s64(nmemb, arr)	 alx_gsl_stats_mean_s64(nmemb, arr)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, pure))
long double alx_gsl_stats_mean_ldbl(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb]);
__attribute__((nonnull, pure))
float	alx_gsl_stats_mean_flt	(ptrdiff_t nmemb,
				 const float arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb]);
__attribute__((always_inline, nonnull, pure))
inline
double	alx_gsl_stats_mean_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
long double alx_gsl_stats_mean_u64(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
long double alx_gsl_stats_mean_s64(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb]);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
double	alx_gsl_stats_mean_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb])
{
	return	gsl_stats_uchar_mean(arr, 1, nmemb);
}

inline
double	alx_gsl_stats_mean_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb])
{

	alx_assert_char_signed();
	return	gsl_stats_char_mean((const char *)arr, 1, nmemb);
}

inline
double	alx_gsl_stats_mean_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb])
{
	return	gsl_stats_ushort_mean(arr, 1, nmemb);
}

inline
double	alx_gsl_stats_mean_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb])
{
	return	gsl_stats_short_mean(arr, 1, nmemb);
}

inline
double	alx_gsl_stats_mean_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb])
{
	return	gsl_stats_uint_mean(arr, 1, nmemb);
}

inline
double	alx_gsl_stats_mean_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb])
{
	return	gsl_stats_int_mean(arr, 1, nmemb);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
