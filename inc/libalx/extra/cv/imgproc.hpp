/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstddef>

#include <vector>

#include <opencv2/core.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_THR_OTSU	(-1)


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
/* ----- Image filtering */
[[gnu::nonnull]]
int	alx_cv_dilate		(void *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode		(void *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_dilate_erode	(void *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_erode_dilate	(void *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	alx_cv_smooth		(void *restrict img, int method, int ksize);
[[gnu::nonnull]]
int	alx_cv_sobel		(void *restrict img,
				 int dx, int dy, ptrdiff_t ksize);
[[gnu::nonnull]]
int	alx_cv_border		(void *restrict img, ptrdiff_t size);
/* ----- Geometric image transformations */
[[gnu::nonnull]]
int	alx_cv_mirror		(void *restrict img, int axis);
[[gnu::nonnull]]
int	alx_cv_rotate_orto	(void *restrict img, int n);
[[gnu::nonnull]]
int	alx_cv_rotate		(void *restrict img,
				 double x, double y, double angle);
[[gnu::nonnull]]
int	alx_cv_rotate_2rect	(void *restrict img,
				 const void *restrict rect_rot);
/* ----- Miscellaneous image transformations */
[[gnu::nonnull]]
int	alx_cv_adaptive_thr	(void *restrict img,
				 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	alx_cv_cvt_color	(void *restrict img, int method);
[[gnu::nonnull]]
void	alx_cv_cvt_res_8b	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_distance_transform(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_distance_transform_8b(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_threshold	(void *restrict img, int thr_typ, int thr_val);
/* ----- Histograms */
[[gnu::nonnull]]
int	alx_cv_histogram1D	(void *restrict hist, const void *restrict img);
[[gnu::nonnull]]
int	alx_cv_histogram3D	(void *restrict hist, const void *restrict img);
/* ----- Structural analysis and shape descriptors */
[[gnu::nonnull]]
int	alx_cv_contours		(void *restrict img, void *restrict contours);
[[gnu::nonnull]]
int	alx_cv_contours_dimensions(const void *restrict contours,
				 double *restrict area,
				 double *restrict perimeter);
[[gnu::nonnull]]
void	alx_cv_bounding_rect	(void *restrict rect,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_fit_ellipse	(void *restrict rect_rot,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_min_area_rect	(void *restrict rect_rot,
				 const void *restrict contour);
[[gnu::nonnull]]
void	alx_cv_draw_rect	(void *restrict img,
				 const void *restrict rect);
[[gnu::nonnull]]
void	alx_cv_draw_rect_rot	(void *restrict img,
				 const void *restrict rect_rot);
/* ----- Feature detection */
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Smooth {
	SMOOTH_MEAN = 1,
	SMOOTH_GAUSS,
	SMOOTH_MEDIAN
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
/* ----- Image filtering */
[[gnu::nonnull]]
int	dilate		(class cv::Mat *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode		(class cv::Mat *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	dilate_erode	(class cv::Mat *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	erode_dilate	(class cv::Mat *restrict img, ptrdiff_t i);
[[gnu::nonnull]]
int	smooth		(class cv::Mat *restrict img,
			 int method, ptrdiff_t ksize);
[[gnu::nonnull]]
int	sobel		(class cv::Mat *restrict img,
			 int dx, int dy, ptrdiff_t ksize);
[[gnu::nonnull]]
int	border		(class cv::Mat *restrict img, ptrdiff_t size);
/* ----- Geometric image transformations */
[[gnu::nonnull]]
int	mirror		(class cv::Mat *restrict img, int axis);
[[gnu::nonnull]]
int	rotate_orto	(class cv::Mat *restrict img, int n);
[[gnu::nonnull]]
int	rotate		(class cv::Mat *restrict img,
			 double x, double y, double angle);
[[gnu::nonnull]]
int	rotate_2rect	(class cv::Mat *restrict img,
			 const class cv::RotatedRect *restrict rect_rot);
/* ----- Miscellaneous image transformations */
[[gnu::nonnull]]
int	adaptive_thr	(class cv::Mat *restrict img,
			 int method, int thr_typ, int ksize);
[[gnu::nonnull]]
int	cvt_color	(class cv::Mat *restrict img, int method);
[[gnu::nonnull]]
void	cvt_res_8b	(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	distance_transform(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	distance_transform_8b(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	threshold	(class cv::Mat *restrict img,
			 int thr_typ, int thr_val);
/* ----- Histograms */
[[gnu::nonnull]]
int	histogram1D	(class cv::Mat *restrict hist,
			 const class cv::Mat *restrict img);
[[gnu::nonnull]]
int	histogram3D	(class cv::Mat *restrict hist,
			 const class cv::Mat *restrict img);
/* ----- Structural analysis and shape descriptors */
[[gnu::nonnull]]
int	contours	(class cv::Mat *restrict img,
			 class std::vector<
				class std::vector<
				class cv::Point_<
				int>>>  *restrict contours);
[[gnu::nonnull]]
void	contour_dimensions(const class std::vector<
				class cv::Point_<
				int>>  *restrict contour,
			 double *restrict area,
			 double *restrict perimeter);
[[gnu::nonnull]]
void	bounding_rect	(class cv::Rect_ <int> *restrict rect,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	fit_ellipse	(class cv::RotatedRect *restrict rect_rot,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	min_area_rect	(class cv::RotatedRect *restrict rect_rot,
			 const class std::vector <
				class cv::Point_ <
				int>>  *restrict contour);
[[gnu::nonnull]]
void	draw_rect	(class cv::Mat *restrict img,
			 const class cv::Rect_ <int> *restrict rect);
[[gnu::nonnull]]
void	draw_rect_rot	(class cv::Mat *restrict img,
			 class cv::RotatedRect *restrict rect_rot);
/* ----- Feature detection */


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
