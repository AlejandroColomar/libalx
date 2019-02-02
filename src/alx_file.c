/******************************************************************************
 *	Copyright (C) 2017	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include <errno.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>

	#include "libalx/io/alx_file.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
	#define BUFF_SIZE_TEXT	(1048576)

#if defined(__unix__)
	#define BEGINNING	"\n┌──────────────────────────────────────────────────────────────────────────────┐\n"
	#define ENDING		"└──────────────────────────────────────────────────────────────────────────────┘\n\n"
#else
	#define BEGINNING	"\n________________________________________________________________________________\n"
	#define ENDING		"________________________________________________________________________________\n\n"
#endif

	#define ERR_FPTR_MSG	"¡ FILE error !"
	#define ERR_FSIZE_MSG	"¡ FILE is too big !"


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
void	alx_snprint_file	(char *dest, int destsize, const char *fpath)
{
	char	buff [BUFF_SIZE_TEXT];
	FILE	*fp;
	long	len;

	/* Open file */
	fp	= fopen(fpath, "r");

#if 0
	/* Implemented using getc instead of fread */
	char	*str;
	int64_t	c;

	if (fp) {
		str	= buff;
		while (((c = getc(fp)) != EOF) && str < BUFF_SIZE_TEXT) {
			sprintf(p, "%c", (char)c);
			str++;
		}
		fclose(fp);
	} else {
		puts(ERR_FPTR_MSG);
		printf(" errno = %i;\n", errno);
	}
#else
	if (fp) {
		/* File lenght */
		fseek(fp, 0, SEEK_END);
		len	= ftell(fp);
		fseek(fp, 0, SEEK_SET);

		/* Read file into buff and append '\0' */
		if (len < BUFF_SIZE_TEXT) {
			fread(buff, sizeof(char), len, fp);
			buff[len]	= '\0';
		} else {
			/* Prevent buffer overflow */
			puts(ERR_FSIZE_MSG);
		}

		/* Close file */
		fclose(fp);
	} else {
		/* File error */
		puts(ERR_FPTR_MSG);
		printf(" errno = %i;\n", errno);
	}
#endif

	/* Print into dest */
	snprintf(dest, destsize, "%s", buff);
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
