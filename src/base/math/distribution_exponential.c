/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/distribution_exponential.h"

#include <errno.h>
#include <math.h>


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
long double	alx_ldbl_distribution_exponential_P(long double b,
						long double x1, long double x2)
{
	long double	tmp;

	if ((b < DIST_BINOMIAL_b_MIN) || (x1 < DIST_BINOMIAL_x_MIN) ||
								(x2 < x1)) {
		errno	= EDOM;
		return	nanl("");
	}

	tmp	= expl(-b * x1);
	tmp	-= expl(-b * x2);

	return	tmp;
}

double		alx_distribution_exponential_P	(double b, double x1, double x2)
{
	double_t	tmp;

	if ((b < DIST_BINOMIAL_b_MIN) || (x1 < DIST_BINOMIAL_x_MIN) ||
								(x2 < x1)) {
		errno	= EDOM;
		return	nan("");
	}

	tmp	= exp(-b * x1);
	tmp	-= exp(-b * x2);

	return	tmp;
}

float		alx_flt_distribution_exponential_P(float b, float x1, float x2)
{
	float_t	tmp;

	if ((b < DIST_BINOMIAL_b_MIN) || (x1 < DIST_BINOMIAL_x_MIN) ||
								(x2 < x1)) {
		errno	= EDOM;
		return	nanf("");
	}

	tmp	= expf(-b * x1);
	tmp	-= expf(-b * x2);

	return	tmp;
}

long double	alx_ldbl_distribution_exponential_E(long double b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1 / b;
}

double		alx_distribution_exponential_E	(double b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nan("");
	}

	return	1 / b;
}

float		alx_flt_distribution_exponential_E(float b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1 / b;
}

long double	alx_ldbl_distribution_exponential_Var(long double b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1 / (b * b);
}

double		alx_distribution_exponential_Var(double b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nan("");
	}

	return	1 / (b * b);
}

float		alx_flt_distribution_exponential_Var(float b)
{

	if (b < DIST_BINOMIAL_b_MIN) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1 / (b * b);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
