/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/median.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/stdlib/compare.h"


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
long double	alx_median_ldbl	(ptrdiff_t n, const long double x[restrict n])
{
	long double	sorted[n];
	long double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_ldbl);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median	(ptrdiff_t n, const double x[restrict n])
{
	double	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

float		alx_median_flt	(ptrdiff_t n, const float x[restrict n])
{
	float	sorted[n];
	float	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_f);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_uint	(ptrdiff_t n, const unsigned x[restrict n])
{
	unsigned	sorted[n];
	double		median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_uint);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_int	(ptrdiff_t n, const int x[restrict n])
{
	int	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_int);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_u8	(ptrdiff_t n, const uint8_t x[restrict n])
{
	uint8_t	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_u8);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_s8	(ptrdiff_t n, const int8_t x[restrict n])
{
	int8_t	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s8);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_u16	(ptrdiff_t n, const uint16_t x[restrict n])
{
	uint16_t	sorted[n];
	double		median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_u16);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_s16	(ptrdiff_t n, const int16_t x[restrict n])
{
	int16_t	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s16);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_u32	(ptrdiff_t n, const uint32_t x[restrict n])
{
	uint32_t	sorted[n];
	double		median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_u32);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_s32	(ptrdiff_t n, const int32_t x[restrict n])
{
	int32_t	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s32);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_u64	(ptrdiff_t n, const uint64_t x[restrict n])
{
	uint64_t	sorted[n];
	double		median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_u64);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}

double		alx_median_s64	(ptrdiff_t n, const int64_t x[restrict n])
{
	int64_t	sorted[n];
	double	median;

	memcpy(sorted, x, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s64);

	if (n % 2)
		median	= sorted[n/2];
	else
		median	= (sorted[n/2] + sorted[n/2 - 1]) / 2.0;

	return	median;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
