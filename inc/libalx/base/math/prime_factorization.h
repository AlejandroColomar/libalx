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
#include <stdint.h>

#include "libalx/base/math/prime.h"


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
int	alx_prime_factorization_s8	(int8_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8]);
int	alx_prime_factorization_u8	(uint8_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8]);
int	alx_prime_factorization_s16	(int16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);
int	alx_prime_factorization_u16	(uint16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16]);


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
