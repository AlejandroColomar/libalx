/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/llist.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "libalx/base/compiler/unused.h"
#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/alx/data-structures/bst.h"
#include "libalx/alx/data-structures/dyn-array.h"
#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/alx/data-structures/node.h"


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
 * Inserts the first node into the list.  It should be called if and only if
 * the list is empty (list->nmemb == 0).
 * Inserts an already existing node, and updates any necessary metadata.
 */
__attribute__((nonnull))
static
void	add_first_node		(struct Alx_LinkedList *list,
				 struct Alx_Node *node);

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
				 struct Alx_Node *node);

/*
 * Removes the last node from the list. It should be called if and only if
 * the list has only one element (list->nmemb == 1).
 * Updates any necessary metadata.
 * A pointer to the orphan node is passed through `node`.
 */
__attribute__((nonnull))
static
void	remove_last_node	(struct Alx_LinkedList *list,
				 struct Alx_Node **node);


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
					 int64_t key,
					 const void *data, size_t size)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, key, data, size))
		return	ENOMEM;
	alx_llist_prepend_node(list, node);

	return	0;
}

void	alx_llist_prepend_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	node->left	= list->tail;
	node->right	= list->head;
	node->parent	= NULL;

	list->head->left	= node;
	list->tail->right	= node;

	list->head	= node;
	(list->nmemb)++;
}

int	alx_llist_append		(struct Alx_LinkedList *list,
					 int64_t key,
					 const void *data, size_t size)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, key, data, size))
		return	ENOMEM;
	alx_llist_append_node(list, node);

	return	0;
}

void	alx_llist_append_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	node->left	= list->tail;
	node->right	= list->head;
	node->parent	= NULL;

	list->head->left	= node;
	list->tail->right	= node;

	list->tail	= node;
	(list->nmemb)++;
}

int	alx_llist_insert_before		(struct Alx_LinkedList *list,
					 int64_t key,
					 const void *data, size_t size,
					 struct Alx_Node *ref)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, key, data, size))
		return	ENOMEM;
	alx_llist_insert_node_before(list, node, ref);

	return	0;
}

void	alx_llist_insert_node_before	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}
	if (ref == list->head) {
		alx_llist_prepend_node(list, node);
		return;
	}

	node->left	= ref->left;
	node->right	= ref;
	node->parent	= NULL;

	ref->left->right	= node;
	ref->left		= node;
	(list->nmemb)++;
}

int	alx_llist_insert_after		(struct Alx_LinkedList *list,
					 int64_t key,
					 const void *data, size_t size,
					 struct Alx_Node *ref)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, key, data, size))
		return	ENOMEM;
	alx_llist_insert_node_after(list, node, ref);

	return	0;
}

void	alx_llist_insert_node_after	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 struct Alx_Node *ref)
{

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}
	if (ref == list->tail) {
		alx_llist_append_node(list, node);
		return;
	}

	node->left	= ref;
	node->right	= ref->right;
	node->parent	= NULL;

	ref->right->left	= node;
	ref->right		= node;
	(list->nmemb)++;
}

int	alx_llist_insert_at		(struct Alx_LinkedList *list,
					 int64_t key,
					 const void *data, size_t size,
					 ptrdiff_t pos)
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, key, data, size))
		return	ENOMEM;
	alx_llist_insert_node_at(list, node, pos);

	return	0;
}

void	alx_llist_insert_node_at	(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_Node	*ref;

	if (!list->nmemb) {
		add_first_node(list, node);
		return;
	}

	/* list->nmemb != 0, so it will return 0 */
	ALX_UNUSED(alx_llist_get_node_at(list, &ref, pos));
	if (pos >= 0)
		alx_llist_insert_node_before(list, node, ref);
	else
		alx_llist_insert_node_after(list, node, ref);
}

int	alx_llist_remove_head		(struct Alx_LinkedList *list,
					 struct Alx_Node **node)
{

