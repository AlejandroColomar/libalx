/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/strto/strtou_s.h */


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
int	alx_strtou8_s	(uint8_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtou16_s	(uint16_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtou32_s	(uint32_t *restrict num, const char *restrict str,
			 int base);
__attribute__((nonnull))
inline
int	alx_strtou64_s	(uint64_t *restrict num, const char *restrict str,
			 int base);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
int	alx_strtou8_s	(uint8_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtou(str, NULL, base, 0, UINT8_MAX, &rstatus);

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
int	alx_strtou16_s	(uint16_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtou(str, NULL, base, 0, UINT16_MAX, &rstatus);

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
int	alx_strtou32_s	(uint32_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtou(str, NULL, base, 0, UINT32_MAX, &rstatus);

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
int	alx_strtou64_s	(uint64_t *restrict num, const char *restrict str,
			 int base)
{
	int	rstatus;

	*num	= strtou(str, NULL, base, 0, UINT64_MAX, &rstatus);

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
