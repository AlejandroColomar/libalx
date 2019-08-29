/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtou_s.h"


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
	char	*endptr;
	int	rstatus;

	*num	= strtou(str, &endptr, base, 0, UINT8_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtou_status(rstatus);
}

int	alx_strtou16_s		(uint16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtou(str, &endptr, base, 0, UINT16_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtou_status(rstatus);
}

int	alx_strtou32_s		(uint32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtou(str, &endptr, base, 0, UINT32_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtou_status(rstatus);
}

int	alx_strtou64_s		(uint64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtou(str, &endptr, base, 0, UINT64_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtou_status(rstatus);
}


extern
int	alx_strtou_status	(int rstatus);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
