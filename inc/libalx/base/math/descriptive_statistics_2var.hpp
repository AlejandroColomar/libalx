/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_DESCRIPTIVE_STATISTICS_2VAR_HPP
#define ALX_MATH_DESCRIPTIVE_STATISTICS_2VAR_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cmath>
#include <cstddef>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_DS1V_N_MIN	(1)
#define ALX_DS1V_N_MAX	(PTRDIFF_MAX)
#define ALX_DS1V_x_MIN	(-INFINITY)
#define ALX_DS1V_x_MAX	(INFINITY)
#define ALX_DS1V_y_MIN	(-INFINITY)
#define ALX_DS1V_y_MAX	(INFINITY)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/
struct	Alx_Descriptive_Statistics_2var_Ldbl {
	long double	ux;
	long double	ox2;
	long double	ox;
	long double	a;
	long double	Aa;
	long double	b;
	long double	Ab;

	long double	uy;
	long double	oy2;
	long double	oy;
	long double	c;
	long double	Ac;
	long double	d;
	long double	Ad;

	long double	oxy;
	long double	r;
	long double	Vr;
	long double	R2;
};

struct	Alx_Descriptive_Statistics_2var {
	double	ux;
	double	ox2;
	double	ox;
	double	a;
	double	Aa;
	double	b;
	double	Ab;

	double	uy;
	double	oy2;
	double	oy;
	double	c;
	double	Ac;
	double	d;
	double	Ad;

	double	oxy;
	double	r;
	double	Vr;
	double	R2;
};

struct	Alx_Descriptive_Statistics_2var_Flt {
	float	ux;
	float	ox2;
	float	ox;
	float	a;
	float	Aa;
	float	b;
	float	Ab;

	float	uy;
	float	oy2;
	float	oy;
	float	c;
	float	Ac;
	float	d;
	float	Ad;

	float	oxy;
	float	r;
	float	Vr;
	float	R2;
};


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
extern	"C"
{
struct Alx_Descriptive_Statistics_2var_Ldbl
alx_descriptive_statistics_2var_ldbl	(ptrdiff_t N,
					const long double x[restrict],
					const long double y[restrict]);
struct Alx_Descriptive_Statistics_2var
alx_descriptive_statistics_2var		(ptrdiff_t N,
					const double x[restrict],
					const double y[restrict]);
struct Alx_Descriptive_Statistics_2var_Flt
alx_descriptive_statistics_2var_flt	(ptrdiff_t N,
					const float x[restrict],
					const float y[restrict]);
}


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/descriptive_statistics_2var.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
