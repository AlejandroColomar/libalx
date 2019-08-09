/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/array_division.h"

#include <errno.h>
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
extern
void	alx_array_division_ldbl	(ptrdiff_t nmemb,
				 long double dest[static nmemb],
				 const long double src1[static nmemb],
				 const long double src2[static nmemb]);
extern
void	alx_array_division	(ptrdiff_t nmemb,
				 double dest[static nmemb],
				 const double src1[static nmemb],
				 const double src2[static nmemb]);
extern
void	alx_array_division_flt	(ptrdiff_t nmemb,
				 float dest[static nmemb],
				 const float src1[static nmemb],
				 const float src2[static nmemb]);

int	alx_array_division_uint	(ptrdiff_t nmemb,
				 unsigned dest[static nmemb],
				 const unsigned src1[static nmemb],
				 const unsigned src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_int	(ptrdiff_t nmemb,
				 int dest[static nmemb],
				 const int src1[static nmemb],
				 const int src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u8	(ptrdiff_t nmemb,
				 uint8_t dest[static nmemb],
				 const uint8_t src1[static nmemb],
				 const uint8_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s8	(ptrdiff_t nmemb,
				 int8_t dest[static nmemb],
				 const int8_t src1[static nmemb],
				 const int8_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u16	(ptrdiff_t nmemb,
				 uint16_t dest[static nmemb],
				 const uint16_t src1[static nmemb],
				 const uint16_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s16	(ptrdiff_t nmemb,
				 int16_t dest[static nmemb],
				 const int16_t src1[static nmemb],
				 const int16_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u32	(ptrdiff_t nmemb,
				 uint32_t dest[static nmemb],
				 const uint32_t src1[static nmemb],
				 const uint32_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s32	(ptrdiff_t nmemb,
				 int32_t dest[static nmemb],
				 const int32_t src1[static nmemb],
				 const int32_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_u64	(ptrdiff_t nmemb,
				 uint64_t dest[static nmemb],
				 const uint64_t src1[static nmemb],
				 const uint64_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}

int	alx_array_division_s64	(ptrdiff_t nmemb,
				 int64_t dest[static nmemb],
				 const int64_t src1[static nmemb],
				 const int64_t src2[static nmemb])
{

	for (ptrdiff_t i = 0; i < nmemb; i++) {
		if (!src2[i])
			goto div0;
		dest[i]	= src1[i] / src2[i];
	}

	return	0;
div0:
	errno	= ERANGE;
	return	-1;
}



/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
