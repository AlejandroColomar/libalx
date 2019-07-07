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
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
					 const unsigned *restrict arr)
		__attribute__((nonnull, pure));
int		alx_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr)
		__attribute__((nonnull, pure));
uint8_t		alx_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr)
		__attribute__((nonnull, pure));
int8_t		alx_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr)
		__attribute__((nonnull, pure));
uint16_t	alx_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr)
		__attribute__((nonnull, pure));
int16_t		alx_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr)
		__attribute__((nonnull, pure));
uint32_t	alx_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr)
		__attribute__((nonnull, pure));
int32_t		alx_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr)
		__attribute__((nonnull, pure));
uint64_t	alx_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr)
		__attribute__((nonnull, pure));
int64_t		alx_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr)
		__attribute__((nonnull, pure));
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
inline
long double	ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr)
		__attribute__((nonnull, pure));
inline
long double	ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr)
		__attribute__((nonnull, pure));

inline
double	dbl_array_sum		(ptrdiff_t nmemb,
				 const double *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr)
	__attribute__((nonnull, pure));
inline
double	dbl_array_sum_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr)
	__attribute__((nonnull, pure));

inline
float	flt_array_sum_flt	(ptrdiff_t nmemb,
				 const float *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
	__attribute__((nonnull, pure));
inline
float	flt_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
	__attribute__((nonnull, pure));


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
inline
long double	ldbl_array_sum_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_uint	(ptrdiff_t nmemb,
					 const unsigned *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_int	(ptrdiff_t nmemb,
					 const int *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_u8	(ptrdiff_t nmemb,
					 const uint8_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_u16	(ptrdiff_t nmemb,
					 const uint16_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_u32	(ptrdiff_t nmemb,
					 const uint32_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_u64	(ptrdiff_t nmemb,
					 const uint64_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
long double	ldbl_array_sum_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict arr)
{
	long double	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


inline
double	dbl_array_sum		(ptrdiff_t nmemb,
				 const double *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
double	dbl_array_sum_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr)
{
	double_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


inline
float	flt_array_sum_flt	(ptrdiff_t nmemb,
				 const float *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_uint	(ptrdiff_t nmemb,
				 const unsigned *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_int	(ptrdiff_t nmemb,
				 const int *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}

inline
float	flt_array_sum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr)
{
	float_t	sum;

	sum	= 0;
	for (ptrdiff_t i = 0; i < nmemb; i++)
		sum += arr[i];

	return	sum;
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/array_sum.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
