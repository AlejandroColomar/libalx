/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <inttypes.h>
	#include <stdbool.h>
	#include <stdio.h>
		/* strlen() */
	#include <string.h>
		/* wchar_t */
	#include <wchar.h>

/* Packages ------------------------------------------------------------------*/
	#include <ncurses.h>

/* libalx --------------------------------------------------------------------*/
	#include "alx_input.h"

	#include "alx_ncur.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
	# define	BUFF_SIZE	(1024)

	# define	MAX_TRIES	(2)

	# define	ERR_RANGE_MSG	"¡ Number is out of range !"
	# define	ERR_SSCANF_MSG	"¡ sscanf() error !"
	# define	ERR_FPTR_MSG	"¡ FILE error !"
	# define	ERR_GETSTR_MSG	"¡ wgetstr() error !"


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	alx_ncur_prn_menu	(WINDOW *win,
					int N, struct Alx_Menu mnu[N]);
static	int	alx_ncur_usr_sel	(WINDOW *win,
					int N, struct Alx_Menu mnu[N]);
static	double	loop_w_getdbl		(WINDOW *win,
					double m, double def, double M);
static	int64_t	loop_w_getint		(WINDOW *win,
					double m, int64_t def, double M);
static	void	loop_w_getstr		(char *dest, int destsize, WINDOW *win);

static	void	loop_w_getfname		(const char *fpath, char *fname, bool exist,
					WINDOW *win);
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
	/* Delete window */
	wbkgd(win, 0);
	wclear(win);
	wrefresh(win);
	delwin(win);
}

int	alx_menu		(int h, int w,
				int N, struct Alx_Menu mnu[N], const char *title)
{
	/* Dimensions */
	WINDOW	*win;
	int	r;
	int	c;
	r =	1;
	c =	(80 - w) / 2;
	win =	newwin(h, w, r, c);

	/* Input */
	int	i;
	i =	alx_menu_2(win, N, mnu, title);

	/* Delete window */
	alx_win_del(win);

	return	i;
}

int	alx_menu_2		(WINDOW *win,
				int N, struct Alx_Menu mnu[N], const char *title)
{
	/* Activate keypad, and don't echo input */
	keypad(win, true);
	noecho();

	/* Print box, title and menu items */
	box(win, 0, 0);
	alx_ncur_prn_title(win, title);
	alx_ncur_prn_menu(win, N, mnu);

	/* Input */
	int	i;
	i =	alx_ncur_usr_sel(win, N, mnu);

	return	i;
}

