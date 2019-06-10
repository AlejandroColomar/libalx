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
		arithmetic_mean.o					\
		array_division.o					\
		array_multiplication.o					\
		array_sum.o						\
		binomial_coefficient.o					\
		descriptive_statistics_1var.o				\
		descriptive_statistics_2var.o				\
		distribution_binomial.o					\
		distribution_exponential.o				\
		distribution_geometric.o				\
		distribution_normal.o					\
		distribution_poisson.o					\
		distribution_uniform.o					\
		factorial.o						\
		matrix_addition.o					\
		matrix_subtraction.o					\
		median.o						\
		pascal_triangle.o					\
		prime.o							\
		prime_defactorization.o					\
		prime_factorization.o					\
		scale_linear.o

ARITHMETIC_MEAN_INC	=						\
		$(INC_DIR)/libalx/base/math/arithmetic_mean.h
ARITHMETIC_MEAN_SRC	=						\
		$(SRC_DIR)/base/math/arithmetic_mean.c

ARRAY_DIVISION_INC	=						\
		$(INC_DIR)/libalx/base/math/array_division.h
ARRAY_DIVISION_SRC	=						\
		$(SRC_DIR)/base/math/array_division.c

ARRAY_MULTIPLICATION_INC	=					\
		$(INC_DIR)/libalx/base/math/array_multiplication.h
ARRAY_MULTIPLICATION_SRC	=					\
		$(SRC_DIR)/base/math/array_multiplication.c

ARRAY_SUM_INC	=							\
		$(INC_DIR)/libalx/base/math/array_sum.h			\
		$(INC_DIR)/libalx/base/stdlib/compare.h
ARRAY_SUM_SRC	=							\
		$(SRC_DIR)/base/math/array_sum.c

BINOMIAL_COEFFICIENT_INC	=					\
		$(INC_DIR)/libalx/base/math/binomial_coefficient.h	\
		$(INC_DIR)/libalx/base/math/pascal_triangle.h		\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/math/prime_defactorization.h	\
		$(INC_DIR)/libalx/base/stddef/size.h
BINOMIAL_COEFFICIENT_SRC	=					\
		$(SRC_DIR)/base/math/binomial_coefficient.c

DESCRIPTIVE_STATISTICS_1VAR_INC	=					\
		$(INC_DIR)/libalx/base/math/descriptive_statistics_1var.h \
		$(INC_DIR)/libalx/base/math/array_multiplication.h	\
		$(INC_DIR)/libalx/base/math/array_sum.h
DESCRIPTIVE_STATISTICS_1VAR_SRC	=					\
		$(SRC_DIR)/base/math/descriptive_statistics_1var.c

DESCRIPTIVE_STATISTICS_2VAR_INC	=					\
		$(INC_DIR)/libalx/base/math/descriptive_statistics_2var.h \
		$(INC_DIR)/libalx/base/math/array_multiplication.h	\
		$(INC_DIR)/libalx/base/math/array_sum.h
DESCRIPTIVE_STATISTICS_2VAR_SRC	=					\
		$(SRC_DIR)/base/math/descriptive_statistics_2var.c

DISTRIBUTION_BINOMIAL_INC	=					\
		$(INC_DIR)/libalx/base/math/distribution_binomial.h	\
		$(INC_DIR)/libalx/base/math/binomial_coefficient.h
DISTRIBUTION_BINOMIAL_SRC	=					\
		$(SRC_DIR)/base/math/distribution_binomial.c

DISTRIBUTION_EXPONENTIAL_INC	=					\
		$(INC_DIR)/libalx/base/math/distribution_exponential.h
DISTRIBUTION_EXPONENTIAL_SRC	=					\
		$(SRC_DIR)/base/math/distribution_exponential.c

DISTRIBUTION_GEOMETRIC_INC	=					\
		$(INC_DIR)/libalx/base/math/distribution_geometric.h
DISTRIBUTION_GEOMETRIC_SRC	=					\
		$(SRC_DIR)/base/math/distribution_geometric.c

DISTRIBUTION_NORMAL_INC	=						\
		$(INC_DIR)/libalx/base/math/distribution_normal.h
DISTRIBUTION_NORMAL_SRC	=						\
		$(SRC_DIR)/base/math/distribution_normal.c

DISTRIBUTION_POISSON_INC	=					\
		$(INC_DIR)/libalx/base/math/distribution_poisson.h	\
		$(INC_DIR)/libalx/base/math/factorial.h
DISTRIBUTION_POISSON_SRC	=					\
		$(SRC_DIR)/base/math/distribution_poisson.c

DISTRIBUTION_UNIFORM_INC	=					\
		$(INC_DIR)/libalx/base/math/distribution_uniform.h
DISTRIBUTION_UNIFORM_SRC	=					\
		$(SRC_DIR)/base/math/distribution_uniform.c

FACTORIAL_INC	=							\
		$(INC_DIR)/libalx/base/math/factorial.h			\
		$(INC_DIR)/libalx/base/math/matrix_addition.h		\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/math/prime_defactorization.h	\
		$(INC_DIR)/libalx/base/math/prime_factorization.h	\
		$(INC_DIR)/libalx/base/stddef/size.h
FACTORIAL_SRC	=							\
		$(SRC_DIR)/base/math/factorial.c

MATRIX_ADDITION_INC	=						\
		$(INC_DIR)/libalx/base/math/matrix_addition.h
MATRIX_ADDITION_SRC	=						\
		$(SRC_DIR)/base/math/matrix_addition.c

MATRIX_SUBTRACTION_INC	=						\
		$(INC_DIR)/libalx/base/math/matrix_subtraction.h
