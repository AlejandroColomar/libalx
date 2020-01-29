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
		basename.o						\
		dirname.o

BASENAME_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf/sbprintf.h		\
		$(INC_DIR)/libalx/base/stdio/printf/snprintfs.h		\
		$(INC_DIR)/libalx/base/libgen/basename.h
BASENAME_SRC	=							\
		$(SRC_DIR)/base/libgen/basename.c

DIRNAME_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf/sbprintf.h		\
		$(INC_DIR)/libalx/base/stdio/printf/snprintfs.h		\
		$(INC_DIR)/libalx/base/libgen/dirname.h
DIRNAME_SRC	=							\
		$(SRC_DIR)/base/libgen/dirname.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/base/libgen/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/base/libgen/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/base/libgen/$@"
	$(Q)$(AS) $< -o $@


basename.a.s: $(BASENAME_SRC) $(BASENAME_INC)
basename.so.s: $(BASENAME_SRC) $(BASENAME_INC)

dirname.a.s: $(DIRNAME_SRC) $(DIRNAME_INC)
dirname.so.s: $(DIRNAME_SRC) $(DIRNAME_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
