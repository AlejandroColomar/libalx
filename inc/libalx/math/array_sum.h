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
unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
int		alx_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb]);
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb]);
static inline	long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb]);

static inline	double	alx_dbl_array_sum	(ptrdiff_t nmemb,
					const double arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb]);
static inline	double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb]);

static inline	float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
					const float arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb]);
static inline	float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict nmemb])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
double	alx_dbl_array_sum	(ptrdiff_t nmemb,
				const double arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
				const int arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
				const uint64_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
				const int64_t arr[restrict nmemb])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				const float arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
				const int arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict nmemb])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
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
