/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_PRIME_FACTORIZATION_H
#define ALX_MATH_PRIME_FACTORIZATION_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#include "libalx/base/math/prime.h"


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
void	alx_prime_factorization_8b_init		(void);
void	alx_prime_factorization_16b_init	(void);
int	alx_prime_factorization_8b		(uint8_t n,
				int8_t pf[static restrict PRIME_NUMS_QTY_8b],
				bool denominator);
int	alx_prime_factorization_16b		(uint16_t n,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b],
				bool denominator);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/prime_factorization.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
