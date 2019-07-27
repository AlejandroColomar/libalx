/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx.hpp"

#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include <algorithm>

#include <opencv2/core/core.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/extra/gsl/rstat/median.hpp"
#include "libalx/extra/gsl/statistics/mean.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Cell {
	NOT_LOCAL_MAX,
	MAYBE_LOCAL_MAX,
	LOCAL_MAX
};


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx::CV::local_max		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	/* Minimum distance between local maxima */
	const int	dist = 2;
	/* Minimum value of local maxima */
	const uint8_t	val_min = 1;
	class cv::Mat	imgtmp;
	int		arr_tmp[rows][cols];
	bool		wh;
	/* pointer to a pixel (in img) */
	const uint8_t	*img_pix;
	/* pointer to a pixel near img_pix (in img) */
	const uint8_t	*near_pix;
	/* pointer to a pixel (same position as img_pix, but in imgtmp) */
	uint8_t		*tmp_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);

	memset(arr_tmp, 0, sizeof(arr_tmp));
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->data + i*step + j;
		if (*img_pix < val_min)
			continue;
		for (ptrdiff_t k = (i + dist); k >= (i - dist); k--) {
		for (ptrdiff_t l = (j + dist); l >= (j - dist); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
				near_pix	= img->data + k*step + l;
				if (*near_pix > *img_pix)
					goto not_maxima;
				if (*near_pix == *img_pix)
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do {
		wh	= false;
#pragma GCC ivdep
		for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
		for (ptrdiff_t j = 0; j < cols; j++) {
			img_pix		= img->data + i*step + j;
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = (i+dist); k >= (i-dist); k--) {
			for (ptrdiff_t l = (j+dist); l >= (j-dist); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
					near_pix = img->data + k*step + l;
					if (*near_pix == *img_pix) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
				}
			}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= 0;
		}
		}
	} while (wh);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		if (!arr_tmp[i][j]) {
			tmp_pix		= imgtmp.data + i * step + j;
			*tmp_pix	= 0;
		}
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_local_max		(void *restrict img)
{
	return	alx::CV::local_max((class cv::Mat *)img);
}

int	alx::CV::skeleton		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	/* (Half of the) width of the skeleton */
	const ptrdiff_t	width = 5;
	ptrdiff_t	dist_x;
	ptrdiff_t	dist_y;
	bool		skeleton;
	int_fast16_t	cnt_lo[width];
	int_fast16_t	cnt_hi_or_eq[width];
	class cv::Mat	imgtmp;
	/* pointer to a pixel (in img) */
	const uint8_t	*img_pix;
	/* pointer to a pixel near img_pix (in img) */
	const uint8_t	*near_pix;
	/* pointer to a pixel (same position as img_pix, but in imgtmp) */
	uint8_t		*tmp_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->data + i * step + j;
		tmp_pix		= imgtmp.data + i * step + j;

		if (!(*img_pix)) {
			*tmp_pix	= 0;
			continue;
		}

		memset(cnt_lo, 0, sizeof(cnt_lo));
		memset(cnt_hi_or_eq, 0, sizeof(cnt_hi_or_eq));

#pragma GCC ivdep
		for (ptrdiff_t k = (i + width); k >= (i - width); k--) {
#pragma GCC ivdep
		for (ptrdiff_t l = (j + width); l >= (j - width); l--) {
			near_pix	= img->data + k * step + l;

			dist_x	= abs(k - i);
			dist_y	= abs(l - j);

			if ((k >= 0)  &&  (k < rows)) {
			if ((l >= 0)  &&  (l < cols)) {
			if (dist_x  ||  dist_y) {
				if (*near_pix < *img_pix)
					cnt_lo[std::max(dist_x, dist_y)]++;
				else
					cnt_hi_or_eq[std::max(dist_x, dist_y)]++;
			}
			}
			}
		}
		}

		skeleton	= false;
#pragma GCC ivdep
		for (ptrdiff_t r = 0; r < width; r++) {
			if (cnt_lo[r] > (cnt_hi_or_eq[r] + (1.6) * (r + 1)))
				skeleton	= true;
		}

		if (skeleton)
			*tmp_pix	= *img_pix;
		else
			*tmp_pix	= 0;
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_skeleton			(void *restrict img)
{
	return	alx::CV::skeleton((class cv::Mat *)img);
}

