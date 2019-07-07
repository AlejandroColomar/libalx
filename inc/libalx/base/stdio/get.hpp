/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDIO_GET_HPP
#define ALX_STDIO_GET_HPP


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
long double	alx_get_ldbl	(long double m, long double def, long double M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
double		alx_get_dbl	(double m, double def, double M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
float		alx_get_flt	(float m, float def, float M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
unsigned	alx_get_uint	(unsigned m, unsigned def, unsigned M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int		alx_get_int	(int m, int def, int M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint8_t		alx_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int8_t		alx_get_s8	(int8_t m, int8_t def, int8_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint16_t	alx_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int16_t		alx_get_s16	(int16_t m, int16_t def, int16_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint32_t	alx_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int32_t		alx_get_s32	(int32_t m, int32_t def, int32_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
uint64_t	alx_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
int64_t		alx_get_s64	(int64_t m, int64_t def, int64_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
ptrdiff_t	alx_get_pdif	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts);
char		alx_get_ch	(const char *restrict valid,
				bool skip_space, bool ignore_case,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
		__attribute__((nonnull(1)));
int		alx_get_fname	(const char *restrict path,
				char fname[static restrict FILENAME_MAX],
				bool exist,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
		__attribute__((nonnull(1, 2)));
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
#endif		/* libalx/base/stdio/get.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
