#! /usr/bin/make -f

# MACRO = substitute with this

# dependencies

BASE_OBJ	=							\
		$(TMP_DIR)/base/assert/assert.o				\
		$(TMP_DIR)/base/compiler/size.o				\
		$(TMP_DIR)/base/compiler/type.o				\
		$(TMP_DIR)/base/compiler/unused.o			\
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
		$(TMP_DIR)/base/stdio/fgets.o				\
		$(TMP_DIR)/base/stdio/get.o				\
		$(TMP_DIR)/base/stdio/printf/b.o			\
		$(TMP_DIR)/base/stdio/printf/sbprintf.o			\
		$(TMP_DIR)/base/stdio/printf/snprintfs.o		\
		$(TMP_DIR)/base/stdio/seekc.o				\
		$(TMP_DIR)/base/stdio/sscan.o				\
		$(TMP_DIR)/base/stdlib/alloc/callocs.o			\
		$(TMP_DIR)/base/stdlib/alloc/frees.o			\
		$(TMP_DIR)/base/stdlib/alloc/mallocarray.o		\
		$(TMP_DIR)/base/stdlib/alloc/mallocarrays.o		\
		$(TMP_DIR)/base/stdlib/alloc/mallocs.o			\
		$(TMP_DIR)/base/stdlib/alloc/reallocarrayf.o		\
		$(TMP_DIR)/base/stdlib/alloc/reallocarrayfs.o		\
		$(TMP_DIR)/base/stdlib/alloc/reallocarrays.o		\
		$(TMP_DIR)/base/stdlib/alloc/reallocfs.o		\
		$(TMP_DIR)/base/stdlib/alloc/reallocs.o			\
		$(TMP_DIR)/base/stdlib/array_split_pos_neg.o		\
		$(TMP_DIR)/base/stdlib/average.o			\
		$(TMP_DIR)/base/stdlib/clz.o				\
		$(TMP_DIR)/base/stdlib/compare.o			\
		$(TMP_DIR)/base/stdlib/ctz.o				\
		$(TMP_DIR)/base/stdlib/local_maxima.o			\
		$(TMP_DIR)/base/stdlib/maximum.o			\
		$(TMP_DIR)/base/stdlib/minimum.o			\
		$(TMP_DIR)/base/stdlib/popcnt.o				\
		$(TMP_DIR)/base/stdlib/pow.o				\
		$(TMP_DIR)/base/stdlib/search.o				\
		$(TMP_DIR)/base/stdlib/seed.o				\
		$(TMP_DIR)/base/stdlib/strto/strtof_s.o			\
		$(TMP_DIR)/base/stdlib/strto/strtoi_s.o			\
		$(TMP_DIR)/base/stdlib/strto/strtou_s.o			\
		$(TMP_DIR)/base/stdlib/swap.o				\
		$(TMP_DIR)/base/string/memchr/memchrend.o		\
		$(TMP_DIR)/base/string/strcat/strscat.o			\
		$(TMP_DIR)/base/string/strchr/strcasechr.o		\
		$(TMP_DIR)/base/string/strchr/strcasechrnul.o		\
		$(TMP_DIR)/base/string/strchr/strncasechr.o		\
		$(TMP_DIR)/base/string/strchr/strncasechrnul.o		\
		$(TMP_DIR)/base/string/strchr/strnchr.o			\
		$(TMP_DIR)/base/string/strchr/strnchrnul.o		\
		$(TMP_DIR)/base/string/strchr/strnrcasechr.o		\
		$(TMP_DIR)/base/string/strchr/strnrcasechrnul.o		\
		$(TMP_DIR)/base/string/strchr/strnrchr.o		\
		$(TMP_DIR)/base/string/strchr/strnrchrnul.o		\
		$(TMP_DIR)/base/string/strchr/strrcasechr.o		\
		$(TMP_DIR)/base/string/strchr/strrcasechrnul.o		\
		$(TMP_DIR)/base/string/strchr/strrchrnul.o		\
		$(TMP_DIR)/base/string/strcpy/strscpy.o			\
		$(TMP_DIR)/base/string/strlwr/strlwr.o			\
		$(TMP_DIR)/base/string/strlwr/strnlwr.o			\
		$(TMP_DIR)/base/string/strlwr/strupr.o			\
		$(TMP_DIR)/base/string/strlwr/strnupr.o			\
		$(TMP_DIR)/base/string/strgrep.o			\
		$(TMP_DIR)/base/string/strstr/strncasestr.o		\
		$(TMP_DIR)/base/string/strstr/strscasestr.o		\
		$(TMP_DIR)/base/string/strstr/strsstr.o

