/*****************************************************************************
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
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "internal.h"

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/base/stdlib/maximum.h"
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
CURLM	*alx_url_mhandle__;


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_url_fill_buffer__	(ALX_URL_FILE *stream, size_t want)
{
	int64_t	curl_timeo;
	int	status;

	if (stream->buf->written > want)
		return	0;
	if (!stream->still_running)
		return	ENOSR;

	do {
		status	= curl_multi_timeout(alx_url_mhandle__, &curl_timeo);
		if (status)
			return	status;
		curl_timeo	= ALX_MAX(curl_timeo, 10);
		status	= curl_multi_poll(alx_url_mhandle__, NULL, 0,
							curl_timeo, NULL);
		if (status)
			return	status;

		/* timeout or readable/writable sockets */
		status	= curl_multi_perform(alx_url_mhandle__,
							&stream->still_running);
		if (status)
			return	status;
	} while (stream->still_running && (stream->buf->written < want));

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

