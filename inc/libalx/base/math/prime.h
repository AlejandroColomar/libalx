/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/prime.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "libalx/base/stdlib/search.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	PRIME_NUMS_QTY_8b	(54)
#define	PRIME_NUMS_QTY_16b	(6542)
#define	PRIME_NUMS_QTY_32b	(203280221)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
/* extern --------------------------------------------------------------------*/
extern const	uint8_t		alx_prime_8b[PRIME_NUMS_QTY_8b];
extern		uint16_t	alx_prime_16b[PRIME_NUMS_QTY_16b];
extern		uint32_t	alx_prime_32b[PRIME_NUMS_QTY_32b];

extern		bool		alx_is_prime_32b[UINT32_MAX];
/* static const --------------------------------------------------------------*/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
void	alx_prime_16b_init	(void);
void	alx_prime_32b_init	(void);

inline
ptrdiff_t	alx_prime_index_8b	(uint8_t n)
		__attribute__((always_inline, const));
inline
ptrdiff_t	alx_prime_index_16b	(uint16_t n)
		__attribute__((always_inline, const));
inline
ptrdiff_t	alx_prime_index_32b	(uint32_t n)
		__attribute__((always_inline, const));


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
ptrdiff_t	alx_prime_index_8b	(uint8_t n)
{
	return	alx_bsearch_u8(PRIME_NUMS_QTY_8b, alx_prime_8b, n);
}

inline
ptrdiff_t	alx_prime_index_16b	(uint16_t n)
{
	return	alx_bsearch_u16(PRIME_NUMS_QTY_16b, alx_prime_16b, n);
}

inline
ptrdiff_t	alx_prime_index_32b	(uint32_t n)
{
	return	alx_bsearch_u32(PRIME_NUMS_QTY_32b, alx_prime_32b, n);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
