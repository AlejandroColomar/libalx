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
int	alx_matrix_subtraction_uint	(ptrdiff_t nmemb,
					unsigned dest[nmemb],
					const unsigned src1[nmemb],
					const unsigned src2[nmemb]);
int	alx_matrix_subtraction_int	(ptrdiff_t nmemb,
					int dest[nmemb],
					const int src1[nmemb],
					const int src2[nmemb]);
int	alx_matrix_subtraction_u8	(ptrdiff_t nmemb,
					uint8_t dest[nmemb],
					const uint8_t src1[nmemb],
					const uint8_t src2[nmemb]);
int	alx_matrix_subtraction_s8	(ptrdiff_t nmemb,
					int8_t dest[nmemb],
					const int8_t src1[nmemb],
					const int8_t src2[nmemb]);
int	alx_matrix_subtraction_u16	(ptrdiff_t nmemb,
					uint16_t dest[nmemb],
					const uint16_t src1[nmemb],
					const uint16_t src2[nmemb]);
int	alx_matrix_subtraction_s16	(ptrdiff_t nmemb,
					int16_t dest[nmemb],
					const int16_t src1[nmemb],
					const int16_t src2[nmemb]);
int	alx_matrix_subtraction_u32	(ptrdiff_t nmemb,
					uint32_t dest[nmemb],
					const uint32_t src1[nmemb],
					const uint32_t src2[nmemb]);
int	alx_matrix_subtraction_s32	(ptrdiff_t nmemb,
					int32_t dest[nmemb],
					const int32_t src1[nmemb],
					const int32_t src2[nmemb]);
int	alx_matrix_subtraction_u64	(ptrdiff_t nmemb,
					uint64_t dest[nmemb],
					const uint64_t src1[nmemb],
					const uint64_t src2[nmemb]);
int	alx_matrix_subtraction_s64	(ptrdiff_t nmemb,
					int64_t dest[nmemb],
					const int64_t src1[nmemb],
					const int64_t src2[nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_matrix_subtraction_ldbl	(ptrdiff_t nmemb,
					long double dest[nmemb],
					const long double src1[nmemb],
					const long double src2[nmemb]);
static inline	void	alx_matrix_subtraction		(ptrdiff_t nmemb,
					double dest[nmemb],
					const double src1[nmemb],
					const double src2[nmemb]);
static inline	void	alx_matrix_subtraction_flt	(ptrdiff_t nmemb,
					float dest[nmemb],
					const float src1[nmemb],
					const float src2[nmemb]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_matrix_subtraction_ldbl	(ptrdiff_t nmemb,
					long double dest[nmemb],
					const long double src1[nmemb],
					const long double src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction		(ptrdiff_t nmemb,
					double dest[nmemb],
					const double src1[nmemb],
					const double src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_flt	(ptrdiff_t nmemb,
					float dest[nmemb],
					const float src1[nmemb],
					const float src2[nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] - src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/matrix_subtraction.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
