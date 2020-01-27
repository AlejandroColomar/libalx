/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	BSD-2-Clause			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/curl/fcurl/fgetc.h"

#include <errno.h>
#include <stdio.h>

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
static
int	url_fgetc__	(ALX_URL_FILE *restrict stream);
static
int	url_ungetc__	(int c, ALX_URL_FILE *restrict stream);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_url_fgetc	(ALX_URL_FILE *restrict stream)
{

	switch (stream->type) {
	case ALX_URL_CFTYPE_FILE:
		return	fgetc(stream->handle.file);
	case ALX_URL_CFTYPE_CURL:
		return	url_fgetc__(stream);
	default:
		errno	= EOF;
		return	0;
	}
}

int	alx_url_ungetc	(int c, ALX_URL_FILE *restrict stream)
{

	if (c == EOF)
		return	EOF;

	switch (stream->type) {
	case ALX_URL_CFTYPE_FILE:
		return	ungetc(c, stream->handle.file);
	case ALX_URL_CFTYPE_CURL:
		return	url_ungetc__(c, stream);
	default:
		errno	= EOF;
		return	0;
	}
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	url_fgetc__	(ALX_URL_FILE *restrict stream)
{
	unsigned char	c;

	alx_url_fill_buffer__(stream, sizeof(c));
	if (!stream->buf->written)
		return	EOF;

	if (alx_dynbuf_read(&c, sizeof(c), stream->buf, 0))
		return	EOF;

	alx_dynbuf_consume(stream->buf, sizeof(c));

	return	c;
}

static
int	url_ungetc__	(int c, ALX_URL_FILE *restrict stream)
{
	unsigned char	ch;

	ch	= c;
	if (alx_dynbuf_insert(stream->buf, 0, &ch, sizeof(ch)))
		return	EOF;

	return	c;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

