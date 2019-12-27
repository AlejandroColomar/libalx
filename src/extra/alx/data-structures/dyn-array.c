/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/data-structures/dyn-array.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/assert/assert.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_size_ptrdiff();


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
static
int	alx_dynarr_grow		(struct Alx_Dyn_Array *arr);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_dynarr_init		(struct Alx_Dyn_Array **arr, size_t elsize)
{

	if (!elsize)
		return	ENOMEM;
	if (alx_mallocarrays(arr, 1))
		return	ENOMEM;

	(*arr)->elsize	= elsize;
	(*arr)->nmemb	= 0;
	(*arr)->written	= 0;

	return	0;
}

void	alx_dynarr_deinit	(struct Alx_Dyn_Array *arr)
{

	if (!arr)
		return;

	free(arr->data);
	free(arr);
}

int	alx_dynarr_write	(struct Alx_Dyn_Array *arr, ptrdiff_t cell,
				 const void *data)
{

	while (cell >= arr->nmemb) {
		if (alx_dynarr_grow(arr))
			return	ENOMEM;
	}

	memmove(arr->data + (cell * arr->elsize), data, arr->elsize);
	if (cell >= arr->written)
		arr->written	= cell + 1;

	return	0;
}

int	alx_dynarr_read		(const struct Alx_Dyn_Array *arr,
				 ptrdiff_t cell, void *data)
{

	if (cell >= arr->nmemb)
		return	ENOENT;
	memmove(data, arr->data + (cell * arr->elsize), arr->elsize);

	return	0;
}

int	alx_dynarr_resize	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t nmemb, size_t elsize)
{
	void	*vp;

	if (!elsize)
		elsize	= arr->elsize;
	if ((size_t)nmemb > (SIZE_MAX / arr->elsize))
		return	ENOMEM;

	vp	= reallocarray(arr->data, nmemb, elsize);
	if (!vp)
		return	ENOMEM;

	arr->data	= vp;
	arr->elsize	= elsize;
	arr->nmemb	= nmemb;
	if (arr->written > nmemb)
		arr->written	= nmemb;

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_dynarr_grow		(struct Alx_Dyn_Array *arr)
{
	ptrdiff_t	nmemb;

	if (!arr->nmemb)
		nmemb	= 1;
	else if (arr->nmemb >= PTRDIFF_MAX / 2)
		nmemb	= PTRDIFF_MAX;
	else
		nmemb	= arr->nmemb * 2;
	if ((size_t)nmemb > (SIZE_MAX / arr->elsize))
		nmemb	= SIZE_MAX / arr->elsize;

	if (nmemb <= arr->nmemb)
		return	ENOMEM;

	return	alx_dynarr_resize(arr, nmemb, arr->elsize);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
