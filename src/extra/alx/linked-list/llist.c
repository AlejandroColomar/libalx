/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list/llist.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/compiler/unused.h"
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
/*
 * Allocates memory for the node and for the data, copies the data passed
 * by the user to the newly allocated space, and updates any necessary metadata.
 *
 * return:
 *	0:		OK.
 *	ENOMEM:		Aborted; failure to allocate the node.
 */
__attribute__((nonnull, warn_unused_result))
static
int	new_node		(struct Alx_LL_Node **node,
				 const void *data, size_t size);

/*
 * Inserts the first node into the list.  It should be called if and only if
 * the list is empty (list->nmemb == 0).
 * Inserts an already existing node, and updates any necessary metadata.
 */
__attribute__((nonnull))
static
void	add_first_node		(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node);

/*
 * Removes `node` from `list`, and updates any necessary metadata.
 *
 * NOTE:  If the list has only one node, and this function is called with a
 * pointer to a node which is not the same as the remaining node in the list,
 * no node is removed.  If `node` is not in the list and list->nmemb != 1, the
 * behavior is undefined.
 *
 * return:
 *	0:		OK.
 *	ENOENT:		Aborted; `list` has only one node and is different
 *			from `node`.
 */
__attribute__((nonnull))
static
int	remove_node		(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node);

/*
 * Deletes `node`.
 * Deallocates memory from the node and from the data.
 */
__attribute__((nonnull))
static
void	delete_node		(struct Alx_LL_Node *node);

/*
 * Removes the last node from the list. It should be called only if
 * the list has only one element (list->nmemb == 1).
 * Updates any necessary metadata.
 * A pointer to the orphan node is passed through `node`.
 */
__attribute__((nonnull))
static
void	remove_last_node	(struct Alx_LinkedList *list,
				 struct Alx_LL_Node **node);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_llist_init			(struct Alx_LinkedList **list)
{

	if (alx_mallocarrays(list, 1))
		return	ENOMEM;

	(*list)->head		= NULL;
	(*list)->tail		= NULL;
	(*list)->nmemb		= 0;

	return	0;
}

void	alx_llist_deinit		(struct Alx_LinkedList *list)
{

	if (!list)
		return;

	alx_llist_delete_all(list);
	free(list);
}

int	alx_llist_prepend		(struct Alx_LinkedList *list,
					 const void *data, size_t size)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;
	alx_llist_prepend_node(list, node);

	return	0;
}

void	alx_llist_prepend_node		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->head	= node;
	(list->nmemb)++;
}

int	alx_llist_append		(struct Alx_LinkedList *list,
					 const void *data, size_t size)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;
	alx_llist_append_node(list, node);

	return	0;
}

void	alx_llist_append_node		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	node->prev	= list->tail;
	node->next	= list->head;

	list->head->prev	= node;
	list->tail->next	= node;

	list->tail	= node;
	(list->nmemb)++;
}

int	alx_llist_insert_before		(struct Alx_LinkedList *list,
					 const void *data, size_t size,
					 struct Alx_LL_Node *ref)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;
	alx_llist_insert_node_before(list, node, ref);

	return	0;
}

void	alx_llist_insert_node_before	(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node,
					 struct Alx_LL_Node *ref)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}
	if (ref == list->head) {
		alx_llist_prepend_node(list, node);
		return;
	}

	node->prev	= ref->prev;
	node->next	= ref;

	ref->prev->next	= node;
	ref->prev	= node;
	(list->nmemb)++;
}

int	alx_llist_insert_after		(struct Alx_LinkedList *list,
					 const void *data, size_t size,
					 struct Alx_LL_Node *ref)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;
	alx_llist_insert_node_after(list, node, ref);

	return	0;
}

void	alx_llist_insert_node_after	(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node,
					 struct Alx_LL_Node *ref)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}
	if (ref == list->tail) {
		alx_llist_append_node(list, node);
		return;
	}

	node->prev	= ref;
	node->next	= ref->next;

	ref->next->prev	= node;
	ref->next	= node;
	(list->nmemb)++;
}

