/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/alx/data-structures/node.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "libalx/base/stdlib/alloc/mallocarrays.h"
#include "libalx/extra/alx/data-structures/dyn-buffer.h"


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
int	alx_node_init		(struct Alx_Node **restrict node,
				 const void *restrict data, size_t size)
{

	if (alx_node_init_empty(node))
		goto err;
	if (alx_dynbuf_init(&(*node)->buf))
		goto err;
	if (alx_node_write(*node, data, size))
		goto err;

	return	0;
err:
	alx_node_deinit(*node);
	return	ENOMEM;
}

int	alx_node_init_empty	(struct Alx_Node **node)
{

	if (alx_mallocarrays(node, 1))
		return	ENOMEM;
	(*node)->buf	= NULL;
	(*node)->left	= NULL;
	(*node)->right	= NULL;
	(*node)->parent	= NULL;

	return	0;
}

void	alx_node_deinit		(struct Alx_Node *node)
{

	if (!node)
		return;

	alx_dynbuf_deinit(node->buf);
	free(node);
}

int	alx_node_write		(struct Alx_Node *node,
				 const void *data, size_t size)
{
	return	alx_dynbuf_write(node->buf, 0, data, size);
}

int	alx_node_read		(const struct Alx_Node *node,
				 void *data, size_t size)
{
	return	alx_dynbuf_read(node->buf, 0, data, size);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
