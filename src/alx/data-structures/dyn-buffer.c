/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/dyn-buffer.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/assert/assert.h"
#include "libalx/base/stdlib/minimum.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/alloc/mallocs.h"
#include "libalx/base/stdlib/alloc/reallocs.h"


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
int	alx_dynbuf_grow		(struct Alx_Dyn_Buffer *buf);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_dynbuf_init		(struct Alx_Dyn_Buffer **buf)
{

	if (alx_mallocarrays(buf, 1))
		return	ENOMEM;
	if (alx_mallocs(&(*buf)->data, 1))
		goto err;
	(*buf)->size	= 1;
	(*buf)->written	= 0;

	return	0;
err:
	free(*buf);
	return	ENOMEM;
}

void	alx_dynbuf_deinit	(struct Alx_Dyn_Buffer *buf)
{

	if (!buf)
		return;

	free(buf->data);
	free(buf);
}

int	alx_dynbuf_write	(struct Alx_Dyn_Buffer *buf, size_t offset,
				 const void *data, size_t size)
{
	size_t	written;

	while ((size + offset) > buf->size) {
		if (alx_dynbuf_grow(buf))
			return	ENOMEM;
	}

	memmove(buf->data + offset, data, size);
	written	= size + offset;
	if (written > buf->written)
		buf->written	= written;

	return	0;
}

int	alx_dynbuf_read		(const struct Alx_Dyn_Buffer *buf,
				 size_t offset, void *data, size_t size)
{
	size_t	sz;

	if (offset > buf->size)
		return	EFAULT;
	sz	= ALX_MIN(size, buf->size - offset);
	memmove(data, buf->data + offset, sz);

	if (size  <  buf->size - offset)
		return	ENOBUFS;
	return	0;
}

int	alx_dynbuf_resize	(struct Alx_Dyn_Buffer *buf, size_t size)
{

	if (size > PTRDIFF_MAX  ||  !size)
		return	ENOMEM;

	if (alx_reallocs(&buf->data, size))
		return	ENOMEM;
	buf->size	= size;

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_dynbuf_grow		(struct Alx_Dyn_Buffer *buf)
{
	size_t	size;

	if (buf->size >= PTRDIFF_MAX / 2)
		size	= PTRDIFF_MAX;
	else
		size	= buf->size * 2;

	if (size <= buf->size)
		return	ENOMEM;

	return	alx_dynbuf_resize(buf, size);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
