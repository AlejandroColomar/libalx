/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/alx/data-structures/dyn-buffer.hpp */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * Dynamic buffer
 *
 * Read  <libalx/alx/data-structures/dyn-buffer.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <sys/types.h>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
struct	Alx_Dyn_Buffer {
	unsigned char	*data;
	size_t		size;
	size_t		written;
};

extern	"C"
{
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_init		(struct Alx_Dyn_Buffer **buf);
void	alx_dynbuf_deinit	(struct Alx_Dyn_Buffer *buf);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_write	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_insert	(struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset,
				 const void *restrict data, size_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
ssize_t	alx_dynbuf_read		(void *restrict data, size_t size,
				 const struct Alx_Dyn_Buffer *restrict buf,
				 size_t offset);
[[gnu::nonnull]]
void	alx_dynbuf_consume	(struct Alx_Dyn_Buffer *buf, size_t size);
[[gnu::nonnull]] [[gnu::warn_unused_result]]
int	alx_dynbuf_resize	(struct Alx_Dyn_Buffer *buf, size_t size);
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
