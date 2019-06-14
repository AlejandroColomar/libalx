#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

MATH_OBJ	=							\
		$(TMP_DIR)/base/math/array_division.o			\
		$(TMP_DIR)/base/math/array_multiplication.o		\
		$(TMP_DIR)/base/math/array_sum.o			\
		$(TMP_DIR)/base/math/binomial_coefficient.o		\
		$(TMP_DIR)/base/math/distribution_binomial.o		\
		$(TMP_DIR)/base/math/distribution_exponential.o		\
		$(TMP_DIR)/base/math/distribution_geometric.o		\
		$(TMP_DIR)/base/math/distribution_normal.o		\
		$(TMP_DIR)/base/math/distribution_poisson.o		\
		$(TMP_DIR)/base/math/distribution_uniform.o		\
		$(TMP_DIR)/base/math/factorial.o			\
		$(TMP_DIR)/base/math/matrix_addition.o			\
		$(TMP_DIR)/base/math/matrix_subtraction.o		\
		$(TMP_DIR)/base/math/median.o				\
		$(TMP_DIR)/base/math/pascal_triangle.o			\
		$(TMP_DIR)/base/math/prime.o				\
		$(TMP_DIR)/base/math/prime_defactorization.o		\
		$(TMP_DIR)/base/math/prime_factorization.o		\
		$(TMP_DIR)/base/math/scale_linear.o
STDDEF_OBJ	=
STDINT_OBJ	=
STDIO_OBJ	=							\
		$(TMP_DIR)/base/stdio/get.o				\
		$(TMP_DIR)/base/stdio/printf_b.o			\
		$(TMP_DIR)/base/stdio/sscan.o				\
		$(TMP_DIR)/base/stdio/wait.o
STDLIB_OBJ	=							\
		$(TMP_DIR)/base/stdlib/array_split_pos_neg.o		\
		$(TMP_DIR)/base/stdlib/average.o			\
		$(TMP_DIR)/base/stdlib/compare.o			\
		$(TMP_DIR)/base/stdlib/local_maxima.o			\
		$(TMP_DIR)/base/stdlib/maximum.o			\
		$(TMP_DIR)/base/stdlib/minimum.o			\
		$(TMP_DIR)/base/stdlib/popcnt.o				\
		$(TMP_DIR)/base/stdlib/pow.o				\
		$(TMP_DIR)/base/stdlib/search.o				\
		$(TMP_DIR)/base/stdlib/seed_mix.o
STRING_OBJ	=							\
		$(TMP_DIR)/base/string/memcpy.o				\
		$(TMP_DIR)/base/string/strchr.o				\
		$(TMP_DIR)/base/string/strgrep.o			\
		$(TMP_DIR)/base/string/strstr.o
BASE_OBJ	=							\
		$(MATH_OBJ)						\
		$(STDDEF_OBJ)						\
		$(STDINT_OBJ)						\
		$(STDIO_OBJ)						\
		$(STDLIB_OBJ)						\
		$(STRING_OBJ)

GSL_OBJ		=							\
		$(TMP_DIR)/extra/gsl/statistics/mean.o
NCURSES_OBJ	=							\
		$(TMP_DIR)/extra/ncurses/common.o			\
		$(TMP_DIR)/extra/ncurses/get.o				\
		$(TMP_DIR)/extra/ncurses/menu.o
EXTRA_OBJ	=							\
		$(GSL_OBJ)						\
		$(NCURSES_OBJ)


ALL	= libalx							\
	math stddef stdint stdio stdlib string				\
	base								\
	gsl ncurses							\
	extra

# target: dependencies
#	action

PHONY := all
all: $(ALL)

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

PHONY += base
base: libalx libalx/libalx-base.a


PHONY += gsl
gsl: libalx libalx/libalx-gsl.a

PHONY += ncurses
ncurses: libalx libalx/libalx-ncurses.a

PHONY += extra
extra: libalx libalx/libalx-extra.a


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

libalx/libalx-stdio.a: $(STDIO_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-string.a: $(STRING_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-base.a: $(BASE_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^


libalx/libalx-ncurses.a: $(NCURSES_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-gsl.a: $(GSL_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-extra.a: $(EXTRA_OBJ)
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
