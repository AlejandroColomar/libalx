/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/alx/linked-list/circular-doubly.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include "libalx/extra/alx/linked-list/doubly.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_cdllist_init		(struct Alx_DLinkedList **list);
[[gnu::nonnull]]
int	alx_cdllist_deinit		(struct Alx_DLinkedList *list);
[[gnu::nonnull]]
int	alx_cdllist_first_element	(struct Alx_DLinkedList *list,
					 void *data);
[[gnu::nonnull]]
int	alx_cdllist_remove_last		(struct Alx_DLinkedList *list);
[[gnu::nonnull]]
int	alx_cdllist_prepend		(struct Alx_DLinkedList *list,
					 void *data);
[[gnu::nonnull]]
int	alx_cdllist_append		(struct Alx_DLinkedList *list,
					 void *data);
[[gnu::nonnull]]
int	alx_cdllist_add_before		(struct Alx_DLinkedList *list,
					 void *data);
[[gnu::nonnull]]
int	alx_cdllist_add_after		(struct Alx_DLinkedList *list,
					 void *data);
[[gnu::nonnull]]
int	alx_cdllist_remove_head		(struct Alx_DLinkedList *list);
[[gnu::nonnull]]
int	alx_cdllist_remove_tail		(struct Alx_DLinkedList *list);
[[gnu::nonnull]]
int	alx_cdllist_remove_current	(struct Alx_DLinkedList *list);
[[gnu::nonnull]]
int	alx_cdllist_remove_all		(struct Alx_DLinkedList *list);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t alx_cdllist_find		(struct Alx_DLinkedList *list,
					 struct Alx_DLLNode *node);
[[gnu::nonnull]]
int	alx_cdllist_move_fwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n);
[[gnu::nonnull]]
int	alx_cdllist_move_bwd		(struct Alx_DLinkedList *list,
					 ptrdiff_t n);
[[gnu::nonnull]]
int	alx_cdllist_move_to		(struct Alx_DLinkedList *list,
					 ptrdiff_t pos);
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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
