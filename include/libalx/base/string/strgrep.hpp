/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/string/strgrep.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstring>

#include "libalx/base/stddef/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
ptrdiff_t	alx_strnfgrep		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strlfgrep		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strsfgrep		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strncasefgrep	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strlcasefgrep	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strscasefgrep	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strnfgrepv		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strlfgrepv		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strsfgrepv		(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strncasefgrepv	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strlcasefgrepv	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
[[gnu::nonnull]]
ptrdiff_t	alx_strscasefgrepv	(ptrdiff_t size,
					 char *restrict dest,
					 const char *restrict src,
					 const char *restrict pattern);
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
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
