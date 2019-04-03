/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime_defactorization.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libalx/base/math/prime.h"
#include "libalx/base/stddef/size.h"


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
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
#include <stdio.h>
#include <inttypes.h>

/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_ldbl_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	long double	n;
	long double	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powl(alx_prime_s8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

long double	alx_ldbl_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	long double	n;
	long double	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powl(alx_prime_u8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

long double	alx_ldbl_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	long double	n;
	long double	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powl(alx_prime_s16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

long double	alx_ldbl_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	long double	n;
	long double	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powl(alx_prime_u16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}


double		alx_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	double_t	n;
	double_t	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= pow(alx_prime_s8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

double		alx_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	double_t	n;
	double_t	tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= pow(alx_prime_u8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

double		alx_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	double_t	n;
	double_t	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= pow(alx_prime_s16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

double		alx_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	double_t	n;
	double_t	tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= pow(alx_prime_u16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}


float		alx_flt_prime_defactorization_s8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	float_t		n;
	float_t		tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powf(alx_prime_s8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

float		alx_flt_prime_defactorization_u8(
			const int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	float_t		n;
	float_t		tmp;
	int_fast8_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powf(alx_prime_u8[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

float		alx_flt_prime_defactorization_s16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	float_t		n;
	float_t		tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powf(alx_prime_s16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}

float		alx_flt_prime_defactorization_u16(
			const int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	float_t		n;
	float_t		tmp;
	int_fast16_t	exp;

	n	= 1;
	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(*pf); i++) {
		exp	= abs((*pf)[i]);
		tmp	= powf(alx_prime_u16[i], exp);
		if ((*pf)[i] > 0)
			n *= tmp;
		else if ((*pf)[i] < 0)
			n /= tmp;
	}

	return	n;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
