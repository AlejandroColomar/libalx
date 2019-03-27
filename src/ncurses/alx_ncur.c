/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/ncurses/alx_ncur.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>

#include "libalx/stdio/common.h"
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


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
