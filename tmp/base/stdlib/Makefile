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

DIRS		=							\
		alloc							\
		strto

OBJ		=							\
		alloc/callocs.o						\
		alloc/mallocarray.o					\
		alloc/mallocs.o						\
		alloc/reallocs.o					\
		array_split_pos_neg.o					\
		average.o						\
		clz.o							\
		compare.o						\
		ctz.o							\
		local_maxima.o						\
		maximum.o						\
		minimum.o						\
		popcnt.o						\
		pow.o							\
		search.o						\
		seed.o							\
		strto/strtof_s.o					\
		strto/strtoi_s.o					\
		strto/strtou_s.o					\
		swap.o

ALLOC_CALLOCS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/alloc/callocs.h
ALLOC_CALLOCS_SRC	=						\
		$(SRC_DIR)/base/stdlib/alloc/callocs.c

ALLOC_MALLOCARRAY_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarray.h
ALLOC_MALLOCARRAY_SRC	=						\
		$(SRC_DIR)/base/stdlib/alloc/mallocarray.c

ALLOC_MALLOCS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocs.h
ALLOC_MALLOCS_SRC	=						\
		$(SRC_DIR)/base/stdlib/alloc/mallocs.c

ALLOC_REALLOCS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/alloc/reallocs.h
ALLOC_REALLOCS_SRC	=						\
		$(SRC_DIR)/base/stdlib/alloc/reallocs.c

ARRAY_SPLIT_POS_NEG_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/array_split_pos_neg.h
ARRAY_SPLIT_POS_NEG_SRC	=						\
		$(SRC_DIR)/base/stdlib/array_split_pos_neg.c

AVERAGE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/average.h
AVERAGE_SRC	=							\
		$(SRC_DIR)/base/stdlib/average.c

CLZ_INC		=							\
		$(INC_DIR)/libalx/base/stdlib/clz.h
CLZ_SRC		=							\
		$(SRC_DIR)/base/stdlib/clz.c

COMPARE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/compare.h
COMPARE_SRC	=							\
		$(SRC_DIR)/base/stdlib/compare.c

CTZ_INC		=							\
		$(INC_DIR)/libalx/base/stdlib/ctz.h
CTZ_SRC		=							\
		$(SRC_DIR)/base/stdlib/ctz.c

LOCAL_MAXIMA_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/local_maxima.h
LOCAL_MAXIMA_SRC	=						\
		$(SRC_DIR)/base/stdlib/local_maxima.c

MAXIMUM_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/maximum.h
MAXIMUM_SRC	=							\
		$(SRC_DIR)/base/stdlib/maximum.c

MINIMUM_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/minimum.h
MINIMUM_SRC	=							\
		$(SRC_DIR)/base/stdlib/minimum.c

POPCNT_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/popcnt.h
POPCNT_SRC	=							\
		$(SRC_DIR)/base/stdlib/popcnt.c

POW_INC		=							\
		$(INC_DIR)/libalx/base/stdlib/pow.h			\
		$(INC_DIR)/libalx/base/stdint/constants.h
POW_SRC		=							\
		$(SRC_DIR)/base/stdlib/pow.c

SEARCH_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/search.h			\
		$(INC_DIR)/libalx/base/stdlib/average.h
SEARCH_SRC	=							\
		$(SRC_DIR)/base/stdlib/search.c

SEED_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/seed.h
SEED_SRC	=							\
		$(SRC_DIR)/base/stdlib/seed.c

STRTO_STRTOFS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/strto/strtof_s.h
STRTO_STRTOFS_SRC	=						\
		$(SRC_DIR)/base/stdlib/strto/strtof_s.c

STRTO_STRTOIS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/strto/strtoi_s.h
STRTO_STRTOIS_SRC	=						\
		$(SRC_DIR)/base/stdlib/strto/strtoi_s.c

STRTO_STRTOUS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/strto/strtou_s.h
STRTO_STRTOUS_SRC	=						\
		$(SRC_DIR)/base/stdlib/strto/strtou_s.c

SWAP_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/swap.h
SWAP_SRC	=							\
		$(SRC_DIR)/base/stdlib/swap.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(DIRS) $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


alloc:
	@echo	"	MKDIR	libalx/tmp/base/stdlib/$@"
	$(Q)mkdir -p		$@/
