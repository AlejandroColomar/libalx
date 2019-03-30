/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdio/get.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "libalx/base/stdio/common.h"
#include "libalx/base/stdio/sscan.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE	(0xFF)


/******************************************************************************
 ******* static functions *****************************************************
 ******************************************************************************/
static
long double	loop_get_ldbl	(long double m, long double def, long double M,
					uint8_t attempts);
static	double		loop_get_dbl	(double m, double def, double M,
					uint8_t attempts);
static	float		loop_get_flt	(float m, float def, float M,
					uint8_t attempts);
static	unsigned	loop_get_uint	(unsigned m, unsigned def, unsigned M,
					uint8_t attempts);
static	int		loop_get_int	(int m, int def, int M,
					uint8_t attempts);
static	uint8_t		loop_get_u8	(uint8_t m, uint8_t def, uint8_t M,
					uint8_t attempts);
static	int8_t		loop_get_s8	(int8_t m, int8_t def, int8_t M,
					uint8_t attempts);
static	uint16_t	loop_get_u16	(uint16_t m, uint16_t def, uint16_t M,
					uint8_t attempts);
static	int16_t		loop_get_s16	(int16_t m, int16_t def, int16_t M,
					uint8_t attempts);
static	uint32_t	loop_get_u32	(uint32_t m, uint32_t def, uint32_t M,
					uint8_t attempts);
static	int32_t		loop_get_s32	(int32_t m, int32_t def, int32_t M,
					uint8_t attempts);
static	uint64_t	loop_get_u64	(uint64_t m, uint64_t def, uint64_t M,
					uint8_t attempts);
static	int64_t		loop_get_s64	(int64_t m, int64_t def, int64_t M,
					uint8_t attempts);
static	ptrdiff_t	loop_get_ptrdiff(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
					uint8_t attempts);
static	int		loop_get_fname	(const char *restrict path,
					char fname[restrict FILENAME_MAX],
					bool exist,
					uint8_t attempts);
static	void		manage_error	(int err);


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

	return	loop_get_flt(m, def, M, attempts);
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
		printf("Introduce an integer [%u U %u] (default %u):...\t",
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
		printf("Introduce an integer [%i U %i] (default %i):...\t",
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
		printf("Introduce an integer [%"PRIu8" U %"PRIu8"] (default %"PRIu8"):...\t",
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
		printf("Introduce an integer [%"PRIi8" U %"PRIi8"] (default %"PRIi8"):...\t",
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
		printf("Introduce an integer [%"PRIu16" U %"PRIu16"] (default %"PRIu16"):...\t",
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
		printf("Introduce an integer [%"PRIi16" U %"PRIi16"] (default %"PRIi16"):...\t",
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
		printf("Introduce an integer [%"PRIu32" U %"PRIu32"] (default %"PRIu32"):...\t",
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
		printf("Introduce an integer [%"PRIi32" U %"PRIi32"] (default %"PRIi32"):...\t",
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
		printf("Introduce an integer [%"PRIu64" U %"PRIu64"] (default %"PRIu64"):...\t",
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
		printf("Introduce an integer [%"PRIi64" U %"PRIi64"] (default %"PRIi64"):...\t",
								m, M, def);

	return	loop_get_s64(m, def, M, attempts);
}

ptrdiff_t	alx_get_ptrdiff	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
				const char *restrict title,
				const char *restrict help,
				uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce an integer [%ti U %ti] (default %ti):...\t",
								m, M, def);

	return	loop_get_ptrdiff(m, def, M, attempts);
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
static
long double	loop_get_ldbl	(long double m, long double def, long double M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	long double	R;
	int		err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_ldbl(&R, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	R;
}

static	double		loop_get_dbl	(double m, double def, double M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	double	R;
	int	err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
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
	}

	return	R;
}

static	float		loop_get_flt	(float m, float def, float M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	float	R;
	int	err;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_flt(&R, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	R;
}

static	unsigned	loop_get_uint	(unsigned m, unsigned def, unsigned M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	unsigned	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_uint(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	N;
}

static	int		loop_get_int	(int m, int def, int M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
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
	}

	return	Z;
}

static	uint8_t		loop_get_u8	(uint8_t m, uint8_t def, uint8_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	uint8_t	N;
	int	err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_u8(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	N;
}

static	int8_t		loop_get_s8	(int8_t m, int8_t def, int8_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int8_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_s8(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	Z;
}

static	uint16_t	loop_get_u16	(uint16_t m, uint16_t def, uint16_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	uint16_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_u16(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	N;
}

static	int16_t		loop_get_s16	(int16_t m, int16_t def, int16_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int16_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_s16(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	Z;
}

static	uint32_t	loop_get_u32	(uint32_t m, uint32_t def, uint32_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	uint32_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_u32(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	N;
}

static	int32_t		loop_get_s32	(int32_t m, int32_t def, int32_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int32_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_s32(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	Z;
}

static	uint64_t	loop_get_u64	(uint64_t m, uint64_t def, uint64_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	uint64_t	N;
	int		err;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_u64(&N, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	N;
}

static	int64_t		loop_get_s64	(int64_t m, int64_t def, int64_t M,
					uint8_t attempts)
{
	char	buff [BUFF_SIZE];
	int64_t	Z;
	int	err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_s64(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	Z;
}

static	ptrdiff_t	loop_get_ptrdiff(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
					uint8_t attempts)
{
	char		buff [BUFF_SIZE];
	ptrdiff_t	Z;
	int		err;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, BUFF_SIZE, stdin))
			goto err_fgets;
		err	= alx_sscan_ptrdiff(&Z, m, def, M, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	Z;
}

static	int		loop_get_fname	(const char *restrict path,
					char fname[restrict FILENAME_MAX],
					bool exist,
					uint8_t attempts)
{
	char	buff [FILENAME_MAX];
	int	err;

	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, FILENAME_MAX, stdin))
			goto err_fgets;
		err	= alx_sscan_fname(path, fname, exist, buff);
		if (err)
			goto err_sscan;
		break;

err_fgets:
		err	= ERR_FGETS;
err_sscan:
		manage_error(err);
	}

	return	err;
}

static	void		manage_error	(int err)
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
