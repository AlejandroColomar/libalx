/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/data-structures/dyn-buffer.h */


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


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
/*
 * Dynamic buffer
 *
 * data:	Pointer to the first byte in the buffer.
 * size:	Size of the data buffer (in bytes).
 * written:	Data used (in bytes).
 */
struct	Alx_Dyn_Buffer {
	void	*data;
	size_t	size;
	size_t	written;
};


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
int	alx_dynbuf_write	(struct Alx_Dyn_Buffer *buf, size_t offset,
				 const void *data, size_t size);

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
 *	ENOBUFS:	OK. data was truncated.
 *	EFAULT:		Aborted; invalid offset.
 */
__attribute__((nonnull))
int	alx_dynbuf_read		(const struct Alx_Dyn_Buffer *buf,
				 size_t offset, void *data, size_t size);

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
