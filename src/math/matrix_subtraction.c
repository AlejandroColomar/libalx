/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/matrix_subtraction.h"

#include <errno.h>
#include <limits.h>
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
int	alx_matrix_subtraction_uint	(ptrdiff_t n,
					unsigned dest[n],
					const unsigned src1[n],
					const unsigned src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			goto err_wrap;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_matrix_subtraction_int	(ptrdiff_t n,
					int dest[n],
					const int src1[n],
					const int src2[n])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < n; i++) {
		tmp	= (double_t)src1[i] - (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			goto err_ovf_hi;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_matrix_subtraction_u8	(ptrdiff_t n,
					uint8_t dest[n],
					const uint8_t src1[n],
					const uint8_t src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			goto err_wrap;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_matrix_subtraction_s8	(ptrdiff_t n,
					int8_t dest[n],
					const int8_t src1[n],
					const int8_t src2[n])
{
	int_fast16_t	tmp;

	for (ptrdiff_t i = 0; i < n; i++) {
		tmp	= (int_fast16_t)src1[i] - (int_fast16_t)src2[i];
		if (tmp > INT8_MAX)
			goto err_ovf_hi;
		if (tmp < INT8_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_matrix_subtraction_u16	(ptrdiff_t n,
					uint16_t dest[n],
					const uint16_t src1[n],
					const uint16_t src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			goto err_wrap;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_matrix_subtraction_s16	(ptrdiff_t n,
					int16_t dest[n],
					const int16_t src1[n],
					const int16_t src2[n])
{
	int_fast32_t	tmp;

	for (ptrdiff_t i = 0; i < n; i++) {
		tmp	= (int_fast32_t)src1[i] - (int_fast32_t)src2[i];
		if (tmp > INT16_MAX)
			goto err_ovf_hi;
		if (tmp < INT16_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_matrix_subtraction_u32	(ptrdiff_t n,
					uint32_t dest[n],
					const uint32_t src1[n],
					const uint32_t src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			goto err_wrap;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_matrix_subtraction_s32	(ptrdiff_t n,
					int32_t dest[n],
					const int32_t src1[n],
					const int32_t src2[n])
{
	int_fast64_t	tmp;

	for (ptrdiff_t i = 0; i < n; i++) {
		tmp	= (int_fast64_t)src1[i] - (int_fast64_t)src2[i];
		if (tmp > INT32_MAX)
			goto err_ovf_hi;
		if (tmp < INT32_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_matrix_subtraction_u64	(ptrdiff_t n,
					uint64_t dest[n],
					const uint64_t src1[n],
					const uint64_t src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (src1[i] < src2[i])
			goto err_wrap;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_matrix_subtraction_s64	(ptrdiff_t n,
					int64_t dest[n],
					const int64_t src1[n],
					const int64_t src2[n])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < n; i++) {
		tmp	= (double_t)src1[i] - (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			goto err_ovf_hi;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] - src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}



/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
