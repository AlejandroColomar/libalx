/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/string/strgrep.h"

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
	TEST_ALX_STRNFGREP,
	TEST_ALX_STRLFGREP,
	TEST_ALX_STRNCASEFGREP,
	TEST_ALX_STRLCASEFGREP,
	TEST_ALX_STRNFGREPV,
	TEST_ALX_STRLFGREPV,
	TEST_ALX_STRNCASEFGREPV,
	TEST_ALX_STRLCASEFGREPV,

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
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\n",
	"abcdefghi\nAsDfFfF gh\n...    \n x",
	"abcdefghi\nAsDfFfF gh\n...    \n x",
	"abcdefghi\n...    \n x",
	"abcdefghi\n...    \n x"
};


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
int	test_alx_strnfgrep(void);
int	test_alx_strlfgrep(void);
int	test_alx_strncasefgrep(void);
int	test_alx_strlcasefgrep(void);
int	test_alx_strnfgrepv(void);
int	test_alx_strlfgrepv(void);
int	test_alx_strncasefgrepv(void);
int	test_alx_strlcasefgrepv(void);


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
int main(void)
{
	int	fail = false;

	if (test_alx_strnfgrep())
		fail = true;
	if (test_alx_strlfgrep())
		fail = true;
	if (test_alx_strncasefgrep())
		fail = true;
	if (test_alx_strlcasefgrep())
		fail = true;
	if (test_alx_strnfgrepv())
		fail = true;
	if (test_alx_strlfgrepv())
		fail = true;
	if (test_alx_strncasefgrepv())
		fail = true;
	if (test_alx_strlcasefgrepv())
		fail = true;

	if (!fail)
		print_ok("	libalx/string/strgrep\n");

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
int	test_alx_strnfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strnfgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strnfgrep()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlfgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlfgrep()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strncasefgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strncasefgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNCASEFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strncasefgrep()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlcasefgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlcasefgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLCASEFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlcasefgrep()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strnfgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strnfgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strnfgrepv()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlfgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlfgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlfgrepv()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strncasefgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strncasefgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNCASEFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strncasefgrepv()\n");
		return	1;
	}

	return	0;
}

int	test_alx_strlcasefgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlcasefgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLCASEFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlcasefgrepv()\n");
		return	1;
	}

	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
