/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/search.h */


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
#define search_uint(nmemb, arr, x)	alx_search_uint(nmemb, arr, x)
#define search_int(nmemb, arr, x)	alx_search_int(nmemb, arr, x)
#define search_u8(nmemb, arr, x)	alx_search_u8(nmemb, arr, x)
#define search_s8(nmemb, arr, x)	alx_search_s8(nmemb, arr, x)
#define search_u16(nmemb, arr, x)	alx_search_u16(nmemb, arr, x)
#define search_s16(nmemb, arr, x)	alx_search_s16(nmemb, arr, x)
#define search_u32(nmemb, arr, x)	alx_search_u32(nmemb, arr, x)
#define search_s32(nmemb, arr, x)	alx_search_s32(nmemb, arr, x)
#define search_u64(nmemb, arr, x)	alx_search_u64(nmemb, arr, x)
#define search_s64(nmemb, arr, x)	alx_search_s64(nmemb, arr, x)
#endif


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
ptrdiff_t	alx_search_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_search_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
