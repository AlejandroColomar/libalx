/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Circular doubly-linked list
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
struct	Alx_LLNode {
	void			*data;
	size_t			size;
	struct Alx_LLNode	*prev;
	struct Alx_LLNode	*next;
};

struct	Alx_LinkedList {
	struct Alx_LLNode	*head;
	struct Alx_LLNode	*tail;
	ptrdiff_t		nmemb;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/*
 * Initialize list
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the list.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_init		(struct Alx_LinkedList **list);

/*
 * Deinitialize list
 */
__attribute__((nonnull))
void	alx_llist_deinit	(struct Alx_LinkedList *list);

/*
 * Inserts a node at the begining of the list.
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 const void *data, size_t size);

/*
 * Inserts a node at the end of the list.
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_append	(struct Alx_LinkedList *list,
				 const void *data, size_t size);

/*
 * Inserts a node just before the `ref` node.
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref);

/*
 * Inserts a node just after the `ref` node.
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref);

/*
 * Inserts a node at the desired position in the list.
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * `pos` can be too large or negative, which results in natural wrapping
 * around the list (a value of -1 would be the tail, and so on).
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_at	(struct Alx_LinkedList *list,
				 const void *data, size_t size, ptrdiff_t pos);

/*
 * Removes the first node from the list.
 * Deallocates memory from the node and from the data, and updates any
 * necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
__attribute__((nonnull))
int	alx_llist_remove_head	(struct Alx_LinkedList *list);

/*
 * Removes the last node from the list.
 * Deallocates memory from the node and from the data, and updates any
 * necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; the list is already empty.
 */
__attribute__((nonnull))
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);

/*
 * Removes the `node` from the list.
 * Deallocates memory from the node and from the data, and updates any
 * necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOENT:	Aborted; the list is already empty.
 */
__attribute__((nonnull))
int	alx_llist_remove_node	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node);

/*
 * Removes all nodes from the list.
 * Deallocates memory from the nodes and from the data, and updates any
 * necessary metadata.
 */
__attribute__((nonnull))
void	alx_llist_remove_all	(struct Alx_LinkedList *list);

/*
 * Finds the `node` in the list.
 *
 * return:
 *	>= 0:		Found at that position relative to the head.
 *	-ENOENT:	Not found.
 */
__attribute__((nonnull, pure, warn_unused_result))
ptrdiff_t alx_llist_find	(const struct Alx_LinkedList *list,
				 const struct Alx_LLNode *node);

/*
 * Gets a pointer to the `node` in the position `pos` relative to the head.
 *
 * return:
 *	0:		OK.
 *	> 0:		OK; wrapped around the end of the list those many times.
 */
__attribute__((nonnull))
int	alx_llist_get_node_at	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 ptrdiff_t pos);

/*
 * Gets a pointer to the `node` in the position `pos` relative to `ref`.
 *
 * return:
 *	0:		OK.
 *	> 0:		OK; wrapped around the end of the list those many times.
 */
__attribute__((nonnull))
int	alx_llist_get_relative	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 const struct Alx_LLNode *ref,
				 ptrdiff_t pos);

/*
 * Moves the `node` in the list to the position `pos` in the list.
 * If `pos` is negative, it wraps around (-1 is the tail, and so on).
 * If the position is too large
 * (pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1)), it doesn't
 * wrap around.  In that case, if `pos` is negative, the node is moved to the
 * head, and if `pos` is positive, the node is moved to the tail.
 */
__attribute__((nonnull))
void	alx_llist_move_node_to	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);

/*
 * Moves the `node` in the list to the position `pos` relative to the `node`'s
 * position at the moment of the call.
 * If `pos` is negative, it wraps around (-1 is the previous, and so on).  If
 * `pos` is negative and sufficiently large, it wraps around to the tail.
 * If the position is too large
 * (pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1)), it doesn't
 * wrap around any more.  In those cases, the node isn't moved at all.
 */
__attribute__((nonnull))
void	alx_llist_move_relative	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);

/*
 * Edits the node data.
 * Reallocates memory for the the data, copies the data passed by the user to
 * the reallocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	-ENOMEM:	Aborted; failure to reallocate the data.  Previous
 *			data is left untouched.
 */
__attribute__((nonnull, warn_unused_result))
int	alx_llist_edit_node_data(struct Alx_LLNode *node,
				 const void *data, size_t size);

/*
 * Sets the `node` in the position `pos` as the new head, and updates any
 * necessary metadata.
 */
__attribute__((nonnull))
void	alx_llist_set_head	(struct Alx_LinkedList *list, ptrdiff_t pos);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
