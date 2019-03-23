/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_DIVISION_H
#define ALX_MATH_ARRAY_DIVISION_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
int	alx_array_division_uint	(ptrdiff_t n,
					unsigned dest[restrict n],
					const unsigned src1[restrict n],
					const unsigned src2[restrict n]);
int	alx_array_division_int	(ptrdiff_t n,
					int dest[restrict n],
					const int src1[restrict n],
					const int src2[restrict n]);
int	alx_array_division_u8	(ptrdiff_t n,
					uint8_t dest[restrict n],
					const uint8_t src1[restrict n],
					const uint8_t src2[restrict n]);
int	alx_array_division_s8	(ptrdiff_t n,
					int8_t dest[restrict n],
					const int8_t src1[restrict n],
					const int8_t src2[restrict n]);
int	alx_array_division_u16	(ptrdiff_t n,
					uint16_t dest[restrict n],
					const uint16_t src1[restrict n],
					const uint16_t src2[restrict n]);
int	alx_array_division_s16	(ptrdiff_t n,
					int16_t dest[restrict n],
					const int16_t src1[restrict n],
					const int16_t src2[restrict n]);
int	alx_array_division_u32	(ptrdiff_t n,
					uint32_t dest[restrict n],
					const uint32_t src1[restrict n],
					const uint32_t src2[restrict n]);
int	alx_array_division_s32	(ptrdiff_t n,
					int32_t dest[restrict n],
					const int32_t src1[restrict n],
					const int32_t src2[restrict n]);
int	alx_array_division_u64	(ptrdiff_t n,
					uint64_t dest[restrict n],
					const uint64_t src1[restrict n],
					const uint64_t src2[restrict n]);
int	alx_array_division_s64	(ptrdiff_t n,
					int64_t dest[restrict n],
					const int64_t src1[restrict n],
					const int64_t src2[restrict n]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_array_division_ldbl	(ptrdiff_t n,
					long double dest[restrict n],
					const long double src1[restrict n],
					const long double src2[restrict n]);
static inline	void	alx_array_division	(ptrdiff_t n,
					double dest[restrict n],
					const double src1[restrict n],
					const double src2[restrict n]);
static inline	void	alx_array_division_flt	(ptrdiff_t n,
					float dest[restrict n],
					const float src1[restrict n],
					const float src2[restrict n]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_array_division_ldbl	(ptrdiff_t n,
					long double dest[restrict n],
					const long double src1[restrict n],
					const long double src2[restrict n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] / src2[i];
}

static inline
void	alx_array_division	(ptrdiff_t n,
					double dest[restrict n],
					const double src1[restrict n],
					const double src2[restrict n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] / src2[i];
}

static inline
void	alx_array_division_flt	(ptrdiff_t n,
					float dest[restrict n],
					const float src1[restrict n],
					const float src2[restrict n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] / src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/array_division.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
