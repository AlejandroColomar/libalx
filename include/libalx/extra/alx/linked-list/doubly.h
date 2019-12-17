/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list/doubly.h */


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
struct	Alx_DLLNode {
	void			*data;
	struct Alx_DLLNode	*prev;
	struct Alx_DLLNode	*next;
};

struct	Alx_DLinkedList {
	struct Alx_DLLNode	*head;
	struct Alx_DLLNode	*tail;
	struct Alx_DLLNode	*current;
	ptrdiff_t		nmemb;
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull))
int	alx_dllist_init			(struct Alx_DLinkedList **list);
__attribute__((nonnull))
int	alx_dllist_deinit		(struct Alx_DLinkedList *list);
__attribute__((nonnull))
int	alx_dllist_first_element	(struct Alx_DLinkedList *list,
					 void *data);
__attribute__((nonnull))
int	alx_dllist_remove_last		(struct Alx_DLinkedList *list);
__attribute__((nonnull))
int	alx_dllist_prepend		(struct Alx_DLinkedList *list,
					 void *data);
__attribute__((nonnull))
int	alx_dllist_append		(struct Alx_DLinkedList *list,
					 void *data);
__attribute__((nonnull))
int	alx_dllist_add_before		(struct Alx_DLinkedList *list,
					 void *data);
__attribute__((nonnull))
int	alx_dllist_add_after		(struct Alx_DLinkedList *list,
					 void *data);
__attribute__((nonnull))
int	alx_dllist_remove_head		(struct Alx_DLinkedList *list);
__attribute__((nonnull))
int	alx_dllist_remove_tail		(struct Alx_DLinkedList *list);
__attribute__((nonnull))
int	alx_dllist_remove_current	(struct Alx_DLinkedList *list);
__attribute__((nonnull))
int	alx_dllist_remove_all		(struct Alx_DLinkedList *list);
__attribute__((nonnull, pure))
ptrdiff_t alx_dllist_find		(struct Alx_DLinkedList *list,
					 struct Alx_DLLNode *node);
__attribute__((nonnull))
int	alx_dllist_move_fwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n);
__attribute__((nonnull))
int	alx_dllist_move_bwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n);
__attribute__((nonnull))
int	alx_dllist_move_to		(struct Alx_DLinkedList *list,
					 ptrdiff_t pos);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
