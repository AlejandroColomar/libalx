/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_SUM_HPP
#define ALX_MATH_ARRAY_SUM_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cmath>
#include <cstddef>
#include <cstdint>

#include "libalx/base/stddef/restrict.hpp"


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
extern	"C"
{
unsigned	alx_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned *restrict arr);
int		alx_array_sum_int	(ptrdiff_t nmemb,
					const int *restrict arr);
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t *restrict arr);
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t *restrict arr);
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict arr);
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t *restrict arr);
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict arr);
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t *restrict arr);
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t *restrict arr);
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t *restrict arr);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double *restrict arr);
static inline	long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned *restrict arr);
static inline	long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int *restrict arr);
static inline	long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t *restrict arr);
static inline	long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t *restrict arr);

static inline	double	alx_dbl_array_sum	(ptrdiff_t nmemb,
					const double *restrict arr);
static inline	double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned *restrict arr);
static inline	double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
					const int *restrict arr);
static inline	double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t *restrict arr);
static inline	double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t *restrict arr);
static inline	double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict arr);
static inline	double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t *restrict arr);
static inline	double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict arr);
static inline	double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t *restrict arr);
static inline	double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t *restrict arr);
static inline	double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t *restrict arr);

static inline	float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
					const float *restrict arr);
static inline	float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned *restrict arr);
static inline	float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
					const int *restrict arr);
static inline	float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t *restrict arr);
static inline	float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t *restrict arr);
static inline	float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict arr);
static inline	float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t *restrict arr);
static inline	float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict arr);
static inline	float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t *restrict arr);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
double	alx_dbl_array_sum	(ptrdiff_t nmemb,
				const double *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
				const int *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
				const uint64_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
				const int64_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				const float *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
				const int *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t *restrict arr)
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
#endif		/* libalx/base/math/array_sum.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
