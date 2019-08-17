/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/alx.hpp"

#include <cmath>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include <algorithm>

#include <opencv2/core.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/base/compiler/size.hpp"
#include "libalx/extra/gsl/rstat/median.hpp"
#include "libalx/extra/gsl/statistics/mean.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/
enum	Cell {
	NOT_LOCAL_MAX,
	MAYBE_LOCAL_MAX,
	LOCAL_MAX
};


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
int	alx::CV::maximum_flt		(const class cv::Mat *restrict img,
					 float *restrict max)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	float	img_pix;

	if (img->channels() != 1)
		return	-1;

	*max	= 0.0f;
	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);
		if (img_pix > *max)
			*max = img_pix;
	}
	}

	return	0;
}

int	alx_cv_maximum_flt		(const void *restrict img,
					 float *restrict max)
{
	return	alx::CV::maximum_flt((const class cv::Mat *)img, max);
}

int	alx::CV::maximum_u8		(const class cv::Mat *restrict img,
					 uint8_t *restrict max)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	uint8_t	img_pix;

	if (img->channels() != 1)
		return	-1;

	*max	= 0;
	for (ptrdiff_t i = 0; i < rows; i++) {
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<uint8_t>(i, j);
		if (img_pix > *max)
			*max = img_pix;
	}
	}

	return	0;
}

int	alx_cv_maximum_u8		(const void *restrict img,
					 uint8_t *restrict max)
{
	return	alx::CV::maximum_u8((const class cv::Mat *)img, max);
}

int	alx::CV::local_max		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	/* Minimum distance between local maxima */
	const int	dist = 8;
	/* Minimum value of local maxima */
	const float	val_min = 2.0f;
	class cv::Mat	imgtmp;
	int		arr_tmp[rows][cols];
	bool		wh;
	/* pointer to a pixel (in img) */
	float		img_pix;
	/* pointer to a pixel near img_pix (in img) */
	float		near_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);
	imgtmp.convertTo(imgtmp, CV_8U);
	imgtmp	= cv::Scalar(UINT8_MAX);

	memset(arr_tmp, 0, ARRAY_BYTES(arr_tmp));
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);

		if (img_pix < val_min)
			continue;
		for (ptrdiff_t k = (i + dist); k >= (i - dist); k--) {
		for (ptrdiff_t l = (j + dist); l >= (j - dist); l--) {
			if ((k >= 0) && (k < rows)) {
			if ((l >= 0) && (l < cols)) {
			if ((l != i) || (k != j)) {
				near_pix	= img->at<float>(k, l);
				if (near_pix > img_pix)
					goto not_maxima;
				if (near_pix == img_pix)
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
			}
			}
		}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		arr_tmp[i][j]	= NOT_LOCAL_MAX;
		;
	}
	}

	do {
		wh	= false;
#pragma GCC ivdep
		for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
		for (ptrdiff_t j = 0; j < cols; j++) {
			img_pix		= img->at<float>(i, j);
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ptrdiff_t k = (i+dist); k >= (i-dist); k--) {
			for (ptrdiff_t l = (j+dist); l >= (j-dist); l--) {
				if ((k >= 0) && (k < rows)) {
				if ((l >= 0) && (l < cols)) {
				if ((l != i) || (k != j)) {
					near_pix = img->at<float>(k, l);
					if (near_pix == img_pix) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
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
		if (!arr_tmp[i][j])
			imgtmp.at<uint8_t>(i, j)	= 0;
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
#if 0
int	alx::CV::skeleton_B		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	/* (Half of the) width of the skeleton */
	const ptrdiff_t	width = 8;
	int_fast16_t	cnt_slopes;
	bool		slope_up;
	class cv::Mat	imgtmp;
	/* pointer to a pixel (in img) */
	float		img_pix;
	/* pointer to a pixel near img_pix (in img) */
	float		near_pix;
	float		near_pix_last;
	float		near_pix_last2;
	float		max_or_min;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);
	imgtmp.convertTo(imgtmp, CV_8U);
	imgtmp	= cv::Scalar(0);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);

		/* Discard pixels of value 1 in skeleton */
		if (img_pix <= 2 * width) {
			imgtmp.at<uint8_t>(i, j)	= 0;
			continue;
		}
		if ((i - width < 0)  ||  (i + width >= rows)) {
			imgtmp.at<uint8_t>(i, j)	= 0;
			continue;
		}
		if ((j - width < 0)  ||  (j + width >= cols)) {
			imgtmp.at<uint8_t>(i, j)	= 0;
			continue;
		}
		cnt_slopes	= 0;
		max_or_min	= 0;
		near_pix_last	= img->at<float>(i+width, j+width-1);
		near_pix_last2	= img->at<float>(i+width, j+width-2);
		if (near_pix_last > near_pix_last2)
			slope_up	= true;
		else
			slope_up	= false;

		for (ptrdiff_t k = (i + width); k >= (i - width); k--) {
			near_pix	= img->at<float>(k, j+width);

			if (!slope_up) {
				if (near_pix > near_pix_last + 0.5f) {
				if (near_pix_last > near_pix_last2 + 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					cnt_slopes++;
					slope_up	= true;
					max_or_min	= near_pix;
				}
				}
				}
			} else {
				if (near_pix < near_pix_last - 0.5f) {
				if (near_pix_last < near_pix_last2 - 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					slope_up	= false;
				}
				}
				}
			}
			near_pix_last2	= near_pix_last;
			near_pix_last	= near_pix;
		}
		for (ptrdiff_t l = (j + width); l >= (j - width); l--) {
			near_pix	= img->at<float>(i-width, l);

			if (!slope_up) {
				if (near_pix > near_pix_last + 0.5f) {
				if (near_pix_last > near_pix_last2 + 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					cnt_slopes++;
					slope_up	= true;
					max_or_min	= near_pix;
				}
				}
				}
			} else {
				if (near_pix < near_pix_last - 0.5f) {
				if (near_pix_last < near_pix_last2 - 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					slope_up	= false;
				}
				}
				}
			}
			near_pix_last2	= near_pix_last;
			near_pix_last	= near_pix;
		}
		for (ptrdiff_t k = (i - width); k <= (i + width); k++) {
			near_pix	= img->at<float>(k, j-width);

			if (!slope_up) {
				if (near_pix > near_pix_last + 0.5f) {
				if (near_pix_last > near_pix_last2 + 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					cnt_slopes++;
					slope_up	= true;
					max_or_min	= near_pix;
				}
				}
				}
			} else {
				if (near_pix < near_pix_last - 0.5f) {
				if (near_pix_last < near_pix_last2 - 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					slope_up	= false;
				}
				}
				}
			}
			near_pix_last2	= near_pix_last;
			near_pix_last	= near_pix;
		}
		for (ptrdiff_t l = (j - width); l <= (j + width); l++) {
			near_pix	= img->at<float>(i+width, l);

			if (!slope_up) {
				if (near_pix > near_pix_last + 0.5f) {
				if (near_pix_last > near_pix_last2 + 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					cnt_slopes++;
					slope_up	= true;
					max_or_min	= near_pix;
				}
				}
				}
			} else {
				if (near_pix < near_pix_last - 0.5f) {
				if (near_pix_last < near_pix_last2 - 0.5f) {
				if (fabsf(near_pix - max_or_min) > 1.0f) {
					slope_up	= false;
				}
				}
				}
			}
			near_pix_last2	= near_pix_last;
			near_pix_last	= near_pix;
		}

		if (cnt_slopes > 1)
			imgtmp.at<uint8_t>(i, j)	= UINT8_MAX;
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_skeleton_B			(void *restrict img)
{
	return	alx::CV::skeleton_B((class cv::Mat *)img);
}

