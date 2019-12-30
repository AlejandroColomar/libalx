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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_rstat_median_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict x);
[[gnu::nonnull]][[gnu::pure]]
float	alx_gsl_rstat_median_flt	(ptrdiff_t nmemb,
					 const float *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_int	(ptrdiff_t nmemb,
					 const int *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_u8		(ptrdiff_t nmemb,
					 const uint8_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_s8		(ptrdiff_t nmemb,
					 const int8_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
double	alx_gsl_rstat_median_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_rstat_median_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict x);
[[gnu::nonnull]][[gnu::pure]]
long double alx_gsl_rstat_median_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict x);
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
