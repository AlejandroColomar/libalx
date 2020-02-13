/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/dyn-array.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/alx/data-structures/llist.h"
#include "libalx/alx/data-structures/types.h"
#include "libalx/base/assert/assert.h"
#include "libalx/base/stdlib/maximum.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/alloc/frees.h"
#include "libalx/base/stdlib/alloc/reallocarrays.h"


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
int	alx_dynarr_grow		(struct Alx_DynArr *arr, ptrdiff_t nmemb);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_dynarr_init		(struct Alx_DynArr **arr, size_t elsize)
{
	int	err;

	if (!elsize)
		return	ENOMEM;
	if (alx_mallocarrays(arr, 1))
		return	ENOMEM;
	/* Initial nmemb of 1 (minimum allocation) */
	(*arr)->data	= alx_mallocarrays__(1, elsize, &err);
	if (err)
		goto err;

	(*arr)->elsize	= elsize;
	(*arr)->nmemb	= 1;
	(*arr)->written	= 0;

	return	0;
err:
	alx_frees(arr);
	return	ENOMEM;
}

void	alx_dynarr_deinit	(struct Alx_DynArr *arr)
{

	if (!arr)
		return;

	free(arr->data);
	free(arr);
}

int	alx_dynarr_write	(struct Alx_DynArr *restrict arr,
				 ptrdiff_t cell, const void *restrict data)
{

	if (cell < 0)
		return	EBADSLT;

	if (cell >= arr->nmemb) {
		if (alx_dynarr_grow(arr, cell + 1))
			return	ENOMEM;
	}

	memcpy(&((char *)arr->data)[cell * arr->elsize], data, arr->elsize);
	if (cell >= arr->written)
		arr->written	= cell + 1;

	return	0;
}

int	alx_dynarr_insert	(struct Alx_DynArr *restrict arr,
				 ptrdiff_t cell, const void *restrict data)
{
	size_t	elsz;

	if (cell < 0)
		return	EBADSLT;

	if (cell >= arr->nmemb)
		return	alx_dynarr_write(arr, cell, data);
	if (arr->written == arr->nmemb) {
		if (alx_dynarr_grow(arr, arr->nmemb + 1))
			return	ENOMEM;
	}

	elsz	= arr->elsize;
	memmove(&((char *)arr->data)[(cell + 1) * elsz],
					&((char *)arr->data)[cell * elsz],
					(arr->written - cell) * elsz);
	memcpy(&((char *)arr->data)[cell * elsz], data, elsz);
	arr->written++;

	return	0;
}

int	alx_dynarr_read		(const struct Alx_DynArr *restrict arr,
				 ptrdiff_t cell, void *restrict data)
{

	if (cell >= arr->written)
		return	EBADSLT;
	if (cell < 0)
		return	EBADSLT;

	memcpy(data, &((char *)arr->data)[cell * arr->elsize], arr->elsize);

	return	0;
}

int	alx_dynarr_remove	(struct Alx_DynArr *arr,
				 ptrdiff_t cell)
{
	size_t	elsz;

	elsz	= arr->elsize;

	if (cell >= arr->written)
		return	EBADSLT;
	if (cell < 0)
		return	EBADSLT;

	memmove(&((char *)arr->data)[(cell) * elsz],
					&((char *)arr->data)[(cell + 1) * elsz],
					(arr->written - cell - 1) * elsz);
	arr->written--;

	return	0;
}

int	alx_dynarr_resize	(struct Alx_DynArr *arr,
				 ptrdiff_t nmemb, size_t elsize)
{
	int	err;

	if (!nmemb)
		return	alx_dynarr_reset(arr, elsize);

	if (!elsize)
		elsize	= arr->elsize;
	if ((size_t)nmemb > (SIZE_MAX / elsize))
		return	ENOMEM;

	arr->data	= alx_reallocarrays__(arr->data, nmemb, elsize, &err);
	if (err)
		return	ENOMEM;
	arr->elsize	= elsize;
	arr->nmemb	= nmemb;
	if (arr->written > nmemb)
		arr->written	= nmemb;

	return	0;
}

int	alx_dynarr_reset	(struct Alx_DynArr *arr, size_t elsize)
{
	int	err;

	if (!elsize)
		elsize	= arr->elsize;

	arr->data	= alx_reallocarrays__(arr->data, 1, elsize, &err);
	if (err)
		return	ENOMEM;
	arr->elsize	= elsize;
	arr->nmemb	= 1;
	arr->written	= 0;

	return	alx_dynarr_resize(arr, 0, 0);
}

int	alx_dynarr_fit		(struct Alx_DynArr *arr)
{

	return	alx_dynarr_resize(arr, arr->written, 0);
}

int	alx_dynarr_to_llist	(struct Alx_DynArr *arr,
				 struct Alx_LinkedList *list)
{
	const void	*cell;

	alx_llist_delete_all(list);

	cell	= arr->data;
	for (ptrdiff_t i = 0; i < arr->written; i++) {
		if (alx_llist_append(list, 0, cell, arr->elsize))
			goto err;
		cell	+= arr->elsize;
	}

	return	0;
err:
	alx_llist_delete_all(list);
	return	ENOMEM;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_dynarr_grow		(struct Alx_DynArr *arr, ptrdiff_t nmemb)
{
	ptrdiff_t	n;

	if (nmemb < 0)
		return	ENOMEM;

	if (arr->nmemb >= PTRDIFF_MAX / 2)
		n	= PTRDIFF_MAX;
	else
		n	= arr->nmemb * 2;
	if ((size_t)n > (SIZE_MAX / arr->elsize))
		n	= SIZE_MAX / arr->elsize;

	n	= ALX_MAX(n, nmemb);

	if (n <= arr->nmemb)
		return	ENOMEM;

	return	alx_dynarr_resize(arr, n, arr->elsize);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
