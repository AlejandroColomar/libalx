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

DIRS		=							\
		printf

OBJ		=							\
		get.o							\
		printf/b.o						\
		printf/sbprintf.o					\
		printf/swnprintf.o					\
		printf/swnprintf.cpp.o					\
		sscan.o							\
		wait.o

GET_INC		=							\
		$(INC_DIR)/libalx/base/stdio/get.h			\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/base/stdio/common.h			\
		$(INC_DIR)/libalx/base/stdio/sscan.h
GET_SRC		=							\
		$(SRC_DIR)/base/stdio/get.c

PRINTF_B_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf/b.h
PRINTF_B_SRC	=							\
		$(SRC_DIR)/base/stdio/printf/b.c

PRINTF_SBPRINTF_INC	=						\
		$(INC_DIR)/libalx/base/stdio/printf/sbprintf.h		\
		$(INC_DIR)/libalx/base/assert/assert.h			\
		$(INC_DIR)/libalx/base/stdio/printf/swnprintf.h
PRINTF_SBPRINTF_SRC	=						\
		$(SRC_DIR)/base/stdio/printf/sbprintf.c

PRINTF_SWNPRINTF_INC	=						\
		$(INC_DIR)/libalx/base/stdio/printf/swnprintf.h
PRINTF_SWNPRINTF_SRC	=						\
		$(SRC_DIR)/base/stdio/printf/swnprintf.c

PRINTF_SWNPRINTF_CXX_INC	=					\
		$(INC_DIR)/libalx/base/stdio/printf/swnprintf.hpp
PRINTF_SWNPRINTF_CXX_SRC	=					\
		$(SRC_DIR)/base/stdio/printf/swnprintf.cpp

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
all: $(DIRS) $(OBJ)


printf:
	@echo	"	MKDIR	libalx/tmp/base/stdio/$@"
	$(Q)mkdir -p		$@/


get.s: $(GET_SRC) $(GET_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
get.o: get.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

printf/b.s: $(PRINTF_B_SRC) $(PRINTF_B_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
printf/b.o: printf/b.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

printf/sbprintf.s: $(PRINTF_SBPRINTF_SRC) $(PRINTF_SBPRINTF_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
printf/sbprintf.o: printf/sbprintf.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

printf/swnprintf.s: $(PRINTF_SWNPRINTF_SRC) $(PRINTF_SWNPRINTF_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
printf/swnprintf.o: printf/swnprintf.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

printf/swnprintf.cpp.s: $(PRINTF_SWNPRINTF_CXX_SRC) $(PRINTF_SWNPRINTF_CXX_INC)
	@echo	"	CXX	libalx/tmp/base/stdio/$@"
	$(Q)$(CXX) $(CXXFLAGS) -S $< -o $@
printf/swnprintf.cpp.o: printf/swnprintf.cpp.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

sscan.s: $(SSCAN_SRC) $(SSCAN_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
sscan.o: sscan.s
	@echo	"	AS	libalx/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@

wait.s: $(WAIT_SRC) $(WAIT_INC)
	@echo	"	CC	libalx/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
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
