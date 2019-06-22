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
		perror.o

PERROR_INC	=							\
		$(INC_DIR)/libalx/base/errno/perror.h
PERROR_SRC	=							\
		$(SRC_DIR)/base/errno/perror.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


perror.s: $(PERROR_SRC) $(PERROR_INC)
	@echo	"	CC	libalx/tmp/base/errno/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
perror.o: perror.s
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
