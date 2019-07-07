/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/array_sum.h"

#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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
extern
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t arr[restrict nmemb]);
extern
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t arr[restrict nmemb]);

extern
double	alx_dbl_array_sum		(ptrdiff_t nmemb,
					 const double arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_uint		(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_int		(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_u8		(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_s8		(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_u16		(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_s16		(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_u32		(ptrdiff_t nmemb,
					 const uint32_t arr[restrict nmemb]);
extern
double	alx_dbl_array_sum_s32		(ptrdiff_t nmemb,
					 const int32_t arr[restrict nmemb]);

extern
float	alx_flt_array_sum_flt		(ptrdiff_t nmemb,
					 const float arr[restrict nmemb]);
extern
float	alx_flt_array_sum_uint		(ptrdiff_t nmemb,
					 const unsigned arr[restrict nmemb]);
extern
float	alx_flt_array_sum_int		(ptrdiff_t nmemb,
					 const int arr[restrict nmemb]);
extern
float	alx_flt_array_sum_u8		(ptrdiff_t nmemb,
					 const uint8_t arr[restrict nmemb]);
extern
float	alx_flt_array_sum_s8		(ptrdiff_t nmemb,
					 const int8_t arr[restrict nmemb]);
extern
float	alx_flt_array_sum_u16		(ptrdiff_t nmemb,
					 const uint16_t arr[restrict nmemb]);
extern
float	alx_flt_array_sum_s16		(ptrdiff_t nmemb,
					 const int16_t arr[restrict nmemb]);

unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb])
{
	unsigned	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		sum += arr[i];
		if (sum < arr[i])
			goto ovf;
	}

	return	sum;
ovf:
	errno	= ERANGE;
	return	UINT_MAX;
}

int		alx_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb])
{
	int		sorted[nmemb];
	ptrdiff_t	i, j;
	double_t	tmp;
	int		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_int);

	tmp	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			goto ovf;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT_MAX)
		goto ovf;
	if (nextafter(tmp, tmp - 1) < INT_MIN)
		goto ovf;

	sum	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;
ovf:
	errno	= ERANGE;
	return	INT_MIN;
}

uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb])
{
	uint_fast16_t		sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		sum += arr[i];
		if (sum > UINT8_MAX)
			goto ovf;
	}

	return	sum;
ovf:
	errno	= ERANGE;
	return	UINT8_MAX;
}

int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb])
{
	int8_t		sorted[nmemb];
	ptrdiff_t	i, j;
	double_t	tmp;
	int_fast8_t	sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s8);

	tmp	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT8_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT8_MIN)
			goto ovf;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT8_MAX)
		goto ovf;
	if (nextafter(tmp, tmp - 1) < INT8_MIN)
		goto ovf;

	sum	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;
ovf:
	errno	= ERANGE;
	return	INT8_MIN;
}

uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb])
{
	uint_fast32_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		sum += arr[i];
		if (sum > UINT16_MAX)
			goto ovf;
	}

	return	sum;
ovf:
	errno	= ERANGE;
	return	UINT16_MAX;
}

int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb])
{
	int16_t		sorted[nmemb];
	ptrdiff_t	i, j;
	double_t	tmp;
	int_fast16_t	sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s16);

	tmp	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT16_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT16_MIN)
			goto ovf;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT16_MAX)
		goto ovf;
	if (nextafter(tmp, tmp - 1) < INT16_MIN)
		goto ovf;

	sum	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;
ovf:
	errno	= ERANGE;
	return	INT16_MIN;
}

uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb])
{
	uint_fast64_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		sum += arr[i];
		if (sum > UINT32_MAX)
			goto ovf;
	}

	return	0;
ovf:
	errno	= ERANGE;
	return	UINT32_MAX;
}

int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb])
{
	int32_t		sorted[nmemb];
	ptrdiff_t	i, j;
	double_t	tmp;
	int_fast32_t	sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s32);

	tmp	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT32_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT32_MIN)
			goto ovf;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT32_MAX)
		goto ovf;
	if (nextafter(tmp, tmp - 1) < INT32_MIN)
		goto ovf;

	sum	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;
ovf:
	errno	= ERANGE;
	return	INT32_MIN;
}

uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb])
{
	uint_fast64_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		sum += arr[i];
		if (sum < arr[i])
			goto ovf;
	}

	return	sum;
ovf:
	errno	= ERANGE;
	return	UINT32_MAX;
}

int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb])
{
	int64_t		sorted[nmemb];
	ptrdiff_t	i, j;
	double_t	tmp;
	int_fast64_t	sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, nmemb, sizeof(sorted[0]), alx_compare_s64);

	tmp	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			goto ovf;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			goto ovf;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT64_MAX)
		goto ovf;
	if (nextafter(tmp, tmp - 1) < INT64_MIN)
		goto ovf;

	sum	= 0;
	i	= 0;
	j	= nmemb - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;
ovf:
	errno	= ERANGE;
	return	INT64_MIN;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
