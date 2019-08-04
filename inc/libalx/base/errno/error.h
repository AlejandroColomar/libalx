/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/errno/error.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/*
 * int	alx_perror(const char *restrict str);
 */
#define alx_perror(str)		do					\
{									\
	alx_perror__(__FILE__, __LINE__, __func__, str);		\
} while (0)

/*
 * noreturn
 * void	alx_error(int status, const char *restrict str);
 */
#define alx_error(status, str)	do					\
{									\
	alx_error__(status, __FILE__, __LINE__, __func__, str);		\
} while (0)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
__attribute__((nonnull(1, 3)))
inline
void	alx_perror__	(const char *restrict file, int line,
			 const char *restrict func, const char *restrict str);
__attribute__((nonnull(2, 4)))
inline noreturn
void	alx_error__	(int status, const char *restrict file, int line,
			 const char *restrict func, const char *restrict str);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/
inline
void	alx_perror__	(const char *restrict file, int line,
		 	 const char *restrict func, const char *restrict str)
{

	fprintf(stderr, "%s:\n", program_invocation_name);
	fprintf(stderr, "	%s:%i:\n", file, line);
	fprintf(stderr, "	%s():\n", func);
	if (str)
		fprintf(stderr, "		%s\n", str);
	fprintf(stderr, "	E%i -	%s\n", errno, strerror(errno));
}

inline noreturn
void	alx_error__	(int status, const char *restrict file, int line,
			 const char *restrict func, const char *restrict str)
{

	alx_perror__(file, line, func, str);
	exit(status);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
