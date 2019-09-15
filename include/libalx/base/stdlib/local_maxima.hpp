/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/local_maxima.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
void	alx_local_maxima_ldbl	(ptrdiff_t rows, ptrdiff_t cols,
				const long double *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima	(ptrdiff_t rows, ptrdiff_t cols,
				const double *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_f	(ptrdiff_t rows, ptrdiff_t cols,
				const float *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_uint	(ptrdiff_t rows, ptrdiff_t cols,
				const unsigned *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_int	(ptrdiff_t rows, ptrdiff_t cols,
				const int *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_u8	(ptrdiff_t rows, ptrdiff_t cols,
				const uint8_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_s8	(ptrdiff_t rows, ptrdiff_t cols,
				const int8_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_u16	(ptrdiff_t rows, ptrdiff_t cols,
				const uint16_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_s16	(ptrdiff_t rows, ptrdiff_t cols,
				const int16_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_u32	(ptrdiff_t rows, ptrdiff_t cols,
				const uint32_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_s32	(ptrdiff_t rows, ptrdiff_t cols,
				const int32_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_u64	(ptrdiff_t rows, ptrdiff_t cols,
				const uint64_t *restrict arr_in,
				bool *restrict arr_out);
[[gnu::nonnull]]
void	alx_local_maxima_s64	(ptrdiff_t rows, ptrdiff_t cols,
				const int64_t *restrict arr_in,
				bool *restrict arr_out);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
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
