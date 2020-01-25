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
		ucat.o

UCAT_INC	=							\
		$(INC_DIR)/libalx/base/compiler/size.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fopen.h		\
		$(INC_DIR)/libalx/extra/curl/fcurl/fread.h		\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(INC_DIR)/libalx/nix/ucat/ucat.h
UCAT_SRC	=							\
		$(SRC_DIR)/nix/ucat/ucat.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/nix/ucat/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/nix/ucat/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/nix/ucat/$@"
	$(Q)$(AS) $< -o $@


ucat.a.s: $(UCAT_SRC) $(UCAT_INC)
ucat.so.s: $(UCAT_SRC) $(UCAT_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
