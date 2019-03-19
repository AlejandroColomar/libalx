#! /usr/bin/make -f

################################################################################
# Copyright (C) 2019	Alejandro Colomar Andrés
# SPDX-License-Identifier:	LGPL-2.0-only
################################################################################
# *AUTHOR*
# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# dependencies

OBJ		=							\
		array_division.o					\
		array_multiplication.o					\
		arithmetic_mean.o					\
		binomial_coefficient.o					\
		factorial.o						\
		matrix_addition.o					\
		matrix_subtraction.o					\
		median.o						\
		pascal_triangle.o					\
		prime.o							\
		prime_factorization.o					\
		scale_linear.o

ARITHMETIC_MEAN_INC	=						\
		$(INC_DIR)/libalx/math/arithmetic_mean.h
ARITHMETIC_MEAN_SRC	=						\
		$(SRC_DIR)/math/arithmetic_mean.c

ARRAY_DIVISION_INC	=						\
		$(INC_DIR)/libalx/math/array_division.h
ARRAY_DIVISION_SRC	=						\
		$(SRC_DIR)/math/array_division.c

ARRAY_MULTIPLICATION_INC	=					\
		$(INC_DIR)/libalx/math/array_multiplication.h
ARRAY_MULTIPLICATION_SRC	=					\
		$(SRC_DIR)/math/array_multiplication.c

BINOMIAL_COEFFICIENT_INC	=					\
		$(INC_DIR)/libalx/math/binomial_coefficient.h		\
		$(INC_DIR)/libalx/stdint/int128.h			\
		$(INC_DIR)/libalx/math/common.h
BINOMIAL_COEFFICIENT_SRC	=					\
		$(SRC_DIR)/math/binomial_coefficient.c

FACTORIAL_INC	=							\
		$(INC_DIR)/libalx/math/factorial.h			\
		$(INC_DIR)/libalx/stdint/int128.h			\
		$(INC_DIR)/libalx/math/common.h
FACTORIAL_SRC	=							\
		$(SRC_DIR)/math/factorial.c

MATRIX_ADDITION_INC	=						\
		$(INC_DIR)/libalx/math/matrix_addition.h
MATRIX_ADDITION_SRC	=						\
		$(SRC_DIR)/math/matrix_addition.c

MATRIX_SUBTRACTION_INC	=						\
		$(INC_DIR)/libalx/math/matrix_subtraction.h
MATRIX_SUBTRACTION_SRC	=						\
		$(SRC_DIR)/math/matrix_subtraction.c

MEDIAN_INC	=							\
		$(INC_DIR)/libalx/math/median.h				\
		$(INC_DIR)/libalx/stdlib/compare.h
MEDIAN_SRC	=							\
		$(SRC_DIR)/math/median.c

PASCAL_TRIANGLE_INC	=						\
		$(INC_DIR)/libalx/math/pascal_triangle.h		\
		$(INC_DIR)/libalx/stdint/int128.h			\
		$(INC_DIR)/libalx/math/common.h
PASCAL_TRIANGLE_SRC	=						\
		$(SRC_DIR)/math/pascal_triangle.c

PRIME_INC	=							\
		$(INC_DIR)/libalx/math/prime.h				\
		$(INC_DIR)/libalx/stdlib/search.h
PRIME_SRC	=							\
		$(SRC_DIR)/math/prime.c

PRIME_FACTORIZATION_INC	=						\
		$(INC_DIR)/libalx/math/prime_factorization.h		\
		$(INC_DIR)/libalx/math/prime.h
PRIME_FACTORZATION_SRC	=						\
		$(SRC_DIR)/math/prime_factorization.c

SCALE_LINEAR_INC	=						\
		$(INC_DIR)/libalx/math/scale_linear.h
SCALE_LINEAR_SRC	=						\
		$(SRC_DIR)/math/scale_linear.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


arithmetic_mean.s: $(ARITHMETIC_MEAN_SRC) $(ARITHMETIC_MEAN_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
arithmetic_mean.o: arithmetic_mean.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

array_division.s: $(ARRAY_DIVISION_SRC) $(ARRAY_DIVISION_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_division.o: array_division.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

array_multiplication.s: $(ARRAY_MULTIPLICATION_SRC) $(ARRAY_MULTIPLICATION_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_multiplication.o: array_multiplication.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

binomial_coefficient.s: $(BINOMIAL_COEFFICIENT_SRC) $(BINOMIAL_COEFFICIENT_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
binomial_coefficient.o: binomial_coefficient.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

factorial.s: $(FACTORIAL_SRC) $(FACTORIAL_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
factorial.o: factorial.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

matrix_addition.s: $(MATRIX_ADDITION_SRC) $(MATRIX_ADDITION_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_addition.o: matrix_addition.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

matrix_subtraction.s: $(MATRIX_SUBTRACTION_SRC) $(MATRIX_SUBTRACTION_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_subtraction.o: matrix_subtraction.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

median.s: $(MEDIAN_SRC) $(MEDIAN_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
median.o: median.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

pascal_triangle.s: $(PASCAL_TRIANGLE_SRC) $(PASCAL_TRIANGLE_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
pascal_triangle.o: pascal_triangle.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

prime.s: $(PRIME_SRC) $(PRIME_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime.o: prime.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

prime_factorization.s: $(PRIME_FACTORZATION_SRC) $(PRIME_FACTORZATION_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime_factorization.o: prime_factorization.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@

scale_linear.s: $(SCALE_LINEAR_SRC) $(SCALE_LINEAR_INC)
	@echo	"	CC	libalx/tmp/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
scale_linear.o: scale_linear.s
	@echo	"	AS	libalx/tmp/math/$@"
	$(Q)$(AS) $< -o $@


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
