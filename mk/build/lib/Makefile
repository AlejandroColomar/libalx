#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

BASE_OBJ	=							\
		$(BUILD_TMP_DIR)/base/assert/assert.o			\
		$(BUILD_TMP_DIR)/base/compiler/size.o			\
		$(BUILD_TMP_DIR)/base/compiler/type.o			\
		$(BUILD_TMP_DIR)/base/compiler/unused.o			\
		$(BUILD_TMP_DIR)/base/errno/error.o			\
		$(BUILD_TMP_DIR)/base/float/constant.o			\
		$(BUILD_TMP_DIR)/base/float/printf.o			\
		$(BUILD_TMP_DIR)/base/float/scanf.o			\
		$(BUILD_TMP_DIR)/base/libgen/basename.o			\
		$(BUILD_TMP_DIR)/base/libgen/dirname.o			\
		$(BUILD_TMP_DIR)/base/math/array_division.o		\
		$(BUILD_TMP_DIR)/base/math/array_multiplication.o	\
		$(BUILD_TMP_DIR)/base/math/array_sum.o			\
		$(BUILD_TMP_DIR)/base/math/binomial_coefficient.o	\
		$(BUILD_TMP_DIR)/base/math/matrix_addition.o		\
		$(BUILD_TMP_DIR)/base/math/matrix_subtraction.o		\
		$(BUILD_TMP_DIR)/base/math/pascal_triangle.o		\
		$(BUILD_TMP_DIR)/base/math/prime.o			\
		$(BUILD_TMP_DIR)/base/math/prime_defactorization.o	\
		$(BUILD_TMP_DIR)/base/math/prime_factorization.o	\
		$(BUILD_TMP_DIR)/base/math/scale_linear.o		\
		$(BUILD_TMP_DIR)/base/stdint/constants.o		\
		$(BUILD_TMP_DIR)/base/stdint/types.o			\
		$(BUILD_TMP_DIR)/base/stdio/fgets.o			\
		$(BUILD_TMP_DIR)/base/stdio/get.o			\
		$(BUILD_TMP_DIR)/base/stdio/printf/b.o			\
		$(BUILD_TMP_DIR)/base/stdio/printf/sbprintf.o		\
		$(BUILD_TMP_DIR)/base/stdio/printf/snprintfs.o		\
		$(BUILD_TMP_DIR)/base/stdio/seekc.o			\
		$(BUILD_TMP_DIR)/base/stdio/sscan.o			\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/callocs.o		\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/frees.o		\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/mallocarray.o	\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/mallocarrays.o	\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/mallocs.o		\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/reallocarrayf.o	\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/reallocarrayfs.o	\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/reallocarrays.o	\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/reallocfs.o		\
		$(BUILD_TMP_DIR)/base/stdlib/alloc/reallocs.o		\
		$(BUILD_TMP_DIR)/base/stdlib/array_split_pos_neg.o	\
		$(BUILD_TMP_DIR)/base/stdlib/average.o			\
		$(BUILD_TMP_DIR)/base/stdlib/clz.o			\
		$(BUILD_TMP_DIR)/base/stdlib/compare.o			\
		$(BUILD_TMP_DIR)/base/stdlib/ctz.o			\
		$(BUILD_TMP_DIR)/base/stdlib/local_maxima.o		\
		$(BUILD_TMP_DIR)/base/stdlib/maximum.o			\
		$(BUILD_TMP_DIR)/base/stdlib/minimum.o			\
		$(BUILD_TMP_DIR)/base/stdlib/popcnt.o			\
		$(BUILD_TMP_DIR)/base/stdlib/pow.o			\
		$(BUILD_TMP_DIR)/base/stdlib/search.o			\
		$(BUILD_TMP_DIR)/base/stdlib/seed.o			\
		$(BUILD_TMP_DIR)/base/stdlib/strto/strtof_s.o		\
		$(BUILD_TMP_DIR)/base/stdlib/strto/strtoi_s.o		\
		$(BUILD_TMP_DIR)/base/stdlib/strto/strtou_s.o		\
		$(BUILD_TMP_DIR)/base/stdlib/swap.o			\
		$(BUILD_TMP_DIR)/base/string/memchr/memchrend.o		\
		$(BUILD_TMP_DIR)/base/string/strcat/strscat.o		\
		$(BUILD_TMP_DIR)/base/string/strchr/strcasechr.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strcasechrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strncasechr.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strncasechrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strnchr.o		\
		$(BUILD_TMP_DIR)/base/string/strchr/strnchrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strnrcasechr.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strnrcasechrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strnrchr.o		\
		$(BUILD_TMP_DIR)/base/string/strchr/strnrchrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strrcasechr.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strrcasechrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strchr/strrchrnul.o	\
		$(BUILD_TMP_DIR)/base/string/strcpy/strlcpys.o		\
		$(BUILD_TMP_DIR)/base/string/strcpy/strscpy.o		\
		$(BUILD_TMP_DIR)/base/string/strlwr/strlwr.o		\
		$(BUILD_TMP_DIR)/base/string/strlwr/strnlwr.o		\
		$(BUILD_TMP_DIR)/base/string/strlwr/strupr.o		\
		$(BUILD_TMP_DIR)/base/string/strlwr/strnupr.o		\
		$(BUILD_TMP_DIR)/base/string/strgrep.o			\
		$(BUILD_TMP_DIR)/base/string/strstr/strncasestr.o	\
		$(BUILD_TMP_DIR)/base/string/strstr/strscasestr.o	\
		$(BUILD_TMP_DIR)/base/string/strstr/strsstr.o

