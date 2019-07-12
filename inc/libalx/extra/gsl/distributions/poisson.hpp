/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/poisson.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cerrno>
#include <cmath>


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
long double	alx_gsl_dist_poisson_E_ldbl	(long double l);
static inline
double		alx_gsl_dist_poisson_E		(double l);
static inline
float		alx_gsl_dist_poisson_E_flt	(float l);

static inline
long double	alx_gsl_dist_poisson_Var_ldbl	(long double l);
static inline
double		alx_gsl_dist_poisson_Var	(double l);
static inline
float		alx_gsl_dist_poisson_Var_flt	(float l);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_gsl_dist_poisson_E_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

static inline
double		alx_gsl_dist_poisson_E		(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

static inline
float		alx_gsl_dist_poisson_E_flt	(float l)
{

	if (l <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}


static inline
long double	alx_gsl_dist_poisson_Var_ldbl	(long double l)
{

	if (l <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	l;
}

static inline
double		alx_gsl_dist_poisson_Var	(double l)
{

	if (l <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	l;
}

static inline
float		alx_gsl_dist_poisson_Var_flt	(float l)
{

	if (l <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	l;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
