#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

BASE_OBJ	=							\
		$(TMP_DIR)/base/assert/assert.o				\
		$(TMP_DIR)/base/compiler/size.o				\
		$(TMP_DIR)/base/compiler/type.o				\
		$(TMP_DIR)/base/errno/error.o				\
		$(TMP_DIR)/base/float/constant.o			\
		$(TMP_DIR)/base/float/printf.o				\
		$(TMP_DIR)/base/float/scanf.o				\
		$(TMP_DIR)/base/math/array_division.o			\
		$(TMP_DIR)/base/math/array_multiplication.o		\
		$(TMP_DIR)/base/math/array_sum.o			\
		$(TMP_DIR)/base/math/binomial_coefficient.o		\
		$(TMP_DIR)/base/math/matrix_addition.o			\
		$(TMP_DIR)/base/math/matrix_subtraction.o		\
		$(TMP_DIR)/base/math/pascal_triangle.o			\
		$(TMP_DIR)/base/math/prime.o				\
		$(TMP_DIR)/base/math/prime_defactorization.o		\
		$(TMP_DIR)/base/math/prime_factorization.o		\
		$(TMP_DIR)/base/math/scale_linear.o			\
		$(TMP_DIR)/base/stdint/constants.o			\
		$(TMP_DIR)/base/stdint/types.o				\
		$(TMP_DIR)/base/stdio/get.o				\
		$(TMP_DIR)/base/stdio/printf/b.o			\
		$(TMP_DIR)/base/stdio/printf/sbprintf.o			\
		$(TMP_DIR)/base/stdio/printf/snprintfs.o		\
		$(TMP_DIR)/base/stdio/seekc.o				\
		$(TMP_DIR)/base/stdio/sscan.o				\
		$(TMP_DIR)/base/stdlib/alloc/mallocs.o			\
		$(TMP_DIR)/base/stdlib/array_split_pos_neg.o		\
		$(TMP_DIR)/base/stdlib/average.o			\
		$(TMP_DIR)/base/stdlib/compare.o			\
		$(TMP_DIR)/base/stdlib/local_maxima.o			\
		$(TMP_DIR)/base/stdlib/maximum.o			\
		$(TMP_DIR)/base/stdlib/minimum.o			\
		$(TMP_DIR)/base/stdlib/popcnt.o				\
		$(TMP_DIR)/base/stdlib/pow.o				\
		$(TMP_DIR)/base/stdlib/search.o				\
		$(TMP_DIR)/base/stdlib/seed_mix.o			\
		$(TMP_DIR)/base/stdlib/swap.o				\
		$(TMP_DIR)/base/string/strchr.o				\
		$(TMP_DIR)/base/string/strgrep.o			\
		$(TMP_DIR)/base/string/strstr.o

CV_OBJ		=							\
		$(TMP_DIR)/extra/cv/alx.o				\
		$(TMP_DIR)/extra/cv/core.o				\
		$(TMP_DIR)/extra/cv/highgui.o				\
		$(TMP_DIR)/extra/cv/imgproc.o				\
		$(TMP_DIR)/extra/cv/ximgproc.o
GSL_OBJ		=							\
		$(TMP_DIR)/extra/gsl/distributions/binomial.o		\
		$(TMP_DIR)/extra/gsl/distributions/exponential.o	\
		$(TMP_DIR)/extra/gsl/distributions/geometric.o		\
		$(TMP_DIR)/extra/gsl/distributions/normal.o		\
		$(TMP_DIR)/extra/gsl/distributions/poisson.o		\
		$(TMP_DIR)/extra/gsl/distributions/uniform.o		\
		$(TMP_DIR)/extra/gsl/rstat/median.o			\
		$(TMP_DIR)/extra/gsl/statistics/mean.o
NCURSES_OBJ	=							\
		$(TMP_DIR)/extra/ncurses/common.o			\
		$(TMP_DIR)/extra/ncurses/get.o				\
		$(TMP_DIR)/extra/ncurses/menu.o				\
		$(TMP_DIR)/extra/ncurses/perror.o
EXTRA_OBJ	=							\
		$(CV_OBJ)						\
		$(GSL_OBJ)						\
		$(NCURSES_OBJ)


ALL	= libalx							\
	base								\
	cv gsl ncurses							\
	extra

# target: dependencies
#	action

PHONY := all
all: $(ALL)

PHONY += base
base: libalx libalx/libalx-base.a


PHONY += cv
cv: libalx libalx/libalx-cv.a

PHONY += gsl
gsl: libalx libalx/libalx-gsl.a

PHONY += ncurses
ncurses: libalx libalx/libalx-ncurses.a

PHONY += extra
extra: libalx cv gsl ncurses libalx/libalx-extra.a


libalx:
	@echo	"	MKDIR	libalx/lib/$@"
	$(Q)mkdir -p		$(LIB_DIR)/$@/

libalx/libalx-base.a: $(BASE_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^


libalx/libalx-cv.a: $(CV_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-gsl.a: $(GSL_OBJ)
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^

libalx/libalx-ncurses.a: $(NCURSES_OBJ)
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
