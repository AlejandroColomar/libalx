/******************************************************************************
 *
 * Copyright (c) 2003 - 2019 Simtec Electronics
 *
 * Re-implemented by Vincent Sanders <vince@kyllikki.org> with extensive
 * reference to original curl example code
 *
 * Modified by Alejandro Colomar Andrés <colomar.6.4.3@gmail.com> to be
 * included in the libalx library.
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
#pragma once	/* libalx/extra/curl/fcurl/URL_FILE.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdio.h>

#include <curl/curl.h>

#include "libalx/alx/data-structures/dyn-buffer.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_URL_stdin	(ALX_URL_FILE){					\
				.type		= ALX_URL_CFTYPE_FILE,	\
				.handle.file	= stdin,		\
				.buf		= NULL,			\
				.still_running	= 0,			\
			}
#define ALX_URL_stdout	(ALX_URL_FILE){					\
				.type		= ALX_URL_CFTYPE_FILE,	\
				.handle.file	= stdout,		\
				.buf		= NULL,			\
				.still_running	= 0,			\
			}
#define ALX_URL_stderr	(ALX_URL_FILE){					\
				.type		= ALX_URL_CFTYPE_FILE,	\
				.handle.file	= stderr,		\
				.buf		= NULL,			\
				.still_running	= 0,			\
			}

#if defined(ALX_NO_PREFIX)
#define URL_stdin	ALX_URL_stdin
#define URL_stdout	ALX_URL_stdout
#define URL_stderr	ALX_URL_stderr
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_URL_Cftype_Type {
	ALX_URL_CFTYPE_NONE = 0,
	ALX_URL_CFTYPE_FILE = 1,
	ALX_URL_CFTYPE_CURL = 2
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/
struct	Alx_URL_Data {
	int	type;	/* type of handle */
	union {
		CURL	*curl;
		FILE	*file;
	} handle;			/* handle */
	struct Alx_Dyn_Buffer	*buf;	/* buffer to store cached data*/
	int	still_running;	/* Is background url fetch still in progress */
};


/******************************************************************************
 ******* typedef **************************************************************
 ******************************************************************************/
typedef struct Alx_URL_Data	ALX_URL_FILE;
#if defined(ALX_NO_PREFIX)
typedef struct Alx_URL_Data	URL_FILE;
#endif


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

