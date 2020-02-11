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
		solver_lut.o

SOLVERLUT_INC	=							\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/base/stdint/types.h			\
		$(INC_DIR)/libalx/base/stdlib/compare.h			\
		$(INC_DIR)/libalx/base/stdlib/popcnt.h			\
		$(INC_DIR)/libalx/alx/npcomplete/solver_lut.h
SOLVERLUT_SRC	=							\
		$(SRC_DIR)/alx/npcomplete/solver_lut.c

################################################################################
# cflags
CFLAGS_A	+= -fopenmp
CFLAGS_SO	+= -fopenmp

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/alx/npcomplete/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/alx/npcomplete/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/alx/npcomplete/$@"
	$(Q)$(AS) $< -o $@


solver_lut.a.s: $(SOLVERLUT_SRC) $(SOLVERLUT_INC)
solver_lut.so.s: $(SOLVERLUT_SRC) $(SOLVERLUT_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
