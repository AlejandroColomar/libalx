/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/types.h */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_Generic_Type {
	ALX_TYPE_NONE,

	ALX_TYPE_S64,
	ALX_TYPE_U64,
	ALX_TYPE_DBL,
	ALX_TYPE_STR,
	ALX_TYPE_VP,

	ALX_TYPES
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_Generic {
	bool	cnst;
	int	type;
	union {
		int64_t			i64;
		uint64_t			u64;
		double				lf;
		struct Alx_Dyn_Buffer		*buf;
		const struct Alx_Dyn_Buffer	*cbuf;
	};
};

/*
 * Comparison function.  This function should return
 *		0:	The user_node compares equal to the compared ds_node.
 *		< 0:	The user_node goes to the left of the compared ds_node.
 *		> 0:	The user_node goes to the right of the compared ds_node.
 */
typedef int	cmp_f	(int64_t user_key, int64_t ds_key,
			 const struct Alx_Generic *user_data,
			 const struct Alx_Generic *ds_data);

/*
 * Dynamic buffer
 *
 * data:	Pointer to the first byte in the buffer.
 * size:	Size of the data buffer (in bytes).
 * written:	Data used (in bytes).
 */
struct	Alx_Dyn_Buffer {
	void		*data;
	size_t		size;
	size_t		written;
};

/*
 * Dynamic array
 *
 * data:	Pointer to the first element in the array.
 * elsize:	Size of each cell (in bytes).
 * nmemb:	Number of cells in the array.
 * written:	Number of used cells in the array.
 */
struct	Alx_Dyn_Array {
	unsigned char	*data;
	size_t		elsize;
	ptrdiff_t	nmemb;
	ptrdiff_t	written;
};

/*
 * Node
 *
 * key:		Key value.
 * buf:		Pointer to a dynamic buffer containing useful data.
 * left:	Pointer to the left node.
 * right:	Pointer to the right node.
 * parent:	Pointer to the parent node (in a tree).
 * count:	Count (for repeated nodes in trees that don't accept duplicates).
 */
struct	Alx_Node {
	int64_t		key;
	struct Alx_Dyn_Buffer	*buf;
	struct Alx_Node	*left;
	struct Alx_Node	*right;
	struct Alx_Node	*parent;
	ptrdiff_t		dup;
};

/*
 * Doubly-linked list
 *
 * head:	Pointer to the first node.
 * tail:	Pointer to the last node.
 * nmemb:	Number of nodes in the list.
 */
struct	Alx_LinkedList {
	struct Alx_Node	*head;
	struct Alx_Node	*tail;
	ptrdiff_t		nmemb;
};

/*
 * Binary search tree
 */
struct	Alx_BST {
	struct Alx_Node	*root;
	ptrdiff_t		nmemb;
	cmp_f			*cmp;		/* comparison function pointer */
	int64_t		key_min;	/* minimum key in the BST */
	int64_t		key_max;	/* maximum key in the BST */
	bool			dup;		/* Allow for duplicate members? */
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
