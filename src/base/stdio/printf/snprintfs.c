/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdio/printf/snprintfs.h"

#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>


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
int	alx_snprintfs	(char str[restrict /*nmemb*/],
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, ...)
{
	va_list	ap;
	int	status;

	va_start(ap, format);
	status	= alx_vsnprintfs(str, written, nmemb, format, ap);
	va_end(ap);

	return	status;
}

int	alx_vsnprintfs	(char str[restrict /*nmemb*/],
			 ptrdiff_t *restrict written, ptrdiff_t nmemb,
			 const char *restrict format, va_list ap)
{
	int	len;

	if (nmemb <= 0)
		goto ovf;

	len	= vsnprintf(str, nmemb, format, ap);

	if (len < 0)
		goto err;
	if (len >= nmemb)
		goto trunc;
	if (written)
		*written = len;

	return	0;
trunc:
	if (written)
		*written = nmemb - 1;
	errno	= ENOBUFS;
	return	1;
ovf:
	errno	= EOVERFLOW;
err:	if (written)
		*written = 0;
	return	-1;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