	if (!list->nmemb) {
		*node	= NULL;
		return	ENOENT;
	}

	*node	= list->head;
	remove_node(list, list->head);

	return	0;
}

int	alx_llist_delete_head		(struct Alx_LinkedList *list)
{
	struct Alx_Node	*node;

	if (alx_llist_remove_head(list, &node))
		return	ENOENT;
	alx_node_deinit(node);

	return	0;
}

int	alx_llist_remove_tail		(struct Alx_LinkedList *list,
					 struct Alx_Node **node)
{

	if (!list->nmemb) {
		*node	= NULL;
		return	ENOENT;
	}

	*node	= list->tail;
	remove_node(list, list->tail);

	return	0;
}

int	alx_llist_delete_tail		(struct Alx_LinkedList *list)
{
	struct Alx_Node	*node;

	if (alx_llist_remove_tail(list, &node))
		return	ENOENT;
	alx_node_deinit(node);

	return	0;
}

int	alx_llist_remove_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node)
{

	if (!list->nmemb)
		return	ENOENT;

	return	remove_node(list, node);
}

int	alx_llist_delete_node		(struct Alx_LinkedList *list,
					 struct Alx_Node *node)
{

	if (alx_llist_remove_node(list, node))
			return	ENOENT;
	alx_node_deinit(node);

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
					 const struct Alx_Node *node)
{
	struct Alx_Node	*tmp;

	tmp	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (tmp == node)
			return	i;
		tmp	= tmp->right;
	}

	return	-ENOENT;
}

int	alx_llist_get_node_at		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 ptrdiff_t pos)
{
	return	alx_llist_get_relative(list, node, list->head, pos);
}

int	alx_llist_get_relative		(const struct Alx_LinkedList *list,
					 struct Alx_Node **node,
					 const struct Alx_Node *ref,
					 ptrdiff_t pos)
{

	if (!list->nmemb)
		return	ENOENT;

	*node	= (struct Alx_Node *)ref;
	pos	%= list->nmemb;
	if (pos >= 0) {
		for (ptrdiff_t i = 0; i < pos; i++)
			*node	= (*node)->right;
	} else {
		for (ptrdiff_t i = 0; i < pos; i++)
			*node	= (*node)->left;
	}

	return	0;
}

void	alx_llist_move_node_to		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_Node	*ref;

	if (list->nmemb < 2)
		return;

	remove_node(list, node);

	if (pos <= (-list->nmemb + 1)) {
		alx_llist_append_node(list, node);
	} else if (pos >= (list->nmemb - 1)) {
		alx_llist_prepend_node(list, node);
	} else {
		/* list->nmemb != 0, so it will return 0 */
		ALX_UNUSED(alx_llist_get_node_at(list, &ref, pos));
		if (pos >= 0)
			alx_llist_insert_node_before(list, node, ref);
		else
			alx_llist_insert_node_after(list, node, ref);
	}
}

void	alx_llist_move_relative		(struct Alx_LinkedList *list,
					 struct Alx_Node *node,
					 ptrdiff_t pos)
{
	struct Alx_Node	*ref;

	if (list->nmemb < 2)
		return;
	if (!pos  ||  pos <= (-list->nmemb + 1)  ||  pos >= (list->nmemb - 1))
		return;

	/* list->nmemb != 0, so it will return 0 */
	ALX_UNUSED(alx_llist_get_relative(list, &ref, node, pos));
	remove_node(list, node);

	if (pos > 0)
		alx_llist_insert_node_after(list, node, ref);
	else
		alx_llist_insert_node_before(list, node, ref);
}

void	alx_llist_set_head		(struct Alx_LinkedList *list,
					 ptrdiff_t pos)
{
	struct Alx_Node	*node;

	if (list->nmemb < 2)
		return;

	/* list->nmemb != 0, so it will return 0 */
	ALX_UNUSED(alx_llist_get_node_at(list, &node, pos));
	list->head	= node;
	list->tail	= node->left;
}