int	alx::CV::skeleton_endpts	(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	/* (Half of the) width of the skeleton */
	const ptrdiff_t	width = 5;
	bool		branch;
	int_fast8_t	cnt_brnchs;
	class cv::Mat	imgtmp;
	/* pointer to a pixel (in img) */
	const uint8_t	*img_pix;
	/* pointer to a pixel near img_pix (in img) */
	const uint8_t	*near_pix;
	/* pointer to a pixel (same position as img_pix, but in imgtmp) */
	uint8_t		*tmp_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->data + i * step + j;
		tmp_pix		= imgtmp.data + i * step + j;

		if (!(*img_pix)) {
			*tmp_pix = 0;
			continue;
		}
		if ((i - 3*width < 0)  ||  (i + 3*width >= rows)) {
			*tmp_pix = 0;
			continue;
		}
		if ((j - 3*width < 0)  ||  (j + 3*width >= cols)) {
			*tmp_pix = 0;
			continue;
		}
		cnt_brnchs	= 0;
		if (img->data + (i+3*width) * step + (j+3*width - 1))
			branch	= true;
		else
			branch	= false;

		for (ptrdiff_t k = (i + 3*width); k >= (i - 3*width); k--) {
			near_pix	= img->data + k * step + (j+3*width);

			if (!branch) {
				if (*near_pix) {
					cnt_brnchs++;
					branch	= true;
				}
			} else {
				if (!*near_pix)
					branch	= false;
			}
		}
		for (ptrdiff_t l = (j + 3*width); l >= (j - 3*width); l--) {
			near_pix	= img->data + (i-3*width) * step + l;

			if (!branch) {
				if (*near_pix) {
					cnt_brnchs++;
					branch	= true;
				}
			} else {
				if (!*near_pix)
					branch	= false;
			}
		}
		for (ptrdiff_t k = (i - 3*width); k <= (i + 3*width); k++) {
			near_pix	= img->data + k * step + (j-3*width);

			if (!branch) {
				if (*near_pix) {
					cnt_brnchs++;
					branch	= true;
				}
			} else {
				if (!*near_pix)
					branch	= false;
			}
		}
		for (ptrdiff_t l = (j - 3*width); l <= (j + 3*width); l++) {
			near_pix	= img->data + (i+3*width) * step + l;

			if (!branch) {
				if (*near_pix) {
					cnt_brnchs++;
					branch	= true;
				}
			} else {
				if (!*near_pix)
					branch	= false;
			}
		}

		if (cnt_brnchs <= 1)
			*tmp_pix	= *img_pix;
		else
			*tmp_pix	= 0;
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_skeleton_endpts		(void *restrict img)
{
	return	alx::CV::skeleton_endpts((class cv::Mat *)img);
}

int	alx::CV::lines_horizontal	(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	bool		white;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		white	= false;
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			if (*pix) {
				white	= true;
				break;
			}
		}
		if (!white)
			continue;
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= UINT8_MAX;
		}
	}
	return	0;
}

int	alx_cv_lines_horizontal		(void *restrict img)
{
	return	alx::CV::lines_horizontal((class cv::Mat *)img);
}

int	alx::CV::lines_vertical		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	bool		white;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		white	= false;
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			if (*pix) {
				white	= true;
				break;
			}
		}
		if (!white)
			continue;
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= UINT8_MAX;
		}
	}
	return	0;
}

int	alx_cv_lines_vertical		(void *restrict img)
{
	return	alx::CV::lines_vertical((class cv::Mat *)img);
}

int	alx::CV::mean_horizontal	(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	uint8_t		row[cols];
	uint8_t		mean;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			row[j]	= *pix;
		}
		mean	= alx_gsl_stats_mean_u8(cols, row);
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= mean;
		}
	}
	return	0;
}

int	alx_cv_mean_horizontal		(void *restrict img)
{
	return	alx::CV::mean_horizontal((class cv::Mat *)img);
}

int	alx::CV::mean_vertical		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	uint8_t		col[rows];
	uint8_t		mean;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			col[j]	= *pix;
		}
		mean	= alx_gsl_stats_mean_u8(rows, col);
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= mean;
		}
	}
	return	0;
}

int	alx_cv_mean_vertical		(void *restrict img)
{
	return	alx::CV::mean_vertical((class cv::Mat *)img);
}

int	alx::CV::median_horizontal	(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	uint8_t		row [cols];
	uint8_t		median;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			row[j]	= *pix;
		}
		median	= alx_gsl_rstat_median_u8(cols, row);
		for (ptrdiff_t j = 0; j < cols; j++) {
			pix	= img->data + i * step + j;
			*pix	= median;
		}
	}
	return	0;
}

int	alx_cv_median_horizontal	(void *restrict img)
{
	return	alx::CV::median_horizontal((class cv::Mat *)img);
}

int	alx::CV::median_vertical	(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	const ptrdiff_t	step = img->step;
	uint8_t		col [rows];
	uint8_t		median;
	/* pointer to a pixel (in img) */
	uint8_t		*pix;

	if (img->channels() != 1)
		return	1;

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < cols; i++) {
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			col[j]	= *pix;
		}
		median	= alx_gsl_rstat_median_u8(rows, col);
		for (ptrdiff_t j = 0; j < rows; j++) {
			pix	= img->data + j * step + i;
			*pix	= median;
		}
	}
	return	0;
}

int	alx_cv_median_vertical		(void *restrict img)
{
	return	alx::CV::median_vertical((class cv::Mat *)img);
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
