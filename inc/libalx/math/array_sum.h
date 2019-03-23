/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_SUM_H
#define ALX_MATH_ARRAY_SUM_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
 ******* extern functions *****************************************************
 ******************************************************************************/
unsigned	alx_array_sum_uint(ptrdiff_t n, const unsigned arr[restrict n]);
int		alx_array_sum_int(ptrdiff_t n, const int arr[restrict n]);
uint8_t		alx_array_sum_u8(ptrdiff_t n, const uint8_t arr[restrict n]);
int8_t		alx_array_sum_s8(ptrdiff_t n, const int8_t arr[restrict n]);
uint16_t	alx_array_sum_u16(ptrdiff_t n, const uint16_t arr[restrict n]);
int16_t		alx_array_sum_s16(ptrdiff_t n, const int16_t arr[restrict n]);
uint32_t	alx_array_sum_u32(ptrdiff_t n, const uint32_t arr[restrict n]);
int32_t		alx_array_sum_s32(ptrdiff_t n, const int32_t arr[restrict n]);
uint64_t	alx_array_sum_u64(ptrdiff_t n, const uint64_t arr[restrict n]);
int64_t		alx_array_sum_s64(ptrdiff_t n, const int64_t arr[restrict n]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t n,
					const long double arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_uint	(ptrdiff_t n,
					const unsigned arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_int	(ptrdiff_t n,
					const int arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u8	(ptrdiff_t n,
					const uint8_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s8	(ptrdiff_t n,
					const int8_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u16	(ptrdiff_t n,
					const uint16_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s16	(ptrdiff_t n,
					const int16_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u32	(ptrdiff_t n,
					const uint32_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s32	(ptrdiff_t n,
					const int32_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u64	(ptrdiff_t n,
					const uint64_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s64	(ptrdiff_t n,
					const int64_t arr[restrict n]);

static inline	double	alx_dbl_array_sum	(ptrdiff_t n,
					const double arr[restrict n]);
static inline	double	alx_dbl_array_sum_uint	(ptrdiff_t n,
					const unsigned arr[restrict n]);
static inline	double	alx_dbl_array_sum_int	(ptrdiff_t n,
					const int arr[restrict n]);
static inline	double	alx_dbl_array_sum_u8	(ptrdiff_t n,
					const uint8_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s8	(ptrdiff_t n,
					const int8_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u16	(ptrdiff_t n,
					const uint16_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s16	(ptrdiff_t n,
					const int16_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u32	(ptrdiff_t n,
					const uint32_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s32	(ptrdiff_t n,
					const int32_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u64	(ptrdiff_t n,
					const uint64_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s64	(ptrdiff_t n,
					const int64_t arr[restrict n]);

static inline	float	alx_flt_array_sum_flt	(ptrdiff_t n,
					const float arr[restrict n]);
static inline	float	alx_flt_array_sum_uint	(ptrdiff_t n,
					const unsigned arr[restrict n]);
static inline	float	alx_flt_array_sum_int	(ptrdiff_t n,
					const int arr[restrict n]);
static inline	float	alx_flt_array_sum_u8	(ptrdiff_t n,
					const uint8_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s8	(ptrdiff_t n,
					const int8_t arr[restrict n]);
static inline	float	alx_flt_array_sum_u16	(ptrdiff_t n,
					const uint16_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s16	(ptrdiff_t n,
					const int16_t arr[restrict n]);
static inline	float	alx_flt_array_sum_u32	(ptrdiff_t n,
					const uint32_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s32	(ptrdiff_t n,
					const int32_t arr[restrict n]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t n,
					const long double arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t n,
					const unsigned arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t n,
					const int arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t n,
					const uint8_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t n,
					const int8_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t n,
					const uint16_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t n,
					const int16_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t n,
					const uint32_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t n,
					const int32_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t n,
					const uint64_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t n,
					const int64_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}


static inline
double	alx_dbl_array_sum	(ptrdiff_t n, const double arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_uint	(ptrdiff_t n, const unsigned arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_int	(ptrdiff_t n, const int arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u8	(ptrdiff_t n, const uint8_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s8	(ptrdiff_t n, const int8_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u16	(ptrdiff_t n, const uint16_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s16	(ptrdiff_t n, const int16_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u32	(ptrdiff_t n, const uint32_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s32	(ptrdiff_t n, const int32_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u64	(ptrdiff_t n, const uint64_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s64	(ptrdiff_t n, const int64_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}


static inline
float	alx_flt_array_sum_flt	(ptrdiff_t n, const float arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_uint	(ptrdiff_t n, const unsigned arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_int	(ptrdiff_t n, const int arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u8	(ptrdiff_t n, const uint8_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s8	(ptrdiff_t n, const int8_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u16	(ptrdiff_t n, const uint16_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s16	(ptrdiff_t n, const int16_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u32	(ptrdiff_t n, const uint32_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s32	(ptrdiff_t n, const int32_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/array_sum.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
