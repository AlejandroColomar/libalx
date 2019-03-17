/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime_factors.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>

#include "libalx/base/math/prime.h"


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
bool	alx_prime_factors_s8	(int8_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	ssize_t	prime_index;
	int	tmp;

	memset(*pf, 0, sizeof(*pf));

	if (n < 2)
		return	false;
	prime_index	= alx_prime_index_s8(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	true;
	}

	tmp	= n;
	for (ssize_t i = 0; true; i++) {
		while (!(tmp % alx_prime_s8[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_s8[i];

			if (tmp == 1)
				return	true;
			prime_index = alx_prime_index_s8(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	true;
			}
		}
	}
}

bool	alx_prime_factors_u8	(uint8_t n,
				uint8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	ssize_t		prime_index;
	unsigned	tmp;

	memset(*pf, 0, sizeof(*pf));

	if (n < 2)
		return	false;
	prime_index	= alx_prime_index_u8(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	true;
	}

	tmp	= n;
	for (ssize_t i = 0; true; i++) {
		while (!(tmp % alx_prime_u8[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_u8[i];

			if (tmp == 1)
				return	true;
			prime_index = alx_prime_index_u8(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	true;
			}
		}
	}
}

bool	alx_prime_factors_s16	(int16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	ssize_t	prime_index;
	int	tmp;

	if (!alx_prime_s16[0])
		alx_prime_s16_init();

	memset(*pf, 0, sizeof(*pf));

	if (n < 2)
		return	false;
	prime_index	= alx_prime_index_s16(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	true;
	}

	tmp	= n;
	for (ssize_t i = 0; true; i++) {
		while (!(tmp % alx_prime_s16[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_s16[i];

			if (tmp == 1)
				return	true;
			prime_index = alx_prime_index_s16(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	true;
			}
		}
	}
}

bool	alx_prime_factors_u16	(uint16_t n,
				uint16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	ssize_t		prime_index;
	unsigned	tmp;

	if (!alx_prime_u16[0])
		alx_prime_u16_init();

	memset(*pf, 0, sizeof(*pf));

	if (n < 2)
		return	false;
	prime_index	= alx_prime_index_u16(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	true;
	}

	tmp	= n;
	for (ssize_t i = 0; true; i++) {
		while (!(tmp % alx_prime_u16[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_u16[i];

			if (tmp == 1)
				return	true;
			prime_index = alx_prime_index_u16(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	true;
			}
		}
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
