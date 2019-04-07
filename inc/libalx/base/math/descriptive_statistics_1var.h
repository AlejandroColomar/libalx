/******************************************************************************
 *	Copyright (C) 2015	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_DESCRIPTIVE_STATISTICS_1VAR_H
#define ALX_MATH_DESCRIPTIVE_STATISTICS_1VAR_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stddef.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#define ALX_DS1V_N_MIN	(1)


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* structs / unions *****************************************************
 ******************************************************************************/
struct	Alx_Descriptive_Statistics_1var_Ldbl {
	long double	u;
	long double	o2;
	long double	o;
	long double	s2;
	long double	s;
	long double	CV;
};

struct	Alx_Descriptive_Statistics_1var {
	double	u;
	double	o2;
	double	o;
	double	s2;
	double	s;
	double	CV;
};

struct	Alx_Descriptive_Statistics_1var_Flt {
	float	u;
	float	o2;
	float	o;
	float	s2;
	float	s;
	float	CV;
};


/******************************************************************************
 ******* variables ************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* extern functions *****************************************************
 ******************************************************************************/
struct Alx_Descriptive_Statistics_1var_Ldbl
alx_descriptive_statistics_1var_ldbl	(ptrdiff_t N,
					const long double x[restrict N],
					const long double n[restrict N]);
struct Alx_Descriptive_Statistics_1var
alx_descriptive_statistics_1var		(ptrdiff_t N,
					const double x[restrict N],
					const double n[restrict N]);
struct Alx_Descriptive_Statistics_1var_Flt
alx_descriptive_statistics_1var_flt	(ptrdiff_t N,
					const float x[restrict N],
					const float n[restrict N]);


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/descriptive_statistics_1var.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/