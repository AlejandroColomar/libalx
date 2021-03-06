/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/float/constant.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cfloat>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#if	(FLT_EVAL_METHOD == 0)
#define FLTT_C(c)	c ## f
#define DBLT_C(c)	c

#elif	(FLT_EVAL_METHOD == 1)
#define FLTT_C(c)	c
#define DBLT_C(c)	c

#elif	(FLT_EVAL_METHOD == 2)
#define FLTT_C(c)	c ## L
#define DBLT_C(c)	c ## L
#endif


/******************************************************************************
 ******* extern "C" ***********************************************************
 ******************************************************************************/
extern	"C"
{
}


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
namespace alx {


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
