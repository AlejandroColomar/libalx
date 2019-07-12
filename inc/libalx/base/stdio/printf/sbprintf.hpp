/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdio/printf/sbprintf.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/size.hpp"
#include "libalx/base/stdio/printf/snprintfs.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * int	alx_sbprintf(char buff[restrict], ptrdiff_t *restrict written,
 *		     const char *restrict fmt, ...);
 */
#define alx_sbprintf(buff, written, fmt, ...)				\
	alx_snprintfs(buff, written, ARRAY_SIZE(buff), fmt, ##__VA_ARGS__)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
