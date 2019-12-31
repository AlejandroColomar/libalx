/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocfs.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	reallocfs(void **ptr, size_t size);
 *
 * Safe & simple wrapper for `reallocf()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `reallocarray()` family of functions for that purpose).
 *
 * PARAMETERS:
 * ptr:		Pointer to a pointer to the memory to be reallocated.
 *		A pointer to the reallocated memory will be stored
 *		in *ptr.
 * size:	Size of the buffer (in bytes).
 *
 * RETURN:
 *	0:		OK.
 *	!= 0:		Failed.
 *
 * FEATURES:
 * - Returns non-zero on error.
 * - Doesn't cast.
 * - Upon failure, the passed pointer is freed.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocfs.h>
 *
 *		char *buf;
 *
 *		if (mallocs(&buf, 5))	// char buf[5];
 *			goto err;
 *		if (reallocfs(&buf, 7))	// char buf[7];
 *			goto err;
 *
 *		// `buf` has been succesfully reallocated here
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
#define alx_reallocfs(ptr, size)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_reallocfs__(*ptr_, size, &err_);			\
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define reallocfs(ptr, size)	alx_reallocfs(ptr, size)
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
__attribute__((nonnull, warn_unused_result))
void	*alx_reallocfs__	(void *restrict ptr, size_t size,
				 int *restrict error);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
