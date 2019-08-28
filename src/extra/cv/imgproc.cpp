/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/imgproc.hpp"

#include <cstdbool>
#include <cstddef>
#include <cstdint>

#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include "libalx/base/compiler/restrict.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_CV_MAX_KSIZE	(50)
#define ALX_CV_MAX_DERIVATIVE	(20)


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
/* ----- Image filtering */
int	alx::CV::dilate		(class cv::Mat *restrict img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::dilate(*img, *img, cv::Mat(), cv::Point(-1,-1), i,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	return	0;
}

int	alx_cv_dilate		(void *restrict img, ptrdiff_t i)
{
	return	alx::CV::dilate((class cv::Mat *)img, i);
}

int	alx::CV::erode		(class cv::Mat *restrict img, ptrdiff_t i)
{

	if (i < 1)
		return	1;
	cv::erode(*img, *img, cv::Mat(), cv::Point(-1,-1), i,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	return	0;
}

int	alx_cv_erode		(void *restrict img, ptrdiff_t i)
{
	return	alx::CV::erode((class cv::Mat *)img, i);
}

int	alx::CV::dilate_erode	(class cv::Mat *restrict img, ptrdiff_t i)
{

	if (alx::CV::dilate(img, i))
		return	1;
	if (alx::CV::erode(img, i))
		return	1;

	return	0;
}

int	alx_cv_dilate_erode	(void *restrict img, ptrdiff_t i)
{
	return	alx::CV::dilate_erode((class cv::Mat *)img, i);
}

int	alx::CV::erode_dilate	(class cv::Mat *restrict img, ptrdiff_t i)
{

	if (alx::CV::erode(img, i))
		return	1;
	if (alx::CV::dilate(img, i))
		return	1;

	return	0;
}

int	alx_cv_erode_dilate	(void *restrict img, ptrdiff_t i)
{
	return	alx::CV::erode_dilate((class cv::Mat *)img, i);
}

int	alx::CV::smooth		(class cv::Mat *restrict img,
				 int method, ptrdiff_t ksize)
{

	if (!(ksize % 2)  ||  ksize < 3  ||  ksize > ALX_CV_MAX_KSIZE)
		return	1;

	switch (method) {
	case alx::CV::SMOOTH_MEAN:
		cv::blur(*img, *img, cv::Size(ksize, ksize), cv::Point(-1,-1),
							cv::BORDER_DEFAULT);
		break;
	case alx::CV::SMOOTH_GAUSS:
		cv::GaussianBlur(*img, *img, cv::Size(ksize, ksize), 0, 0,
							cv::BORDER_DEFAULT);
		break;
	case alx::CV::SMOOTH_MEDIAN:
		cv::medianBlur(*img, *img, ksize);
		break;
	default:
		return	1;
	}

	return	0;
}

int	alx_cv_smooth		(void *restrict img, int method, int ksize)
{
	return	alx::CV::smooth((class cv::Mat *)img, method, ksize);
}

int	alx::CV::sobel		(class cv::Mat *restrict img,
				 int dx, int dy, ptrdiff_t ksize)
{

	if (dx < 0 || dy < 0)
		return	1;
	if (dx > ALX_CV_MAX_DERIVATIVE || dy > ALX_CV_MAX_DERIVATIVE)
		return	1;
	if (!(ksize % 2)  ||  ksize < -1  ||  ksize > ALX_CV_MAX_KSIZE)
		return	1;
	cv::Sobel(*img, *img, -1, dx, dy, ksize, 1, 0, cv::BORDER_DEFAULT);

	return	0;
}

int	alx_cv_sobel		(void *restrict img,
				 int dx, int dy, ptrdiff_t ksize)
{
	return	alx::CV::sobel((class cv::Mat *)img, dx, dy, ksize);
}

int	alx::CV::border		(class cv::Mat *restrict img, ptrdiff_t size)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;

	tmp	= cv::Mat(cv::Size(img->cols + size, img->rows + size), CV_8U);
	cv::copyMakeBorder(*img, tmp, size, size, size, size,
					cv::BORDER_CONSTANT, cv::Scalar(0));
	tmp.copyTo(*img);
	tmp.release();
	return	0;
}

int	alx_cv_border		(void *restrict img, ptrdiff_t size)
{
	return	alx::CV::border((class cv::Mat *)img, size);
}

/* ----- Geometric image transformations */
int	alx::CV::mirror		(class cv::Mat *restrict img, int axis)
{

	if (axis < 0 || axis > 1)
		return	1;
	cv::flip(*img, *img, axis);

	return	0;
}

int	alx_cv_mirror		(void *restrict img, int axis)
{
	return	alx::CV::mirror((class cv::Mat *)img, axis);
}

int	alx::CV::rotate_orto	(class cv::Mat *restrict img, int n)
{

	switch (n) {
	case 1:
		/* Rotate: transpose and flip around horizontal axis: flip_mode=0 */
		cv::transpose(*img, *img);
		cv::flip(*img, *img, 0);
		break;
	case 2:
		/* Rotate: Flip both axises: flip_mode=-1 */
		cv::flip(*img, *img, -1);
		break;
	case 3:
		/* Rotate: transpose and flip around vertical axis: flip_mode=1 */
		cv::transpose(*img, *img);
		cv::flip(*img, *img, 1);
		break;
	default:
		return	1;
	}

	return	0;
}

int	alx_cv_rotate_orto	(void *restrict img, int n)
{
	return	alx::CV::rotate_orto((class cv::Mat *)img, n);
}

int	alx::CV::rotate		(class cv::Mat *restrict img,
				 double x, double y, double angle)
{
	class cv::Point_<float>	center;
	class cv::Mat		map_matrix;

	if (x < 0 || y < 0 || (x >= img->cols) || (y >= img->rows))
		return	1;
	if (angle < -360 || angle > 360)
		return	1;
	center.x	= x;
	center.y	= y;

	map_matrix	= cv::getRotationMatrix2D(center, angle, 1);
	cv::warpAffine(*img, *img, map_matrix, img->size(), cv::INTER_LINEAR,
				cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));
	map_matrix.release();

	return	0;
}

