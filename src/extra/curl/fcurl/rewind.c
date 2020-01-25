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
#include "libalx/extra/curl/fcurl/rewind.h"

#include <stdio.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
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


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_url_rewind	(ALX_URL_FILE *stream)
{
	int	ret;

	ret	= 0;
	switch (stream->type) {
	case ALX_URL_CFTYPE_FILE:
		rewind(stream->handle.file);
		break;

	case ALX_URL_CFTYPE_CURL:
		ret = curl_multi_remove_handle(alx_url_mhandle__,
							stream->handle.curl);
		if (ret)
			goto err;
		ret = curl_multi_add_handle(alx_url_mhandle__,
							stream->handle.curl);
err:
		stream->buf->written	= 0;
		break;

	default:	/* unknown or supported type */
		break;
	}

	return	ret;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

