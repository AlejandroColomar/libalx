#!/usr/bin/make -f

# MACRO = substitute with this

# dependencies

BASE_MATH_OBJ	=							\
		$(TMP_DIR)/base/math/arithmetic_mean.o			\
		$(TMP_DIR)/base/math/binomial_coefficient.o		\
		$(TMP_DIR)/base/math/factorial.o			\
		$(TMP_DIR)/base/math/median.o				\
		$(TMP_DIR)/base/math/pascal_triangle.o			\
		$(TMP_DIR)/base/math/prime.o				\
		$(TMP_DIR)/base/math/prime_factors.o			\
		$(TMP_DIR)/base/math/scale_linear.o
BASE_STDLIB_OBJ	=							\
		$(TMP_DIR)/base/stdlib/compare.o			\
		$(TMP_DIR)/base/stdlib/search.o				\
		$(TMP_DIR)/base/stdlib/local_maxima.o			\
		$(TMP_DIR)/base/stdlib/matrix_addition.o		\
		$(TMP_DIR)/base/stdlib/matrix_subtraction.o		\
		$(TMP_DIR)/base/stdlib/maximum.o			\
		$(TMP_DIR)/base/stdlib/popcnt.o				\
		$(TMP_DIR)/base/stdlib/pow.o				\
		$(TMP_DIR)/base/stdlib/seed_mix.o

BASE_OBJ	=							\
		$(BASE_MATH_OBJ)					\
		$(BASE_STDLIB_OBJ)
IO_OBJ		=							\
		$(TMP_DIR)/io/alx_input.o				\
		$(TMP_DIR)/io/alx_file.o
CURSES_OBJ	=							\
		$(TMP_DIR)/curses/alx_ncur.o

# target: dependencies
#	action

PHONY := all
all: base io curses

PHONY += base
base: libalx/libalx-base.a

PHONY += io
io: libalx/libalx-io.a

PHONY += curses
curses: libalx/libalx-curses.a


libalx/libalx-base.a: $(BASE_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-io.a: $(IO_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-curses.a: $(CURSES_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^


PHONY += clean
clean:
	$(Q)rm -f *.a

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
