/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core.hpp */


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


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
/* ----- Alloc */
[[gnu::nonnull]]
int	alx_cv_alloc_img	(void **restrict img);
[[gnu::nonnull]]
void	alx_cv_free_img		(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_alloc_rect	(void **restrict rect);
[[gnu::nonnull]]
void	alx_cv_free_rect	(void *restrict rect);
[[gnu::nonnull]]
int	alx_cv_alloc_rect_rot	(void **restrict rect_rot);
[[gnu::nonnull]]
void	alx_cv_free_rect_rot	(void *restrict rect_rot);
[[gnu::nonnull]]
int	alx_cv_alloc_conts	(void **restrict contours);
[[gnu::nonnull]]
void	alx_cv_free_conts	(void *restrict contours);
/* ----- Init */
[[gnu::nonnull]]
int	alx_cv_init_img		(void *restrict img, ptrdiff_t w, ptrdiff_t h);
[[gnu::nonnull]]
void	alx_cv_deinit_img	(void *restrict img);
[[gnu::nonnull]]
void	alx_cv_init_conts	(void *restrict conts);
[[gnu::nonnull]]
void	alx_cv_deinit_conts	(void *restrict conts);
[[gnu::nonnull]]
int	alx_cv_init_rect	(void *restrict rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	alx_cv_extract_imgdata	(const void *restrict img, void **data,
				 ptrdiff_t *restrict rows,
				 ptrdiff_t *restrict cols,
				 ptrdiff_t *restrict width,
				 ptrdiff_t *restrict height,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line);
[[gnu::nonnull(1)]]
void	alx_cv_extract_rect	(const void *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
[[gnu::nonnull(1)]]
void	alx_cv_extract_rect_rot	(const void *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 double *restrict angle);
/* ----- Copy */
[[gnu::nonnull]]
void	alx_cv_clone		(void *restrict clone,
				 const void *restrict img);
/* ----- Pixel */
[[gnu::nonnull]]
int	alx_cv_pixel_get_u8	(const void *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	alx_cv_pixel_set_u8	(void *restrict img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	alx_cv_pixel_get_flt	(const void *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y);
/* ----- ROI */
[[gnu::nonnull]]
void	alx_cv_roi_set		(void *restrict img, const void *restrict rect);
/* ----- Operations on arrays */
[[gnu::nonnull]]
int	alx_cv_and_2ref		(void *restrict img, const void *restrict ref);
[[gnu::nonnull]]
void	alx_cv_invert		(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_or_2ref		(void *restrict img, const void *restrict ref);
[[gnu::nonnull]]
int	alx_cv_component	(void *restrict img, ptrdiff_t cmp);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Cmp {
	CMP_BLUE,
	CMP_GREEN,
	CMP_RED
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
/* ----- Alloc */
[[gnu::nonnull]]
int	alloc_img	(class cv::Mat **restrict img);
[[gnu::nonnull]]
void	free_img	(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	alloc_rect	(class cv::Rect_<int> **restrict rect);
[[gnu::nonnull]]
void	free_rect	(class cv::Rect_<int> *restrict rect);
[[gnu::nonnull]]
int	alloc_rect_rot	(class cv::RotatedRect **restrict rect_rot);
[[gnu::nonnull]]
void	free_rect_rot	(class cv::RotatedRect *restrict rect_rot);
[[gnu::nonnull]]
int	alloc_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> **restrict contours);
[[gnu::nonnull]]
void	free_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *restrict contours);
/* ----- Init */
[[gnu::nonnull]]
int	init_img	(class cv::Mat *restrict img,
			 ptrdiff_t w, ptrdiff_t h);
[[gnu::nonnull]]
void	deinit_img	(class cv::Mat *restrict img);
[[gnu::nonnull]]
void	init_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *restrict conts);
[[gnu::nonnull]]
void	deinit_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *restrict conts);
[[gnu::nonnull]]
int	init_rect	(class cv::Rect_<int> *restrict rect,
			 ptrdiff_t x, ptrdiff_t y, ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
[[gnu::nonnull(1)]]
void	extract_imgdata	(const class cv::Mat *restrict img, void **data,
			 ptrdiff_t *restrict rows,
			 ptrdiff_t *restrict cols,
			 ptrdiff_t *restrict width,
			 ptrdiff_t *restrict height,
			 ptrdiff_t *restrict B_per_pix,
			 ptrdiff_t *restrict B_per_line);
[[gnu::nonnull(1)]]
void	extract_rect	(const class cv::Rect_<int> *restrict rect,
			 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
			 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
[[gnu::nonnull(1)]]
void	extract_rect_rot(const class cv::RotatedRect *restrict rect_rot,
			 ptrdiff_t *restrict ctr_x, ptrdiff_t *restrict ctr_y,
			 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
			 double *restrict angle);
/* ----- Copy */
[[gnu::nonnull]]
void	clone		(class cv::Mat *restrict clone,
			 const class cv::Mat *restrict img);
/* ----- Pixel */
[[gnu::nonnull]]
int	pixel_get_u8	(const class cv::Mat *restrict img,
			 unsigned char *restrict val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	pixel_set_u8	(class cv::Mat *restrict img,
			 unsigned char val, ptrdiff_t x, ptrdiff_t y);
[[gnu::nonnull]]
int	pixel_get_flt	(const class cv::Mat *restrict img,
			 float *restrict val, ptrdiff_t x, ptrdiff_t y);
/* ----- ROI */
[[gnu::nonnull]]
void	roi_set		(class cv::Mat *restrict img,
			 const class cv::Rect_<int> *restrict rect);
/* ----- Operations on arrays */
[[gnu::nonnull]]
int	and_2ref	(class cv::Mat *restrict img,
			 const class cv::Mat *restrict ref);
[[gnu::nonnull]]
void	invert		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	or_2ref		(class cv::Mat *restrict img,
			 const class cv::Mat *restrict ref);
[[gnu::nonnull]]
int	component	(class cv::Mat *restrict img, ptrdiff_t cmp);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