void	alx_llist_set_node_as_head	(struct Alx_LinkedList *list,
					 struct Alx_Node *node)
{

	if (list->nmemb < 2)
		return;

	list->head	= node;
	list->tail	= node->left;
}

int	alx_llist_apply			(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state)
{
	struct Alx_Node	*current;
	struct Alx_Node	*right;
	int		status;

	current	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		right	= current->right;
		status	= f(list, current, state, i);
		if (status)
			return	status;
		current	= right;
	}

	return	0;
}

int	alx_llist_apply_bwd		(struct Alx_LinkedList *restrict list,
					 int (*f)(struct Alx_LinkedList *list,
						  struct Alx_Node *node,
						  void *restrict state,
						  ptrdiff_t i),
					 void *restrict state)
{
	struct Alx_Node	*current;
	struct Alx_Node	*right;
	int		status;

	current	= list->tail;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		right	= current->left;
		status	= f(list, current, state, i);
		if (status)
			return	status;
		current	= right;
	}

	return	0;
}

int	alx_llist_to_dynarr		(struct Alx_LinkedList *restrict list,
					 struct Alx_Dyn_Array *restrict arr)
{
	struct Alx_Node	*node;

	if (alx_dynarr_resize(arr, list->nmemb, list->head->buf->size))
		goto err_alloc;

	node	= list->head;
	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		if (node->buf->size != arr->elsize)
			goto err_size;
		if (alx_dynarr_write(arr, i, node->buf->data))
			goto err_alloc;
		node	= node->right;
	}

	return	0;
err_alloc:
	ALX_UNUSED(alx_dynarr_reset(arr, 0));
	return	ENOMEM;
err_size:
	ALX_UNUSED(alx_dynarr_reset(arr, 0));
	return	ENOBUFS;
}

void	alx_llist_to_bst		(struct Alx_BST *restrict bst,
					 struct Alx_LinkedList *restrict list,
					 int (*cmp)(int64_t bst_key,
						    int64_t user_key,
						    const void *bst_data,
						    const void *node_data))
{
	struct Alx_Node	*node;

	alx_bst_delete_all(bst);

	for (ptrdiff_t i = 0; i < list->nmemb; i++) {
		ALX_UNUSED(alx_llist_remove_tail(list, &node));
		alx_bst_insert_node(bst, node, cmp);
	}
}

int	alx_llist_treesort		(struct Alx_LinkedList *restrict list,
					 int (*cmp)(int64_t list_key,
						    int64_t user_key,
						    const void *list_data,
						    const void *node_data))
{
	struct Alx_BST	*bst;

	if (alx_bst_init(&bst))
		return	ENOMEM;

	alx_llist_to_bst(bst, list, cmp);
	alx_bst_to_llist(list, bst);

	alx_bst_deinit(bst);
	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
void	add_first_node		(struct Alx_LinkedList *list,
				 struct Alx_Node *node)
{

	node->left	= node;
	node->right	= node;
	node->parent	= NULL;

	list->head	= node;
	list->tail	= node;
	list->nmemb	= 1;
}

static
int	remove_node		(struct Alx_LinkedList *list,
				 struct Alx_Node *node)
{
	struct Alx_Node	*foo;

	if (list->nmemb == 1) {
		remove_last_node(list, &foo);
		if (foo != node)
			goto err;
		goto out;
	}

	node->left->right	= node->right;
	node->right->left	= node->left;
	list->nmemb--;

	if (node == list->head)
		list->head	= node->right;
	if (node == list->tail)
		list->tail	= node->left;
out:
	node->left	= NULL;
	node->right	= NULL;
	node->parent	= NULL;

	return	0;
err:
	add_first_node(list, foo);
	return	ENOENT;
}

static
void	remove_last_node	(struct Alx_LinkedList *list,
				 struct Alx_Node **node)
{

	*node	= list->head;

	list->head	= NULL;
	list->tail	= NULL;
	list->nmemb	= 0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
