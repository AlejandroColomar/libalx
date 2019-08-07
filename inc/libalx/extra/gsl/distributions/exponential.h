/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/exponential.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>


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
long double	alx_gsl_dist_exponential_E_ldbl		(long double b);
__attribute__((const))
inline
double		alx_gsl_dist_exponential_E		(double b);
__attribute__((const))
inline
float		alx_gsl_dist_exponential_E_flt		(float b);

__attribute__((const))
inline
long double	alx_gsl_dist_exponential_Var_ldbl	(long double b);
__attribute__((const))
inline
double		alx_gsl_dist_exponential_Var		(double b);
__attribute__((const))
inline
float		alx_gsl_dist_exponential_Var_flt	(float b);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_dist_exponential_E_ldbl		(long double b)
{

	if (b <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1.0L / b;
}

inline
double		alx_gsl_dist_exponential_E		(double b)
{

	if (b <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	1.0 / b;
}

inline
float		alx_gsl_dist_exponential_E_flt		(float b)
{

	if (b <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1.0f / b;
}


inline
long double	alx_gsl_dist_exponential_Var_ldbl	(long double b)
{

	if (b <= 0.0L) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1.0L / (b * b);
}

inline
double		alx_gsl_dist_exponential_Var		(double b)
{

	if (b <= 0.0) {
		errno	= EDOM;
		return	nan("");
	}

	return	1.0 / (b * b);
}

inline
float		alx_gsl_dist_exponential_Var_flt	(float b)
{

	if (b <= 0.0f) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1.0f / (b * b);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
