/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_PRIME_FACTORIZATION_HPP
#define ALX_MATH_PRIME_FACTORIZATION_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstdint>

#include "libalx/base/math/prime.hpp"
#include "libalx/base/stddef/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	{
	PF_NUMERATOR,
	PF_DENOMINATOR
};


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
void	alx_prime_factorization_8b_init		(void);
void	alx_prime_factorization_16b_init	(void);
int	alx_prime_factorization_8b		(uint8_t n,
				int8_t pf[static restrict PRIME_NUMS_QTY_8b],
				bool denominator);
int	alx_prime_factorization_16b		(uint16_t n,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b],
				bool denominator);
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
#endif		/* libalx/base/math/prime_factorization.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