strto:
	@echo	"	MKDIR	libalx/tmp/base/stdlib/$@"
	$(Q)mkdir -p		$@/


%.a.s:
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@


alloc/callocs.a.s: $(ALLOC_CALLOCS_SRC) $(ALLOC_CALLOCS_INC)
alloc/callocs.so.s: $(ALLOC_CALLOCS_SRC) $(ALLOC_CALLOCS_INC)

alloc/mallocarray.a.s: $(ALLOC_MALLOCARRAY_SRC) $(ALLOC_MALLOCARRAY_INC)
alloc/mallocarray.so.s: $(ALLOC_MALLOCARRAY_SRC) $(ALLOC_MALLOCARRAY_INC)

alloc/mallocs.a.s: $(ALLOC_MALLOCS_SRC) $(ALLOC_MALLOCS_INC)
alloc/mallocs.so.s: $(ALLOC_MALLOCS_SRC) $(ALLOC_MALLOCS_INC)

alloc/reallocs.a.s: $(ALLOC_REALLOCS_SRC) $(ALLOC_REALLOCS_INC)
alloc/reallocs.so.s: $(ALLOC_REALLOCS_SRC) $(ALLOC_REALLOCS_INC)

array_split_pos_neg.a.s: $(ARRAY_SPLIT_POS_NEG_SRC) $(ARRAY_SPLIT_POS_NEG_INC)
array_split_pos_neg.so.s: $(ARRAY_SPLIT_POS_NEG_SRC) $(ARRAY_SPLIT_POS_NEG_INC)

average.a.s: $(AVERAGE_SRC) $(AVERAGE_INC)
average.so.s: $(AVERAGE_SRC) $(AVERAGE_INC)

clz.a.s: $(CLZ_SRC) $(CLZ_INC)
clz.so.s: $(CLZ_SRC) $(CLZ_INC)

compare.a.s: $(COMPARE_SRC) $(COMPARE_INC)
compare.so.s: $(COMPARE_SRC) $(COMPARE_INC)

ctz.a.s: $(CTZ_SRC) $(CTZ_INC)
ctz.so.s: $(CTZ_SRC) $(CTZ_INC)

local_maxima.a.s: $(LOCAL_MAXIMA_SRC) $(LOCAL_MAXIMA_INC)
local_maxima.so.s: $(LOCAL_MAXIMA_SRC) $(LOCAL_MAXIMA_INC)

maximum.a.s: $(MAXIMUM_SRC) $(MAXIMUM_INC)
maximum.so.s: $(MAXIMUM_SRC) $(MAXIMUM_INC)

minimum.a.s: $(MINIMUM_SRC) $(MINIMUM_INC)
minimum.so.s: $(MINIMUM_SRC) $(MINIMUM_INC)

popcnt.a.s: $(POPCNT_SRC) $(POPCNT_INC)
popcnt.so.s: $(POPCNT_SRC) $(POPCNT_INC)

pow.a.s: $(POW_SRC) $(POW_INC)
pow.so.s: $(POW_SRC) $(POW_INC)

search.a.s: $(SEARCH_SRC) $(SEARCH_INC)
search.so.s: $(SEARCH_SRC) $(SEARCH_INC)

seed.a.s: $(SEED_SRC) $(SEED_INC)
seed.so.s: $(SEED_SRC) $(SEED_INC)

strto/strtof_s.a.s: $(STRTO_STRTOFS_SRC) $(STRTO_STRTOFS_INC)
strto/strtof_s.so.s: $(STRTO_STRTOFS_SRC) $(STRTO_STRTOFS_INC)

strto/strtoi_s.a.s: $(STRTO_STRTOIS_SRC) $(STRTO_STRTOIS_INC)
strto/strtoi_s.so.s: $(STRTO_STRTOIS_SRC) $(STRTO_STRTOIS_INC)

strto/strtou_s.a.s: $(STRTO_STRTOUS_SRC) $(STRTO_STRTOUS_INC)
strto/strtou_s.so.s: $(STRTO_STRTOUS_SRC) $(STRTO_STRTOUS_INC)

swap.a.s: $(SWAP_SRC) $(SWAP_INC)
swap.so.s: $(SWAP_SRC) $(SWAP_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
