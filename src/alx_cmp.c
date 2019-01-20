/******************************************************************************
 *	NO COPYRIGHT FOR THIS FILE.	FREE FOR ALL			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include <stdint.h>

	#include "libalx/alx_cmp.h"


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
	/*
	 * Comparison function. Receives two items under comparison.
	 * return int
	 */
int	compare_int		(const void *a_ptr, const void *b_ptr)
{
	int	a =	*(int *)a_ptr;
	int	b =	*(int *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

int	compare_u8		(const void *a_ptr, const void *b_ptr)
{
	uint8_t	a =	*(uint8_t *)a_ptr;
	uint8_t	b =	*(uint8_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}

int	compare_i64		(const void *a_ptr, const void *b_ptr)
{
	int64_t	a =	*(int64_t *)a_ptr;
	int64_t	b =	*(int64_t *)b_ptr;

	if (a < b)
		return	-1;
	else if (a > b)
		return	1;
	else
		return	0;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