int	alx_cv_rotate		(void *restrict img,
				 double x, double y, double angle)
{
	return	alx::CV::rotate((class cv::Mat *)img, x, y, angle);
}

int	alx::CV::rotate_2rect	(class cv::Mat *restrict img,
				 const class cv::RotatedRect *restrict rect_rot)
{
	ptrdiff_t	x;
	ptrdiff_t	y;
	double		angle;

	x	= rect_rot->center.x;
	y	= rect_rot->center.y;
	angle	= rect_rot->angle;
	/* If angle is < -45º, it is taking into acount the incorrect side */
	if (angle < -45.0)
		angle += 90.0;

	return	alx::CV::rotate(img, x, y, angle);
}

int	alx_cv_rotate_2rect		(void *restrict img,
					 const void *restrict rect_rot)
{
	return	alx::CV::rotate_2rect((class cv::Mat *)img,
				(const class cv::RotatedRect *)rect_rot);
}

/* ----- Miscellaneous image transformations */
int	alx::CV::adaptive_thr	(class cv::Mat *restrict img,
				 int method, int thr_typ, int ksize)
{

	if (img->channels() != 1)
		return	1;
	if (method < 0 || method > 1)
		return	1;
	if (thr_typ < 0 || thr_typ > 1)
		return	1;
	if (!(ksize % 2) || ksize < 3 || ksize > ALX_CV_MAX_KSIZE)
		return	1;
	cv::adaptiveThreshold(*img, *img, UINT8_MAX, method, thr_typ, ksize, 0);

	return	0;
}

int	alx_cv_adaptive_thr	(void *restrict img,
				 int method, int thr_typ, int ksize)
{
	return	alx::CV::adaptive_thr((class cv::Mat *)img,
						method, thr_typ, ksize);
}

int	alx::CV::cvt_color	(class cv::Mat *restrict img, int method)
{

	if (img->channels() != 3)
		return	1;
	if (method < 0 || method > cv::COLOR_COLORCVT_MAX)
		return	1;
	cv::cvtColor(*img, *img, method, 0);

	return	0;
}

int	alx_cv_cvt_color	(void *restrict img, int method)
{
	return	alx::CV::cvt_color((class cv::Mat *)img, method);
}

