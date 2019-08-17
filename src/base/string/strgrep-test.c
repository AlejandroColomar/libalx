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

#include "libalx/base/compiler/size.h"

#include "libalx/../../test/test.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define BUFF_SIZE	(100)


/******************************************************************************
 ******* enum / struct / union ************************************************
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
 ******* static prototypes ****************************************************
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
 ******* static function definitions ******************************************
 ******************************************************************************/
static	int	test_alx_strnfgrep(void)
{
	char	buff[BUFF_SIZE];
	int	cmp;

	alx_strnfgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRNFGREP], ARRAY_SIZE(buff));
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

	alx_strlfgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRLFGREP], ARRAY_SIZE(buff));
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

	alx_strsfgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRSFGREP], ARRAY_SIZE(buff));
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

	alx_strncasefgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRNCASEFGREP], ARRAY_SIZE(buff));
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

	alx_strlcasefgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRLCASEFGREP], ARRAY_SIZE(buff));
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

	alx_strscasefgrep(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRSCASEFGREP], ARRAY_SIZE(buff));
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

	alx_strnfgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRNFGREPV], ARRAY_SIZE(buff));
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

	alx_strlfgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRLFGREPV], ARRAY_SIZE(buff));
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

	alx_strsfgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRSFGREPV], ARRAY_SIZE(buff));
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

	alx_strncasefgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRNCASEFGREPV], ARRAY_SIZE(buff));
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

	alx_strlcasefgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRLCASEFGREPV], ARRAY_SIZE(buff));
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

	alx_strscasefgrepv(ARRAY_SIZE(buff), buff, str, pattern);
	cmp = strncmp(buff, expected[TEST_ALX_STRSCASEFGREPV], ARRAY_SIZE(buff));
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
