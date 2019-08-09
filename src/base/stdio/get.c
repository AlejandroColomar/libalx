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

#include "libalx/base/compiler/size.h"
#include "libalx/base/errno/error.h"
#include "libalx/base/stdio/sscan.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/
static
long double	loop_get_ldbl	(long double m, long double def, long double M,
				 uint8_t attempts);
static
double		loop_get_dbl	(double m, double def, double M,
				 uint8_t attempts);
static
float		loop_get_flt	(float m, float def, float M,
				 uint8_t attempts);
static
unsigned	loop_get_uint	(unsigned m, unsigned def, unsigned M,
				 uint8_t attempts);
static
int		loop_get_int	(int m, int def, int M,
				 uint8_t attempts);
static
uint8_t		loop_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				 uint8_t attempts);
static
int8_t		loop_get_s8	(int8_t m, int8_t def, int8_t M,
				 uint8_t attempts);
static
uint16_t	loop_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				 uint8_t attempts);
static
int16_t		loop_get_s16	(int16_t m, int16_t def, int16_t M,
				 uint8_t attempts);
static
uint32_t	loop_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				 uint8_t attempts);
static
int32_t		loop_get_s32	(int32_t m, int32_t def, int32_t M,
				 uint8_t attempts);
static
uint64_t	loop_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				 uint8_t attempts);
static
int64_t		loop_get_s64	(int64_t m, int64_t def, int64_t M,
				 uint8_t attempts);
static
ptrdiff_t	loop_get_pdif	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
				 uint8_t attempts);
static
char		loop_get_ch	(const char *restrict valid,
				 bool skip_space, bool ignore_case,
				 uint8_t attempts);
static
int		loop_get_fname	(const char *restrict path,
				 char fname[restrict FILENAME_MAX],
				 bool exist,
				 uint8_t attempts);


/******************************************************************************
 ******* global functions *****************************************************
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

ptrdiff_t	alx_get_pdif	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
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

	return	loop_get_pdif(m, def, M, attempts);
}

char		alx_get_ch	(const char *restrict valid,
				 bool skip_space, bool ignore_case,
				 const char *restrict title,
				 const char *restrict help,
				 uint8_t attempts)
{

	if (title)
		printf("%s\n", title);
	if (help)
		printf("%s\n", help);
	else
		printf("Introduce a character [%s] (default %c):...\t",
				 		valid, valid[0]);

	return	loop_get_ch(valid, skip_space, ignore_case, attempts);
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
 ******* static function definitions ******************************************
 ******************************************************************************/
static
long double	loop_get_ldbl	(long double m, long double def, long double M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	long double	R;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_ldbl(&R, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	R;
}

static
double		loop_get_dbl	(double m, double def, double M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	double	R;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_dbl(&R, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	R;
}

static
float		loop_get_flt	(float m, float def, float M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	float	R;

	R	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_flt(&R, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	R;
}

static
unsigned	loop_get_uint	(unsigned m, unsigned def, unsigned M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	unsigned	N;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_uint(&N, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	N;
}

static
int		loop_get_int	(int m, int def, int M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	int	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_int(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
uint8_t		loop_get_u8	(uint8_t m, uint8_t def, uint8_t M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	uint8_t	N;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_u8(&N, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	N;
}

static
int8_t		loop_get_s8	(int8_t m, int8_t def, int8_t M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	int8_t	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_s8(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
uint16_t	loop_get_u16	(uint16_t m, uint16_t def, uint16_t M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	uint16_t	N;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_u16(&N, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	N;
}

static
int16_t		loop_get_s16	(int16_t m, int16_t def, int16_t M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	int16_t	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_s16(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
uint32_t	loop_get_u32	(uint32_t m, uint32_t def, uint32_t M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	uint32_t	N;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_u32(&N, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	N;
}

static
int32_t		loop_get_s32	(int32_t m, int32_t def, int32_t M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	int32_t	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_s32(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
uint64_t	loop_get_u64	(uint64_t m, uint64_t def, uint64_t M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	uint64_t	N;

	N	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_u64(&N, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	N;
}

static
int64_t		loop_get_s64	(int64_t m, int64_t def, int64_t M,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	int64_t	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_s64(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
ptrdiff_t	loop_get_pdif	(ptrdiff_t m, ptrdiff_t def, ptrdiff_t M,
				 uint8_t attempts)
{
	char		buff[BUFSIZ];
	ptrdiff_t	Z;

	Z	= def;
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_pdif(&Z, m, def, M, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	Z;
}

static
char		loop_get_ch	(const char *restrict valid,
				 bool skip_space, bool ignore_case,
				 uint8_t attempts)
{
	char	buff[BUFSIZ];
	char	c;

	c	= valid[0];
	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_ch(&c, valid, skip_space, ignore_case, buff))
			goto err;
		break;
err:
		alx_perror(NULL);
	}

	return	c;
}

static
int		loop_get_fname	(const char *restrict path,
				 char fname[restrict FILENAME_MAX],
				 bool exist,
				 uint8_t attempts)
{
	char	buff[FILENAME_MAX];

	for (uint8_t i = 0; i <= (attempts - 1u); i++) {
		if (!fgets(buff, ARRAY_SIZE(buff), stdin))
			goto err;
		if (alx_sscan_fname(path, fname, exist, buff))
			goto err;
		return	0;
err:
		alx_perror(NULL);
	}

	return	-1;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
