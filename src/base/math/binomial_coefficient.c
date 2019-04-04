/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/binomial_coefficient.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "libalx/base/math/pascal_triangle.h"
#include "libalx/base/math/prime.h"
#include "libalx/base/math/prime_defactorization.h"
#include "libalx/base/stddef/size.h"


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
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_ldbl_binomial_coefficient		(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	if (alx_binomial_coefficient_factorized(n, k, &pf))
		return	nanl("");

	return	alx_ldbl_prime_defactorization_s16((const int16_t (*)[])&pf);
}

double		alx_binomial_coefficient		(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nan("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	if (alx_binomial_coefficient_factorized(n, k, &pf))
		return	nan("");

	return	alx_prime_defactorization_s16((const int16_t (*)[])&pf);
}

float		alx_flt_binomial_coefficient		(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	nanf("");
	}
	if (k > n)
		return	0;
	if ((n == k) || (!k))
		return	1;
	if (k == 1)
		return	n;

	if (alx_binomial_coefficient_factorized(n, k, &pf))
		return	nanf("");

	return	alx_flt_prime_defactorization_s16((const int16_t (*)[])&pf);
}

int		alx_binomial_coefficient_factorized	(int16_t n, int16_t k,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	-EDOM;
	}

	memset(pf, 0, sizeof(*pf));

	if (k > n) {
		errno	= EDOM;
		return	-EDOM;
	}
	if ((n == k) || (!k))
		return	0;

	return	alx_pascal_triangle_factorized(n, k, pf);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
