/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/zbar/zbar.h"

#include <stddef.h>

#include <zbar.h>

#include "libalx/base/stdio/printf/snprintfs.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx_zbar_read	(ptrdiff_t bufsiz,
			 char bcode_data[static restrict bufsiz],
			 char bcode_type[static restrict bufsiz],
			 const void *restrict imgdata,
			 ptrdiff_t rows, ptrdiff_t cols,
			 int type)
{
	const struct zbar_symbol_s	*symbol;
	struct zbar_image_scanner_s	*scanner;
	struct zbar_image_s		*image_zb;
	ptrdiff_t	n;
	int		status;

	status	= -1;

	/* create & configure a reader */
	scanner	= zbar_image_scanner_create();
	if (zbar_image_scanner_set_config(scanner, type, ZBAR_CFG_ENABLE, 1))
		goto out_free_scn;

	/* wrap image data */
	image_zb = zbar_image_create();
	zbar_image_set_format(image_zb, *(int*)"GREY");
	zbar_image_set_size(image_zb, cols, rows);
	zbar_image_set_data(image_zb, imgdata, cols * rows, NULL);

	/* scan the image for barcodes */
	n	= zbar_scan_image(scanner, image_zb);
	if (n != 1)
		goto err;

	/* extract results */
	symbol	= zbar_image_first_symbol(image_zb);
	if (alx_snprintfs(bcode_type, NULL, bufsiz, "%s", zbar_get_symbol_name(
						zbar_symbol_get_type(symbol))))
		goto err;
	if (alx_snprintfs(bcode_data, NULL, bufsiz, "%s", zbar_symbol_get_data(
						symbol)))
		goto err;

	status	= 0;
err:
	zbar_image_destroy(image_zb);
out_free_scn:
	zbar_image_scanner_destroy(scanner);
	return	status;
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
