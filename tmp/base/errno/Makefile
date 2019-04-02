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
		errno_str.o

ERRNO_STR_INC	=							\
		$(INC_DIR)/libalx/base/errno/errno_str.h
ERRNO_STR_SRC	=							\
		$(SRC_DIR)/base/errno/errno_str.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


errno_str.s: $(ERRNO_STR_SRC) $(ERRNO_STR_INC)
	@echo	"	CC	libalx/tmp/base/errno/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
errno_str.o: errno_str.s
	@echo	"	AS	libalx/tmp/base/errno/$@"
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
