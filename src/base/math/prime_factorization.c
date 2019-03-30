/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/prime_factorization.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

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
int	alx_prime_factorization_s8	(int8_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_S8])
{
	ptrdiff_t	prime_index;
	int_fast8_t	tmp;

	if (!n) {
		errno	= EDOM;
		return	-1;
	}

	memset(*pf, 0, sizeof(*pf));
	if (n < 0) {
		errno	= EDOM;
		n	= -n;
	}
	if (n == 1)
		return	0;

	prime_index	= alx_prime_index_s8(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	0;
	}

	tmp	= n;
	for (ptrdiff_t i = 0; true; i++) {
		while (!(tmp % alx_prime_s8[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_s8[i];

			if (tmp == 1)
				return	0;
			prime_index = alx_prime_index_s8(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	0;
			}
		}
	}
}

int	alx_prime_factorization_u8	(uint8_t n,
				int8_t (*restrict pf)[PRIME_NUMBERS_QTY_U8])
{
	ptrdiff_t	prime_index;
	uint_fast8_t	tmp;

	if (!n) {
		errno	= EDOM;
		return	-1;
	}

	memset(*pf, 0, sizeof(*pf));
	if (n == 1)
		return	0;

	prime_index	= alx_prime_index_u8(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	0;
	}

	tmp	= n;
	for (ptrdiff_t i = 0; true; i++) {
		while (!(tmp % alx_prime_u8[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_u8[i];

			if (tmp == 1)
				return	0;
			prime_index = alx_prime_index_u8(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	0;
			}
		}
	}
}

int	alx_prime_factorization_s16	(int16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_S16])
{
	ptrdiff_t	prime_index;
	int_fast16_t	tmp;

	if (!n) {
		errno	= EDOM;
		return	-1;
	}

	memset(*pf, 0, sizeof(*pf));
	if (n < 0) {
		errno	= EDOM;
		n	= -n;
	}
	if (n == 1)
		return	0;

	if (!alx_prime_s16[0])
		alx_prime_s16_init();

	prime_index	= alx_prime_index_s16(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	0;
	}

	tmp	= n;
	for (ptrdiff_t i = 0; true; i++) {
		while (!(tmp % alx_prime_s16[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_s16[i];

			if (tmp == 1)
				return	0;
			prime_index = alx_prime_index_s16(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	0;
			}
		}
	}
}

int	alx_prime_factorization_u16	(uint16_t n,
				int16_t (*restrict pf)[PRIME_NUMBERS_QTY_U16])
{
	ptrdiff_t	prime_index;
	uint_fast16_t	tmp;

	if (!n) {
		errno	= EDOM;
		return	-1;
	}

	memset(*pf, 0, sizeof(*pf));
	if (n == 1)
		return	0;

	if (!alx_prime_u16[0])
		alx_prime_u16_init();

	prime_index	= alx_prime_index_u16(n);
	if (prime_index != -1) {
		(*pf)[prime_index]	= 1;
		return	0;
	}

	tmp	= n;
	for (ptrdiff_t i = 0; true; i++) {
		while (!(tmp % alx_prime_u16[i])) {
			(*pf)[i]++;
			tmp	/= alx_prime_u16[i];

			if (tmp == 1)
				return	0;
			prime_index = alx_prime_index_u16(tmp);
			if (prime_index != -1) {
				(*pf)[prime_index]	= 1;
				return	0;
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
