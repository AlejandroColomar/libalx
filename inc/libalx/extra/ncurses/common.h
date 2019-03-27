/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_NCURSES_COMMON_H
#define ALX_NCURSES_COMMON_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <ncurses.h>


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
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
void	alx_ncurses_init	(void);
void	alx_ncurses_pause	(void);
void	alx_ncurses_resume	(void);
void	alx_ncurses_deinit	(void);
void	alx_ncurses_delwin	(WINDOW *win);
void	alx_ncurses_title	(WINDOW *win, const char *restrict title);
void	alx_ncurses_subtitle	(WINDOW *win, const char *restrict subtitle);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/extra/ncurses/common.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/