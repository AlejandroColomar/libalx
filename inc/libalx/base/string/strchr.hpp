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

#include "libalx/base/stddef/restrict.hpp"


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
ptrdiff_t	alx_strcasechr		(const char *restrict str, char c);
ptrdiff_t	alx_strrcasechr		(const char *restrict str, char c);
ptrdiff_t	alx_strcasechrnul	(const char *restrict str, char c);
ptrdiff_t	alx_strrcasechrnul	(const char *restrict str, char c);
ptrdiff_t	alx_strncasechr		(ptrdiff_t size,
					const char *restrict str,
					char c);
#if defined(_GNU_SOURCE)
ptrdiff_t	alx_strnrcasechr	(ptrdiff_t size,
					const char *restrict str,
					char c);
#endif
ptrdiff_t	alx_strncasechrnul	(ptrdiff_t size,
					const char *restrict str,
					char c);
#if defined(_GNU_SOURCE)
ptrdiff_t	alx_strnrcasechrnul	(ptrdiff_t size,
					const char *restrict str,
					char c);
#endif
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	ptrdiff_t	alx_strrchrnul	(const char *restrict str,
					char c);
static inline	ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char *restrict str, char c);
#if defined(_GNU_SOURCE)
static inline	ptrdiff_t	alx_strnrchr	(ptrdiff_t size,
					const char *restrict str, char c);
#endif
static inline	ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char *restrict str, char c);
#if defined(_GNU_SOURCE)
static inline	ptrdiff_t	alx_strnrchrnul	(ptrdiff_t size,
					const char *restrict str, char c);
#endif


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
ptrdiff_t	alx_strrchrnul	(const char *restrict str, char c)
{
	const char	*p = strrchr(str, c);

	if (!p)
		return	strlen(str);
	return	p - str;
}

static inline
ptrdiff_t	alx_strnchr	(ptrdiff_t size,
					const char *restrict str, char c)
{
	const char	*p = memchr(str, c, strnlen(str, size));

	if (!p)
		return	-1;
	return	p - str;
}

#if defined(_GNU_SOURCE)
static inline
ptrdiff_t	alx_strnrchr	(ptrdiff_t size,
					const char *restrict str, char c)
{
	const char	*p = memrchr(str, c, strnlen(str, size));

	if (!p)
		return	-1;
	return	p - str;
}
#endif

static inline
ptrdiff_t	alx_strnchrnul	(ptrdiff_t size,
					const char *restrict str, char c)
{
	const char	*p = memchr(str, c, strnlen(str, size));

	if (!p)
		return	size;
	return	p - str;
}

#if defined(_GNU_SOURCE)
static inline
ptrdiff_t	alx_strnrchrnul	(ptrdiff_t size,
					const char *restrict str, char c)
{
	const char	*p = memrchr(str, c, strnlen(str, size));

	if (!p)
		return	size;
	return	p - str;
}
#endif


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/string/strchr.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
