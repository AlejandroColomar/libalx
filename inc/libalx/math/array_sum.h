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
 ******* extern functions *****************************************************
 ******************************************************************************/
int	alx_array_sum_uint	(unsigned *restrict sum,
					ssize_t n,
					const unsigned arr[restrict n]);
int	alx_array_sum_int	(int *restrict sum,
					ssize_t n,
					const int arr[restrict n]);
int	alx_array_sum_u8	(uint8_t *restrict sum,
					ssize_t n,
					const uint8_t arr[restrict n]);
int	alx_array_sum_s8	(int8_t *restrict sum,
					ssize_t n,
					const int8_t arr[restrict n]);
int	alx_array_sum_u16	(uint16_t *restrict sum,
					ssize_t n,
					const uint16_t arr[restrict n]);
int	alx_array_sum_s16	(int16_t *restrict sum,
					ssize_t n,
					const int16_t arr[restrict n]);
int	alx_array_sum_u32	(uint32_t *restrict sum,
					ssize_t n,
					const uint32_t arr[restrict n]);
int	alx_array_sum_s32	(int32_t *restrict sum,
					ssize_t n,
					const int32_t arr[restrict n]);
int	alx_array_sum_u64	(uint64_t *restrict sum,
					ssize_t n,
					const uint64_t arr[restrict n]);
int	alx_array_sum_s64	(int64_t *restrict sum,
					ssize_t n,
					const int64_t arr[restrict n]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_array_sum_ldbl	(ssize_t n,
					const long double arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_uint	(ssize_t n,
					const unsigned arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_int	(ssize_t n,
					const int arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u8	(ssize_t n,
					const uint8_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s8	(ssize_t n,
					const int8_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u16	(ssize_t n,
					const uint16_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s16	(ssize_t n,
					const int16_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u32	(ssize_t n,
					const uint32_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s32	(ssize_t n,
					const int32_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_u64	(ssize_t n,
					const uint64_t arr[restrict n]);
static inline	long double	alx_ldbl_array_sum_s64	(ssize_t n,
					const int64_t arr[restrict n]);

static inline	double	alx_dbl_array_sum	(ssize_t n,
					const double arr[restrict n]);
static inline	double	alx_dbl_array_sum_uint	(ssize_t n,
					const unsigned arr[restrict n]);
static inline	double	alx_dbl_array_sum_int	(ssize_t n,
					const int arr[restrict n]);
static inline	double	alx_dbl_array_sum_u8	(ssize_t n,
					const uint8_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s8	(ssize_t n,
					const int8_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u16	(ssize_t n,
					const uint16_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s16	(ssize_t n,
					const int16_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u32	(ssize_t n,
					const uint32_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s32	(ssize_t n,
					const int32_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_u64	(ssize_t n,
					const uint64_t arr[restrict n]);
static inline	double	alx_dbl_array_sum_s64	(ssize_t n,
					const int64_t arr[restrict n]);

static inline	float	alx_flt_array_sum_flt	(ssize_t n,
					const float arr[restrict n]);
static inline	float	alx_flt_array_sum_uint	(ssize_t n,
					const unsigned arr[restrict n]);
static inline	float	alx_flt_array_sum_int	(ssize_t n,
					const int arr[restrict n]);
static inline	float	alx_flt_array_sum_u8	(ssize_t n,
					const uint8_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s8	(ssize_t n,
					const int8_t arr[restrict n]);
static inline	float	alx_flt_array_sum_u16	(ssize_t n,
					const uint16_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s16	(ssize_t n,
					const int16_t arr[restrict n]);
static inline	float	alx_flt_array_sum_u32	(ssize_t n,
					const uint32_t arr[restrict n]);
static inline	float	alx_flt_array_sum_s32	(ssize_t n,
					const int32_t arr[restrict n]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_array_sum_ldbl	(ssize_t n,
					const long double arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_uint	(ssize_t n,
					const unsigned arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_int	(ssize_t n,
					const int arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u8	(ssize_t n,
					const uint8_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s8	(ssize_t n,
					const int8_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u16	(ssize_t n,
					const uint16_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s16	(ssize_t n,
					const int16_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u32	(ssize_t n,
					const uint32_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s32	(ssize_t n,
					const int32_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u64	(ssize_t n,
					const uint64_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s64	(ssize_t n,
					const int64_t arr[restrict n])
{
	long double	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}


static inline
double	alx_dbl_array_sum	(ssize_t n, const double arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_uint	(ssize_t n, const unsigned arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_int	(ssize_t n, const int arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u8	(ssize_t n, const uint8_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s8	(ssize_t n, const int8_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u16	(ssize_t n, const uint16_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s16	(ssize_t n, const int16_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u32	(ssize_t n, const uint32_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s32	(ssize_t n, const int32_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u64	(ssize_t n, const uint64_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s64	(ssize_t n, const int64_t arr[restrict n])
{
	double_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}


static inline
float	alx_flt_array_sum_flt	(ssize_t n, const float arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_uint	(ssize_t n, const unsigned arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_int	(ssize_t n, const int arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u8	(ssize_t n, const uint8_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s8	(ssize_t n, const int8_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u16	(ssize_t n, const uint16_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s16	(ssize_t n, const int16_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u32	(ssize_t n, const uint32_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s32	(ssize_t n, const int32_t arr[restrict n])
{
	float_t	sum;

	sum	= 0;
	for (ssize_t i = 0; i < n; i++)
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
