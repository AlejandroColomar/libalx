/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/distribution_normal.h"

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
long double	alx_ldbl_distribution_normal_A	(long double o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1 / o;
}

double		alx_distribution_normal_A	(double o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	1 / o;
}

float		alx_flt_distribution_normal_A	(float o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1 / o;
}

long double	alx_ldbl_distribution_normal_B	(long double u, long double o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	-u / o;
}

double		alx_distribution_normal_B	(double u, double o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	-u / o;
}

float		alx_flt_distribution_normal_B	(float u, float o)
{

	if ((o < 0) || (o == 0)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	-u / o;
}

long double	alx_ldbl_distribution_normal_Z	(long double a, long double b,
						long double x)
{

	return	a * x + b;
}

double		alx_distribution_normal_Z	(double a, double b, double x)
{

	return	a * x + b;
}

float		alx_flt_distribution_normal_Z	(float a, float b, float x)
{

	return	a * x + b;
}

long double	alx_ldbl_distribution_normal_X	(long double a, long double b,
						long double z)
{

	return	(z - b) / a;
}

double		alx_distribution_normal_X	(double a, double b, double z)
{

	return	(z - b) / a;
}

float		alx_flt_distribution_normal_X	(float a, float b, float z)
{

	return	(z - b) / a;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
