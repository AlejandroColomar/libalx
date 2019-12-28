/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/

<libalx/base/stdlib/alloc/*>
============================

The following functions are added to the C / POSIX / GNU / BSD allocation
functions (some of them may be implemented as macros; only when necessary).


1) Headers
----------

.. code-block:: c

	<libalx/base/stdlib/alloc/callocs.h>
	<libalx/base/stdlib/alloc/callocs.hpp>
	<libalx/base/stdlib/alloc/mallocarray.h>
	<libalx/base/stdlib/alloc/mallocarray.hpp>
	<libalx/base/stdlib/alloc/mallocarrays.h>
	<libalx/base/stdlib/alloc/mallocarrays.hpp>
	<libalx/base/stdlib/alloc/mallocs.h>
	<libalx/base/stdlib/alloc/mallocs.hpp>
	<libalx/base/stdlib/alloc/reallocarrayf.h>
	<libalx/base/stdlib/alloc/reallocarrayf.hpp>
	<libalx/base/stdlib/alloc/reallocarrayfs.h>
	<libalx/base/stdlib/alloc/reallocarrayfs.hpp>
	<libalx/base/stdlib/alloc/reallocarrays.h>
	<libalx/base/stdlib/alloc/reallocarrays.hpp>
	<libalx/base/stdlib/alloc/reallocfs.h>
	<libalx/base/stdlib/alloc/reallocfs.hpp>
	<libalx/base/stdlib/alloc/reallocs.h>
	<libalx/base/stdlib/alloc/reallocs.hpp>

2) Functions
------------

.. code-block:: c

	[[gnu::nonnull]]
	int	callocs(type **restrict ptr, ptrdiff_t nmemb);

	[[gnu::malloc]] [[gnu::warn_unused_result]]
	void	*mallocarray(ptrdiff_t nmemb, size_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	mallocarrays(type **restrict ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]]  [[gnu::warn_unused_result]]
	int	mallocs(void **restrict ptr, size_t size);

	[[gnu::warn_unused_result]]
	void	*reallocarrayf(void *ptr, ptrdiff_t nmemb, size_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocarrayfs(type **restrict ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]][[gnu::warn_unused_result]]
	int	reallocarrays(type **restrict ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocfs(void **restrict ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocs(void **restrict ptr, ptrdiff_t nmemb);

To be able to use any of those functions, the corresponding header should be
included.

3) When to use each of the functions
------------------------------------

Functions ending in ``s`` should always be preferred.

Reallocation functions ending in ``f`` (or ``fs``) free the memory upon
failure to ease error handling.

Functions containing ``array`` (and ``callocs()``) should be used when
allocating arrays, or single elements (arrays of size 1).  The other funtions
should be used when and only when dealing with buffers of bytes.

4) More info
------------

For more detailed documentation about each of the functions, read the
corresponding headers.