MATRIX_SUBTRACTION_SRC	=						\
		$(SRC_DIR)/base/math/matrix_subtraction.c

MEDIAN_INC	=							\
		$(INC_DIR)/libalx/base/math/median.h			\
		$(INC_DIR)/libalx/base/stdlib/compare.h
MEDIAN_SRC	=							\
		$(SRC_DIR)/base/math/median.c

PASCAL_TRIANGLE_INC	=						\
		$(INC_DIR)/libalx/base/math/pascal_triangle.h		\
		$(INC_DIR)/libalx/base/math/matrix_addition.h		\
		$(INC_DIR)/libalx/base/math/matrix_subtraction.h	\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/math/prime_defactorization.h	\
		$(INC_DIR)/libalx/base/math/prime_factorization.h	\
		$(INC_DIR)/libalx/base/stddef/size.h
PASCAL_TRIANGLE_SRC	=						\
		$(SRC_DIR)/base/math/pascal_triangle.c

PRIME_INC	=							\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/stddef/size.h			\
		$(INC_DIR)/libalx/base/stdlib/search.h
PRIME_SRC	=							\
		$(SRC_DIR)/base/math/prime.c

PRIME_DEFACTORIZATION_INC	=					\
		$(INC_DIR)/libalx/base/math/prime_defactorization.h	\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/stddef/size.h
PRIME_DEFACTORIZATION_SRC	=					\
		$(SRC_DIR)/base/math/prime_defactorization.c

PRIME_FACTORIZATION_INC	=						\
		$(INC_DIR)/libalx/base/math/prime_factorization.h	\
		$(INC_DIR)/libalx/base/math/prime.h
PRIME_FACTORIZATION_SRC	=						\
		$(SRC_DIR)/base/math/prime_factorization.c

SCALE_LINEAR_INC	=						\
		$(INC_DIR)/libalx/base/math/scale_linear.h
SCALE_LINEAR_SRC	=						\
		$(SRC_DIR)/base/math/scale_linear.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


arithmetic_mean.s: $(ARITHMETIC_MEAN_SRC) $(ARITHMETIC_MEAN_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
arithmetic_mean.o: arithmetic_mean.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

array_division.s: $(ARRAY_DIVISION_SRC) $(ARRAY_DIVISION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_division.o: array_division.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

array_multiplication.s: $(ARRAY_MULTIPLICATION_SRC) $(ARRAY_MULTIPLICATION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_multiplication.o: array_multiplication.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

array_sum.s: $(ARRAY_SUM_SRC) $(ARRAY_SUM_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_sum.o: array_sum.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

binomial_coefficient.s: $(BINOMIAL_COEFFICIENT_SRC) $(BINOMIAL_COEFFICIENT_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
binomial_coefficient.o: binomial_coefficient.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

descriptive_statistics_1var.s: $(DESCRIPTIVE_STATISTICS_1VAR_SRC) $(DESCRIPTIVE_STATISTICS_1VAR_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
descriptive_statistics_1var.o: descriptive_statistics_1var.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

descriptive_statistics_2var.s: $(DESCRIPTIVE_STATISTICS_2VAR_SRC) $(DESCRIPTIVE_STATISTICS_2VAR_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
descriptive_statistics_2var.o: descriptive_statistics_2var.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_binomial.s: $(DISTRIBUTION_BINOMIAL_SRC) $(DISTRIBUTION_BINOMIAL_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_binomial.o: distribution_binomial.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_exponential.s: $(DISTRIBUTION_EXPONENTIAL_SRC) $(DISTRIBUTION_EXPONENTIAL_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_exponential.o: distribution_exponential.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_geometric.s: $(DISTRIBUTION_GEOMETRIC_SRC) $(DISTRIBUTION_GEOMETRIC_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_geometric.o: distribution_geometric.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_normal.s: $(DISTRIBUTION_NORMAL_SRC) $(DISTRIBUTION_NORMAL_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_normal.o: distribution_normal.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_poisson.s: $(DISTRIBUTION_POISSON_SRC) $(DISTRIBUTION_POISSON_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_poisson.o: distribution_poisson.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

distribution_uniform.s: $(DISTRIBUTION_UNIFORM_SRC) $(DISTRIBUTION_UNIFORM_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
distribution_uniform.o: distribution_uniform.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

factorial.s: $(FACTORIAL_SRC) $(FACTORIAL_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
factorial.o: factorial.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

matrix_addition.s: $(MATRIX_ADDITION_SRC) $(MATRIX_ADDITION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_addition.o: matrix_addition.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

matrix_subtraction.s: $(MATRIX_SUBTRACTION_SRC) $(MATRIX_SUBTRACTION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_subtraction.o: matrix_subtraction.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

median.s: $(MEDIAN_SRC) $(MEDIAN_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
median.o: median.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

pascal_triangle.s: $(PASCAL_TRIANGLE_SRC) $(PASCAL_TRIANGLE_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
pascal_triangle.o: pascal_triangle.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

prime.s: $(PRIME_SRC) $(PRIME_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime.o: prime.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

prime_defactorization.s: $(PRIME_DEFACTORIZATION_SRC) $(PRIME_DEFACTORIZATION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime_defactorization.o: prime_defactorization.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

prime_factorization.s: $(PRIME_FACTORIZATION_SRC) $(PRIME_FACTORIZATION_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime_factorization.o: prime_factorization.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

scale_linear.s: $(SCALE_LINEAR_SRC) $(SCALE_LINEAR_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
scale_linear.o: scale_linear.s
	@echo	"	AS	libalx/tmp/base/math/$@"
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
