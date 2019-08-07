/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/string/strgrep.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <string.h>


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
 ******* function prototypes **************************************************
 ******************************************************************************/
__attribute__((nonnull))
ptrdiff_t	alx_strnfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strlfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strsfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size]);
__attribute__((nonnull))
ptrdiff_t	alx_strncasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strlcasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strscasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size]);
__attribute__((nonnull))
ptrdiff_t	alx_strnfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strlfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strsfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size]);
__attribute__((nonnull))
ptrdiff_t	alx_strncasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strlcasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict]);
__attribute__((nonnull))
ptrdiff_t	alx_strscasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size]);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
