/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list/treesort.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/alloc/mallocs.h"
#include "libalx/base/stdlib/alloc/reallocs.h"
#include "libalx/extra/alx/linked-list/llist.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/
/*
 * Binary search tree node
 *
 * data:	Pointer to memory containing useful data.
 * size:	Size of the allocated buffer (in bytes).
 * left:	Pointer to left subtree.
 * right:	Pointer to right subtree.
 * parent:	Pointer to parent supertree.
 * nmemb:	Number of nodes in the tree (including this node)
 */
struct	Alx_LL_Node {
	void			*data;
	size_t			size;
	struct Alx_LL_Node	*left;
	struct Alx_LL_Node	*right;
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull))
static
int	new_node		(struct Alx_LL_Node **node, void *data);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_bst_new		(struct Alx_LL_Node **bst,
				 const void *data, size_t size)
{
	return	new_node(bst, data, size);
}

int	alx_bst_insert		(struct Alx_LL_Node *bst,
				 const void *data, size_t size,
				 int (*cmp)	(const void *bst_data,
						 const void *node_data))
{
	struct Alx_BST_Node	*node;
	int			status;

	status	= new_node(&node, data, size);
	if (status)
		return	status;

	alx_bst_insert_node(tree, node, cmp);

	return	0;
}

int	alx_bst_insert_node	(struct Alx_LL_Node *bst,
				 struct Alx_LL_Node *node,
				 int (*cmp)(const void *bst_data,
					    const void *node_data))
{

	if (cmp(bst->data, node->data) < 0) {
		if (!bst->left)
			bst->left	= node;
		else
			insert_node(bst->left, node, cmp);
	} else {
		if (!bst->right)
			bst->right	= node;
		else
			insert_node(bst->right, node, cmp);
	}
}

int	alx_bst_into_array	(


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
__attribute__((nonnull))
static
int	new_node		(struct Alx_LL_Node **node,
				 const void *data, size_t size)
{

	if (alx_mallocarrays(node, 1))
		return	ENOMEM;
	if (alx_mallocs(&node->data, size))
		goto err;
	node->size	= size;

	memcpy(node->data, data, size);
	(*node)->left	= NULL;
	(*node)->right	= NULL;

	return	0;
err:
	free(node);
	return	ENOMEM;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
