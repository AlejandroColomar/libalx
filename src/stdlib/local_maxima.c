/******************************************************************************
 *	Copyright (C) 2019	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/stdlib/local_maxima.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enums ****************************************************************
 ******************************************************************************/
enum	Cell {
	NOT_LOCAL_MAX,
	MAYBE_LOCAL_MAX,
	LOCAL_MAX
};


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
void	alx_local_maxima_ldbl	(int rows, int cols,
				const long double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{

	memset(arr_out, 0, rows * cols * sizeof(arr_out[0][0]));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
			}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_local_maxima	(int rows, int cols,
				const double arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{

	memset(arr_out, 0, rows * cols * sizeof(arr_out[0][0]));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
			}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_local_maxima_f	(int rows, int cols,
				const float arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{

	memset(arr_out, 0, rows * cols * sizeof(arr_out[0][0]));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
			}
		}
		arr_out[i][j]	= true;
		continue;
not_maxima:
		;
	}
	}
}

void	alx_local_maxima_uint	(int rows, int cols,
				const unsigned arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_int	(int rows, int cols,
				const int arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_u8	(int rows, int cols,
				const uint8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_s8	(int rows, int cols,
				const int8_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_u16	(int rows, int cols,
				const uint16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_s16	(int rows, int cols,
				const int16_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_u32	(int rows, int cols,
				const uint32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_s32	(int rows, int cols,
				const int32_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_u64	(int rows, int cols,
				const uint64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}

void	alx_local_maxima_s64	(int rows, int cols,
				const int64_t arr_in[restrict rows][cols],
				bool arr_out[restrict rows][cols])
{
	int	arr_tmp[rows][cols];
	bool	wh;

	memset(arr_tmp, 0, sizeof(arr_tmp));

	for (ssize_t i = 0; i < rows; i++) {
	for (ssize_t j = 0; j < cols; j++) {
		for (ssize_t k = i - 1; k <= (i + 1); k++) {
			if (k < 0)
				continue;
			if (k >= rows)
				break;
			for (ssize_t l = j - 1; l <= (j + 1); l++) {
				if (l < 0)
					continue;
				if (l >= cols)
					break;
				if (arr_in[i][j] < arr_in[k][l])
					goto not_maxima;
				if (arr_in[i][j] == arr_in[k][l])
					arr_tmp[i][j]	= MAYBE_LOCAL_MAX;
			}
		}
		if (!arr_tmp[i][j])
			arr_tmp[i][j]	= LOCAL_MAX;
		continue;
not_maxima:
		;
	}
	}

	do { 
		wh	= false;
		for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			if (arr_tmp[i][j] != MAYBE_LOCAL_MAX)
				continue;
			for (ssize_t k = i - 1; k <= (i + 1); k++) {
				if (k < 0)
					continue;
				if (k >= rows)
					break;
				for (ssize_t l = j - 1; l <= (j + 1); l++) {
					if (l < 0)
						continue;
					if (l >= cols)
						break;
					if (arr_in[i][j] == arr_in[k][l]) {
						if (!arr_tmp[k][l])
							goto not_maxima_2;
					}
				}
			}
			continue;
not_maxima_2:
			wh		= true;
			arr_tmp[i][j]	= false;
		}
		}
	} while (wh);

	for (ssize_t i = 0; i < rows; i++) {
		for (ssize_t j = 0; j < cols; j++) {
			arr_out[i][j]	= arr_tmp[i][j];
		}
	}
}


/******************************************************************************
 ******* static functions (definitions) ***************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
