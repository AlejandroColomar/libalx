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
		fgets.o							\
		freads.o						\
		get.o							\
		printf/b.o						\
		printf/sbprintf.o					\
		printf/snprintfs.o					\
		seekc.o							\
		sscan.o

FGETS_INC	=							\
		$(INC_DIR)/libalx/base/stdio/fgets.h
FGETS_SRC	=							\
		$(SRC_DIR)/base/stdio/fgets.c

FREADS_INC	=							\
		$(INC_DIR)/libalx/base/assert/assert.h			\
		$(INC_DIR)/libalx/base/stdio/freads.h
FREADS_SRC	=							\
		$(SRC_DIR)/base/stdio/freads.c

GET_INC		=							\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/base/errno/error.h			\
		$(INC_DIR)/libalx/base/stdio/sscan.h			\
		$(INC_DIR)/libalx/base/stdio/get.h
GET_SRC		=							\
		$(SRC_DIR)/base/stdio/get.c

PRINTF_B_INC	=							\
		$(INC_DIR)/libalx/base/compiler/unused.h		\
		$(INC_DIR)/libalx/base/stdio/printf/b.h
PRINTF_B_SRC	=							\
		$(SRC_DIR)/base/stdio/printf/b.c

PRINTF_SBPRINTF_INC	=						\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/base/stdio/printf/snprintfs.h		\
		$(INC_DIR)/libalx/base/stdio/printf/sbprintf.h
PRINTF_SBPRINTF_SRC	=						\
		$(SRC_DIR)/base/stdio/printf/sbprintf.c

PRINTF_SNPRINTFS_INC	=						\
		$(INC_DIR)/libalx/base/stdio/printf/snprintfs.h
PRINTF_SNPRINTFS_SRC	=						\
		$(SRC_DIR)/base/stdio/printf/snprintfs.c

SEEKC_INC	=							\
		$(INC_DIR)/libalx/base/stdio/seekc.h
SEEKC_SRC	=							\
		$(SRC_DIR)/base/stdio/seekc.c

SSCAN_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf/sbprintf.h		\
		$(INC_DIR)/libalx/base/string/strchr/strcasechr.h	\
		$(INC_DIR)/libalx/base/stdio/sscan.h
SSCAN_SRC	=							\
		$(SRC_DIR)/base/stdio/sscan.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(DIRS) $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


printf:
	@echo	"	MKDIR	build/tmp/base/stdio/$@"
	$(Q)mkdir -p		$@/


%.a.s:
	@echo	"	CC	build/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/base/stdio/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/base/stdio/$@"
	$(Q)$(AS) $< -o $@


fgets.a.s: $(FGETS_SRC) $(FGETS_INC)
fgets.so.s: $(FGETS_SRC) $(FGETS_INC)

freads.a.s: $(FREADS_SRC) $(FREADS_INC)
freads.so.s: $(FREADS_SRC) $(FREADS_INC)

get.a.s: $(GET_SRC) $(GET_INC)
get.so.s: $(GET_SRC) $(GET_INC)

printf/b.a.s: $(PRINTF_B_SRC) $(PRINTF_B_INC)
printf/b.so.s: $(PRINTF_B_SRC) $(PRINTF_B_INC)

printf/sbprintf.a.s: $(PRINTF_SBPRINTF_SRC) $(PRINTF_SBPRINTF_INC)
printf/sbprintf.so.s: $(PRINTF_SBPRINTF_SRC) $(PRINTF_SBPRINTF_INC)

printf/snprintfs.a.s: $(PRINTF_SNPRINTFS_SRC) $(PRINTF_SNPRINTFS_INC)
printf/snprintfs.so.s: $(PRINTF_SNPRINTFS_SRC) $(PRINTF_SNPRINTFS_INC)

seekc.a.s: $(SEEKC_SRC) $(SEEKC_INC)
seekc.so.s: $(SEEKC_SRC) $(SEEKC_INC)

sscan.a.s: $(SSCAN_SRC) $(SSCAN_INC)
sscan.so.s: $(SSCAN_SRC) $(SSCAN_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