ALX_DS_OBJ	=							\
		$(TMP_DIR)/alx/data-structures/bst.o			\
		$(TMP_DIR)/alx/data-structures/dyn-array.o		\
		$(TMP_DIR)/alx/data-structures/dyn-buffer.o		\
		$(TMP_DIR)/alx/data-structures/llist.o			\
		$(TMP_DIR)/alx/data-structures/node.o
ALX_NPC_OBJ	=							\
		$(TMP_DIR)/alx/npcomplete/solver_lut.o

CURL_OBJ	=							\
		$(TMP_DIR)/extra/curl/fcurl/fclose.o			\
		$(TMP_DIR)/extra/curl/fcurl/feof.o			\
		$(TMP_DIR)/extra/curl/fcurl/fgetc.o			\
		$(TMP_DIR)/extra/curl/fcurl/fgets.o			\
		$(TMP_DIR)/extra/curl/fcurl/fopen.o			\
		$(TMP_DIR)/extra/curl/fcurl/fread.o			\
		$(TMP_DIR)/extra/curl/fcurl/init.o			\
		$(TMP_DIR)/extra/curl/fcurl/internal.o			\
		$(TMP_DIR)/extra/curl/fcurl/rewind.o			\
		$(TMP_DIR)/extra/curl/fcurl/ungetc.o			\
		$(TMP_DIR)/extra/curl/fcurl/URL_FILE.o
CV_OBJ		=							\
		$(TMP_DIR)/extra/cv/alx.o				\
		$(TMP_DIR)/extra/cv/core.o				\
		$(TMP_DIR)/extra/cv/features2d.o			\
		$(TMP_DIR)/extra/cv/highgui.o				\
		$(TMP_DIR)/extra/cv/imgproc.o				\
		$(TMP_DIR)/extra/cv/ximgproc.o
GMP_OBJ		=							\
		$(TMP_DIR)/extra/gmp/mpq/cmp.o				\
		$(TMP_DIR)/extra/gmp/mpz/arithmetic.o			\
		$(TMP_DIR)/extra/gmp/mpz/cmp.o				\
		$(TMP_DIR)/extra/gmp/mpz/division.o			\
		$(TMP_DIR)/extra/gmp/mpz/exp.o				\
		$(TMP_DIR)/extra/gmp/mpz/get.o				\
		$(TMP_DIR)/extra/gmp/mpz/init_set.o			\
		$(TMP_DIR)/extra/gmp/mpz/misc.o				\
		$(TMP_DIR)/extra/gmp/mpz/root.o				\
		$(TMP_DIR)/extra/gmp/mpz/set.o				\
		$(TMP_DIR)/extra/gmp/mpz/theoretic.o
GSL_OBJ		=							\
		$(TMP_DIR)/extra/gsl/distributions/binomial.o		\
		$(TMP_DIR)/extra/gsl/distributions/exponential.o	\
		$(TMP_DIR)/extra/gsl/distributions/geometric.o		\
		$(TMP_DIR)/extra/gsl/distributions/normal.o		\
		$(TMP_DIR)/extra/gsl/distributions/poisson.o		\
		$(TMP_DIR)/extra/gsl/distributions/uniform.o		\
		$(TMP_DIR)/extra/gsl/rstat/median.o			\
		$(TMP_DIR)/extra/gsl/statistics/mean.o			\
		$(TMP_DIR)/extra/gsl/units/len.o			\
		$(TMP_DIR)/extra/gsl/units/temp.o			\
		$(TMP_DIR)/extra/gsl/units/weight.o
