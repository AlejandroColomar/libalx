/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/frees.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * void	frees(type **ptr);
 *
 * Safe wrapper for `free()`.
 *
 * PARAMETERS:
 * ptr:		*ptr will be deallocated, and NULL will be stored in *ptr.
 *
 * FEATURES:
 * - Stores NULL in the pointer so that it can be freed more than once safely.
 *
 * EXAMPLE:
 *	#define ALX_NO_PREFIX
 *	#include <libalx/base/stdlib/alloc/frees.h>
 *
 *		char *buf;
 *
 *		buf	= malloc(1);
 *
 *		frees(&buf);	// `buf` has been freed here;  buf is NULL.
 *		frees(&buf);	// No memory leaks or undefined behavior
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_frees(ptr)	do						\
{									\
	__auto_type	ptr_	= (ptr);				\
									\
	free(*ptr_);							\
	*ptr_	= NULL;							\
} while (0)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define frees(ptr)	alx_frees(ptr)
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


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/