/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdlib/array_split_pos_neg.h"

#include <stdint.h>
#include <string.h>

#include <sys/types.h>


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
void	alx_array_split_pos_neg_ldbl	(ssize_t n,
				const long double mix[restrict n],
				long double pos[restrict n],
				long double neg[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (mix[i] > 0) {
			pos[i]	= mix[i];
			neg[i]	= 0;
		} else {
			neg[i]	= mix[i];
			pos[i]	= 0;
		}
	}
}

void	alx_array_split_pos_neg		(ssize_t n,
				const double mix[restrict n],
				double pos[restrict n],
				double neg[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (mix[i] > 0) {
			pos[i]	= mix[i];
			neg[i]	= 0;
		} else {
			neg[i]	= mix[i];
			pos[i]	= 0;
		}
	}
}

void	alx_array_split_pos_neg_flt	(ssize_t n,
				const float mix[restrict n],
				float pos[restrict n],
				float neg[restrict n])
{

	for (ssize_t i = 0; i < n; i++) {
		if (mix[i] > 0) {
			pos[i]	= mix[i];
			neg[i]	= 0;
		} else {
			neg[i]	= mix[i];
			pos[i]	= 0;
		}
	}
}

void	alx_array_split_pos_neg_int	(ssize_t n,
				const int mix[restrict n],
				int pos[restrict n],
				int neg[restrict n])
{

	memset(pos, 0, sizeof(pos[0]) * n);
	memset(neg, 0, sizeof(neg[0]) * n);

	for (ssize_t i = 0; i < n; i++) {
		if (!mix[i])
			continue;
		if (mix[i] > 0)
			pos[i]	= mix[i];
		else
			neg[i]	= mix[i];
	}
}

void	alx_array_split_pos_neg_s8	(ssize_t n,
				const int8_t mix[restrict n],
				int8_t pos[restrict n],
				int8_t neg[restrict n])
{

	memset(pos, 0, sizeof(pos[0]) * n);
	memset(neg, 0, sizeof(neg[0]) * n);

	for (ssize_t i = 0; i < n; i++) {
		if (!mix[i])
			continue;
		if (mix[i] > 0)
			pos[i]	= mix[i];
		else
			neg[i]	= mix[i];
	}
}

void	alx_array_split_pos_neg_s16	(ssize_t n,
				const int16_t mix[restrict n],
				int16_t pos[restrict n],
				int16_t neg[restrict n])
{

	memset(pos, 0, sizeof(pos[0]) * n);
	memset(neg, 0, sizeof(neg[0]) * n);

	for (ssize_t i = 0; i < n; i++) {
		if (!mix[i])
			continue;
		if (mix[i] > 0)
			pos[i]	= mix[i];
		else
			neg[i]	= mix[i];
	}
}

void	alx_array_split_pos_neg_s32	(ssize_t n,
				const int32_t mix[restrict n],
				int32_t pos[restrict n],
				int32_t neg[restrict n])
{

	memset(pos, 0, sizeof(pos[0]) * n);
	memset(neg, 0, sizeof(neg[0]) * n);

	for (ssize_t i = 0; i < n; i++) {
		if (!mix[i])
			continue;
		if (mix[i] > 0)
			pos[i]	= mix[i];
		else
			neg[i]	= mix[i];
	}
}

void	alx_array_split_pos_neg_s64	(ssize_t n,
				const int64_t mix[restrict n],
				int64_t pos[restrict n],
				int64_t neg[restrict n])
{

	memset(pos, 0, sizeof(pos[0]) * n);
	memset(neg, 0, sizeof(neg[0]) * n);

	for (ssize_t i = 0; i < n; i++) {
		if (!mix[i])
			continue;
		if (mix[i] > 0)
			pos[i]	= mix[i];
		else
			neg[i]	= mix[i];
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
