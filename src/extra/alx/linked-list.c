/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list.h"

#include <stdlib.h>
#include <string.h>

#include "libalx/base/stdlib/alloc/mallocarrays.h"
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
int	alx_llist_init		(struct Alx_LinkedList **list)
{

	if (alx_mallocs(list, 1))
		return	-1;

	(*list)->head		= NULL;
	(*list)->tail		= NULL;
	(*list)->current	= NULL;
	(*list)->nmemb		= 0;

	return	0;
}

int	alx_llist_deinit	(struct Alx_LinkedList *list)
{
	int	status;

	status	= alx_llist_remove_all(list);
	free(list);

	return	status;
}

int	alx_llist_first_element	(struct Alx_LinkedList *list,
				 size_t size, const void *data)
{
	struct Alx_LLNode	*node;

	if (list->nmemb)
		return	-3;

	if (alx_mallocarrays(&node, 1))
		return	-1;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= node;
	node->next	= node;

	list->head	= node;
	list->tail	= node;
	list->current	= node;
	list->nmemb	= 1;

	return	0;
err:
	free(node);
	return	-2;
}

int	alx_llist_remove_last	(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	if (list->nmemb != 1)
		return	-1;

	node	= list->head;
	free(node->data);

	list->head	= NULL;
	list->tail	= NULL;
	list->current	= NULL;
	free(node);
	list->nmemb	= 0;

	return	0;
}

int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 size_t size, const void *data)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb) {
		alx_llist_first_element(list, size, data);
		return	1;
	}

	if (alx_mallocarrays(&node, 1))
		return	-1;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->head	= node;
	(list->nmemb)++;

	return	0;
err:
	free(node);
	return	-2;
}

int	alx_llist_append	(struct Alx_LinkedList *list,
				 size_t size, const void *data)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb) {
		alx_llist_first_element(list, size, data);
		return	1;
	}

	if (alx_mallocarrays(&node, 1))
		return	-1;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->tail	= node;
	(list->nmemb)++;

	return	0;
err:
	free(node);
	return	-2;
}

int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 size_t size, const void *data)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb) {
		alx_llist_first_element(list, size, data);
		return	1;
	}

	if (alx_mallocarrays(&node, 1))
		return	-1;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= list->current->prev;
	node->next	= list->current;

	list->current->prev->next	= node;
	list->current->prev	= node;
	list->current		= node;
	(list->nmemb)++;

	return	0;
err:
	free(node);
	return	-2;
}

int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 size_t size, const void *data)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb) {
		alx_llist_first_element(list, size, data);
		return	1;
	}

	if (alx_mallocarrays(&node, 1))
		return	-1;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= list->current;
	node->next	= list->current->next;

	list->current->next->prev	= node;
	list->current->next	= node;
	list->current		= node;
	(list->nmemb)++;

	return	0;
err:
	free(node);
	return	-2;
}

int	alx_llist_remove_head	(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	node	= list->head;
	free(node->data);

	list->head->prev->next	= node->next;
	list->head->next->prev	= node->prev;
	if (list->current == list->head)
		list->current	= node->next;
	list->head		= node->next;
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_llist_remove_tail	(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	node	= list->tail;
	free(node->data);

	list->tail->prev->next	= node->next;
	list->tail->next->prev	= node->prev;
	if (list->current == list->tail)
		list->current	= node->prev;
	list->tail		= node->prev;
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_llist_remove_current(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	1;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	node	= list->current;
	free(node->data);

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

int	alx_llist_remove_all	(struct Alx_LinkedList *list)
{
	ptrdiff_t	n;

	n	= list->nmemb;
	if (!n)
		return	1;

	for (ptrdiff_t i = 0; i < n; i++)
		alx_llist_remove_tail(list);

	return	0;
}

ptrdiff_t alx_llist_find	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node)
{
	struct Alx_LLNode	*tmp;

	tmp	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (tmp == node)
			return	i;
		tmp	= tmp->next;
	}

	return	-1;
}

int	alx_llist_move_fwd	(struct Alx_LinkedList *list, ptrdiff_t n)
{
	int	status;

	if (n < 0)
		return	alx_llist_move_bwd(list, -n);

	status	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		list->current	= list->current->next;
		if (list->current == list->head)
			status++;
	}

	return	0;
}

int	alx_llist_move_bwd	(struct Alx_LinkedList *list, ptrdiff_t n)
{
	int	status;

	if (n < 0)
		return	alx_llist_move_fwd(list, -n);

	status	= 0;
	for (ptrdiff_t i = 0; i < n; i++) {
		list->current	= list->current->prev;
		if (list->current == list->tail)
			status--;
	}

	return	0;
}

int	alx_llist_move_to	(struct Alx_LinkedList *list, ptrdiff_t pos)
{

	list->current	= list->head;

	if (pos < 0)
		return	alx_llist_move_bwd(list, -pos);
	return	alx_llist_move_fwd(list, pos);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
