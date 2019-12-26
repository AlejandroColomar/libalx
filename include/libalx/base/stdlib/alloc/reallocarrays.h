/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/reallocarrays.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * int	alx_reallocarrays(type **restrict ptr, ptrdiff_t nmemb);
 */
#define alx_reallocarrays(ptr, nmemb)	(				\
{									\
	__auto_type	ptr_	= (ptr);				\
	void		*vp_;						\
									\
	vp_	= reallocarray(*ptr_, nmemb, sizeof(**ptr_));		\
	if (vp_)							\
		*ptr_	= vp_;						\
									\
	!vp_;								\
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