void	alx::CV::cvt_res_8b	(class cv::Mat *restrict img)
{
	class cv::Mat	tmp;

	img->convertTo(tmp, CV_8U);
	tmp.copyTo(*img);

	tmp.release();
}

void	alx_cv_cvt_res_8b	(void *restrict img)
{
	alx::CV::cvt_res_8b((class cv::Mat *)img);
}

int	alx::CV::distance_transform(class cv::Mat *restrict img)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;
	cv::distanceTransform(*img, tmp, CV_DIST_L2, CV_DIST_MASK_PRECISE);
	tmp.copyTo(*img);

	tmp.release();
	return	0;
}

int	alx_cv_distance_transform(void *restrict img)
{
	return	alx::CV::distance_transform((class cv::Mat *)img);
}

int	alx::CV::distance_transform_8b(class cv::Mat *restrict img)
{
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	1;
	cv::distanceTransform(*img, tmp, CV_DIST_L2, CV_DIST_MASK_PRECISE);
	/* DistanceTransform gives CV_32F image */
	tmp.convertTo(*img, CV_8U);

	tmp.release();
	return	0;
}

int	alx_cv_distance_transform_8b(void *restrict img)
{
	return	alx::CV::distance_transform_8b((class cv::Mat *)img);
}

int	alx::CV::threshold	(class cv::Mat *restrict img,
				 int thr_typ, int thr_val)
{

	if (img->channels() != 1)
		return	1;
	if (thr_typ < 0 || thr_typ > 4)
		return	1;
	if (thr_typ < -1 || thr_typ > UINT8_MAX)
		return	1;
	if (thr_val == -1)
		thr_typ	|= cv::THRESH_OTSU;
	cv::threshold(*img, *img, thr_val, UINT8_MAX, thr_typ);

	return	0;
}

int	alx_cv_threshold	(void *restrict img, int thr_typ, int thr_val)
{
	return	alx::CV::threshold((class cv::Mat *)img, thr_typ, thr_val);
}

/* ----- Histograms */
int	alx::CV::histogram1D	(class cv::Mat *restrict hist,
				 const class cv::Mat *restrict img)
{
	const	int	h_size		= 256;
	const	int	h_height	= 100;
	const	float	h_range_arr[]	= {0.0, 256.0};
	const	float	*h_range	= {h_range_arr};
	class cv::Mat	tmp;

	if (img->channels() != 1)
		return	-1;
	*hist	= cv::Mat::zeros(cv::Size(h_size, h_height), CV_8UC3);

	cv::calcHist(img, 1, 0, cv::Mat(), tmp, 1, &h_size, &h_range,
								true, false);
	/* Normalize the result to [0, rows - 1] */
	cv::normalize(tmp, tmp, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								 cv::Mat());
	/* Draw hist into tmp */
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(i, hist->rows - 0),
				cv::Point(i, hist->rows - tmp.at<float>(i)),
				cv::Scalar(UINT8_MAX, 0, 0), 1, 8, 0);
	}

	tmp.release();
	return	0;
}

int	alx_cv_histogram1D	(void *restrict hist, const void *restrict img)
{
	return	alx::CV::histogram1D((class cv::Mat *)hist,
						(const class cv::Mat *)img);
}

