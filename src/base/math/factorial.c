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
long double	alx_ldbl_factorial		(int16_t n)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if (n < 0) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!n)
		return	1;

	memset(pf, 0, sizeof(pf));
	if (alx_factorial_factorized(n, pf))
		return	nanl("");

	return	alx_ldbl_prime_defactorization_16b(pf);
}

double		alx_factorial			(int16_t n)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if (n < 0) {
		errno	= EDOM;
		return	nan("");
	}
	if (!n)
		return	1;

	memset(pf, 0, sizeof(pf));
	if (alx_factorial_factorized(n, pf))
		return	nan("");

	return	alx_prime_defactorization_16b(pf);
}

float		alx_flt_factorial		(int16_t n)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if (n < 0) {
		errno	= EDOM;
		return	nanf("");
	}
	if (!n)
		return	1;

	memset(pf, 0, sizeof(pf));
	if (alx_factorial_factorized(n, pf))
		return	nanf("");

	return	alx_flt_prime_defactorization_16b(pf);
}

int		alx_factorial_factorized	(int16_t n,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{

	if (n < 0) {
		errno	= EDOM;
		return	-1;
	}

	if (!n)
		return	0;

	for (int_fast16_t i = n; i > 1; i--)
		alx_prime_factorization_16b(i, pf, PF_NUMERATOR);

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
