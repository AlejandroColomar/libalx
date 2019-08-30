/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/gmp/mpz/division.h"

#include <stdint.h>

#include <gmp.h>


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
uint64_t alx_mpz_cdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_cdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_cdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_cdiv_u64	(const mpz_t n, uint64_t d);

extern
uint64_t alx_mpz_fdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_fdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_fdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_fdiv_u64	(const mpz_t n, uint64_t d);

extern
uint64_t alx_mpz_tdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_tdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_tdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
extern
uint64_t alx_mpz_tdiv_u64	(const mpz_t n, uint64_t d);

extern
uint64_t alx_mpz_mod_u64	(mpz_t r, const mpz_t n, uint64_t d);
extern
void	alx_mpz_divexact_u64	(mpz_t q, const mpz_t n, uint64_t d);
extern
bool	alx_mpz_divisible_u64_p	(const mpz_t n, uint64_t d);
extern
bool	alx_mpz_congruent_u64_p	(const mpz_t n, uint64_t c, uint64_t d);


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
