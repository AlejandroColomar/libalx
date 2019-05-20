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
		printf.o						\
		sscan.o							\
		wait.o

GET_INC		=							\
		$(INC_DIR)/libalx/base/stdio/get.h			\
		$(INC_DIR)/libalx/base/stddef/size.h			\
		$(INC_DIR)/libalx/base/stdio/common.h			\
		$(INC_DIR)/libalx/base/stdio/sscan.h
GET_SRC		=							\
		$(SRC_DIR)/base/stdio/get.c

PRINTF_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf.h
PRINTF_SRC	=							\
		$(SRC_DIR)/base/stdio/printf.c

SSCAN_INC	=							\
		$(INC_DIR)/libalx/base/stdio/sscan.h			\
		$(INC_DIR)/libalx/base/stdio/common.h			\
		$(INC_DIR)/libalx/base/string/strchr.h
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

printf.s: $(PRINTF_SRC) $(PRINTF_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
printf.o: printf.s
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
