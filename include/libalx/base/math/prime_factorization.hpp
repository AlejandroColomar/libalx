/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/prime_factorization.hpp */


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
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
void	alx_prime_factorization_8b_init		(void);
void	alx_prime_factorization_16b_init	(void);

[[gnu::nonnull]]
int	alx_prime_factorization_8b(uint8_t n,
				int8_t pf[static restrict PRIME_NUMS_QTY_8b],
				bool denominator);
[[gnu::nonnull]]
int	alx_prime_factorization_16b(uint16_t n,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b],
				bool denominator);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	{
	PF_NUMERATOR,
	PF_DENOMINATOR
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
