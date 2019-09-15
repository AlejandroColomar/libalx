/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/minimum.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	ALX_MIN(a, b) (							\
{									\
	__auto_type	a_	= (a);					\
	__auto_type	b_	= (b);					\
									\
	(a_ < b_) ? a_ : b_;						\
}									\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_ldbl	(ptrdiff_t nmemb,
					const long double arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum		(ptrdiff_t nmemb,
					const double arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_f		(ptrdiff_t nmemb,
					const float arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_int		(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_u8		(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_s8		(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_u16		(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_s16		(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_u32		(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_s32		(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_u64		(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_s64		(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_minimum_pdif	(ptrdiff_t nmemb,
					const ptrdiff_t arr[restrict nmemb]);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
