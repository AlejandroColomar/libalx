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
		constants.o						\
		types.o

CONSTANTS_INC	=							\
		$(INC_DIR)/libalx/base/stdint/constants.h
CONSTANTS_SRC	=							\
		$(SRC_DIR)/base/stdint/constants.c

TYPES_INC	=							\
		$(INC_DIR)/libalx/base/stdint/types.h
TYPES_SRC	=							\
		$(SRC_DIR)/base/stdint/types.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/base/stdint/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/base/stdint/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/base/stdint/$@"
	$(Q)$(AS) $< -o $@


constants.a.s: $(CONSTANTS_SRC) $(CONSTANTS_INC)
constants.so.s: $(CONSTANTS_SRC) $(CONSTANTS_INC)

types.a.s: $(TYPES_SRC) $(TYPES_INC)
types.so.s: $(TYPES_SRC) $(TYPES_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
