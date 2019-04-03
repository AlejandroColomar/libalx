/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STRING_STRCHR_HPP
#define ALX_STRING_STRCHR_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstring>


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
extern	"C"
{
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char str[], char c);
/* Missing memrchr() */
#if 0
static inline	ptrdiff_t	alx_strnrchr	(ptrdiff_t size,
					const char str[], char c);
#endif
static inline	ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char str[], char c);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char str[], char c)
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
					const char str[], char c)
{
	const char	*p = memrchr(str, c, strnlen(str, size));

	if (!p)
		return	-1;
	return	p - str;
}
#endif

static inline
ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char str[], char c)
{
	const char	*p = memchr(str, c, strnlen(str, size));

	if (!p)
		return	size;
	return	p - str;
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/string/strchr.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
