/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/maximum.h"

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
ptrdiff_t	alx_maximum_ldbl(ptrdiff_t nmemb,
				const long double arr[restrict nmemb])
{
	ptrdiff_t	pos;
	long double	val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum	(ptrdiff_t nmemb,
				const double arr[restrict nmemb])
{
	ptrdiff_t	pos;
	double		val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_f	(ptrdiff_t nmemb,
				const float arr[restrict nmemb])
{
	ptrdiff_t	pos;
	float		val;

	pos	= 0;
	val	= -INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_uint(ptrdiff_t nmemb,
				const unsigned arr[restrict nmemb])
{
	ptrdiff_t	pos;
	unsigned	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_int	(ptrdiff_t nmemb,
				const int arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int		val;

	pos	= 0;
	val	= INT_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast8_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast8_t	val;

	pos	= 0;
	val	= INT8_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast16_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast16_t	val;

	pos	= 0;
	val	= INT16_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast32_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast32_t	val;

	pos	= 0;
	val	= INT32_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_u64	(ptrdiff_t nmemb,
				const uint64_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast64_t	val;

	pos	= 0;
	val	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_s64	(ptrdiff_t nmemb,
				const int64_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast64_t	val;

	pos	= 0;
	val	= INT64_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] >= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_maximum_pdif(ptrdiff_t nmemb,
				const ptrdiff_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	ptrdiff_t	val;

	pos	= 0;
	val	= PTRDIFF_MIN;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
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
