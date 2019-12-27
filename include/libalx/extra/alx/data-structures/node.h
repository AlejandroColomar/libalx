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
 * Doubly linked node
 *
 * A node pointer can be created with `struct Alx_Node *node;`
 * To use the node, it has to be initialized with
 * `alx_node_init(&node, data, size)` or `alx_node_init_empty(&node)`.
 * It can be deinitialized with `alx_node_deinit(node)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * A node stores a pointer to a dynamic buffer, and pointers to the two
 * connecting nodes.
 *
 * If any of the node metadata is manually modified by the user, the node may
 * be corrupted, and the behavior is undefined.  alx_dynbuf_ functions may
 * be called with the buffer pointer for lower level management.
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
 * buf:		Pointer to a dynamic buffer containing useful data.
 * left:	Pointer to the leftious node.
 * right:	Pointer to the right node.
 */
struct	Alx_Node {
	struct Alx_Dyn_Buffer	*buf;
	struct Alx_Node		*left;
	struct Alx_Node		*right;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Allocates memory for the node and for the buffer, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * node:	Pointer to a pointer to a node.  A node will be allocated,
 *		and a pointer to it will be stored in *node.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node or the buffer.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_init		(struct Alx_Node **restrict node,
				 const void *restrict data, size_t size);

/*
 * Allocates memory for the node (not for the buffer), and updates any
 * necessary metadata.
 *
 * node:	Pointer to a pointer to a node.  A node will be allocated,
 *		and a pointer to it will be stored in *node.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_init_empty	(struct Alx_Node **node);

/*
 * Deletes `node`.
 * Deallocates memory from the node and from the data.
 * If node is NULL, no operation is performed.
 *
 * node:	Pointer to a node.  It is invalid after the call.
 */
void	alx_node_deinit		(struct Alx_Node *node);

/*
 * Writes into the buffer.
 * Reallocates memory for the data if necessary, copies the data passed by the
 * user to the reallocated space, and updates any necessary metadata.
 *
 * node:	Pointer to a node.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_node_write		(struct Alx_Node *node,
				 const void *data, size_t size);

/*
 * Reads from the buffer.
 *
 * node:	Pointer to a node.
 * data:	Copy the read data here.  Should be at least `size` bytes.
 * size:	Size of the data to be copied.
 *
 * return:
 *	0:		OK.
 *	ENOBUFS:	OK. data was truncated.
 */
__attribute__((nonnull))
int	alx_node_read		(const struct Alx_Node *node,
				 void *data, size_t size);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
