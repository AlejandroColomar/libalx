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
int	compare_int		(const void *a, const void *b)
{
	int	r;

	if (*(int *)a < *(int *)b) {
		r = -1;
	} else if (*(int *)a > *(int *)b) {
		r = 1;
	} else {
		/*  (*(int *)a == *(int *)b)  */
		r = 0;
	}

	return	r;
}

	/*
	 * Comparison function. Receives two items under comparison.
	 * return int
	 */
int	compare_u8		(const void *a, const void *b)
{
	int	r;

	if (*(uint8_t *)a < *(uint8_t *)b) {
		r = -1;
	} else if (*(uint8_t *)a > *(uint8_t *)b) {
		r = 1;
	} else {
		/*  (*(uint8_t *)a == *(uint8_t *)b)  */
		r = 0;
	}

	return	r;
}

	/*
	 * Comparison function. Receives two items under comparison.
	 * return int
	 */
int	compare_i64		(const void *a, const void *b)
{
	int	r;

	if (*(int64_t *)a < *(int64_t *)b) {
		r = -1;
	} else if (*(int64_t *)a > *(int64_t *)b) {
		r = 1;
	} else {
		/*  (*(int64_t *)a == *(int64_t *)b)  */
		r = 0;
	}

	return	r;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
