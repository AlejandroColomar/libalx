/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/mallocarray.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
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
 ******* function prototypes **************************************************
 ******************************************************************************/
__attribute__((malloc))
inline
void	*alx_mallocarray(ptrdiff_t nmemb, size_t size);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
void	*alx_mallocarray(ptrdiff_t nmemb, size_t size)
{

	if (nmemb < 0)
		goto ovf;
	if (nmemb > (PTRDIFF_MAX / (ptrdiff_t)size))
		goto ovf;

	return	malloc(size * nmemb);
ovf:
	errno	= EOVERFLOW;
	return	NULL;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
