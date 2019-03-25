/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include "libalx/curses/alx_ncur.h"

	#include <inttypes.h>
	#include <stdbool.h>
	#include <stddef.h>
	#include <stdio.h>
	#include <string.h>

	#include <ncurses.h>

	#include "libalx/stdio/alx_input.h"
	#include "libalx/stdio/sscan.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE	(1024)

#define MAX_TRIES	(2)


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	alx_ncur_prn_menu	(WINDOW *win,
					int N, const struct Alx_Menu mnu[N]);
static	int	alx_ncur_usr_sel	(WINDOW *win,
					int N, const struct Alx_Menu mnu[N]);
static	double	loop_w_getdbl		(WINDOW *win,
					double m, double def, double M);
static	int64_t	loop_w_getint		(WINDOW *win,
					double m, int64_t def, double M);
static	int	loop_w_getstr		(char *dest, int destsize, WINDOW *win);

static	int	loop_w_getfname		(const char *fpath, char *fname,
					bool exist, WINDOW *win);
static	void	manage_w_error		(WINDOW *win, int err);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
void	alx_start_curses	(void)
{

	initscr();
	nonl();
	cbreak();
	noecho();
	keypad(stdscr, true);

	if (has_colors()) {
		start_color();
		use_default_colors();
	}
//	mousemask(BUTTON4_PRESSED | BUTTON2_PRESSED, NULL);
}

void	alx_pause_curses	(void)
{

	def_prog_mode();
	endwin();
}

void	alx_resume_curses	(void)
{

	fflush(stdout);
	reset_prog_mode();
}

void	alx_end_curses		(void)
{

	clear();
	refresh();
	endwin();
}

void	alx_win_del		(WINDOW *win)
{

	wbkgd(win, 0);
	wclear(win);
	wrefresh(win);
	delwin(win);
}

int	alx_menu		(int h, int w,
				int N, const struct Alx_Menu mnu[N],
				const char *title)
{
	WINDOW	*win;
	int	r;
	int	c;
	int	i;

	/* Dimensions */
	r	= 1;
	c	= (80 - w) / 2;
	win	= newwin(h, w, r, c);

	/* Input */
	i	= alx_menu_2(win, N, mnu, title);

	/* Delete window */
	alx_win_del(win);

	return	i;
}

int	alx_menu_2		(WINDOW *win,
				int N, const struct Alx_Menu mnu[N],
				const char *title)
{
	int	i;

	/* Activate keypad, and don't echo input */
	keypad(win, true);
	noecho();

	/* Print box, title and menu items */
	box(win, 0, 0);
	alx_ncur_prn_title(win, title);
	alx_ncur_prn_menu(win, N, mnu);

	/* Input */
	i	= alx_ncur_usr_sel(win, N, mnu);

	return	i;
}

double	alx_w_getdbl		(int w, int r, const char *title,
				double m, double def, double M,
				const char *help)
{
	WINDOW	*win1;
	int	h1;
	int	w1;
	int	r1;
	int	c1;
	WINDOW	*win2;
	int	h2;
	int	w2;
	int	r2;
	int	c2;
	WINDOW	*win3;
	int	h3;
	int	w3;
	int	r3;
	int	c3;
	double	R;

	/* Dimensions */
	h1	= 3;
	w1	= w;
	r1	= r;
	c1	= (80 - w) / 2;
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
	alx_ncur_prn_title(win1, title);
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
	R	= loop_w_getdbl(win3, m, def, M);

	/* Delete window */
	alx_win_del(win3);
	alx_win_del(win2);
	alx_win_del(win1);

	return	R;
}

int64_t	alx_w_getint		(int w, int r, const char *title,
				double m, int64_t def, double M,
				const char *help)
{
	WINDOW	*win1;
	int	h1;
	int	w1;
	int	r1;
	int	c1;
	WINDOW	*win2;
	int	h2;
	int	w2;
	int	r2;
	int	c2;
	WINDOW	*win3;
	int	h3;
	int	w3;
	int	r3;
	int	c3;
	int	Z;

	/* Dimensions */
	h1	= 3;
	w1	= w;
	r1	= r;
	c1	= (80 - w) / 2;
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
	alx_ncur_prn_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2	= newwin(h2, w2, r2, c2);
	if (help)
		wprintw(win2, "%s", help);
	else
		wprintw(win2, "Introduce an integer number [%lf U %lf] (default %"PRIi64")",
								m, M, def);
	wrefresh(win2);

	/* Input */
	win3	= newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	Z	= loop_w_getint(win3, m, def, M);

	/* Delete window */
	alx_win_del(win3);
	alx_win_del(win2);
	alx_win_del(win1);

	return	Z;
}

void	alx_w_getstr		(char *dest, int destsize,
				int w, int r, const char *title,
				const char *help)
{
	WINDOW	*win1;
	int	h1;
	int	w1;
	int	r1;
	int	c1;
	WINDOW	*win2;
	int	h2;
	int	w2;
	int	r2;
	int	c2;
	WINDOW	*win3;
	int	h3;
	int	w3;
	int	r3;
	int	c3;

	/* Dimensions */
	h1	= 3;
	w1	= w;
	r1	= r;
	c1	= (80 - w) / 2;
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
	alx_ncur_prn_title(win1, title);
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
	loop_w_getstr(dest, destsize, win3);

	/* Delete window */
	alx_win_del(win3);
	alx_win_del(win2);
	alx_win_del(win1);
}

