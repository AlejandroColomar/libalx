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
 ******* macros ***************************************************************
 ******************************************************************************/


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
