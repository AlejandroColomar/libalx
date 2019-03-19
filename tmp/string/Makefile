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
		strchr.o						\
		strgrep.o

STRCHR_INC	=							\
		$(INC_DIR)/libalx/string/strchr.h
STRCHR_SRC	=							\
		$(SRC_DIR)/string/strchr.c

STRGREP_INC	=							\
		$(INC_DIR)/libalx/string/strgrep.h			\
		$(INC_DIR)/libalx/string/strchr.h
STRGREP_SRC	=							\
		$(SRC_DIR)/string/strgrep.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


strchr.s: $(STRCHR_SRC) $(STRCHR_INC)
	@echo	"	CC	libalx/tmp/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strchr.o: strchr.s
	@echo	"	AS	libalx/tmp/string/$@"
	$(Q)$(AS) $< -o $@

strgrep.s: $(STRGREP_SRC) $(STRGREP_INC)
	@echo	"	CC	libalx/tmp/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strgrep.o: strgrep.s
	@echo	"	AS	libalx/tmp/string/$@"
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
