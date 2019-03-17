/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_BASE_MATH_SCALE_LINEAR_HPP
#define ALX_BASE_MATH_SCALE_LINEAR_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
long double	alx_scale_linear_ldbl	(long double input,
					long double in_0, long double in_1,
					long double out_0, long double out_1);
double		alx_scale_linear	(double input,
					double in_0, double in_1,
					double out_0, double out_1);
float		alx_scale_linear_f	(float input,
					float in_0, float in_1,
					float out_0, float out_1);
unsigned	alx_scale_linear_uint	(unsigned input,
					unsigned in_0, unsigned in_1,
					unsigned out_0, unsigned out_1);
int		alx_scale_linear_int	(int input,
					int in_0, int in_1,
					int out_0, int out_1);
uint8_t		alx_scale_linear_u8	(uint8_t input,
					uint8_t in_0, uint8_t in_1,
					uint8_t out_0, uint8_t out_1);
int8_t		alx_scale_linear_s8	(int8_t input,
					int8_t in_0, int8_t in_1,
					int8_t out_0, int8_t out_1);
uint16_t	alx_scale_linear_u16	(uint16_t input,
					uint16_t in_0, uint16_t in_1,
					uint16_t out_0, uint16_t out_1);
int16_t		alx_scale_linear_s16	(int16_t input,
					int16_t in_0, int16_t in_1,
					int16_t out_0, int16_t out_1);
uint32_t	alx_scale_linear_u32	(uint32_t input,
					uint32_t in_0, uint32_t in_1,
					uint32_t out_0, uint32_t out_1);
int32_t		alx_scale_linear_s32	(int32_t input,
					int32_t in_0, int32_t in_1,
					int32_t out_0, int32_t out_1);
uint64_t	alx_scale_linear_u64	(uint64_t input,
					uint64_t in_0, uint64_t in_1,
					uint64_t out_0, uint64_t out_1);
int64_t		alx_scale_linear_s64	(int64_t input,
					int64_t in_0, int64_t in_1,
					int64_t out_0, int64_t out_1);
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
#endif		/* libalx/base/math/scale_linear.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
