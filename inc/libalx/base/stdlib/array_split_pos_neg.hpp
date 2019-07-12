/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/array_split_pos_neg.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>
#include <cstdint>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
void	alx_array_split_pos_neg_ldbl	(ptrdiff_t nmemb,
					 const long double *restrict mix,
					 long double *restrict pos,
					 long double *restrict neg);
void	alx_array_split_pos_neg		(ptrdiff_t nmemb,
					 const double *restrict mix,
					 double *restrict pos,
					 double *restrict neg);
void	alx_array_split_pos_neg_flt	(ptrdiff_t nmemb,
					 const float *restrict mix,
					 float *restrict pos,
					 float *restrict neg);
void	alx_array_split_pos_neg_int	(ptrdiff_t nmemb,
					 const int *restrict mix,
					 int *restrict pos,
					 int *restrict neg);
void	alx_array_split_pos_neg_s8	(ptrdiff_t nmemb,
					 const int8_t *restrict mix,
					 int8_t *restrict pos,
					 int8_t *restrict neg);
void	alx_array_split_pos_neg_s16	(ptrdiff_t nmemb,
					 const int16_t *restrict mix,
					 int16_t *restrict pos,
					 int16_t *restrict neg);
void	alx_array_split_pos_neg_s32	(ptrdiff_t nmemb,
					 const int32_t *restrict mix,
					 int32_t *restrict pos,
					 int32_t *restrict neg);
void	alx_array_split_pos_neg_s64	(ptrdiff_t nmemb,
					 const int64_t *restrict mix,
					 int64_t *restrict pos,
					 int64_t *restrict neg);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
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
