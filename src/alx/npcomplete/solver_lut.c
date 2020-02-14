/******************************************************************************
 *	Copyright (C) 2012	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/alx/npcomplete/solver_lut.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libalx/base/compiler/size.h"
#include "libalx/base/stdint/types.h"
#include "libalx/base/stdlib/compare.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
/* Clean ---------------------------------------------------------------------*/
__attribute__((nonnull))
static
void	clean		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t l);
__attribute__((nonnull))
static
void	clean_x		(ptrdiff_t dim,
			 uint256_a mat_m_x[static restrict dim],
			 ptrdiff_t l);

/* Comp ----------------------------------------------------------------------*/
__attribute__((nonnull))
static
void	comp		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m);
__attribute__((nonnull))
static
void	comp_a		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m);
__attribute__((nonnull))
static
void	comp_z		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m);
__attribute__((nonnull))
static
void	comp_0		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m);
__attribute__((nonnull))
static
bool	comp_1_8	(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 int64_t *restrict num_m);
__attribute__((nonnull))
static
void	comp_9		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t pos_m);
__attribute__((nonnull))
static
int	calc_pos	(ptrdiff_t dim,
			 const int64_t cmp_m[static restrict dim][dim],
			 const int64_t alt_m[static restrict dim],
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m,
			 bool a_z);
__attribute__((nonnull))
static
int64_t	calc_num	(ptrdiff_t dim,
			 const uint256_a mat_m_a[static restrict dim],
			 int64_t cmp_m_a[static restrict dim],
			 int64_t num_m, ptrdiff_t pos_m);
__attribute__((nonnull, pure))
static
int	comp_zrs	(ptrdiff_t dim,
			 const int64_t cmp_m_a[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl);

/* Next ----------------------------------------------------------------------*/
__attribute__((nonnull))
static
void	lvl_up		(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count);
__attribute__((nonnull))
static
void	lvl_next	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count);
__attribute__((nonnull))
static
void	update_sol	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t pos[static restrict dim][2],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 int64_t lut_num[static restrict lut_sz],
			 const int64_t lut_lvl[static restrict lut_sz],
			 const bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 int64_t *restrict count);
__attribute__((nonnull))
static
void	init_lvl	(ptrdiff_t dim,
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t *restrict tab_m,
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ]);
__attribute__((nonnull))
static
bool	chk_LUT_unuseful(uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 const uint256_a lut_nrws[static restrict lut_sz],
			 const int64_t lut_num[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ]);
__attribute__((nonnull))
static
void	LUTbit_init	(uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 const uint256_a lut_nrws[static restrict lut_sz],
			 const int64_t lut_num[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ]);

/* Prev ----------------------------------------------------------------------*/
__attribute__((nonnull))
static
void	lvl_dwn		(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t tab_m, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 bool lut_rdy[static restrict lut_sz],
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ]);

/* Check ---------------------------------------------------------------------*/
__attribute__((nonnull))
static
int	check_mat	(ptrdiff_t dim,
			 const int64_t sol[static restrict 3][dim],
			 const bool prb_mat[static restrict dim][dim],
			 ptrdiff_t len);
__attribute__((nonnull))
static
int	check_sol	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t len);
__attribute__((nonnull))
static
int	check_unique_sol(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t len);

