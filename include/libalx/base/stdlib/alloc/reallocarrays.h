/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrays.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	reallocarrays(type **ptr, size_t nmemb);
 *
 * Safe & simple wrapper for `reallocarray()`.
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr = NULL.
 *	-ERRNO:		Failed.  errno = ENOMEM.  *ptr is untouched.
 *
 * FEATURES:
 * - Safely computes the element size (second argument to `reallocarray()`).
 * - *ptr is NULL on zero size reallocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - Upon failure, the pointer is untouched.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL or untouched.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocarrays.h>
 *
 *		int *arr;
 *
 *		if (mallocarrays(&arr, 5))	// int arr[5];
 *			goto err;
 *		if (reallocarrays(&arr, 7))	// int arr[7];
 *			goto err;
 *
 *		// `arr` has been succesfully reallocated here
 *	err:
 *		free(arr);
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
#define alx_reallocarrays(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_reallocarrays__(*ptr_, nmemb, sizeof(**ptr_), &err_); \
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define reallocarrays(ptr, nmemb)	alx_reallocarrays(ptr, nmemb)
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
 * void	*alx_reallocarrays__(void *restrict ptr, ptrdiff_t nmemb, size_t size,
 *			     int *restrict error);
 *
 * Helper function for `reallocarrays()`.
 *
 * PARAMETERS:
 * ptr:		Pointer to allocated memory (or NULL).
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 * error:	Variable to pass the error code (through a pointer to it).
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  return NULL.
 *	-ERRNO:		Failure.  errno = ENOMEM.  return ptr.
 *
 * FEATURES:
 * - Returns NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Upon failure, the pointer is returned untouched.
 * - error is non-zero if the resulting pointer is NULL or untouched.
 */
__attribute__((nonnull, warn_unused_result))
void	*alx_reallocarrays__	(void *restrict ptr, ptrdiff_t nmemb,
				 size_t size, int *restrict error);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull, warn_unused_result))
inline
void	*reallocarrays__	(void *restrict ptr, ptrdiff_t nmemb,
				 size_t size, int *restrict error)
{
	return	alx_reallocarrays__(ptr, nmemb, size, error);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
