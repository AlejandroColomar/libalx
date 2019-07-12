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


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
long double alx_gsl_rstat_median_ldbl(ptrdiff_t nmemb,
				const long double x[static restrict nmemb]);
float	alx_gsl_rstat_median_flt(ptrdiff_t nmemb,
				const float x[static restrict nmemb]);
double	alx_gsl_rstat_median_uint(ptrdiff_t nmemb,
				const unsigned x[static restrict nmemb]);
double	alx_gsl_rstat_median_int(ptrdiff_t nmemb,
				const int x[static restrict nmemb]);
double	alx_gsl_rstat_median_u8	(ptrdiff_t nmemb,
				const uint8_t x[static restrict nmemb]);
double	alx_gsl_rstat_median_s8	(ptrdiff_t nmemb,
				const int8_t x[static restrict nmemb]);
double	alx_gsl_rstat_median_u16(ptrdiff_t nmemb,
				const uint16_t x[static restrict nmemb]);
double	alx_gsl_rstat_median_s16(ptrdiff_t nmemb,
				const int16_t x[static restrict nmemb]);
double	alx_gsl_rstat_median_u32(ptrdiff_t nmemb,
				const uint32_t x[static restrict nmemb]);
double	alx_gsl_rstat_median_s32(ptrdiff_t nmemb,
				const int32_t x[static restrict nmemb]);
long double alx_gsl_rstat_median_u64(ptrdiff_t nmemb,
				const uint64_t x[static restrict nmemb]);
long double alx_gsl_rstat_median_s64(ptrdiff_t nmemb,
				const int64_t x[static restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
