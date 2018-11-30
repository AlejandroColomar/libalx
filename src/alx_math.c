/******************************************************************************
 *	NO COPYRIGHT FOR THIS FILE.	FREE FOR ALL			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
/* Standard C ----------------------------------------------------------------*/
	#include <stdint.h>
		/* qsort() */
	#include <stdlib.h>

/* libalx --------------------------------------------------------------------*/
		/* compare_u8() */
	#include "alx_cmp.h"

/* Module --------------------------------------------------------------------*/
	#include "alx_math.h"


/******************************************************************************
 ******* main *****************************************************************
 ******************************************************************************/
	/*
	 * Factorial
	 */
double	alx_fact		(int64_t n)
{
	if (n < 1) {
		return	1;
	} else {
		return	n * alx_fact(n - 1);
	}
}

	/*
	 * Binomial coefficient (a b):			--!!!  a > b  !!!--
	 * - Bugs: If !(a > b), returns 1.
	 */
double	alx_bin_coef		(int64_t a, int64_t b)
{
	int64_t	i = 1;
	double	c = 1;

	while (a > b) {
		c = c * a-- / i++;
	}

	return	c;
}

	/*
	 * Median
	 * - If even array, return the mean of the two central values
	 */
uint8_t	alx_median_u8		(int n, uint8_t x[n])
{
	uint8_t	median;

	qsort(x, n, sizeof(x[0]), compare_u8);

	if (n % 2) {
		median	= x[n/2];
	} else {
		median	= (x[n/2] + x[n/2 - 1]) / 2.0;
	}

	return	median;
}

	/*
	 * Maximum element of an array
	 * - Return position containing the maximum element of the array
	 */
int	alx_maximum_u8		(int n, uint8_t x[n])
{
	int	pos	= 0;
	uint8_t	val	= 0;

	int	i;
	for (i = 0; i < n; i++) {
		if (x[i] >= val) {
			val	= x[i];
			pos	= i;
		}
	}

	return	pos;
}

	/**
	 * @brief	Linear scale transform.
	 *			Values can be out of range [in_min, in_max].
	 * @param	input:		value to be transformed.
	 * @param	in_min:		input min value.
	 * @param	in_max:		input max value.
	 * @param	out_min:	output value that corresponds to in_min.
	 * @param	out_max:	output value that corresponds to in_max.
	 * @return	output:		transformed value.
	 */
double	scale_linear		(double input,
				double in_min, double in_max,
				double out_min, double out_max)
{
	double	normalized;
	double	output;

	normalized	= (input - in_min) / (in_max - in_min);
	output		= out_min + normalized * (out_max - out_min);

	return	output;
}

float	scale_linear_f		(float input,
				float in_min, float in_max,
				float out_min, float out_max)
{
	float	normalized;
	float	output;

	normalized	= (input - in_min) / (in_max - in_min);
	output		= out_min + normalized * (out_max - out_min);

	return	output;
}

int16_t	scale_linear_i16	(int16_t input,
				int16_t in_min, int16_t in_max,
				int16_t out_min, int16_t out_max)
{
	int16_t	output;

	output		= (int16_t)((int32_t)out_min +
					(int32_t)(input - in_min) *
					(int32_t)(out_max - out_min) /
					(int32_t)(in_max - in_min));

	return	output;
}


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
