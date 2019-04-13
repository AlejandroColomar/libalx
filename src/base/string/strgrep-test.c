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
	TEST_ALX_STRSFGREP,
	TEST_ALX_STRNCASEFGREP,
	TEST_ALX_STRLCASEFGREP,
	TEST_ALX_STRSCASEFGREP,
	TEST_ALX_STRNFGREPV,
	TEST_ALX_STRLFGREPV,
	TEST_ALX_STRSFGREPV,
	TEST_ALX_STRNCASEFGREPV,
	TEST_ALX_STRLCASEFGREPV,
	TEST_ALX_STRSCASEFGREPV,

	TESTS
};


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/
static	const char	 str[54] =
	"abcdefghi\nasdffff\tgh\nAsDfFfF gh\n...    \n  asd \"\n x\nasd";
static	const char	*const pattern = "asd";
static	const char	*const expected[TESTS] = {
	"asdffff\tgh\n  asd \"\nasd",
	"asdffff\tgh\n  asd \"\nasd",
	"asdffff\tgh\n  asd \"\nasd",
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\nasd",
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\nasd",
	"asdffff\tgh\nAsDfFfF gh\n  asd \"\nasd",
	"abcdefghi\nAsDfFfF gh\n...    \n x\n",
	"abcdefghi\nAsDfFfF gh\n...    \n x\n",
	"abcdefghi\nAsDfFfF gh\n...    \n x\n",
	"abcdefghi\n...    \n x\n",
	"abcdefghi\n...    \n x\n",
	"abcdefghi\n...    \n x\n"
};


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/
static	int	test_alx_strnfgrep(void);
static	int	test_alx_strlfgrep(void);
static	int	test_alx_strsfgrep(void);
static	int	test_alx_strncasefgrep(void);
static	int	test_alx_strlcasefgrep(void);
static	int	test_alx_strscasefgrep(void);
static	int	test_alx_strnfgrepv(void);
static	int	test_alx_strlfgrepv(void);
static	int	test_alx_strsfgrepv(void);
static	int	test_alx_strncasefgrepv(void);
static	int	test_alx_strlcasefgrepv(void);
static	int	test_alx_strscasefgrepv(void);


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
	if (test_alx_strsfgrep())
		fail = true;
	if (test_alx_strncasefgrep())
		fail = true;
	if (test_alx_strlcasefgrep())
		fail = true;
	if (test_alx_strscasefgrep())
		fail = true;
	if (test_alx_strnfgrepv())
		fail = true;
	if (test_alx_strlfgrepv())
		fail = true;
	if (test_alx_strsfgrepv())
		fail = true;
	if (test_alx_strncasefgrepv())
		fail = true;
	if (test_alx_strlcasefgrepv())
		fail = true;
	if (test_alx_strscasefgrepv())
		fail = true;

	if (!fail)
		print_ok("	libalx/string/strgrep\n");

	return	0;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/
static	int	test_alx_strnfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strnfgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strnfgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRNFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strlfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlfgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlfgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRLFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strsfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strsfgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRSFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strsfgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRSFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strncasefgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strncasefgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNCASEFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strncasefgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRNCASEFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strlcasefgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlcasefgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLCASEFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlcasefgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRLCASEFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strscasefgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strscasefgrep(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRSCASEFGREP], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strscasefgrep()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRSCASEFGREP]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strnfgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strnfgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strnfgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRNFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strlfgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlfgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlfgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRLFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strsfgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strsfgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRSFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strsfgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRSFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strncasefgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strncasefgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRNCASEFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strncasefgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRNCASEFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strlcasefgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strlcasefgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRLCASEFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strlcasefgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRLCASEFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}

static	int	test_alx_strscasefgrepv(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strscasefgrepv(sizeof(buff), buff, str, pattern);
	cmp	= strncmp(buff, expected[TEST_ALX_STRSCASEFGREPV], sizeof(buff));
	if (cmp) {
		print_fail("	libalx/string/strgrep:	alx_strscasefgrepv()\n");
		printf("Expected:\n%s\n", expected[TEST_ALX_STRSCASEFGREPV]);
		printf("Result:\n%s\n", buff);
		return	1;
	}

	return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
