/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/descriptive_statistics_2var.h"

#include <errno.h>
#include <math.h>
#include <stddef.h>

#include "libalx/base/math/array_multiplication.h"
#include "libalx/base/math/array_sum.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define STRUCT_DS2V_COMPOUND_LITERAL(type, x)	(			\
(type){									\
	.ux	= x,							\
	.ox2	= x,							\
	.ox	= x,							\
	.a	= x,							\
	.Aa	= x,							\
	.b	= x,							\
	.Ab	= x,							\
	.uy	= x,							\
	.oy2	= x,							\
	.oy	= x,							\
	.c	= x,							\
	.Ac	= x,							\
	.d	= x,							\
	.Ad	= x,							\
	.oxy	= x,							\
	.r	= x,							\
	.Vr	= x,							\
	.R2	= x							\
}									\
)

#define STRUCT_DS2V_NaNl	(					\
	STRUCT_DS2V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_2var_Ldbl, nanl(""))		\
)
#define STRUCT_DS2V_NaN		(					\
	STRUCT_DS2V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_2var, nan(""))		\
)
#define STRUCT_DS2V_NaNf	(					\
	STRUCT_DS2V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_2var_Flt, nanf(""))		\
)

#define STRUCT_DS2V_RETURN(type)	(				\
(type){									\
	.ux	= ux,							\
	.ox2	= ox2,							\
	.ox	= ox,							\
	.a	= a,							\
	.Aa	= Aa,							\
	.b	= b,							\
	.Ab	= Ab,							\
	.uy	= uy,							\
	.oy2	= oy2,							\
	.oy	= oy,							\
	.c	= c,							\
	.Ac	= Ac,							\
	.d	= d,							\
	.Ad	= Ad,							\
	.oxy	= oxy,							\
	.r	= r,							\
	.Vr	= Vr,							\
	.R2	= R2							\
}									\
)

#define STRUCT_DS2V_RETURN_LDBL		(				\
	STRUCT_DS2V_RETURN(						\
	struct Alx_Descriptive_Statistics_2var_Ldbl)			\
)
#define STRUCT_DS2V_RETURN_DBL		(				\
	STRUCT_DS2V_RETURN(						\
	struct Alx_Descriptive_Statistics_2var)				\
)
#define STRUCT_DS2V_RETURN_FLT		(				\
	STRUCT_DS2V_RETURN(						\
	struct Alx_Descriptive_Statistics_2var_Flt)			\
)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static functions (prototypes) ****************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
struct Alx_Descriptive_Statistics_2var_Ldbl
alx_descriptive_statistics_2var_ldbl	(ptrdiff_t N,
					const long double x[restrict N],
					const long double y[restrict N])
{
	long double	x2[N], y2[N], xy[N];
	long double	Exi, Exi2;
	long double	Eyi, Eyi2;
	long double	Exiyi;
	long double	Eyiy2, Exix2;
	long double	tmp;

	long double	ux, ox2, ox, a, Aa, b, Ab;
	long double	uy, oy2, oy, c, Ac, d, Ad;
	long double	oxy, r, Vr, R2;

	if (N < ALX_DS2V_N_MIN)
		goto err;

	Exi	= alx_ldbl_array_sum_ldbl(N, x);
	alx_array_multiplication_ldbl(N, x2, x, x);
	Exi2	= alx_ldbl_array_sum_ldbl(N, x2);
	Eyi	= alx_ldbl_array_sum_ldbl(N, y);
	alx_array_multiplication_ldbl(N, y2, y, y);
	Eyi2	= alx_ldbl_array_sum_ldbl(N, y2);
	alx_array_multiplication_ldbl(N, xy, x, y);
	Exiyi	= alx_ldbl_array_sum_ldbl(N, y2);

	ux	= Exi / N;
	ox2	= Exi2 / N - ux * ux;
	ox	= sqrtl(ox2);
	uy	= Eyi / N;
	oy2	= Eyi2 / N - uy * uy;
	oy	= sqrtl(oy2);
	oxy	= Exiyi / N - ux * uy;
	a	= oxy / ox2;
	b	= uy - a * ux;
	c	= oxy / oy2;
	d	= ux - c * uy;
	r	= oxy / (ox * oy);

	Eyiy2	= 0;
	Exix2	= 0;
	for (ptrdiff_t i = 0; i < N; i++) {
		tmp	= y[i] - (a * x[i]) - b;
		Eyiy2 += tmp * tmp;
		tmp	= x[i] - (c * y[i]) - d;
		Exix2 += tmp * tmp;
	}

	Aa	= sqrtl(Eyiy2 / ((N-2) * (Exi2 - Exi*Exi/N)));
	Ab	= Aa * sqrtl(Exi2 / N);
	Ac	= sqrtl(Exix2 / ((N-2) * (Eyi2 - Eyi*Eyi/N)));
	Ad	= Ac * sqrtl(Eyi2 / N);
	Vr	= Eyiy2 / N;
	R2	= 1 - Vr / oy2;

	return	STRUCT_DS2V_RETURN_LDBL;
err:
	errno	= EDOM;
	return	STRUCT_DS2V_NaNl;
}

