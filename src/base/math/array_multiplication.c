/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/array_multiplication.h"

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
int	alx_array_multiplication_uint	(ptrdiff_t nmemb,
					unsigned dest[restrict nmemb],
					const unsigned src1[nmemb],
					const unsigned src2[nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > UINT_MAX)
			goto err_wrap;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_array_multiplication_int	(ptrdiff_t nmemb,
					int dest[restrict nmemb],
					const int src1[nmemb],
					const int src2[nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT_MAX)
			goto err_ovf_hi;
		if (nextafter(tmp, tmp - 1) < INT_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u8	(ptrdiff_t nmemb,
					uint8_t dest[restrict nmemb],
					const uint8_t src1[nmemb],
					const uint8_t src2[nmemb])
{
	uint_fast16_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast16_t)src1[i] * (uint_fast16_t)src2[i];
		if (tmp > UINT8_MAX)
			goto err_wrap;
		dest[i]	= tmp;
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_array_multiplication_s8	(ptrdiff_t nmemb,
					int8_t dest[restrict nmemb],
					const int8_t src1[nmemb],
					const int8_t src2[nmemb])
{
	int_fast16_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast16_t)src1[i] * (int_fast16_t)src2[i];
		if (tmp > INT8_MAX)
			goto err_ovf_hi;
		if (tmp < INT8_MIN)
			goto err_ovf_lo;
		dest[i]	= tmp;
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u16	(ptrdiff_t nmemb,
					uint16_t dest[restrict nmemb],
					const uint16_t src1[nmemb],
					const uint16_t src2[nmemb])
{
	uint_fast32_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast32_t)src1[i] * (uint_fast32_t)src2[i];
		if (tmp > UINT16_MAX)
			goto err_wrap;
		dest[i]	= tmp;
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_array_multiplication_s16	(ptrdiff_t nmemb,
					int16_t dest[restrict nmemb],
					const int16_t src1[nmemb],
					const int16_t src2[nmemb])
{
	int_fast32_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast32_t)src1[i] * (int_fast32_t)src2[i];
		if (tmp > INT16_MAX)
			goto err_ovf_hi;
		if (tmp < INT16_MIN)
			goto err_ovf_lo;
		dest[i]	= tmp;
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u32	(ptrdiff_t nmemb,
					uint32_t dest[restrict nmemb],
					const uint32_t src1[nmemb],
					const uint32_t src2[nmemb])
{
	uint_fast64_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (uint_fast64_t)src1[i] * (uint_fast64_t)src2[i];
		if (tmp > UINT32_MAX)
			goto err_wrap;
		dest[i]	= tmp;
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_array_multiplication_s32	(ptrdiff_t nmemb,
					int32_t dest[restrict nmemb],
					const int32_t src1[nmemb],
					const int32_t src2[nmemb])
{
	int_fast64_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (int_fast64_t)src1[i] * (int_fast64_t)src2[i];
		if (tmp > INT32_MAX)
			goto err_ovf_hi;
		if (tmp < INT32_MIN)
			goto err_ovf_lo;
		dest[i]	= tmp;
	}

	return	0;

err_ovf_hi:
	errno	= ERANGE;
	return	1;
err_ovf_lo:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_multiplication_u64	(ptrdiff_t nmemb,
					uint64_t dest[restrict nmemb],
					const uint64_t src1[nmemb],
					const uint64_t src2[nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > UINT64_MAX) 
			goto err_wrap;
		dest[i]	= src1[i] * src2[i];
	}

	return	0;

err_wrap:
	errno	= ERANGE;
	return	1;
}

int	alx_array_multiplication_s64	(ptrdiff_t nmemb,
					int64_t dest[restrict nmemb],
					const int64_t src1[nmemb],
					const int64_t src2[nmemb])
{
	double_t	tmp;

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		tmp	= (double_t)src1[i] * (double_t)src2[i];
		if (nextafter(tmp, tmp + 1) > INT64_MAX)
			goto err_ovf_hi;
		if (nextafter(tmp, tmp - 1) < INT64_MIN)
			goto err_ovf_lo;
		dest[i]	= src1[i] * src2[i];
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
