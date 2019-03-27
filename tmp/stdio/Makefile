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
		get.o							\
		sprint_file.o						\
		sscan.o

GET_INC		=							\
		$(INC_DIR)/libalx/stdio/get.h				\
		$(INC_DIR)/libalx/stdio/common.h			\
		$(INC_DIR)/libalx/stdio/sscan.h
GET_SRC		=							\
		$(SRC_DIR)/stdio/get.c

SPRINT_FILE_INC	=							\
		$(INC_DIR)/libalx/stdio/sprint_file.h			\
		$(INC_DIR)/libalx/stdlib/minimum.h
SPRINT_FILE_SRC	=							\
		$(SRC_DIR)/stdio/sprint_file.c

SSCAN_INC	=							\
		$(INC_DIR)/libalx/stdio/sscan.h				\
		$(INC_DIR)/libalx/stdio/common.h
SSCAN_SRC	=							\
		$(SRC_DIR)/stdio/sscan.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


get.s: $(GET_SRC) $(GET_INC)
	@echo	"	CC	libalx/tmp/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
get.o: get.s
	@echo	"	AS	libalx/tmp/stdio/$@"
	$(Q)$(AS) $< -o $@

sprint_file.s: $(SPRINT_FILE_SRC) $(SPRINT_FILE_INC)
	@echo	"	CC	libalx/tmp/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
sprint_file.o: sprint_file.s
	@echo	"	AS	libalx/tmp/stdio/$@"
	$(Q)$(AS) $< -o $@

sscan.s: $(SSCAN_SRC) $(SSCAN_INC)
	@echo	"	CC	libalx/tmp/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
sscan.o: sscan.s
	@echo	"	AS	libalx/tmp/stdio/$@"
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
