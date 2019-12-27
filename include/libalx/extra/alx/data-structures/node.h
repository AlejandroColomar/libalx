/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/data-structures/node.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Node
 *
 * A list pointer can be created with `struct Alx_LinkedList *list;`
 * To use the list, it has to be initialized with `alx_llist_init(&list)`.
 * It can be deinitialized with `alx_llist_deinit(list)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * Each node stores a pointer to its allocated data, the size of the data,
 * and pointers to the two connecting nodes.
 *
 * If any of the list metadata is manually modified by the user, the list may
 * be corrupted, and the behavior is undefined.  The only thing that the user
 * can safely manually modify are the contents of data, being careful of not
 * overrunning the buffer.
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
 * Doubly linked node
 *
 * data:	Pointer to allocated memory containing useful data.
 * size:	Size of the allocated buffer (in bytes).
 * left:	Pointer to the leftious node.
 * right:	Pointer to the right node.
 */
struct	Alx_Node {
	void		*data;
	size_t		size;
	struct Alx_Node	*left;
	struct Alx_Node	*right;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_new		(struct Alx_Node **node,
				 const void *data, size_t size);

/*
 * Allocates memory for the node (not for the data), and updates any
 * necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_new_empty	(struct Alx_Node **node);

/*
 * Deletes `node`.
 * Deallocates memory from the node and from the data.
 */
__attribute__((nonnull))
void	alx_node_delete		(struct Alx_Node *node);

/*
 * Edits the node data.
 * Reallocates memory for the the data, copies the data passed by the user to
 * the reallocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_edit_data	(struct Alx_Node *node,
				 const void *data, size_t size);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
