/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/ocr/ocr.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
[[gnu::nonnull]]
int	alx_ocr_read	(ptrdiff_t bufsiz, char text[static restrict bufsiz],
			 void *restrict img, ptrdiff_t w, ptrdiff_t h,
			 int B_per_pix, int B_per_line,
			 int lang, int conf);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace ocr {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Lang {
	LANG_ENG,
	LANG_SPA,
	LANG_CAT,
	LANG_DIGITS,
	LANG_DIGITS_COMMA
};

enum	Conf {
	CONF_PRICE = 1,
	CONF_PRICE_EUR,
	CONF_PRICE_GBP,
	CONF_PRICE_USD
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace ocr */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
