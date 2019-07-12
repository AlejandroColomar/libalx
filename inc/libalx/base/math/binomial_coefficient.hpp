/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/binomial_coefficient.hpp */


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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
long double alx_binomial_coefficient_ldbl	(int32_t n, int32_t k)
	    __attribute__((const));
double	alx_binomial_coefficient		(int16_t n, int16_t k)
	__attribute__((const));
float	alx_binomial_coefficient_flt		(int16_t n, int16_t k)
	__attribute__((const));
int	alx_binomial_coefficient_factorized	(int16_t n, int16_t k,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
	__attribute__((nonnull));
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
