/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strgrep.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "libalx/base/string/strchr.h"
#include "libalx/base/string/strstr.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	ptrdiff_t	_strnfgrep_line		(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict]);
static	ptrdiff_t	_strncasefgrep_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict]);
static	ptrdiff_t	_strnfgrepv_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict]);
static	ptrdiff_t	_strncasefgrepv_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict]);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
ptrdiff_t	alx_strnfgrep		(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	pos_dest;
	ptrdiff_t	pos_src;
	ptrdiff_t	line_len;

	pos_dest	= 0;
	pos_src		= 0;

	while (pos_src < size) {
		line_len = alx_strnchrnul(size - pos_src, &src[pos_src], '\n');
		if (line_len < size - pos_src)
			line_len++;
		pos_dest += _strnfgrep_line(line_len, &dest[pos_dest],
						&src[pos_src], pattern);
		pos_src += line_len;
		if (src[pos_src - 1] == '\0')
			break;
	}

	return	pos_dest;
}

ptrdiff_t	alx_strlfgrep		(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	dest_len;

	if (!size)
		return	0;

	dest_len	= alx_strnfgrep(size, dest, src, pattern) + 1;

	if (dest_len <= size)
		dest[dest_len - 1]	= '\0';
	else
		dest[size - 1]		= '\0';

	return	dest_len;
}

ptrdiff_t	alx_strncasefgrep	(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	pos_dest;
	ptrdiff_t	pos_src;
	ptrdiff_t	line_len;

	pos_dest	= 0;
	pos_src		= 0;

	while (pos_src < size) {
		line_len = alx_strnchrnul(size - pos_src, &src[pos_src], '\n');
		if (line_len < size - pos_src)
			line_len++;
		pos_dest += _strncasefgrep_line(line_len, &dest[pos_dest],
						&src[pos_src], pattern);
		pos_src += line_len;
		if (src[pos_src - 1] == '\0')
			break;
	}

	return	pos_dest;
}

ptrdiff_t	alx_strlcasefgrep	(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	dest_len;

	if (!size)
		return	0;

	dest_len	= alx_strncasefgrep(size, dest, src, pattern) + 1;

	if (dest_len <= size)
		dest[dest_len - 1]	= '\0';
	else
		dest[size - 1]		= '\0';

	return	dest_len;
}

ptrdiff_t	alx_strnfgrepv		(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	pos_dest;
	ptrdiff_t	pos_src;
	ptrdiff_t	line_len;

	pos_dest	= 0;
	pos_src		= 0;

	while (pos_src < size) {
		line_len = alx_strnchrnul(size - pos_src, &src[pos_src], '\n');
		if (line_len < size - pos_src)
			line_len++;
		pos_dest += _strnfgrepv_line(line_len, &dest[pos_dest],
						&src[pos_src], pattern);
		pos_src += line_len;
		if (src[pos_src - 1] == '\0')
			break;
	}

	return	pos_dest;
}

ptrdiff_t	alx_strlfgrepv		(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	dest_len;

	if (!size)
		return	0;

	dest_len	= alx_strnfgrepv(size, dest, src, pattern) + 1;

	if (dest_len <= size)
		dest[dest_len - 1]	= '\0';
	else
		dest[size - 1]		= '\0';

	return	dest_len;
}

ptrdiff_t	alx_strncasefgrepv	(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	pos_dest;
	ptrdiff_t	pos_src;
	ptrdiff_t	line_len;

	pos_dest	= 0;
	pos_src		= 0;

	while (pos_src < size) {
		line_len = alx_strnchrnul(size - pos_src, &src[pos_src], '\n');
		if (line_len < size - pos_src)
			line_len++;
		pos_dest += _strncasefgrepv_line(line_len, &dest[pos_dest],
						&src[pos_src], pattern);
		pos_src += line_len;
		if (src[pos_src - 1] == '\0')
			break;
	}

	return	pos_dest;
}

ptrdiff_t	alx_strlcasefgrepv	(ptrdiff_t size,
					char dest[restrict size],
					const char src[restrict size],
					const char pattern[restrict])
{
	ptrdiff_t	dest_len;

	if (!size)
		return	0;

	dest_len	= alx_strncasefgrepv(size, dest, src, pattern) + 1;

	if (dest_len <= size)
		dest[dest_len - 1]	= '\0';
	else
		dest[size - 1]		= '\0';

	return	dest_len;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	ptrdiff_t	_strnfgrep_line		(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict])
{

	if (!strnstr(src, pattern, len))
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static	ptrdiff_t	_strncasefgrep_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict])
{

	if (alx_strncasestr(len, src, pattern) < 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static	ptrdiff_t	_strnfgrepv_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict])
{

	if (strnstr(src, pattern, len))
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static	ptrdiff_t	_strncasefgrepv_line	(ptrdiff_t len,
						char dest[restrict len],
						const char src[restrict len],
						const char pattern[restrict])
{

	if (alx_strncasestr(len, src, pattern) >= 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
