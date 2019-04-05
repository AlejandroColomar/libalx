/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#ifndef ALX_MATH_FAST_HPP
#define ALX_MATH_FAST_HPP


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <cfloat>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/
#if	(FLT_EVAL_METHOD == 0)
#define PRIaFLT		"a"
#define PRIAFLT		"A"
#define PRIeFLT		"e"
#define PRIEFLT		"E"
#define PRIfFLT		"f"
#define PRIFFLT		"F"
#define PRIgFLT		"g"
#define PRIGFLT		"G"

#define SCNaFLT		"a"
#define SCNeFLT		"e"
#define SCNfFLT		"f"
#define SCNgFLT		"g"

#define PRIaDBL		"la"
#define PRIADBL		"lA"
#define PRIeDBL		"le"
#define PRIEDBL		"lE"
#define PRIfDBL		"lf"
#define PRIFDBL		"lF"
#define PRIgDBL		"lg"
#define PRIGDBL		"lG"

#define SCNaDBL		"la"
#define SCNeDBL		"le"
#define SCNfDBL		"lf"
#define SCNgDBL		"lg"


#elif	(FLT_EVAL_METHOD == 1)
#define PRIaFLT		"la"
#define PRIAFLT		"lA"
#define PRIeFLT		"le"
#define PRIEFLT		"lE"
#define PRIfFLT		"lf"
#define PRIFFLT		"lF"
#define PRIgFLT		"lg"
#define PRIGFLT		"lG"

#define SCNaFLT		"la"
#define SCNeFLT		"le"
#define SCNfFLT		"lf"
#define SCNgFLT		"lg"

#define PRIaDBL		"la"
#define PRIADBL		"lA"
#define PRIeDBL		"le"
#define PRIEDBL		"lE"
#define PRIfDBL		"lf"
#define PRIFDBL		"lF"
#define PRIgDBL		"lg"
#define PRIGDBL		"lG"

#define SCNaDBL		"la"
#define SCNeDBL		"le"
#define SCNfDBL		"lf"
#define SCNgDBL		"lg"


#elif	(FLT_EVAL_METHOD == 2)
#define PRIaFLT		"La"
#define PRIAFLT		"LA"
#define PRIeFLT		"Le"
#define PRIEFLT		"LE"
#define PRIfFLT		"Lf"
#define PRIFFLT		"LF"
#define PRIgFLT		"Lg"
#define PRIGFLT		"LG"

#define SCNaFLT		"La"
#define SCNeFLT		"Le"
#define SCNfFLT		"Lf"
#define SCNgFLT		"Lg"

#define PRIaDBL		"La"
#define PRIADBL		"LA"
#define PRIeDBL		"Le"
#define PRIEDBL		"LE"
#define PRIfDBL		"Lf"
#define PRIFDBL		"LF"
#define PRIgDBL		"Lg"
#define PRIGDBL		"LG"

#define SCNaDBL		"La"
#define SCNeDBL		"Le"
#define SCNfDBL		"Lf"
#define SCNgDBL		"Lg"
#endif


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
 ******* extern functions *****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (prototypes) *********************************
 ******************************************************************************/


/******************************************************************************
 ******* static inline functions (definitions) ********************************
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#endif		/* libalx/base/math/fast.hpp */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
