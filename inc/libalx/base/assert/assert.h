/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/assert.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <limits.h>
#include <stdint.h>

#include "libalx/base/compiler/type.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_Static_assert_array(a)					\
	_Static_assert(!alx_same_type((a), &(a)[0]), "Not a `[]` !")

#define alx_Static_assert_char_array(a)					\
	alx_Static_assert_array(a);					\
	_Static_assert(__builtin_types_compatible_p(			\
			char, typeof((a)[0])),				\
			"Not a `char[]` !")

#define alx_Static_assert_char_signed()					\
	_Static_assert(CHAR_MIN < 0, "char != signed char")

#define alx_Static_assert_char_unsigned()				\
	_Static_assert(CHAR_MIN == 0, "char != unsigned char")

#define alx_Static_assert_stdint_types()				\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint8_t, unsigned char),			\
			"uint8_t != unsigned char");			\
	_Static_assert(__builtin_types_compatible_p(			\
			 int8_t, signed char),				\
			"int8_t != signed char");			\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint16_t, unsigned short),			\
			"uint16_t != unsigned short");			\
	_Static_assert(__builtin_types_compatible_p(			\
			 int16_t, short),				\
			"int16_t != short");				\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint32_t, unsigned),				\
			"uint32_t != unsigned");			\
	_Static_assert(__builtin_types_compatible_p(			\
			 int32_t, int),					\
			"int32_t != int");				\
	_Static_assert(__builtin_types_compatible_p(			\
			 uint64_t, unsigned long),			\
			"uint64_t != unsigned long");			\
	_Static_assert(__builtin_types_compatible_p(			\
			 int64_t, long),				\
			"int64_t != long")


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
