/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/ctz.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
uint8_t		alx_ctz_u8	(uint8_t n);
__attribute__((const))
inline
uint16_t	alx_ctz_u16	(uint16_t n);
__attribute__((const))
inline
uint32_t	alx_ctz_u32	(uint32_t n);
__attribute__((const))
inline
uint64_t	alx_ctz_u64	(uint64_t n);
__attribute__((const))
#if defined(uint128_t)
__attribute__((const))
inline
uint64_t	alx_ctz_u128	(uint128_t n);
#endif
#if defined(uint256_t)
__attribute__((const))
inline
uint64_t	alx_ctz_u256	(uint256_t n);
#endif


/******************************************************************************
 ******* static inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u8		(uint8_t n)
{
	return	alx_ctz_u8(n);
}

__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u16		(uint16_t n)
{
	return	alx_ctz_u16(n);
}

__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u32		(uint32_t n)
{
	return	alx_ctz_u32(n);
}

__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u64		(uint64_t n)
{
	return	alx_ctz_u64(n);
}

# if defined(uint128_t)
__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u128	(uint128_t n)
{
	return	alx_ctz_u128(n);
}
# endif

# if defined(uint256_t)
__attribute__((always_inline, const))
static inline
ptrdiff_t	ctz_u256	(uint256_t n)
{
	return	alx_ctz_u256(n);
}
# endif
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
uint8_t		alx_ctz_u8	(uint8_t n)
{

	return	__builtin_ctz(n);
}

inline
uint16_t	alx_ctz_u16	(uint16_t n)
{

	return	__builtin_ctz(n);
}

inline
uint32_t	alx_ctz_u32	(uint32_t n)
{

	return	__builtin_ctz(n);
}

inline
uint64_t	alx_ctz_u64	(uint64_t n)
{

	return	__builtin_ctzl(n);
}

#if defined(uint128_t)
inline
uint64_t	alx_ctz_u128	(uint128_t n)
{

	if (!(uint64_t)n)
		return	64 + alx_ctz_u64(n >> 64);
	return	alx_ctz_u64(n);
}
#endif

#if defined(uint256_t)
inline
uint64_t	alx_ctz_u256	(uint256_t n)
{

	if (!(uint128_t)n)
		return	128 + alx_ctz_u128(n >> 128);
	return	alx_ctz_u128(n);
}
#endif


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
