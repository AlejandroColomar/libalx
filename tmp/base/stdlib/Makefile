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
		find.o							\
		local_maxima.o						\
		maximum.o						\
		popcnt.o						\
		seed_mix.o

COMPARE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/compare.h
COMPARE_SRC	=							\
		$(SRC_DIR)/base/stdlib/compare.c

FIND_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/find.h
FIND_SRC	=							\
		$(SRC_DIR)/base/stdlib/find.c

LOCAL_MAXIMA_INC	=						\
		$(INC_DIR)/libalx/base/stdlib/local_maxima.h
LOCAL_MAXIMA_SRC	=						\
		$(SRC_DIR)/base/stdlib/local_maxima.c

MAXIMUM_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/maximum.h
MAXIMUM_SRC	=							\
		$(SRC_DIR)/base/stdlib/maximum.c

POPCNT_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/popcnt.h
POPCNT_SRC	=							\
		$(SRC_DIR)/base/stdlib/popcnt.c

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

find.s: $(FIND_SRC) $(FIND_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
find.o: find.s
	@echo	"	AS	libalx/tmp/base/stdlib/$@"
	$(Q)$(AS) $< -o $@

local_maxima.s: $(LOCAL_MAXIMA_SRC) $(LOCAL_MAXIMA_INC)
	@echo	"	CC	libalx/tmp/base/stdlib/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
local_maxima.o: local_maxima.s
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
