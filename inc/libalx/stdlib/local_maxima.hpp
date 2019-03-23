/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDLIB_LOCAL_MAXIMA_HPP
#define ALX_STDLIB_LOCAL_MAXIMA_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdbool>
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
void	alx_local_maxima_ldbl	(ssize_t rows, ssize_t cols,
				const long double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima	(ssize_t rows, ssize_t cols,
				const double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_f	(ssize_t rows, ssize_t cols,
				const float arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_uint	(ssize_t rows, ssize_t cols,
				const unsigned arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_int	(ssize_t rows, ssize_t cols,
				const int arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u8	(ssize_t rows, ssize_t cols,
				const uint8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s8	(ssize_t rows, ssize_t cols,
				const int8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u16	(ssize_t rows, ssize_t cols,
				const uint16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s16	(ssize_t rows, ssize_t cols,
				const int16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u32	(ssize_t rows, ssize_t cols,
				const uint32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s32	(ssize_t rows, ssize_t cols,
				const int32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u64	(ssize_t rows, ssize_t cols,
				const uint64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s64	(ssize_t rows, ssize_t cols,
				const int64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/stdlib/local_maxima.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
