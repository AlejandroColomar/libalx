/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/pow.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((const))
uint8_t		alx_pow_u8	(uint8_t base, uint8_t exp);
__attribute__((const))
int8_t		alx_pow_s8	(int8_t base, uint8_t exp);
__attribute__((const))
uint16_t	alx_pow_u16	(uint16_t base, uint8_t exp);
__attribute__((const))
int16_t		alx_pow_s16	(int16_t base, uint8_t exp);
__attribute__((const))
uint32_t	alx_pow_u32	(uint32_t base, uint8_t exp);
__attribute__((const))
int32_t		alx_pow_s32	(int32_t base, uint8_t exp);
__attribute__((const))
uint64_t	alx_pow_u64	(uint64_t base, uint8_t exp);
__attribute__((const))
int64_t		alx_pow_s64	(int64_t base, uint8_t exp);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/