/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrayfs.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	reallocarrayfs(type **ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `reallocarrayf()`.
 *
 * PARAMETERS:
 * ptr:		Pointer to a pointer to the memory to be reallocated.
 *		A pointer to the reallocated memory will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr set to NULL.
 *	-ERRNO:		Failed.  errno set to ENOMEM.  *ptr set to NULL.
 *
 * FEATURES:
 * - Safely computes the element size (second argument to `reallocarrayf()`).
 * - *ptr is NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - Upon failure, the passed pointer is freed.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocarrayfs.h>
 *
 *		int *arr;
 *
 *		if (mallocarrays(&arr, 5))	// int arr[5];
 *			goto err;
 *		if (reallocarrayfs(&arr, 7))	// int arr[7];
 *			goto err;
 *
 *		// `arr` has been succesfully reallocated here
 *		free(arr);
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
#define alx_reallocarrayfs(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_reallocarrayfs__(*ptr_, nmemb, sizeof(**ptr_), &err_); \
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define reallocarrayfs(ptr, nmemb)	alx_reallocarrayfs(ptr, nmemb)
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
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	alx_reallocarrayfs__(void **ptr, ptrdiff_t nmemb, size_t size);
 *
 * Helper function for `reallocarrayfs()`.
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr set to NULL.
 *	-ERRNO:		Failed.  errno set to ENOMEM.  *ptr set to NULL.
 *
 * FEATURES:
 * - *ptr is NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - Upon failure, the passed pointer is freed.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 */
__attribute__((nonnull, warn_unused_result))
void	*alx_reallocarrayfs__	(void *restrict ptr, ptrdiff_t nmemb,
				 size_t size, int *restrict error);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
