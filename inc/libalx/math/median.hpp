/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_MEDIAN_HPP
#define ALX_MATH_MEDIAN_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>


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
long double	alx_median_ldbl	(ptrdiff_t n, const long double x[restrict]);
double		alx_median	(ptrdiff_t n, const double x[restrict]);
float		alx_median_flt	(ptrdiff_t n, const float x[restrict]);
double		alx_median_uint	(ptrdiff_t n, const unsigned x[restrict]);
double		alx_median_int	(ptrdiff_t n, const int x[restrict]);
double		alx_median_u8	(ptrdiff_t n, const uint8_t x[restrict]);
double		alx_median_s8	(ptrdiff_t n, const int8_t x[restrict]);
double		alx_median_u16	(ptrdiff_t n, const uint16_t x[restrict]);
double		alx_median_s16	(ptrdiff_t n, const int16_t x[restrict]);
double		alx_median_u32	(ptrdiff_t n, const uint32_t x[restrict]);
double		alx_median_s32	(ptrdiff_t n, const int32_t x[restrict]);
double		alx_median_u64	(ptrdiff_t n, const uint64_t x[restrict]);
double		alx_median_s64	(ptrdiff_t n, const int64_t x[restrict]);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/median.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
