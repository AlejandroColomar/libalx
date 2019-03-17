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
		compare.o						\
		search.o						\
		local_maxima.o						\
		matrix_addition.o					\
		matrix_subtraction.o					\
		maximum.o						\
		popcnt.o						\
		pow.o							\
		seed_mix.o

COMPARE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/compare.h
COMPARE_SRC	=							\
		$(SRC_DIR)/base/stdlib/compare.c

SEARCH_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/search.h
SEARCH_SRC	=							\
		$(SRC_DIR)/base/stdlib/search.c

LOCAL_MAXIMA_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/local_maxima.h
LOCAL_MAXIMA_SRC	=						\
		$(SRC_DIR)/base/stdlib/local_maxima.c

MATRIX_ADDITION_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/matrix_addition.h
MATRIX_ADDITION_SRC	=						\
		$(SRC_DIR)/base/stdlib/matrix_addition.c

MATRIX_SUBTRACTION_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/matrix_subtraction.h
MATRIX_SUBTRACTION_SRC	=						\
		$(SRC_DIR)/base/stdlib/matrix_subtraction.c

MAXIMUM_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/maximum.h
MAXIMUM_SRC	=							\
		$(SRC_DIR)/base/stdlib/maximum.c

POPCNT_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/popcnt.h
POPCNT_SRC	=							\
		$(SRC_DIR)/base/stdlib/popcnt.c

POW_INC		=							\
		$(INC_DIR)/libalx/base/stdlib/pow.h			\
		$(INC_DIR)/libalx/base/stdint/constants.h
POW_SRC		=							\
		$(SRC_DIR)/base/stdlib/pow.c

SEED_MIX_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/seed_mix.h
SEED_MIX_SRC	=							\
		$(SRC_DIR)/base/stdlib/seed_mix.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


compare.s: $(COMPARE_SRC) $(COMPARE_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
compare.o: compare.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

search.s: $(SEARCH_SRC) $(SEARCH_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
search.o: search.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

local_maxima.s: $(LOCAL_MAXIMA_SRC) $(LOCAL_MAXIMA_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
local_maxima.o: local_maxima.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

matrix_addition.s: $(MATRIX_ADDITION_SRC) $(MATRIX_ADDITION_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_addition.o: matrix_addition.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

matrix_subtraction.s: $(MATRIX_SUBTRACTION_SRC) $(MATRIX_SUBTRACTION_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
matrix_subtraction.o: matrix_subtraction.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

maximum.s: $(MAXIMUM_SRC) $(MAXIMUM_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
maximum.o: maximum.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

popcnt.s: $(POPCNT_SRC) $(POPCNT_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
popcnt.o: popcnt.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

pow.s: $(POW_SRC) $(POW_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
pow.o: pow.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

seed_mix.s: $(SEED_MIX_SRC) $(SEED_MIX_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
seed_mix.o: seed_mix.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
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
