/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDIO_PRINTF_SBPRINTF_HPP
#define ALX_STDIO_PRINTF_SBPRINTF_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdio>

#include "libalx/base/assert/assert.hpp"
#include "libalx/base/compiler/size.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* int	sbprintf(buff[__restrict__], const char *restrict format, ...); */
#define sbprintf(buff, format, ...)	(				\
{									\
	alx_static_assert_array(buff);					\
									\
	snprintf(buff, sizeof(buff), format, ##__VA_ARGS__) >= SSIZEOF(buff) \
}									\
)


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
#endif		/* libalx/base/stdio/printf/sbprintf.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
