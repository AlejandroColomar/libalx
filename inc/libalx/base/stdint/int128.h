/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDINT_INT128_H
#define ALX_STDINT_INT128_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>


/******************************************************************************
 ******* typedefs *************************************************************
 ******************************************************************************/
/* This is to test if uint128_t already exists */
#if !defined(UINT128_MAX)
	typedef	unsigned __int128	uint128_t;
	typedef	__int128		int128_t;
#endif


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define U128_MAX	(~((uint128_t)0))
#define S128_MAX	((int128_t)(U128_MAX >> 1))
#define S128_MIN	((int128_t)(-S128_MAX - 1))

#define SQRT_U128_MAX	((uint128_t)(0xFFFFFFFFFFFFFFFF))
#define SQRT_S128_MAX	((int128_t)(0xB504F333F9DE6800))


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


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdint/int128.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
