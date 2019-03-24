/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdlib/maximum.h"

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
ptrdiff_t	alx_maximum_ldbl(ptrdiff_t n, const long double arr[restrict n])
{
	ptrdiff_t	pos;
	long double	val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum	(ptrdiff_t n, const double arr[restrict n])
{
	ptrdiff_t	pos;
	double		val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_f	(ptrdiff_t n, const float arr[restrict n])
{
	ptrdiff_t	pos;
	float		val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_uint(ptrdiff_t n, const unsigned arr[restrict n])
{
	ptrdiff_t	pos;
	unsigned	val;

	pos	= 0;
	val	= INT_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_int	(ptrdiff_t n, const int arr[restrict n])
{
	ptrdiff_t	pos;
	int		val;

	pos	= 0;
	val	= INT_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u8	(ptrdiff_t n, const uint8_t arr[restrict n])
{
	ptrdiff_t	pos;
	uint8_t		val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s8	(ptrdiff_t n, const int8_t arr[restrict n])
{
	ptrdiff_t	pos;
	int8_t		val;

	pos	= 0;
	val	= INT8_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u16	(ptrdiff_t n, const uint16_t arr[restrict n])
{
	ptrdiff_t	pos;
	uint16_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s16	(ptrdiff_t n, const int16_t arr[restrict n])
{
	ptrdiff_t	pos;
	int16_t		val;

	pos	= 0;
	val	= INT16_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u32	(ptrdiff_t n, const uint32_t arr[restrict n])
{
	ptrdiff_t	pos;
	uint32_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s32	(ptrdiff_t n, const int32_t arr[restrict n])
{
	ptrdiff_t	pos;
	int32_t		val;

	pos	= 0;
	val	= INT32_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u64	(ptrdiff_t n, const uint64_t arr[restrict n])
{
	ptrdiff_t	pos;
	uint64_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s64	(ptrdiff_t n, const int64_t arr[restrict n])
{
	ptrdiff_t	pos;
	int64_t		val;

	pos	= 0;
	val	= INT64_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_pdif(ptrdiff_t n, const ptrdiff_t arr[restrict n])
{
	ptrdiff_t	pos;
	ptrdiff_t	val;

	pos	= 0;
	val	= INT64_MIN;
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
