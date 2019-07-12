/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/array_split_pos_neg.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>
#include <stdint.h>


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
 ******* extern functions *****************************************************
 ******************************************************************************/
void	alx_array_split_pos_neg_ldbl	(ptrdiff_t nmemb,
				const long double mix[restrict nmemb],
				long double pos[restrict nmemb],
				long double neg[restrict nmemb]);
void	alx_array_split_pos_neg		(ptrdiff_t nmemb,
				const double mix[restrict nmemb],
				double pos[restrict nmemb],
				double neg[restrict nmemb]);
void	alx_array_split_pos_neg_flt	(ptrdiff_t nmemb,
				const float mix[restrict nmemb],
				float pos[restrict nmemb],
				float neg[restrict nmemb]);
void	alx_array_split_pos_neg_int	(ptrdiff_t nmemb,
				const int mix[restrict nmemb],
				int pos[restrict nmemb],
				int neg[restrict nmemb]);
void	alx_array_split_pos_neg_s8	(ptrdiff_t nmemb,
				const int8_t mix[restrict nmemb],
				int8_t pos[restrict nmemb],
				int8_t neg[restrict nmemb]);
void	alx_array_split_pos_neg_s16	(ptrdiff_t nmemb,
				const int16_t mix[restrict nmemb],
				int16_t pos[restrict nmemb],
				int16_t neg[restrict nmemb]);
void	alx_array_split_pos_neg_s32	(ptrdiff_t nmemb,
				const int32_t mix[restrict nmemb],
				int32_t pos[restrict nmemb],
				int32_t neg[restrict nmemb]);
void	alx_array_split_pos_neg_s64	(ptrdiff_t nmemb,
				const int64_t mix[restrict nmemb],
				int64_t pos[restrict nmemb],
				int64_t neg[restrict nmemb]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
