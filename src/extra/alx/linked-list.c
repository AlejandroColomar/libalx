/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/alloc/mallocs.h"
#include "libalx/base/stdlib/alloc/reallocs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull))
static
int	alx_llist_add_first_element	(struct Alx_LinkedList *list,
					 const void *data, size_t size);
__attribute__((nonnull))
static
void	alx_llist_remove_last		(struct Alx_LinkedList *list);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_llist_init		(struct Alx_LinkedList **list)
{

	if (alx_mallocarrays(list, 1))
		return	-ENOMEM;

	(*list)->head		= NULL;
	(*list)->tail		= NULL;
	(*list)->nmemb		= 0;

	return	0;
}

void	alx_llist_deinit	(struct Alx_LinkedList *list)
{

	alx_llist_remove_all(list);
	free(list);
}

int	alx_llist_prepend	(struct Alx_LinkedList *list,
				 const void *data, size_t size)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb)
		return	alx_llist_add_first_element(list, data, size);

	if (alx_mallocarrays(&node, 1))
		return	-ENOMEM;
	if (alx_mallocs(&node->data, size))
		goto err;
	node->size	= size;

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
	return	-ENOMEM;
}

int	alx_llist_append	(struct Alx_LinkedList *list,
				 const void *data, size_t size)
{
	struct Alx_LLNode	*node;

	if (!list->nmemb)
		return	alx_llist_add_first_element(list, data, size);

	if (alx_mallocarrays(&node, 1))
		return	-ENOMEM;
	if (alx_mallocs(&node->data, size))
		goto err;
	node->size	= size;

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
	return	-ENOMEM;
}

int	alx_llist_insert_before	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref)
{
	struct Alx_LLNode	*new;

	if (!list->nmemb)
		return	alx_llist_add_first_element(list, data, size);

	if (ref == list->head)
		return	alx_llist_prepend(list, data, size);

	if (alx_mallocarrays(&new, 1))
		return	-ENOMEM;
	if (alx_mallocs(&new->data, size))
		goto err;
	new->size	= size;

	memcpy(new->data, data, size);
	new->prev	= ref->prev;
	new->next	= ref;

	ref->prev->next	= new;
	ref->prev	= new;
	(list->nmemb)++;

	return	0;
err:
	free(new);
	return	-ENOMEM;
}

int	alx_llist_insert_after	(struct Alx_LinkedList *list,
				 const void *data, size_t size,
				 struct Alx_LLNode *ref)
{
	struct Alx_LLNode	*new;

	if (!list->nmemb)
		return	alx_llist_add_first_element(list, data, size);

	if (ref == list->tail)
		return	alx_llist_append(list, data, size);

	if (alx_mallocarrays(&new, 1))
		return	-ENOMEM;
	if (alx_mallocs(&new->data, size))
		goto err;
	new->size	= size;

	memcpy(new->data, data, size);
	new->prev	= ref;
	new->next	= ref->next;

	ref->next->prev	= new;
	ref->next	= new;
	(list->nmemb)++;

	return	0;
err:
	free(new);
	return	-ENOMEM;
}

int	alx_llist_insert_at	(struct Alx_LinkedList *list,
				 const void *data, size_t size, ptrdiff_t pos)
{
	struct Alx_LLNode	*tmp;

	if (!list->nmemb)
		return	alx_llist_add_first_element(list, data, size);

	alx_llist_get_node_at(list, &tmp, pos);
	return	alx_llist_insert_before(list, data, size, tmp);
}

int	alx_llist_remove_head	(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	switch (list->nmemb) {
	case 0:
		return	ENOENT;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	node	= list->head;
	free(node->data);

	list->head->prev->next	= node->next;
	list->head->next->prev	= node->prev;
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
		return	ENOENT;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	node	= list->tail;
	free(node->data);

	list->tail->prev->next	= node->next;
	list->tail->next->prev	= node->prev;
	list->tail		= node->prev;
	free(node);
	(list->nmemb)--;

	return	0;
}

int	alx_llist_remove_node	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node)
{

	switch (list->nmemb) {
	case 0:
		return	-ENOENT;
	case 1:
		alx_llist_remove_last(list);
		return	0;
	}

	if (node == list->head)
		return	alx_llist_remove_head(list);
	if (node == list->tail)
		return	alx_llist_remove_tail(list);

	free(node->data);

	node->prev->next	= node->next;
	node->next->prev	= node->prev;
	free(node);
	(list->nmemb)--;

	return	0;
}

