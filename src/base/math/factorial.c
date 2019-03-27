/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/factorial.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "libalx/base/math/matrix_addition.h"
#include "libalx/base/math/prime.h"
#include "libalx/base/math/prime_defactorization.h"
#include "libalx/base/math/prime_factorization.h"


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
long double	alx_ldbl_factorial		(int16_t n)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if (n < 0) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!n)
		return	1;

	if (alx_factorial_factorized(n, &pf))
		return	nanl("");

	return	alx_ldbl_prime_defactorization_s16((const int8_t (*)[])&pf);
}

double		alx_factorial			(int16_t n)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if (n < 0) {
		errno	= EDOM;
		return	nan("");
	}
	if (!n)
		return	1;

	if (alx_factorial_factorized(n, &pf))
		return	nan("");

	return	alx_prime_defactorization_s16((const int8_t (*)[])&pf);
}

float		alx_flt_factorial		(int16_t n)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if (n < 0) {
		errno	= EDOM;
		return	nanf("");
	}
	if (!n)
		return	1;

	if (alx_factorial_factorized(n, &pf))
		return	nanf("");

	return	alx_flt_prime_defactorization_s16((const int8_t (*)[])&pf);
}

int		alx_factorial_factorized	(int16_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	int8_t	tmp[PRIME_NUMBERS_QTY_S16];

	if (n < 0) {
		errno	= EDOM;
		return	-1;
	}

	memset(pf, 0, sizeof(*pf));

	if (!n)
		return	0;

	for (int_fast16_t i = n; i > 1; i--) {
		alx_prime_factorization_s16(i, &tmp);
		alx_matrix_addition_s8(ARRAY_SSIZE(*pf), *pf, *pf, tmp);
	}

	if (errno)
		return	-2;
	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
