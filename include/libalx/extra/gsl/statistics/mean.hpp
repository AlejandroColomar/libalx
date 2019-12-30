/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/statistics/mean.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_stats_mean_ldbl(ptrdiff_t nmemb,
				 const long double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
float	alx_gsl_stats_mean_flt	(ptrdiff_t nmemb,
				 const float *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_stats_mean_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_stats_mean_u64(ptrdiff_t nmemb,
				 const uint64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_stats_mean_s64(ptrdiff_t nmemb,
				 const int64_t *restrict arr);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gsl {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gsl */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
