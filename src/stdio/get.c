/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdio/get.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/stdio/sscan.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define NUMSTR_SIZE	(128)


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
long double	alx_get_ldbl	(long double m, long double def, long double M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%Lf U %Lf] (default %Lf):...\t",
								m, M, def);

	return	loop_get_ldbl(m, def, M, attempts);
}

double		alx_get_dbl	(double m, double def, double M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%lf U %lf] (default %lf):...\t",
								m, M, def);

	return	loop_get_dbl(m, def, M, attempts);
}

float		alx_get_flt	(float m, float def, float M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%f U %f] (default %f):...\t",
								m, M, def);

	return	loop_get_dbl(m, def, M, attempts);
}

unsigned	alx_get_uint	(unsigned m, unsigned def, unsigned M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%u U %u] (default %u):...\t",
								m, M, def);

	return	loop_get_uint(m, def, M, attempts);
}

int		alx_get_int	(int m, int def, int M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%i U %i] (default %i):...\t",
								m, M, def);

	return	loop_get_int(m, def, M, attempts);
}

uint8_t		alx_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIu8" U %"PRIu8"] (default %"PRIu8"):...\t",
								m, M, def);

	return	loop_get_u8(m, def, M, attempts);
}

int8_t		alx_get_s8	(int8_t m, int8_t def, int8_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIi8" U %"PRIi8"] (default %"PRIi8"):...\t",
								m, M, def);

	return	loop_get_s8(m, def, M, attempts);
}

uint16_t	alx_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIu16" U %"PRIu16"] (default %"PRIu16"):...\t",
								m, M, def);

	return	loop_get_u16(m, def, M, attempts);
}

int16_t		alx_get_s16	(int16_t m, int16_t def, int16_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIi16" U %"PRIi16"] (default %"PRIi16"):...\t",
								m, M, def);

	return	loop_get_s16(m, def, M, attempts);
}

uint32_t	alx_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIu32" U %"PRIu32"] (default %"PRIu32"):...\t",
								m, M, def);

	return	loop_get_u32(m, def, M, attempts);
}

int32_t		alx_get_s32	(int32_t m, int32_t def, int32_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIi32" U %"PRIi32"] (default %"PRIi32"):...\t",
								m, M, def);

	return	loop_get_s32(m, def, M, attempts);
}

uint64_t	alx_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIu64" U %"PRIu64"] (default %"PRIu64"):...\t",
								m, M, def);

	return	loop_get_u64(m, def, M, attempts);
}

int64_t		alx_get_s64	(int64_t m, int64_t def, int64_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a real number [%"PRIi64" U %"PRIi64"] (default %"PRIi64"):...\t",
								m, M, def);

	return	loop_get_s64(m, def, M, attempts);
}

int		alx_get_fname	(const char *restrict path,
				char fname[restrict FILENAME_MAX],
				bool exist,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a file name:...\t");

	return	loop_get_fname(path, fname, exist, attempts);
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
