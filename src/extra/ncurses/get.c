/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/ncurses/get.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#include "libalx/base/stdio/common.h"
#include "libalx/base/stdio/sscan.h"
#include "libalx/extra/ncurses/common.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE	(0xFF)


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
static	long double	loop_w_get_ldbl	(WINDOW *win,
					long double m, long double def,
								long double M,
					uint8_t attempts);
static	double		loop_w_get_dbl	(WINDOW *win,
					double m, double def, double M,
					uint8_t attempts);
static	float		loop_w_get_flt	(WINDOW *win,
					float m, float def, float M,
					uint8_t attempts);
static	unsigned	loop_w_get_uint	(WINDOW *win,
					unsigned m, unsigned def, unsigned M,
					uint8_t attempts);
static	int		loop_w_get_int	(WINDOW *win,
					int m, int def, int M,
					uint8_t attempts);
static	uint8_t		loop_w_get_u8	(WINDOW *win,
					uint8_t m, uint8_t def, uint8_t M,
					uint8_t attempts);
static	int8_t		loop_w_get_s8	(WINDOW *win,
					int8_t m, int8_t def, int8_t M,
					uint8_t attempts);
static	uint16_t	loop_w_get_u16	(WINDOW *win,
					uint16_t m, uint16_t def, uint16_t M,
					uint8_t attempts);
static	int16_t		loop_w_get_s16	(WINDOW *win,
					int16_t m, int16_t def, int16_t M,
					uint8_t attempts);
static	uint32_t	loop_w_get_u32	(WINDOW *win,
					uint32_t m, uint32_t def, uint32_t M,
					uint8_t attempts);
static	int32_t		loop_w_get_s32	(WINDOW *win,
					int32_t m, int32_t def, int32_t M,
					uint8_t attempts);
static	uint64_t	loop_w_get_u64	(WINDOW *win,
					uint64_t m, uint64_t def, uint64_t M,
					uint8_t attempts);
static	int64_t		loop_w_get_s64	(WINDOW *win,
					int64_t m, int64_t def, int64_t M,
					uint8_t attempts);
static	int		loop_w_get_fname(WINDOW *win,
					const char *restrict fpath,
					char fname[restrict FILENAME_MAX],
					bool exist,
					uint8_t attempts);
