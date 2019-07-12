/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/stdlib/compare.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
int	alx_compare_ldbl(const void *a_ptr, const void *b_ptr);
int	alx_compare	(const void *a_ptr, const void *b_ptr);
int	alx_compare_f	(const void *a_ptr, const void *b_ptr);
int	alx_compare_uint(const void *a_ptr, const void *b_ptr);
int	alx_compare_int	(const void *a_ptr, const void *b_ptr);
int	alx_compare_u8	(const void *a_ptr, const void *b_ptr);
int	alx_compare_s8	(const void *a_ptr, const void *b_ptr);
int	alx_compare_u16	(const void *a_ptr, const void *b_ptr);
int	alx_compare_s16	(const void *a_ptr, const void *b_ptr);
int	alx_compare_u32	(const void *a_ptr, const void *b_ptr);
int	alx_compare_s32	(const void *a_ptr, const void *b_ptr);
int	alx_compare_u64	(const void *a_ptr, const void *b_ptr);
int	alx_compare_s64	(const void *a_ptr, const void *b_ptr);
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
