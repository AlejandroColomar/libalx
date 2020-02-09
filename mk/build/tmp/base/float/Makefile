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
		constant.o						\
		printf.o						\
		scanf.o

CONSTANT_INC	=							\
		$(INC_DIR)/libalx/base/float/constant.h
CONSTANT_SRC	=							\
		$(SRC_DIR)/base/float/constant.c

PRINTF_INC	=							\
		$(INC_DIR)/libalx/base/float/printf.h
PRINTF_SRC	=							\
		$(SRC_DIR)/base/float/printf.c

SCANF_INC	=							\
		$(INC_DIR)/libalx/base/float/scanf.h
SCANF_SRC	=							\
		$(SRC_DIR)/base/float/scanf.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/base/float/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/base/float/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/base/float/$@"
	$(Q)$(AS) $< -o $@


constant.a.s: $(CONSTANT_SRC) $(CONSTANT_INC)
constant.so.s: $(CONSTANT_SRC) $(CONSTANT_INC)

printf.a.s: $(PRINTF_SRC) $(PRINTF_INC)
printf.so.s: $(PRINTF_SRC) $(PRINTF_INC)

scanf.a.s: $(SCANF_SRC) $(SCANF_INC)
scanf.so.s: $(SCANF_SRC) $(SCANF_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
