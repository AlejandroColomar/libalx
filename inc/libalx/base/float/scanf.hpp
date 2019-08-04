/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* libalx/base/float/scanf.hpp */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cfloat>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#if	(FLT_EVAL_METHOD == 0)
#define SCNaFLTT	"a"
#define SCNeFLTT	"e"
#define SCNfFLTT	"f"
#define SCNgFLTT	"g"

#define SCNaDBLT	"la"
#define SCNeDBLT	"le"
#define SCNfDBLT	"lf"
#define SCNgDBLT	"lg"

#elif	(FLT_EVAL_METHOD == 1)
#define SCNaFLTT	"la"
#define SCNeFLTT	"le"
#define SCNfFLTT	"lf"
#define SCNgFLTT	"lg"

#define SCNaDBLT	"la"
#define SCNeDBLT	"le"
#define SCNfDBLT	"lf"
#define SCNgDBLT	"lg"

#elif	(FLT_EVAL_METHOD == 2)
#define SCNaFLTT	"La"
#define SCNeFLTT	"Le"
#define SCNfFLTT	"Lf"
#define SCNgFLTT	"Lg"

#define SCNaDBLT	"La"
#define SCNeDBLT	"Le"
#define SCNfDBLT	"Lf"
#define SCNgDBLT	"Lg"
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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* namespace ************************************************************
 ******************************************************************************/
}	/* namespace alx */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
