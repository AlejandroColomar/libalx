/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/alloc/reallocarrays.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
void	*alx_reallocarrays__	(void *restrict ptr, ptrdiff_t nmemb,
				 size_t size, int *restrict error)
{
	void	*p;

	*error	= 0;
	if (!nmemb || !size)
		goto zero;
	if (nmemb < 0)
		goto ovf;

	p	= reallocarray(ptr, nmemb, size);
	if (!p)
		goto err;

	return	p;
ovf:
	errno	= ENOMEM;
err:
	*error	= -ENOMEM;
	return	ptr;
zero:
	free(ptr);
	*error	= ENOMEM;
	return	NULL;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
