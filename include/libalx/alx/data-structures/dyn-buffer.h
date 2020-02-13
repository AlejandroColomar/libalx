/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dyn-buffer.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic buffer
 *
 * A buffer pointer can be created with `struct Alx_Dyn_Buffer *buf;`
 * To use the buffer, it has to be initialized with `alx_dynbuf_init(&buf)`.
 * It can be deinitialized with `alx_dynbuf_deinit(buf)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * A buffer stores a pointer to its allocated data, the size of the buffer,
 * and the initialized bytes in the buffer.
 *
 * If any of the list metadata is manually modified by the user, the buffer
 * may be corrupted, and the behavior is undefined.  The only thing that the
 * user can safely manually modify are the contents of data, being careful of
 * not overrunning the buffer.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include <sys/types.h>

#include "libalx/alx/data-structures/types.h"


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
 * Allocates memory for the buffer, and updates any necessary metadata.
 * The initialized buffer has a size of 1 byte.
 *
 * buf:		Pointer to a pointer to a buffer.  A buffer will be allocated,
 *		and a pointer to it will be stored in *buf.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the buffer.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynbuf_init		(struct Alx_Dyn_Buffer **buf);

/*
 * Allocates memory for the buffer, and clones the ref buffer into it.
 *
 * clone:	Pointer to a pointer to a buffer.  A buffer will be allocated,
 *		and a pointer to it will be stored in *clone.
 * ref:		Pointer to a buffer to clone from.
 *
 * return:
 *	0:		OK.
 *	ENOANO:		Aborted; ref was NULL.
 *	ENOMEM:		Aborted; failure to allocate the buffer.
 */
__attribute__((nonnull(1), warn_unused_result))
int	alx_dynbuf_init_clone	(struct Alx_Dyn_Buffer **restrict clone,
				 const struct Alx_Dyn_Buffer *restrict ref);

/*
 * Deletes `buf`.
 * Deallocates memory from the buffer.
 * If buf is NULL, no operation is performed.
 *
 * buf:		Pointer to a buffer.  It is invalid after the call.
 */
void	alx_dynbuf_deinit	(struct Alx_Dyn_Buffer *buf);

/*
 * Writes into the buffer.
 * Reallocates memory for the data if necessary, copies the data passed by the
 * user to the reallocated space, and updates any necessary metadata.
 *
 * buf:		Pointer to a buffer.
 * offset:	Start writing at buf->data + offset.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynbuf_write	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size);

/*
 * Inserts into the buffer.
 * The data that was previously after `offset` bytes is moved so that after
 * the operation it starts at the end of the new data.
 * Reallocates memory for the data if necessary, copies the data passed by the
 * user to the reallocated space, and updates any necessary metadata.
 *
 * buf:		Pointer to a buffer.
 * offset:	Start writing at buf->data + offset.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynbuf_insert	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size);

/*
 * Reads from the buffer.
 *
 * buf:		Pointer to a buffer.
 * offset:	Start reading at buf->data + offset.
 * data:	Copy the read data here.  Should be at least `size` bytes.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	>0:		OK. data was truncated. number of bytes actually read.
 *	-1:		Aborted; invalid offset.
 */
__attribute__((nonnull, warn_unused_result))
ssize_t	alx_dynbuf_read		(void *restrict data, size_t size,
				 const struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset);

/*
 * Consume part of the buffer.
 * The buffer data is moved down `size` bytes.
 *
 * buf:		Pointer to a buffer.
 * size:	Number of bytes to be consumed.
 */
__attribute__((nonnull))
void	alx_dynbuf_consume	(struct Alx_Dyn_Buffer *buf, size_t size);

/*
 * Reallocates memory for the buffer, and updates any necessary metadata.
 *
 * buf:		Pointer to a buffer.
 * size:	New size.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the data.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynbuf_resize	(struct Alx_Dyn_Buffer *buf, size_t size);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
