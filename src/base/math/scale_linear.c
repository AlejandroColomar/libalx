/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/scale_linear.h"

#include <math.h>
#include <stdint.h>

#include "libalx/base/stdint/redefinitions.h"


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
long double	alx_scale_linear_ldbl	(long double input,
					long double in_lo, long double in_hi,
					long double out_lo, long double out_hi)
{
	long double	normalized;
	long double	output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

double		alx_scale_linear	(double input,
					double in_lo, double in_hi,
					double out_lo, double out_hi)
{
	double_t	normalized;
	double		output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

float		alx_scale_linear_flt	(float input,
					float in_lo, float in_hi,
					float out_lo, float out_hi)
{
	float_t	normalized;
	float	output;

	normalized	= (input - in_lo) / (in_hi - in_lo);
	output		= out_lo + normalized * (out_hi - out_lo);

	return	output;
}

unsigned	alx_scale_linear_uint	(unsigned input,
					unsigned in_lo, unsigned in_hi,
					unsigned out_lo, unsigned out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	unsigned	output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}

int		alx_scale_linear_int	(int input,
					int in_lo, int in_hi,
					int out_lo, int out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	int		output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}

uint8_t		alx_scale_linear_u8	(uint8_t input,
					uint8_t in_lo, uint8_t in_hi,
					uint8_t out_lo, uint8_t out_hi)
{
	uint_fast16_t	input_	= input;
	uint_fast16_t	in_lo_	= in_lo;
	uint_fast16_t	in_hi_	= in_hi;
	uint_fast16_t	out_lo_	= out_lo;
	uint_fast16_t	out_hi_	= out_hi;
	uint_fast16_t	tmp;
	uint_fast8_t	normalized;
	uint8_t		output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

int8_t		alx_scale_linear_s8	(int8_t input,
					int8_t in_lo, int8_t in_hi,
					int8_t out_lo, int8_t out_hi)
{
	int_fast16_t	input_	= input;
	int_fast16_t	in_lo_	= in_lo;
	int_fast16_t	in_hi_	= in_hi;
	int_fast16_t	out_lo_	= out_lo;
	int_fast16_t	out_hi_	= out_hi;
	int_fast16_t	tmp;
	int_fast8_t	normalized;
	int8_t		output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

uint16_t	alx_scale_linear_u16	(uint16_t input,
					uint16_t in_lo, uint16_t in_hi,
					uint16_t out_lo, uint16_t out_hi)
{
	uint_fast32_t	input_	= input;
	uint_fast32_t	in_lo_	= in_lo;
	uint_fast32_t	in_hi_	= in_hi;
	uint_fast32_t	out_lo_	= out_lo;
	uint_fast32_t	out_hi_	= out_hi;
	uint_fast32_t	tmp;
	uint_fast16_t	normalized;
	uint16_t	output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

int16_t		alx_scale_linear_s16	(int16_t input,
					int16_t in_lo, int16_t in_hi,
					int16_t out_lo, int16_t out_hi)
{
	int_fast32_t	input_	= input;
	int_fast32_t	in_lo_	= in_lo;
	int_fast32_t	in_hi_	= in_hi;
	int_fast32_t	out_lo_	= out_lo;
	int_fast32_t	out_hi_	= out_hi;
	int_fast32_t	tmp;
	int_fast16_t	normalized;
	int16_t		output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

uint32_t	alx_scale_linear_u32	(uint32_t input,
					uint32_t in_lo, uint32_t in_hi,
					uint32_t out_lo, uint32_t out_hi)
{
	uint_fast64_t	input_	= input;
	uint_fast64_t	in_lo_	= in_lo;
	uint_fast64_t	in_hi_	= in_hi;
	uint_fast64_t	out_lo_	= out_lo;
	uint_fast64_t	out_hi_	= out_hi;
	uint_fast64_t	tmp;
	uint_fast32_t	normalized;
	uint32_t	output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

int32_t		alx_scale_linear_s32	(int32_t input,
					int32_t in_lo, int32_t in_hi,
					int32_t out_lo, int32_t out_hi)
{
	int_fast64_t	input_	= input;
	int_fast64_t	in_lo_	= in_lo;
	int_fast64_t	in_hi_	= in_hi;
	int_fast64_t	out_lo_	= out_lo;
	int_fast64_t	out_hi_	= out_hi;
	int_fast64_t	tmp;
	int_fast32_t	normalized;
	int32_t		output;

	if (!((out_hi_ - out_lo_) % (in_hi_ - in_lo_))) {
		normalized	= (input - in_lo) / (in_hi - in_lo);
		output		= out_lo + normalized * (out_hi - out_lo);
	} else {
		tmp		= (input_ - in_lo_) * (out_hi_ - out_lo_);
		output		= out_lo_ + tmp / (in_hi_ - in_lo_);
	}

	return	output;
}

uint64_t	alx_scale_linear_u64	(uint64_t input,
					uint64_t in_lo, uint64_t in_hi,
					uint64_t out_lo, uint64_t out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	uint64_t	output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}

int64_t		alx_scale_linear_s64	(int64_t input,
					int64_t in_lo, int64_t in_hi,
					int64_t out_lo, int64_t out_hi)
{
	double_t	input_	= input;
	double_t	in_lo_	= in_lo;
	double_t	in_hi_	= in_hi;
	double_t	out_lo_	= out_lo;
	double_t	out_hi_	= out_hi;
	double_t	normalized;
	int64_t		output;

	normalized	= (input_ - in_lo_) / (in_hi_ - in_lo_);
	output		= out_lo_ + normalized * (out_hi_ - out_lo_);

	return	output;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
