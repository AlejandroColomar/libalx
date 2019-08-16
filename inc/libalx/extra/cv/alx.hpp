/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/extra/cv/alx.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cstdint>

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
[[gnu::nonnull]]
int	alx_cv_maximum_flt	(const void *restrict img,
				 float *restrict max);
[[gnu::nonnull]]
int	alx_cv_maximum_u8	(const void *restrict img,
				 uint8_t *restrict max);
[[gnu::nonnull]]
int	alx_cv_local_max	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_skeleton_B	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_skeleton_A	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_skeleton_endpts	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_lines_horizontal	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_lines_vertical	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_mean_horizontal	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_mean_vertical	(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_median_horizontal(void *restrict img);
[[gnu::nonnull]]
int	alx_cv_median_vertical	(void *restrict img);
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {
namespace CV {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
[[gnu::nonnull]]
int	maximum_flt		(const class cv::Mat *restrict img,
				 float *restrict max);
[[gnu::nonnull]]
int	maximum_u8		(const class cv::Mat *restrict img,
				 uint8_t *restrict max);
[[gnu::nonnull]]
int	local_max		(class cv::Mat *restrict img);
#if 0
[[gnu::nonnull]]
int	skeleton_B		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	skeleton_A		(class cv::Mat *restrict img);
#endif
[[gnu::nonnull]]
int	skeleton_endpts		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	lines_horizontal	(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	lines_vertical		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	mean_horizontal		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	mean_vertical		(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	median_horizontal	(class cv::Mat *restrict img);
[[gnu::nonnull]]
int	median_vertical		(class cv::Mat *restrict img);


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace CV */
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
