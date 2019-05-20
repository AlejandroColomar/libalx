/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDLIB_POPCNT_HPP
#define ALX_STDLIB_POPCNT_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

#include <immintrin.h>
#include <nmmintrin.h>

#include "libalx/base/stdint/types.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/
#if defined(uint128_t)
union	Uint128 {
	uint128_t	uu128;
	uint64_t	uu64[2];
};
#endif

#if defined(uint256_t)
union	Uint256 {
	uint256_t	uu256;
	uint64_t	uu64[4];
};
#endif


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	uint8_t		popcnt_u8	(uint8_t n);
static inline	uint16_t	popcnt_u16	(uint16_t n);
static inline	uint32_t	popcnt_u32	(uint32_t n);
static inline	uint64_t	popcnt_u64	(uint32_t n);
#if defined(uint128_t)
static inline	uint64_t	popcnt_u128	(uint128_t n);
#endif
#if defined(uint256_t)
static inline	uint64_t	popcnt_u256	(uint256_t n);
#endif


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline	uint8_t		popcnt_u8	(uint8_t n)
{

	return	_mm_popcnt_u64(n);
}

static inline	uint16_t	popcnt_u16	(uint16_t n)
{

	return	_mm_popcnt_u64(n);
}

static inline	uint32_t	popcnt_u32	(uint32_t n)
{

	return	_mm_popcnt_u64(n);
}

static inline	uint64_t	popcnt_u64	(uint32_t n)
{

	return	_mm_popcnt_u64(n);
}

#if defined(uint128_t)
static inline	uint64_t	popcnt_u128	(uint128_t n)
{
	const	union Uint128	n_u	= {.uu128 = n};
	const	uint_fast64_t	cnt_a	= _mm_popcnt_u64(n_u.uu64[0]);
	const	uint_fast64_t	cnt_b	= _mm_popcnt_u64(n_u.uu64[1]);
	const	uint_fast64_t	cnt	= cnt_a + cnt_b;

	return	cnt;
}
#endif

#if defined(uint256_t)
static inline	uint64_t	popcnt_u256	(uint256_t n)
{
	const	union Uint256	n_u	= {.uu256 = n};
	const	uint_fast64_t	cnt_a	= _mm_popcnt_u64(n_u.uu64[0]);
	const	uint_fast64_t	cnt_b	= _mm_popcnt_u64(n_u.uu64[1]);
	const	uint_fast64_t	cnt_c	= _mm_popcnt_u64(n_u.uu64[2]);
	const	uint_fast64_t	cnt_d	= _mm_popcnt_u64(n_u.uu64[3]);
	const	uint_fast64_t	cnt	= cnt_a + cnt_b + cnt_c + cnt_d;

	return	cnt;
}
#endif


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdlib/popcnt.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
