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

#include <sys/types.h>

#include "libalx/base/assert/assert.h"
#include "libalx/base/stdlib/maximum.h"
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
int	alx_dynbuf_grow		(struct Alx_Dyn_Buffer *buf, size_t size);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_dynbuf_init		(struct Alx_Dyn_Buffer **buf)
{

	if (alx_mallocarrays(buf, 1))
		return	ENOMEM;
	/* Initial size of 1 (minimum allocation) */
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

int	alx_dynbuf_write	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size)
{
	size_t	written;

	if ((size + offset) > buf->size) {
		if (alx_dynbuf_grow(buf, size + offset))
			return	ENOMEM;
	}

	memmove(&buf->data[offset], data, size);
	written	= size + offset;
	if (written > buf->written)
		buf->written	= written;

	return	0;
}

int	alx_dynbuf_insert	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size)
{

	if ((size + buf->written) > buf->size) {
		if (alx_dynbuf_grow(buf, size + buf->written))
			return	ENOMEM;
	}

	memmove(&buf->data[offset + size], &buf->data[offset],
							buf->written - offset);
	memmove(&buf->data[offset], data, size);
	buf->written	+= size;

	return	0;
}

ssize_t	alx_dynbuf_read		(void *restrict data, size_t size,
				 const struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset)
{
	size_t	sz;

	if (offset >= buf->written)
		return	-1;
	sz	= ALX_MIN(size, buf->written - offset);
	memmove(data, &buf->data[offset], sz);

	if (size  <  buf->written - offset)
		return	sz;
	return	0;
}

void	alx_dynbuf_consume	(struct Alx_Dyn_Buffer *buf, size_t size)
{

	if (size >= buf->written) {
		buf->written	= 0;
		return;
	}

	buf->written	-= size;
	memmove(buf->data, &buf->data[size], buf->written);
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
int	alx_dynbuf_grow		(struct Alx_Dyn_Buffer *buf, size_t size)
{
	size_t	sz;

	if (size > PTRDIFF_MAX)
		return	ENOMEM;

	if (buf->size >= PTRDIFF_MAX / 2)
		sz	= PTRDIFF_MAX;
	else
		sz	= buf->size * 2;

	sz	= ALX_MAX(sz, size);

	if (sz <= buf->size)
		return	ENOMEM;

	return	alx_dynbuf_resize(buf, size);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
