/******************************************************************************
 *	NO COPYRIGHT FOR THIS FILE.	FREE FOR ALL			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# ifndef		ALX_MATH_H
	# define	ALX_MATH_H


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
	#include <stdint.h>


/******************************************************************************
 ******* functions ************************************************************
 ******************************************************************************/
	/*
	 * Factorial
	 */
double	alx_fact		(int64_t n);

	/*
	 * Binomial coefficient (a b):				--!!!  a > b  !!!--
	 * - Bugs: If !(a > b), returns 1.
	 */
double	alx_bin_coef		(int64_t a, int64_t b);

	/*
	 * Median
	 * - If even array, return the mean of the two central values
	 */
double	alx_median		(int n, double x[n]);
uint8_t	alx_median_u8		(int n, uint8_t x[n]);

	/*
	 * Maximum element of an array
	 * - Return position containing the maximum element of the array
	 */
int	alx_maximum_u8		(int n, uint8_t x[n]);

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
double	alx_scale_linear	(double input,
					double in_min, double in_max,
					double out_min, double out_max);
float	alx_scale_linear_f	(float input,
					float in_min, float in_max,
					float out_min, float out_max);
int8_t	alx_scale_linear_i8	(int8_t input,
					int8_t in_min, int8_t in_max,
					int8_t out_min, int8_t out_max);
int16_t	alx_scale_linear_i16	(int16_t input,
					int16_t in_min, int16_t in_max,
					int16_t out_min, int16_t out_max);


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
# endif			/* alx_math.h */


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