int	alx_llist_insert_at		(struct Alx_LinkedList *list,
					 const void *data, size_t size,
					 ptrdiff_t pos)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;
	alx_llist_insert_node_at(list, node, pos);

	return	0;
}

void	alx_llist_insert_node_at	(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_LL_Node	*ref;

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	/* list->nmemb != 0, so it will return 0 */
	UNUSED(alx_llist_get_node_at(list, &ref, pos));
	if (pos >= 0)
		alx_llist_insert_node_before(list, node, ref);
	else
		alx_llist_insert_node_after(list, node, ref);
}

int	alx_llist_remove_head		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node **node)
{

	if (!list->nmemb) {
		*node	= NULL;
		return	ENOENT;
	}

	(*node)	= list->head;
	remove_node(list, list->head);

	return	0;
}

int	alx_llist_delete_head		(struct Alx_LinkedList *list)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= alx_llist_remove_head(list, &node);
	if (status)
		return	status;
	delete_node(node);

	return	0;
}

int	alx_llist_remove_tail		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node **node)
{

	if (!list->nmemb) {
		*node	= NULL;
		return	ENOENT;
	}

	(*node)	= list->tail;
	remove_node(list, list->tail);

	return	0;
}

int	alx_llist_delete_tail		(struct Alx_LinkedList *list)
{
	struct Alx_LL_Node	*node;
	int			status;

	status	= alx_llist_remove_tail(list, &node);
	if (status)
		return	status;
	delete_node(node);

	return	0;
}

int	alx_llist_remove_node		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node)
{

	if (!list->nmemb)
		return	ENOENT;

	return	remove_node(list, node);
}

int	alx_llist_delete_node		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node)
{
	int	status;

	if (list) {
		status	= alx_llist_remove_node(list, node);
		if (status)
			return	status;
	}

	delete_node(node);

	return	0;
}

void	alx_llist_delete_all		(struct Alx_LinkedList *list)
{
	ptrdiff_t	n;

	n	= list->nmemb;
	if (!n)
		return;

	for (ptrdiff_t i = 0; i < n; i++)
		alx_llist_delete_tail(list);
}

ptrdiff_t alx_llist_find		(const struct Alx_LinkedList *list,
					 const struct Alx_LL_Node *node)
{
	struct Alx_LL_Node	*tmp;

	tmp	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (tmp == node)
			return	i;
		tmp	= tmp->next;
	}

	return	-ENOENT;
}

int	alx_llist_get_node_at		(const struct Alx_LinkedList *list,
					 struct Alx_LL_Node **node,
					 ptrdiff_t pos)
{
	return	alx_llist_get_relative(list, node, list->head, pos);
}

int	alx_llist_get_relative		(const struct Alx_LinkedList *list,
					 struct Alx_LL_Node **node,
					 const struct Alx_LL_Node *ref,
					 ptrdiff_t pos)
{

	if (!list->nmemb)
		return	ENOENT;

	*node	= (struct Alx_LL_Node *)ref;
	pos	%= list->nmemb;
	if (pos >= 0) {
		for (ptrdiff_t i = 0; i < pos; i++)
			*node	= (*node)->next;
	} else {
		for (ptrdiff_t i = 0; i < pos; i++)
			*node	= (*node)->prev;
	}

	return	0;
}

void	alx_llist_move_node_to		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_LL_Node	*ref;

	if (list->nmemb < 2)
		return;

	remove_node(list, node);

	if (pos <= (-list->nmemb + 1)) {
		alx_llist_append_node(list, node);
	} else if (pos >= (list->nmemb - 1)) {
		alx_llist_prepend_node(list, node);
	} else {
		/* list->nmemb != 0, so it will return 0 */
		UNUSED(alx_llist_get_node_at(list, &ref, pos));
		if (pos >= 0)
			alx_llist_insert_node_before(list, node, ref);
		else
			alx_llist_insert_node_after(list, node, ref);
	}
}

