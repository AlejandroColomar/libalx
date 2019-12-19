/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list.hpp */


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
}

extern	"C"
{
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_init		(struct Alx_LinkedList **list);
[[gnu::nonnull]]
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
				 struct Alx_LLNode *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_insert_at	(struct Alx_LinkedList *list,
				 const void *data, size_t size, ptrdiff_t pos);
[[gnu::nonnull]]
int	alx_llist_remove_head	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_node	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node);
[[gnu::nonnull]]
void	alx_llist_remove_all	(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::pure]][[gnu::warn_unused_result]]
ptrdiff_t alx_llist_find	(const struct Alx_LinkedList *list,
				 const struct Alx_LLNode *node);
[[gnu::nonnull]]
int	alx_llist_get_node_at	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 ptrdiff_t pos);
[[gnu::nonnull]]
int	alx_llist_get_relative	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 const struct Alx_LLNode *ref,
				 ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_node_to	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);
[[gnu::nonnull]]
void	alx_llist_move_relative	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_llist_edit_node_data(struct Alx_LLNode *node,
				 const void *data, size_t size);
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
