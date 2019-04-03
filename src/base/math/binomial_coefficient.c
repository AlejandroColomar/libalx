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

#include "libalx/base/math/matrix_addition.h"
#include "libalx/base/math/matrix_subtraction.h"
#include "libalx/base/math/prime.h"
#include "libalx/base/math/prime_defactorization.h"
#include "libalx/base/math/prime_factorization.h"
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

#include <inttypes.h>
#include <stdio.h>
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


for (int i = 0; i < 20; i++)
printf("pf_%i = %"PRIi16"\n", i, (pf)[i]);

//	return	alx_ldbl_prime_defactorization_s16((const int16_t (*)[])&pf);
	long double tmp =	alx_ldbl_prime_defactorization_s16((const int16_t (*)[])&pf);
printf("n = %"PRIi16"\n", n);
printf("k = %"PRIi16"\n", k);
printf("tmp = %Lf", tmp);
	return	tmp;
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
	int_fast16_t	m;
	int_fast16_t	j;
	int16_t		tmp[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0)) {
		errno	= EDOM;
		return	-EDOM;
	}

	m	= n;
	j	= 1;
	memset(pf, 0, sizeof(*pf));

	if (k > n) {
		errno	= EDOM;
		return	-EDOM;
	}
	if ((n == k) || (!k))
		return	0;

	do {
		alx_prime_factorization_s16(j++, &tmp);
		alx_matrix_subtraction_s16(ARRAY_SSIZE(*pf), *pf, *pf, tmp);
		alx_prime_factorization_s16(m--, &tmp);
		alx_matrix_addition_s16(ARRAY_SSIZE(*pf), *pf, *pf, tmp);
	} while (j < k);

	return	-errno;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