struct Alx_Descriptive_Statistics_2var
alx_descriptive_statistics_2var		(ptrdiff_t N,
					const double x[restrict N],
					const double y[restrict N])
{
	double		x2[N], y2[N], xy[N];
	double_t	Exi, Exi2;
	double_t	Eyi, Eyi2;
	double_t	Exiyi;
	double_t	Eyiy2, Exix2;
	double_t	tmp;

	double_t	ux, ox2, ox, a, Aa, b, Ab;
	double_t	uy, oy2, oy, c, Ac, d, Ad;
	double_t	oxy, r, Vr, R2;

	if (N < ALX_DS2V_N_MIN)
		goto err;

	Exi	= alx_dbl_array_sum(N, x);
	alx_array_multiplication(N, x2, x, x);
	Exi2	= alx_dbl_array_sum(N, x2);
	Eyi	= alx_dbl_array_sum(N, y);
	alx_array_multiplication(N, y2, y, y);
	Eyi2	= alx_dbl_array_sum(N, y2);
	alx_array_multiplication(N, xy, x, y);
	Exiyi	= alx_dbl_array_sum(N, y2);

	ux	= Exi / N;
	ox2	= Exi2 / N - ux * ux;
	ox	= sqrt(ox2);
	uy	= Eyi / N;
	oy2	= Eyi2 / N - uy * uy;
	oy	= sqrt(oy2);
	oxy	= Exiyi / N - ux * uy;
	a	= oxy / ox2;
	b	= uy - a * ux;
	c	= oxy / oy2;
	d	= ux - c * uy;
	r	= oxy / (ox * oy);

	Eyiy2	= 0;
	Exix2	= 0;
	for (ptrdiff_t i = 0; i < N; i++) {
		tmp	= y[i] - (a * x[i]) - b;
		Eyiy2 += tmp * tmp;
		tmp	= x[i] - (c * y[i]) - d;
		Exix2 += tmp * tmp;
	}

	Aa	= sqrt(Eyiy2 / ((N-2) * (Exi2 - Exi*Exi/N)));
	Ab	= Aa * sqrt(Exi2 / N);
	Ac	= sqrt(Exix2 / ((N-2) * (Eyi2 - Eyi*Eyi/N)));
	Ad	= Ac * sqrt(Eyi2 / N);
	Vr	= Eyiy2 / N;
	R2	= 1 - Vr / oy2;

	return	STRUCT_DS2V_RETURN_DBL;
err:
	errno	= EDOM;
	return	STRUCT_DS2V_NaN;
}

struct Alx_Descriptive_Statistics_2var_Flt
alx_descriptive_statistics_2var_flt	(ptrdiff_t N,
					const float x[restrict N],
					const float y[restrict N])
{
	float	x2[N], y2[N], xy[N];
	float_t	Exi, Exi2;
	float_t	Eyi, Eyi2;
	float_t	Exiyi;
	float_t	Eyiy2, Exix2;
	float_t	tmp;

	float_t	ux, ox2, ox, a, Aa, b, Ab;
	float_t	uy, oy2, oy, c, Ac, d, Ad;
	float_t	oxy, r, Vr, R2;

	if (N < ALX_DS2V_N_MIN)
		goto err;

	Exi	= alx_flt_array_sum_flt(N, x);
	alx_array_multiplication_flt(N, x2, x, x);
	Exi2	= alx_flt_array_sum_flt(N, x2);
	Eyi	= alx_flt_array_sum_flt(N, y);
	alx_array_multiplication_flt(N, y2, y, y);
	Eyi2	= alx_flt_array_sum_flt(N, y2);
	alx_array_multiplication_flt(N, xy, x, y);
	Exiyi	= alx_flt_array_sum_flt(N, y2);

	ux	= Exi / N;
	ox2	= Exi2 / N - ux * ux;
	ox	= sqrtf(ox2);
	uy	= Eyi / N;
	oy2	= Eyi2 / N - uy * uy;
	oy	= sqrtf(oy2);
	oxy	= Exiyi / N - ux * uy;
	a	= oxy / ox2;
	b	= uy - a * ux;
	c	= oxy / oy2;
	d	= ux - c * uy;
	r	= oxy / (ox * oy);

	Eyiy2	= 0;
	Exix2	= 0;
	for (ptrdiff_t i = 0; i < N; i++) {
		tmp	= y[i] - (a * x[i]) - b;
		Eyiy2 += tmp * tmp;
		tmp	= x[i] - (c * y[i]) - d;
		Exix2 += tmp * tmp;
	}

	Aa	= sqrtf(Eyiy2 / ((N-2) * (Exi2 - Exi*Exi/N)));
	Ab	= Aa * sqrtf(Exi2 / N);
	Ac	= sqrtf(Exix2 / ((N-2) * (Eyi2 - Eyi*Eyi/N)));
	Ad	= Ac * sqrtf(Eyi2 / N);
	Vr	= Eyiy2 / N;
	R2	= 1 - Vr / oy2;

	return	STRUCT_DS2V_RETURN_FLT;
err:
	errno	= EDOM;
	return	STRUCT_DS2V_NaNf;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
