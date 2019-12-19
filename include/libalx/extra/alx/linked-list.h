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
 * To use the list, it has to be initialized with `alx_llist_init(&list)`
 * It can be deinitialized with `alx_llist_deinit(list)`
 *
 * Data is copied into a `malloc`ed memory, and `free`d or `realloc`ed
 * automatically by the functions.
 *
 * Each node stores its data, the size of the data, as well as a pointer to
 * the two connecting nodes.
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
__attribute__((nonnull, warn_unused_result))
int	alx_llist_init		(struct Alx_LinkedList **list);
__attribute__((nonnull))
void	alx_llist_deinit	(struct Alx_LinkedList *list);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_append	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_insert_at	(struct Alx_LinkedList *list,
				 const void *data, size_t size, ptrdiff_t pos);
__attribute__((nonnull))
int	alx_llist_remove_head	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_remove_node	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node);
__attribute__((nonnull))
void	alx_llist_remove_all	(struct Alx_LinkedList *list);
__attribute__((nonnull, pure, warn_unused_result))
ptrdiff_t alx_llist_find	(const struct Alx_LinkedList *list,
				 const struct Alx_LLNode *node);
__attribute__((nonnull))
int	alx_llist_get_node_at	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 ptrdiff_t pos);
__attribute__((nonnull))
int	alx_llist_get_relative	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 const struct Alx_LLNode *ref,
				 ptrdiff_t pos);
__attribute__((nonnull))
void	alx_llist_move_node_to	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);
__attribute__((nonnull))
void	alx_llist_move_relative	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);
__attribute__((nonnull, warn_unused_result))
int	alx_llist_edit_node_data(struct Alx_LLNode *node,
				 const void *data, size_t size);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
