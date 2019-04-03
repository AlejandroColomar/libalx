/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_PRIME_DEFACTORIZATION_HPP
#define ALX_MATH_PRIME_DEFACTORIZATION_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cmath>
#include <cstddef>
#include <cstdint>

#include "libalx/base/math/prime.hpp"
#include "libalx/base/stddef/restrict.hpp"
#include "libalx/base/stddef/size.hpp"


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
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8]);
static inline	long double	alx_ldbl_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8]);
static inline	long double	alx_ldbl_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);
static inline	long double	alx_ldbl_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);

static inline	double		alx_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8]);
static inline	double		alx_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8]);
static inline	double		alx_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);
static inline	double		alx_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);

static inline	float		alx_flt_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8]);
static inline	float		alx_flt_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8]);
static inline	float		alx_flt_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);
static inline	float		alx_flt_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	long double	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s8[i];

	return	n;
}

static inline
long double	alx_ldbl_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	long double	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u8[i];

	return	n;
}

static inline
long double	alx_ldbl_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	long double	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s16[i];

	return	n;
}

static inline
long double	alx_ldbl_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	long double	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u16[i];

	return	n;
}


static inline
double		alx_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	double_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s8[i];

	return	n;
}

static inline
double		alx_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	double_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u8[i];

	return	n;
}

static inline
double		alx_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	double_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s16[i];

	return	n;
}

static inline
double		alx_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	double_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u16[i];

	return	n;
}


static inline
float		alx_flt_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	float_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s8[i];

	return	n;
}

static inline
float		alx_flt_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	float_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u8[i];

	return	n;
}

static inline
float		alx_flt_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	float_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_s16[i];

	return	n;
}

static inline
float		alx_flt_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	float_t	n;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++)
		n	+= (*pf)[i] * alx_prime_u16[i];

	return	n;
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/prime_defactorization.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
