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
		zbar.o

ZBAR_INC	=							\
		$(INC_DIR)/libalx/base/stdio/printf/snprintfs.h		\
		$(INC_DIR)/libalx/extra/zbar/zbar.h
ZBAR_SRC	=							\
		$(SRC_DIR)/extra/zbar/zbar.c

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags zbar`
CFLAGS_SO	+= `pkg-config --cflags zbar`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/extra/zbar/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/extra/zbar/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/zbar/$@"
	$(Q)$(AS) $< -o $@


zbar.a.s: $(ZBAR_SRC) $(ZBAR_INC)
zbar.so.s: $(ZBAR_SRC) $(ZBAR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
