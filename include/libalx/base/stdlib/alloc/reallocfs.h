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
 * int	reallocfs(void **restrict ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `reallocf()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `reallocarray()` family of functions for that purpose).
 *
 * Features:
 * - Returns non-zero on error.
 * - Doesn't cast.
 * - Upon failure, the passed pointer is freed, to ease error handling and to
 *	avoid memory leaks.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 *
 * example:
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
#include <stdlib.h>


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
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * reallocfs()
 *
 * ptr:		Pointer to a pointer to the memory to be reallocated.
 *		A pointer to the reallocated memory will be stored
 *		in *ptr.
 * size:	Size of the buffer (in bytes).
 *
 * return:
 *	0:		OK.
 *	!= 0:		Failed.
 */
__attribute__((nonnull, warn_unused_result))
inline
int	alx_reallocfs	(void **restrict ptr, size_t size);


/******************************************************************************
 ******* static inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
static inline
int	reallocfs	(void **restrict ptr, size_t size)
{
	return	alx_reallocfs(ptr, size);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_reallocfs	(void **restrict ptr, size_t size)
{

	*ptr	= reallocf(*ptr, size);

	return	!*ptr;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
