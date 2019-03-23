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
		size.o

SIZE_INC	=							\
		$(INC_DIR)/libalx/stddef/size.h
SIZE_SRC	=							\
		$(SRC_DIR)/stddef/size.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


size.s: $(SIZE_SRC) $(SIZE_INC)
	@echo	"	CC	libalx/tmp/stdint/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
size.o: size.s
	@echo	"	AS	libalx/tmp/stdint/$@"
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
