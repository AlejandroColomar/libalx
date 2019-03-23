/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/array_sum.h"

#include <errno.h>
#include <limits.h>
#include <math.h>
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
unsigned	alx_array_sum_uint(ptrdiff_t n, const unsigned arr[restrict n])
{
	double_t	tmp;
	unsigned	sum;

	tmp	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT_MAX)
		goto err_range;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;

err_range:
	errno	= ERANGE;
	return	UINT_MAX;
}

int		alx_array_sum_int(ptrdiff_t n, const int arr[restrict n])
{
	int		sorted[n];
	ptrdiff_t	i, j;
	double_t	tmp;
	int		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_int);

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			goto err_range_hi;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			goto err_range_lo;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT_MAX)
		goto err_range_hi;
	if (nextafter(tmp, tmp - 1) < INT_MIN)
		goto err_range_lo;

	sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	sum;

err_range_hi:
	errno	= ERANGE;
	return	INT_MAX;
err_range_lo:
	errno	= ERANGE;
	return	INT_MIN;
}

uint8_t		alx_array_sum_u8(ptrdiff_t n, const uint8_t arr[restrict n])
{
	double_t	tmp;
	uint8_t		sum;

	tmp	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT8_MAX)
		goto err_range;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	0;

err_range:
	errno	= ERANGE;
	return	UINT8_MAX;
}

int8_t		alx_array_sum_s8(ptrdiff_t n, const int8_t arr[restrict n])
{
	int8_t		sorted[n];
	ptrdiff_t	i, j;
	double_t	tmp;
	int8_t		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s8);

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT8_MAX)
			goto err_range_hi;
		if (nextafter(tmp, tmp - 1) < INT8_MIN)
			goto err_range_lo;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT8_MAX)
		goto err_range_hi;
	if (nextafter(tmp, tmp - 1) < INT8_MIN)
		goto err_range_lo;

	sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	0;

err_range_hi:
	errno	= ERANGE;
	return	INT8_MAX;
err_range_lo:
	errno	= ERANGE;
	return	INT8_MIN;
}

uint16_t	alx_array_sum_u16(ptrdiff_t n, const uint16_t arr[restrict n])
{
	double_t	tmp;
	uint16_t	sum;

	tmp	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT16_MAX)
		goto err_range;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	0;

err_range:
	errno	= ERANGE;
	return	UINT16_MAX;
}

int16_t		alx_array_sum_s16(ptrdiff_t n, const int16_t arr[restrict n])
{
	int16_t		sorted[n];
	ptrdiff_t	i, j;
	double_t	tmp;
	int16_t		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s16);

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT16_MAX)
			goto err_range_hi;
		if (nextafter(tmp, tmp - 1) < INT16_MIN)
			goto err_range_lo;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT16_MAX)
		goto err_range_hi;
	if (nextafter(tmp, tmp - 1) < INT16_MIN)
		goto err_range_lo;

	sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	0;

err_range_hi:
	errno	= ERANGE;
	return	INT16_MAX;
err_range_lo:
	errno	= ERANGE;
	return	INT16_MIN;
}

uint32_t	alx_array_sum_u32(ptrdiff_t n, const uint32_t arr[restrict n])
{
	double_t	tmp;
	uint32_t	sum;

	tmp	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT32_MAX)
		goto err_range;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	0;

err_range:
	errno	= ERANGE;
	return	UINT32_MAX;
}

int32_t		alx_array_sum_s32(ptrdiff_t n, const int32_t arr[restrict n])
{
	int32_t		sorted[n];
	ptrdiff_t	i, j;
	double_t	tmp;
	int32_t		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s32);

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT32_MAX)
			goto err_range_hi;
		if (nextafter(tmp, tmp - 1) < INT32_MIN)
			goto err_range_lo;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT32_MAX)
		goto err_range_hi;
	if (nextafter(tmp, tmp - 1) < INT32_MIN)
		goto err_range_lo;

	sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	0;

err_range_hi:
	errno	= ERANGE;
	return	INT32_MAX;
err_range_lo:
	errno	= ERANGE;
	return	INT32_MIN;
}

uint64_t	alx_array_sum_u64(ptrdiff_t n, const uint64_t arr[restrict n])
{
	double_t	tmp;
	uint64_t	sum;

	tmp	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT64_MAX)
		goto err_range;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	0;

err_range:
	errno	= ERANGE;
	return	UINT32_MAX;
}

int64_t		alx_array_sum_s64(ptrdiff_t n, const int64_t arr[restrict n])
{
	int64_t		sorted[n];
	ptrdiff_t	i, j;
	double_t	tmp;
	int64_t		sum;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s64);

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			goto err_range_hi;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			goto err_range_lo;
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT64_MAX)
		goto err_range_hi;
	if (nextafter(tmp, tmp - 1) < INT64_MIN)
		goto err_range_lo;

	sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (sum > 0)
			sum += arr[i++];
		else
			sum += arr[j--];
	}
	sum += arr[i];

	return	0;

err_range_hi:
	errno	= ERANGE;
	return	INT64_MAX;
err_range_lo:
	errno	= ERANGE;
	return	INT64_MIN;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
