/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/imgproc.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>

#include "libalx/extra/cv/core.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_THR_OTSU	(-1)


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_Cv_Smooth {
	ALX_CV_SMOOTH_MEAN = 1,
	ALX_CV_SMOOTH_GAUSS,
	ALX_CV_SMOOTH_MEDIAN
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
/* ----- Image filtering */
__attribute__((nonnull))
int	alx_cv_dilate		(img_s *restrict img, ptrdiff_t i);
__attribute__((nonnull))
int	alx_cv_erode		(img_s *restrict img, ptrdiff_t i);
__attribute__((nonnull))
int	alx_cv_dilate_erode	(img_s *restrict img, ptrdiff_t i);
__attribute__((nonnull))
int	alx_cv_erode_dilate	(img_s *restrict img, ptrdiff_t i);
__attribute__((nonnull))
int	alx_cv_smooth		(img_s *restrict img, int method, int ksize);
__attribute__((nonnull))
int	alx_cv_sobel		(img_s *restrict img,
				 int dx, int dy, ptrdiff_t ksize);
__attribute__((nonnull))
int	alx_cv_border		(img_s *restrict img, ptrdiff_t size);
/* ----- Geometric image transformations */
__attribute__((nonnull))
int	alx_cv_mirror		(img_s *restrict img, int axis);
__attribute__((nonnull))
int	alx_cv_rotate_orto	(img_s *restrict img, int n);
__attribute__((nonnull))
int	alx_cv_rotate		(img_s *restrict img,
				 double x, double y, double angle);
__attribute__((nonnull))
int	alx_cv_rotate_2rect	(img_s *restrict img,
				 const rect_rot_s *restrict rect_rot);
/* ----- Miscellaneous image transformations */
__attribute__((nonnull))
int	alx_cv_adaptive_thr	(img_s *restrict img,
				 int method, int thr_typ, int ksize);
__attribute__((nonnull))
int	alx_cv_cvt_color	(img_s *restrict img, int method);
__attribute__((nonnull))
void	alx_cv_cvt_res_8b	(img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_distance_transform(img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_distance_transform_8b(img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_threshold	(img_s *restrict img, int thr_typ, int thr_val);
/* ----- Histograms */
__attribute__((nonnull))
int	alx_cv_histogram1D	(img_s *restrict hist, const img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_histogram3D	(img_s *restrict hist, const img_s *restrict img);
/* ----- Structural analysis and shape descriptors */
__attribute__((nonnull))
int	alx_cv_contours		(img_s *restrict img, conts_s *restrict contours);
__attribute__((nonnull, pure))
ptrdiff_t alx_cv_contours_size	(const conts_s *restrict contours);
__attribute__((nonnull))
int	alx_cv_contours_contour	(const cont_s **restrict contour,
				 const conts_s *restrict contours, ptrdiff_t i);
__attribute__((nonnull))
int	alx_cv_contour_dimensions(const cont_s *restrict contour,
				 double *restrict area,
				 double *restrict perimeter);
__attribute__((nonnull))
void	alx_cv_bounding_rect	(rect_s *restrict rect,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_fit_ellipse	(rect_rot_s *restrict rect_rot,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_min_area_rect	(rect_rot_s *restrict rect_rot,
				 const cont_s *restrict contour);
__attribute__((nonnull))
void	alx_cv_draw_rect	(img_s *restrict img,
				 const rect_s *restrict rect);
__attribute__((nonnull))
void	alx_cv_draw_rect_rot	(img_s *restrict img,
				 const rect_rot_s *restrict rect_rot);
/* ----- Feature detection */


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
