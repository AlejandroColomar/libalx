/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/compare.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
 ******* function prototypes **************************************************
 ******************************************************************************/
inline
int	alx_compare_ldbl(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline	
int	alx_compare	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_f	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_uint(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_int	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_u8	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_s8	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_u16	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_s16	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_u32	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_s32	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_u64	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));
inline
int	alx_compare_s64	(const void *a_ptr, const void *b_ptr)
__attribute__((nonnull, pure));


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
int	alx_compare_ldbl(const void *a_ptr, const void *b_ptr)
{
	long double	a =	*(long double *)a_ptr;
	long double	b =	*(long double *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare	(const void *a_ptr, const void *b_ptr)
{
	double	a =	*(double *)a_ptr;
	double	b =	*(double *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_f	(const void *a_ptr, const void *b_ptr)
{
	float	a =	*(float *)a_ptr;
	float	b =	*(float *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_uint(const void *a_ptr, const void *b_ptr)
{
	unsigned	a =	*(unsigned *)a_ptr;
	unsigned	b =	*(unsigned *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_int	(const void *a_ptr, const void *b_ptr)
{
	int	a =	*(int *)a_ptr;
	int	b =	*(int *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_u8	(const void *a_ptr, const void *b_ptr)
{
	uint8_t	a =	*(uint8_t *)a_ptr;
	uint8_t	b =	*(uint8_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_s8	(const void *a_ptr, const void *b_ptr)
{
	int8_t	a =	*(int8_t *)a_ptr;
	int8_t	b =	*(int8_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_u16	(const void *a_ptr, const void *b_ptr)
{
	uint16_t	a =	*(uint16_t *)a_ptr;
	uint16_t	b =	*(uint16_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_s16	(const void *a_ptr, const void *b_ptr)
{
	int16_t	a =	*(int16_t *)a_ptr;
	int16_t	b =	*(int16_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_u32	(const void *a_ptr, const void *b_ptr)
{
	uint32_t	a =	*(uint32_t *)a_ptr;
	uint32_t	b =	*(uint32_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_s32	(const void *a_ptr, const void *b_ptr)
{
	int32_t	a =	*(int32_t *)a_ptr;
	int32_t	b =	*(int32_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_u64	(const void *a_ptr, const void *b_ptr)
{
	uint64_t	a =	*(uint64_t *)a_ptr;
	uint64_t	b =	*(uint64_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

inline
int	alx_compare_s64	(const void *a_ptr, const void *b_ptr)
{
	int64_t	a =	*(int64_t *)a_ptr;
	int64_t	b =	*(int64_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
