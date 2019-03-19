/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/arithmetic_mean.h"

#include <math.h>
#include <stdint.h>

#include <sys/types.h>


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
long double	alx_arithmetic_mean_ldbl(ssize_t n,
					const long double arr[restrict n])
{
	long double	sum;
	long double	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean	(ssize_t n,
					const double arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

float		alx_arithmetic_mean_flt	(ssize_t n,
					const float arr[restrict n])
{
	float_t	sum;
	float_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_uint(ssize_t n,
					const unsigned arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_int	(ssize_t n,
					const int arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_u8	(ssize_t n,
					const uint8_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_s8	(ssize_t n,
					const int8_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_u16	(ssize_t n,
					const uint16_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_s16	(ssize_t n,
					const int16_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_u32	(ssize_t n,
					const uint32_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_s32	(ssize_t n,
					const int32_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_u64	(ssize_t n,
					const uint64_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}

double		alx_arithmetic_mean_s64	(ssize_t n,
					const int64_t arr[restrict n])
{
	double_t	sum;
	double_t	mean;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum	+= arr[i];

	mean	= sum / n;

	return	mean;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
