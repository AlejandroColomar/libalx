/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/bst.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Binary search tree
 *
 * An orphan node is a BST itself.  A BST can be created by inserting nodes
 * into a single element BST (a node) with
 * `alx_bst_insert_node(bst, node, cmp)` or
 * `alx_bst_insert(bst, data, size, cmp)`.
 *
 * Data is copied into `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * Each node stores a pointer to a dynamic buffer, and pointers to its two
 * subtrees and its parent.  More info about the nodes can be found in
 *  <libalx/alx/data-structures/node.h>.
 *
 * If any of the nodes' metadata is manually modified by the user, the list may
 * be corrupted, and the behavior is undefined.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "libalx/alx/data-structures/llist.h"
#include "libalx/alx/data-structures/node.h"
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
 * Initializes bst.
 * The alx_bst_init() function allocates a binary search tree and assigns a
 * pointer to it to `*bst`.  On error, the function assigns NULL, which can
 * later be successfully passed to alx_bst_deinit().
 *
 * bst:		Pointer to a pointer to a binary search tree.  A BST will be
 *		allocated, and a pointer to it will be stored in *bst.
 * cmp:		Comparison function pointer.
 * dup:		Does the BST accept duplicate members?
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the bst.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_bst_init		(struct Alx_BST **restrict bst,
				 cmp_f *cmp, bool dup);

/*
 * Deinitializes bst.
 * The alx_bst_deinit() function frees all the memory space used by the BST
 * and all of its remaining nodes.  The BST must have been initialized by a
 * previous call to alx_bst_init().  Otherwise, or if alx_bst_deinit(bst)
 * has already been called before, undefined behavior occurs.
 * If bst is NULL, no operation is performed.
 *
 * bst:		Pointer to a bst.  It is invalid after the call.
 */
void	alx_bst_deinit		(struct Alx_BST *bst);

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
 *	EEXIST:		Aborted; existing equivalent node in the BST.
 */
__attribute__((nonnull(1), warn_unused_result))
int	alx_bst_insert		(struct Alx_BST *restrict bst,
				 int64_t key,
				 const void *restrict data, size_t size);

/*
 * Inserts an already existing node into the BST.
 * Updates any necessary metadata.  If the node compares equal to a node in
 * the BST, if (bst->dup), the node is not inserted; else, the node is
 * inserted to the right.
 *
 * bst:		Pointer to a BST.
 * node:	Pointer to the node to be prepended.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The node data compares equal to the bst node.
 *			< 0:	The node data goes to the left of the bst node.
 *			> 0:	The node data goes to the right of the bst node.
 *
 * return:
 *	0:		OK.
 *	EEXIST:		Aborted; existing equivalent node in the BST.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_bst_insert_node	(struct Alx_BST *restrict bst,
				 struct Alx_Node *restrict node);

/*
 * Deletes all the nodes in the BST.
 * If bst is NULL, no operation is performed.
 *
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull))
void	alx_bst_delete_all	(struct Alx_BST *bst);

/*
 * Gets the leftmost node in the BST.
 * Returns non-zero if the BST is empty.
 *
 * node:	Pointer to a pointer to a node.  The pointer to the leftmost
 *		node will be stored here.
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_bst_leftmost_node	(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst);

/*
 * Gets the rightmost node in the BST.
 * Returns non-zero if the BST is empty.
 *
 * node:	Pointer to a pointer to a node.  The pointer to the rightmost
 *		node will be stored here.
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_bst_rightmost_node	(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst);

/*
 * Finds a node in the BST.  Returns ENOENT if not found.
 * If more than one node would compare equal to the data, the leftmost one is
 * found.
 *
 * node:	Pointer to a pointer to a node.  The pointer to the found node
 *		will be stored here.
 * bst:		Pointer to a BST.
 * data:	Data to search for.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The data compares equal to the bst node.
 *			< 0:	The data goes to the left of the bst node.
 *			> 0:	The data goes to the right of the bst node.
 */
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_bst_find		(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst,
				 int64_t key, const void *restrict data);

/*
 * Removes a node (found by its data) from the BST and updates any necessary
 * metadata.  If more than one node would compare equal to the data, only the
 * leftmost one is removed.
 *
 * node:	Pointer to a pointer to a node.  The pointer to the removed
 *		node will be stored here.
 * bst:		Pointer to a BST.
 * data:	Data to search for.
 * cmp:		Comparison function pointer.  This function should return
 *			0:	The data compares equal to the bst node.
 *			< 0:	The data goes to the left of the bst node.
 *			> 0:	The data goes to the right of the bst node.
 */
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_bst_remove		(struct Alx_Node **restrict node,
				 struct Alx_BST *restrict bst,
				 int64_t key, const void *restrict data);

/*
 * Removes a node from the BST and updates any necessary metadata.
 *
 * bst:		Pointer to a BST.
 * node:	Pointer to the node to be removed from the BST.
 */
__attribute__((nonnull(1)))
void	alx_bst_remove_node	(struct Alx_BST *restrict bst,
				 struct Alx_Node *restrict node);

/*
 * Apply function `*f` to each node in the list (in order, starting at the
 * leftmost and ending at the rightmost).
 * If bst is NULL, no operation is performed.
 *
 * bst:		Pointer to a BST.
 * f:		Pointer to the function to be applied.
 * state:	External data to be used within `*f`.
 *
 * return:
 *	0:		OK.
 *	else:		If `*f` fails (returns != 0), the function returns
 *			immediately and the return value is passed to the
 *			caller.
 */
__attribute__((nonnull(1, 2)))
int	alx_bst_apply		(struct Alx_BST *restrict bst,
				 int (*f)(struct Alx_Node *restrict node,
					  void *restrict state),
				 void *restrict state);

/*
 * Apply function `*f` to each node in the list (in reverse order, starting
 * at the rightmost and ending at the leftmost).
 * If bst is NULL, no operation is performed.
 *
 * bst:		Pointer to a BST.
 * f:		Pointer to the function to be applied.
 * state:	External data to be used within `*f`.
 *
 * return:
 *	0:		OK.
 *	else:		If `*f` fails (returns != 0), the function returns
 *			immediately and the return value is passed to the
 *			caller.
 */
__attribute__((nonnull(1, 2)))
int	alx_bst_apply_bwd	(struct Alx_BST *restrict bst,
				 int (*f)(struct Alx_Node *restrict node,
					  void *restrict state),
				 void *restrict state);

/*
 * Reorder the BST with a new comparison function.
 *
 * bst:		Pointer to a BST.
 * cmp:		Comparison function pointer.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; internal failure.
 */
__attribute__((nonnull))
int	alx_bst_reorder		(struct Alx_BST *restrict bst, cmp_f *cmp);

/*
 * Moves the BST nodes into an empty linked list.  The BST is empty afterwards.
 *
 * list:	Pointer to a list.
 * bst:		Pointer to a BST.
 */
__attribute__((nonnull))
void	alx_bst_to_llist	(struct Alx_LinkedList *restrict list,
				 struct Alx_BST *restrict bst);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
