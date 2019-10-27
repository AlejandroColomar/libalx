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
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi8_s		(int8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read);
__attribute__((nonnull(1, 2), warn_unused_result))
int	alx_strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read);

__attribute__((nonnull, warn_unused_result))
int	alx_strtol_status	(const char *restrict str,
				 const char *restrict endptr,
				 int errno_after, int errno_before);


/******************************************************************************
 ******* static inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
static inline
int	strtoi8_s		(int8_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	return	alx_strtoi8_s(num, str, base, read);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
static inline
int	strtoi16_s		(int16_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	return	alx_strtoi16_s(num, str, base, read);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
static inline
int	strtoi32_s		(int32_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	return	alx_strtoi32_s(num, str, base, read);
}

__attribute__((always_inline, nonnull(1, 2), warn_unused_result))
static inline
int	strtoi64_s		(int64_t *restrict num,
				 const char *restrict str,
				 int base, ptrdiff_t *restrict read)
{
	return	alx_strtoi64_s(num, str, base, read);
}
#endif	/* defined(ALX_NO_PREFIX) */


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
