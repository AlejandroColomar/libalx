/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_DIVISION_HPP
#define ALX_MATH_ARRAY_DIVISION_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
int	alx_array_division_uint	(ptrdiff_t nmemb,
					unsigned *restrict dest,
					const unsigned *restrict src1,
					const unsigned *restrict src2);
int	alx_array_division_int	(ptrdiff_t nmemb,
					int *restrict dest,
					const int *restrict src1,
					const int *restrict src2);
int	alx_array_division_u8	(ptrdiff_t nmemb,
					uint8_t *restrict dest,
					const uint8_t *restrict src1,
					const uint8_t *restrict src2);
int	alx_array_division_s8	(ptrdiff_t nmemb,
					int8_t *restrict dest,
					const int8_t *restrict src1,
					const int8_t *restrict src2);
int	alx_array_division_u16	(ptrdiff_t nmemb,
					uint16_t *restrict dest,
					const uint16_t *restrict src1,
					const uint16_t *restrict src2);
int	alx_array_division_s16	(ptrdiff_t nmemb,
					int16_t *restrict dest,
					const int16_t *restrict src1,
					const int16_t *restrict src2);
int	alx_array_division_u32	(ptrdiff_t nmemb,
					uint32_t *restrict dest,
					const uint32_t *restrict src1,
					const uint32_t *restrict src2);
int	alx_array_division_s32	(ptrdiff_t nmemb,
					int32_t *restrict dest,
					const int32_t *restrict src1,
					const int32_t *restrict src2);
int	alx_array_division_u64	(ptrdiff_t nmemb,
					uint64_t *restrict dest,
					const uint64_t *restrict src1,
					const uint64_t *restrict src2);
int	alx_array_division_s64	(ptrdiff_t nmemb,
					int64_t *restrict dest,
					const int64_t *restrict src1,
					const int64_t *restrict src2);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_array_division_ldbl	(ptrdiff_t nmemb,
					long double *restrict dest,
					const long double *restrict src1,
					const long double *restrict src2);
static inline	void	alx_array_division	(ptrdiff_t nmemb,
					double *restrict dest,
					const double *restrict src1,
					const double *restrict src2);
static inline	void	alx_array_division_flt	(ptrdiff_t nmemb,
					float *restrict dest,
					const float *restrict src1,
					const float *restrict src2);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_array_division_ldbl	(ptrdiff_t nmemb,
					long double *restrict dest,
					const long double *restrict src1,
					const long double *restrict src2)
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] / src2[i];
}

static inline
void	alx_array_division	(ptrdiff_t nmemb,
					double *restrict dest,
					const double *restrict src1,
					const double *restrict src2)
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] / src2[i];
}

static inline
void	alx_array_division_flt	(ptrdiff_t nmemb,
					float *restrict dest,
					const float *restrict src1,
					const float *restrict src2)
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] / src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/array_division.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
