/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/matrix_subtraction.h"

#include <limits.h>
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
int	alx_matrix_subtraction_uint	(ssize_t n,
					unsigned dest[restrict n],
					const unsigned src1[restrict n],
					const unsigned src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_int	(ssize_t n,
					int dest[restrict n],
					const int src1[restrict n],
					const int src2[restrict n])
{
	double_t	tmp;

	for (ssize_t i = 0; i < n; i++) {
		tmp	= (double_t)src1[i] - (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			return	1;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_u8	(ssize_t n,
					uint8_t dest[restrict n],
					const uint8_t src1[restrict n],
					const uint8_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_s8	(ssize_t n,
					int8_t dest[restrict n],
					const int8_t src1[restrict n],
					const int8_t src2[restrict n])
{
	int_fast16_t	tmp;

	for (ssize_t i = 0; i < n; i++) {
		tmp	= (int_fast16_t)src1[i] - (int_fast16_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT8_MAX)
			return	1;
		if (nextafter(tmp, tmp - 1) < INT8_MIN)
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_u16	(ssize_t n,
					uint16_t dest[restrict n],
					const uint16_t src1[restrict n],
					const uint16_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_s16	(ssize_t n,
					int16_t dest[restrict n],
					const int16_t src1[restrict n],
					const int16_t src2[restrict n])
{
	int_fast32_t	tmp;

	for (ssize_t i = 0; i < n; i++) {
		tmp	= (int_fast32_t)src1[i] - (int_fast32_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT16_MAX)
			return	1;
		if (nextafter(tmp, tmp - 1) < INT16_MIN)
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_u32	(ssize_t n,
					uint32_t dest[restrict n],
					const uint32_t src1[restrict n],
					const uint32_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_s32	(ssize_t n,
					int32_t dest[restrict n],
					const int32_t src1[restrict n],
					const int32_t src2[restrict n])
{
	int_fast64_t	tmp;

	for (ssize_t i = 0; i < n; i++) {
		tmp	= (int_fast64_t)src1[i] - (int_fast64_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT32_MAX)
			return	1;
		if (nextafter(tmp, tmp - 1) < INT32_MIN)
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_u64	(ssize_t n,
					uint64_t dest[restrict n],
					const uint64_t src1[restrict n],
					const uint64_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}

int	alx_matrix_subtraction_s64	(ssize_t n,
					int64_t dest[restrict n],
					const int64_t src1[restrict n],
					const int64_t src2[restrict n])
{
	double_t	tmp;

	for (ssize_t i = 0; i < n; i++) {
		tmp	= (double_t)src1[i] - (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			return	1;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			return	-1;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;
}



/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
