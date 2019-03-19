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
		alx_ncur.o

NCUR_INC	=							\
		$(INC_DIR)/libalx/curses/alx_ncur.h			\
		$(INC_DIR)/libalx/io/alx_input.h
NCUR_SRC	=							\
		$(SRC_DIR)/curses/alx_ncur.c

################################################################################
# CFLAGS
CFLAGS	+= `pkg-config --cflags ncurses`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


alx_ncur.s: $(NCUR_SRC) $(NCUR_INC)
	@echo	"	CC	libalx/tmp/curses/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
alx_ncur.o: alx_ncur.s
	@echo	"	AS	libalx/tmp/curses/$@"
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
