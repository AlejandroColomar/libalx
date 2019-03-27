/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_DISTRIBUTION_UNIFORM_HPP
#define ALX_MATH_DISTRIBUTION_UNIFORM_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/


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
extern	"C"
{
long double	alx_ldbl_distribution_uniform_P	(long double a, long double b,
						long double x1, long double x2);
double		alx_distribution_uniform_P	(double a, double b,
						double x1, double x2);
float		alx_flt_distribution_uniform_P	(float a, float b,
						float x1, float x2);

long double	alx_ldbl_distribution_uniform_E	(long double a, long double b);
double		alx_distribution_uniform_E	(double a, double b);
float		alx_flt_distribution_uniform_E	(float a, float b);

long double	alx_ldbl_distribution_uniform_Var(long double a, long double b);
double		alx_distribution_uniform_Var	(double a, double b);
float		alx_flt_distribution_uniform_Var(float a, float b);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/distribution_uniform.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
