/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/search.hpp */


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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr,
				 unsigned x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_int	(ptrdiff_t nmemb,
				 const int *restrict arr,
				 int x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr,
				 uint8_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr,
				 int8_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr,
				 uint16_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr,
				 int16_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr,
				 uint32_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr,
				 int32_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_u64	(ptrdiff_t nmemb,
				 const uint64_t *restrict arr,
				 uint64_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_search_s64	(ptrdiff_t nmemb,
				 const int64_t *restrict arr,
				 int64_t x);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
