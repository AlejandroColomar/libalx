/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_ARRAY_MULTIPLICATION_H
#define ALX_MATH_ARRAY_MULTIPLICATION_H


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
 ******* function prototypes **************************************************
 ******************************************************************************/
inline
void	alx_array_multiplication_ldbl	(ptrdiff_t nmemb,
					 long double dest[static nmemb],
					 const long double src1[static nmemb],
					 const long double src2[static nmemb])
	__attribute__((nonnull));
inline
void	alx_array_multiplication	(ptrdiff_t nmemb,
					 double dest[static nmemb],
					 const double src1[static nmemb],
					 const double src2[static nmemb])
	__attribute__((nonnull));
inline
void	alx_array_multiplication_flt	(ptrdiff_t nmemb,
					 float dest[static nmemb],
					 const float src1[static nmemb],
					 const float src2[static nmemb])
	__attribute__((nonnull));

int	alx_array_multiplication_uint	(ptrdiff_t nmemb,
					 unsigned dest[static nmemb],
					 const unsigned src1[static nmemb],
					 const unsigned src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_int	(ptrdiff_t nmemb,
					 int dest[static nmemb],
					 const int src1[static nmemb],
					 const int src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_u8	(ptrdiff_t nmemb,
					 uint8_t dest[static nmemb],
					 const uint8_t src1[static nmemb],
					 const uint8_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_s8	(ptrdiff_t nmemb,
					 int8_t dest[static nmemb],
					 const int8_t src1[static nmemb],
					 const int8_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_u16	(ptrdiff_t nmemb,
					 uint16_t dest[static nmemb],
					 const uint16_t src1[static nmemb],
					 const uint16_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_s16	(ptrdiff_t nmemb,
					 int16_t dest[static nmemb],
					 const int16_t src1[static nmemb],
					 const int16_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_u32	(ptrdiff_t nmemb,
					 uint32_t dest[static nmemb],
					 const uint32_t src1[static nmemb],
					 const uint32_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_s32	(ptrdiff_t nmemb,
					 int32_t dest[static nmemb],
					 const int32_t src1[static nmemb],
					 const int32_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_u64	(ptrdiff_t nmemb,
					 uint64_t dest[static nmemb],
					 const uint64_t src1[static nmemb],
					 const uint64_t src2[static nmemb])
	__attribute__((nonnull));
int	alx_array_multiplication_s64	(ptrdiff_t nmemb,
					 int64_t dest[static nmemb],
					 const int64_t src1[static nmemb],
					 const int64_t src2[static nmemb])
	__attribute__((nonnull));


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
void	alx_array_multiplication_ldbl	(ptrdiff_t nmemb,
					 long double dest[static nmemb],
					 const long double src1[static nmemb],
					 const long double src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] * src2[i];
}

inline
void	alx_array_multiplication	(ptrdiff_t nmemb,
					 double dest[static nmemb],
					 const double src1[static nmemb],
					 const double src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] * src2[i];
}

inline
void	alx_array_multiplication_flt	(ptrdiff_t nmemb,
					 float dest[static nmemb],
					 const float src1[static nmemb],
					 const float src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++)
		dest[i]	= src1[i] * src2[i];
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/array_multiplication.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