/* Init ----------------------------------------------------------------------*/
__attribute__((nonnull))
static
void	init_mat	(ptrdiff_t dim,
			 const bool prb_mat[static restrict dim][dim],
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_npcomplete_solver_lut(ptrdiff_t dim,
			 const bool prb_mat[static restrict dim][dim],
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count, double *restrict tim)
{
	clock_t		tim_0, tim_1;
	ptrdiff_t	lvl;

	if (dim <= 0)
		return -1;
	init_mat(dim, prb_mat, sol, mat, tab, cmp, alt, num, pos, rws, len,
				&lvl, lut_sz, lut_nrws, lut_num, lut_lvl,
				lut_rdy, lut_ind, lutbit_rdy, lutbit_rws,
				lutbit_num, lutbit_all, count);

	tim_0	= clock();
	lvl_up(dim, sol, mat, tab, cmp, alt, num, pos, rws, len, &lvl,
				lut_sz, lut_nrws, lut_num, lut_lvl, lut_rdy,
				lut_ind, lutbit_rdy, lutbit_rws, lutbit_num,
				lutbit_all, count);
	tim_1	= clock();

	*tim	= (double)(tim_1 - tim_0) / CLOCKS_PER_SEC;

	if (check_mat(dim, sol, prb_mat, *len))
		return	-2;
	if (check_sol(dim, sol, *len))
		return	-3;

	return	0;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
/* Clean ---------------------------------------------------------------------*/
	/*
	 * Erase row l off a matrix.
	 * ALT-- (One less alternative).
	 * Erase cmp for that row.
	 */
static
void	clean		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t l)
{
	const int64_t	m_a_z	= alt_m[0];

	clean_x(dim, mat_m[0], l);

	/* NOT USEFUL: #pragma omp parallel for */
	for (ptrdiff_t z = 1; z <= m_a_z; z++) {
		clean_x(dim, mat_m[z], l);
		if (cmp_m[z][l]) {
			alt_m[z]--;
			if (alt_m[z] < 2)
				alt_m[z] = 0;
			cmp_m[z][l] = 0;
		}
	}

	cmp_m[0][l] = 0;
}

static
void	clean_x		(ptrdiff_t dim,
			 uint256_a mat_m_x[static restrict dim],
			 ptrdiff_t l)
{
	uint256_a	m;

	nmask_256b(m, l);

	for (ptrdiff_t c = 0; c < dim; c++)
		andassign_256b(mat_m_x[c], m);
	reset_256b(mat_m_x[l]);
}

/* Comp ----------------------------------------------------------------------*/
	/*
	 * Start the compZ() function that corresponds, depending on Z_A.
	 *
	 * If ALT is 1 or 0, set NUM = 0 in order to
	 * decrease lvl inmediately.
	 */
static
void	comp		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m)
{
	const int64_t	m_a_z	= alt_m[0];

	if (m_a_z) {
		if (alt_m[m_a_z] < 2)
			*num_m	= 0;
		else
			comp_z(dim, mat_m, cmp_m, alt_m, len, lvl, num_m,pos_m);
	} else {
		comp_a(dim, mat_m, cmp_m, alt_m, len, lvl, num_m, pos_m);
	}

	if (comp_zrs(dim, cmp_m[0], len, lvl))
		*num_m	= 0;
}

	/*
	 * compZ() functions:
	 *
	 * Their objective is to run the compX() funtions in correct order.
	 *
	 * Each compZ() function has to run compX() functions in this order:
	 * 	0, 1;
	 *
	 * Their second objective is to exit whenever there aren't any rows
	 * valid for a solution, making MAX_NUM = 0 to decrease lvl.
	 */

	/*
	 * First compZ() function that runs.
	 */
static
void	comp_a		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m)
{

	comp_0(dim, mat_m, cmp_m, alt_m, len, lvl, num_m, pos_m);
	if (*num_m)
		comp_9(dim, mat_m, cmp_m, alt_m, *pos_m);
}

	/*
	 * It runs the second and following times.
	 */
static
void	comp_z		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m)
{
	const int64_t	m_a_z	= alt_m[0];
	bool	wh;

	do {
		wh = false;
		comp_0(dim, mat_m, cmp_m, alt_m, len, lvl, num_m, pos_m);
		if (alt_m[m_a_z] < 2)
			*num_m	= 0;
		else if (*num_m)
			wh = comp_1_8(dim, mat_m, cmp_m, alt_m, num_m);
	} while (wh);

	if (*num_m) {
		if (!calc_pos(dim, cmp_m, alt_m, num_m, pos_m, true))
			*num_m = calc_num(dim, mat_m[0],cmp_m[0],*num_m,*pos_m);
		comp_9(dim, mat_m, cmp_m, alt_m, *pos_m);
	}
}

	/*
	 * CompX():
	 */

	/*
	 * Count the number of rows with which each row is compatible.
	 *
	 * If a row is NOT compatible with more rows than what is
	 * needed for improving the solution, ERASE it.
	 *
	 * If a row has a greater number of compatibilities than the
	 * preceding ones, update MAX with it.
	 */

