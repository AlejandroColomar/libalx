/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_STDLIB_ALLOC_MALLOCS_H
#define ALX_STDLIB_ALLOC_MALLOCS_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define mallocs(ptr, nmemb)	(					\
{									\
	ptrdiff_t	nmemb_	= (nmemb);				\
	__auto_type	ptr_	= (ptr);				\
	int		err_;						\
									\
	err_	= 0;							\
	if (ptr_ == NULL) {						\
		errno	= EINVAL;					\
		err_	= EINVAL;					\
		goto ret_;						\
	}								\
	if (nmemb_ < 0) {						\
		*ptr_	= NULL;						\
		errno	= EOVERFLOW;					\
		err_	= -EOVERFLOW;					\
		goto ret_;						\
	}								\
	if (nmemb_ > (PTRDIFF_MAX / (ptrdiff_t)sizeof(**ptr_))) {	\
		*ptr_	= NULL;						\
		errno	= EOVERFLOW;					\
		err_	= EOVERFLOW;					\
		goto ret_;						\
	}								\
									\
	*ptr_	= malloc(sizeof(**ptr_) * nmemb_);			\
	if (!(*ptr_))							\
		err_	= ENOMEM;					\
ret_:									\
	err_;								\
}									\
)


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


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/stdlib/alloc/mallocs.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
