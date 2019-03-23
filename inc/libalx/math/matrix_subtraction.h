/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_MATRIX_SUBTRACTION_H
#define ALX_MATH_MATRIX_SUBTRACTION_H


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
int	alx_matrix_subtraction_uint	(ptrdiff_t n,
					unsigned dest[n],
					const unsigned src1[n],
					const unsigned src2[n]);
int	alx_matrix_subtraction_int	(ptrdiff_t n,
					int dest[n],
					const int src1[n],
					const int src2[n]);
int	alx_matrix_subtraction_u8	(ptrdiff_t n,
					uint8_t dest[n],
					const uint8_t src1[n],
					const uint8_t src2[n]);
int	alx_matrix_subtraction_s8	(ptrdiff_t n,
					int8_t dest[n],
					const int8_t src1[n],
					const int8_t src2[n]);
int	alx_matrix_subtraction_u16	(ptrdiff_t n,
					uint16_t dest[n],
					const uint16_t src1[n],
					const uint16_t src2[n]);
int	alx_matrix_subtraction_s16	(ptrdiff_t n,
					int16_t dest[n],
					const int16_t src1[n],
					const int16_t src2[n]);
int	alx_matrix_subtraction_u32	(ptrdiff_t n,
					uint32_t dest[n],
					const uint32_t src1[n],
					const uint32_t src2[n]);
int	alx_matrix_subtraction_s32	(ptrdiff_t n,
					int32_t dest[n],
					const int32_t src1[n],
					const int32_t src2[n]);
int	alx_matrix_subtraction_u64	(ptrdiff_t n,
					uint64_t dest[n],
					const uint64_t src1[n],
					const uint64_t src2[n]);
int	alx_matrix_subtraction_s64	(ptrdiff_t n,
					int64_t dest[n],
					const int64_t src1[n],
					const int64_t src2[n]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_matrix_subtraction_ldbl	(ptrdiff_t n,
					long double dest[n],
					const long double src1[n],
					const long double src2[n]);
static inline	void	alx_matrix_subtraction		(ptrdiff_t n,
					double dest[n],
					const double src1[n],
					const double src2[n]);
static inline	void	alx_matrix_subtraction_flt	(ptrdiff_t n,
					float dest[n],
					const float src1[n],
					const float src2[n]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_matrix_subtraction_ldbl	(ptrdiff_t n,
					long double dest[n],
					const long double src1[n],
					const long double src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction		(ptrdiff_t n,
					double dest[n],
					const double src1[n],
					const double src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_flt	(ptrdiff_t n,
					float dest[n],
					const float src1[n],
					const float src2[n])
{

	for (ptrdiff_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/matrix_subtraction.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
