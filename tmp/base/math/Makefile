#!/usr/bin/make -f

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
		binomial_coefficient.o					\
		factorial.o						\
		median.o						\
		pascal_triangle.o					\
		prime.o							\
		prime_factors.o						\
		scale_linear.o

ARITHMETIC_MEAN_INC	=						\
		$(INC_DIR)/libalx/base/math/arithmetic_mean.h
ARITHMETIC_MEAN_SRC	=						\
		$(SRC_DIR)/base/math/arithmetic_mean.c

BINOMIAL_COEFFICIENT_INC	=					\
		$(INC_DIR)/libalx/base/math/binomial_coefficient.h	\
		$(INC_DIR)/libalx/base/stdint.h				\
		$(INC_DIR)/libalx/base/math/common.h
BINOMIAL_COEFFICIENT_SRC	=					\
		$(SRC_DIR)/base/math/binomial_coefficient.c

FACTORIAL_INC	=							\
		$(INC_DIR)/libalx/base/math/factorial.h			\
		$(INC_DIR)/libalx/base/stdint.h				\
		$(INC_DIR)/libalx/base/math/common.h
FACTORIAL_SRC	=							\
		$(SRC_DIR)/base/math/factorial.c

MEDIAN_INC	=							\
		$(INC_DIR)/libalx/base/math/median.h			\
		$(INC_DIR)/libalx/base/stdlib/compare.h
MEDIAN_SRC	=							\
		$(SRC_DIR)/base/math/median.c

PASCAL_TRIANGLE_INC	=						\
		$(INC_DIR)/libalx/base/math/pascal_triangle.h		\
		$(INC_DIR)/libalx/base/stdint.h				\
		$(INC_DIR)/libalx/base/math/common.h
PASCAL_TRIANGLE_SRC	=						\
		$(SRC_DIR)/base/math/pascal_triangle.c

PRIME_INC	=							\
		$(INC_DIR)/libalx/base/math/prime.h			\
		$(INC_DIR)/libalx/base/stdlib/find.h
PRIME_SRC	=							\
		$(SRC_DIR)/base/math/prime.c

PRIME_FACTORS_INC	=						\
		$(INC_DIR)/libalx/base/math/prime_factors.h		\
		$(INC_DIR)/libalx/base/math/prime.h
PRIME_FACTORS_SRC	=						\
		$(SRC_DIR)/base/math/prime_factors.c

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

binomial_coefficient.s: $(BINOMIAL_COEFFICIENT_SRC) $(BINOMIAL_COEFFICIENT_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
binomial_coefficient.o: binomial_coefficient.s
	@echo	"	AS	libalx/tmp/base/math/$@"
	$(Q)$(AS) $< -o $@

factorial.s: $(FACTORIAL_SRC) $(FACTORIAL_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
factorial.o: factorial.s
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

prime_factors.s: $(PRIME_FACTORS_SRC) $(PRIME_FACTORS_INC)
	@echo	"	CC	libalx/tmp/base/math/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
prime_factors.o: prime_factors.s
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
