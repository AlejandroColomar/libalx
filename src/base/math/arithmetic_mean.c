/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/arithmetic_mean.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>


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


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_arithmetic_mean_ldbl(ptrdiff_t nmemb,
					const long double arr[restrict nmemb])
{
	long double	sum;
	long double	mean;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum	+= arr[i];

	mean	= sum / nmemb;

	return	mean;
}

double		alx_arithmetic_mean	(ptrdiff_t nmemb,
					const double arr[restrict nmemb])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum	+= arr[i];

	mean	= sum / nmemb;

	return	mean;
}

float		alx_arithmetic_mean_flt	(ptrdiff_t nmemb,
					const float arr[restrict nmemb])
{
	float_t	sum;
	float_t	mean;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum	+= arr[i];

	mean	= sum / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_uint(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb])
{
	unsigned	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb])
{
	int		quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb])
{
	uint_fast8_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb])
{
	int_fast8_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb])
{
	uint_fast16_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb])
{
	int_fast16_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb])
{
	uint_fast32_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb])
{
	int_fast32_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb])
{
	uint_fast64_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

double		alx_arithmetic_mean_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb])
{
	int_fast64_t	quotients;
	double_t	remainders;
	double_t	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
