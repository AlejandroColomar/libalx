/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/distributions/uniform.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::const]]
long double	alx_gsl_dist_uniform_E_ldbl	(long double a, long double b);
[[gnu::const]]
double		alx_gsl_dist_uniform_E		(double a, double b);
[[gnu::const]]
float		alx_gsl_dist_uniform_E_flt	(float a, float b);

[[gnu::const]]
long double	alx_gsl_dist_uniform_Var_ldbl	(long double a, long double b);
[[gnu::const]]
double		alx_gsl_dist_uniform_Var	(double a, double b);
[[gnu::const]]
float		alx_gsl_dist_uniform_Var_flt	(float a, float b);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace gsl {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gsl */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
