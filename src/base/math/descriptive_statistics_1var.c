/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/base/math/descriptive_statistics_1var.h"

#include <errno.h>
#include <math.h>
#include <stddef.h>

#include "libalx/base/math/array_multiplication.h"
#include "libalx/base/math/array_sum.h"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define STRUCT_DS1V_COMPOUND_LITERAL(type, x)	(					\
(type){									\
	.u	= x,							\
	.o2	= x,							\
	.o	= x,							\
	.s2	= x,							\
	.s	= x,							\
	.CV	= x							\
}									\
)

#define STRUCT_DS1V_NaNl	(					\
	STRUCT_DS1V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_1var_Ldbl, nanl(""))		\
)
#define STRUCT_DS1V_NaN		(					\
	STRUCT_DS1V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_1var, nan(""))		\
)
#define STRUCT_DS1V_NaNf	(					\
	STRUCT_DS1V_COMPOUND_LITERAL(					\
	struct Alx_Descriptive_Statistics_1var_Flt, nanf(""))		\
)

#define STRUCT_DS1V_RETURN(type)	(				\
(type){									\
	.u	= u,							\
	.o2	= o2,							\
	.o	= o,							\
	.s2	= s2,							\
	.s	= s,							\
	.CV	= CV							\
}									\
)

#define STRUCT_DS1V_RETURN_LDBL		(				\
	STRUCT_DS1V_RETURN(						\
	struct Alx_Descriptive_Statistics_1var_Ldbl)			\
)
#define STRUCT_DS1V_RETURN_DBL		(				\
	STRUCT_DS1V_RETURN(						\
	struct Alx_Descriptive_Statistics_1var)				\
)
#define STRUCT_DS1V_RETURN_FLT		(				\
	STRUCT_DS1V_RETURN(						\
	struct Alx_Descriptive_Statistics_1var_Flt)			\
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
struct Alx_Descriptive_Statistics_1var_Ldbl
alx_descriptive_statistics_1var_ldbl	(ptrdiff_t N,
					const long double x[restrict N],
					const long double n[restrict N])
{
	long double	xn[N], x2n[N];
	long double	Eni, Exi, Exi2;
	long double	u, o2, o, s2, s, CV;

	if (N <= 0)
		goto err;

	Eni	= alx_ldbl_array_sum_ldbl(N, n);
	alx_array_multiplication_ldbl(N, xn, x, n);
	Exi	= alx_ldbl_array_sum_ldbl(N, xn);
	alx_array_multiplication_ldbl(N, x2n, xn, x);
	Exi2	= alx_ldbl_array_sum_ldbl(N, x2n);

	u	= Exi / Eni;
	o2	= Exi2 / Eni - u * u;
	o	= sqrtl(o2);
	s2	= o2 * Eni / (Eni - 1);
	s	= sqrtl(s2);
	CV	= o / u;

	return	STRUCT_DS1V_RETURN_LDBL;

err:
	errno	= EDOM;
	return	STRUCT_DS1V_NaNl;
}

struct Alx_Descriptive_Statistics_1var
alx_descriptive_statistics_1var		(ptrdiff_t N,
					const double x[restrict N],
					const double n[restrict N])
{
	double		xn[N], x2n[N];
	double_t	Eni, Exi, Exi2;
	double_t	u, o2, o, s2, s, CV;

	if (N <= 0)
		goto err;

	Eni	= alx_dbl_array_sum(N, n);
	alx_array_multiplication(N, xn, x, n);
	Exi	= alx_dbl_array_sum(N, xn);
	alx_array_multiplication(N, x2n, xn, x);
	Exi2	= alx_dbl_array_sum(N, x2n);

	u	= Exi / Eni;
	o2	= Exi2 / Eni - u * u;
	o	= sqrt(o2);
	s2	= o2 * Eni / (Eni - 1);
	s	= sqrt(s2);
	CV	= o / u;

	return	STRUCT_DS1V_RETURN_DBL;

err:
	errno	= EDOM;
	return	STRUCT_DS1V_NaN;
}

struct Alx_Descriptive_Statistics_1var_Flt
alx_descriptive_statistics_1var_flt	(ptrdiff_t N,
					const float x[restrict N],
					const float n[restrict N])
{
	float	xn[N], x2n[N];
	float_t	Eni, Exi, Exi2;
	float_t	u, o2, o, s2, s, CV;

	if (N <= 0)
		goto err;

	Eni	= alx_flt_array_sum_flt(N, n);
	alx_array_multiplication_flt(N, xn, x, n);
	Exi	= alx_flt_array_sum_flt(N, xn);
	alx_array_multiplication_flt(N, x2n, xn, x);
	Exi2	= alx_flt_array_sum_flt(N, x2n);

	u	= Exi / Eni;
	o2	= Exi2 / Eni - u * u;
	o	= sqrtf(o2);
	s2	= o2 * Eni / (Eni - 1);
	s	= sqrtf(s2);
	CV	= o / u;

	return	STRUCT_DS1V_RETURN_FLT;

err:
	errno	= EDOM;
	return	STRUCT_DS1V_NaNf;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
