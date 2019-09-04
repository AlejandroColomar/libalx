/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtou_s.h"

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
int	alx_strtou8_s		(uint8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp > UINT8_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp > UINT16_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;
	unsigned long	tmp;

	tmp	= strtoul(str, &endptr, base);
	*num	= tmp;
	if (read)
		*read	= endptr - str;
	if (tmp > UINT32_MAX)
		errno	= ERANGE;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}

int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	const int	errno_before = errno;
	char		*endptr;

	*num	= strtoul(str, &endptr, base);
	if (read)
		*read	= endptr - str;

	return	alx_strtoul_status(str, endptr, errno, errno_before);
}


extern
int	alx_strtoul_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
