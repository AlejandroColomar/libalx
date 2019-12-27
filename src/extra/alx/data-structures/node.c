/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/linked-list/node.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/base/stdlib/alloc/mallocs.h"
#include "libalx/base/stdlib/alloc/reallocs.h"
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
int	alx_node_new		(struct Alx_Node **node,
				 const void *data, size_t size)
{

	if (alx_node_new_empty(node))
		return	ENOMEM;
	if (alx_mallocs(&(*node)->data, size))
		goto err;
	(*node)->size	= size;
	memcpy((*node)->data, data, size);

	return	0;
err:
	alx_node_delete(*node);
	return	ENOMEM;
}

int	alx_node_new_empty	(struct Alx_Node **node)
{

	if (alx_mallocarrays(node, 1))
		return	ENOMEM;
	(*node)->size	= 0;
	(*node)->data	= NULL;
	(*node)->left	= NULL;
	(*node)->right	= NULL;

	return	0;
}

void	alx_node_delete		(struct Alx_Node *node)
{

	if (node)
		free(node->data);
	free(node);
}

int	alx_node_edit_data	(struct Alx_Node *node,
				 const void *data, size_t size)
{

	if (alx_reallocs(&node->data, size))
		return	ENOMEM;
	node->size	= size;

	memmove(node->data, data, size);

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
