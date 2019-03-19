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
		int128.o

CONSTANTS_INC	=							\
		$(INC_DIR)/libalx/stdint/constants.h
CONSTANTS_SRC	=							\
		$(SRC_DIR)/stdint/constants.c

INT128_INC	=							\
		$(INC_DIR)/libalx/stdint/int128.h
INT128_SRC	=							\
		$(SRC_DIR)/stdint/int128.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


constants.s: $(CONSTANTS_SRC) $(CONSTANTS_INC)
	@echo	"	CC	libalx/tmp/stdint/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
constants.o: constants.s
	@echo	"	AS	libalx/tmp/stdint/$@"
	$(Q)$(AS) $< -o $@

int128.s: $(INT128_SRC) $(INT128_INC)
	@echo	"	CC	libalx/tmp/stdint/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
int128.o: int128.s
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
