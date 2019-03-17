/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_BASE_STDLIB_MATRIX_ADDITION_HPP
#define ALX_BASE_STDLIB_MATRIX_ADDITION_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

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
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_matrix_addition_ldbl(ssize_t n,
					long double dest[restrict],
					const long double src1[restrict],
					const long double src2[restrict]);
static inline	void	alx_matrix_addition	(ssize_t n,
					double dest[restrict],
					const double src1[restrict],
					const double src2[restrict]);
static inline	void	alx_matrix_addition_f	(ssize_t n,
					float dest[restrict],
					const float src1[restrict],
					const float src2[restrict]);
static inline	void	alx_matrix_addition_uint(ssize_t n,
					unsigned dest[restrict],
					const unsigned src1[restrict],
					const unsigned src2[restrict]);
static inline	void	alx_matrix_addition_int	(ssize_t n,
					int dest[restrict],
					const int src1[restrict],
					const int src2[restrict]);
static inline	void	alx_matrix_addition_u8	(ssize_t n,
					uint8_t dest[restrict],
					const uint8_t src1[restrict],
					const uint8_t src2[restrict]);
static inline	void	alx_matrix_addition_s8	(ssize_t n,
					int8_t dest[restrict],
					const int8_t src1[restrict],
					const int8_t src2[restrict]);
static inline	void	alx_matrix_addition_u16	(ssize_t n,
					uint16_t dest[restrict],
					const uint16_t src1[restrict],
					const uint16_t src2[restrict]);
static inline	void	alx_matrix_addition_s16	(ssize_t n,
					int16_t dest[restrict],
					const int16_t src1[restrict],
					const int16_t src2[restrict]);
static inline	void	alx_matrix_addition_u32	(ssize_t n,
					uint32_t dest[restrict],
					const uint32_t src1[restrict],
					const uint32_t src2[restrict]);
static inline	void	alx_matrix_addition_s32	(ssize_t n,
					int32_t dest[restrict],
					const int32_t src1[restrict],
					const int32_t src2[restrict]);
static inline	void	alx_matrix_addition_u64	(ssize_t n,
					uint64_t dest[restrict],
					const uint64_t src1[restrict],
					const uint64_t src2[restrict]);
static inline	void	alx_matrix_addition_s64	(ssize_t n,
					int64_t dest[restrict],
					const int64_t src1[restrict],
					const int64_t src2[restrict]);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_matrix_addition_ldbl	(ssize_t n,
					long double dest[restrict],
					const long double src1[restrict],
					const long double src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition		(ssize_t n,
					double dest[restrict],
					const double src1[restrict],
					const double src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_f		(ssize_t n,
					float dest[restrict],
					const float src1[restrict],
					const float src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_uint	(ssize_t n,
					unsigned dest[restrict],
					const unsigned src1[restrict],
					const unsigned src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_int		(ssize_t n,
					int dest[restrict],
					const int src1[restrict],
					const int src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_u8		(ssize_t n,
					uint8_t dest[restrict],
					const uint8_t src1[restrict],
					const uint8_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_s8		(ssize_t n,
					int8_t dest[restrict],
					const int8_t src1[restrict],
					const int8_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_u16		(ssize_t n,
					uint16_t dest[restrict],
					const uint16_t src1[restrict],
					const uint16_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_s16		(ssize_t n,
					int16_t dest[restrict],
					const int16_t src1[restrict],
					const int16_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_u32		(ssize_t n,
					uint32_t dest[restrict],
					const uint32_t src1[restrict],
					const uint32_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_s32		(ssize_t n,
					int32_t dest[restrict],
					const int32_t src1[restrict],
					const int32_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_u64		(ssize_t n,
					uint64_t dest[restrict],
					const uint64_t src1[restrict],
					const uint64_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}

static inline
void	alx_matrix_addition_s64		(ssize_t n,
					int64_t dest[restrict],
					const int64_t src1[restrict],
					const int64_t src2[restrict])
{

	for (ssize_t i = 0; i < n; i++)
		dest[i]	= src1[i] + src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdlib/matrix_addition.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
