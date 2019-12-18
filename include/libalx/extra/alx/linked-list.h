/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list.h */


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
	struct Alx_LLNode	*prev;
	struct Alx_LLNode	*next;
};

struct	Alx_LinkedList {
	struct Alx_LLNode	*head;
	struct Alx_LLNode	*tail;
	struct Alx_LLNode	*current;
	ptrdiff_t		nmemb;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull))
int	alx_llist_init		(struct Alx_LinkedList **list);
__attribute__((nonnull))
int	alx_llist_deinit	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_first_element	(struct Alx_LinkedList *list,
				 size_t size, const void *data);
__attribute__((nonnull))
int	alx_llist_remove_last	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 size_t size, const void *data);
__attribute__((nonnull))
int	alx_llist_append	(struct Alx_LinkedList *list,
				 size_t size, const void *data);
__attribute__((nonnull))
int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 size_t size, const void *data);
__attribute__((nonnull))
int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 size_t size, const void *data);
__attribute__((nonnull))
int	alx_llist_remove_head	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_remove_tail	(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_remove_current(struct Alx_LinkedList *list);
__attribute__((nonnull))
int	alx_llist_remove_all	(struct Alx_LinkedList *list);
__attribute__((nonnull, pure))
ptrdiff_t alx_llist_find	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node);
__attribute__((nonnull))
int	alx_llist_move_fwd	(struct Alx_LinkedList *list, ptrdiff_t n);
__attribute__((nonnull))
int	alx_llist_move_bwd	(struct Alx_LinkedList *list, ptrdiff_t n);
__attribute__((nonnull))
int	alx_llist_move_to	(struct Alx_LinkedList *list, ptrdiff_t pos);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
