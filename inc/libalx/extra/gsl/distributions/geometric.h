/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/geometric.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline
long double	alx_gsl_dist_geometric_E_ldbl	(long double p);
static inline
double		alx_gsl_dist_geometric_E	(double p);
static inline
float		alx_gsl_dist_geometric_E_flt	(float p);

static inline
long double	alx_gsl_dist_geometric_Var_ldbl	(long double p);
static inline
double		alx_gsl_dist_geometric_Var	(double p);
static inline
float		alx_gsl_dist_geometric_Var_flt	(float p);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_gsl_dist_geometric_E_ldbl	(long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	1.0L / p;
}

static inline
double		alx_gsl_dist_geometric_E	(double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	1.0 / p;
}

static inline
float		alx_gsl_dist_geometric_E_flt	(float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	1.0f / p;
}


static inline
long double	alx_gsl_dist_geometric_Var_ldbl	(long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	(1.0L - p) / (p * p);
}

static inline
double		alx_gsl_dist_geometric_Var	(double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	(1.0 - p) / (p * p);
}

static inline
float		alx_gsl_dist_geometric_Var_flt	(float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	(1.0f - p) / (p * p);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