void	alx_llist_remove_all	(struct Alx_LinkedList *list)
{
	ptrdiff_t	n;

	n	= list->nmemb;
	if (!n)
		return;

	for (ptrdiff_t i = 0; i < n; i++)
		alx_llist_remove_tail(list);
}

ptrdiff_t alx_llist_find	(const struct Alx_LinkedList *list,
				 const struct Alx_LLNode *node)
{
	struct Alx_LLNode	*tmp;

	tmp	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (tmp == node)
			return	i;
		tmp	= tmp->next;
	}

	return	-ENOENT;
}

int	alx_llist_get_node_at	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 ptrdiff_t pos)
{

	return	alx_llist_get_relative(list, node, list->head, pos);
}

int	alx_llist_get_relative	(const struct Alx_LinkedList *list,
				 struct Alx_LLNode **node,
				 const struct Alx_LLNode *ref,
				 ptrdiff_t pos)
{
	int	status;

	status	= 0;
	*node	= (struct Alx_LLNode *)ref;
	if (pos >= 0) {
		for (ptrdiff_t i = 0; i < pos; i++) {
			*node	= (*node)->next;
			if (*node == list->head)
				status++;
		}
	} else {
		for (ptrdiff_t i = 0; i < pos; i++) {
			*node	= (*node)->prev;
			if (*node == list->tail)
				status++;
		}
	}

	return	status;
}

void	alx_llist_move_node_to	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos)
{
	struct Alx_LLNode	*ref;

	if (list->nmemb < 2)
		return;

	node->prev->next	= node->next;
	node->next->prev	= node->prev;
	if (node == list->tail)
		list->tail		= node->prev;
	if (node == list->head)
		list->head		= node->next;

	if (pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1)) {
		ref	= list->head;
	} else {
		if (pos < 0)
			alx_llist_get_node_at(list, &ref, pos + 1);
		else
			alx_llist_get_node_at(list, &ref, pos);
	}

	node->prev	= ref->prev;
	node->next	= ref;

	ref->prev->next	= node;
	ref->prev	= node;
	if (ref == list->head) {
		if (pos == -1  ||  pos > 0)
			list->tail	= node;
		else
			list->head	= node;
	}
}

void	alx_llist_move_relative	(struct Alx_LinkedList *list,
				 struct Alx_LLNode *node, ptrdiff_t pos)
{
	struct Alx_LLNode	*ref;

	if (list->nmemb < 2)
		return;
	if (!pos  ||  pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1))
		return;
	if (pos > 0)
		pos++;

	alx_llist_get_relative(list, &ref, node, pos);

	node->prev->next	= node->next;
	node->next->prev	= node->prev;
	if (node == list->tail)
		list->tail		= node->prev;
	if (node == list->head)
		list->head		= node->next;

	node->prev	= ref->prev;
	node->next	= ref;

	ref->prev->next	= node;
	ref->prev	= node;
	if (ref == list->head) {
		if (pos < 0)
			list->head	= node;
		else
			list->tail	= node;
	}
}

int	alx_llist_edit_node_data(struct Alx_LLNode *node,
				 const void *data, size_t size)
{

	if (alx_reallocs(&node->data, size))
		return	-ENOMEM;
	node->size	= size;

	memmove(node->data, data, size);

	return	0;
}

void	alx_llist_set_head	(struct Alx_LinkedList *list, ptrdiff_t pos)
{
	struct Alx_LLNode	*node;

	if (list->nmemb < 2)
		return;

	alx_llist_get_node_at(list, &node, pos);
	list->head	= node;
	list->tail	= node->prev;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_llist_add_first_element	(struct Alx_LinkedList *list,
					 const void *data, size_t size)
{
	struct Alx_LLNode	*node;

	if (alx_mallocarrays(&node, 1))
		return	-ENOMEM;
	if (alx_mallocs(&node->data, size))
		goto err;

	memcpy(node->data, data, size);
	node->prev	= node;
	node->next	= node;

	list->head	= node;
	list->tail	= node;
	list->nmemb	= 1;

	return	0;
err:
	free(node);
	return	-ENOMEM;
}

static
void	alx_llist_remove_last		(struct Alx_LinkedList *list)
{
	struct Alx_LLNode	*node;

	node	= list->head;
	free(node->data);

	list->head	= NULL;
	list->tail	= NULL;
	free(node);
	list->nmemb	= 0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
