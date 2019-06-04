/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/pascal_triangle.h"

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


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_ldbl_pascal_triangle	(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_ldbl_pascal_triangle(n, n - k);

	memset(pf, 0, sizeof(pf));
	if (alx_pascal_triangle_factorized(n, k, pf))
		return	nanl("");

	return	alx_ldbl_prime_defactorization_16b(pf);
}

double		alx_pascal_triangle		(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nan("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_pascal_triangle(n, n - k);

	memset(pf, 0, sizeof(pf));
	if (alx_pascal_triangle_factorized(n, k, pf))
		return	nan("");

	return	alx_prime_defactorization_16b(pf);
}

float		alx_flt_pascal_triangle		(int16_t n, int16_t k)
{
	int16_t	pf[PRIME_NUMS_QTY_16b];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanf("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_flt_pascal_triangle(n, n - k);

	memset(pf, 0, sizeof(pf));
	if (alx_pascal_triangle_factorized(n, k, pf))
		return	nanf("");

	return	alx_flt_prime_defactorization_16b(pf);
}

int		alx_pascal_triangle_factorized	(int16_t n, int16_t k,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	-EDOM;
	}

	if (k > (n / 2))
		return	alx_pascal_triangle_factorized(n, n - k, pf);

	if (!k)
		return	0;

	for (int_fast16_t i = 0; i < k; i++) {
		alx_prime_factorization_16b(n - i, pf, PF_NUMERATOR);
		alx_prime_factorization_16b(i + 1, pf, PF_DENOMINATOR);
	}

	return	-errno;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
