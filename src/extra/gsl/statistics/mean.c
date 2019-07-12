/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/gsl/statistics/mean.h"

#include <math.h>
#include <stddef.h>
#include <stdint.h>


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
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double alx_gsl_stats_mean_ldbl(ptrdiff_t nmemb,
				const long double arr[static restrict nmemb])
{
	long double	sum;
	long double	mean;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum	+= arr[i];

	mean	= sum / nmemb;

	return	mean;
}

float	alx_gsl_stats_mean_flt	(ptrdiff_t nmemb,
				const float arr[static restrict nmemb])
{
	float_t	sum;
	float_t	mean;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum	+= arr[i];

	mean	= sum / nmemb;

	return	mean;
}

double	alx_gsl_stats_mean_s8	(ptrdiff_t nmemb,
				const int8_t arr[static restrict nmemb])
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

long double alx_gsl_stats_mean_u64(ptrdiff_t nmemb,
				const uint64_t arr[static restrict nmemb])
{
	uint_fast64_t	quotients;
	long double	remainders;
	long double	mean;

	quotients	= 0;
	remainders	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		quotients	+= arr[i] / nmemb;
		remainders	+= arr[i] % nmemb;
	}

	mean	= quotients + remainders / nmemb;

	return	mean;
}

long double alx_gsl_stats_mean_s64(ptrdiff_t nmemb,
				const int64_t arr[static restrict nmemb])
{
	int_fast64_t	quotients;
	long double	remainders;
	long double	mean;

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
