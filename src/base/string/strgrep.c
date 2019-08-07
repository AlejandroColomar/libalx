/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strgrep.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "libalx/base/string/strchr.h"
#include "libalx/base/string/strstr.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static
ptrdiff_t	_strnfgrep_line		(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict]);
static
ptrdiff_t	_strsfgrep_line		(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len]);
static
ptrdiff_t	_strncasefgrep_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict]);
static
ptrdiff_t	_strscasefgrep_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len]);
static
ptrdiff_t	_strnfgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict]);
static
ptrdiff_t	_strsfgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len]);
static
ptrdiff_t	_strncasefgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict]);
static
ptrdiff_t	_strscasefgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len]);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
ptrdiff_t	alx_strnfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strnfgrep_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1])
			break;
	}
	memset(&dest[dpos], 0, size - dpos);

	if (!dest[dpos - 1])
		return	dpos - 1;
	return	dpos;
}

ptrdiff_t	alx_strlfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strnfgrep_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strsfgrep		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strsfgrep_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strncasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strncasefgrep_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1])
			break;
	}
	memset(&dest[dpos], 0, size - dpos);

	if (!dest[dpos - 1])
		return	dpos - 1;
	return	dpos;
}

ptrdiff_t	alx_strlcasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strncasefgrep_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strscasefgrep	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strscasefgrep_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strnfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strnfgrepv_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1])
			break;
	}
	memset(&dest[dpos], 0, size - dpos);

	if (!dest[dpos - 1])
		return	dpos - 1;
	return	dpos;
}

ptrdiff_t	alx_strlfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strnfgrepv_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strsfgrepv		(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strsfgrepv_line(llen, &dest[dpos], &src[spos], pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strncasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strncasefgrepv_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1])
			break;
	}
	memset(&dest[dpos], 0, size - dpos);

	if (!dest[dpos - 1])
		return	dpos - 1;
	return	dpos;
}

ptrdiff_t	alx_strlcasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strncasefgrepv_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}

ptrdiff_t	alx_strscasefgrepv	(ptrdiff_t size,
					 char dest[restrict size],
					 const char src[restrict size],
					 const char pattern[restrict size])
{
	ptrdiff_t	dpos;
	ptrdiff_t	spos;
	ptrdiff_t	llen;
	ptrdiff_t	plen;

	if (!size)
		return	0;

	dpos	= 0;
	spos	= 0;
	plen	= strnlen(pattern, size);

	while (spos < size) {
		llen = alx_strnchrnul(size - spos, &src[spos], '\n');
		if (llen < (size - spos))
			llen++;
		if (llen < plen)
			goto short_line;
		dpos += _strscasefgrepv_line(llen, &dest[dpos], &src[spos],
					 		pattern);
		spos += llen;
short_line:
		if (!src[spos - 1]) {
			if (!dest[dpos - 1])
				return	dpos - 1;
			if (dpos == size)
				dpos--;
			dest[dpos]	= '\0';
			return	dpos;
		}
	}
	if (dpos == size)
		dpos--;
	dest[dpos]	= '\0';

	return	-E2BIG;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static
ptrdiff_t	_strnfgrep_line		(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict])
{

	if (!strnstr(src, pattern, len))
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strsfgrep_line		(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len])
{

	if (alx_strsstr(len, src, pattern) < 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strncasefgrep_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict])
{

	if (alx_strncasestr(len, src, pattern) < 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strscasefgrep_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len])
{

	if (alx_strscasestr(len, src, pattern) < 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strnfgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict])
{

	if (strnstr(src, pattern, len))
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strsfgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len])
{

	if (alx_strsstr(len, src, pattern) >= 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strncasefgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict])
{

	if (alx_strncasestr(len, src, pattern) >= 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}

static
ptrdiff_t	_strscasefgrepv_line	(ptrdiff_t len,
					 char dest[restrict len],
					 const char src[restrict len],
					 const char pattern[restrict len])
{

	if (alx_strscasestr(len, src, pattern) >= 0)
		return	0;

	memcpy(dest, src, len);
	return	len;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
