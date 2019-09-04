/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtof_s.h"

#include <ctype.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
__attribute__((nonnull, warn_unused_result))
static
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_strtod_s	(double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtod(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}

int	alx_strtof_s	(float *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtof(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}

int	alx_strtold_s	(long double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;

	errno	= 0;
	*num	= strtold(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno, errno_before);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_strtof_status	(const char *restrict str,
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
	if (*endptr != '\0') {
		status	= ENOTSUP;
		goto out;
	}

	if (errno_after == ERANGE) {
		status	= ERANGE;
		goto out;
	}
out:
	if (!errno)
		errno	= errno_before;

	return	status;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
