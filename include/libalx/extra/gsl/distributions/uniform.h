/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/uniform.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>

#include "libalx/base/stdlib/average.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((const))
inline
long double	alx_gsl_dist_uniform_E_ldbl	(long double a, long double b);
__attribute__((const))
inline
double		alx_gsl_dist_uniform_E		(double a, double b);
__attribute__((const))
inline
float		alx_gsl_dist_uniform_E_flt	(float a, float b);

__attribute__((const))
inline
long double	alx_gsl_dist_uniform_Var_ldbl	(long double a, long double b);
__attribute__((const))
inline
double		alx_gsl_dist_uniform_Var	(double a, double b);
__attribute__((const))
inline
float		alx_gsl_dist_uniform_Var_flt	(float a, float b);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_dist_uniform_E_ldbl	(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	ALX_AVG(a, b);
}

inline
double		alx_gsl_dist_uniform_E		(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	ALX_AVG(a, b);
}

inline
float		alx_gsl_dist_uniform_E_flt	(float a, float b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanf("");
	}

	return	ALX_AVG(a, b);
}


inline
long double	alx_gsl_dist_uniform_Var_ldbl	(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	(b - a) * (b - a) / 12.0L;
}

inline
double		alx_gsl_dist_uniform_Var	(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	(b - a) * (b - a) / 12.0;
}

inline
float		alx_gsl_dist_uniform_Var_flt	(float a, float b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanf("");
	}

	return	(b - a) * (b - a) / 12.0f;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
