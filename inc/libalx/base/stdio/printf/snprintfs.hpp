/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDIO_PRINTF_SNPRINTFS_HPP
#define ALX_STDIO_PRINTF_SNPRINTFS_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdarg>
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


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
 ******* extern functions *****************************************************
 ******************************************************************************/
int swnprintf(char *restrict str, ptrdiff_t *restrict written,
	      ptrdiff_t nmemb, const char *restrict format, ...)
__attribute__((format(printf, 4, 5)));
int vswnprintf(char *restrict str, ptrdiff_t *restrict written,
	       ptrdiff_t nmemb, const char *restrict format, va_list ap)
__attribute__((format(printf, 4, 0)));


/******************************************************************************
 ******* template (declarations) **********************************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* template (definitions) ***********************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdio/printf/snprintfs.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/