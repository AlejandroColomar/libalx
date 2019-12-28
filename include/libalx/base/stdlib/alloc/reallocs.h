/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocs.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	reallocs(void **restrict ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `reallocf()`.
 * To be used for generic buffers of bytes, and not for arrays (use
 * `reallocarray()` family of functions for that purpose).
 *
 * Features:
 * - Returns non-zero on error.
 * - Doesn't cast.
 * - Upon failure, the pointer is untouched (no memory leak).
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 *
 * example:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocs.h>
 *
 *		char *buf;
 *
 *		if (mallocs(&buf, 5))	// char buf[5];
 *			goto err;
 *		if (reallocs(&buf, 7))	// char buf[7];
 *			goto err;
 *
 *		// `buf` has been succesfully reallocated here
 *	err:
 *		free(buf);
 *		// No memory leaks
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
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
 * reallocs()
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
int	alx_reallocs	(void **restrict ptr, size_t size);

/*
 * alx_reallocs__()
 *
 * This function safely assigns the result of a reallocation to the pointer
 * provided.  If the reallocation failed, this function doesn't assign the
 * pointer, and keeps the old one.  This function is only to be used within
 * this library, and should not be called directly by the user.
 *
 * ptr:		Pointer to a pointer to the memory to be reallocated.
 *		A pointer to the reallocated memory will be stored
 *		in *ptr.
 * vp:		Result of `realloc()`.
 * size:	`size` passed to `realloc()`.
 *
 * return:
 *	0:		OK.
 *	!= 0:		Reallocation failed.
 */
__attribute__((nonnull(1), warn_unused_result))
inline
int	alx_reallocs__	(void **restrict ptr, void *restrict vp, size_t size);


/******************************************************************************
 ******* static inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
static inline
int	reallocs	(void **restrict ptr, size_t size)
{
	return	alx_reallocs(ptr, size);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
int	alx_reallocs	(void **restrict ptr, size_t size)
{
	void	*vp;

	vp	= realloc(*ptr, size);

	return	alx_reallocs__(ptr, vp, size);
}

inline
int	alx_reallocs__	(void **restrict ptr, void *restrict vp, size_t size)
{
	bool	failed;

	failed	= !vp && size;
	if (!failed)
		*ptr	= vp;

	return	failed;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
