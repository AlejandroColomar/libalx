/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/string/strstr.h"

#include <ctype.h>
#include <stddef.h>
#include <string.h>


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


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
ptrdiff_t	alx_strncasestr		(ptrdiff_t buff_size,
					const char str[restrict buff_size],
					const char pattern[restrict])
{
	char	str_lower[buff_size];
	char	pat_lower[buff_size];
	char	*p;

	if (!buff_size)
		return	-1;
	if (!pattern[0])
		return	0;

	for (ptrdiff_t i = 0; i < buff_size; i++) {
		str_lower[i]	= tolower(str[i]);
		if (!str_lower[i])
			break;
	}
	for (ptrdiff_t i = 0; i < buff_size; i++) {
		pat_lower[i]	= tolower(pattern[i]);
		if (!pat_lower[i])
			break;
	}

	p	= strnstr(str_lower, pat_lower, buff_size);

	if (!p)
		return	-1;
	return	p - str_lower;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
