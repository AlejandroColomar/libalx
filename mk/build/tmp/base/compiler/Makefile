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
		size.o							\
		type.o							\
		unused.o

SIZE_INC	=							\
		$(INC_DIR)/libalx/base/compiler/size.h
SIZE_SRC	=							\
		$(SRC_DIR)/base/compiler/size.c

TYPE_INC	=							\
		$(INC_DIR)/libalx/base/compiler/type.h
TYPE_SRC	=							\
		$(SRC_DIR)/base/compiler/type.c

UNUSED_INC	=							\
		$(INC_DIR)/libalx/base/compiler/unused.h
UNUSED_SRC	=							\
		$(SRC_DIR)/base/compiler/unused.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/base/compiler/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/base/compiler/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/base/compiler/$@"
	$(Q)$(AS) $< -o $@


size.a.s: $(SIZE_SRC) $(SIZE_INC)
size.so.s: $(SIZE_SRC) $(SIZE_INC)

type.a.s: $(TYPE_SRC) $(TYPE_INC)
type.so.s: $(TYPE_SRC) $(TYPE_INC)

unused.a.s: $(UNUSED_SRC) $(UNUSED_INC)
unused.so.s: $(UNUSED_SRC) $(UNUSED_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
