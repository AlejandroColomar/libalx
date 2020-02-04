/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dyn-array.hpp */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic array
 *
 * Read  <libalx/alx/data-structures/dyn-array.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/alx/data-structures/llist.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_Dyn_Array {
	unsigned char	*data;
	size_t		elsize;
	ptrdiff_t	nmemb;
	ptrdiff_t	written;
};

/* Avoid circular include dependence */
struct	Alx_LinkedList;

extern	"C"
{
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_init		(struct Alx_Dyn_Array **arr, size_t elsize);
void	alx_dynarr_deinit	(struct Alx_Dyn_Array *arr);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_write	(struct Alx_Dyn_Array *restrict arr,
				 ptrdiff_t cell, const void *restrict data);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_insert	(struct Alx_Dyn_Array *restrict arr,
				 ptrdiff_t cell, const void *restrict data);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_read		(const struct Alx_Dyn_Array *restrict arr,
				 ptrdiff_t cell, void *restrict data);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_remove	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t cell);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_resize	(struct Alx_Dyn_Array *arr,
				 ptrdiff_t nmemb, size_t elsize);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_reset	(struct Alx_Dyn_Array *arr, size_t elsize);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_fit		(struct Alx_Dyn_Array *arr);
[[gnu::nonnull]][[gnu::warn_unused_result]]
int	alx_dynarr_to_llist	(struct Alx_Dyn_Array *arr,
				 struct Alx_LinkedList *list);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
