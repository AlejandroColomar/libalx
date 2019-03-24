/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# ifndef		ALX_INPUT_H
	# define	ALX_INPUT_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include <stdbool.h>
	#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ERR_OK			(0)
#define ERR_RANGE		(1)
#define ERR_SSCANF		(2)
#define ERR_FPTR		(3)
#define ERR_FGETS		(4)
#define ERR_GETSTR		(5)
#define ERR_SNPRINTF		(6)

#define ERR_RANGE_MSG		"¡ Number is out of range !"
#define ERR_SSCANF_MSG		"¡ sscanf() error !"
#define ERR_FPTR_MSG		"¡ FILE error !"
#define ERR_FGETS_MSG		"¡ fgets() error !"
#define ERR_GETSTR_MSG		"¡ wgetstr() error !"
#define ERR_SNPRINTF_MSG	"¡ snprintf() error !"


/******************************************************************************
 ******* functions ************************************************************
 ******************************************************************************/
int	alx_sscan_dbl	(double *dest, double m, double def, double M,
			const char *str);

int	alx_sscan_int	(int *dest, double m, int def, double M,
			const char *str);

int	alx_sscan_i64	(int64_t *dest, double m, int64_t def, double M,
			const char *str);

int	alx_sscan_fname	(const char *fpath, char *fname, bool exist,
			const char *str);

double	alx_getdbl	(double m, double def, double M,
			const char *title, const char *help);

int	alx_getint	(double m, int def, double M,
			const char *title, const char *help);

int64_t	alx_getint_i64	(double m, int64_t def, double M,
			const char *title, const char *help);


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# endif			/* alx_input.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
