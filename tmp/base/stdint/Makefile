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
		constants.o						\
		types.o

CONSTANTS_INC	=							\
		$(INC_DIR)/libalx/base/stdint/constants.h
CONSTANTS_SRC	=							\
		$(SRC_DIR)/base/stdint/constants.c

TYPES_INC	=							\
		$(INC_DIR)/libalx/base/stdint/types.h
TYPES_SRC	=							\
		$(SRC_DIR)/base/stdint/types.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


constants.s: $(CONSTANTS_SRC) $(CONSTANTS_INC)
	@echo	"	CC	libalx/tmp/base/stdint/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
constants.o: constants.s
	@echo	"	AS	libalx/tmp/base/stdint/$@"
	$(Q)$(AS) $< -o $@

types.s: $(TYPES_SRC) $(TYPES_INC)
	@echo	"	CC	libalx/tmp/base/stdint/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
types.o: types.s
	@echo	"	AS	libalx/tmp/base/stdint/$@"
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
