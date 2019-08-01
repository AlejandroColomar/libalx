/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/stdio/printf/b.h"

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <printf.h>

#include "libalx/base/compiler/unused.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BIN_REPR_BUFSIZ	(sizeof(uintmax_t) * CHAR_BIT)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/
struct	Printf_Pad {
	char	ch;
	int	len;
};


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static
int	b_output	(FILE *stream, const struct printf_info *info,
			 const void *const args[]);
static
int	b_arginf_sz	(const struct printf_info *info,
			 size_t n, int *argtypes, int *size);

static
uintmax_t b_value	(const struct printf_info *info, const void *arg);
static
int	b_bin_repr	(bool bin[BIN_REPR_BUFSIZ],
			 const struct printf_info *info, const void *arg);
static
int	b_bin_len	(const struct printf_info *info, int min_len);
static
int	b_pad_len	(const struct printf_info *info, int bin_len);
static
int	b_print_prefix	(FILE *stream, const struct printf_info *info);
static
int	b_pad_zeros	(FILE *stream, const struct printf_info *info,
			 int min_len);
static
int	b_print_number	(FILE *stream, const struct printf_info *info,
			 bool bin[BIN_REPR_BUFSIZ], int min_len, int bin_len);
static
char	pad_ch		(const struct printf_info *info);
static
int	pad_spaces	(FILE *stream, int pad_len);




/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_printf_b_init	(void)
{

	if (register_printf_specifier('b', b_output, b_arginf_sz))
		return	-1;
	if (register_printf_specifier('B', b_output, b_arginf_sz))
		return	-1;

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static
int	b_output	(FILE *stream, const struct printf_info *info,
			 const void *const args[])
{
	struct	Printf_Pad	pad = {0};
	bool	bin[BIN_REPR_BUFSIZ];
	int	min_len;
	int	bin_len;
	int	len;
	int	tmp;

	len = 0;

	min_len	= b_bin_repr(bin, info, args[0]);
	bin_len	= b_bin_len(info, min_len);

	pad.ch = pad_ch(info);
	if (pad.ch == ' ')
		pad.len = b_pad_len(info, bin_len);

	/* Padding with ' ' (right aligned) */
	if ((pad.ch == ' ')  &&  !info->left) {
		tmp = pad_spaces(stream, pad.len);
		if (tmp == EOF)
			return	EOF;
		len += tmp;
	}

	/* "0b"/"0B" prefix */
	if (info->alt) {
		tmp = b_print_prefix(stream, info);
		if (tmp == EOF)
			return	EOF;
		len += tmp;
	}
	
	/* Padding with '0' */
	if (pad.ch == '0') {
		tmp = b_pad_zeros(stream, info, min_len);
		if (tmp == EOF)
			return	EOF;
		len += tmp;
	}

	/* Print number (including leading 0s to fill precission) */
	tmp = b_print_number(stream, info, bin, min_len, bin_len);
	if (tmp == EOF)
		return	EOF;
	len += tmp;

	/* Padding with ' ' (left aligned) */
	if (info->left) {
		tmp = pad_spaces(stream, pad.len);
		if (tmp == EOF)
			return	EOF;
		len += tmp;
	}

	return	len;
}

static
int	b_arginf_sz	(const struct printf_info *info,
			 size_t n, int *argtypes, int *size)
{

	UNUSED(info);
	UNUSED(size);

	if (n > 0)
		argtypes[0] = PA_INT;

	return 1;
}

static
uintmax_t b_value	(const struct printf_info *info, const void *arg)
{

	if (info->is_long_double)
		return	*(unsigned long long *)arg;
	if (info->is_long)
		return	*(unsigned long *)arg;
	if (info->is_char)
		return	*(unsigned char *)arg;
	if (info->is_short)
		return	*(unsigned short *)arg;
	return	*(unsigned *)arg;
}

static
int	b_bin_repr	(bool bin[BIN_REPR_BUFSIZ],
			 const struct printf_info *info, const void *arg)
{
	uintmax_t	val;
	int		min_len;

	val	= b_value(info, arg);

	memset(bin, 0, sizeof(bin[0]) * BIN_REPR_BUFSIZ);
	for (min_len = 0; val; min_len++) {
		if (val % 2)
			bin[min_len]	= 1;
		val >>= 1;
	}

	if (!min_len)
		return	1;
	return	min_len;
}

static
int	b_bin_len	(const struct printf_info *info, int min_len)
{

	if (info->prec > min_len)
		return	info->prec;
	return	min_len;
}

static
int	b_pad_len	(const struct printf_info *info, int bin_len)
{
	int	pad_len;

	pad_len = info->width - bin_len;
	if (info->alt)
		pad_len -= 2;
	if (info->group)
		pad_len -= (bin_len - 1) / 4;
	if (pad_len < 0)
		pad_len	= 0;

	return	pad_len;
}

static
int	b_print_prefix	(FILE *stream, const struct printf_info *info)
{
	int	len;

	len = 0;
	if (fputc('0', stream) == EOF)
		return	EOF;
	len++;
	if (fputc(info->spec, stream) == EOF)
		return	EOF;
	len++;

	return	len;
}

static
int	b_pad_zeros	(FILE *stream, const struct printf_info *info,
			 int min_len)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = info->width - (info->alt * 2);
	if (info->group)
		tmp -= tmp / 5 - !(tmp % 5);
	for (int i = tmp - 1; i > min_len - 1; i--) {
		if (fputc('0', stream) == EOF)
			return	EOF;
		len++;
		if (info->group  &&  !(i % 4)) {
			if (fputc('_', stream) == EOF)
				return	EOF;
			len++;
		}
	}

	return	len;
}

static
int	b_print_number	(FILE *stream, const struct printf_info *info,
			 bool bin[BIN_REPR_BUFSIZ], int min_len, int bin_len)
{
	int	len;

	len	= 0;

	/* Print leading zeros to fill precission */
	for (int i = bin_len - 1; i > min_len - 1; i--) {
		if (fputc('0', stream) == EOF)
			return	EOF;
		len++;
		if (info->group  &&  !(i % 4)) {
			if (fputc('_', stream) == EOF)
				return	EOF;
			len++;
		}
	}

	/* Print number */
	for (int i = min_len - 1; i; i--) {
		if (fputc('0' + bin[i], stream) == EOF)
			return	EOF;
		len++;
		if (info->group  &&  !(i % 4)) {
			if (fputc('_', stream) == EOF)
				return	EOF;
			len++;
		}
	}
	if (fputc('0' + bin[0], stream) == EOF)
		return	EOF;
	len++;

	return	len;
}

static
char	pad_ch		(const struct printf_info *info)
{

	if ((info->prec != -1)  ||  (info->pad == ' ')  ||  info->left)
		return	' ';
	return	'0';
}

static
int	pad_spaces	(FILE *stream, int pad_len)
{
	int	len;

	len = 0;
	for (int i = pad_len; i; i--) {
		if (fputc(' ', stream) == EOF)
			return	EOF;
		len++;
	}

	return	len;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
