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
		temp.o

TEMP_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/units/temp.h
TEMP_SRC	=							\
		$(SRC_DIR)/extra/gsl/units/temp.c

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags gsl`
CFLAGS_SO	+= `pkg-config --cflags gsl`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/gsl/units/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/gsl/units/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/gsl/units/$@"
	$(Q)$(AS) $< -o $@


temp.a.s: $(TEMP_SRC) $(TEMP_INC)
temp.so.s: $(TEMP_SRC) $(TEMP_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
