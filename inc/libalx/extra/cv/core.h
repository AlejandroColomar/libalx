/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/core.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* typedef **************************************************************
 ******************************************************************************/
/*
 * These are C++ classes which are accessed through a `void *`.
 * We just pass them around calls to C++  functions wrapped with `void *`,
 * so all the logic is in C++, and we just can't access them in C.
 * These types help visually differentiate between all the `void *`.
 */
typedef	void	img_s;
typedef	void	rect_s;
typedef	void	rect_rot_s;
typedef	void	conts_s;
typedef	void	cont_s;


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/
enum	Alx_Cv_Cmp {
	ALX_CV_CMP_BLUE,
	ALX_CV_CMP_GREEN,
	ALX_CV_CMP_RED
};


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* function prototypes **************************************************
 ******************************************************************************/
/* ----- alloc / free */
__attribute__((nonnull))
int	alx_cv_alloc_img	(img_s **restrict img);
__attribute__((nonnull))
void	alx_cv_free_img		(img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_alloc_rect	(rect_s **restrict rect);
__attribute__((nonnull))
void	alx_cv_free_rect	(rect_s *restrict rect);
__attribute__((nonnull))
int	alx_cv_alloc_rect_rot	(rect_rot_s **restrict rect_rot);
__attribute__((nonnull))
void	alx_cv_free_rect_rot	(rect_rot_s *restrict rect_rot);
__attribute__((nonnull))
int	alx_cv_alloc_conts	(conts_s **restrict conts);
__attribute__((nonnull))
void	alx_cv_free_conts	(conts_s *restrict conts);
/* ----- init / deinit */
__attribute__((nonnull))
int	alx_cv_init_img		(img_s *restrict img, ptrdiff_t w, ptrdiff_t h);
__attribute__((nonnull))
void	alx_cv_deinit_img	(img_s *restrict img);
__attribute__((nonnull))
void	alx_cv_init_conts	(conts_s *restrict img);
__attribute__((nonnull))
void	alx_cv_deinit_conts	(conts_s *restrict img);
__attribute__((nonnull))
int	alx_cv_init_rect	(rect_s *restrict rect,
				 ptrdiff_t x, ptrdiff_t y,
				 ptrdiff_t w, ptrdiff_t h);
/* ----- Extract */
__attribute__((nonnull))
void	alx_cv_extract_imgdata	(const img_s *restrict img, void **data,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h,
				 ptrdiff_t *restrict B_per_pix,
				 ptrdiff_t *restrict B_per_line);
__attribute__((nonnull))
void	alx_cv_extract_rect	(const rect_s *restrict rect,
				 ptrdiff_t *restrict x, ptrdiff_t *restrict y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
__attribute__((nonnull))
void	alx_cv_extract_rect_rot	(const rect_rot_s *restrict rect_rot,
				 ptrdiff_t *restrict ctr_x,
				 ptrdiff_t *restrict ctr_y,
				 ptrdiff_t *restrict w, ptrdiff_t *restrict h);
/* ----- Copy */
__attribute__((nonnull))
void	alx_cv_clone		(img_s *restrict clone,
				 const img_s *restrict img);
/* ----- Pixel */
__attribute__((nonnull))
int	alx_cv_pixel_get_u8	(const img_s *restrict img,
				 unsigned char *restrict val,
				 ptrdiff_t x, ptrdiff_t y);
__attribute__((nonnull))
int	alx_cv_pixel_set_u8	(img_s *restrict img,
				 unsigned char val, ptrdiff_t x, ptrdiff_t y);
__attribute__((nonnull))
int	alx_cv_pixel_get_flt	(const img_s *restrict img,
				 float *restrict val, ptrdiff_t x, ptrdiff_t y);
/* ----- ROI */
__attribute__((nonnull))
void	alx_cv_roi_set		(img_s *restrict img,
				 const rect_s *restrict rect);
/* ----- Operations on arrays */
__attribute__((nonnull))
int	alx_cv_and_2ref		(img_s *restrict img,
				 const img_s *restrict ref);
__attribute__((nonnull))
void	alx_cv_invert		(img_s *restrict img);
__attribute__((nonnull))
int	alx_cv_or_2ref		(img_s *restrict img,
				 const img_s *restrict ref);
__attribute__((nonnull))
int	alx_cv_component	(img_s *restrict img, ptrdiff_t cmp);


/******************************************************************************
 ******* inline functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
