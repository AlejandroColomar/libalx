/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/distribution_binomial.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>

#include "libalx/base/math/binomial_coefficient.h"


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
long double	alx_ldbl_distribution_binomial_P(int16_t n, long double p,
						int16_t x)
{
	long double	tmp;

	if ((n < 0) || (p < 0) || (p > 1) || (x < 0) || (x > n)) {
		errno	= EDOM;
		return	-1;
	}

	tmp	= alx_ldbl_binomial_coefficient(n, x);
	tmp	*= powl(p, x);
	tmp	*= powl(1 - p, n - x);

	return	tmp;
}

double		alx_distribution_binomial_P	(int16_t n, double p,
						int16_t x)
{
	double_t	tmp;

	if ((n < 0) || (p < 0) || (p > 1) || (x < 0) || (x > n)) {
		errno	= EDOM;
		return	-1;
	}

	tmp	= alx_binomial_coefficient(n, x);
	tmp	*= pow(p, x);
	tmp	*= pow(1 - p, n - x);

	return	tmp;
}

float		alx_flt_distribution_binomial_P	(int16_t n, float p,
						int16_t x)
{
	float_t	tmp;

	if ((n < 0) || (p < 0) || (p > 1) || (x < 0) || (x > n)) {
		errno	= EDOM;
		return	-1;
	}

	tmp	= alx_flt_binomial_coefficient(n, x);
	tmp	*= powf(p, x);
	tmp	*= powf(1 - p, n - x);

	return	tmp;
}

long double	alx_ldbl_distribution_binomial_E(int16_t n, long double p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p;
}

double		alx_distribution_binomial_E	(int16_t n, double p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p;
}

float		alx_flt_distribution_binomial_E	(int16_t n, float p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p;
}

long double	alx_ldbl_distribution_binomial_Var(int16_t n, long double p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p * (1 - p);
}

double		alx_distribution_binomial_Var	(int16_t n, double p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p * (1 - p);
}

float		alx_flt_distribution_binomial_Var(int16_t n, float p)
{

	if ((n < 0) || (p < 0) || (p > 1)) {
		errno	= EDOM;
		return	-1;
	}


	return	n * p * (1 - p);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
