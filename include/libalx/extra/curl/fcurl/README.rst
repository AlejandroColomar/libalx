
:Author:	Simtec Electronics
:Author:	Vincent Sanders
:Author:	Alejandro Colomar Andrés
________________________________________________________________________________


<libalx/extra/curl/fcurl/*>
============================


This code is a C library buffered I/O interface to URL reads.
It supports fopen(), fread(), fgets(), feof(), fclose(), rewind().
Supported functions have identical prototypes to their normal C
lib namesakes and are preceaded by url_ .


1) Headers
----------

::

	<libalx/extra/curl/fcurl/fclose.h>
	<libalx/extra/curl/fcurl/feof.h>
	<libalx/extra/curl/fcurl/fgets.h>
	<libalx/extra/curl/fcurl/fopen.h>
	<libalx/extra/curl/fcurl/fread.h>
	<libalx/extra/curl/fcurl/init.h>
	<libalx/extra/curl/fcurl/rewind.h>
	<libalx/extra/curl/fcurl/URL_FILE.h>

2) Functions
------------

::

	[[gnu::warn_unused_result]]
	int	url_init(void);

	[[gnu::destructor]] [[gnu::warn_unused_result]]
	int	url_deinit(void);

	[[gnu::warn_unused_result]]
	int	url_fclose(URL_FILE *stream);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	url_feof(URL_FILE *stream);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	char	*url_fgets(char *str, size_t size, URL_FILE *stream);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	URL_FILE *url_fopen(const char *url, const char *mode);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	ptrdiff_t url_fread(void *ptr, size_t size, ptrdiff_t nmemb,
			    URL_FILE *stream);

	[[gnu::nonnull]] [[gnu::warn_unused_result]]
	int	url_rewind(URL_FILE *stream);

To be able to use any of those functions, the corresponding header should be
included.


3) Description
--------------

Using this code you can replace your program's fopen() with url_fopen()
and fread() with url_fread() and it becomes possible to read remote streams
instead of (only) local files.  Local files (ie those that can be directly
fopened) will drop back to using the underlying libc implementations.

The user should initialize the module by calling url_init(), and deinitialize
it afterwards by calling url_deinit().  Those calls are not strictly
necessary, because the library will call them internally if needed (url_init()
will be called during the first url_fopen() call, and url_fclose() will be
called after main() ends or exit() is called).

Unlike fopen(), url_fopen() accepts NULL, in which case it returns EOF with no
other operation.

Instead of a `FILE *`, the user should use `URL_FILE *`.  Its usage is
identical to `FILE *`.


4) More info
------------

For more detailed documentation about each of the functions, read the
corresponding headers.


5) Example
----------

See a program that uses this library to read a file from an URL (or a path)
in stdout (similar to cat):

<url_cat>

