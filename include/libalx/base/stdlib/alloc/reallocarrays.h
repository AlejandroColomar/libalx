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
 * [[gnu::nonnull]][[gnu::warn_unused_result]]
 * int	reallocarrays(type **restrict ptr, size_t nmemb);
 *
 * Safe & simple wrapper for `reallocarray()`.
 *
 * Features:
 * - Safely computes the element size (second argument to `reallocarray()`)
 *	so the user can't make mistakes.
 * - Returns non-zero on error.
 * - Doesn't cast.
 * - Upon failure, the pointer is untouched (no memory leak).
 * - The pointer stored in `*ptr` is always a valid pointer or NULL.
 *
 * example:
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
#include <stdlib.h>

#include "libalx/base/stdlib/alloc/reallocs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * reallocarrays()
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
#define alx_reallocarrays(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	__auto_type	nmemb_	= (nmemb);				\
	void		*vp_;						\
									\
	vp_	= reallocarray(*ptr_, nmemb_, sizeof(**ptr_));		\
									\
	alx_reallocs__(ptr_, vp_, nmemb_);				\
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
 ******* function prototypes **************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
