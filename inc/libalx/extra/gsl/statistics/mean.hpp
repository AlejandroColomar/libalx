/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_GSL_STATS_MEAN_HPP
#define ALX_GSL_STATS_MEAN_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include <gsl/gsl_statistics_uchar.h>
#include <gsl/gsl_statistics_ushort.h>
#include <gsl/gsl_statistics_short.h>
#include <gsl/gsl_statistics_uint.h>
#include <gsl/gsl_statistics_int.h>

#include "libalx/base/stddef/restrict.hpp"


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
extern	"C"
{
long double alx_stats_mean_ldbl	(ptrdiff_t nmemb,
				const long double *restrict arr);
float	alx_stats_mean_flt	(ptrdiff_t nmemb,
				const float *restrict arr);
double	alx_stats_mean_s8	(ptrdiff_t nmemb,
				const int8_t *restrict arr);
long double alx_stats_mean_u64	(ptrdiff_t nmemb,
				const uint64_t *restrict arr);
long double alx_stats_mean_s64	(ptrdiff_t nmemb,
				const int64_t *restrict arr);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline
double	alx_stats_mean_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr);
static inline
double	alx_stats_mean_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr);
static inline
double	alx_stats_mean_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr);
static inline
double	alx_stats_mean_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr);
static inline
double	alx_stats_mean_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
double	alx_stats_mean_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr)
{
	return	gsl_stats_uchar_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr)
{
	return	gsl_stats_ushort_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr)
{
	return	gsl_stats_short_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr)
{
	return	gsl_stats_uint_mean(arr, 1, nmemb);
}

static inline
double	alx_stats_mean_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr)
{
	return	gsl_stats_int_mean(arr, 1, nmemb);
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/extra/gsl/statistics/mean.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
