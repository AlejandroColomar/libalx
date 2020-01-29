/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/libgen/basename.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdio.h>


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
__attribute__((nonnull))
int	alx_basename_s	(char dest[static restrict FILENAME_MAX],
			 const char *restrict path);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, nonnull))
inline
int	basename_s	(char dest[static restrict FILENAME_MAX],
			 const char *restrict path)
{
	return	alx_basename_s(dest, path);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