int	alx::CV::histogram3D	(class cv::Mat *restrict hist,
				 const class cv::Mat *restrict img)
{
	const	int	h_size		= 256;
	const	int	h_height	= 100;
	const	float	h_range_arr[]	= {0.0, 256.0};
	const	float	*h_range	= {h_range_arr};
	class cv::Mat	cmp[3];
	class cv::Mat	tmp0;
	class cv::Mat	tmp1;
	class cv::Mat	tmp2;

	if (img->channels() != 3)
		return	-1;
	*hist	= cv::Mat::zeros(cv::Size(h_size * 3, h_height), CV_8UC3);

	/* Write components into cmp[] */
	cv::split(*img, cmp);
	/* Write components into cmp[] */
	cv::calcHist(&cmp[0], 1, 0, cv::Mat(), tmp0, 1, &h_size, &h_range,
								true, false);
	cv::calcHist(&cmp[1], 1, 0, cv::Mat(), tmp1, 1, &h_size, &h_range,
								true, false);
	cv::calcHist(&cmp[2], 1, 0, cv::Mat(), tmp2, 1, &h_size, &h_range,
								true, false);
	/* Normalize the result to [0, rows - 1] */
	cv::normalize(tmp0, tmp0, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	cv::normalize(tmp1, tmp1, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	cv::normalize(tmp2, tmp2, 0, hist->rows - 1, cv::NORM_MINMAX, -1,
								cv::Mat());
	/* Draw hist into hist_img */
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i, hist->rows - 0),
				cv::Point(3 * i,
					hist->rows - tmp0.at<float>(i)),
				cv::Scalar(UINT8_MAX, 0, 0), 1, 8, 0);
	}
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i + 1, hist->rows - 0),
				cv::Point(3 * i + 1,
					hist->rows - tmp1.at<float>(i)),
				cv::Scalar(0, UINT8_MAX, 0), 1, 8, 0);
	}
#pragma GCC ivdep
	for (ptrdiff_t i = 0; i < h_size; i++) {
		cv::line(*hist, cv::Point(3 * i + 2, hist->rows - 0),
				cv::Point(3 * i + 2,
					hist->rows - tmp2.at<float>(i)),
				cv::Scalar(0, 0, UINT8_MAX), 1, 8, 0);
	}

	cmp[0].release();
	cmp[1].release();
	cmp[2].release();
	tmp0.release();
	tmp1.release();
	tmp2.release();
	return	0;
}

int	alx_cv_histogram3D	(void *restrict hist, const void *restrict img)
{
	return	alx::CV::histogram3D((class cv::Mat *)hist,
						(const class cv::Mat *)img);
}

/* ----- Structural analysis and shape descriptors */
int	alx::CV::contours	(class cv::Mat *restrict img,
				 class std::vector<
					class std::vector<
					class cv::Point_<
					int>>>  *restrict contours)
{
	class cv::Mat	hierarchy;

	if (img->channels() != 1)
		return	-1;
	cv::findContours(*img, *contours, hierarchy, CV_RETR_EXTERNAL,
							CV_CHAIN_APPROX_SIMPLE);
	/* Set image to black */
	img->setTo(cv::Scalar(0));
	/* Draw contours in color */
	cv::drawContours(*img, *contours, -1, cv::Scalar(UINT8_MAX), 1, 8,
						hierarchy, 1, cvPoint(0, 0));

	hierarchy.release();
	return	0;
}

int	alx_cv_contours		(void *restrict img, void *restrict contours)
{
	return	alx::CV::contours((class cv::Mat *)img,
				  (class std::vector<
					class std::vector<
					class cv::Point_<int>>>  *)contours);
}

void	alx::CV::contour_dimensions(const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour,
				 double *restrict area,
				 double *restrict perimeter)
{

	if (area)
		*area		= cv::contourArea(*contour, false);
	if (perimeter)
		*perimeter	= cv::arcLength(*contour, true);
}

void	alx_cv_contour_dimensions(const void *restrict contour,
				 double *restrict area,
				 double *restrict perimeter)
{
	alx::CV::contour_dimensions((const class std::vector <
						class cv::Point_ <
						int>>  *)contour,
					area, perimeter);
}

void	alx::CV::bounding_rect	(class cv::Rect_ <int> *restrict rect,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect	= cv::boundingRect(*contour);
}

