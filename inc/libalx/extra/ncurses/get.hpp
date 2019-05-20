/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_NCURSES_GET_HPP
#define ALX_NCURSES_GET_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>

#include "libalx/base/stddef/restrict.hpp"


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
long double	alx_w_get_ldbl	(long double m, long double def, long double M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
double		alx_w_get_dbl	(double m, double def, double M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
float		alx_w_get_flt	(float m, float def, float M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
unsigned	alx_w_get_uint	(unsigned m, unsigned def, unsigned M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int		alx_w_get_int	(int m, int def, int M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint8_t		alx_w_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int8_t		alx_w_get_s8	(int8_t m, int8_t def, int8_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint16_t	alx_w_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int16_t		alx_w_get_s16	(int16_t m, int16_t def, int16_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint32_t	alx_w_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int32_t		alx_w_get_s32	(int32_t m, int32_t def, int32_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint64_t	alx_w_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int64_t		alx_w_get_s64	(int64_t m, int64_t def, int64_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
ptrdiff_t	alx_w_get_pdif	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int		alx_w_get_nstr	(ptrdiff_t size, char dest[restrict size],
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help);
int		alx_w_get_fname	(const char *restrict fpath,
				char fname[restrict FILENAME_MAX],
				bool exist,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
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
#endif		/* libalx/extra/ncurses/get.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
