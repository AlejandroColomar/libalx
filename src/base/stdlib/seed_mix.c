/******************************************************************************
 *	Robert Jenkins' 96 bit Mix Function				      *
 *	The code given here is all public domain			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include "libalx/base/stdlib/seed_mix.h"

	#include <stdint.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


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
uint32_t	alx_seed_mix	(uint32_t a, uint32_t b, uint32_t c)
{

	a -=	b + c;
	a ^=	c >> 13;
	b -=	c + a;
	b ^=	a << 8;
	c -=	a + b;
	c ^=	b >> 13;
	a -=	b + c;
	a ^=	c >> 12;
	b -=	a + c;
	b ^=	a << 16;
	c -=	a + b;
	c ^=	b >> 5;
	a -=	b + c;
	a ^=	c >> 3;
	b -=	a + c;
	b ^=	a << 10;
	c -=	a + b;
	c ^=	b >> 15;

	return	c;
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/