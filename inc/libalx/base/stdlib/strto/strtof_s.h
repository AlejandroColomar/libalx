/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtof_s.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
/*
 * `errno` needs to be cleared before calling these functions.  If not, false
 * negatives could happen (the function succeds, but it reports error).
 */
__attribute__((nonnull, warn_unused_result))
inline
int	alx_strtod_s	(double *restrict num, const char *restrict str);
__attribute__((nonnull, warn_unused_result))
inline
int	alx_strtof_s	(float *restrict num, const char *restrict str);
__attribute__((nonnull, warn_unused_result))
inline
int	alx_strtold_s	(long double *restrict num, const char *restrict str);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
int	alx_strtod_s	(double *restrict num, const char *restrict str)
{
	char	*endptr;

	*num	= strtod(str, &endptr);

	if (errno == ERANGE)
		return	ERANGE;
	if (*endptr != '\0')
		return	ENOTSUP;
	if (str == endptr)
		return	-ECANCELED;

	return	0;
}

inline
int	alx_strtof_s	(float *restrict num, const char *restrict str)
{
	char	*endptr;

	*num	= strtof(str, &endptr);

	if (errno == ERANGE)
		return	ERANGE;
	if (*endptr != '\0')
		return	ENOTSUP;
	if (str == endptr)
		return	-ECANCELED;

	return	0;
}

inline
int	alx_strtold_s	(long double *restrict num, const char *restrict str)
{
	char	*endptr;

	*num	= strtold(str, &endptr);

	if (errno == ERANGE)
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
