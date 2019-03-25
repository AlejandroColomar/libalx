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
		array_split_pos_neg.o					\
		compare.o						\
		local_maxima.o						\
		maximum.o						\
		minimum.o						\
		popcnt.o						\
		pow.o							\
		search.o						\
		seed_mix.o

ARRAY_SPLIT_POS_NEG_INC	=						\
		$(INC_DIR)/libalx/stdlib/array_split_pos_neg.h
ARRAY_SPLIT_POS_NEG_SRC	=						\
		$(SRC_DIR)/stdlib/array_split_pos_neg.c

COMPARE_INC	=							\
		$(INC_DIR)/libalx/stdlib/compare.h
COMPARE_SRC	=							\
		$(SRC_DIR)/stdlib/compare.c

LOCAL_MAXIMA_INC	=						\
		$(INC_DIR)/libalx/stdlib/local_maxima.h
LOCAL_MAXIMA_SRC	=						\
		$(SRC_DIR)/stdlib/local_maxima.c

MAXIMUM_INC	=							\
		$(INC_DIR)/libalx/stdlib/maximum.h
MAXIMUM_SRC	=							\
		$(SRC_DIR)/stdlib/maximum.c

MINIMUM_INC	=							\
		$(INC_DIR)/libalx/stdlib/minimum.h
MINIMUM_SRC	=							\
		$(SRC_DIR)/stdlib/minimum.c

POPCNT_INC	=							\
		$(INC_DIR)/libalx/stdlib/popcnt.h
POPCNT_SRC	=							\
		$(SRC_DIR)/stdlib/popcnt.c

POW_INC		=							\
		$(INC_DIR)/libalx/stdlib/pow.h				\
		$(INC_DIR)/libalx/stdint/constants.h
POW_SRC		=							\
		$(SRC_DIR)/stdlib/pow.c

SEARCH_INC	=							\
		$(INC_DIR)/libalx/stdlib/search.h			\
		$(INC_DIR)/libalx/math/arithmetic_mean.h
SEARCH_SRC	=							\
		$(SRC_DIR)/stdlib/search.c

SEED_MIX_INC	=							\
		$(INC_DIR)/libalx/stdlib/seed_mix.h
SEED_MIX_SRC	=							\
		$(SRC_DIR)/stdlib/seed_mix.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


array_split_pos_neg.s: $(ARRAY_SPLIT_POS_NEG_SRC) $(ARRAY_SPLIT_POS_NEG_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
array_split_pos_neg.o: array_split_pos_neg.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

compare.s: $(COMPARE_SRC) $(COMPARE_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
compare.o: compare.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

local_maxima.s: $(LOCAL_MAXIMA_SRC) $(LOCAL_MAXIMA_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
local_maxima.o: local_maxima.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

maximum.s: $(MAXIMUM_SRC) $(MAXIMUM_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
maximum.o: maximum.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

minimum.s: $(MINIMUM_SRC) $(MINIMUM_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
minimum.o: minimum.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

popcnt.s: $(POPCNT_SRC) $(POPCNT_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
popcnt.o: popcnt.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

pow.s: $(POW_SRC) $(POW_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
pow.o: pow.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

search.s: $(SEARCH_SRC) $(SEARCH_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
search.o: search.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
	$(Q)$(AS) $< -o $@

seed_mix.s: $(SEED_MIX_SRC) $(SEED_MIX_INC)
	@echo	"	CC	libalx/tmp/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
seed_mix.o: seed_mix.s
	@echo	"	AS	libalx/tmp/stdlib/$@"
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
