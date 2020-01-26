/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	BSD-2-Clause			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/nix/ucat/ucat.h"

#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "libalx/base/compiler/size.h"
#include "libalx/extra/curl/fcurl/fclose.h"
#include "libalx/extra/curl/fcurl/fopen.h"
#include "libalx/extra/curl/fcurl/fread.h"
#include "libalx/extra/curl/fcurl/URL_FILE.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
/* TODO:  cat flags */
#if 0
#define FLAG_b	(ALX_NIX_UCAT_FLAG_b)
#define FLAG_e	(ALX_NIX_UCAT_FLAG_e)
#define FLAG_l	(ALX_NIX_UCAT_FLAG_l)
#define FLAG_n	(ALX_NIX_UCAT_FLAG_n)
#define FLAG_s	(ALX_NIX_UCAT_FLAG_s)
#define FLAG_t	(ALX_NIX_UCAT_FLAG_t)
#define FLAG_v	(ALX_NIX_UCAT_FLAG_v)

#define is_set(flags, flag)	((bool)(flags & flag))
#endif


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_nix_ucat	(const char *url, uint32_t flags)
{
	ALX_URL_FILE	*istream;

	if (!url  ||  !strcmp(url, "-")) {
		istream	= alx_url_stdin;
	} else {
		istream	= alx_url_fopen(url, "r");
		if (!istream)
			return	errno;
	}

	alx_nix_ucat__(stdout, istream, flags);

	if (istream != alx_url_stdin)
		return	alx_url_fclose(istream);

	return	0;
}

void	alx_nix_ucat__	(FILE *restrict ostream, ALX_URL_FILE *restrict istream,
			 uint32_t flags)
{
	size_t	n;
	char	buf[BUFSIZ];

	(void)flags;

	do {
		n	= alx_url_fread(buf, 1, ARRAY_SIZE(buf), istream);
		fwrite(buf, 1, n, ostream);
	} while (n);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/
/* TODO:  cat flags */
#if 0
static
int	cook_ucat	(FILE *restrict ostream, ALX_URL_FILE *restrict istream,
			 int flags)
{
	int	c;
	int	line;
	bool	gobble;
	wint_t	wch;
	int	rval	= 0;

	/* Reset EOF condition on stdin. */
	if (istream == alx_url_stdin) {
		if (alx_url_feof(alx_url_stdin))
			clearerr(stdin);
	}

	line	= 0;
	gobble	= false;
	for (int prev = '\n'; (c = alx_url_fgetc(istream)) != EOF; prev = c) {
		if (prev == '\n') {
			if (is_set(flags, FLAG_s)) {
				if (c == '\n') {
					if (gobble)
						continue;
					gobble	= true;
				} else {
					gobble	= false;
				}
			}
			if (is_set(flags, FLAG_n)) {
				if (!is_set(flags, FLAG_b) || c != '\n') {
					(void)fprintf(ostream, "%6i\t", ++line);
					if (ferror(ostream))
						break;
				} else if (is_set(flags, FLAG_e)) {
					(void)fprintf(ostream, "%6s\t", "");
					if (ferror(ostream))
						break;
				}
			}
		}
		if (c == '\n') {
			if (is_set(flags, FLAG_e)) {
				if (fputc('$') == EOF)
					break;
			}
		} else if (c == '\t') {
			if (is_set(flags, FLAG_t)) {
				if (fputc('^', ) == EOF)
					break;
				if (fputc('I') == EOF)
					break;
				continue;
			}
		} else if (is_set(flags, FLAG_v)) {
			(void)alx_url_ungetc(c, fp);
			wch = alx_url_fgetwc(fp);
			if (wch == WEOF)
				break;
			if (!iswprint(wch)) {
				if (putchar('M') == EOF || putchar('-') == EOF)
					break;
				wch = toascii(wch);
			}
			if (iswcntrl(wch)) {
				c = toascii(wch);
				if (c == '\177')
					c = '?';
				else
					c |= 0100;
				if (putchar('^') == EOF || putchar(c) == EOF)
					break;
				continue;
			}
			if (putwchar(wch) == WEOF)
				break;
			c = -1;
			continue;
		}
		if (putchar(c) == EOF)
			break;
	}
	if (alx_url_ferror(fp)) {
		warn("%s", fname);
		rval = 1;
		alx_url_clearerr(fp);
	}
	if (alx_url_ferror(stdout))
		err(1, "stdout");

	return	rval;
}
#endif


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/

