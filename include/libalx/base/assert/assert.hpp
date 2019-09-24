/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/assert/assert.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cassert>
#include <climits>
#include <cstdbool>
#include <cstdint>
#include <cstdio>

#include <type_traits>

#include "libalx/base/errno/error.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * void	alx_assert(bool expr, const char *msg);
 */
#if !defined(NDEBUG)
#define alx_assert(expr, msg)	do					\
{									\
	const bool	e_ = expr;					\
									\
	if (!e_) {							\
		fputs(msg, stderr);					\
		fputc('\n', stderr);					\
		assert(e_);						\
	}								\
} while (0)
#else
#define alx_assert(expr, msg)	do					\
{									\
									\
	if (!(expr))							\
		alx_perror(msg);					\
} while (0)
#endif

#define alx_Static_assert_array(a)					\
	_Static_assert(std::is_array <typeof(a)>::value, "Not a `[]`!")

#define alx_static_assert_char_array(a)					\
	alx_Static_assert_array(a);					\
	_Static_assert(std::is_same <char, typeof((a)[0])>::value,	\
						"Not a `char[]` !")

#define alx_Static_assert_char_signed()					\
	_Static_assert(CHAR_MIN < 0, "char != signed char")

#define alx_Static_assert_char_unsigned()				\
	_Static_assert(CHAR_MIN == 0, "char != unsigned char")

#define alx_assert_char_signed()					\
	alx_assert(CHAR_MIN < 0, "BUG:   char != signed char")

#define alx_assert_char_unsigned()					\
	alx_assert(CHAR_MIN == 0, "BUG:   char != unsigned char")

#define alx_Static_assert_stdint_types()				\
	alx_Static_assert_u8_uchar();					\
	alx_Static_assert_s8_schar();					\
	alx_Static_assert_u16_ushort();					\
	alx_Static_assert_s16_short();					\
	alx_Static_assert_u32_unsigned();				\
	alx_Static_assert_s32_int();					\
	alx_Static_assert_u64_ulong();					\
	alx_Static_assert_s64_long()

#define alx_Static_assert_u8_uchar()					\
	_Static_assert(std::is_same <uint8_t, unsigned char>::value,	\
				    "uint8_t != unsigned char")

#define alx_Static_assert_s8_schar()					\
	_Static_assert(std::is_same < int8_t, signed char>::value,	\
				     "int8_t != signed char")

#define alx_Static_assert_u16_ushort()					\
	_Static_assert(std::is_same <uint16_t, unsigned short>::value,	\
				    "uint16_t != unsigned short")

#define alx_Static_assert_s16_short()					\
	_Static_assert(std::is_same < int16_t, short>::value,		\
				     "int16_t != short")

#define alx_Static_assert_u32_unsigned()				\
	_Static_assert(std::is_same <uint32_t, unsigned>::value,	\
				    "uint32_t != unsigned")

#define alx_Static_assert_s32_int()					\
	_Static_assert(std::is_same < int32_t, int>::value,		\
				     "int32_t != int")

#define alx_Static_assert_u64_ulong()					\
	_Static_assert(std::is_same <uint64_t, unsigned long>::value,	\
				    "uint64_t != unsigned long")

#define alx_Static_assert_s64_long()					\
	_Static_assert(std::is_same < int64_t, long>::value,		\
				     "int64_t != long")

#define alx_assert_stdint_types()					\
	alx_assert_u8_uchar();						\
	alx_assert_s8_schar();						\
	alx_assert_u16_ushort();					\
	alx_assert_s16_short();						\
	alx_assert_u32_unsigned();					\
	alx_assert_s32_int();						\
	alx_assert_u64_ulong();						\
	alx_assert_s64_long()

#define alx_assert_u8_uchar()						\
	alx_assert(std::is_same <uint8_t, unsigned char>::value,	\
			 "BUG:   uint8_t != unsigned char")

#define alx_assert_s8_schar()						\
	alx_assert(std::is_same <int8_t, signed char>::value,		\
			 "BUG:   int8_t != signed char")

#define alx_assert_u16_ushort()						\
	alx_assert(std::is_same <uint16_t, unsigned short>::value,	\
			 "BUG:   uint16_t != unsigned short")

#define alx_assert_s16_short()						\
	alx_assert(std::is_same <int16_t, short>::value,		\
			 "BUG:   int16_t != short")

#define alx_assert_u32_unsigned()					\
	alx_assert(std::is_same <uint32_t, unsigned>::value,		\
			 "BUG:   uint32_t != unsigned")

#define alx_assert_s32_int()						\
	alx_assert(std::is_same <int32_t, int>::value,			\
			 "BUG:   int32_t != int")

#define alx_assert_u64_ulong()						\
	alx_assert(std::is_same <uint64_t, unsigned long>::value,	\
			 "BUG:   uint64_t != unsigned long")

#define alx_assert_s64_long()						\
	alx_assert(std::is_same <int64_t, long>::value,			\
			 "BUG:   int64_t != long")


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
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
