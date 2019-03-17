/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_BASE_STDLIB_SEARCH_H
#define ALX_BASE_STDLIB_SEARCH_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>

#include <sys/types.h>


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
ssize_t	alx_search_uint	(ssize_t n, const unsigned arr[restrict n], unsigned x);
ssize_t	alx_search_int	(ssize_t n, const int arr[restrict n], int x);
ssize_t	alx_search_u8	(ssize_t n, const uint8_t arr[restrict n], uint8_t x);
ssize_t	alx_search_s8	(ssize_t n, const int8_t arr[restrict n], int8_t x);
ssize_t	alx_search_u16	(ssize_t n, const uint16_t arr[restrict n], uint16_t x);
ssize_t	alx_search_s16	(ssize_t n, const int16_t arr[restrict n], int16_t x);
ssize_t	alx_search_u32	(ssize_t n, const uint32_t arr[restrict n], uint32_t x);
ssize_t	alx_search_s32	(ssize_t n, const int32_t arr[restrict n], int32_t x);
ssize_t	alx_search_u64	(ssize_t n, const uint64_t arr[restrict n], uint64_t x);
ssize_t	alx_search_s64	(ssize_t n, const int64_t arr[restrict n], int64_t x);

ssize_t	alx_bsearch_uint(ssize_t n, const unsigned arr[restrict n], unsigned x);
ssize_t	alx_bsearch_int	(ssize_t n, const int arr[restrict n], int x);
ssize_t	alx_bsearch_u8	(ssize_t n, const uint8_t arr[restrict n], uint8_t x);
ssize_t	alx_bsearch_s8	(ssize_t n, const int8_t arr[restrict n], int8_t x);
ssize_t	alx_bsearch_u16	(ssize_t n, const uint16_t arr[restrict n], uint16_t x);
ssize_t	alx_bsearch_s16	(ssize_t n, const int16_t arr[restrict n], int16_t x);
ssize_t	alx_bsearch_u32	(ssize_t n, const uint32_t arr[restrict n], uint32_t x);
ssize_t	alx_bsearch_s32	(ssize_t n, const int32_t arr[restrict n], int32_t x);
ssize_t	alx_bsearch_u64	(ssize_t n, const uint64_t arr[restrict n], uint64_t x);
ssize_t	alx_bsearch_s64	(ssize_t n, const int64_t arr[restrict n], int64_t x);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdlib/search.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
