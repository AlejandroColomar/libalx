/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/pascal_triangle.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "libalx/math/matrix_addition.h"
#include "libalx/math/matrix_subtraction.h"
#include "libalx/math/prime.h"
#include "libalx/math/prime_defactorization.h"
#include "libalx/math/prime_factorization.h"


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
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_ldbl_pascal_triangle(n, n - k);

	alx_pascal_triangle_factorized(n, k, &pf);

	return	alx_ldbl_prime_defactorization_s16((const int8_t (*)[])&pf);
}

double		alx_pascal_triangle		(int16_t n, int16_t k)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_pascal_triangle(n, n - k);

	alx_pascal_triangle_factorized(n, k, &pf);

	return	alx_prime_defactorization_s16((const int8_t (*)[])&pf);
}

float		alx_flt_pascal_triangle		(int16_t n, int16_t k)
{
	int8_t	pf[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!k)
		return	1;
	if (k > (n / 2))
		return	alx_flt_pascal_triangle(n, n - k);

	alx_pascal_triangle_factorized(n, k, &pf);

	return	alx_flt_prime_defactorization_s16((const int8_t (*)[])&pf);
}

int		alx_pascal_triangle_factorized	(int16_t n, int16_t k,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	int8_t	tmp[PRIME_NUMBERS_QTY_S16];

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	-1;
	}

	if (k > (n / 2))
		return	alx_pascal_triangle_factorized(n, n - k, pf);

	memset(pf, 0, sizeof(*pf));

	if (!k)
		return	0;

	for (int_fast16_t i = 0; i < k; i++) {
		alx_prime_factorization_s16(i + 1, &tmp);
		alx_matrix_subtraction_s8(sizeof(*pf), *pf, *pf, tmp);
		alx_prime_factorization_s16(n - i, &tmp);
		alx_matrix_addition_s8(sizeof(*pf), *pf, *pf, tmp);
	}

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
