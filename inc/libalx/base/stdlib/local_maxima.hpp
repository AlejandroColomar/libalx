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
				const long double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima	(ptrdiff_t rows, ptrdiff_t cols,
				const double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_f	(ptrdiff_t rows, ptrdiff_t cols,
				const float arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_uint	(ptrdiff_t rows, ptrdiff_t cols,
				const unsigned arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_int	(ptrdiff_t rows, ptrdiff_t cols,
				const int arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_u8	(ptrdiff_t rows, ptrdiff_t cols,
				const uint8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_s8	(ptrdiff_t rows, ptrdiff_t cols,
				const int8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_u16	(ptrdiff_t rows, ptrdiff_t cols,
				const uint16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_s16	(ptrdiff_t rows, ptrdiff_t cols,
				const int16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_u32	(ptrdiff_t rows, ptrdiff_t cols,
				const uint32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_s32	(ptrdiff_t rows, ptrdiff_t cols,
				const int32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_u64	(ptrdiff_t rows, ptrdiff_t cols,
				const uint64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
[[gnu::nonnull]]
void	alx_local_maxima_s64	(ptrdiff_t rows, ptrdiff_t cols,
				const int64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
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
