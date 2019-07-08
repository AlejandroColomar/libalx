/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_SUM_HPP
#define ALX_MATH_ARRAY_SUM_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/stddef/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr)
		__attribute__((nonnull, pure));
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr)
		__attribute__((nonnull, pure));

double	dbl_array_sum		(ptrdiff_t nmemb,
				 const double *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr)
	__attribute__((nonnull, pure));
double	dbl_array_sum_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr)
	__attribute__((nonnull, pure));

float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				 const float *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
	__attribute__((nonnull, pure));
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
	__attribute__((nonnull, pure));

unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr)
		__attribute__((nonnull, pure));
int		alx_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr)
		__attribute__((nonnull, pure));
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr)
		__attribute__((nonnull, pure));
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr)
		__attribute__((nonnull, pure));
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr)
		__attribute__((nonnull, pure));
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr)
		__attribute__((nonnull, pure));
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr)
		__attribute__((nonnull, pure));
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr)
		__attribute__((nonnull, pure));
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr)
		__attribute__((nonnull, pure));
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr)
		__attribute__((nonnull, pure));
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/array_sum.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
