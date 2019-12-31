/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocarrays.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]] [[gnu::warn_unused_result]]
 * int	mallocarrays(type **ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `mallocarray()`.
 *
 * PARAMETERS:
 * ptr:		Memory will be allocated, and a pointer to it will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * RETURN:
 *	0:		OK.
 *	ERRNO:		OK.  nmemb == 0.  *ptr set to NULL.
 *	-ERRNO:		Failed.  errno set to ENOMEM.  *ptr set to NULL.
 *
 * FEATURES:
 * - Safely computes the element size (second argument to `mallocarray()`).
 * - *ptr is NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/mallocarrays.h>
 *
 *		int *arr;
 *
 *		if (mallocarrays(&arr, 7))		// int arr[7];
 *			goto err;
 *
 *		// `arr` has been succesfully allocated here
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
#define alx_mallocarrays(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	*ptr_	= alx_mallocarrays__(nmemb, sizeof(**ptr_), &err_);	\
	alx_warn_unused_int(err_);					\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define mallocarrays(ptr, nmemb)	alx_mallocarrays(ptr, nmemb)
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
 * int	alx_mallocarrays__(void **ptr, ptrdiff_t nmemb, size_t size);
 *
 * Helper function for `mallocarrays()`.
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
 *	-ERRNO:		Failure.  errno set to ENOMEM.  *ptr set to NULL.
 *
 * FEATURES:
 * - *ptr is NULL on zero size allocation.
 * - Fails safely if (nmemb < 0).
 * - Fails safely if (nmemb * size) would overflow.
 * - Doesn't cast.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 * - Returns non-zero if the resulting pointer is NULL.
 */
__attribute__((malloc, nonnull, warn_unused_result))
void	*alx_mallocarrays__	(ptrdiff_t nmemb, size_t size, int *error);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
