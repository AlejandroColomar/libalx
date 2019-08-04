/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/ocr/ocr.h"

#include <stddef.h>

#include <tesseract/capi.h>

#include "libalx/base/stdio/printf/snprintfs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_ocr_read	(ptrdiff_t bufsiz, char text[static restrict bufsiz],
			 void *restrict img, ptrdiff_t w, ptrdiff_t h,
			 int B_per_pix, int B_per_line,
			 int lang, int conf)
{
	struct TessBaseAPI	*handle_ocr;
	const char		*lang_str;
	const char		*conf_str;
	char			*txt;
	int			status;

	/* Language */
	switch (lang) {
	case ALX_OCR_LANG_ENG:
		lang_str = "eng";
		break;
	case ALX_OCR_LANG_SPA:
		lang_str = "spa";
		break;
	case ALX_OCR_LANG_CAT:
		lang_str = "cat";
		break;
	case ALX_OCR_LANG_DIGITS:
		lang_str = "digits";
		break;
	case ALX_OCR_LANG_DIGITS_COMMA:
		lang_str = "digits_comma";
		break;
	default:
		return	-4;
	}

	/* Config file */
	switch (conf) {
	case ALX_OCR_CONF_PRICE:
		conf_str = "usr/local/share/libalx/extra/ocr/price";
		break;
	case ALX_OCR_CONF_PRICE_EUR:
		conf_str = "usr/local/share/libalx/extra/ocr/price_eur";
		break;
	case ALX_OCR_CONF_PRICE_GBP:
		conf_str = "usr/local/share/libalx/extra/ocr/price_gbp";
		break;
	case ALX_OCR_CONF_PRICE_USD:
		conf_str = "usr/local/share/libalx/extra/ocr/price_usd";
		break;
	default:
		return	-3;
	}

	status	= -2;

	/* init OCR */
	handle_ocr	= TessBaseAPICreate();
#if defined(OEM_LSTM_ONLY)
	TessBaseAPIInit2(handle_ocr, NULL, lang_str, OEM_LSTM_ONLY);
#else
	TessBaseAPIInit2(handle_ocr, NULL, lang_str, OEM_DEFAULT);
#endif
/*	TessBaseAPIInit2(handle_ocr, NULL, lang_str, OEM_TESSERACT_LSTM_COMBINED);*/

	/* Configure OCR (whitelist chars) */
	if (conf)
		TessBaseAPIReadConfigFile(handle_ocr, conf_str);

	/* scan image for text */
	TessBaseAPISetImage(handle_ocr, img, w, h, B_per_pix, B_per_line);
	if (TessBaseAPIRecognize(handle_ocr, NULL))
		goto err;
	txt	= TessBaseAPIGetUTF8Text(handle_ocr);
	if (!txt)
		goto err;

	status	= alx_snprintfs(text, NULL, bufsiz, "%s", txt);

	/* Cleanup */
	TessDeleteText(txt);
err:
	TessBaseAPIEnd(handle_ocr);
	TessBaseAPIDelete(handle_ocr);
	return	status;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
