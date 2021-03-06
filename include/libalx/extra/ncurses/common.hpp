/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/ncurses/common.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <ncurses.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
void	alx_ncurses_init	(void);
void	alx_ncurses_pause	(void);
void	alx_ncurses_resume	(void);
void	alx_ncurses_deinit	(void);
[[gnu::nonnull]]
void	alx_ncurses_delwin	(WINDOW *restrict win);
[[gnu::nonnull]]
void	alx_ncurses_title	(WINDOW *restrict win,
				 const char *restrict title);
[[gnu::nonnull]]
void	alx_ncurses_subtitle	(WINDOW *restrict win,
				 const char *restrict subtitle);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace ncurses {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace ncurses */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
