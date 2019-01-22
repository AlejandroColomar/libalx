/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <inttypes.h>
	#include <stdbool.h>
	#include <stddef.h>
	#include <stdio.h>
/* libalx --------------------------------------------------------------------*/
	#include "libalx/io/alx_input.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
	# define	BUFF_SIZE	(FILENAME_MAX)

	# define	MAX_TRIES	(2)

	# define	ERR_RANGE_MSG	"¡ Number is out of range !"
	# define	ERR_SSCANF_MSG	"¡ sscanf() error !"
	# define	ERR_FPTR_MSG	"¡ FILE error !"
	# define	ERR_FGETS_MSG	"¡ fgets() error !"


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	double	loop_getdbl	(double m, double def, double M);
static	int	loop_getint	(double m, int def, double M);
static	int64_t	loop_getint_i64	(double m, int64_t def, double M);
static	void	manage_error	(int err);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
	/*
	 * Scan a number in the range [m, M].
	 * return:	0	if correct
	 *		non 0	if there is an error
	 */
int	alx_sscan_dbl	(double *dest, double m, double def, double M,
			const char *str)
{
	int	err	= ERR_OK;

	if (sscanf(str, " %lf", dest) != 1)
		err	= ERR_SSCANF;
	else if ((*dest < m) || (*dest > M))
		err	= ERR_RANGE;

	if (err)
		*dest = def;

	return	err;
}

int	alx_sscan_int	(int *dest, double m, int def, double M,
			const char *str)
{
	int	err	= ERR_OK;

	if (sscanf(str, " %i", dest) != 1)
		err	= ERR_SSCANF;
	else if ((*dest < m) || (*dest > M))
		err	= ERR_RANGE;

	if (err)
		*dest = def;

	return	err;
}

int	alx_sscan_i64	(int64_t *dest, double m, int64_t def, double M,
			const char *str)
{
	int	err	= ERR_OK;

	if (sscanf(str, " %"SCNi64"", dest) != 1)
		err	= ERR_SSCANF;
	else if ((*dest < m) || (*dest > M))
		err	= ERR_RANGE;

	if (err)
		*dest = def;

	return	err;
}

	/*
	 * Scan a file name in fpath.
	 * return:	0	if correct
	 *		non 0	if there is an error
	 */
int	alx_sscan_fname	(const char *fpath, char *fname, bool exist,
			const char *str)
{
	char	buff [FILENAME_MAX];
	char	file_path [FILENAME_MAX];
	int	err;
	FILE	*fp;

	if (sscanf(str, " %s ", buff) != 1)
		return	ERR_SSCANF;

	snprintf(file_path, FILENAME_MAX, "%s%s", fpath, buff);

	fp	= fopen(file_path, "r");
	if (fp) {
		fclose(fp);
		if (!exist)
			return	ERR_FPTR;
	} else {
		if (exist)
			return	ERR_FPTR;
	}

	snprintf(fname, FILENAME_MAX, "%s", buff);

	return	ERR_OK;
}

	/*
	 * Ask for a double in the range [m, M].
	 *
	 * If the user enters a non valid number, it repeats to ask for
	 * the number two more times. After that, it uses the default
	 * value.
	 */
double	alx_getdbl	(double m, double def, double M,
			const char *title, const char *help)
{
	double	R;

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%lf U %lf] (default %lf):...\t",
								m, M, def);

	R = loop_getdbl(m, def, M);

	return	R;
}

	/*
	 * Ask for an int in the range [m, M].
	 *
	 * If the user enters a non valid number, it repeats to ask for
	 * the number two more times. After that, it uses the default
	 * value.
	 */
int	alx_getint	(double m, int def, double M,
			const char *title, const char *help)
{
	int	Z;

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce an integer number [%lf U %lf] (default %i):...\t",
								m, M, def);

	Z = loop_getint(m, def, M);

	return	Z;
}

int64_t	alx_getint_i64	(double m, int64_t def, double M,
			const char *title, const char *help)
{
	int64_t	Z;

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce an integer number [%lf U %lf] (default %"PRIi64"):...\t",
								m, M, def);

	Z = loop_getint_i64(m, def, M);

	return	Z;
}


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static	double	loop_getdbl	(double m, double def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	double	R;
	int	err;

	R	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;

		err	= alx_sscan_dbl(&R, m, def, M, buff);
		if (err)
			goto err_sscan;

		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
		continue;
	}

	return	R;
}

static	int	loop_getint	(double m, int def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	Z;
	int	err;

	Z	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;

		err	= alx_sscan_int(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;

		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
		continue;
	}

	return	Z;
}

static	int64_t	loop_getint_i64	(double m, int64_t def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int64_t	Z;
	int	err;

	Z	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;

		err	= alx_sscan_i64(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;

		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
		continue;
	}

	return	Z;
}

static	void	manage_error	(int err)
{

	switch (err) {
	case ERR_RANGE:
		printf("%s\n", ERR_RANGE_MSG);
		break;
	case ERR_SSCANF:
		printf("%s\n", ERR_SSCANF_MSG);
		break;
	case ERR_FGETS:
		printf("%s\n", ERR_FGETS_MSG);
		break;
	}
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
