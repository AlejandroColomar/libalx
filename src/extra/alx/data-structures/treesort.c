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
#include "libalx/extra/alx/linked-list/linked-list.h"


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
 */
struct	Alx_BST_Node {
	void			*data;
	size_t			size;
	struct Alx_BST_Node	*left;
	struct Alx_BST_Node	*right;
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull))
static
void	insert_node_into_bst		(struct Alx_BSTNode *tree, );


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_llist_treesort		(struct Alx_LinkedList **list,
					 int (*cmp_f)
						(const void *root,
						 const void *r))
{
	struct Alx_BST_Node	*bst;

	if (alx_mallocarrays(&bst, 1))
		return	ENOMEM;

	(*list)->head		= NULL;
	(*list)->tail		= NULL;
	(*list)->nmemb		= 0;

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
