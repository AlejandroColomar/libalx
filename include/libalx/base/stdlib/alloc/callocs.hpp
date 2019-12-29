/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/alloc/callocs.hpp */


/******************************************************************************
 ******* about ****************************************************************
 ******************************************************************************/
/*
 * [[gnu::nonnull]]
 * int	callocs(type **restrict ptr, size_t nmemb);
 *
 * Read  <libalx/base/stdlib/alloc/callocs.h>  for documentation.
 */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdlib>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define alx_callocs(ptr, nmemb)	(					\
{									\
	auto	ptr_	= (ptr);					\
	void	*vp;							\
									\
	vp	= calloc(nmemb, sizeof(**ptr_));			\
	*ptr_	= static_cast<typeof(*ptr_)>(vp);			\
									\
	!(*ptr_);							\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define callocs(ptr, nmemb)	alx_callocs(ptr, nmemb)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/


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
