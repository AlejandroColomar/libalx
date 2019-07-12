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
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline
long double	alx_gsl_dist_uniform_E_ldbl	(long double a, long double b);
static inline
double		alx_gsl_dist_uniform_E		(double a, double b);
static inline
float		alx_gsl_dist_uniform_E_flt	(float a, float b);

static inline
long double	alx_gsl_dist_uniform_Var_ldbl	(long double a, long double b);
static inline
double		alx_gsl_dist_uniform_Var	(double a, double b);
static inline
float		alx_gsl_dist_uniform_Var_flt	(float a, float b);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_gsl_dist_uniform_E_ldbl	(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	ALX_AVG(a, b);
}

static inline
double		alx_gsl_dist_uniform_E		(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	ALX_AVG(a, b);
}

static inline
float		alx_gsl_dist_uniform_E_flt	(float a, float b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanf("");
	}

	return	ALX_AVG(a, b);
}


static inline
long double	alx_gsl_dist_uniform_Var_ldbl	(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	(b - a) * (b - a) / 12.0L;
}

static inline
double		alx_gsl_dist_uniform_Var	(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	(b - a) * (b - a) / 12.0;
}

static inline
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