static
void	comp_0		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl,
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m)
{
	bool	wh;

	do {
		wh = false;
		for (ptrdiff_t l = 0; l < dim; l++) {
			cmp_m[0][l] = popcnt_256b(mat_m[0][l]);

			if (cmp_m[0][l] && (cmp_m[0][l] <= (len - lvl))) {
				wh = true;
				clean(dim, mat_m, cmp_m, alt_m, l);
			}
		}
	} while (wh);
	calc_pos(dim, cmp_m, alt_m, num_m, pos_m, false);
}

	/*
	 * If a row is still an alternative check again:
	 *
	 * Count the number of rows with which that row is compatible.
	 *
	 * If a row is NOT compatible with more rows than what is
	 * needed for improving the solution, ERASE it.
	 *
	 * If there are still alternatives, continue.
	 * If NOT, decrease level.
	 */
static
bool	comp_1_8	(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 int64_t *restrict num_m)
{
	const int64_t	m_a_z	= alt_m[0];
	bool	wh;
	bool	rt;

	rt = false;
	do {
		wh = false;
		for (ptrdiff_t i = 1; i <= m_a_z; i++) {
			for (ptrdiff_t l = 0; l < dim; l++) {
				if (!cmp_m[i][l])
					continue;
				cmp_m[i][l] = popcnt_256b(mat_m[i][l]);
				if (cmp_m[i][l] < 2) {
					clean(dim, mat_m, cmp_m, alt_m, l);
					wh = true;
					rt = true;
				}
			}

			if (alt_m[i] < 2) {
				*num_m	= 0;
				wh = false;
				rt = false;
				break;
			}
		}
	} while (wh);

	return	rt;
}

	/*
	 * If a row is compatible with MAX or is 0, set it to 0.
	 *
	 * Else, if a row is NOT compatible with max_cmp, it can be an
	 * alternative to MAX in the future, so copy it from MAT[0] to
	 * MAT[x], being careful of making 0 those columns that
	 * correspond to MAX.
	 */
static
void	comp_9		(ptrdiff_t dim,
			 uint256_a mat_m[static restrict dim][dim],
			 int64_t cmp_m[static restrict dim][dim],
			 int64_t alt_m[static restrict dim],
			 ptrdiff_t pos_m)
{
	const int64_t	m_a_z	= ++(alt_m[0]);
	uint256_a	mask;
	uint256_a	tmp;

	alt_m[m_a_z] =	0;

	memcpy(mat_m[m_a_z], mat_m[0], ARRAY_BYTES(mat_m[0]));

//	#pragma omp parallel for
	for (ptrdiff_t l = 0; l < dim; l++) {
		mask_256b(mask, pos_m);
		and_256b(tmp, mat_m[0][l], mask);
		if (bool_256b(tmp))
			clean_x(dim, mat_m[m_a_z], l);
	}

//	#pragma omp parallel for
	for (ptrdiff_t l = 0; l < dim; l++)
		cmp_m[m_a_z][l]	= popcnt_256b(mat_m[m_a_z][l]);

	for (ptrdiff_t l = 0; l < dim; l++) {
		if (cmp_m[m_a_z][l])
			alt_m[m_a_z]++;
	}
}

static
int	calc_pos	(ptrdiff_t dim,
			 const int64_t cmp_m[static restrict dim][dim],
			 const int64_t alt_m[static restrict dim],
			 int64_t *restrict num_m, ptrdiff_t *restrict pos_m,
			 bool a_z)
{
	const int64_t	m_a_z	= alt_m[0];
	ptrdiff_t	i;
	ptrdiff_t	n;

	i = 0;
	n = dim;
	if (a_z) {
		for (ptrdiff_t l = 1; l <= m_a_z; l++) {
			if (alt_m[l] < n) {
				n = alt_m[l];
				i = l;
			}
		}
	}

	*num_m	= 0;
	*pos_m	= 0;
	for (ptrdiff_t l = 0; l < dim; l++) {
		if (cmp_m[i][l] > *num_m) {
			*num_m = cmp_m[i][l];
			*pos_m = l;
		}
	}
	return	!*num_m;
}

static
int64_t	calc_num	(ptrdiff_t dim,
			 const uint256_a mat_m_a[static restrict dim],
			 int64_t cmp_m_a[static restrict dim],
			 int64_t num_m, ptrdiff_t pos_m)
{

	if (!num_m)
		return	0;

	cmp_m_a[pos_m]	= popcnt_256b(mat_m_a[pos_m]);
	num_m		= cmp_m_a[pos_m];
	return	num_m;
}

