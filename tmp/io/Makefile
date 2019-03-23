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
		sprint_file.o						\
		alx_input.o

SPRINT_FILE_INC	=							\
		$(INC_DIR)/libalx/io/sprint_file.h
SPRINT_FILE_SRC	=							\
		$(SRC_DIR)/io/sprint_file.c

INPUT_INC	=							\
		$(INC_DIR)/libalx/io/alx_input.h
INPUT_SRC	=							\
		$(SRC_DIR)/io/alx_input.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


sprint_file.s: $(SPRINT_FILE_SRC) $(SPRINT_FILE_INC)
	@echo	"	CC	libalx/tmp/io/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
sprint_file.o: sprint_file.s
	@echo	"	AS	libalx/tmp/io/$@"
	$(Q)$(AS) $< -o $@

alx_input.s: $(INPUT_SRC) $(INPUT_INC)
	@echo	"	CC	libalx/tmp/io/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
alx_input.o: alx_input.s
	@echo	"	AS	libalx/tmp/io/$@"
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
