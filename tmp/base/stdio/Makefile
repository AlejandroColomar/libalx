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
		sscan.o							\
		wait.o

GET_INC		=							\
		$(INC_DIR)/libalx/base/stdio/get.h			\
		$(INC_DIR)/libalx/base/stdio/common.h			\
		$(INC_DIR)/libalx/base/stdio/sscan.h
GET_SRC		=							\
		$(SRC_DIR)/base/stdio/get.c

SPRINT_FILE_INC	=							\
		$(INC_DIR)/libalx/base/stdio/sprint_file.h		\
		$(INC_DIR)/libalx/base/stdlib/minimum.h
SPRINT_FILE_SRC	=							\
		$(SRC_DIR)/base/stdio/sprint_file.c

SSCAN_INC	=							\
		$(INC_DIR)/libalx/base/stdio/sscan.h			\
		$(INC_DIR)/libalx/base/stdio/common.h
SSCAN_SRC	=							\
		$(SRC_DIR)/base/stdio/sscan.c

WAIT_INC	=							\
		$(INC_DIR)/libalx/base/stdio/wait.h
WAIT_SRC	=							\
		$(SRC_DIR)/base/stdio/wait.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


get.s: $(GET_SRC) $(GET_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
get.o: get.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

sprint_file.s: $(SPRINT_FILE_SRC) $(SPRINT_FILE_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
sprint_file.o: sprint_file.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

sscan.s: $(SSCAN_SRC) $(SSCAN_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
sscan.o: sscan.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

wait.s: $(WAIT_SRC) $(WAIT_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
wait.o: wait.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
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
