/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/maximum.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define	ALX_MAX(a, b) (							\
{									\
	auto	a_	= (a);						\
	auto	b_	= (b);						\
									\
	(a_ > b_) ? a_ : b_;						\
}									\
)


/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define MAX(a, b)	ALX_MAX(a, b)
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_ldbl(ptrdiff_t nmemb,
				 const long double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum	(ptrdiff_t nmemb,
				 const double *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_f	(ptrdiff_t nmemb,
				 const float *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_uint(ptrdiff_t nmemb,
				 const unsigned *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_int	(ptrdiff_t nmemb,
				 const int *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_u8	(ptrdiff_t nmemb,
				 const uint8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_s8	(ptrdiff_t nmemb,
				 const int8_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_u16	(ptrdiff_t nmemb,
				 const uint16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_s16	(ptrdiff_t nmemb,
				 const int16_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_u32	(ptrdiff_t nmemb,
				 const uint32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_s32	(ptrdiff_t nmemb,
				 const int32_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_u64	(ptrdiff_t nmemb,
				 const uint64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_s64	(ptrdiff_t nmemb,
				 const int64_t *restrict arr);
[[gnu::nonnull]][[gnu::pure]]
ptrdiff_t	alx_maximum_pdif(ptrdiff_t nmemb,
				 const ptrdiff_t *restrict arr);
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
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
