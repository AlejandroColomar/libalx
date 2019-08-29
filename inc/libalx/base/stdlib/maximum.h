/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/maximum.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	ALX_MAX(a, b) (							\
{									\
	__auto_type	a_	= (a);					\
	__auto_type	b_	= (b);					\
									\
	(a_ > b_) ? a_ : b_;						\
}									\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_ldbl(ptrdiff_t nmemb,
				 const long double arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum	(ptrdiff_t nmemb,
				 const double arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_f	(ptrdiff_t nmemb,
				 const float arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_uint(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb]);
__attribute__((nonnull, pure))
ptrdiff_t	alx_maximum_pdif(ptrdiff_t nmemb,
				 const ptrdiff_t arr[static restrict nmemb]);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
