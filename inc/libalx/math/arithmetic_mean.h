/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARITHMETIC_MEAN_H
#define ALX_MATH_ARITHMETIC_MEAN_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	AVG(a, b) (							\
{									\
	__auto_type	_a	= (a);					\
	__auto_type	_b	= (b);					\
									\
	(_a / 2) + (_b / 2) + (((_a % 2) + (_b % 2)) / 2);		\
}									\
)

#define	fAVG(a, b) (							\
{									\
	__auto_type	_a	= (a);					\
	__auto_type	_b	= (b);					\
									\
	(_a / 2.0) + (_b / 2.0);					\
}									\
)

#define	fAVGf(a, b) (							\
{									\
	__auto_type	_a	= (a);					\
	__auto_type	_b	= (b);					\
									\
	(_a + _b) / 2.0;						\
}									\
)


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
long double	alx_arithmetic_mean_ldbl(ptrdiff_t nmemb,
					const long double arr[restrict nmemb]);
double		alx_arithmetic_mean	(ptrdiff_t nmemb,
					const double arr[restrict nmemb]);
float		alx_arithmetic_mean_flt	(ptrdiff_t nmemb,
					const float arr[restrict nmemb]);
double		alx_arithmetic_mean_uint(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
double		alx_arithmetic_mean_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
double		alx_arithmetic_mean_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
double		alx_arithmetic_mean_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
double		alx_arithmetic_mean_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
double		alx_arithmetic_mean_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
double		alx_arithmetic_mean_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
double		alx_arithmetic_mean_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);
double		alx_arithmetic_mean_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb]);
double		alx_arithmetic_mean_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/arithmetic_mean.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
