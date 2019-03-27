/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/pow.h"

#include <stdint.h>

#include "libalx/base/stdint/constants.h"
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
uint8_t		alx_pow_u8	(uint8_t base, uint8_t exp)
{
	uint_fast8_t	base_;
	uint_fast8_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_U8_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

int8_t		alx_pow_s8	(int8_t base, uint8_t exp)
{
	int_fast8_t	base_;
	int_fast8_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_S8_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

uint16_t	alx_pow_u16	(uint16_t base, uint8_t exp)
{
	uint_fast16_t	base_;
	uint_fast16_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_U16_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

int16_t		alx_pow_s16	(int16_t base, uint8_t exp)
{
	int_fast16_t	base_;
	int_fast16_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_S16_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

uint32_t	alx_pow_u32	(uint32_t base, uint8_t exp)
{
	uint_fast32_t	base_;
	uint_fast32_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_U32_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

int32_t		alx_pow_s32	(int32_t base, uint8_t exp)
{
	int_fast32_t	base_;
	int_fast32_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_S32_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

uint64_t	alx_pow_u64	(uint64_t base, uint8_t exp)
{
	uint_fast64_t	base_;
	uint_fast64_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_U64_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}

int64_t		alx_pow_s64	(int64_t base, uint8_t exp)
{
	int_fast64_t	base_;
	int_fast64_t	result;

	base_	= base;

	if (base_ == 1)
		return	1;
	if (!exp)
		return	1;
	if (!base_)
		return	0;

	result	= 1;
	if (exp & 1)
		result *= base_;
	exp >>= 1;
	while (exp) {
		if (base_ > SQRT_S64_MAX)
			return	0;
		base_ *= base_;
		if (exp & 1)
			result *= base_;
		exp >>= 1;
	}

	return	result;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
