/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdlib/search.h"

#include <stddef.h>
#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
ptrdiff_t	alx_search_uint	(ptrdiff_t nmemb,
				 const unsigned arr[static restrict nmemb],
				 unsigned x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_int	(ptrdiff_t nmemb,
				 const int arr[static restrict nmemb],
				 int x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u8	(ptrdiff_t nmemb,
				 const uint8_t arr[static restrict nmemb],
				 uint8_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s8	(ptrdiff_t nmemb,
				 const int8_t arr[static restrict nmemb],
				 int8_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u16	(ptrdiff_t nmemb,
				 const uint16_t arr[static restrict nmemb],
				 uint16_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s16	(ptrdiff_t nmemb,
				 const int16_t arr[static restrict nmemb],
				 int16_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u32	(ptrdiff_t nmemb,
				 const uint32_t arr[static restrict nmemb],
				 uint32_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s32	(ptrdiff_t nmemb,
				 const int32_t arr[static restrict nmemb],
				 int32_t x)
{
	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_u64	(ptrdiff_t nmemb,
				 const uint64_t arr[static restrict nmemb],
				 uint64_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}

ptrdiff_t	alx_search_s64	(ptrdiff_t nmemb,
				 const int64_t arr[static restrict nmemb],
				 int64_t x)
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (arr[i] == x)
			return	i;
	}

	return	-1;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
