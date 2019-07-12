/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/ncurses/menu.h"

#include <stdbool.h>
#include <stdint.h>

#include <ncurses.h>

#include "libalx/extra/ncurses/common.h"


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
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	void	_print_menu	(WINDOW *win,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[N]);
static	int8_t	_usr_input_sel	(WINDOW *win,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[N]);


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int8_t	alx_ncurses_menu	(int8_t height, int8_t width,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[restrict N],
				const char *restrict title)
{
	WINDOW		*win;
	int_fast8_t	r, c;
	int_fast8_t	sel;

	r	= 1;
	c	= (80 - width) / 2;
	win	= newwin(height, width, r, c);

	sel	= alx_ncurses_menu_w(win, N, mnu, title);

	alx_ncurses_delwin(win);

	return	sel;
}

int8_t	alx_ncurses_menu_w	(WINDOW *win,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[restrict N],
				const char *restrict title)
{
	int_fast8_t	sel;

	keypad(win, true);
	noecho();

	box(win, 0, 0);
	alx_ncurses_title(win, title);
	_print_menu(win, N, mnu);

	sel	= _usr_input_sel(win, N, mnu);

	return	sel;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	void	_print_menu	(WINDOW *win,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[N])
{

	/* Print menu items */
	for (int_fast8_t i = 0; i < N; i++)
		mvwaddstr(win, mnu[i].r, mnu[i].c, mnu[i].t);
	wrefresh(win);
}

static	int8_t	_usr_input_sel	(WINDOW *win,
				int8_t N,
				const struct Alx_Ncurses_Menu mnu[N])
{
	int_fast8_t	sel;
	bool		wh;
	int		c;

	/* default item */
	sel	= 1;
	wmove(win, mnu[sel].r, mnu[sel].c + 1);

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
			if (sel)
				sel--;
			else
				sel = N - 1;
			wmove(win, mnu[sel].r, mnu[sel].c + 1);
			break;

		case KEY_DOWN:
		case 's':
		case 'j':
			/* KEY_DOWN, move one item down */
			if (sel != N - 1)
				sel++;
			else
				sel = 0;
			wmove(win, mnu[sel].r, mnu[sel].c + 1);
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
				sel = c - '0';
				wmove(win, mnu[sel].r, mnu[sel].c + 1);
				wh = false;
			}
			break;

		}

	}

	return	sel;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
