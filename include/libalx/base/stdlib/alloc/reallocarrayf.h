/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrayf.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::warn_unused_result]]
 * void	*reallocarrayf(void *ptr, ptrdiff_t nmemb, size_t size);
 *
 * Almost equivalent to `reallocarray()`.
 *
 * Features:
 * - Upon failure, the passed pointer is freed, to ease error handling and to
 *	avoid memory leaks.
 * - It fails safely if (nmemb < 0).  With `reallocarray()` the array would be
 *	be allocated (it uses `size_t` instead of `ptrdiff_t`), and it's usage
 *	would likely produce undefined behavior.
 *
 * example:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/reallocarrayf.h>
 *
 *		int *arr;
 *
 *		arr	= mallocarray(5, sizeof(*arr);		// int arr[5];
 *		arr	= reallocarrayf(arr, 7, sizeof(*arr));	// int arr[7];
 *		if (!arr)
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
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "libalx/base/assert/assert.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_size_ptrdiff();


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
 * reallocarrayf()
 *
 * ptr:		Pointer to allocated memory (or NULL).
 * nmemb:	Number of elements in the array.
 * size:	Size of each element in the array.
 *
 * return:
 *	!= NULL:	OK.
 *	NULL:		Failed.
 */
__attribute__((warn_unused_result))
inline
void	*alx_reallocarrayf	(void *ptr, ptrdiff_t nmemb, size_t size);


/******************************************************************************
 ******* static inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, warn_unused_result))
static inline
void	*reallocarrayf		(void *ptr, ptrdiff_t nmemb, size_t size)
{
	return	alx_reallocarrayf(ptr, nmemb, size);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
void	*alx_reallocarrayf	(void *ptr, ptrdiff_t nmemb, size_t size)
{

	if (!size)
		goto out;
	if (nmemb < 0)
		goto ovf;
	if ((size_t)nmemb  >  (SIZE_MAX / size))
		goto ovf;

	return	reallocf(ptr, size * (size_t)nmemb);
ovf:
	errno	= ENOMEM;
out:
	free(ptr);
	return	NULL;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
