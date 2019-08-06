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
		array_sum.o						\
		binomial_coefficient.o					\
		matrix_addition.o					\
		matrix_subtraction.o					\
		pascal_triangle.o					\
		prime.o							\
		prime_defactorization.o					\
		prime_factorization.o					\
		scale_linear.o

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
		$(INC_DIR)/libalx/base/math/prime.h
BINOMIAL_COEFFICIENT_SRC	=					\
		$(SRC_DIR)/base/math/binomial_coefficient.c

MATRIX_ADDITION_INC	=						\
		$(INC_DIR)/libalx/base/math/matrix_addition.h
MATRIX_ADDITION_SRC	=						\
		$(SRC_DIR)/base/math/matrix_addition.c

MATRIX_SUBTRACTION_INC	=						\
		$(INC_DIR)/libalx/base/math/matrix_subtraction.h
MATRIX_SUBTRACTION_SRC	=						\
		$(SRC_DIR)/base/math/matrix_subtraction.c

PASCAL_TRIANGLE_INC	=						\
		$(INC_DIR)/libalx/base/math/pascal_triangle.h		\
		$(INC_DIR)/libalx/base/float/constant.h			\
		$(INC_DIR)/libalx/base/math/matrix_addition.h		\
		$(INC_DIR)/libalx/base/math/matrix_subtraction.h	\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/math/prime_factorization.h
PASCAL_TRIANGLE_SRC	=						\
		$(SRC_DIR)/base/math/pascal_triangle.c

PRIME_INC	=							\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/base/stdlib/search.h
PRIME_SRC	=							\
		$(SRC_DIR)/base/math/prime.c

PRIME_DEFACTORIZATION_INC	=					\
		$(INC_DIR)/libalx/base/math/prime_defactorization.h	\
		$(INC_DIR)/libalx/base/math/prime.h
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
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@


array_division.a.s: $(ARRAY_DIVISION_SRC) $(ARRAY_DIVISION_INC)
array_division.so.s: $(ARRAY_DIVISION_SRC) $(ARRAY_DIVISION_INC)

array_multiplication.a.s: $(ARRAY_MULTIPLICATION_SRC) $(ARRAY_MULTIPLICATION_INC)
array_multiplication.so.s: $(ARRAY_MULTIPLICATION_SRC) $(ARRAY_MULTIPLICATION_INC)

array_sum.a.s: $(ARRAY_SUM_SRC) $(ARRAY_SUM_INC)
array_sum.so.s: $(ARRAY_SUM_SRC) $(ARRAY_SUM_INC)

binomial_coefficient.a.s: $(BINOMIAL_COEFFICIENT_SRC) $(BINOMIAL_COEFFICIENT_INC)
binomial_coefficient.so.s: $(BINOMIAL_COEFFICIENT_SRC) $(BINOMIAL_COEFFICIENT_INC)

matrix_addition.a.s: $(MATRIX_ADDITION_SRC) $(MATRIX_ADDITION_INC)
matrix_addition.so.s: $(MATRIX_ADDITION_SRC) $(MATRIX_ADDITION_INC)

matrix_subtraction.a.s: $(MATRIX_SUBTRACTION_SRC) $(MATRIX_SUBTRACTION_INC)
matrix_subtraction.so.s: $(MATRIX_SUBTRACTION_SRC) $(MATRIX_SUBTRACTION_INC)

pascal_triangle.a.s: $(PASCAL_TRIANGLE_SRC) $(PASCAL_TRIANGLE_INC)
pascal_triangle.so.s: $(PASCAL_TRIANGLE_SRC) $(PASCAL_TRIANGLE_INC)

prime.a.s: $(PRIME_SRC) $(PRIME_INC)
prime.so.s: $(PRIME_SRC) $(PRIME_INC)

prime_defactorization.a.s: $(PRIME_DEFACTORIZATION_SRC) $(PRIME_DEFACTORIZATION_INC)
prime_defactorization.so.s: $(PRIME_DEFACTORIZATION_SRC) $(PRIME_DEFACTORIZATION_INC)

prime_factorization.a.s: $(PRIME_FACTORIZATION_SRC) $(PRIME_FACTORIZATION_INC)
prime_factorization.so.s: $(PRIME_FACTORIZATION_SRC) $(PRIME_FACTORIZATION_INC)

scale_linear.a.s: $(SCALE_LINEAR_SRC) $(SCALE_LINEAR_INC)
scale_linear.so.s: $(SCALE_LINEAR_SRC) $(SCALE_LINEAR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
