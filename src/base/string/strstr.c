/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strstr.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>


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
ptrdiff_t alx_strsstr		(ptrdiff_t size,
				 const char str[static restrict size],
				 const char pattern[static restrict size])
{
	const ptrdiff_t	plen = strnlen(pattern, size);
	ptrdiff_t	slen = strnlen(str, size);
	const char	*p;

	if (!plen)
		return	0;
	if (!slen)
		return	-1;

	p	= str;
	while (slen >= plen) {
		slen--;
		if (!memcmp(p, pattern, plen))
			return	p - str;
		p++;
	}
	return	-1;
}

ptrdiff_t alx_strncasestr	(ptrdiff_t size,
				 const char str[static restrict size],
				 const char pattern[restrict])
{
	const ptrdiff_t	slen = strnlen(str, size);
	const ptrdiff_t	plen = strlen(pattern);
	char		str_lower[slen + 1];
	char		pat_lower[plen + 1];
	const char	*p;

	if (!plen)
		return	0;
	if (!slen)
		return	-1;

	for (ptrdiff_t i = 0; i < slen; i++)
		str_lower[i]	= tolower((unsigned char)str[i]);
	str_lower[slen]	= '\0';
	for (ptrdiff_t i = 0; i < plen; i++)
		pat_lower[i]	= tolower((unsigned char)pattern[i]);
	pat_lower[plen]	= '\0';

	p	= strstr(str_lower, pat_lower);

	if (!p)
		return	-1;
	return	p - str_lower;
}

ptrdiff_t alx_strscasestr	(ptrdiff_t size,
				 const char str[static restrict size],
				 const char pattern[static restrict size])
{
	const ptrdiff_t	slen = strnlen(str, size);
	const ptrdiff_t	plen = strnlen(pattern, size);
	char		str_lower[slen + 1];
	char		pat_lower[plen + 1];
	const char	*p;

	if (!plen)
		return	0;
	if (!slen)
		return	-1;

	for (ptrdiff_t i = 0; i < slen; i++)
		str_lower[i]	= tolower((unsigned char)str[i]);
	str_lower[slen]	= '\0';
	for (ptrdiff_t i = 0; i < plen; i++)
		pat_lower[i]	= tolower((unsigned char)pattern[i]);
	pat_lower[plen]	= '\0';

	p	= strstr(str_lower, pat_lower);

	if (!p)
		return	-1;
	return	p - str_lower;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