double	alx_w_getdbl		(int w, int r, const char *title,
				double m, double def, double M,
				const char *help)
{
	/* Dimensions */
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
	h1 =	3;
	w1 =	w;
	r1 =	r;
	c1 =	(80 - w) / 2;
	h2 =	1;
	w2 =	w1 - 4;
	r2 =	r1 + 3;
	c2 =	c1 + 2;
	h3 =	1;
	w3 =	w1 - 2;
	r3 =	r1 + 1;
	c3 =	c1 + 1;

	/* Box & title */
	win1 =	newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncur_prn_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2 =	newwin(h2, w2, r2, c2);
	if (help == NULL) {
		wprintw(win2, "Introduce a real number [%lf U %lf] (default %lf)", m, M, def);
	} else {
		wprintw(win2, "%s", help);
	}
	wrefresh(win2);

	/* Input */
	double	R;
	win3 =	newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	R =	loop_w_getdbl(win3, m, def, M);

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
	/* Dimensions */
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
	h1 =	3;
	w1 =	w;
	r1 =	r;
	c1 =	(80 - w) / 2;
	h2 =	1;
	w2 =	w1 - 4;
	r2 =	r1 + 3;
	c2 =	c1 + 2;
	h3 =	1;
	w3 =	w1 - 2;
	r3 =	r1 + 1;
	c3 =	c1 + 1;

	/* Box & title */
	win1 =	newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncur_prn_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2 =	newwin(h2, w2, r2, c2);
	if (help == NULL) {
		wprintw(win2, "Introduce an integer number [%lf U %lf] (default %"PRIi64")", m, M, def);
	} else {
		wprintw(win2, "%s", help);
	}
	wrefresh(win2);

	/* Input */
	int	Z;
	win3 =	newwin(h3, w3, r3, c3);
	wbkgd(win3, A_REVERSE);
	wrefresh(win3);
	Z =	loop_w_getint(win3, m, def, M);

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
	/* Dimensions */
	WINDOW	*win1;
	int	h1;
	int	w1;
	int	r1;
	int	c1;
	h1 =	3;
	w1 =	w;
	r1 =	r;
	c1 =	(80 - w) / 2;
	WINDOW	*win2;
	int	h2;
	int	w2;
	int	r2;
	int	c2;
	h2 =	1;
	w2 =	w1 - 4;
	r2 =	r1 + 3;
	c2 =	c1 + 2;
	WINDOW	*win3;
	int	h3;
	int	w3;
	int	r3;
	int	c3;
	h3 =	1;
	w3 =	w1 - 2;
	r3 =	r1 + 1;
	c3 =	c1 + 1;

	/* Box & title */
	win1 =	newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncur_prn_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2 =	newwin(h2, w2, r2, c2);
	if (help == NULL) {
		waddstr(win2, "Introduce a string");
	} else {
		wprintw(win2, "%s", help);
	}
	wrefresh(win2);

	/* Input */
	win3 =	newwin(h3, w3, r3, c3);
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
	/* Dimensions */
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
	h1 =	3;
	w1 =	w;
	r1 =	r;
	c1 =	(80 - w) / 2;
	h2 =	1;
	w2 =	w1 - 4;
	r2 =	r1 + 3;
	c2 =	c1 + 2;
	h3 =	1;
	w3 =	w1 - 2;
	r3 =	r1 + 1;
	c3 =	c1 + 1;

	/* Box & title */
	win1 =	newwin(h1, w1, r1, c1);
	wbkgd(win1, A_REVERSE);
	box(win1, 0, 0);
	alx_ncur_prn_title(win1, title);
	wrefresh(win1);

	/* Help */
	win2 =	newwin(h2, w2, r2, c2);
	if (help == NULL) {
		waddstr(win2, "Introduce a file name");
	} else {
		wprintw(win2, "%s", help);
	}
	wrefresh(win2);

	/* Input */
	win3 =	newwin(h3, w3, r3, c3);
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
	/* Find size of window */
	int	h;
	int	w;
	getmaxyx(win, h, w);

	/* Find length of title */
	int	len;
	len =	strlen(title);

	/* Print title centered */
	mvwaddch(win, 0, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", title);
	waddch(win, ACS_LTEE);
}

void	alx_ncur_prn_subtitle	(WINDOW *win, const char *subtitle)
{
	/* Find size of window */
	int	h;
	int	w;
	getmaxyx(win, h, w);

	/* Find length of title */
	int	len;
	len =	strlen(subtitle);

	/* Print subtitle centered */
	mvwaddch(win, h - 1, (w - (len + 2))/2 - 1, ACS_RTEE);
	wprintw(win, " %s ", subtitle);
	waddch(win, ACS_LTEE);
}


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	void	alx_ncur_prn_menu	(WINDOW *win,
					int N, struct Alx_Menu mnu[N])
{
	/* Find size of window */
	int	h;
	int	w;
	getmaxyx(win, h, w);

	/* Print all menu items */
	int	i;
	for (i = 0; i < N; i++) {
		mvwaddstr(win, mnu[i].r, mnu[i].c, mnu[i].t);
	}

	wrefresh(win);
}

static	int	alx_ncur_usr_sel	(WINDOW *win,
					int N, struct Alx_Menu mnu[N])
{
	/* default item */
	int	i =	1;
	wmove(win, mnu[i].r, mnu[i].c + 1);

	/* Receive input until ENTER key */
	bool	wh;
	wchar_t	ch;
	wh = true;
	while (wh) {
		/* Input */
		ch = wgetch(win);

		switch (ch) {
		case KEY_UP:
		case 'w':
		case 'k':
			/* KEY_UP, move one item up */
			if (i) {
				i--;
			} else {
				i = N - 1;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);
			break;

		case KEY_DOWN:
		case 's':
		case 'j':
			/* KEY_DOWN, move one item down */
			if (i != N - 1) {
				i++;
			} else {
				i = 0;
			}
			wmove(win, mnu[i].r, mnu[i].c + 1);
			break;

		/* '\r' is Enter key in Windows */
		case '\r':
		case '\n':
		case ' ':
			/* ENTER / SPACE, end menu */
			wh = false;
			break;

		default:
			if ((ch >= '0') && (ch < N + '0')) {
				/* Input is a number, move to that item & end menu */
				i = ch - '0';
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
	int	err;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x =	mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err	= ERR_GETSTR;
		} else {
			err	= alx_sscan_dbl(&R, m, def, M, buff);
		}

		if (err) {
			manage_w_error(win, err);
		} else {
			break;
		}
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
	int	err;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err	= ERR_GETSTR;
		} else {
			err	= alx_sscan_int64(&Z, m, def, M, buff);
		}

		if (err) {
			manage_w_error(win, err);
		} else {
			break;
		}
	}

	return	Z;
}

static	void	loop_w_getstr		(char *dest, int destsize, WINDOW *win)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	x;
	int	err;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x	= mvwgetnstr(win, 0, 0, buff, BUFF_SIZE);
		noecho();
		wclear(win);
		wrefresh(win);

		err	= ERR_OK;
		if (x == ERR) {
			err	= ERR_GETSTR;
		} else {
			break;
		}

		if (err) {
			manage_w_error(win, err);
		} else {
			break;
		}
	}

	if (!err) {
		snprintf(dest, destsize, "%s", buff);
	}
}

static	void	loop_w_getfname		(const char *fpath, char *fname, bool exist,
					WINDOW *win)
{
	int	i;
	char	buff [FILENAME_MAX];
	int	x;
	int	err;

	for (i = 0; i < MAX_TRIES; i++) {
		echo();
		x	= mvwgetnstr(win, 0, 0, buff, FILENAME_MAX);
		noecho();
		wclear(win);
		wrefresh(win);

		if (x == ERR) {
			err	= ERR_GETSTR;
		} else {
			err	= alx_sscan_fname(fpath, fname, exist, buff);
		}

		if (err) {
			manage_w_error(win, err);
		} else {
			break;
		}
	}
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
	case ERR_FPTR:
		mvwaddstr(win, 0, 0, ERR_FPTR_MSG);
		break;
	case ERR_GETSTR:
		mvwaddstr(win, 0, 0, ERR_GETSTR_MSG);
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