static
int	comp_zrs	(ptrdiff_t dim,
			 const int64_t cmp_m_a[static restrict dim],
			 ptrdiff_t len, ptrdiff_t lvl)
{
	int64_t	ones, zeros, msize, zmax;

	ones	= 0;
	msize	= 0;

	for (ptrdiff_t l = 0; l < dim; l++) {
		if (!cmp_m_a[l])
			continue;
		msize++;
		ones +=	cmp_m_a[l];
	}

	zeros	= (msize * msize) - ones;
	zmax	= 2 * (msize - (len - lvl)) * (msize - (len - lvl));
	if (zeros > zmax)
		return	1;
	return	0;
}

/* Next ----------------------------------------------------------------------*/
	/*
	 * Check for viable subtrees (comp).
	 *
	 * If any viable subtree (MAX_NUM), continue in that subtree.
	 * If NOT, decrease lvl (exit while).
	 *
	 * If viable subtree, continue increasing lvl until matrix is
	 * 0x0 or no viable solutions left.
	 *
	 * Then return to this lvl.
	 */
static
void	lvl_up		(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count)
{

	alt[*lvl][0] = 0;

	do {
		comp(dim, mat[*lvl], cmp[*lvl], alt[*lvl], *len, *lvl,
						&num[*lvl][1], &pos[*lvl][1]);
		if (num[*lvl][1])
			lvl_next(dim, sol, mat, tab, cmp, alt, num, pos, rws,
					len, lvl, lut_sz, lut_nrws, lut_num,
					lut_lvl, lut_rdy, lut_ind, lutbit_rdy,
					lutbit_rws, lutbit_num, lutbit_all,
					count);
	} while (num[*lvl][1]);
}

static
void	lvl_next	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count)
{
	pos[*lvl + 1][0] = pos[*lvl][1];
	num[*lvl + 1][0] = num[*lvl][1];

	update_sol(dim, sol, pos, len, lvl, lut_sz, lut_num, lut_lvl, lut_rdy,
							*lut_ind, count);

	if (num[*lvl][0] > 1) {
		init_lvl(dim, mat, &tab[*lvl], cmp, alt, pos, rws[*lvl],
					*len, *lvl, lut_sz, lut_nrws, lut_num,
					lut_lvl, lut_rdy, lut_ind, lutbit_rdy,
					lutbit_rws, lutbit_num, lutbit_all);
		lvl_up(dim, sol, mat, tab, cmp, alt, num, pos, rws,
					len, lvl, lut_sz, lut_nrws, lut_num,
					lut_lvl, lut_rdy, lut_ind, lutbit_rdy,
					lutbit_rws, lutbit_num, lutbit_all,
					count);
	}

	lvl_dwn(dim, sol, tab[*lvl], lvl, lut_sz, lut_rdy, lutbit_rdy);
	clean(dim, mat[*lvl], cmp[*lvl], alt[*lvl], pos[*lvl][1]);
}

	/*
	 * Update tmp solution.
	 *
	 * Store greatest lvl reached since lvl creation from 0 to
	 * in last_pivot.
	 *
	 * If tmp sol is better that sol, updt sol.
	 */
static
void	update_sol	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t pos[static restrict dim][2],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 int64_t lut_num[static restrict lut_sz],
			 const int64_t lut_lvl[static restrict lut_sz],
			 const bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 int64_t *restrict count)
{

	sol[1][*lvl]	= pos[*lvl + 1][0];
	++*lvl;
	++*count;

	if (*lvl > *len) {
		memcpy(sol[0], sol[1], *lvl * sizeof(sol[0][0]));
		*len	= *lvl;

		#pragma omp parallel for simd
		for (ptrdiff_t i = 0; i < lut_ind; i++) {
			if (!lut_rdy[i] && (*len - lut_lvl[i] > lut_num[i]))
				lut_num[i] = (*len - lut_lvl[i]);
		}
	}
}

	/*
	 * Initialize next lvl.
	 */
