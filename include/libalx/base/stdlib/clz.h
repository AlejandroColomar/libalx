/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/clz.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <limits.h>
#include <stdint.h>

#include "libalx/base/assert/assert.h"
#include "libalx/base/stdint/types.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_stdint_types();


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
__attribute__((const))
inline
uint8_t		alx_clz_u8	(uint8_t n);
__attribute__((const))
inline
uint16_t	alx_clz_u16	(uint16_t n);
__attribute__((const))
inline
uint32_t	alx_clz_u32	(uint32_t n);
__attribute__((const))
inline
uint64_t	alx_clz_u64	(uint64_t n);
__attribute__((const))
#if defined(uint128_t)
__attribute__((const))
inline
uint64_t	alx_clz_u128	(uint128_t n);
#endif
#if defined(uint256_t)
__attribute__((const))
inline
uint64_t	alx_clz_u256	(uint256_t n);
#endif


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u8		(uint8_t n)
{
	return	alx_clz_u8(n);
}

__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u16		(uint16_t n)
{
	return	alx_clz_u16(n);
}

__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u32		(uint32_t n)
{
	return	alx_clz_u32(n);
}

__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u64		(uint64_t n)
{
	return	alx_clz_u64(n);
}

# if defined(uint128_t)
__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u128	(uint128_t n)
{
	return	alx_clz_u128(n);
}
# endif

# if defined(uint256_t)
__attribute__((always_inline, const))
inline
ptrdiff_t	clz_u256	(uint256_t n)
{
	return	alx_clz_u256(n);
}
# endif
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
uint8_t		alx_clz_u8	(uint8_t n)
{
	static const uint8_t unused_bytes = sizeof(unsigned) - sizeof(uint8_t);
	static const uint8_t unused_bits = unused_bytes * CHAR_BIT;

	return	__builtin_clz(n) - unused_bits;
}

inline
uint16_t	alx_clz_u16	(uint16_t n)
{
	static const uint8_t unused_bytes = sizeof(unsigned) - sizeof(uint16_t);
	static const uint8_t unused_bits = unused_bytes * CHAR_BIT;

	return	__builtin_clz(n) - unused_bits;
}

inline
uint32_t	alx_clz_u32	(uint32_t n)
{

	return	__builtin_clz(n);
}

inline
uint64_t	alx_clz_u64	(uint64_t n)
{

	return	__builtin_clzl(n);
}

#if defined(uint128_t)
inline
uint64_t	alx_clz_u128	(uint128_t n)
{

	if (!(uint64_t)(n >> 64))
		return	64 + alx_clz_u64(n);
	return	alx_clz_u64(n >> 64);
}
#endif

#if defined(uint256_t)
inline
uint64_t	alx_clz_u256	(uint256_t n)
{

	if (!(uint128_t)(n >> 128))
		return	128 + alx_clz_u128(n);
	return	alx_clz_u128(n >> 128);
}
#endif


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
