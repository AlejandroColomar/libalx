/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/minimum.h"

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
ptrdiff_t	alx_minimum_ldbl(ptrdiff_t nmemb,
				const long double arr[restrict nmemb])
{
	ptrdiff_t	pos;
	long double	val;

	pos	= 0;
	val	= INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum	(ptrdiff_t nmemb,
				const double arr[restrict nmemb])
{
	ptrdiff_t	pos;
	double		val;

	pos	= 0;
	val	= INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_f	(ptrdiff_t nmemb,
				const float arr[restrict nmemb])
{
	ptrdiff_t	pos;
	float		val;

	pos	= 0;
	val	= INFINITY;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_uint(ptrdiff_t nmemb,
				const unsigned arr[restrict nmemb])
{
	ptrdiff_t	pos;
	unsigned	val;

	pos	= 0;
	val	= UINT_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_int	(ptrdiff_t nmemb,
				const int arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int		val;

	pos	= 0;
	val	= INT_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast8_t	val;

	pos	= 0;
	val	= UINT8_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast8_t	val;

	pos	= 0;
	val	= INT8_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast16_t	val;

	pos	= 0;
	val	= UINT16_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast16_t	val;

	pos	= 0;
	val	= INT16_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast32_t	val;

	pos	= 0;
	val	= UINT32_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast32_t	val;

	pos	= 0;
	val	= INT32_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_u64	(ptrdiff_t nmemb,
				const uint64_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	uint_fast64_t	val;

	pos	= 0;
	val	= UINT64_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_s64	(ptrdiff_t nmemb,
				const int64_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	int_fast64_t	val;

	pos	= 0;
	val	= INT64_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
			val	= arr[i];
			pos	= i;
		}
	}

	return	pos;
}

ptrdiff_t	alx_minimum_pdif(ptrdiff_t nmemb,
				const ptrdiff_t arr[restrict nmemb])
{
	ptrdiff_t	pos;
	ptrdiff_t	val;

	pos	= 0;
	val	= PTRDIFF_MAX;
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] <= val) {
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
