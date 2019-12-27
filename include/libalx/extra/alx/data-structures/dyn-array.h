/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/data-structures/dyn-array.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic array
 *
 * An array pointer can be created with `struct Alx_Dyn_Buffer *buf;`
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

#include "libalx/extra/alx/data-structures/llist.h"


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
 * Dynamic array
 *
 * data:	Pointer to the first element in the array.
 * elsize:	Size of each cell (in bytes).
 * nmemb:	Number of cells in the array.
 * written:	Number of used cells in the array.
 */
struct	Alx_Dyn_Array {
	void		*data;
	size_t		elsize;
	ptrdiff_t	nmemb;
	ptrdiff_t	written;
};

/* Avoid circular include dependence */
struct	Alx_LinkedList;


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Allocates memory for the array, and updates any necessary metadata.
 * The initialized array has a size of 0 elements.
 *
 * arr:		Pointer to a pointer to an array.  An array will be allocated,
 *		and a pointer to it will be stored in *arr.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the array.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_init		(struct Alx_Dyn_Array **arr, size_t elsize);

/*
 * Deletes `arr`.
 * Deallocates memory from the array.
 * If buf is NULL, no operation is performed.
 *
 * arr:		Pointer to an array.  It is invalid after the call.
 */
void	alx_dynarr_deinit	(struct Alx_Dyn_Array *arr);

/*
 * Writes into the array.
 * Reallocates memory for the data if necessary, copies the data passed by the
 * user to the reallocated space, and updates any necessary metadata.
 *
 * arr:		Pointer to an array.
 * cell:	Write at arr->data[cell].
 * data:	Pointer to the start of the data to be copied.  Should be at
 *		least `elsize` bytes.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_write	(struct Alx_Dyn_Array *arr, ptrdiff_t cell,
				 const void *data);

/*
 * Reads from the array.
 *
 * arr:		Pointer to an array.
 * cell:	Read at arr->data[cell].
 * data:	Copy the read data here.  Should be at least `elsize` bytes.
 *
 * return:
 *	0:		OK.
 *	EBADSLT:	Aborted; cell >= arr->nmemb.
 */
__attribute__((nonnull))
int	alx_dynarr_read		(const struct Alx_Dyn_Array *arr,
				 ptrdiff_t cell, void *data);

/*
 * Reallocates memory for the array, and updates any necessary metadata.
 *
 * arr:		Pointer to an array.
 * nmemb:	New array size (in number of elements).
 * elsize:	New element size.  A value of 0 keeps the old value.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the array.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_resize	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t nmemb, size_t elsize);

/*
 * Reset the array as if just initialized.
 *
 * arr:		Pointer to an array.
 * elsize:	New element size.  A value of 0 keeps the old value.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the array.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_reset	(struct Alx_Dyn_Array *arr, size_t elsize);

/*
 * Shrink the array to fit the used space.
 *
 * arr:		Pointer to an array.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the array.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_fit		(struct Alx_Dyn_Array *arr);

/*
 * Copy the array data into an empty linked list.  If the list is not empty,
 * all of its previous nodes will be safely deleted.  Only the `written` part
 * in the array will be copied.  The dynamic array is unchanged.
 *
 * arr:		Pointer to an array.
 * list:	Pointer to a list.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the nodes.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_dynarr_to_llist	(struct Alx_Dyn_Array *arr,
				 struct Alx_LinkedList *list);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
