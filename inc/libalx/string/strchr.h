/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STRING_STRCHR_H
#define ALX_STRING_STRCHR_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char str[restrict size], char c);
/* Missing memrchr() */
#if 0
static inline	ptrdiff_t	alx_strnrchr	(ptrdiff_t size,
					const char str[restrict size], char c);
#endif
static inline	ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char str[restrict size], char c);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char str[restrict size], char c)
{
	const char	*p = memchr(str, c, strnlen(str, size));

	if (!p)
		return	-1;
	return	p - str;
}

/* Missing memrchr() */
#if 0
static inline
ptrdiff_t	alx_strnrchr	(ptrdiff_t size,
					const char str[restrict size], char c)
{
	const char	*p = memrchr(str, c, strnlen(str, size));

	if (!p)
		return	-1;
	return	p - str;
}
#endif

static inline
ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char str[restrict size], char c)
{
	const char	*p = memchr(str, c, strnlen(str, size));

	if (!p)
		return	size;
	return	p - str;
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/string/strchr.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
