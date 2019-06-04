/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime_factorization.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "libalx/base/math/prime.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Prime_Factorization {
	PF_FACTOR,
	PF_NEXT,

	PF_LUT
};


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
/* global --------------------------------------------------------------------*/
	int8_t	alx_factors_8b [UINT8_MAX][PF_LUT];
	int16_t	alx_factors_16b [UINT16_MAX][PF_LUT];
/* static --------------------------------------------------------------------*/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	alx_prime_factorization_8b_init		(void)
{
	ptrdiff_t	tmp;

	alx_factors_8b[0][PF_FACTOR]	= -1;
	alx_factors_8b[0][PF_NEXT]	= 0;
	alx_factors_8b[1][PF_FACTOR]	= -1;
	alx_factors_8b[1][PF_NEXT]	= 0;

	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_8b; i++) {
		tmp	= alx_prime_8b[i];
		for (ptrdiff_t j = tmp; j < UINT8_MAX; j += tmp) {
			if (!alx_factors_8b[j][PF_NEXT]  &&  !(j % tmp)) {
				alx_factors_8b[j][PF_FACTOR]	= i;
				alx_factors_8b[j][PF_NEXT]	= j / tmp;
			}
		}
	}
}

void	alx_prime_factorization_16b_init	(void)
{
	ptrdiff_t	tmp;

	alx_factors_16b[0][PF_FACTOR]	= -1;
	alx_factors_16b[0][PF_NEXT]	= 0;
	alx_factors_16b[1][PF_FACTOR]	= -1;
	alx_factors_16b[1][PF_NEXT]	= 0;

	for (ptrdiff_t i = 0; i < PRIME_NUMS_QTY_16b; i++) {
		tmp	= alx_prime_16b[i];
		for (ptrdiff_t j = tmp; j < UINT16_MAX; j += tmp) {
			if (!alx_factors_16b[j][PF_NEXT]  &&  !(j % tmp)) {
				alx_factors_16b[j][PF_FACTOR]	= i;
				alx_factors_16b[j][PF_NEXT]	= j / tmp;
			}
		}
	}
}

int	alx_prime_factorization_8b		(uint8_t n,
				int8_t pf[static restrict PRIME_NUMS_QTY_8b])
{

	if (!n) {
		errno	= EDOM;
		return	-EDOM;
	}

	memset(pf, 0, sizeof(pf[0]) * PRIME_NUMS_QTY_8b);
	if (n == 1)
		return	0;

	if (!alx_factors_8b[(3)][PF_FACTOR])
		alx_prime_factorization_8b_init();

	do {
		pf[alx_factors_8b[n][PF_FACTOR]]++;
		n	= alx_factors_8b[n][PF_NEXT];
	} while (n > 1);

	return	0;
}

int	alx_prime_factorization_16b		(uint16_t n,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{

	if (!n) {
		errno	= EDOM;
		return	-EDOM;
	}

	memset(pf, 0, sizeof(pf[0]) * PRIME_NUMS_QTY_16b);
	if (n == 1)
		return	0;

	if (!alx_prime_16b[0])
		alx_prime_16b_init();
	if (!alx_factors_16b[(3)][PF_FACTOR])
		alx_prime_factorization_16b_init();

	do {
		pf[alx_factors_16b[n][PF_FACTOR]]++;
		n	= alx_factors_16b[n][PF_NEXT];
	} while (n > 1);

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
