/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_BASE_STDLIB_LOCAL_MAXIMA_HPP
#define ALX_BASE_STDLIB_LOCAL_MAXIMA_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstdint>


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
void	alx_local_maxima_ldbl	(int rows, int cols,
				const long double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima	(int rows, int cols,
				const double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_f	(int rows, int cols,
				const float arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_uint	(int rows, int cols,
				const unsigned arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_int	(int rows, int cols,
				const int arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u8	(int rows, int cols,
				const uint8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s8	(int rows, int cols,
				const int8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u16	(int rows, int cols,
				const uint16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s16	(int rows, int cols,
				const int16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u32	(int rows, int cols,
				const uint32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s32	(int rows, int cols,
				const int32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_u64	(int rows, int cols,
				const uint64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols]);
void	alx_local_maxima_s64	(int rows, int cols,
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
#endif		/* libalx/base/stdlib/local_maxima.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