ALX_DS_OBJ	=							\
		$(BUILD_TMP_DIR)/alx/data-structures/bst.o		\
		$(BUILD_TMP_DIR)/alx/data-structures/dyn-array.o	\
		$(BUILD_TMP_DIR)/alx/data-structures/dyn-buffer.o	\
		$(BUILD_TMP_DIR)/alx/data-structures/llist.o		\
		$(BUILD_TMP_DIR)/alx/data-structures/node.o
ALX_NPC_OBJ	=							\
		$(BUILD_TMP_DIR)/alx/npcomplete/solver_lut.o

CURL_OBJ	=							\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/fclose.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/feof.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/fgetc.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/fgets.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/fopen.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/fread.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/init.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/internal.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/rewind.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/ungetc.o		\
		$(BUILD_TMP_DIR)/extra/curl/fcurl/URL_FILE.o
CV_OBJ		=							\
		$(BUILD_TMP_DIR)/extra/cv/alx.o				\
		$(BUILD_TMP_DIR)/extra/cv/core.o			\
		$(BUILD_TMP_DIR)/extra/cv/features2d.o			\
		$(BUILD_TMP_DIR)/extra/cv/highgui.o			\
		$(BUILD_TMP_DIR)/extra/cv/imgproc.o			\
		$(BUILD_TMP_DIR)/extra/cv/ximgproc.o
GMP_OBJ		=							\
		$(BUILD_TMP_DIR)/extra/gmp/mpq/cmp.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/arithmetic.o		\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/cmp.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/division.o		\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/exp.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/get.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/init_set.o		\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/misc.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/root.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/set.o			\
		$(BUILD_TMP_DIR)/extra/gmp/mpz/theoretic.o
GSL_OBJ		=							\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/binomial.o	\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/exponential.o	\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/geometric.o	\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/normal.o	\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/poisson.o	\
		$(BUILD_TMP_DIR)/extra/gsl/distributions/uniform.o	\
		$(BUILD_TMP_DIR)/extra/gsl/rstat/median.o		\
		$(BUILD_TMP_DIR)/extra/gsl/statistics/mean.o		\
		$(BUILD_TMP_DIR)/extra/gsl/units/len.o			\
		$(BUILD_TMP_DIR)/extra/gsl/units/temp.o			\
		$(BUILD_TMP_DIR)/extra/gsl/units/weight.o
NCURSES_OBJ	=							\
		$(BUILD_TMP_DIR)/extra/ncurses/common.o			\
		$(BUILD_TMP_DIR)/extra/ncurses/get.o			\
		$(BUILD_TMP_DIR)/extra/ncurses/menu.o			\
		$(BUILD_TMP_DIR)/extra/ncurses/perror.o
NPCOMPLETE_OBJ	=							\
		$(BUILD_TMP_DIR)/extra/npcomplete/solver_lut.o
OCR_OBJ		=							\
		$(BUILD_TMP_DIR)/extra/ocr/ocr.o
ZBAR_OBJ	=							\
		$(BUILD_TMP_DIR)/extra/zbar/zbar.o


ALL	= base alx extra

# target: dependencies
#	action

PHONY := all
all: $(ALL)


PHONY += base
base: libalx
	$(Q)$(MAKE)	libalx/libalx-base.a
	$(Q)$(MAKE)	libalx/libalx-base.so


PHONY += alx
alx: data-structures npcomplete

PHONY += data-structures
data-structures: libalx base
	$(Q)$(MAKE)	libalx/libalx-data-structures.a
	$(Q)$(MAKE)	libalx/libalx-data-structures.so

