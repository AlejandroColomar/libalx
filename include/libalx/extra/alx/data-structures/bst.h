/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/data-structures/bst.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Binary search tree
 *
 * An orphan node is a BST itself.  A BST can be created by inserting nodes
 * into a single element BST (a node).
 * To use the BST, it has to be initialized with `alx_llist_init(&list)`.
 * It can be deinitialized with `alx_llist_deinit(list)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * Each node stores a pointer to a dynamic buffer, and pointers to the two
 * connecting nodes.  More info about the nodes can be found in
 *  <libalx/extra/alx/data-structures/node.h>.
 *
 * If any of the list metadata is manually modified by the user, the list may
 * be corrupted, and the behavior is undefined.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/extra/alx/data-structures/llist.h"
#include "libalx/extra/alx/data-structures/node.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
/* Avoid circular dependence */
struct	Alx_Dyn_Array;
struct	Alx_LinkedList;


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Inserts a new node into the BST.
 * Allocates memory for the node and for the data, copies the data passed by
 * the user to the newly allocated space, and updates any necessary metadata.
 *
 * bst:		Pointer to a BST.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The node data compares equal to the bst node.
 *			< 0:	The node data goes to the left of the bst node.
 *			> 0:	The node data goes to the right of the bst node.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_bst_insert			(struct Alx_Node *bst,
					 const void *data, size_t size,
					 int (*cmp)
							(const void *bst_data,
							 const void *node_data));

/*
 * Inserts an already existing node into the BST.
 * Updates any necessary metadata.
 *
 * bst:		Pointer to a BST.
 * node:	Pointer to the node to be prepended.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The node data compares equal to the bst node.
 *			< 0:	The node data goes to the left of the bst node.
 *			> 0:	The node data goes to the right of the bst node.
 */
__attribute__((nonnull))
void	alx_bst_insert_node		(struct Alx_Node *restrict bst,
					 struct Alx_Node *restrict node,
					 int (*cmp)
							(const void *bst_data,
							 const void *node_data));

/*
 * Returns the leftmost node in the BST.
 *
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull, pure, warn_unused_result))
struct Alx_Node	*alx_bst_leftmost_node	(struct Alx_Node *restrict bst);

/*
 * Returns the rightmost node in the BST.
 *
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull, pure, warn_unused_result))
struct Alx_Node	*alx_bst_rightmost_node	(struct Alx_Node *restrict bst);

/*
 * Returns the parentmost node in the BST.
 *
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull, pure, warn_unused_result))
struct Alx_Node	*alx_bst_parentmost_node(struct Alx_Node *restrict bst);

/*
 * Removes the left and right subtrees of a BST node, and joins them into a
 * new isolated BST.  Updates any necessary metadata.
 * Returns a pointer to the new BST.
 *
 * node:	Pointer to a node.
 */
__attribute__((nonnull))
struct Alx_Node	*alx_bst_join_L_R	(struct Alx_Node *restrict node);

/*
 * Removes a node from the BST and updates any necessary metadata.
 *
 * list:	Pointer to a list.
 * data:	Pointer to the first byte of the data to be copied.
 * size:	Size of the data to be copied.
 *
 * return:
 *	NULL:		OK.  BST is empty.
 *	!= NULL:	OK.
 */
__attribute__((nonnull, warn_unused_result))
struct Alx_Node	*alx_bst_remove_node	(struct Alx_Node *restrict node);

/*
 * Moves the BST nodes into an empty linked list.  If the linked list is not
 * empty, all of its previous nodes are deleted.  The BST is destroyed.
 *
 * bst:		Pointer to a BST.
 * list:	Pointer to a list.
 */
__attribute__((nonnull))
void	alx_bst_to_llist		(struct Alx_Node *restrict bst,
					 struct Alx_LinkedList *restrict list);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