NCURSES_OBJ	=							\
		$(TMP_DIR)/extra/ncurses/common.o			\
		$(TMP_DIR)/extra/ncurses/get.o				\
		$(TMP_DIR)/extra/ncurses/menu.o				\
		$(TMP_DIR)/extra/ncurses/perror.o
NPCOMPLETE_OBJ	=							\
		$(TMP_DIR)/extra/npcomplete/solver_lut.o
OCR_OBJ		=							\
		$(TMP_DIR)/extra/ocr/ocr.o
ZBAR_OBJ	=							\
		$(TMP_DIR)/extra/zbar/zbar.o


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
	@echo	"	MKDIR	libalx/lib/$@"
	$(Q)mkdir -p		$(LIB_DIR)/$@/


%.a:
	@echo	"	AR	libalx/lib/$@"
	$(Q)$(AR) -r -c -s -o $@ $^


libalx/libalx-base.a: $(patsubst %.o,%.a.o,$(BASE_OBJ))
libalx/libalx-base.so: $(patsubst %.o,%.so.o,$(BASE_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libbsd-overlay`


libalx/libalx-data-structures.a: $(patsubst %.o,%.a.o,$(ALX_DS_OBJ))
libalx/libalx-data-structures.so: $(patsubst %.o,%.so.o,$(ALX_DS_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l alx-base


libalx/libalx-npcomplete.a: $(patsubst %.o,%.a.o,$(ALX_NPC_OBJ))
libalx/libalx-npcomplete.so: $(patsubst %.o,%.so.o,$(ALX_NPC_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -fopenmp -l alx-base

libalx/libalx-curl.a: $(patsubst %.o,%.a.o,$(CURL_OBJ))
libalx/libalx-curl.so: $(patsubst %.o,%.so.o,$(CURL_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs libcurl`	\
					-l alx-data-structures -l alx-base

libalx/libalx-cv.a: $(patsubst %.o,%.a.o,$(CV_OBJ))
libalx/libalx-cv.so: $(patsubst %.o,%.so.o,$(CV_OBJ))
	@echo	"	CXX	libalx/lib/$@"
	$(Q)$(CXX) $(LDFLAGS) -o $@ $^ `pkg-config --libs opencv4`	\
						-l alx-gsl -l alx-base

libalx/libalx-gmp.a: $(patsubst %.o,%.a.o,$(GMP_OBJ))
libalx/libalx-gmp.so: $(patsubst %.o,%.so.o,$(GMP_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ -l gmp				\
						-l alx-base

libalx/libalx-gsl.a: $(patsubst %.o,%.a.o,$(GSL_OBJ))
libalx/libalx-gsl.so: $(patsubst %.o,%.so.o,$(GSL_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs gsl`		\
						-l alx-base

libalx/libalx-ncurses.a: $(patsubst %.o,%.a.o,$(NCURSES_OBJ))
libalx/libalx-ncurses.so: $(patsubst %.o,%.so.o,$(NCURSES_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs ncurses`	\
						-l alx-base

libalx/libalx-ocr.a: $(patsubst %.o,%.a.o,$(OCR_OBJ))
libalx/libalx-ocr.so: $(patsubst %.o,%.so.o,$(OCR_OBJ))
	@echo	"	CC	libalx/lib/$@"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^ `pkg-config --libs tesseract`	\
						-l alx-base

libalx/libalx-zbar.a: $(patsubst %.o,%.a.o,$(ZBAR_OBJ))
libalx/libalx-zbar.so: $(patsubst %.o,%.so.o,$(ZBAR_OBJ))
	@echo	"	CC	libalx/lib/$@"
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
