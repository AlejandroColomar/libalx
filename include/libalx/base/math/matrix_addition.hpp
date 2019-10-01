/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/math/matrix_addition.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
void	alx_matrix_addition_ldbl(ptrdiff_t nmemb,
				 long double dest[],
				 const long double src1[],
				 const long double src2[]);
[[gnu::nonnull]]
void	alx_matrix_addition	(ptrdiff_t nmemb,
				 double dest[],
				 const double src1[],
				 const double src2[]);
[[gnu::nonnull]]
void	alx_matrix_addition_flt	(ptrdiff_t nmemb,
				 float dest[],
				 const float src1[],
				 const float src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_uint(ptrdiff_t nmemb,
				 unsigned dest[],
				 const unsigned src1[],
				 const unsigned src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_int	(ptrdiff_t nmemb,
				 int dest[],
				 const int src1[],
				 const int src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_u8	(ptrdiff_t nmemb,
				 uint8_t dest[],
				 const uint8_t src1[],
				 const uint8_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_s8	(ptrdiff_t nmemb,
				 int8_t dest[],
				 const int8_t src1[],
				 const int8_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_u16	(ptrdiff_t nmemb,
				 uint16_t dest[],
				 const uint16_t src1[],
				 const uint16_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_s16	(ptrdiff_t nmemb,
				 int16_t dest[],
				 const int16_t src1[],
				 const int16_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_u32	(ptrdiff_t nmemb,
				 uint32_t dest[],
				 const uint32_t src1[],
				 const uint32_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_s32	(ptrdiff_t nmemb,
				 int32_t dest[],
				 const int32_t src1[],
				 const int32_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_u64	(ptrdiff_t nmemb,
				 uint64_t dest[],
				 const uint64_t src1[],
				 const uint64_t src2[]);
[[gnu::nonnull]]
int	alx_matrix_addition_s64	(ptrdiff_t nmemb,
				 int64_t dest[],
				 const int64_t src1[],
				 const int64_t src2[]);
}


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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/