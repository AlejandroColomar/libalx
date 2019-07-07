/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier;	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/scale_linear.h"

#include <math.h>
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
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
extern
long double	alx_scale_linear_ldbl	(long double input,
					long double in_lo, long double in_hi,
					long double out_lo, long double out_hi);
extern
double		alx_scale_linear	(double input,
					double in_lo, double in_hi,
					double out_lo, double out_hi);
extern
float		alx_scale_linear_flt	(float input,
					float in_lo, float in_hi,
					float out_lo, float out_hi);
extern
unsigned	alx_scale_linear_uint	(unsigned input,
					unsigned in_lo, unsigned in_hi,
					unsigned out_lo, unsigned out_hi);
extern
int		alx_scale_linear_int	(int input,
					int in_lo, int in_hi,
					int out_lo, int out_hi);
extern
uint8_t		alx_scale_linear_u8	(uint8_t input,
					uint8_t in_lo, uint8_t in_hi,
					uint8_t out_lo, uint8_t out_hi);
extern
int8_t		alx_scale_linear_s8	(int8_t input,
					int8_t in_lo, int8_t in_hi,
					int8_t out_lo, int8_t out_hi);
extern
uint16_t	alx_scale_linear_u16	(uint16_t input,
					uint16_t in_lo, uint16_t in_hi,
					uint16_t out_lo, uint16_t out_hi);
extern
int16_t		alx_scale_linear_s16	(int16_t input,
					int16_t in_lo, int16_t in_hi,
					int16_t out_lo, int16_t out_hi);
extern
uint32_t	alx_scale_linear_u32	(uint32_t input,
					uint32_t in_lo, uint32_t in_hi,
					uint32_t out_lo, uint32_t out_hi);
extern
int32_t		alx_scale_linear_s32	(int32_t input,
					int32_t in_lo, int32_t in_hi,
					int32_t out_lo, int32_t out_hi);
extern
uint64_t	alx_scale_linear_u64	(uint64_t input,
					uint64_t in_lo, uint64_t in_hi,
					uint64_t out_lo, uint64_t out_hi);
extern
int64_t		alx_scale_linear_s64	(int64_t input,
					int64_t in_lo, int64_t in_hi,
					int64_t out_lo, int64_t out_hi);


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
