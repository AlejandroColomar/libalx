/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_MATRIX_ADDITION_HPP
#define ALX_MATH_MATRIX_ADDITION_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
extern	"C"
{
int	alx_matrix_addition_uint(ssize_t n,
					unsigned dest[],
					const unsigned src1[],
					const unsigned src2[]);
int	alx_matrix_addition_int	(ssize_t n,
					int dest[],
					const int src1[],
					const int src2[]);
int	alx_matrix_addition_u8	(ssize_t n,
					uint8_t dest[],
					const uint8_t src1[],
					const uint8_t src2[]);
int	alx_matrix_addition_s8	(ssize_t n,
					int8_t dest[],
					const int8_t src1[],
					const int8_t src2[]);
int	alx_matrix_addition_u16	(ssize_t n,
					uint16_t dest[],
					const uint16_t src1[],
					const uint16_t src2[]);
int	alx_matrix_addition_s16	(ssize_t n,
					int16_t dest[],
					const int16_t src1[],
					const int16_t src2[]);
int	alx_matrix_addition_u32	(ssize_t n,
					uint32_t dest[],
					const uint32_t src1[],
					const uint32_t src2[]);
int	alx_matrix_addition_s32	(ssize_t n,
					int32_t dest[],
					const int32_t src1[],
					const int32_t src2[]);
int	alx_matrix_addition_u64	(ssize_t n,
					uint64_t dest[],
					const uint64_t src1[],
					const uint64_t src2[]);
int	alx_matrix_addition_s64	(ssize_t n,
					int64_t dest[],
					const int64_t src1[],
					const int64_t src2[]);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_matrix_addition_ldbl(ssize_t n,
					long double dest[],
					const long double src1[],
					const long double src2[]);
static inline	void	alx_matrix_addition	(ssize_t n,
					double dest[],
					const double src1[],
					const double src2[]);
static inline	void	alx_matrix_addition_flt	(ssize_t n,
					float dest[],
					const float src1[],
					const float src2[]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_matrix_addition_ldbl	(ssize_t n,
					long double dest[],
					const long double src1[],
					const long double src2[])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition		(ssize_t n,
					double dest[],
					const double src1[],
					const double src2[])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_flt		(ssize_t n,
					float dest[],
					const float src1[],
					const float src2[])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}



/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/math/matrix_addition.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
