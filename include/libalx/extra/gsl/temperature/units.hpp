/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/temperature/units.hpp */


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
long double	alx_gsl_temp_K_to_C_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_temp_K_to_C		(double k);
[[gnu::const]]
float		alx_gsl_temp_K_to_C_flt		(float k);

[[gnu::const]]
long double	alx_gsl_temp_C_to_K_ldbl	(long double c);
[[gnu::const]]
double		alx_gsl_temp_C_to_K		(double c);
[[gnu::const]]
float		alx_gsl_temp_C_to_K_flt		(float c);

[[gnu::const]]
long double	alx_gsl_temp_K_to_F_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_temp_K_to_F		(double k);
[[gnu::const]]
float		alx_gsl_temp_K_to_F_flt		(float k);

[[gnu::const]]
long double	alx_gsl_temp_F_to_K_ldbl	(long double f);
[[gnu::const]]
double		alx_gsl_temp_F_to_K		(double f);
[[gnu::const]]
float		alx_gsl_temp_F_to_K_flt		(float f);

[[gnu::const]]
long double	alx_gsl_temp_C_to_F_ldbl	(long double c);
[[gnu::const]]
double		alx_gsl_temp_C_to_F		(double c);
[[gnu::const]]
float		alx_gsl_temp_C_to_F_flt		(float c);

[[gnu::const]]
long double	alx_gsl_temp_F_to_C_ldbl	(long double f);
[[gnu::const]]
double		alx_gsl_temp_F_to_C		(double f);
[[gnu::const]]
float		alx_gsl_temp_F_to_C_flt		(float f);

[[gnu::const]]
long double	alx_gsl_temp_K_to_R_ldbl	(long double k);
[[gnu::const]]
double		alx_gsl_temp_K_to_R		(double k);
[[gnu::const]]
float		alx_gsl_temp_K_to_R_flt		(float k);

[[gnu::const]]
long double	alx_gsl_temp_R_to_K_ldbl	(long double r);
[[gnu::const]]
double		alx_gsl_temp_R_to_K		(double r);
[[gnu::const]]
float		alx_gsl_temp_R_to_K_flt		(float r);

[[gnu::const]]
long double	alx_gsl_temp_C_to_R_ldbl	(long double c);
[[gnu::const]]
double		alx_gsl_temp_C_to_R		(double c);
[[gnu::const]]
float		alx_gsl_temp_C_to_R_flt		(float c);

[[gnu::const]]
long double	alx_gsl_temp_R_to_C_ldbl	(long double r);
[[gnu::const]]
double		alx_gsl_temp_R_to_C		(double r);
[[gnu::const]]
float		alx_gsl_temp_R_to_C_flt		(float r);

[[gnu::const]]
long double	alx_gsl_temp_F_to_R_ldbl	(long double f);
[[gnu::const]]
double		alx_gsl_temp_F_to_R		(double f);
[[gnu::const]]
float		alx_gsl_temp_F_to_R_flt		(float f);

[[gnu::const]]
long double	alx_gsl_temp_R_to_F_ldbl	(long double r);
[[gnu::const]]
double		alx_gsl_temp_R_to_F		(double r);
[[gnu::const]]
float		alx_gsl_temp_R_to_F_flt		(float r);
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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace gsl */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
