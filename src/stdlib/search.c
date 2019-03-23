/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdlib/search.h"

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
ptrdiff_t alx_search_uint(ptrdiff_t n, const unsigned arr[restrict n], unsigned x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_int(ptrdiff_t n, const int arr[restrict n], int x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_u8	(ptrdiff_t n, const uint8_t arr[restrict n], uint8_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_s8	(ptrdiff_t n, const int8_t arr[restrict n], int8_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_u16(ptrdiff_t n, const uint16_t arr[restrict n], uint16_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_s16(ptrdiff_t n, const int16_t arr[restrict n], int16_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_u32(ptrdiff_t n, const uint32_t arr[restrict n], uint32_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_s32(ptrdiff_t n, const int32_t arr[restrict n], int32_t x)
{
	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_u64(ptrdiff_t n, const uint64_t arr[restrict n], uint64_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_search_s64(ptrdiff_t n, const int64_t arr[restrict n], int64_t x)
{

	for (ptrdiff_t i = 0; i < n; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_uint(ptrdiff_t n, const unsigned arr[restrict n], unsigned x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_int(ptrdiff_t n, const int arr[restrict n], int x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_u8(ptrdiff_t n, const uint8_t arr[restrict n], uint8_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_s8(ptrdiff_t n, const int8_t arr[restrict n], int8_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_u16(ptrdiff_t n, const uint16_t arr[restrict n], uint16_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_s16(ptrdiff_t n, const int16_t arr[restrict n], int16_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_u32(ptrdiff_t n, const uint32_t arr[restrict n], uint32_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_s32(ptrdiff_t n, const int32_t arr[restrict n], int32_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_u64(ptrdiff_t n, const uint64_t arr[restrict n], uint64_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}

ptrdiff_t alx_bsearch_s64(ptrdiff_t n, const int64_t arr[restrict n], int64_t x)
{
	ptrdiff_t	lim_hi;
	ptrdiff_t	lim_lo;
	ptrdiff_t	i;

	lim_hi	= n;
	lim_lo	= 0;

	while (lim_hi > lim_lo) {
		i	= (lim_hi + lim_lo) / 2;
		if (arr[i] > x)
			lim_hi	= i;
		else if (arr[i] < x)
			lim_lo	= i + 1;
		else
			return	i;
	}

	return	-1;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
