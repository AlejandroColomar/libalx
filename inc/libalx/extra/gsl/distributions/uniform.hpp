/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_GSL_DISTRIBUTIONS_UNIFORM_HPP
#define ALX_GSL_DISTRIBUTIONS_UNIFORM_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cerrno>
#include <cmath>

#include "libalx/base/stdlib/average.hpp"


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

	return	AVGfast(a, b);
}

static inline
double		alx_gsl_dist_uniform_E		(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	AVGfast(a, b);
}

static inline
float		alx_gsl_dist_uniform_E_flt	(float a, float b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanf("");
	}

	return	AVGfast(a, b);
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
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/extra/gsl/distributions/uniform.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
