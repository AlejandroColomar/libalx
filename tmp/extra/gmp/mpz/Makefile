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
		set.o							\
		init_set.o

INITSET_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/init_set.h
INITSET_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/init_set.c

SET_INC		=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/set.h
SET_SRC		=							\
		$(SRC_DIR)/extra/gmp/mpz/set.c

################################################################################
# cflags
#CFLAGS_A	+=
#CFLAGS_SO	+=

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(AS) $< -o $@


init_set.a.s: $(INITSET_SRC) $(INITSET_INC)
init_set.so.s: $(INITSET_SRC) $(INITSET_INC)

set.a.s: $(SET_SRC) $(SET_INC)
set.so.s: $(SET_SRC) $(SET_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
