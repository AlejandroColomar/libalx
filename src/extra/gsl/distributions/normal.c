/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/distributions/normal.h"

#include <errno.h>
#include <math.h>


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
long double	alx_gsl_dist_normal_A_ldbl	(long double o)
{

	if (o <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1.0L / o;
}

double		alx_gsl_dist_normal_A		(double o)
{

	if (o <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	1.0 / o;
}

float		alx_gsl_dist_normal_A_flt	(float o)
{

	if (o <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1.0f / o;
}

long double	alx_gsl_dist_normal_B_ldbl	(long double u, long double o)
{

	if (o <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	-u / o;
}

double		alx_gsl_dist_normal_B		(double u, double o)
{

	if (o <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	-u / o;
}

float		alx_gsl_dist_normal_B_flt	(float u, float o)
{

	if (o <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	-u / o;
}

long double	alx_gsl_dist_normal_X2Z_ldbl	(long double a, long double b,
						long double x)
{

	return	a * x + b;
}

double		alx_gsl_dist_normal_X2Z		(double a, double b, double x)
{

	return	a * x + b;
}

float		alx_gsl_dist_normal_X2Z_flt	(float a, float b, float x)
{

	return	a * x + b;
}

long double	alx_gsl_dist_normal_Z2X_ldbl	(long double a, long double b,
						long double z)
{

	return	(z - b) / a;
}

double		alx_gsl_dist_normal_Z2X		(double a, double b, double z)
{

	return	(z - b) / a;
}

float		alx_gsl_dist_normal_Z2X_flt	(float a, float b, float z)
{

	return	(z - b) / a;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
