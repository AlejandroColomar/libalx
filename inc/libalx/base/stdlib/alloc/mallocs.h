/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocs.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libalx/base/stdlib/alloc/mallocarray.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * int	alx_mallocs(type **restrict p, ptrdiff_t nmemb);
 */
#define alx_mallocs(ptr, nmemb)	(					\
{									\
	__auto_type	ptr_	= (ptr);				\
									\
	*ptr_	= alx_mallocarray(nmemb, sizeof(**ptr_));		\
									\
	!(*ptr_);							\
}									\
)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