static
void	init_lvl	(ptrdiff_t dim,
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t *restrict tab_m,
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ])
{
	uint256_a	m;
	uint256_a	nm;
	uint256_a	tmp;
	bool		unuseful;

	mask_256b(m, pos[lvl][0]);
	nmask_256b(nm, pos[lvl][0]);
	and_256b(rws_m, mat[lvl-1][0][pos[lvl][0]], nm);

	unuseful = chk_LUT_unuseful(rws_m, len, lvl, lut_sz, lut_nrws, lut_num,
			*lut_ind, lutbit_rdy,lutbit_rws,lutbit_num, lutbit_all);

	if (unuseful) {
		memset(mat[lvl][0], 0, ARRAY_BYTES(mat[lvl][0]));
	} else {
		/* NOT USEFUL: #pragma omp parallel for */
		for (ptrdiff_t l = 0; l < dim; l++) {
			and_256b(tmp, mat[lvl-1][0][l], m);
			if (bool_256b(tmp))
				and_256b(mat[lvl][0][l], mat[0][0][l], rws_m);
			else
				reset_256b(mat[lvl][0][l]);
		}
		reset_256b(mat[lvl][0][pos[lvl][0]]);

		*tab_m			= *lut_ind;
		not_256b(tmp, rws_m);
		assign_256b(lut_nrws[*lut_ind], tmp);
		lut_lvl[*lut_ind]	= lvl;
		lut_num[*lut_ind]	= len - lvl;
		lut_rdy[*lut_ind]	= false;
		lutbit_rdy[*lut_ind / 64] &= ~(UINT64_C(1) << (*lut_ind % 64)); /* XXX:Redundant */
		++*lut_ind;
	}
	memset(alt[lvl], 0, ARRAY_BYTES(alt[lvl]));
	for (ptrdiff_t i = 0; i < 2; i++)
		memset(cmp[lvl][i], 0, ARRAY_BYTES(cmp[lvl][i]));
}

static
bool	chk_LUT_unuseful(uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 const uint256_a lut_nrws[static restrict lut_sz],
			 const int64_t lut_num[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ])
{

	LUTbit_init(rws_m, len, lvl, lut_sz, lut_nrws, lut_num, lut_ind,
			lutbit_rdy, lutbit_rws, lutbit_num, lutbit_all);

	for (ptrdiff_t i = 0; i < LUTBIT_SZ; i++) {
		if (lutbit_all[i])
			return	true;
	}

	return	false;
}

static
void	LUTbit_init	(uint256_a rws_m, ptrdiff_t len, ptrdiff_t lvl,
			 ptrdiff_t lut_sz,
			 const uint256_a lut_nrws[static restrict lut_sz],
			 const int64_t lut_num[static restrict lut_sz],
			 ptrdiff_t lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ])
{
	uint256_a	tmp;

	memset(lutbit_rws, 0, sizeof(lutbit_rws[0]) * LUTBIT_SZ);
	memset(lutbit_num, 0, sizeof(lutbit_num[0]) * LUTBIT_SZ);

	#pragma omp parallel for simd
	for (ptrdiff_t i = 0; i < lut_ind; i++)
		lutbit_rws[i / 64] |= (uint64_t)((lut_num[i] + lvl) <= len) <<
								(i % 64);
	for (ptrdiff_t i = 0; i < lut_ind; i++) {
		and_256b(tmp, lut_nrws[i], rws_m);
		lutbit_num[i / 64] |= (uint64_t)!bool_256b(tmp) << (i % 64);
	}

	memcpy(lutbit_all, lutbit_rdy, sizeof(lutbit_all[0]) * LUTBIT_SZ);
	#pragma omp parallel for simd
	for (ptrdiff_t i = 0; i < LUTBIT_SZ; i++)
		lutbit_all[i] &= lutbit_rws[i] & lutbit_num[i];
}

/* Prev ----------------------------------------------------------------------*/
	/*
	 * Update tmp solution.
	 * Update pivot.
	 * Decrease lvl.
	 */
static
void	lvl_dwn		(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t tab_m, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 bool lut_rdy[static restrict lut_sz],
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ])
{

	sol[1][*lvl]	= 0;
	lut_rdy[tab_m]	= true;
	lutbit_rdy[tab_m / 64] |= UINT64_C(1) << (tab_m % 64);
	--*lvl;
}

