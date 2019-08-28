/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtoi_s.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>


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
__attribute__((nonnull))
inline
int	alx_strtoi8_s	(int8_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtoi16_s	(int16_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtoi32_s	(int32_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtoi64_s	(int64_t *restrict num, const char *restrict str,
			 int base);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
int	alx_strtoi8_s	(int8_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtoi(str, NULL, base, INT8_MIN, INT8_MAX, &rstatus);

	switch (rstatus) {
	case 0:
		return	0;
	case ENOTSUP:
		return	ENOTSUP;
	case ECANCELED:
		return	-ECANCELED;
	case EINVAL:
		return	-EINVAL;
	case ERANGE:
		return	-ERANGE;
	default:
		return	-rstatus;
	}
}

inline
int	alx_strtoi16_s	(int16_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtoi(str, NULL, base, INT16_MIN, INT16_MAX, &rstatus);

	switch (rstatus) {
	case 0:
		return	0;
	case ENOTSUP:
		return	ENOTSUP;
	case ECANCELED:
		return	-ECANCELED;
	case EINVAL:
		return	-EINVAL;
	case ERANGE:
		return	-ERANGE;
	default:
		return	-rstatus;
	}
}

inline
int	alx_strtoi32_s	(int32_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtoi(str, NULL, base, INT32_MIN, INT32_MAX, &rstatus);

	switch (rstatus) {
	case 0:
		return	0;
	case ENOTSUP:
		return	ENOTSUP;
	case ECANCELED:
		return	-ECANCELED;
	case EINVAL:
		return	-EINVAL;
	case ERANGE:
		return	-ERANGE;
	default:
		return	-rstatus;
	}
}

inline
int	alx_strtoi64_s	(int64_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtoi(str, NULL, base, INT64_MIN, INT64_MAX, &rstatus);

	switch (rstatus) {
	case 0:
		return	0;
	case ENOTSUP:
		return	ENOTSUP;
	case ECANCELED:
		return	-ECANCELED;
	case EINVAL:
		return	-EINVAL;
	case ERANGE:
		return	-ERANGE;
	default:
		return	-rstatus;
	}
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
