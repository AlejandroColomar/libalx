#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

MATH_OBJ	=							\
		$(TMP_DIR)/math/arithmetic_mean.o			\
		$(TMP_DIR)/math/array_division.o			\
		$(TMP_DIR)/math/array_multiplication.o			\
		$(TMP_DIR)/math/array_sum.o				\
		$(TMP_DIR)/math/binomial_coefficient.o			\
		$(TMP_DIR)/math/factorial.o				\
		$(TMP_DIR)/math/matrix_addition.o			\
		$(TMP_DIR)/math/matrix_subtraction.o			\
		$(TMP_DIR)/math/median.o				\
		$(TMP_DIR)/math/pascal_triangle.o			\
		$(TMP_DIR)/math/prime.o					\
		$(TMP_DIR)/math/prime_defactorization.o			\
		$(TMP_DIR)/math/prime_factorization.o			\
		$(TMP_DIR)/math/scale_linear.o
STDDEF_OBJ	=							\
		$(TMP_DIR)/stddef/size.o
STDINT_OBJ	=							\
		$(TMP_DIR)/stdint/constants.o				\
		$(TMP_DIR)/stdint/int128.o
STDIO_OBJ	=							\
		$(TMP_DIR)/stdio/get.o					\
		$(TMP_DIR)/stdio/sprint_file.o				\
		$(TMP_DIR)/stdio/sscan.o
STDLIB_OBJ	=							\
		$(TMP_DIR)/stdlib/array_split_pos_neg.o			\
		$(TMP_DIR)/stdlib/compare.o				\
		$(TMP_DIR)/stdlib/local_maxima.o			\
		$(TMP_DIR)/stdlib/maximum.o				\
		$(TMP_DIR)/stdlib/minimum.o				\
		$(TMP_DIR)/stdlib/popcnt.o				\
		$(TMP_DIR)/stdlib/pow.o					\
		$(TMP_DIR)/stdlib/search.o				\
		$(TMP_DIR)/stdlib/seed_mix.o
STRING_OBJ	=							\
		$(TMP_DIR)/string/memcpy.o				\
		$(TMP_DIR)/string/strchr.o				\
		$(TMP_DIR)/string/strgrep.o				\
		$(TMP_DIR)/string/strstr.o
CURSES_OBJ	=							\
		$(TMP_DIR)/curses/alx_ncur.o

# target: dependencies
#	action

PHONY := all
all: libalx math stddef stdint stdio stdlib string curses

PHONY += math
math: libalx libalx/libalx-math.a

PHONY += stddef
stddef: libalx libalx/libalx-stddef.a

PHONY += stdint
stdint: libalx libalx/libalx-stdint.a

PHONY += stdio
stdio: libalx libalx/libalx-stdio.a

PHONY += stdlib
stdlib: libalx libalx/libalx-stdlib.a

PHONY += string
string: libalx libalx/libalx-string.a

PHONY += curses
curses: libalx libalx/libalx-curses.a


libalx:
	@echo	"	MKDIR	libalx/lib/$@"
	$(Q)mkdir -p		$(LIB_DIR)/$@/

libalx/libalx-math.a: $(MATH_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-stddef.a: $(STDDEF_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-stdint.a: $(STDINT_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-stdlib.a: $(STDLIB_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-string.a: $(STRING_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-stdio.a: $(IO_OBJ)
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
