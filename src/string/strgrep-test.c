/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/string/strgrep.h"

#include <stdbool.h>
#include <stdio.h>

#include "libalx/../../test/test.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE	(100)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Tests {
	TEST_ALX_STRNGREPF,
	TEST_ALX_STRLGREPF,
	TEST_ALX_STRNCASEGREPF,
	TEST_ALX_STRLCASEGREPF,

	TESTS
};


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
static	const char	*const str =
	"abcdefghi\nasdffff\tgh\nAsDfFfF gh\n...    \n  asd \"\n x";
static	const char	*const pattern = "asd";
static	const char	*const expected[TESTS] = {
	"asdffff\tgh\n  asd \"\n",
	"asdffff\tgh\n  asd \"\n",
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\n",
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\n"
};


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
int	test_alx_strngrepF(void);
int	test_alx_strlgrepF(void);
int	test_alx_strncasegrepF(void);
int	test_alx_strlcasegrepF(void);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
int main(void)
{
	int	fail = false;

	if (test_alx_strngrepF())
		fail = true;
	if (test_alx_strlgrepF())
		fail = true;
	if (test_alx_strncasegrepF())
		fail = true;
	if (test_alx_strlcasegrepF())
		fail = true;

	if (!fail)
		print_ok("	libalx/string/strgrep\n");

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
int	test_alx_strngrepF(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strngrepF(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNGREPF], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strngrepF()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlgrepF(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlgrepF(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLGREPF], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlgrepF()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strncasegrepF(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strncasegrepF(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNCASEGREPF], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strncasegrepF()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlcasegrepF(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlcasegrepF(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLCASEGREPF], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlcasegrepF()\n");
		return	1;
	}

	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
