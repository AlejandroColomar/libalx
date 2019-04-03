/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_FACTORIAL_HPP
#define ALX_MATH_FACTORIAL_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

#include "libalx/base/math/prime.hpp"
#include "libalx/base/stddef/restrict.hpp"


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
extern	"C"
{
long double	alx_ldbl_factorial		(int16_t n);
double		alx_factorial			(int16_t n);
float		alx_flt_factorial		(int16_t n);
int		alx_factorial_factorized	(int16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);
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
#endif		/* libalx/base/math/factorial.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
