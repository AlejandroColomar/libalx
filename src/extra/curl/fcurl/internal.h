/******************************************************************************
 *
 * Copyright (c) 2003 - 2019 Simtec Electronics
 *
 * Re-implemented by Vincent Sanders <vince@kyllikki.org> with extensive
 * reference to original curl example code
 *
 * Modified by Alejandro Colomar Andrés <colomar.6.4.3@gmail.com> to be
 * used as a library and included in the libalx library.
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
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/src/extra/curl/fcurl/internal.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdio.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"
#include "libalx/extra/curl/fcurl/URL_FILE.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_URL_Type {
	CFTYPE_NONE = 0,
	CFTYPE_FILE = 1,
	CFTYPE_CURL = 2
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_URL_Data {
	enum Alx_URL_Type	type;	/* type of handle */
	union {
		CURL	*curl;
		FILE	*file;
	} handle;			/* handle */
	struct Alx_Dyn_Buffer	*buf;	/* buffer to store cached data*/
	int	still_running;	/* Is background url fetch still in progress */
};


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
/* curl calls this routine to get more data */
size_t	alx_url_write_callback__(const char *buf, size_t size, size_t nitems,
				 void *userp);

/* use to attempt to fill the read buffer up to requested number of bytes */
int	alx_url_fill_buffer__	(ALX_URL_FILE *stream, size_t want);


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
/* we use a global one for convenience */
extern	CURLM	*alx_url_multi_handle__;


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

