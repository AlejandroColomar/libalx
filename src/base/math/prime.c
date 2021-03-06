/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime.h"

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdlib/search.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
/* global --------------------------------------------------------------------*/
const	uint8_t		alx_prime_8b [PRIME_NUMS_QTY_8b] = {
		2, 3, 5, 7, 11,			13, 17, 19, 23, 29,
		31, 37, 41, 43, 47,		53, 59, 61, 67, 71,
		73, 79, 83, 89, 97,		101, 103, 107, 109, 113,
		127, 131, 137, 139, 149,	151, 157, 163, 167, 173,
		179, 181, 191, 193, 197,	199, 211, 223, 227, 229,
		233, 239, 241, 251
	};
	uint16_t	alx_prime_16b [PRIME_NUMS_QTY_16b];
/* static --------------------------------------------------------------------*/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static bool	is_prime_16b	(uint_fast16_t n);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx_prime_16b_init	(void)
{
	ptrdiff_t	i;

	i	= 0;
	alx_prime_16b[i++]	= 2;
	alx_prime_16b[i++]	= 3;
	alx_prime_16b[i++]	= 5;

	for (uint_fast32_t n = 7; n < UINT16_MAX; n++) {
		if (is_prime_16b(n))
			alx_prime_16b[i++]	= n;
	}
}



/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static bool	is_prime_16b	(uint_fast16_t n)
{
	uint_fast16_t	sqrt_n;

	sqrt_n	= sqrt(n) + 1;

	for (ptrdiff_t i = 0; (alx_prime_16b[i] <= sqrt_n) &&
					(i < PRIME_NUMS_QTY_16b); i++) {
		if (!(n % alx_prime_16b[i]))
			return	false;
	}

	return	true;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