static	void		manage_w_error	(WINDOW *win, int err);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
long double	alx_w_get_ldbl	(long double m, long double def, long double M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce a real number [%Lf U %Lf] (default %Lf)",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_ldbl(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

double		alx_w_get_dbl	(double m, double def, double M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce a real number [%lf U %lf] (default %lf)",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_dbl(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

float		alx_w_get_flt	(float m, float def, float M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce a real number [%f U %f] (default %f)",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_flt(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

unsigned	alx_w_get_uint	(unsigned m, unsigned def, unsigned M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%u U %u] (default %u)",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_uint(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int		alx_w_get_int	(int m, int def, int M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%i U %i] (default %i)",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_int(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

uint8_t		alx_w_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIu8" U %"PRIu8"] (default %"PRIu8")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_u8(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int8_t		alx_w_get_s8	(int8_t m, int8_t def, int8_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIi8" U %"PRIi8"] (default %"PRIi8")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_s8(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

uint16_t	alx_w_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIu16" U %"PRIu16"] (default %"PRIu16")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_u16(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int16_t		alx_w_get_s16	(int16_t m, int16_t def, int16_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIi16" U %"PRIi16"] (default %"PRIi16")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_s16(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

uint32_t	alx_w_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIu32" U %"PRIu32"] (default %"PRIu32")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_u32(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int32_t		alx_w_get_s32	(int32_t m, int32_t def, int32_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIi32" U %"PRIi32"] (default %"PRIi32")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_s32(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

uint64_t	alx_w_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIu64" U %"PRIu64"] (default %"PRIu64")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_u64(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int64_t		alx_w_get_s64	(int64_t m, int64_t def, int64_t M,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer [%"PRIi64" U %"PRIi64"] (default %"PRIi64")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R	= loop_w_get_s64(win3, m, def, M, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	R;
}

int		alx_w_get_nstr	(ptrdiff_t size, char dest[restrict size],
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	int	err;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		waddstr(win2, "Introduce a string");
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	echo();
	if (mvwgetnstr(win3, 0, 0, dest, size) == ERR)
		err	= ERR_GETSTR;
	else
		err	= 0;
	noecho();

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	err;
}

int		alx_w_get_fname	(const char *restrict fpath,
				char fname[restrict FILENAME_MAX],
				bool exist,
				int8_t width, int8_t row,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{
	WINDOW	*win1;
	int8_t	h1, w1, r1, c1;
	WINDOW	*win2;
	int8_t	h2, w2, r2, c2;
	WINDOW	*win3;
	int8_t	h3, w3, r3, c3;
	int	err;

	/* Dimensions */
	h1	= 3;
	w1	= width;
	r1	= row;
	c1	= (80 - width) / 2;
	h2	= 1;
	w2	= w1 - 4;
	r2	= r1 + 3;
	c2	= c1 + 2;
	h3	= 1;
	w3	= w1 - 2;
	r3	= r1 + 1;
	c3	= c1 + 1;

	/* Box & title */
	win1	= newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncurses_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		waddstr(win2, "Introduce a file name");
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	err	= loop_w_get_fname(win3, fpath, fname, exist, attempts);

	/* Delete window */
	alx_ncurses_delwin(win3);
	alx_ncurses_delwin(win2);
	alx_ncurses_delwin(win1);

	return	err;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	long double	loop_w_get_ldbl	(WINDOW *win,
					long double m, long double def,
								long double M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	int		tmp;
	long double	R;
	int		err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_ldbl(&R, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	R;
}

static	double		loop_w_get_dbl	(WINDOW *win,
					double m, double def, double M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	double	R;
	int	err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_dbl(&R, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	R;
}

static	float		loop_w_get_flt	(WINDOW *win,
					float m, float def, float M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	float	R;
	int	err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_flt(&R, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	R;
}

static	unsigned	loop_w_get_uint	(WINDOW *win,
					unsigned m, unsigned def, unsigned M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	int		tmp;
	unsigned	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_uint(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	N;
}

static	int		loop_w_get_int	(WINDOW *win,
					int m, int def, int M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	int	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_int(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	Z;
}

static	uint8_t		loop_w_get_u8	(WINDOW *win,
					uint8_t m, uint8_t def, uint8_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	uint8_t	N;
	int	err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_u8(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	N;
}

static	int8_t		loop_w_get_s8	(WINDOW *win,
					int8_t m, int8_t def, int8_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	int8_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_s8(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	Z;
}

static	uint16_t	loop_w_get_u16	(WINDOW *win,
					uint16_t m, uint16_t def, uint16_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	int		tmp;
	uint16_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_u16(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	N;
}

static	int16_t		loop_w_get_s16	(WINDOW *win,
					int16_t m, int16_t def, int16_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	int16_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_s16(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	Z;
}

static	uint32_t	loop_w_get_u32	(WINDOW *win,
					uint32_t m, uint32_t def, uint32_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	int		tmp;
	uint32_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_u32(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	N;
}

static	int32_t		loop_w_get_s32	(WINDOW *win,
					int32_t m, int32_t def, int32_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	int32_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_s32(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	Z;
}

static	uint64_t	loop_w_get_u64	(WINDOW *win,
					uint64_t m, uint64_t def, uint64_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	int		tmp;
	uint64_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_u64(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	N;
}

static	int64_t		loop_w_get_s64	(WINDOW *win,
					int64_t m, int64_t def, int64_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	tmp;
	int64_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_s64(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	Z;
}

static	int		loop_w_get_fname(WINDOW *win,
					const char *restrict fpath,
					char fname[restrict FILENAME_MAX],
					bool exist,
					uint8_t attempts)
{
	char	buff [FILENAME_MAX];
	int	tmp;
	int	err;

	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		echo();
		tmp	= mvwgetnstr(win, 0, 0, buff, FILENAME_MAX);
		noecho();
		wclear(win);
		wrefresh(win);
		if (tmp == ERR)
			goto err_getstr;
		err	= alx_sscan_fname(fpath, fname, exist, buff);
		if (err)
			goto err_sscan;
		break;

err_getstr:
		err	= ERR_GETSTR;
err_sscan:
		manage_w_error(win, err);
	}

	return	err;
}

static	void		manage_w_error	(WINDOW *win, int err)
{

	switch (err) {
	case ERR_RANGE:
		mvwaddstr(win, 0, 0, ERR_RANGE_MSG);
		break;
	case ERR_SSCANF:
		mvwaddstr(win, 0, 0, ERR_SSCANF_MSG);
		break;
	case ERR_FOPEN:
		mvwaddstr(win, 0, 0, ERR_FOPEN_MSG);
		break;
	case ERR_FEXIST:
		mvwaddstr(win, 0, 0, ERR_FEXIST_MSG);
		break;
	case ERR_FGETS:
		mvwaddstr(win, 0, 0, ERR_FGETS_MSG);
		break;
	case ERR_GETSTR:
		mvwaddstr(win, 0, 0, ERR_GETSTR_MSG);
		break;
	case ERR_SNPRINTF:
		mvwaddstr(win, 0, 0, ERR_SNPRINTF_MSG);
		break;
	}
	wrefresh(win);
	/* Wait for any key */
	wgetch(win);
	wclear(win);
	wrefresh(win);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
