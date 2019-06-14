/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_GSL_STATS_MEAN_H
#define ALX_GSL_STATS_MEAN_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>

#include <gsl/gsl_statistics_uchar.h>
#include <gsl/gsl_statistics_ushort.h>
#include <gsl/gsl_statistics_short.h>
#include <gsl/gsl_statistics_uint.h>
#include <gsl/gsl_statistics_int.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
long double alx_stats_mean_ldbl	(ptrdiff_t nmemb,
				const long double arr[static restrict nmemb]);
float	alx_stats_mean_flt	(ptrdiff_t nmemb,
				const float arr[static restrict nmemb]);
double	alx_stats_mean_s8	(ptrdiff_t nmemb,
				const int8_t arr[static restrict nmemb]);
long double alx_stats_mean_u64	(ptrdiff_t nmemb,
				const uint64_t arr[static restrict nmemb]);
long double alx_stats_mean_s64	(ptrdiff_t nmemb,
				const int64_t arr[static restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline
double	alx_stats_mean_u8	(ptrdiff_t nmemb,
				const uint8_t arr[static restrict nmemb]);
static inline
double	alx_stats_mean_u16	(ptrdiff_t nmemb,
				const uint16_t arr[static restrict nmemb]);
static inline
double	alx_stats_mean_s16	(ptrdiff_t nmemb,
				const int16_t arr[static restrict nmemb]);
static inline
double	alx_stats_mean_u32	(ptrdiff_t nmemb,
				const uint32_t arr[static restrict nmemb]);
static inline
double	alx_stats_mean_s32	(ptrdiff_t nmemb,
				const int32_t arr[static restrict nmemb]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
double	alx_stats_mean_u8	(ptrdiff_t nmemb,
				const uint8_t arr[static restrict nmemb])
{
	return	gsl_stats_uchar_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_u16	(ptrdiff_t nmemb,
				const uint16_t arr[static restrict nmemb])
{
	return	gsl_stats_ushort_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_s16	(ptrdiff_t nmemb,
				const int16_t arr[static restrict nmemb])
{
	return	gsl_stats_short_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_u32	(ptrdiff_t nmemb,
				const uint32_t arr[static restrict nmemb])
{
	return	gsl_stats_uint_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_s32	(ptrdiff_t nmemb,
				const int32_t arr[static restrict nmemb])
{
	return	gsl_stats_int_mean(arr, 1, nmemb);
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/extra/gsl/statistics/mean.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
