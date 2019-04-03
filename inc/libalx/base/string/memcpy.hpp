/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STRING_MEMCPY_HPP
#define ALX_STRING_MEMCPY_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <sys/types.h>

#include "libalx/base/stddef/restrict.hpp"


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
 ******* extern functions *****************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/
static inline	void	alx_memcpy_vds	(volatile void *restrict dest,
					const volatile void *restrict src,
					ssize_t n);
static inline	void	alx_memcpy_vd	(volatile void *restrict dest,
					const void *restrict src,
					ssize_t n);
static inline	void	alx_memcpy_vs	(void *restrict dest,
					const volatile void *restrict src,
					ssize_t n);


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/
static inline
void	alx_memcpy_vds	(volatile void *restrict dest,
			const volatile void *restrict src,
			ssize_t n)
{
	volatile unsigned char		*dest_c	= dest;
	const volatile unsigned char	*src_c	= src;

	while (n) {
		n--;
		dest_c[n] = src_c[n];
	}
}

static inline
void	alx_memcpy_vd	(volatile void *restrict dest,
			const void *restrict src,
			ssize_t n)
{
	volatile unsigned char	*dest_c	= dest;
	const unsigned char	*src_c	= src;

	while (n) {
		n--;
		dest_c[n] = src_c[n];
	}
}

static inline
void	alx_memcpy_vs	(void *restrict dest,
			const volatile void *restrict src,
			ssize_t n)
{
	unsigned char			*dest_c	= dest;
	const volatile unsigned char	*src_c	= src;

	while (n) {
		n--;
		dest_c[n] = src_c[n];
	}
}


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/string/memcpy.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
