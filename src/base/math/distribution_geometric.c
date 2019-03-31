/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/distribution_geometric.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>


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
long double	alx_ldbl_distribution_geometric_P(long double p, int64_t x)
{
	long double	tmp;

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX) ||
						(x < DIST_GEOMETRIC_x_MIN)) {
		errno	= EDOM;
		return	nanl("");
	}

	tmp	= p;
	tmp	*= powl(1 - p, x - 1);

	return	tmp;
}

double		alx_distribution_geometric_P	(double p, int32_t x)
{
	double_t	tmp;

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX) ||
						(x < DIST_GEOMETRIC_x_MIN)) {
		errno	= EDOM;
		return	nan("");
	}

	tmp	= p;
	tmp	*= pow(1 - p, x - 1);

	return	tmp;
}

float		alx_flt_distribution_geometric_P(float p, int16_t x)
{
	float_t	tmp;

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX) ||
						(x < DIST_GEOMETRIC_x_MIN)) {
		errno	= EDOM;
		return	nanf("");
	}

	tmp	= p;
	tmp	*= powf(1 - p, x - 1);

	return	tmp;
}

long double	alx_ldbl_distribution_geometric_E(long double p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1 / p;
}

double		alx_distribution_geometric_E	(double p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nan("");
	}

	return	1 / p;
}

float		alx_flt_distribution_geometric_E(float p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1 / p;
}

long double	alx_ldbl_distribution_geometric_Var(long double p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	(1 - p) / (p * p);
}

double		alx_distribution_geometric_Var	(double p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nan("");
	}

	return	(1 - p) / (p * p);
}

float		alx_flt_distribution_geometric_Var(float p)
{

	if ((p < DIST_GEOMETRIC_p_MIN) || (p > DIST_GEOMETRIC_p_MAX)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	(1 - p) / (p * p);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
