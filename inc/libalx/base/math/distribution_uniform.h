/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_DISTRIBUTION_UNIFORM_H
#define ALX_MATH_DISTRIBUTION_UNIFORM_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <math.h>

#include "libalx/base/math/arithmetic_mean.h"


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
long double	alx_ldbl_distribution_uniform_E	(long double a, long double b);
static inline
double		alx_distribution_uniform_E	(double a, double b);
static inline
float		alx_flt_distribution_uniform_E	(float a, float b);

static inline
long double	alx_ldbl_distribution_uniform_Var(long double a, long double b);
static inline
double		alx_distribution_uniform_Var	(double a, double b);
static inline
float		alx_flt_distribution_uniform_Var(float a, float b);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_distribution_uniform_E	(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	AVGfast(a, b);
}

static inline
double		alx_distribution_uniform_E	(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	AVGfast(a, b);
}

static inline
float		alx_flt_distribution_uniform_E	(float a, float b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanf("");
	}

	return	AVGfast(a, b);
}


static inline
long double	alx_ldbl_distribution_uniform_Var(long double a, long double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nanl("");
	}

	return	(b - a) * (b - a) / 12.0L;
}

static inline
double		alx_distribution_uniform_Var	(double a, double b)
{

	if (b < a) {
		errno	= EDOM;
		return	nan("");
	}

	return	(b - a) * (b - a) / 12.0;
}

static inline
float		alx_flt_distribution_uniform_Var(float a, float b)
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
#endif		/* libalx/base/math/distribution_uniform.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
