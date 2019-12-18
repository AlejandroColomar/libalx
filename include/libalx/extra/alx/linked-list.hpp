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
	struct Alx_LLNode	*prev;
	struct Alx_LLNode	*next;
};

struct	Alx_LinkedList {
	struct Alx_LLNode	*head;
	struct Alx_LLNode	*tail;
	struct Alx_LLNode	*current;
	ptrdiff_t		nmemb;
}

extern	"C"
{
[[gnu::nonnull]]
int	alx_llist_init		(struct Alx_LinkedList **list);
[[gnu::nonnull]]
int	alx_llist_deinit	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_first_element	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_llist_remove_last	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_llist_append	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size);
[[gnu::nonnull]]
int	alx_llist_remove_head	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_current(struct Alx_LinkedList *list);
[[gnu::nonnull]]
int	alx_llist_remove_all	(struct Alx_LinkedList *list);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_llist_find	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node);
[[gnu::nonnull]]
int	alx_llist_move_fwd	(struct Alx_LinkedList *list, ptrdiff_t n);
[[gnu::nonnull]]
int	alx_llist_move_bwd	(struct Alx_LinkedList *list, ptrdiff_t n);
[[gnu::nonnull]]
int	alx_llist_move_to	(struct Alx_LinkedList *list, ptrdiff_t pos);
[[gnu::nonnull]]
int	alx_llist_edit_current	(struct Alx_LinkedList *list,
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
