/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# ifndef		ALX_NCUR_H
	# define	ALX_NCUR_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <stdint.h>

/* Packages ------------------------------------------------------------------*/
	#include <ncurses.h>


/******************************************************************************
 ******* structs **************************************************************
 ******************************************************************************/
	struct	Alx_Menu {
		int	r;
		int	c;
		char	*t;
	};


/******************************************************************************
 ******* functions ************************************************************
 ******************************************************************************/
	void	alx_start_curses	(void);
	void	alx_pause_curses	(void);
	void	alx_resume_curses	(void);
	void	alx_end_curses		(void);
	void	alx_win_del		(WINDOW		*win);

	int	alx_menu		(int		h,
					int		w,
					int		N,
					struct Alx_Menu	mnu[N],
					const char	*str);

	int	alx_menu_2		(WINDOW		*win,
					int		N,
					struct Alx_Menu	mnu[N],
					const char	*str);

	double	alx_w_getdbl		(int		w,
					int		r,
					const char	*title,
					double		m,
					double		def,
					double		M,
					const char	*help);

	int64_t	alx_w_getint		(int		w,
					int		r,
					const char	*title,
					double		m,
					int64_t		def,
					double		M,
					const char	*help);

	void	alx_w_getstr		(char		*dest,
					int		destsize,
					int		w,
					int		r,
					const char	*title,
					const char	*help);

	void	alx_w_getfname		(const char	*fpath,
					char		*fname,
					bool		exist,
					int		w,
					int		r,
					const char	*title,
					const char	*help);

	void	alx_ncur_prn_title	(WINDOW		*win,
					const char	*title);

	void	alx_ncur_prn_subtitle	(WINDOW		*win,
					const char	*subtitle);


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# endif			/* alx_ncur.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
