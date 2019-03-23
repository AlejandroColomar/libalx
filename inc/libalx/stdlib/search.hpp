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
ptrdiff_t alx_search_uint(ptrdiff_t n, const unsigned arr[restrict], unsigned x);
ptrdiff_t alx_search_int(ptrdiff_t n, const int arr[restrict], int x);
ptrdiff_t alx_search_u8	(ptrdiff_t n, const uint8_t arr[restrict], uint8_t x);
ptrdiff_t alx_search_s8	(ptrdiff_t n, const int8_t arr[restrict], int8_t x);
ptrdiff_t alx_search_u16(ptrdiff_t n, const uint16_t arr[restrict], uint16_t x);
ptrdiff_t alx_search_s16(ptrdiff_t n, const int16_t arr[restrict], int16_t x);
ptrdiff_t alx_search_u32(ptrdiff_t n, const uint32_t arr[restrict], uint32_t x);
ptrdiff_t alx_search_s32(ptrdiff_t n, const int32_t arr[restrict], int32_t x);
ptrdiff_t alx_search_u64(ptrdiff_t n, const uint64_t arr[restrict], uint64_t x);
ptrdiff_t alx_search_s64(ptrdiff_t n, const int64_t arr[restrict], int64_t x);

ptrdiff_t alx_bsearch_uint(ptrdiff_t n, const unsigned arr[restrict], unsigned x);
ptrdiff_t alx_bsearch_int(ptrdiff_t n, const int arr[restrict], int x);
ptrdiff_t alx_bsearch_u8(ptrdiff_t n, const uint8_t arr[restrict], uint8_t x);
ptrdiff_t alx_bsearch_s8(ptrdiff_t n, const int8_t arr[restrict], int8_t x);
ptrdiff_t alx_bsearch_u16(ptrdiff_t n, const uint16_t arr[restrict], uint16_t x);
ptrdiff_t alx_bsearch_s16(ptrdiff_t n, const int16_t arr[restrict], int16_t x);
ptrdiff_t alx_bsearch_u32(ptrdiff_t n, const uint32_t arr[restrict], uint32_t x);
ptrdiff_t alx_bsearch_s32(ptrdiff_t n, const int32_t arr[restrict], int32_t x);
ptrdiff_t alx_bsearch_u64(ptrdiff_t n, const uint64_t arr[restrict], uint64_t x);
ptrdiff_t alx_bsearch_s64(ptrdiff_t n, const int64_t arr[restrict], int64_t x);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/stdlib/search.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
