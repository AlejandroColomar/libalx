/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STRING_STRSTR_HPP
#define ALX_STRING_STRSTR_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/stddef/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
ptrdiff_t alx_strncasestr	(ptrdiff_t size,
				const char *restrict str,
				const char *restrict pattern);
ptrdiff_t alx_strscasestr	(ptrdiff_t size,
				const char *restrict str,
				const char *restrict pattern);
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
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/string/strstr.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
