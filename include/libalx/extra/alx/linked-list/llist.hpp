/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list/llist.hpp */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Circular doubly-linked list
 *
 * Read  <libalx/extra/alx/linked-list/llist.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_LL_Node {
	void			*data;
	size_t			size;
	struct Alx_LL_Node	*prev;
	struct Alx_LL_Node	*next;
};

struct	Alx_LinkedList {
	struct Alx_LL_Node	*head;
	struct Alx_LL_Node	*tail;
	ptrdiff_t		nmemb;
}

extern	"C"
{
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_init		(struct Alx_LinkedList **list);
void	alx_llist_deinit	(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_append	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LL_Node *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LL_Node *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_at	(struct Alx_LinkedList *list,
				 const void *data, size_t size, ptrdiff_t pos);
[[gnu::nonnull]]
int	alx_llist_remove_head	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_node	(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node);
[[gnu::nonnull]]
void	alx_llist_remove_all	(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::pure]][[gnu::warn_unused_result]]
ptrdiff_t alx_llist_find	(const struct Alx_LinkedList *list,
				 const struct Alx_LL_Node *node);
[[gnu::nonnull]]
int	alx_llist_get_node_at	(const struct Alx_LinkedList *list,
				 struct Alx_LL_Node **node,
				 ptrdiff_t pos);
[[gnu::nonnull]]
int	alx_llist_get_relative	(const struct Alx_LinkedList *list,
				 struct Alx_LL_Node **node,
				 const struct Alx_LL_Node *ref,
				 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_node_to	(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node, ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_relative	(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node, ptrdiff_t pos);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_edit_node_data(struct Alx_LL_Node *node,
				 const void *data, size_t size);
[[gnu::nonnull]]
void	alx_llist_set_head	(struct Alx_LinkedList *list, ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_set_node_as_head(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node);
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply		(struct Alx_LinkedList *list,
				 int (*f)	(struct Alx_LinkedList *list,
						 struct Alx_LL_Node *node,
						 void *state, ptrdiff_t i),
				 void *state);
[[gnu::nonnull(1, 2)]]
int	alx_llist_apply_bwd	(struct Alx_LinkedList *list,
				 int (*f)	(struct Alx_LinkedList *list,
						 struct Alx_LL_Node *node,
						 void *state, ptrdiff_t i),
				 void *state);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
