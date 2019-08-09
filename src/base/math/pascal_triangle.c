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

#include "libalx/base/float/constant.h"
#include "libalx/base/math/matrix_addition.h"
#include "libalx/base/math/matrix_subtraction.h"
#include "libalx/base/math/prime.h"
#include "libalx/base/math/prime_factorization.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double alx_pascal_triangle_ldbl	(int32_t n, int32_t k)
{
	long double	x;

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanl("");
	}
	if (!k)
		return	1.0L;
	if (k > (n / 2))
		return	alx_pascal_triangle_ldbl(n, n - k);

	x	= 1.0L;
	for (int_fast32_t i = 0; i < k; i++) {
		x	*= n - i;
		x	/= i + 1;
	}

	return	x;
}

double	alx_pascal_triangle		(int16_t n, int16_t k)
{
	double_t	x;

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nan("");
	}
	if (!k)
		return	1.0;
	if (k > (n / 2))
		return	alx_pascal_triangle(n, n - k);

	x	= DBLT_C(1.0);
	for (int_fast16_t i = 0; i < k; i++) {
		x	*= n - i;
		x	/= i + 1;
	}

	return	x;
}

float	alx_pascal_triangle_flt		(int16_t n, int16_t k)
{
	float_t	x;

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	nanf("");
	}
	if (!k)
		return	1.0f;
	if (k > (n / 2))
		return	alx_pascal_triangle_flt(n, n - k);

	x	= FLTT_C(1.0);
	for (int_fast16_t i = 0; i < k; i++) {
		x	*= n - i;
		x	/= i + 1;
	}

	return	x;
}

int	alx_pascal_triangle_factorized	(int16_t n, int16_t k,
				int16_t pf[static restrict PRIME_NUMS_QTY_16b])
{

	if ((n < 0) || (k < 0) || (k > n)) {
		errno	= EDOM;
		return	-EDOM;
	}
	if (!k)
		return	0;
	if (k > (n / 2))
		return	alx_pascal_triangle_factorized(n, n - k, pf);


	for (int_fast16_t i = 0; i < k; i++) {
		alx_prime_factorization_16b(n - i, pf, PF_NUMERATOR);
		alx_prime_factorization_16b(i + 1, pf, PF_DENOMINATOR);
	}

	return	-errno;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
