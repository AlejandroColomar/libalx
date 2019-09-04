/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtoi_s.h"

#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


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
int	alx_strtoi8_s		(int8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp < INT8_MIN || tmp > INT8_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp < INT16_MIN || tmp > INT16_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	long		tmp;

	tmp	= strtol(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp < INT32_MIN || tmp > INT32_MAX)
		errno	= ERANGE;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}

int	alx_strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;

	*num	= strtol(str, &endptr, base);
	if (read)
		*read	= endptr - str;

	return	alx_strtol_status(str, endptr, errno, errno_before);
}


int	alx_strtol_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before)
{
	int	status;

	status	= 0;

	if (str == endptr) {
		status	= -ECANCELED;
		goto out;
	}

	while (isspace((unsigned char)*endptr))
		endptr++;
	if (*endptr) {
		status	= ENOTSUP;
		goto out;
	}

	/* EINVAL or ERANGE */
	if (errno_after) {
		status	= errno_after;
		goto out;
	}
out:
	if (!errno)
		errno	= errno_before;

	return	status;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
