/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocs.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]  [[gnu::warn_unused_result]]
 * int	mallocs(void **ptr, size_t size);
 *
 * Safe & simple wrapper for `malloc()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `mallocarray()` family of functions for that purpose).
 *
 * RETURN:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * size:	Size of the buffer (in bytes).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr set to NULL.
 *	-ERRNO:		Failed.  errno set to ENOMEM.  *ptr set to NULL.
 *
 * FEATURES:
 * - *ptr is NULL on zero size allocation.
 * - Doesn't cast.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/mallocs.h>
 *
 *		char *buf;
 *
 *		if (mallocs(&buf, 7))		// char buf[7];
 *			goto err;
 *
 *		// `buf` has been succesfully allocated here
 *		free(buf);
 *	err:
 *		// No memory leaks
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_mallocs(ptr, size)	(					\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_mallocs__(size, &err_);				\
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define mallocs(ptr, size)	alx_mallocs(ptr, size)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((malloc, nonnull, warn_unused_result))
void	*alx_mallocs__	(size_t size, int *error);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