PHONY += npcomplete
npcomplete: libalx base
#	$(Q)$(MAKE)	libalx/libalx-npcomplete.a
#	$(Q)$(MAKE)	libalx/libalx-npcomplete.so


PHONY += extra
extra: curl cv gmp gsl ncurses ocr zbar

PHONY += curl
curl: libalx base data-structures
	$(Q)$(MAKE)	libalx/libalx-curl.a
	$(Q)$(MAKE)	libalx/libalx-curl.so

PHONY += cv
cv: libalx base gsl
	$(Q)$(MAKE)	libalx/libalx-cv.a
	$(Q)$(MAKE)	libalx/libalx-cv.so

PHONY += gmp
gmp: libalx base
	$(Q)$(MAKE)	libalx/libalx-gmp.a
	$(Q)$(MAKE)	libalx/libalx-gmp.so

PHONY += gsl
gsl: libalx base
	$(Q)$(MAKE)	libalx/libalx-gsl.a
	$(Q)$(MAKE)	libalx/libalx-gsl.so

PHONY += ncurses
ncurses: libalx base
	$(Q)$(MAKE)	libalx/libalx-ncurses.a
	$(Q)$(MAKE)	libalx/libalx-ncurses.so

PHONY += ocr
ocr: libalx base
	$(Q)$(MAKE)	libalx/libalx-ocr.a
	$(Q)$(MAKE)	libalx/libalx-ocr.so

PHONY += zbar
zbar: libalx base
	$(Q)$(MAKE)	libalx/libalx-zbar.a
	$(Q)$(MAKE)	libalx/libalx-zbar.so


libalx:
	@echo	"	MKDIR	build/lib/$@"
	$(Q)mkdir -p		$(BUILD_LIB_DIR)/$@/


%.a:
	@echo	"	AR	build/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^


libalx/libalx-base.a: $(patsubst %.o,%.a.o,$(BASE_OBJ))
libalx/libalx-base.so: $(patsubst %.o,%.so.o,$(BASE_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libbsd-overlay`


libalx/libalx-data-structures.a: $(patsubst %.o,%.a.o,$(ALX_DS_OBJ))
libalx/libalx-data-structures.so: $(patsubst %.o,%.so.o,$(ALX_DS_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l alx-base


libalx/libalx-npcomplete.a: $(patsubst %.o,%.a.o,$(ALX_NPC_OBJ))
libalx/libalx-npcomplete.so: $(patsubst %.o,%.so.o,$(ALX_NPC_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -fopenmp -l alx-base

libalx/libalx-curl.a: $(patsubst %.o,%.a.o,$(CURL_OBJ))
libalx/libalx-curl.so: $(patsubst %.o,%.so.o,$(CURL_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libcurl`	\
					-l alx-data-structures -l alx-base

libalx/libalx-cv.a: $(patsubst %.o,%.a.o,$(CV_OBJ))
libalx/libalx-cv.so: $(patsubst %.o,%.so.o,$(CV_OBJ))
	@echo	"	CXX	build/lib/$@"
	$(Q)$(CXX) $(LDFLAGS) -o $@ $^ `pkg-config --libs opencv4`	\
						-l alx-gsl -l alx-base

libalx/libalx-gmp.a: $(patsubst %.o,%.a.o,$(GMP_OBJ))
libalx/libalx-gmp.so: $(patsubst %.o,%.so.o,$(GMP_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l gmp				\
						-l alx-base

libalx/libalx-gsl.a: $(patsubst %.o,%.a.o,$(GSL_OBJ))
libalx/libalx-gsl.so: $(patsubst %.o,%.so.o,$(GSL_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs gsl`		\
						-l alx-base

libalx/libalx-ncurses.a: $(patsubst %.o,%.a.o,$(NCURSES_OBJ))
libalx/libalx-ncurses.so: $(patsubst %.o,%.so.o,$(NCURSES_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs ncurses`	\
						-l alx-base

libalx/libalx-ocr.a: $(patsubst %.o,%.a.o,$(OCR_OBJ))
libalx/libalx-ocr.so: $(patsubst %.o,%.so.o,$(OCR_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs tesseract`	\
						-l alx-base

libalx/libalx-zbar.a: $(patsubst %.o,%.a.o,$(ZBAR_OBJ))
libalx/libalx-zbar.so: $(patsubst %.o,%.so.o,$(ZBAR_OBJ))
	@echo	"	CC	build/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs zbar`		\
						-l alx-base


PHONY += clean
clean:
	$(Q)rm -f *.a *.so

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
