/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gsl/units/temp.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/


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
long double	alx_gsl_units_K_to_C_ldbl	(long double k);
__attribute__((const))
inline
double		alx_gsl_units_K_to_C		(double k);
__attribute__((const))
inline
float		alx_gsl_units_K_to_C_flt	(float k);

__attribute__((const))
inline
long double	alx_gsl_units_C_to_K_ldbl	(long double c);
__attribute__((const))
inline
double		alx_gsl_units_C_to_K		(double c);
__attribute__((const))
inline
float		alx_gsl_units_C_to_K_flt	(float c);

__attribute__((const))
inline
long double	alx_gsl_units_K_to_F_ldbl	(long double k);
__attribute__((const))
inline
double		alx_gsl_units_K_to_F		(double k);
__attribute__((const))
inline
float		alx_gsl_units_K_to_F_flt	(float k);

__attribute__((const))
inline
long double	alx_gsl_units_F_to_K_ldbl	(long double f);
__attribute__((const))
inline
double		alx_gsl_units_F_to_K		(double f);
__attribute__((const))
inline
float		alx_gsl_units_F_to_K_flt	(float f);

__attribute__((const))
inline
long double	alx_gsl_units_C_to_F_ldbl	(long double c);
__attribute__((const))
inline
double		alx_gsl_units_C_to_F		(double c);
__attribute__((const))
inline
float		alx_gsl_units_C_to_F_flt	(float c);

__attribute__((const))
inline
long double	alx_gsl_units_F_to_C_ldbl	(long double f);
__attribute__((const))
inline
double		alx_gsl_units_F_to_C		(double f);
__attribute__((const))
inline
float		alx_gsl_units_F_to_C_flt	(float f);

__attribute__((const))
inline
long double	alx_gsl_units_K_to_R_ldbl	(long double k);
__attribute__((const))
inline
double		alx_gsl_units_K_to_R		(double k);
__attribute__((const))
inline
float		alx_gsl_units_K_to_R_flt	(float k);

__attribute__((const))
inline
long double	alx_gsl_units_R_to_K_ldbl	(long double r);
__attribute__((const))
inline
double		alx_gsl_units_R_to_K		(double r);
__attribute__((const))
inline
float		alx_gsl_units_R_to_K_flt	(float r);

__attribute__((const))
inline
long double	alx_gsl_units_C_to_R_ldbl	(long double c);
__attribute__((const))
inline
double		alx_gsl_units_C_to_R		(double c);
__attribute__((const))
inline
float		alx_gsl_units_C_to_R_flt	(float c);

__attribute__((const))
inline
long double	alx_gsl_units_R_to_C_ldbl	(long double r);
__attribute__((const))
inline
double		alx_gsl_units_R_to_C		(double r);
__attribute__((const))
inline
float		alx_gsl_units_R_to_C_flt	(float r);

__attribute__((const))
inline
long double	alx_gsl_units_F_to_R_ldbl	(long double f);
__attribute__((const))
inline
double		alx_gsl_units_F_to_R		(double f);
__attribute__((const))
inline
float		alx_gsl_units_F_to_R_flt	(float f);

__attribute__((const))
inline
long double	alx_gsl_units_R_to_F_ldbl	(long double r);
__attribute__((const))
inline
double		alx_gsl_units_R_to_F		(double r);
__attribute__((const))
inline
float		alx_gsl_units_R_to_F_flt	(float r);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
long double	alx_gsl_units_C_to_F_ldbl	(long double c)
{
	return	c * 1.8L + 32;
}

inline
double		alx_gsl_units_C_to_F		(double c)
{
	return	c * 1.8 + 32;
}

inline
float		alx_gsl_units_C_to_F_flt	(float c)
{
	return	c * 1.8f + 32;
}


inline
long double	alx_gsl_units_F_to_C_ldbl	(long double f)
{
	return	(f - 32) / 1.8L;
}

inline
double		alx_gsl_units_F_to_C		(double f)
{
	return	(f - 32) / 1.8;
}

inline
float		alx_gsl_units_F_to_C_flt	(float f)
{
	return	(f - 32) / 1.8f;
}


inline
long double	alx_gsl_units_K_to_F_ldbl	(long double k)
{
	return	k * 1.8L + 459.67L;
}

inline
double		alx_gsl_units_K_to_F		(double k)
{
	return	k * 1.8 + 459.67;
}

inline
float		alx_gsl_units_K_to_F_flt	(float k)
{
	return	k * 1.8f + 459.67f;
}


inline
long double	alx_gsl_units_F_to_K_ldbl	(long double f)
{
	return	(f - 459.67L) / 1.8L;
}

inline
double		alx_gsl_units_F_to_K		(double f)
{
	return	(f - 459.67) / 1.8;
}

inline
float		alx_gsl_units_F_to_K_flt	(float f)
{
	return	(f - 459.67f) / 1.8f;
}


inline
long double	alx_gsl_units_K_to_C_ldbl	(long double k)
{
	return	k - 273.15L;
}

inline
double		alx_gsl_units_K_to_C		(double k)
{
	return	k - 273.15;
}

inline
float		alx_gsl_units_K_to_C_flt	(float k)
{
	return	k - 273.15f;
}


inline
long double	alx_gsl_units_C_to_K_ldbl	(long double c)
{
	return	c + 273.15L;
}

inline
double		alx_gsl_units_C_to_K		(double c)
{
	return	c + 273.15;
}

inline
float		alx_gsl_units_C_to_K_flt	(float c)
{
	return	c + 273.15f;
}


inline
long double	alx_gsl_units_K_to_R_ldbl	(long double k)
{
	return	k * 1.8L;
}

inline
double		alx_gsl_units_K_to_R		(double k)
{
	return	k * 1.8;
}

inline
float		alx_gsl_units_K_to_R_flt	(float k)
{
	return	k * 1.8f;
}


inline
long double	alx_gsl_units_R_to_K_ldbl	(long double r)
{
	return	r / 1.8L;
}

inline
double		alx_gsl_units_R_to_K		(double r)
{
	return	r / 1.8;
}

inline
float		alx_gsl_units_R_to_K_flt	(float r)
{
	return	r / 1.8f;
}


inline
long double	alx_gsl_units_C_to_R_ldbl	(long double c)
{
	return	(c + 273.15L) * 1.8L;
}

inline
double		alx_gsl_units_C_to_R		(double c)
{
	return	(c + 273.15) * 1.8;
}

inline
float		alx_gsl_units_C_to_R_flt	(float c)
{
	return	(c + 273.15f) * 1.8f;
}


inline
long double	alx_gsl_units_R_to_C_ldbl	(long double r)
{
	return	(r - 491.67L) / 1.8L;
}

inline
double		alx_gsl_units_R_to_C		(double r)
{
	return	(r - 491.67) / 1.8;
}

inline
float		alx_gsl_units_R_to_C_flt	(float r)
{
	return	(r - 491.67f) / 1.8f;
}


inline
long double	alx_gsl_units_F_to_R_ldbl	(long double f)
{
	return	f + 459.67L;
}

inline
double		alx_gsl_units_F_to_R		(double f)
{
	return	f + 459.67;
}

inline
float		alx_gsl_units_F_to_R_flt	(float f)
{
	return	f + 459.67f;
}


inline
long double	alx_gsl_units_R_to_F_ldbl	(long double r)
{
	return	r - 459.67L;
}

inline
double		alx_gsl_units_R_to_F		(double r)
{
	return	r - 459.67;
}

inline
float		alx_gsl_units_R_to_F_flt	(float r)
{
	return	r - 459.67f;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
