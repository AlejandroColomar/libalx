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
					long double in_0, long double in_1,
					long double out_0, long double out_1)
{
	long double	normalized;
	long double	output;

	normalized	= (input - in_0) / (in_1 - in_0);
	output		= out_0 + normalized * (out_1 - out_0);

	return	output;
}

double		alx_scale_linear	(double input,
					double in_0, double in_1,
					double out_0, double out_1)
{
	double_t	normalized;
	double		output;

	normalized	= (input - in_0) / (in_1 - in_0);
	output		= out_0 + normalized * (out_1 - out_0);

	return	output;
}

float		alx_scale_linear_f	(float input,
					float in_0, float in_1,
					float out_0, float out_1)
{
	float_t	normalized;
	float	output;

	normalized	= (input - in_0) / (in_1 - in_0);
	output		= out_0 + normalized * (out_1 - out_0);

	return	output;
}

int		alx_scale_linear_int	(int input,
					int in_0, int in_1,
					int out_0, int out_1)
{
	double_t	input_	= input;
	double_t	in_0_	= in_0;
	double_t	in_1_	= in_1;
	double_t	out_0_	= out_0;
	double_t	out_1_	= out_1;
	double_t	normalized;
	int		output;

	normalized	= (input_ - in_0_) / (in_1_ - in_0_);
	output		= out_0_ + normalized * (out_1_ - out_0_);

	return	output;
}

int8_t		alx_scale_linear_s8	(int8_t input,
					int8_t in_0, int8_t in_1,
					int8_t out_0, int8_t out_1)
{
	int_fast16_t	input_	= input;
	int_fast16_t	in_0_	= in_0;
	int_fast16_t	in_1_	= in_1;
	int_fast16_t	out_0_	= out_0;
	int_fast16_t	out_1_	= out_1;
	int_fast16_t	tmp;
	int_fast8_t	normalized;
	int8_t		output;

	if (!((out_1_ - out_0_) % (in_1_ - in_0_))) {
		normalized	= (input - in_0) / (in_1 - in_0);
		output		= out_0 + normalized * (out_1 - out_0);
	} else {
		tmp		= (input_ - in_0_) * (out_1_ - out_0_);
		output		= out_0_ + tmp / (in_1_ - in_0_);
	}

	return	output;
}

int16_t		alx_scale_linear_s16	(int16_t input,
					int16_t in_0, int16_t in_1,
					int16_t out_0, int16_t out_1)
{
	int_fast32_t	input_	= input;
	int_fast32_t	in_0_	= in_0;
	int_fast32_t	in_1_	= in_1;
	int_fast32_t	out_0_	= out_0;
	int_fast32_t	out_1_	= out_1;
	int_fast32_t	tmp;
	int_fast16_t	normalized;
	int16_t		output;

	if (!((out_1_ - out_0_) % (in_1_ - in_0_))) {
		normalized	= (input - in_0) / (in_1 - in_0);
		output		= out_0 + normalized * (out_1 - out_0);
	} else {
		tmp		= (input_ - in_0_) * (out_1_ - out_0_);
		output		= out_0_ + tmp / (in_1_ - in_0_);
	}

	return	output;
}

int32_t		alx_scale_linear_s32	(int32_t input,
					int32_t in_0, int32_t in_1,
					int32_t out_0, int32_t out_1)
{
	int_fast64_t	input_	= input;
	int_fast64_t	in_0_	= in_0;
	int_fast64_t	in_1_	= in_1;
	int_fast64_t	out_0_	= out_0;
	int_fast64_t	out_1_	= out_1;
	int_fast64_t	tmp;
	int_fast32_t	normalized;
	int32_t		output;

	if (!((out_1_ - out_0_) % (in_1_ - in_0_))) {
		normalized	= (input - in_0) / (in_1 - in_0);
		output		= out_0 + normalized * (out_1 - out_0);
	} else {
		tmp		= (input_ - in_0_) * (out_1_ - out_0_);
		output		= out_0_ + tmp / (in_1_ - in_0_);
	}

	return	output;
}

int64_t		alx_scale_linear_s64	(int64_t input,
					int64_t in_0, int64_t in_1,
					int64_t out_0, int64_t out_1)
{
	double_t	input_	= input;
	double_t	in_0_	= in_0;
	double_t	in_1_	= in_1;
	double_t	out_0_	= out_0;
	double_t	out_1_	= out_1;
	double_t	normalized;
	int64_t		output;

	normalized	= (input_ - in_0_) / (in_1_ - in_0_);
	output		= out_0_ + normalized * (out_1_ - out_0_);

	return	output;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
