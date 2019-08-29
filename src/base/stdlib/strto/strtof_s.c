/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtof_s.h"


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
				 const char *restrict endptr, int _errno);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_strtod_s	(double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	char	*endptr;

	*num	= strtod(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno);
}

int	alx_strtof_s	(float *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	char	*endptr;

	*num	= strtof(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno);
}

int	alx_strtold_s	(long double *restrict num, const char *restrict str,
			 ptrdiff_t *restrict read)
{
	char	*endptr;

	*num	= strtold(str, &endptr);
	if (read)
		*read	= endptr - str;

	return	alx_strtof_status(str, endptr, errno);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
static
int	alx_strtof_status	(const char *restrict str,
				 const char *restrict endptr, int _errno)
{

	if (_errno == ERANGE)
		return	ERANGE;
	if (*endptr != '\0')
		return	ENOTSUP;
	if (str == endptr)
		return	-ECANCELED;

	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
