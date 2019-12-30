/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/bsearch.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


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
ptrdiff_t	alx_bsearch_uint(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x);
__attribute__((nonnull, pure))
ptrdiff_t	alx_bsearch_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x)
{
	return	alx_bsearch_uint(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x)
{
	return	alx_bsearch_int(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x)
{
	return	alx_bsearch_u8(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x)
{
	return	alx_bsearch_s8(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x)
{
	return	alx_bsearch_u16(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x)
{
	return	alx_bsearch_s16(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x)
{
	return	alx_bsearch_u32(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x)
{
	return	alx_bsearch_s32(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x)
{
	return	alx_bsearch_u64(nmemb, arr, x);
}

__attribute__((always_inline, nonnull, pure))
inline
ptrdiff_t	bsearch_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x)
{
	return	alx_bsearch_s64(nmemb, arr, x);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
