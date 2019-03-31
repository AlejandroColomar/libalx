/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/distribution_poisson.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>

#include "libalx/base/math/factorial.h"


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
long double	alx_ldbl_distribution_poisson_P	(long double l, int16_t x)
{
	long double	tmp;

	if ((l < DIST_POISSON_l_MIN) || (x < DIST_POISSON_x_MIN)) {
		errno	= EDOM;
		return	nanl("");
	}

	tmp	= expl(-l);
	tmp	*= powl(l, x);
	tmp	/= alx_ldbl_factorial(x);

	return	tmp;
}

double		alx_distribution_poisson_P	(double l, int16_t x)
{
	double_t	tmp;

	if ((l < DIST_POISSON_l_MIN) || (x < DIST_POISSON_x_MIN)) {
		errno	= EDOM;
		return	nan("");
	}

	tmp	= exp(-l);
	tmp	*= pow(l, x);
	tmp	/= alx_factorial(x);

	return	tmp;
}

float		alx_flt_distribution_poisson_P	(float l, int16_t x)
{
	float_t	tmp;

	if ((l < DIST_POISSON_l_MIN) || (x < DIST_POISSON_x_MIN)) {
		errno	= EDOM;
		return	nanf("");
	}

	tmp	= expf(-l);
	tmp	*= powf(l, x);
	tmp	/= alx_flt_factorial(x);

	return	tmp;
}

long double	alx_ldbl_distribution_poisson_E(long double l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

double		alx_distribution_poisson_E	(double l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

float		alx_flt_distribution_poisson_E	(float l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}

long double	alx_ldbl_distribution_poisson_Var(long double l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nanl("");
	}


	return	l;
}

double		alx_distribution_poisson_Var	(double l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nan("");
	}


	return	l;
}

float		alx_flt_distribution_poisson_Var(float l)
{

	if (l < DIST_POISSON_l_MIN) {
		errno	= EDOM;
		return	nanf("");
	}


	return	l;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
