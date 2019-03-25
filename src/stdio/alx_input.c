/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdio/alx_input.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/stdio/sscan.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
	# define	BUFF_SIZE	(FILENAME_MAX)

	# define	MAX_TRIES	(2)


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
	int	err_val;

	R	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin)) {
			err_val	= ERR_FGETS;
			goto err;
		}

		err_val	= alx_sscan_dbl(&R, m, def, M, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_error(err_val);
		continue;
	}

	return	R;
}

static	int	loop_getint	(double m, int def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int	Z;
	int	err_val;

	Z	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin)) {
			err_val	= ERR_FGETS;
			goto err;
		}

		err_val	= alx_sscan_int(&Z, m, def, M, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_error(err_val);
		continue;
	}

	return	Z;
}

static	int64_t	loop_getint_i64	(double m, int64_t def, double M)
{
	int	i;
	char	buff [BUFF_SIZE];
	int64_t	Z;
	int	err_val;

	Z	= def;

	for (i = 0; i < MAX_TRIES; i++) {
		if (!fgets(buff, BUFF_SIZE, stdin)) {
			err_val	= ERR_FGETS;
			goto err;
		}

		err_val	= alx_sscan_s64(&Z, m, def, M, buff);
		if (err_val)
			goto err;

		break;

err:
		manage_error(err_val);
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
	case ERR_FOPEN:
		printf("%s\n", ERR_FOPEN_MSG);
		break;
	case ERR_FEXIST:
		printf("%s\n", ERR_FEXIST_MSG);
		break;
	case ERR_FGETS:
		printf("%s\n", ERR_FGETS_MSG);
		break;
	case ERR_SNPRINTF:
		printf("%s\n", ERR_SNPRINTF_MSG);
		break;
	}
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
