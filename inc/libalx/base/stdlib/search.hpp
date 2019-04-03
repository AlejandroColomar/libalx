/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDLIB_SEARCH_HPP
#define ALX_STDLIB_SEARCH_HPP


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
ptrdiff_t	alx_search_uint	(ptrdiff_t nmemb,
				const unsigned *restrict arr,
				unsigned x);
ptrdiff_t	alx_search_int	(ptrdiff_t nmemb,
				const int *restrict arr,
				int x);
ptrdiff_t	alx_search_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr,
				uint8_t x);
ptrdiff_t	alx_search_s8	(ptrdiff_t nmemb,
				const int8_t *restrict arr,
				int8_t x);
ptrdiff_t	alx_search_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr,
				uint16_t x);
ptrdiff_t	alx_search_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr,
				int16_t x);
ptrdiff_t	alx_search_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr,
				uint32_t x);
ptrdiff_t	alx_search_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr,
				int32_t x);
ptrdiff_t	alx_search_u64	(ptrdiff_t nmemb,
				const uint64_t *restrict arr,
				uint64_t x);
ptrdiff_t	alx_search_s64	(ptrdiff_t nmemb,
				const int64_t *restrict arr,
				int64_t x);

ptrdiff_t	alx_bsearch_uint(ptrdiff_t nmemb,
				const unsigned *restrict arr,
				unsigned x);
ptrdiff_t	alx_bsearch_int	(ptrdiff_t nmemb,
				const int *restrict arr,
				int x);
ptrdiff_t	alx_bsearch_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr,
				uint8_t x);
ptrdiff_t	alx_bsearch_s8	(ptrdiff_t nmemb,
				const int8_t *restrict arr,
				int8_t x);
ptrdiff_t	alx_bsearch_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr,
				uint16_t x);
ptrdiff_t	alx_bsearch_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr,
				int16_t x);
ptrdiff_t	alx_bsearch_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr,
				uint32_t x);
ptrdiff_t	alx_bsearch_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr,
				int32_t x);
ptrdiff_t	alx_bsearch_u64	(ptrdiff_t nmemb,
				const uint64_t *restrict arr,
				uint64_t x);
ptrdiff_t	alx_bsearch_s64	(ptrdiff_t nmemb,
				const int64_t *restrict arr,
				int64_t x);
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
#endif		/* libalx/base/stdlib/search.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
