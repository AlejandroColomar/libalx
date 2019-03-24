/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/math/array_division.h"

#include <errno.h>
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
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_array_division_uint	(ptrdiff_t nmemb,
				unsigned dest[restrict nmemb],
				const unsigned src1[restrict nmemb],
				const unsigned src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_int	(ptrdiff_t nmemb,
				int dest[restrict nmemb],
				const int src1[restrict nmemb],
				const int src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u8	(ptrdiff_t nmemb,
				uint8_t dest[restrict nmemb],
				const uint8_t src1[restrict nmemb],
				const uint8_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s8	(ptrdiff_t nmemb,
				int8_t dest[restrict nmemb],
				const int8_t src1[restrict nmemb],
				const int8_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u16	(ptrdiff_t nmemb,
				uint16_t dest[restrict nmemb],
				const uint16_t src1[restrict nmemb],
				const uint16_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s16	(ptrdiff_t nmemb,
				int16_t dest[restrict nmemb],
				const int16_t src1[restrict nmemb],
				const int16_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u32	(ptrdiff_t nmemb,
				uint32_t dest[restrict nmemb],
				const uint32_t src1[restrict nmemb],
				const uint32_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s32	(ptrdiff_t nmemb,
				int32_t dest[restrict nmemb],
				const int32_t src1[restrict nmemb],
				const int32_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u64	(ptrdiff_t nmemb,
				uint64_t dest[restrict nmemb],
				const uint64_t src1[restrict nmemb],
				const uint64_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s64	(ptrdiff_t nmemb,
				int64_t dest[restrict nmemb],
				const int64_t src1[restrict nmemb],
				const int64_t src2[restrict nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto err_div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;

err_div0:
	errno	= ERANGE;
	return	-1;
}



/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
