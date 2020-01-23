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
 *
 * This example requires libcurl 7.9.7 or later.
 */
/* <DESC>
 * implements an fopen() abstraction allowing reading from URLs
 * </DESC>
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "internal.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <sys/select.h>
#include <sys/time.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/extra/curl/fcurl/URL_FILE.h"


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
 ******* variables ************************************************************
 ******************************************************************************/
/* we use a global one for convenience */
CURLM	*alx_url_multi_handle__;


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
size_t	alx_url_write_callback__(const char *buf, size_t size, size_t nmemb,
				 void *userp)
{
	ALX_URL_FILE *stream;

	if (!nmemb || !size)
		return	0;
	if (nmemb  >  (SIZE_MAX / size))
		return	0;

	stream	= (ALX_URL_FILE *)userp;
	size	= nmemb * size;

	if (alx_dynbuf_write(stream->buf, stream->buf->written, buf, size))
		return	0;

	return	size;
}

int	alx_url_fill_buffer__	(ALX_URL_FILE *stream, size_t want)
{
	fd_set	fdread;
	fd_set	fdwrite;
	fd_set	fdexcep;
	struct timeval	timeout;
	int	rc;
	CURLMcode	mc;	/* curl_multi_fdset() return code */
	int	maxfd;
	long	curl_timeo;

	/* only attempt to fill buffer if transactions still running and buffer
	 * doesn't exceed required size already
	 */
	if ((!stream->still_running) || (stream->buf->written > want))
		return	0;

	/* attempt to fill buffer */
	do {
		maxfd = -1;
		curl_timeo = -1;

		FD_ZERO(&fdread);
		FD_ZERO(&fdwrite);
		FD_ZERO(&fdexcep);

		/* set a suitable timeout to fail on */
		timeout.tv_sec = 60; /* 1 minute */
		timeout.tv_usec = 0;

		curl_multi_timeout(alx_url_multi_handle__, &curl_timeo);
		if (curl_timeo >= 0) {
			timeout.tv_sec = curl_timeo / 1000;
			if (timeout.tv_sec > 1)
				timeout.tv_sec = 1;
			else
				timeout.tv_usec = (curl_timeo % 1000) * 1000;
		}

		/* get file descriptors from the transfers */
		mc	= curl_multi_fdset(alx_url_multi_handle__, &fdread,
						 &fdwrite, &fdexcep, &maxfd);

		if (mc != CURLM_OK)
			/* "curl_multi_fdset() failed, code %d.\n", mc */
			return	1;

		/* On success the value of maxfd is guaranteed to be >= -1.
		 * We call  select(maxfd + 1, ...); specially in case of
		 * (maxfd == -1) there are no fds ready yet so we call
		 * select(0, ...) to sleep 100ms, which is the minimum
		 * suggested value in the curl_multi_fdset() doc. */

		if (maxfd == -1) {
			struct timeval	wait = {0, 100 * 1000}; /* 100ms */
			rc	= select(0, NULL, NULL, NULL, &wait);
		} else {
			/* Note that on some platforms 'timeout' may be
			 * modified by select().  If you need access to the
			 * original value save a copy beforehand. */
			rc	= select(maxfd + 1, &fdread, &fdwrite,
							&fdexcep, &timeout);
		}

		if (rc == -1)
			/* select error */
			continue;

		/* timeout or readable/writable sockets */
		curl_multi_perform(alx_url_multi_handle__, &stream->still_running);

	} while (stream->still_running && (stream->buf->written < want));

	return	1;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

