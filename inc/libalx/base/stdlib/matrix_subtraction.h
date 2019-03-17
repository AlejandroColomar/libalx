/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_BASE_STDLIB_MATRIX_SUBTRACTION_H
#define ALX_BASE_STDLIB_MATRIX_SUBTRACTION_H


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


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_matrix_subtraction_ldbl	(ssize_t n,
					long double dest[restrict n],
					const long double src1[restrict n],
					const long double src2[restrict n]);
static inline	void	alx_matrix_subtraction		(ssize_t n,
					double dest[restrict n],
					const double src1[restrict n],
					const double src2[restrict n]);
static inline	void	alx_matrix_subtraction_f	(ssize_t n,
					float dest[restrict n],
					const float src1[restrict n],
					const float src2[restrict n]);
static inline	void	alx_matrix_subtraction_uint	(ssize_t n,
					unsigned dest[restrict n],
					const unsigned src1[restrict n],
					const unsigned src2[restrict n]);
static inline	void	alx_matrix_subtraction_int	(ssize_t n,
					int dest[restrict n],
					const int src1[restrict n],
					const int src2[restrict n]);
static inline	void	alx_matrix_subtraction_u8	(ssize_t n,
					uint8_t dest[restrict n],
					const uint8_t src1[restrict n],
					const uint8_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_s8	(ssize_t n,
					int8_t dest[restrict n],
					const int8_t src1[restrict n],
					const int8_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_u16	(ssize_t n,
					uint16_t dest[restrict n],
					const uint16_t src1[restrict n],
					const uint16_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_s16	(ssize_t n,
					int16_t dest[restrict n],
					const int16_t src1[restrict n],
					const int16_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_u32	(ssize_t n,
					uint32_t dest[restrict n],
					const uint32_t src1[restrict n],
					const uint32_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_s32	(ssize_t n,
					int32_t dest[restrict n],
					const int32_t src1[restrict n],
					const int32_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_u64	(ssize_t n,
					uint64_t dest[restrict n],
					const uint64_t src1[restrict n],
					const uint64_t src2[restrict n]);
static inline	void	alx_matrix_subtraction_s64	(ssize_t n,
					int64_t dest[restrict n],
					const int64_t src1[restrict n],
					const int64_t src2[restrict n]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_matrix_subtraction_ldbl	(ssize_t n,
					long double dest[restrict n],
					const long double src1[restrict n],
					const long double src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction		(ssize_t n,
					double dest[restrict n],
					const double src1[restrict n],
					const double src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_f	(ssize_t n,
					float dest[restrict n],
					const float src1[restrict n],
					const float src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_uint	(ssize_t n,
					unsigned dest[restrict n],
					const unsigned src1[restrict n],
					const unsigned src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_int	(ssize_t n,
					int dest[restrict n],
					const int src1[restrict n],
					const int src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_u8	(ssize_t n,
					uint8_t dest[restrict n],
					const uint8_t src1[restrict n],
					const uint8_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_s8	(ssize_t n,
					int8_t dest[restrict n],
					const int8_t src1[restrict n],
					const int8_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_u16	(ssize_t n,
					uint16_t dest[restrict n],
					const uint16_t src1[restrict n],
					const uint16_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_s16	(ssize_t n,
					int16_t dest[restrict n],
					const int16_t src1[restrict n],
					const int16_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_u32	(ssize_t n,
					uint32_t dest[restrict n],
					const uint32_t src1[restrict n],
					const uint32_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_s32	(ssize_t n,
					int32_t dest[restrict n],
					const int32_t src1[restrict n],
					const int32_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_u64	(ssize_t n,
					uint64_t dest[restrict n],
					const uint64_t src1[restrict n],
					const uint64_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}

static inline
void	alx_matrix_subtraction_s64	(ssize_t n,
					int64_t dest[restrict n],
					const int64_t src1[restrict n],
					const int64_t src2[restrict n])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] - src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdlib/matrix_subtraction.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