void	alx_llist_move_relative		(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_LL_Node	*ref;

	if (list->nmemb < 2)
		return;
	if (!pos  ||  pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1))
		return;

	/* list->nmemb != 0, so it will return 0 */
	UNUSED(alx_llist_get_relative(list, &ref, node, pos));
	remove_node(list, node);

	if (pos > 0)
		alx_llist_insert_node_after(list, node, ref);
	else
		alx_llist_insert_node_before(list, node, ref);
}

int	alx_llist_edit_node_data	(struct Alx_LL_Node *node,
					 const void *data, size_t size)
{

	if (alx_reallocs(&node->data, size))
		return	ENOMEM;
	node->size	= size;

	memmove(node->data, data, size);

	return	0;
}

void	alx_llist_set_head		(struct Alx_LinkedList *list,
					 ptrdiff_t pos)
{
	struct Alx_LL_Node	*node;

	if (list->nmemb < 2)
		return;

	/* list->nmemb != 0, so it will return 0 */
	UNUSED(alx_llist_get_node_at(list, &node, pos));
	list->head	= node;
	list->tail	= node->prev;
}

void	alx_llist_set_node_as_head	(struct Alx_LinkedList *list,
					 struct Alx_LL_Node *node)
{

	if (list->nmemb < 2)
		return;

	list->head	= node;
	list->tail	= node->prev;
}

int	alx_llist_apply			(struct Alx_LinkedList *list,
					 int (*f)(struct Alx_LinkedList *list,
						 struct Alx_LL_Node *node,
						 void *state, ptrdiff_t i),
					 void *state)
{
	struct Alx_LL_Node	*current;
	struct Alx_LL_Node	*next;
	int			status;

	current	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		next	= current->next;
		status	= f(list, current, state, i);
		if (status)
			return	status;
		current	= next;
	}

	return	0;
}

int	alx_llist_apply_bwd		(struct Alx_LinkedList *list,
					 int (*f)(struct Alx_LinkedList *list,
						 struct Alx_LL_Node *node,
						 void *state, ptrdiff_t i),
					 void *state)
{
	struct Alx_LL_Node	*current;
	struct Alx_LL_Node	*next;
	int			status;

	current	= list->tail;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		next	= current->prev;
		status	= f(list, current, state, i);
		if (status)
			return	status;
		current	= next;
	}

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	new_node		(struct Alx_LL_Node **node,
				 const void *data, size_t size)
{

	if (alx_mallocarrays(node, 1))
		return	ENOMEM;
	if (alx_mallocs((*node)->data, size))
		goto err;
	(*node)->size	= size;
	memcpy((*node)->data, data, size);

	return	0;
err:
	free(*node);
	return	ENOMEM;
}

static
void	add_first_node		(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node)
{

	node->prev	= node;
	node->next	= node;

	list->head	= node;
	list->tail	= node;
	list->nmemb	= 1;
}

static
int	remove_node		(struct Alx_LinkedList *list,
				 struct Alx_LL_Node *node)
{
	struct Alx_LL_Node	*foo;

	if (list->nmemb == 1) {
		remove_last_node(list, &foo);
		if (foo != node)
			goto err;
		return	0;
	}

	node->prev->next	= node->next;
	node->next->prev	= node->prev;
	(list->nmemb)--;

	if (node == list->head)
		list->head	= node->next;
	if (node == list->tail)
		list->tail	= node->prev;

	node->prev	= NULL;
	node->next	= NULL;

	return	0;
err:
	add_first_node(list, foo);
	return	ENOENT;
}

static
void	delete_node		(struct Alx_LL_Node *node)
{

	free(node->data);
	free(node);

}

static
void	remove_last_node	(struct Alx_LinkedList *list,
				 struct Alx_LL_Node **node)
{

	*node	= list->head;

	list->head	= NULL;
	list->tail	= NULL;
	list->nmemb	= 0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
