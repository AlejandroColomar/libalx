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
					const unsigned arr[restrict]);
int		alx_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict]);
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict]);
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict]);
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict]);
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict]);
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict]);
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict]);
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict]);
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict]);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double arr[restrict]);
static inline	long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict]);
static inline	long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict]);
static inline	long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict]);
static inline	long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict]);

static inline	double	alx_dbl_array_sum	(ptrdiff_t nmemb,
					const double arr[restrict]);
static inline	double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict]);
static inline	double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict]);
static inline	double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict]);
static inline	double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict]);
static inline	double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict]);
static inline	double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict]);
static inline	double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict]);
static inline	double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict]);
static inline	double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict]);
static inline	double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict]);

static inline	float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
					const float arr[restrict]);
static inline	float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict]);
static inline	float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict]);
static inline	float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict]);
static inline	float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict]);
static inline	float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict]);
static inline	float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict]);
static inline	float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict]);
static inline	float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
long double	alx_ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					const long double arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_uint	(ptrdiff_t nmemb,
					const unsigned arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_int	(ptrdiff_t nmemb,
					const int arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u8	(ptrdiff_t nmemb,
					const uint8_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s8	(ptrdiff_t nmemb,
					const int8_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u16	(ptrdiff_t nmemb,
					const uint16_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s16	(ptrdiff_t nmemb,
					const int16_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u32	(ptrdiff_t nmemb,
					const uint32_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s32	(ptrdiff_t nmemb,
					const int32_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_u64	(ptrdiff_t nmemb,
					const uint64_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
long double	alx_ldbl_array_sum_s64	(ptrdiff_t nmemb,
					const int64_t arr[restrict])
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
double	alx_dbl_array_sum	(ptrdiff_t nmemb,
				const double arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_int	(ptrdiff_t nmemb,
				const int arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_u64	(ptrdiff_t nmemb,
				const uint64_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
double	alx_dbl_array_sum_s64	(ptrdiff_t nmemb,
				const int64_t arr[restrict])
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


static inline
float	alx_flt_array_sum_flt	(ptrdiff_t nmemb,
				const float arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_uint	(ptrdiff_t nmemb,
				const unsigned arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_int	(ptrdiff_t nmemb,
				const int arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u8	(ptrdiff_t nmemb,
				const uint8_t arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s8	(ptrdiff_t nmemb,
				const int8_t arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u16	(ptrdiff_t nmemb,
				const uint16_t arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s16	(ptrdiff_t nmemb,
				const int16_t arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_u32	(ptrdiff_t nmemb,
				const uint32_t arr[restrict])
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

static inline
float	alx_flt_array_sum_s32	(ptrdiff_t nmemb,
				const int32_t arr[restrict])
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
#endif		/* libalx/math/array_sum.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
