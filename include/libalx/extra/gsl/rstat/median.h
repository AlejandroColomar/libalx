/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/rstat/median.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define gsl_rstat_median_ldbl(nmemb, x)	alx_gsl_rstat_median_ldbl(nmemb, x)
#define gsl_rstat_median_flt(nmemb, x)	alx_gsl_rstat_median_flt(nmemb, x)
#define gsl_rstat_median_uint(nmemb, x)	alx_gsl_rstat_median_uint(nmemb, x)
#define gsl_rstat_median_int(nmemb, x)	alx_gsl_rstat_median_int(nmemb, x)
#define gsl_rstat_median_u8(nmemb, x)	alx_gsl_rstat_median_u8(nmemb, x)
#define gsl_rstat_median_s8(nmemb, x)	alx_gsl_rstat_median_s8(nmemb, x)
#define gsl_rstat_median_u16(nmemb, x)	alx_gsl_rstat_median_u16(nmemb, x)
#define gsl_rstat_median_s16(nmemb, x)	alx_gsl_rstat_median_s16(nmemb, x)
#define gsl_rstat_median_u32(nmemb, x)	alx_gsl_rstat_median_u32(nmemb, x)
#define gsl_rstat_median_s32(nmemb, x)	alx_gsl_rstat_median_s32(nmemb, x)
#define gsl_rstat_median_u64(nmemb, x)	alx_gsl_rstat_median_u64(nmemb, x)
#define gsl_rstat_median_s64(nmemb, x)	alx_gsl_rstat_median_s64(nmemb, x)
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
__attribute__((nonnull))
long double alx_gsl_rstat_median_ldbl(ptrdiff_t nmemb,
				 const long double x[static restrict nmemb]);
__attribute__((nonnull))
float	alx_gsl_rstat_median_flt(ptrdiff_t nmemb,
				 const float x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_uint(ptrdiff_t nmemb,
				 const unsigned x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_int(ptrdiff_t nmemb,
				 const int x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_u8	(ptrdiff_t nmemb,
				 const uint8_t x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_s8	(ptrdiff_t nmemb,
				 const int8_t x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_u16(ptrdiff_t nmemb,
				 const uint16_t x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_s16(ptrdiff_t nmemb,
				 const int16_t x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_u32(ptrdiff_t nmemb,
				 const uint32_t x[static restrict nmemb]);
__attribute__((nonnull))
double	alx_gsl_rstat_median_s32(ptrdiff_t nmemb,
				 const int32_t x[static restrict nmemb]);
__attribute__((nonnull))
long double alx_gsl_rstat_median_u64(ptrdiff_t nmemb,
				 const uint64_t x[static restrict nmemb]);
__attribute__((nonnull))
long double alx_gsl_rstat_median_s64(ptrdiff_t nmemb,
				 const int64_t x[static restrict nmemb]);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
