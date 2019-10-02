/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/gmp/mpz/division.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#include <gmp.h>

#include "libalx/base/assert/assert.h"


/******************************************************************************
 ******* _Static_assert *******************************************************
 ******************************************************************************/
alx_Static_assert_stdint_types();


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* Rename without alx_ prefix */
#if defined(ALX_NO_PREFIX)
#define mpz_cdiv_q_u64(q, n, d)		alx_mpz_cdiv_q_u64(q, n, d)
#define mpz_cdiv_r_u64(r, n, d)		alx_mpz_cdiv_r_u64(r, n, d)
#define mpz_cdiv_qr_u64(q, r, n, d)	alx_mpz_cdiv_qr_u64(q, r, n, d)
#define mpz_cdiv_u64(n, d)		alx_mpz_cdiv_u64(n, d)
#define mpz_fdiv_q_u64(q, n, d)		alx_mpz_fdiv_q_u64(q, n, d)
#define mpz_fdiv_r_u64(r, n, d)		alx_mpz_fdiv_r_u64(r, n, d)
#define mpz_fdiv_qr_u64(q, r, n, d)	alx_mpz_fdiv_qr_u64(q, r, n, d)
#define mpz_fdiv_u64(n, d)		alx_mpz_fdiv_u64(n, d)
#define mpz_tdiv_q_u64(q, n, d)		alx_mpz_tdiv_q_u64(q, n, d)
#define mpz_tdiv_r_u64(r, n, d)		alx_mpz_tdiv_r_u64(r, n, d)
#define mpz_tdiv_qr_u64(q, r, n, d)	alx_mpz_tdiv_qr_u64(q, r, n, d)
#define mpz_tdiv_u64(n, d)		alx_mpz_tdiv_u64(n, d)
#define mpz_mod_u64(r, n, d)		alx_mpz_mod_u64(r, n, d)
#define mpz_divexact_u64(q, n, d)	alx_mpz_divexact_u64(q, n, d)
#define mpz_divisible_u64_p(n, d)	alx_mpz_divisible_u64_p(n, d)
#define mpz_congruent_u64_p(n, c, d)	alx_mpz_congruent_u64_p(n, c, d)
#endif


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/
inline
uint64_t alx_mpz_cdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_cdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_cdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_cdiv_u64	(const mpz_t n, uint64_t d);

inline
uint64_t alx_mpz_fdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_fdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_fdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_fdiv_u64	(const mpz_t n, uint64_t d);

inline
uint64_t alx_mpz_tdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_tdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_tdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d);
inline
uint64_t alx_mpz_tdiv_u64	(const mpz_t n, uint64_t d);

inline
uint64_t alx_mpz_mod_u64	(mpz_t r, const mpz_t n, uint64_t d);
inline
void	alx_mpz_divexact_u64	(mpz_t q, const mpz_t n, uint64_t d);
inline
bool	alx_mpz_divisible_u64_p	(const mpz_t n, uint64_t d);
inline
bool	alx_mpz_congruent_u64_p	(const mpz_t n, uint64_t c, uint64_t d);


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/
inline
uint64_t alx_mpz_cdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d)
{
	return	mpz_cdiv_q_ui(q, n, d);
}

inline
uint64_t alx_mpz_cdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_cdiv_r_ui(r, n, d);
}

inline
uint64_t alx_mpz_cdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_cdiv_qr_ui(q, r, n, d);
}

inline
uint64_t alx_mpz_cdiv_u64	(const mpz_t n, uint64_t d)
{
	return	mpz_cdiv_ui(n, d);
}


inline
uint64_t alx_mpz_fdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d)
{
	return	mpz_fdiv_q_ui(q, n, d);
}

inline
uint64_t alx_mpz_fdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_fdiv_r_ui(r, n, d);
}

inline
uint64_t alx_mpz_fdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_fdiv_qr_ui(q, r, n, d);
}

inline
uint64_t alx_mpz_fdiv_u64	(const mpz_t n, uint64_t d)
{
	return	mpz_fdiv_ui(n, d);
}


inline
uint64_t alx_mpz_tdiv_q_u64	(mpz_t q, const mpz_t n, uint64_t d)
{
	return	mpz_tdiv_q_ui(q, n, d);
}

inline
uint64_t alx_mpz_tdiv_r_u64	(mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_tdiv_r_ui(r, n, d);
}

inline
uint64_t alx_mpz_tdiv_qr_u64	(mpz_t q, mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_tdiv_qr_ui(q, r, n, d);
}

inline
uint64_t alx_mpz_tdiv_u64	(const mpz_t n, uint64_t d)
{
	return	mpz_tdiv_ui(n, d);
}


inline
uint64_t alx_mpz_mod_u64	(mpz_t r, const mpz_t n, uint64_t d)
{
	return	mpz_mod_ui(r, n, d);
}

inline
void	alx_mpz_divexact_u64	(mpz_t q, const mpz_t n, uint64_t d)
{
	mpz_divexact_ui(q, n, d);
}

inline
bool	alx_mpz_divisible_u64_p	(const mpz_t n, uint64_t d)
{
	return	mpz_divisible_ui_p(n, d);
}

inline
bool	alx_mpz_congruent_u64_p	(const mpz_t n, uint64_t c, uint64_t d)
{
	return	mpz_congruent_ui_p(n, c, d);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