int	alx::CV::skeleton_A		(class cv::Mat *restrict img)
{
	const ptrdiff_t	rows = img->rows;
	const ptrdiff_t	cols = img->cols;
	/* (Half of the) width of the skeleton */
	const ptrdiff_t	width = 10;
	ptrdiff_t	dist_x;
	ptrdiff_t	dist_y;
	bool		skeleton;
	int_fast16_t	cnt_lo[width];
	int_fast16_t	cnt_hi_or_eq[width];
	class cv::Mat	imgtmp;
	/* pointer to a pixel (in img) */
	float		img_pix;
	/* pointer to a pixel near img_pix (in img) */
	float		near_pix;

	if (img->channels() != 1)
		return	1;
	/* Tmp image copy */
	img->copyTo(imgtmp);
	imgtmp.convertTo(imgtmp, CV_8U);
	imgtmp	= cv::Scalar(UINT8_MAX);

#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < rows; i++) {
#pragma GCC ivdep
	for (ptrdiff_t j = 0; j < cols; j++) {
		img_pix		= img->at<float>(i, j);

		/* Discard pixels of value 1 in skeleton */
		if (img_pix <= 2.0f) {
			imgtmp.at<uint8_t>(i, j)	= 0;
			continue;
		}

		memset(cnt_lo, 0, ARRAY_BYTES(cnt_lo));
		memset(cnt_hi_or_eq, 0, ARRAY_BYTES(cnt_hi_or_eq));

#pragma GCC ivdep
		for (ptrdiff_t k = (i + width); k >= (i - width); k--) {
#pragma GCC ivdep
		for (ptrdiff_t l = (j + width); l >= (j - width); l--) {
			near_pix	= img->at<float>(k, l);

			dist_x	= abs(k - i);
			dist_y	= abs(l - j);

			if ((k >= 0)  &&  (k < rows)) {
			if ((l >= 0)  &&  (l < cols)) {
			if (dist_x  ||  dist_y) {
				if (near_pix < img_pix)
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
			if (cnt_lo[r] > (cnt_hi_or_eq[r] + (1.3) * (r + 1)))
				skeleton	= true;
		}

		if (!skeleton)
			imgtmp.at<uint8_t>(i, j)	= 0;
	}
	}

	imgtmp.copyTo(*img);
	imgtmp.release();
	return	0;
}

int	alx_cv_skeleton_A			(void *restrict img)
{
	return	alx::CV::skeleton_A((class cv::Mat *)img);
}
#endif
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
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
