/*****************************************************************************
 *
 * This example source code introduces a c library buffered I/O interface to
 * URL reads it supports fopen(), fread(), fgets(), feof(), fclose(),
 * rewind(). Supported functions have identical prototypes to their normal c
 * lib namesakes and are preceaded by url_ .
 *
 * Using this code you can replace your program's fopen() with url_fopen()
 * and fread() with url_fread() and it become possible to read remote streams
 * instead of (only) local files. Local files (ie those that can be directly
 * fopened) will drop back to using the underlying clib implementations
 *
 * See the main() function at the bottom that shows an app that retrieves from
 * a specified url using fgets() and fread() and saves as two output files.
 *
 * Copyright (c) 2003 - 2019 Simtec Electronics
 *
 * Re-implemented by Vincent Sanders <vince@kyllikki.org> with extensive
 * reference to original curl example code
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * TODO: url_fwrite()	- Use CURLOPT_READFUNCTION and CURLOPT_READDATA
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/curl/fcurl/fopen.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/base/compiler/unused.h"
#include "libalx/base/stdlib/alloc/callocs.h"
#include "libalx/extra/curl/fcurl/init.h"
#include "libalx/extra/curl/fcurl/URL_FILE.h"

#include "internal.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
int	url_fopen__	(ALX_URL_FILE *stream, const char *url,
			 const char *mode);
static
int	url_fopen_r__	(ALX_URL_FILE *stream, const char *url);
/* curl calls this routine to get more data */
static
size_t	url_write_cb__	(const void *buf, size_t size, size_t nmemb,
			 void *ostream);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
ALX_URL_FILE	*alx_url_fopen	(const char *url, const char *mode)
{
	ALX_URL_FILE	*stream;

	if (alx_callocs(&stream, 1))
		return	NULL;
	if (alx_dynbuf_init(&stream->buf))
		goto err;

	stream->handle.file = fopen(url, "r");
	if (stream->handle.file) {
		stream->type = ALX_URL_CFTYPE_FILE; /* marked as FILE */
		return	stream;
	}

	if (url_fopen__(stream, url, mode))
		goto err;

	return	stream;
err:
	free(stream);
	return	NULL;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	url_fopen__	(ALX_URL_FILE *stream, const char *url,
			 const char *mode)
{
	int	status;

	if (!alx_url_mhandle__) {
		status = alx_url_init();
		if (status)
			return	status;
	}

	if (!strcmp(mode, "r")  ||  !strcmp(mode, "rb"))
		status	= url_fopen_r__(stream, url);
	else
		status	= EINVAL;

	if (!status)
		stream->type	= ALX_URL_CFTYPE_CURL; /* marked as URL */

	return	status;
}

static
int	url_fopen_r__	(ALX_URL_FILE *stream, const char *url)
{
	int	err;

	stream->handle.curl	= curl_easy_init();
	if (!stream->handle.curl)
		return	EAGAIN;

	err = curl_easy_setopt(stream->handle.curl, CURLOPT_URL, url);
	if (err)
		goto clean_opt;
	(void)curl_easy_setopt(stream->handle.curl, CURLOPT_WRITEDATA, stream);
	(void)curl_easy_setopt(stream->handle.curl, CURLOPT_VERBOSE, 0L);
	(void)curl_easy_setopt(stream->handle.curl, CURLOPT_WRITEFUNCTION,
							&url_write_cb__);

	err = curl_multi_add_handle(alx_url_mhandle__, stream->handle.curl);
	if (err)
		goto clean_opt;

	/* lets start the fetch */
	err = curl_multi_perform(alx_url_mhandle__, &stream->still_running);
	if (err)
		goto err_fetch;
	if ((!stream->buf->written) && (!stream->still_running)) {
		err	= EREMOTEIO;
		goto err_fetch;
	}

	return	0;
err_fetch:
	curl_multi_remove_handle(alx_url_mhandle__, stream->handle.curl);
clean_opt:
	curl_easy_cleanup(stream->handle.curl);
	stream->handle.curl	= NULL;
	return	err;
}

static
size_t	url_write_cb__	(const void *buf, size_t size, size_t nmemb,
			 void *ostream)
{
	ALX_URL_FILE *stream;

	if (!nmemb || !size)
		return	0;
	if (nmemb  >  (SIZE_MAX / size))
		return	0;

	stream	= ostream;
	size	*= nmemb;

	if (alx_dynbuf_write(stream->buf, stream->buf->written, buf, size))
		return	0;

	return	nmemb;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

