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
		alloc

OBJ		=							\
		alloc/mallocs.o						\
		array_split_pos_neg.o					\
		average.o						\
		compare.o						\
		local_maxima.o						\
		maximum.o						\
		minimum.o						\
		popcnt.o						\
		pow.o							\
		search.o						\
		seed.o							\
		swap.o

ALLOC_MALLOCS_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocs.h
ALLOC_MALLOCS_SRC	=						\
		$(SRC_DIR)/base/stdlib/alloc/mallocs.c

ARRAY_SPLIT_POS_NEG_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/array_split_pos_neg.h
ARRAY_SPLIT_POS_NEG_SRC	=						\
		$(SRC_DIR)/base/stdlib/array_split_pos_neg.c

AVERAGE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/average.h
AVERAGE_SRC	=							\
		$(SRC_DIR)/base/stdlib/average.c

COMPARE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/compare.h
COMPARE_SRC	=							\
		$(SRC_DIR)/base/stdlib/compare.c

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


%.a.s:
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@


alloc/mallocs.a.s: $(ALLOC_MALLOCS_SRC) $(ALLOC_MALLOCS_INC)
alloc/mallocs.so.s: $(ALLOC_MALLOCS_SRC) $(ALLOC_MALLOCS_INC)

array_split_pos_neg.a.s: $(ARRAY_SPLIT_POS_NEG_SRC) $(ARRAY_SPLIT_POS_NEG_INC)
array_split_pos_neg.so.s: $(ARRAY_SPLIT_POS_NEG_SRC) $(ARRAY_SPLIT_POS_NEG_INC)

average.a.s: $(AVERAGE_SRC) $(AVERAGE_INC)
average.so.s: $(AVERAGE_SRC) $(AVERAGE_INC)

compare.a.s: $(COMPARE_SRC) $(COMPARE_INC)
compare.so.s: $(COMPARE_SRC) $(COMPARE_INC)

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