void	alx_cv_bounding_rect	(void *restrict rect,
				 const void *restrict contour)
{
	alx::CV::bounding_rect((class cv::Rect_ <int> *)rect,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::fit_ellipse	(class cv::RotatedRect *restrict rect_rot,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect_rot	= cv::fitEllipse(*contour);
}

void	alx_cv_fit_ellipse	(void *restrict rect_rot,
				 const void *restrict contour)
{
	alx::CV::fit_ellipse((class cv::RotatedRect *)rect_rot,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::min_area_rect	(class cv::RotatedRect *restrict rect_rot,
				 const class std::vector <
					class cv::Point_ <
					int>>  *restrict contour)
{
	*rect_rot	= cv::minAreaRect(*contour);
}

void	alx_cv_min_area_rect	(void *restrict rect_rot,
				 const void *restrict contour)
{
	alx::CV::min_area_rect((class cv::RotatedRect *)rect_rot,
					(const class std::vector <
						class cv::Point_ <
						int>>  *)contour);
}

void	alx::CV::draw_rect	(class cv::Mat *restrict img,
				 const class cv::Rect_ <int> *restrict rect)
{
	class cv::Point_ <float>	vertices[4];

	vertices[0].x	= rect->x;
	vertices[0].y	= rect->y;
	vertices[1].x	= rect->x + rect->width;
	vertices[1].y	= rect->y;
	vertices[2].x	= rect->x + rect->width;
	vertices[2].y	= rect->y + rect->height;
	vertices[3].x	= rect->x;
	vertices[3].y	= rect->y + rect->height;
	cv::line(*img, cv::Point(vertices[0].x, vertices[0].y),
				cv::Point(vertices[1].x, vertices[1].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[1].x, vertices[1].y),
				cv::Point(vertices[2].x, vertices[2].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[2].x, vertices[2].y),
				cv::Point(vertices[3].x, vertices[3].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[3].x, vertices[3].y),
				cv::Point(vertices[0].x, vertices[0].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
}

void	alx_cv_draw_rect	(void *restrict img,
				 const void *restrict rect)
{
	alx::CV::draw_rect((class cv::Mat *)img,
					(const class cv::Rect_<int> *)rect);
}

void	alx::CV::draw_rect_rot	(class cv::Mat *restrict img,
				 class cv::RotatedRect *restrict rect_rot)
{
	class cv::Point_ <float>	vertices[4];

	rect_rot->points(vertices);
	cv::line(*img, cv::Point(vertices[0].x, vertices[0].y),
				cv::Point(vertices[1].x, vertices[1].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[1].x, vertices[1].y),
				cv::Point(vertices[2].x, vertices[2].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[2].x, vertices[2].y),
				cv::Point(vertices[3].x, vertices[3].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
	cv::line(*img, cv::Point(vertices[3].x, vertices[3].y),
				cv::Point(vertices[0].x, vertices[0].y),
				CV_RGB(0, 0, UINT8_MAX), 1, 8, 0);
}

void	alx_cv_draw_rect_rot	(void *restrict img,
				 const void *restrict rect_rot)
{
	alx::CV::draw_rect_rot((class cv::Mat *)img,
					(class cv::RotatedRect *)rect_rot);
}

/* ----- Feature detection */
#if 0
/* TODO: Tune parameters */
void	img_cv_hough_circles	(class cv::Mat *imgptr, const void *data)
{
	const	struct Img_Iface_Data_Hough_Circles	*data_cast;
	class std::vector <class cv::Vec <float, 3>>	*circles;
	class cv::Point_ <int>	center;
	int			radius;
	double			dist_min;
	double			param_1;
	double			param_2;
	int			radius_min;
	int			radius_max;
	ptrdiff_t		size;

	data_cast	= (const struct Img_Iface_Data_Hough_Circles *)data;
	circles		= data_cast->circles;
	dist_min	= data_cast->dist_min;
	param_1		= data_cast->param_1;
	param_2		= data_cast->param_2;
	radius_min	= data_cast->radius_min;
	radius_max	= data_cast->radius_max;

	/* Get circles */
	cv::HoughCircles(*imgptr, *circles, CV_HOUGH_GRADIENT, 1, dist_min,
				param_1, param_2, radius_min, radius_max);

	/* Set image to black */
	imgptr->setTo(cv::Scalar(0));

	/* Draw circles */
	size	= circles->size();
	for (ptrdiff_t i = 0; i < size; i++) {
		center.x	= cvRound((*circles)[i][0]);
		center.y	= cvRound((*circles)[i][1]);
		radius		= cvRound((*circles)[i][2]);

		/* Draw the circle center */
/*		cv::circle(*imgptr, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);*/

		/* Draw the circle outline */
		cv::circle(*imgptr, center, radius, cv::Scalar(250), 1, 8, 0);
	}
}
#endif


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
