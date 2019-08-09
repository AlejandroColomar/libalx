/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/errno/error.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * void	alx_perror(const char *restrict str);
 */
#define alx_perror(str)		do					\
{									\
	alx_perror__(__FILE__, __LINE__, __func__, str);		\
} while (0)

/*
 * [[noreturn]]
 * void	alx_error(int status, const char *restrict str);
 */
#define alx_error(status, str)	do					\
{									\
	alx_error__(status, __FILE__, __LINE__, __func__, str);		\
} while (0)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull(1, 3)]]
void	alx_perror__	(const char *restrict file, int line,
			 const char *restrict func, const char *restrict str);
[[noreturn]][[gnu::nonnull(2, 4)]]
void	alx_error__	(int status, const char *restrict file, int line,
			 const char *restrict func, const char *restrict str);
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
