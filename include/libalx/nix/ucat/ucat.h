/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	BSD-2-Clause			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/nix/ucat/ucat.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>

#include "libalx/extra/curl/fcurl/URL_FILE.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* TODO:  cat flags */
#if 0
#ifdef BOOTSTRAP_CAT
#define SUPPORTED_FLAGS "lu"
#else
#define SUPPORTED_FLAGS "belnstuv"
#endif

#define FLAG_b	(0x0001)
#define FLAG_e	(0x0002)
#define FLAG_l	(0x0004)
#define FLAG_n	(0x0008)
#define FLAG_s	(0x0010)
#define FLAG_t	(0x0020)
#define FLAG_v	(0x0040)
#endif



/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
__attribute__((warn_unused_result))
int	alx_nix_ucat	(const char *url, uint32_t flags);
__attribute__((nonnull))
void	alx_nix_ucat__	(FILE *restrict ostream, ALX_URL_FILE *restrict istream,
			 uint32_t flags);


/******************************************************************************
 ******* always_inline ********************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
__attribute__((always_inline, warn_unused_result))
inline
int	nix_ucat	(const char *url, uint32_t flags)
{
	return	alx_nix_ucat(url);
}
__attribute__((always_inline, nonnull))
inline
void	nix_ucat__	(FILE *restrict ostream, ALX_URL_FILE *restrict istream,
			 uint32_t flags)
{
	return	alx_nix_ucat__(ostream, istream);
}
#endif


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

