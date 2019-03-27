/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_MEDIAN_H
#define ALX_MATH_MEDIAN_H


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
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
long double	alx_median_ldbl	(ptrdiff_t nmemb,
				const long double x[restrict nmemb]);
double		alx_median	(ptrdiff_t nmemb,
				const double x[restrict nmemb]);
float		alx_median_flt	(ptrdiff_t nmemb,
				const float x[restrict nmemb]);
double		alx_median_uint	(ptrdiff_t nmemb,
				const unsigned x[restrict nmemb]);
double		alx_median_int	(ptrdiff_t nmemb,
				const int x[restrict nmemb]);
double		alx_median_u8	(ptrdiff_t nmemb,
				const uint8_t x[restrict nmemb]);
double		alx_median_s8	(ptrdiff_t nmemb,
				const int8_t x[restrict nmemb]);
double		alx_median_u16	(ptrdiff_t nmemb,
				const uint16_t x[restrict nmemb]);
double		alx_median_s16	(ptrdiff_t nmemb,
				const int16_t x[restrict nmemb]);
double		alx_median_u32	(ptrdiff_t nmemb,
				const uint32_t x[restrict nmemb]);
double		alx_median_s32	(ptrdiff_t nmemb,
				const int32_t x[restrict nmemb]);
double		alx_median_u64	(ptrdiff_t nmemb,
				const uint64_t x[restrict nmemb]);
double		alx_median_s64	(ptrdiff_t nmemb,
				const int64_t x[restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/median.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/