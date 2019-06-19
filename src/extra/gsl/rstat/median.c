/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/rstat/median.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/stdlib/average.h"
#include "libalx/base/stdlib/compare.h"


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
long double alx_gsl_rstat_median_ldbl(ptrdiff_t nmemb,
				const long double arr[static restrict nmemb])
{
	long double	sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_ldbl);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast(sorted[nmemb/2], sorted[nmemb/2 - 1]);

	return	median;
}

float	alx_gsl_rstat_median_flt(ptrdiff_t nmemb,
				const float arr[static restrict nmemb])
{
	float	sorted[nmemb];
	float	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_f);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = AVGfast(sorted[nmemb/2], sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_uint(ptrdiff_t nmemb,
				const unsigned arr[static restrict nmemb])
{
	unsigned	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_uint);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 -1]);

	return	median;
}

double	alx_gsl_rstat_median_int(ptrdiff_t nmemb,
				const int arr[static restrict nmemb])
{
	int	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_int);

	if (nmemb % 2)
		median = sorted[nmemb/2];
	else
		median = AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 -1]);

	return	median;
}

double	alx_gsl_rstat_median_u8	(ptrdiff_t nmemb,
				const uint8_t arr[static restrict nmemb])
{
	uint8_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_u8);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_s8	(ptrdiff_t nmemb,
				const int8_t arr[static restrict nmemb])
{
	int8_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s8);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_u16(ptrdiff_t nmemb,
				const uint16_t arr[static restrict nmemb])
{
	uint16_t	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_u16);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_rstat_median_s16	(ptrdiff_t nmemb,
				const int16_t arr[static restrict nmemb])
{
	int16_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s16);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_rgsl_stat_median_u32(ptrdiff_t nmemb,
				const uint32_t arr[static restrict nmemb])
{
	uint32_t	sorted[nmemb];
	double		median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_u32);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

double	alx_gsl_rstat_median_s32(ptrdiff_t nmemb,
				const int32_t arr[static restrict nmemb])
{
	int32_t	sorted[nmemb];
	double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s32);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((double_t)sorted[nmemb/2],
					(double_t)sorted[nmemb/2 - 1]);

	return	median;
}

long double alx_gsl_rstat_median_u64(ptrdiff_t nmemb,
				const uint64_t arr[static restrict nmemb])
{
	uint64_t	sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_u64);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((long double)sorted[nmemb/2],
					(long double)sorted[nmemb/2 - 1]);

	return	median;
}

long double alx_gsl_rstat_median_s64(ptrdiff_t nmemb,
				const int64_t arr[static restrict nmemb])
{
	int64_t		sorted[nmemb];
	long double	median;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s64);

	if (nmemb % 2)
		median	= sorted[nmemb/2];
	else
		median	= AVGfast((long double)sorted[nmemb/2],
					(long double)sorted[nmemb/2 - 1]);

	return	median;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
