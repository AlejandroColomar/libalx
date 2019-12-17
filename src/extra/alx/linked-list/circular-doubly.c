/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list/circular-doubly.h"

#include <stdlib.h>

#include "libalx/base/stdlib/alloc/mallocs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_cdllist_init		(struct Alx_DLinkedList **list)
{

	if (alx_mallocs(list, 1))
		return	-1;

	(*list)->head		= NULL;
	(*list)->tail		= NULL;
	(*list)->current	= NULL;
	(*list)->nmemb		= 0;

	return	0;
}

int	alx_cdllist_deinit		(struct Alx_DLinkedList *list)
{
	int	status;

	status	= alx_cdllist_remove_all(list);
	free(list);

	return	status;
}

int	alx_cdllist_first_element	(struct Alx_DLinkedList *list,
					 void *data)
{
	struct Alx_DLLNode	*node;

	if (list->nmemb)
		return	-1;

	if (alx_mallocs(&node, 1))
		return	-2;

	node->data	= data;
	node->prev	= node;
	node->next	= node;

	list->head	= node;
	list->tail	= node;
	list->current	= node;
	list->nmemb	= 1;

	return	0;
}

int	alx_cdllist_remove_last		(struct Alx_DLinkedList *list)
{
	struct Alx_DLLNode	*node;

	if (list->nmemb != 1)
		return	-1;

	node	= list->head;

	list->head	= NULL;
	list->tail	= NULL;
	list->current	= NULL;
	free(node);
	list->nmemb	= 0;

	return	0;
}

int	alx_cdllist_prepend		(struct Alx_DLinkedList *list,
					 void *data)
{
	struct Alx_DLLNode	*node;

	if (!list->nmemb) {
		alx_cdllist_first_element(list, data);
		return	1;
	}

	if (alx_mallocs(&node, 1))
		return	-1;

	node->data	= data;
	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->head	= node;
	(list->nmemb)++;

	return	0;
}

int	alx_cdllist_append		(struct Alx_DLinkedList *list,
					 void *data)
{
	struct Alx_DLLNode	*node;

	if (!list->nmemb) {
		alx_cdllist_first_element(list, data);
		return	1;
	}

	if (alx_mallocs(&node, 1))
		return	-1;

	node->data	= data;
	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->tail	= node;
	(list->nmemb)++;

	return	0;
}

int	alx_cdllist_add_before		(struct Alx_DLinkedList *list,
					 void *data)
{
	struct Alx_DLLNode	*node;

	if (!list->nmemb) {
		alx_cdllist_first_element(list, data);
		return	1;
	}

	if (alx_mallocs(&node, 1))
		return	-1;

	node->data	= data;
	node->prev	= list->current->prev;
	node->next	= list->current;

	list->current->prev->next	= node;
	list->current->prev	= node;
	list->current		= node;
	(list->nmemb)++;

	return	0;
}

int	alx_cdllist_add_after		(struct Alx_DLinkedList *list,
					 void *data)
{
	struct Alx_DLLNode	*node;

	if (!list->nmemb) {
		alx_cdllist_first_element(list, data);
		return	1;
	}

	if (alx_mallocs(&node, 1))
		return	-1;

	node->data	= data;
	node->prev	= list->current;
	node->next	= list->current->next;

	list->current->next->prev	= node;
	list->current->next	= node;
	list->current		= node;
	(list->nmemb)++;

	return	0;
}

int	alx_cdllist_remove_head		(struct Alx_DLinkedList *list)
{
	struct Alx_DLLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_cdllist_remove_last(list);
		return	0;
	}

	node	= list->head;
	list->head->prev->next	= node->next;
	list->head->next->prev	= node->prev;
	if (list->current == list->head)
		list->current	= node->next;
	list->head		= node->next;
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_cdllist_remove_tail		(struct Alx_DLinkedList *list)
{
	struct Alx_DLLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_cdllist_remove_last(list);
		return	0;
	}

	node	= list->tail;
	list->tail->prev->next	= node->next;
	list->tail->next->prev	= node->prev;
	if (list->current == list->tail)
		list->current	= node->prev;
	list->tail		= node->prev;
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_cdllist_remove_current	(struct Alx_DLinkedList *list)
{
	struct Alx_DLLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_cdllist_remove_last(list);
		return	0;
	}

	node	= list->current;
	list->current->prev->next	= node->next;
	list->current->next->prev	= node->prev;
	if (list->tail == list->current) {
		list->tail		= node->prev;
		list->current		= node->prev;
	} else if (list->head == list->current) {
		list->head		= node->next;
		list->current		= node->next;
	} else {
		list->current		= node->prev;
	}
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_cdllist_remove_all		(struct Alx_DLinkedList *list)
{
	ptrdiff_t	n;

	n	= list->nmemb;
	if (!n)
		return	1;

	for (ptrdiff_t i = 0; i < n; i++)
		alx_cdllist_remove_tail(list);

	return	0;
}

ptrdiff_t alx_cdllist_find		(struct Alx_DLinkedList *list,
					 struct Alx_DLLNode *node)
{
	struct Alx_DLLNode	*tmp;

	tmp	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (tmp == node)
			return	i;
		tmp	= tmp->next;
	}

	return	-1;
}

int	alx_cdllist_move_fwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n)
{
	int	status;

	if (n < 0)
		return	alx_cdllist_move_bwd(list, -n);

	status	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		list->current	= list->current->next;
		if (list->current == list->head)
			status++;
	}

	return	0;
}

int	alx_cdllist_move_bwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n)
{
	int	status;

	if (n < 0)
		return	alx_cdllist_move_fwd(list, -n);

	status	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		list->current	= list->current->prev;
		if (list->current == list->tail)
			status--;
	}

	return	0;
}

int	alx_cdllist_move_to		(struct Alx_DLinkedList *list,
					 ptrdiff_t pos)
{

	list->current	= list->head;

	if (pos < 0)
		return	alx_cdllist_move_bwd(list, -pos);
	return	alx_cdllist_move_fwd(list, pos);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
