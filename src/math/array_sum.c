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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>

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

// FIXME TODO
/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
unsigned	alx_array_sum_uint(ssize_t n, const unsigned arr[restrict n])
{
	double_t	tmp;
	unsigned	sum;

	tmp	= 0;
	for (ssize_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT_MAX) {
		errno	= ERANGE;
		return	UINT_MAX;
	}

	*sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		*sum += arr[i];

	return	sum;
}

int		alx_array_sum_int	(ssize_t n, const int arr[restrict n])
{
	int		sorted[n];
	ssize_t		i, j;
	double_t	tmp;

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
		if (nextafter(tmp, tmp + 1) > INT_MAX) {
			errno	= ERANGE;
			return	1;
		}
		if (nextafter(tmp, tmp - 1) < INT_MIN) {
			errno	= ERANGE;
			return	-1;
		}
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT_MAX) {
		errno	= ERANGE;
		return	1;
	}
	if (nextafter(tmp, tmp - 1) < INT_MIN) {
		errno	= ERANGE;
		return	-1;
	}

	*sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (*sum > 0)
			*sum += arr[i++];
		else
			*sum += arr[j--];
	}
	*sum += arr[i];

	return	0;
}

ssize_t	alx_array_sum_u8	(uint8_t *restrict sum,
				ssize_t n,
				const uint8_t arr[restrict n])
{
	double_t	tmp;

	tmp	= 0;
	for (ssize_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT8_MAX) {
		errno	= ERANGE;
		return	1;
	}

	*sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		*sum += arr[i];

	return	0;
}

static inline
ssize_t	alx_array_sum_s8	(int8_t *restrict sum,
				ssize_t n,
				const int8_t arr[restrict n])
{
	int8_t		sorted[n];
	ssize_t		i, j;
	double_t	tmp;

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
		if (nextafter(tmp, tmp + 1) > INT8_MAX) {
			errno	= ERANGE;
			return	1;
		}
		if (nextafter(tmp, tmp - 1) < INT8_MIN) {
			errno	= ERANGE;
			return	-1;
		}
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT8_MAX) {
		errno	= ERANGE;
		return	1;
	}
	if (nextafter(tmp, tmp - 1) < INT8_MIN) {
		errno	= ERANGE;
		return	-1;
	}

	*sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (*sum > 0)
			*sum += arr[i++];
		else
			*sum += arr[j--];
	}
	*sum += arr[i];

	return	0;
}

ssize_t	alx_array_sum_u16	(uint16_t *restrict sum,
				ssize_t n,
				const uint16_t arr[restrict n])
{
	double_t	tmp;

	tmp	= 0;
	for (ssize_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT16_MAX) {
		errno	= ERANGE;
		return	1;
	}

	*sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		*sum += arr[i];

	return	0;
}

static inline
ssize_t	alx_array_sum_s16	(int16_t *restrict sum,
				ssize_t n,
				const int16_t arr[restrict n])
{
	int16_t		sorted[n];
	ssize_t		i, j;
	double_t	tmp;

	memcpy(sorted, arr, sizeof(sorted));
	qsort(sorted, n, sizeof(sorted[0]), alx_compare_s16;

	tmp	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (tmp > 0)
			tmp += arr[i++];
		else
			tmp += arr[j--];
		if (nextafter(tmp, tmp + 1) > INT16_MAX) {
			errno	= ERANGE;
			return	1;
		}
		if (nextafter(tmp, tmp - 1) < INT16_MIN) {
			errno	= ERANGE;
			return	-1;
		}
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT16_MAX) {
		errno	= ERANGE;
		return	1;
	}
	if (nextafter(tmp, tmp - 1) < INT16_MIN) {
		errno	= ERANGE;
		return	-1;
	}

	*sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (*sum > 0)
			*sum += arr[i++];
		else
			*sum += arr[j--];
	}
	*sum += arr[i];

	return	0;
}

ssize_t	alx_array_sum_u32	(uint32_t *restrict sum,
				ssize_t n,
				const uint32_t arr[restrict n])
{
	double_t	tmp;

	tmp	= 0;
	for (ssize_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT32_MAX) {
		errno	= ERANGE;
		return	1;
	}

	*sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		*sum += arr[i];

	return	0;
}

static inline
ssize_t	alx_array_sum_s32	(int32_t *restrict sum,
				ssize_t n,
				const int32_t arr[restrict n])
{
	int32_t		sorted[n];
	ssize_t		i, j;
	double_t	tmp;

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
		if (nextafter(tmp, tmp + 1) > INT32_MAX) {
			errno	= ERANGE;
			return	1;
		}
		if (nextafter(tmp, tmp - 1) < INT32_MIN) {
			errno	= ERANGE;
			return	-1;
		}
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT32_MAX) {
		errno	= ERANGE;
		return	1;
	}
	if (nextafter(tmp, tmp - 1) < INT32_MIN) {
		errno	= ERANGE;
		return	-1;
	}

	*sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (*sum > 0)
			*sum += arr[i++];
		else
			*sum += arr[j--];
	}
	*sum += arr[i];

	return	0;
}

ssize_t	alx_array_sum_u64	(uint64_t *restrict sum,
				ssize_t n,
				const uint64_t arr[restrict n])
{
	double_t	tmp;

	tmp	= 0;
	for (ssize_t i = 0; i < n; i++)
		tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > UINT64_MAX) {
		errno	= ERANGE;
		return	1;
	}

	*sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		*sum += arr[i];

	return	0;
}

static inline
ssize_t	alx_array_sum_s64	(int64_t *restrict sum,
				ssize_t n,
				const int64_t arr[restrict n])
{
	int64_t		sorted[n];
	ssize_t		i, j;
	double_t	tmp;

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
		if (nextafter(tmp, tmp + 1) > INT64_MAX) {
			errno	= ERANGE;
			return	1;
		}
		if (nextafter(tmp, tmp - 1) < INT64_MIN) {
			errno	= ERANGE;
			return	-1;
		}
	}
	tmp += arr[i];
	if (nextafter(tmp, tmp + 1) > INT64_MAX) {
		errno	= ERANGE;
		return	1;
	}
	if (nextafter(tmp, tmp - 1) < INT64_MIN) {
		errno	= ERANGE;
		return	-1;
	}

	*sum	= 0;
	i	= 0;
	j	= n - 1;
	while (i != j) {
		if (*sum > 0)
			*sum += arr[i++];
		else
			*sum += arr[j--];
	}
	*sum += arr[i];

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
