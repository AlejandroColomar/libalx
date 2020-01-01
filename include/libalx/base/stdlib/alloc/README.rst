
:Author:	Alejandro Colomar Andrés
________________________________________________________________________________


<libalx/base/stdlib/alloc/*>
============================


These functions and macros provide a simpler and safer interface that allows
the user to allocate memory in a single short statement without having to add
checks for all the different possible errors.


1) Headers
----------

::

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
	<libalx/base/stdlib/alloc/frees.h>
	<libalx/base/stdlib/alloc/frees.hpp>

2) Functions
------------

::

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	callocs(type **ptr, ptrdiff_t nmemb);

	[[gnu::malloc]] [[gnu::warn_unused_result]]
	void	*mallocarray(ptrdiff_t nmemb, size_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	mallocarrays(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	mallocs(type **ptr, size_t size);

	[[gnu::warn_unused_result]]
	void	*reallocarrayf(void *ptr, ptrdiff_t nmemb, size_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocarrayfs(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]][[gnu::warn_unused_result]]
	int	reallocarrays(type **ptr, ptrdiff_t nmemb);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocfs(type **ptr, size_t size);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	reallocs(type **ptr, size_t size);

	[[gnu::nonnull]]
	void	frees(type **ptr);

To be able to use any of those functions, the corresponding header should be
included.


3) Description
--------------

Functions ending in ``s`` should always be preferred.  These are implemented
as macros.  These macros use ``sizeof()`` internally and safely assign to
the pointer as needed, avoiding unsafe usage of memory allocation functions.
An error code is returned to the user; this error code shall be used.

Reallocation functions ending in ``f`` (or ``fs``) free the memory upon
failure to ease error handling.

Functions containing ``array`` (and ``callocs()``) should be used when
allocating arrays, or single elements (arrays of size 1).  The other funtions
should be used when and only when dealing with buffers of bytes.

``frees()`` stores ``NULL`` in the pointer so that it can be freed more than
once safely.


4) More info
------------

For more detailed documentation about each of the functions, read the
corresponding headers.

