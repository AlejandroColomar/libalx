/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/strto/strtoi_s.h"


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
	char	*endptr;
	int	rstatus;

	*num	= strtoi(str, &endptr, base, INT8_MIN, INT8_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtoi_status(rstatus);
}

int	alx_strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtoi(str, &endptr, base, INT16_MIN, INT16_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtoi_status(rstatus);
}

int	alx_strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtoi(str, &endptr, base, INT32_MIN, INT32_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtoi_status(rstatus);
}

int	alx_strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	char	*endptr;
	int	rstatus;

	*num	= strtoi(str, &endptr, base, INT64_MIN, INT64_MAX, &rstatus);
	if (read)
		*read	= endptr - str;

	return	alx_strtoi_status(rstatus);
}


extern
int	alx_strtoi_status	(int rstatus);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
