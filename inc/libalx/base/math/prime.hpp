/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_PRIME_HPP
#define ALX_MATH_PRIME_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/stdlib/search.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	PRIME_NUMS_QTY_8b	(54)
#define	PRIME_NUMS_QTY_16b	(6542)
#define	PRIME_NUMBERS_QTY_32b	(203280221)


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
extern const	uint8_t		alx_prime_8b [PRIME_NUMS_QTY_8b];
extern		uint16_t	alx_prime_16b [PRIME_NUMS_QTY_16b];
/* static const --------------------------------------------------------------*/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
extern	"C"
{
void	alx_prime_16b_init	(void);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	ptrdiff_t	alx_prime_index_8b	(uint8_t n);
static inline	ptrdiff_t	alx_prime_index_16b	(uint16_t n);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
ptrdiff_t	alx_prime_index_8b	(uint8_t n)
{
	return	alx_bsearch_u8(PRIME_NUMS_QTY_8b, alx_prime_8b, n);
}

static inline
ptrdiff_t	alx_prime_index_16b	(uint16_t n)
{
	return	alx_bsearch_u16(PRIME_NUMS_QTY_16b, alx_prime_16b, n);
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/prime.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
