/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strchr.h"

#include "ctype.h"
#include "string.h"

#include "libalx/base/stddef/size.h"


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
ptrdiff_t	alx_strcasechr		(const char *restrict str, char c)
{
	char	str_lower[strlen(str) + 1];
	char	c_lower;
	char	*p;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	p	= strchr(str_lower, c_lower);

	return	p - str_lower;
}

ptrdiff_t	alx_strrcasechr		(const char *restrict str, char c)
{
	char	str_lower[strlen(str) + 1];
	char	c_lower;
	char	*p;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	p	= strrchr(str_lower, c_lower);

	return	p - str_lower;
}

#if defined(_GNU_SOURCE)
ptrdiff_t	alx_strcasechrnul	(const char *restrict str, char c)
{
	char	str_lower[strlen(str) + 1];
	char	c_lower;
	char	*p;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	p	= strchrnul(str_lower, c_lower);

	return	p - str_lower;
}
#endif

ptrdiff_t	alx_strrcasechrnul	(const char *restrict str, char c)
{
	char	str_lower[strlen(str) + 1];
	char	c_lower;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	return	alx_strrchrnul(str_lower, c_lower);
}

ptrdiff_t	alx_strncasechr		(ptrdiff_t size,
					const char str[restrict size],
					char c)
{
	char	str_lower[size];
	char	c_lower;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	return	alx_strnchr(size, str_lower, c_lower);
}

#if defined(_GNU_SOURCE)
ptrdiff_t	alx_strnrcasechr	(ptrdiff_t size,
					const char str[restrict size],
					char c)
{
	char	str_lower[size];
	char	c_lower;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	return	alx_strnrchr(size, str_lower, c_lower);
}
#endif

ptrdiff_t	alx_strncasechrnul	(ptrdiff_t size,
					const char str[restrict size],
					char c)
{
	char	str_lower[size];
	char	c_lower;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	return	alx_strnchrnul(size, str_lower, c_lower);
}

#if defined(_GNU_SOURCE)
ptrdiff_t	alx_strnrcasechrnul	(ptrdiff_t size,
					const char str[restrict size],
					char c)
{
	char	str_lower[size];
	char	c_lower;

	for (ptrdiff_t i = 0; i < ARRAY_SSIZE(str_lower); i++) {
		str_lower[i]	= tolower((unsigned char)str[i]);
		if (!str_lower[i])
			break;
	}
	c_lower	= tolower((unsigned char)c);

	return	alx_strnrchrnul(size, str_lower, c_lower);
}
#endif


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
