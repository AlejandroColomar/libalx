/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/data-structures/bst.h"

#include <errno.h>
#include <stddef.h>

#include "libalx/alx/data-structures/llist.h"
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
 * Removes the left and right subtrees of a BST node, and joins them into a
 * new isolated BST.  Updates any necessary metadata.
 * Returns a pointer to the new BST.
 *
 * node:	Pointer to a node.
 */
__attribute__((nonnull))
static
struct Alx_Node	*bst_join_L_R	(struct Alx_Node *restrict node);

/*
 * Helper function for alx_bst_to_llist()
 */
static
void	bst_to_llist_recursive	(struct Alx_Node *restrict bst,
				 struct Alx_LinkedList *restrict list);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_bst_insert			(struct Alx_Node *bst,
					 const void *data, size_t size,
					 int (*cmp)(const void *bst_data,
						    const void *node_data))
{
	struct Alx_Node	*node;

	if (alx_node_init(&node, data, size))
		return	ENOMEM;
	alx_bst_insert_node(bst, node, cmp);

	return	0;
}

void	alx_bst_insert_node		(struct Alx_Node *restrict bst,
					 struct Alx_Node *restrict node,
					 int (*cmp)(const void *bst_data,
						    const void *node_data))
{
	enum		{LEFT, RIGHT};

	struct Alx_Node	*parent;
	struct Alx_Node	*son;
	int		pos;

	son	= bst;
	while (son) {
		parent	= son;
		if (cmp(bst->buf->data, node->buf->data) < 0) {
			son	= son->left;
			pos	= LEFT;
		} else {
			son	= son->right;
			pos	= RIGHT;
		}
	}

	if (pos == LEFT)
		parent->left	= node;
	else
		parent->right	= node;
}

void	alx_bst_delete_all		(struct Alx_Node *restrict bst)
{
	struct Alx_Node	*right;

	if (!bst)
		return;

	alx_bst_delete_all(bst->left);
	right	= bst->right;
	alx_node_deinit(bst);
	alx_bst_delete_all(right);
}

struct Alx_Node	*alx_bst_leftmost_node	(struct Alx_Node *restrict bst)
{

	while (bst->left)
		bst	= bst->left;

	return	bst;
}

struct Alx_Node	*alx_bst_rightmost_node	(struct Alx_Node *restrict bst)
{

	while (bst->right)
		bst	= bst->right;

	return	bst;
}

struct Alx_Node	*alx_bst_remove_node	(struct Alx_Node *restrict parent,
					 struct Alx_Node *restrict node)
{

	if (!parent)
		parent	= bst_join_L_R(node);
	else if (node == parent->left)
		parent->left	= bst_join_L_R(node);
	else
		parent->right	= bst_join_L_R(node);

	node->left	= NULL;
	node->right	= NULL;

	return	parent;
}

int	alx_bst_apply			(struct Alx_Node *restrict bst,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state)
{
	struct Alx_Node	*right;
	int		status;

	if (!bst)
		return	0;

	status	= alx_bst_apply(bst->left, f, state);
	if (status)
		return	status;

	right	= bst->right;
	status	= f(bst, state);
	if (status)
		return	status;

	return	alx_bst_apply(right, f, state);
}

int	alx_bst_apply_bwd		(struct Alx_Node *restrict bst,
					 int (*f)(struct Alx_Node *restrict node,
						  void *restrict state),
					 void *restrict state)
{
	struct Alx_Node	*left;
	int		status;

	if (!bst)
		return	0;

	status	= alx_bst_apply(bst->right, f, state);
	if (status)
		return	status;

	left	= bst->left;
	status	= f(bst, state);
	if (status)
		return	status;

	return	alx_bst_apply_bwd(left, f, state);
}

void	alx_bst_to_llist		(struct Alx_Node *restrict bst,
					 struct Alx_LinkedList *restrict list)
{

	alx_llist_delete_all(list);
	bst_to_llist_recursive(bst, list);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
struct Alx_Node	*bst_join_L_R	(struct Alx_Node *restrict node)
{
	struct Alx_Node	*tmp;
	struct Alx_Node	*bst;

	if (!node->left  &&  !node->right)
		return	NULL;
	if (!node->left) {
		bst		= node->right;
		node->right	= NULL;
		return	bst;
	}
	if (!node->right) {
		bst		= node->left;
		node->left	= NULL;
		return	bst;
	}

	bst		= node->left;
	tmp		= alx_bst_rightmost_node(node->left);
	tmp->right	= node->right;

	node->left	= NULL;
	node->right	= NULL;

	return	bst;
}

static
void	bst_to_llist_recursive	(struct Alx_Node *restrict bst,
				 struct Alx_LinkedList *restrict list)
{
	struct Alx_Node	*right;

	if (!bst)
		return;
	bst_to_llist_recursive(bst->left, list);
	right	= bst->right;
	alx_llist_append_node(list, bst);
	bst_to_llist_recursive(right, list);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
