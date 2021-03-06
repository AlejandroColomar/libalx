/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/binomial.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>
#include <stdint.h>


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
long double	alx_gsl_dist_binomial_E_ldbl	(uint64_t n, long double p);
__attribute__((const))
inline
double		alx_gsl_dist_binomial_E		(uint32_t n, double p);
__attribute__((const))
inline
float		alx_gsl_dist_binomial_E_flt	(uint16_t n, float p);

__attribute__((const))
inline
long double	alx_gsl_dist_binomial_Var_ldbl	(uint64_t n, long double p);
__attribute__((const))
inline
double		alx_gsl_dist_binomial_Var	(uint32_t n, double p);
__attribute__((const))
inline
float		alx_gsl_dist_binomial_Var_flt	(uint16_t n, float p);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_dist_binomial_E_ldbl	(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	n * p;
}

inline
double		alx_gsl_dist_binomial_E		(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	n * p;
}

inline
float		alx_gsl_dist_binomial_E_flt	(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	n * p;
}


inline
long double	alx_gsl_dist_binomial_Var_ldbl	(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}


	return	n * p * (1.0L - p);
}

inline
double		alx_gsl_dist_binomial_Var	(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}


	return	n * p * (1.0 - p);
}

inline
float		alx_gsl_dist_binomial_Var_flt	(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}


	return	n * p * (1.0f - p);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
