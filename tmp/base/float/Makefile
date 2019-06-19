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
		constant.o						\
		printf.o						\
		scanf.o

CONSTANT_INC	=							\
		$(INC_DIR)/libalx/base/float/constant.h
CONSTANT_SRC	=							\
		$(SRC_DIR)/base/float/constant.c

PRINTF_INC	=							\
		$(INC_DIR)/libalx/base/float/printf.h
PRINTF_SRC	=							\
		$(SRC_DIR)/base/float/printf.c

SCANF_INC	=							\
		$(INC_DIR)/libalx/base/float/scanf.h
SCANF_SRC	=							\
		$(SRC_DIR)/base/float/scanf.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


constant.s: $(CONSTANT_SRC) $(CONSTANT_INC)
	@echo	"	CC	libalx/tmp/base/float/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
constant.o: constant.s
	@echo	"	AS	libalx/tmp/base/float/$@"
	$(Q)$(AS) $< -o $@

printf.s: $(PRINTF_SRC) $(PRINTF_INC)
	@echo	"	CC	libalx/tmp/base/float/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
printf.o: printf.s
	@echo	"	AS	libalx/tmp/base/float/$@"
	$(Q)$(AS) $< -o $@

scanf.s: $(SCANF_SRC) $(SCANF_INC)
	@echo	"	CC	libalx/tmp/base/float/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
scanf.o: scanf.s
	@echo	"	AS	libalx/tmp/base/float/$@"
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
