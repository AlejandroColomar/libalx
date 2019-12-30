/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/bsearch.hpp */


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
#define bsearch_uint(nmemb, arr, x)	alx_bsearch_uint(nmemb, arr, x)
#define bsearch_int(nmemb, arr, x)	alx_bsearch_int(nmemb, arr, x)
#define bsearch_u8(nmemb, arr, x)	alx_bsearch_u8(nmemb, arr, x)
#define bsearch_s8(nmemb, arr, x)	alx_bsearch_s8(nmemb, arr, x)
#define bsearch_u16(nmemb, arr, x)	alx_bsearch_u16(nmemb, arr, x)
#define bsearch_s16(nmemb, arr, x)	alx_bsearch_s16(nmemb, arr, x)
#define bsearch_u32(nmemb, arr, x)	alx_bsearch_u32(nmemb, arr, x)
#define bsearch_s32(nmemb, arr, x)	alx_bsearch_s32(nmemb, arr, x)
#define bsearch_u64(nmemb, arr, x)	alx_bsearch_u64(nmemb, arr, x)
#define bsearch_s64(nmemb, arr, x)	alx_bsearch_s64(nmemb, arr, x)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_uint(ptrdiff_t nmemb,
				 const unsigned *restrict arr,
				 unsigned x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_int	(ptrdiff_t nmemb,
				 const int *restrict arr,
				 int x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr,
				 uint8_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr,
				 int8_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr,
				 uint16_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr,
				 int16_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr,
				 uint32_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr,
				 int32_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_u64	(ptrdiff_t nmemb,
				 const uint64_t *restrict arr,
				 uint64_t x);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_bsearch_s64	(ptrdiff_t nmemb,
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
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
