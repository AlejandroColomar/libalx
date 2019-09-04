/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtof_s.h"

#include <ctype.h>
#include <errno.h>
#include <stddef.h>
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


extern
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