void	alx_w_getfname		(const char *fpath, char *fname, bool exist,
				int w, int r, const char *title,
				const char *help)
{
	WINDOW	*win1;
	int	h1;
	int	w1;
	int	r1;
	int	c1;
	WINDOW	*win2;
	int	h2;
	int	w2;
	int	r2;
	int	c2;
	WINDOW	*win3;
	int	h3;
	int	w3;
	int	r3;
	int	c3;

	/* Dimensions */
	h1	= 3;
	w1	= w;
	r1	= r;
	c1	= (80 - w) / 2;
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
	alx_ncur_prn_title(win1, title);
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
	loop_w_getfname(fpath, fname, exist, win3);

	/* Delete window */
	alx_win_del(win3);
	alx_win_del(win2);
	alx_win_del(win1);
}

void	alx_ncur_prn_title	(WINDOW *win, const char *title)
{
	int	w;
	int	len;

	/* Find size of window */
	w	= getmaxx(win);

	/* Find length of title */
	len	= strlen(title);

	/* Print title centered */
	mvwaddch(win, 0, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", title);
	waddch(win, ACS_LTEE);
}

void	alx_ncur_prn_subtitle	(WINDOW *win, const char *subtitle)
{
	int	h;
	int	w;
	int	len;

	/* Find size of window */
	h	= getmaxy(win);
	w	= getmaxx(win);

	/* Find length of title */
	len	= strlen(subtitle);

	/* Print subtitle centered */
	mvwaddch(win, h - 1, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", subtitle);
	waddch(win, ACS_LTEE);
}


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	alx_ncur_prn_menu	(WINDOW *win,
					int N, const struct Alx_Menu mnu[N])
{
	int	i;

	/* Print menu items */
	for (i = 0; i < N; i++)
		mvwaddstr(win, mnu[i].r, mnu[i].c, mnu[i].t);

	wrefresh(win);
}

static	int	alx_ncur_usr_sel	(WINDOW *win,
					int N, const struct Alx_Menu mnu[N])
{
	int	i;
	bool	wh;
	int	c;

	/* default item */
	i	= 1;
	wmove(win, mnu[i].r, mnu[i].c + 1);

	/* Receive input until ENTER key */
	wh	= true;
	while (wh) {
		/* Input */
		c = wgetch(win);

		switch (c) {
		case KEY_UP:
		case 'w':
		case 'k':
			/* KEY_UP, move one item up */
			if (i)
				i--;
			else
				i = N - 1;
			wmove(win, mnu[i].r, mnu[i].c + 1);
			break;

		case KEY_DOWN:
		case 's':
		case 'j':
			/* KEY_DOWN, move one item down */
			if (i != N - 1)
				i++;
			else
				i = 0;
			wmove(win, mnu[i].r, mnu[i].c + 1);
			break;

		/* '\r' is Enter key in Windows */
		case KEY_ENTER:
		case '\r':
		case '\n':
		case ' ':
			/* ENTER / SPACE, end menu */
			wh = false;
			break;

		default:
			if ((c >= '0') && (c < N + '0')) {
				/* Input is a number, move to item & end menu */
				i = c - '0';
				wmove(win, mnu[i].r, mnu[i].c + 1);
				wh = false;
			}
			break;

		}

	}

	return	i;
}

static	double	loop_w_getdbl		(WINDOW *win,
					double m, double def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	x;
	double	R;
	int	err_val;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err_val	= ERR_GETSTR;
			goto err;
		}
		err_val	= alx_sscan_dbl(&R, m, def, M, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_w_error(win, err_val);
		R	= def;
	}

	return	R;
}

static	int64_t	loop_w_getint		(WINDOW *win,
					double m, int64_t def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	x;
	int64_t	Z;
	int	err_val;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err_val	= ERR_GETSTR;
			goto err;
		}
		err_val	= alx_sscan_s64(&Z, m, def, M, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_w_error(win, err_val);
		Z	= def;
	}

	return	Z;
}

static	int	loop_w_getstr		(char *dest, int destsize, WINDOW *win)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	x;
	int	err_val;

	for (i = 0; i < MAX_TRIES; i++) {
		err_val	= 0;

		echo();
		x	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err_val	= ERR_GETSTR;
			goto err;
		}
		if (snprintf(dest, destsize, "%s", buff) >= destsize) {
			err_val	= ERR_SNPRINTF;
			goto err;
		}

		break;

err:
		manage_w_error(win, err_val);
	}

	return	err_val;
}

static	int	loop_w_getfname		(const char *fpath, char *fname,
					bool exist, WINDOW *win)
{
	int	i;
	char	buff [FILENAME_MAX];
	int	x;
	int	err_val;

	for (i = 0; i < MAX_TRIES; i++) {
		err_val	= 0;

		echo();
		x	= mvwgetnstr(win, 0, 0, buff, FILENAME_MAX);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err_val	= ERR_GETSTR;
			goto err;
		}
		err_val	= alx_sscan_fname(fpath, fname, exist, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_w_error(win, err_val);
	}

	return	err_val;
}

static	void	manage_w_error		(WINDOW *win, int err)
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
