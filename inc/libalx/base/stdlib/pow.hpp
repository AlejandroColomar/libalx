/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/pow.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
uint8_t		alx_pow_u8	(uint8_t base, uint8_t exp);
int8_t		alx_pow_s8	(int8_t base, uint8_t exp);
uint16_t	alx_pow_u16	(uint16_t base, uint8_t exp);
int16_t		alx_pow_s16	(int16_t base, uint8_t exp);
uint32_t	alx_pow_u32	(uint32_t base, uint8_t exp);
int32_t		alx_pow_s32	(int32_t base, uint8_t exp);
uint64_t	alx_pow_u64	(uint64_t base, uint8_t exp);
int64_t		alx_pow_s64	(int64_t base, uint8_t exp);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