/* Check ---------------------------------------------------------------------*/
static
int	check_mat	(ptrdiff_t dim,
			 const int64_t sol[static restrict 3][dim],
			 const bool prb_mat[static restrict dim][dim],
			 ptrdiff_t len)
{
	bool	chk_mat[len][len];

	for (ptrdiff_t l = 0; l < len; l++) {
		for (ptrdiff_t c = 0; c < len; c++)
			chk_mat[l][c] =	prb_mat[sol[0][l]][sol[0][c]];
	}

	for (ptrdiff_t l = 0; l < len; l++) {
		for (ptrdiff_t c = 0; c < len; c++) {
			if (!chk_mat[l][c])
				return	1;
		}
	}

	return	0;
}

	/*
	 *
	 */
static
int	check_sol	(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t len)
{

	for (ptrdiff_t i = 0; i < len; i++)
		sol[2][i]	= sol[0][i];
	qsort(sol[2], len, sizeof(sol[2][0]), alx_compare_s64);

	return	check_unique_sol(dim, sol, len);
}

static
int	check_unique_sol(ptrdiff_t dim,
			 int64_t sol[static restrict 3][dim],
			 ptrdiff_t len)
{

	for (ptrdiff_t i = 1; i < len; i++) {
		if (sol[2][i] == sol[2][i - 1])
			return	1;
	}
	return	0;
}

/* Init ----------------------------------------------------------------------*/
	/*
	 * This copies the matrix to be solved(mat_0) into the 0th level of the
	 * working matrix (mat).
	 */
static
void	init_mat	(ptrdiff_t dim,
			 const bool prb_mat[static restrict dim][dim],
			 int64_t sol[static restrict 3][dim],
			 uint256_a mat[static restrict dim][dim][dim],
			 ptrdiff_t tab[static restrict dim],
			 int64_t cmp[static restrict dim][dim][dim],
			 int64_t alt[static restrict dim][dim],
			 int64_t num[static restrict dim][2],
			 ptrdiff_t pos[static restrict dim][2],
			 uint256_a rws[static restrict dim],
			 ptrdiff_t *restrict len, ptrdiff_t *restrict lvl,
			 ptrdiff_t lut_sz,
			 uint256_a lut_nrws[static restrict lut_sz],
			 int64_t lut_num[static restrict lut_sz],
			 int64_t lut_lvl[static restrict lut_sz],
			 bool lut_rdy[static restrict lut_sz],
			 ptrdiff_t *restrict lut_ind,
			 uint64_t lutbit_rdy[static restrict LUTBIT_SZ],
			 uint64_t lutbit_rws[static restrict LUTBIT_SZ],
			 uint64_t lutbit_num[static restrict LUTBIT_SZ],
			 uint64_t lutbit_all[static restrict LUTBIT_SZ],
			 int64_t *restrict count)
{
	uint256_a	mask;

	*len	= 0;
	*lvl	= 0;
	*lut_ind = 0;
	*count	= 0;

	memset(sol, 0, sizeof(sol[0]) * 3);
	memset(mat, 0, sizeof(mat[0]) * dim);
	for (ptrdiff_t l = 0; l < dim; l++) {
		for (ptrdiff_t c = 0; c < dim; c++) {
			if (!prb_mat[l][c])
				continue;
			mask_256b(mask, c);
			orassign_256b(mat[0][0][l], mask);
		}
	}
	memset(tab, 0, sizeof(tab[0]) * dim);
	memset(cmp, 0, sizeof(cmp[0]) * dim);
	memset(alt, 0, sizeof(alt[0]) * dim);
	memset(num, 0, sizeof(num[0]) * dim);
	memset(pos, 0, sizeof(pos[0]) * dim);
	memset(rws, 0, sizeof(rws[0]) * dim);
	memset(lut_nrws, 0, sizeof(lut_nrws[0]) * lut_sz);
	memset(lut_num, 0, sizeof(lut_num[0]) * lut_sz);
	memset(lut_lvl, 0, sizeof(lut_lvl[0]) * lut_sz);
	memset(lut_rdy, 0, sizeof(lut_rdy[0]) * lut_sz);
	memset(lutbit_rdy, 0, sizeof(lutbit_rdy[0]) * LUTBIT_SZ);
	memset(lutbit_rws, 0, sizeof(lutbit_rws[0]) * LUTBIT_SZ);
	memset(lutbit_num, 0, sizeof(lutbit_num[0]) * LUTBIT_SZ);
	memset(lutbit_all, 0, sizeof(lutbit_all[0]) * LUTBIT_SZ);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
