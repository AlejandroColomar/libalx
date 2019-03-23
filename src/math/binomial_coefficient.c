/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/binomial_coefficient.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "libalx/math/matrix_addition.h"
#include "libalx/math/matrix_subtraction.h"
#include "libalx/math/prime.h"
#include "libalx/math/prime_defactorization.h"
#include "libalx/math/prime_factorization.h"
#include "libalx/stddef/size.h"


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
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

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

	alx_binomial_coefficient_factorized(n, k, &pf);

	return	alx_ldbl_prime_defactorization_s16((const int8_t (*)[])&pf);
}

double		alx_binomial_coefficient		(int16_t n, int16_t k)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

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

	alx_binomial_coefficient_factorized(n, k, &pf);

	return	alx_prime_defactorization_s16((const int8_t (*)[])&pf);
}

float		alx_flt_binomial_coefficient		(int16_t n, int16_t k)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

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

	alx_binomial_coefficient_factorized(n, k, &pf);

	return	alx_flt_prime_defactorization_s16((const int8_t (*)[])&pf);
}

int		alx_binomial_coefficient_factorized	(int16_t n, int16_t k,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	int_fast16_t	m;
	int_fast16_t	j;
	int8_t		tmp[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	-2;
	}

	m	= n;
	j	= 1;
	memset(pf, 0, sizeof(*pf));

	if (k > n) {
		errno	= EDOM;
		return	-1;
	}
	if ((n == k) || (!k))
		return	0;

	do {
		alx_prime_factorization_s16(j++, &tmp);
		alx_matrix_subtraction_s8(ARRAY_SIZE(*pf), *pf, *pf, tmp);
		alx_prime_factorization_s16(m--, &tmp);
		alx_matrix_addition_s8(ARRAY_SIZE(*pf), *pf, *pf, tmp);
	} while (j < k);

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
