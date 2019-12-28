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
 * int	reallocarrayfs(type **restrict ptr, ptrdiff_t nmemb);
 *
 * Safe & simple wrapper for `reallocarrayf()`.
 *
 * Features:
 * - Safely computes the element size (second argument to `reallocarrayf()`)
 *	so the user can't make mistakes.
 * - Returns non-zero on error.
 * - Doesn't cast.
 * - Upon failure, the passed pointer is freed, to ease error handling and to
 *	avoid memory leaks.
 * - It fails safely if (nmemb < 0).  With `reallocarray()` the array would be
 *	be allocated (it uses `size_t` instead of `ptrdiff_t`), and it's usage
 *	would likely produce undefined behavior.
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 *
 * example:
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
#include "libalx/base/stdlib/alloc/reallocarrayf.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * reallocarrayfs()
 *
 * ptr:		Pointer to a pointer to the memory to be reallocated.
 *		A pointer to the reallocated memory will be stored
 *		in *ptr.
 * nmemb:	Number of elements in the array.
 *
 * return:
 *	0:		OK.
 *	!= 0:		Failed.
 */
#define alx_reallocarrayfs(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
									\
	*ptr_	= alx_reallocarrayf(*ptr_, nmemb, sizeof(**ptr_));	\
									\
	!(*ptr_);							\
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
 ******* function prototypes **************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
