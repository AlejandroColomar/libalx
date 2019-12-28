/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/data-structures/bst.h"

#include <errno.h>
#include <stddef.h>

#include "libalx/extra/alx/data-structures/llist.h"
#include "libalx/extra/alx/data-structures/node.h"


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
			son	= parent->left;
			pos	= LEFT;
		} else {
			son	= parent->right;
			pos	= RIGHT;
		}
	}

	node->parent	= parent;
	if (pos == LEFT)
		parent->left	= node;
	else
		parent->right	= node;
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

struct Alx_Node	*alx_bst_parentmost_node(struct Alx_Node *restrict bst)
{

	while (bst->parent)
		bst	= bst->parent;

	return	bst;
}

struct Alx_Node	*alx_bst_join_L_R	(struct Alx_Node *restrict node)
{
	struct Alx_Node	*tmp;
	struct Alx_Node	*bst;

	if (!node->left  &&  !node->right)
		return	NULL;
	if (!node->left) {
		bst	= node->right;
		node->right->parent	= NULL;
		node->right		= NULL;
		return	bst;
	}
	if (!node->right) {
		bst	= node->left;
		node->left->parent	= NULL;
		node->left		= NULL;
		return	bst;
	}

	bst	= node->left;
	tmp	= alx_bst_rightmost_node(node->left);
	node->left->parent	= NULL;
	node->right->parent	= tmp;
	tmp->right		= node->right;

	node->left	= NULL;
	node->right	= NULL;

	return	bst;
}

struct Alx_Node	*alx_bst_remove_node	(struct Alx_Node *restrict node)
{
	struct Alx_Node	*bst;

	bst	= alx_bst_parentmost_node(node);

	if (bst == node) {
		bst	= alx_bst_join_L_R(node);
	} else if (node == node->parent->left) {
		node->parent->left		= alx_bst_join_L_R(node);
		node->parent->left->parent	= node->parent;
	} else {
		node->parent->right		= alx_bst_join_L_R(node);
		node->parent->right->parent	= node->parent;
	}
	node->parent	= NULL;

	return	bst;
}

void	alx_bst_to_llist		(struct Alx_Node *restrict bst,
					 struct Alx_LinkedList *restrict list)
{
	struct Alx_Node	*node;

	alx_llist_delete_all(list);

	while (bst) {
		node	= alx_bst_leftmost_node(bst);
		bst	= alx_bst_remove_node(node);
		alx_llist_append_node(list, node);
	}
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
