/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/rstat/median.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


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
extern	"C"
{
long double alx_gsl_rstat_median_ldbl	(ptrdiff_t nmemb,
					const long double *restrict x);
float	alx_gsl_rstat_median_flt	(ptrdiff_t nmemb,
					const float *restrict x);
double	alx_gsl_rstat_median_uint	(ptrdiff_t nmemb,
					const unsigned *restrict x);
double	alx_gsl_rstat_median_int	(ptrdiff_t nmemb,
					const int *restrict x);
double	alx_gsl_rstat_median_u8		(ptrdiff_t nmemb,
					const uint8_t *restrict x);
double	alx_gsl_rstat_median_s8		(ptrdiff_t nmemb,
					const int8_t *restrict x);
double	alx_gsl_rstat_median_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict x);
double	alx_gsl_rstat_median_s16	(ptrdiff_t nmemb,
					const int16_t *restrict x);
double	alx_gsl_rstat_median_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict x);
double	alx_gsl_rstat_median_s32	(ptrdiff_t nmemb,
					const int32_t *restrict x);
long double alx_gsl_rstat_median_u64	(ptrdiff_t nmemb,
					const uint64_t *restrict x);
long double alx_gsl_rstat_median_s64	(ptrdiff_t nmemb,
					const int64_t *restrict x);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
