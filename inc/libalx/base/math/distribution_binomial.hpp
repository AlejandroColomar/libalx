/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_DISTRIBUTION_BINOMIAL_HPP
#define ALX_MATH_DISTRIBUTION_BINOMIAL_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cerrno>
#include <cmath>
#include <cstdint>


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
long double	alx_ldbl_distribution_binomial_E(uint64_t n, long double p);
static inline
double		alx_distribution_binomial_E	(uint32_t n, double p);
static inline
float		alx_flt_distribution_binomial_E	(uint16_t n, float p);

static inline
long double	alx_ldbl_distribution_binomial_Var(uint64_t n, long double p);
static inline
double		alx_distribution_binomial_Var	(uint32_t n, double p);
static inline
float		alx_flt_distribution_binomial_Var(uint16_t n, float p);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_distribution_binomial_E(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}

	return	n * p;
}

static inline
double		alx_distribution_binomial_E	(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}

	return	n * p;
}

static inline
float		alx_flt_distribution_binomial_E	(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}

	return	n * p;
}


static inline
long double	alx_ldbl_distribution_binomial_Var(uint64_t n, long double p)
{

	if ((p < 0.0L) || (p > 1.0L)) {
		errno	= EDOM;
		return	nanl("");
	}


	return	n * p * (1 - p);
}

static inline
double		alx_distribution_binomial_Var	(uint32_t n, double p)
{

	if ((p < 0.0) || (p > 1.0)) {
		errno	= EDOM;
		return	nan("");
	}


	return	n * p * (1 - p);
}

static inline
float		alx_flt_distribution_binomial_Var(uint16_t n, float p)
{

	if ((p < 0.0f) || (p > 1.0f)) {
		errno	= EDOM;
		return	nanf("");
	}


	return	n * p * (1 - p);
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/distribution_binomial.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
