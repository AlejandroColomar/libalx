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
		strchr.o						\
		strgrep.o						\
		strstr.o

OBJ_TST		=							\
		strgrep-test.o

STRCHR_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr.h
STRCHR_SRC	=							\
		$(SRC_DIR)/base/string/strchr.c

STRGREP_INC	=							\
		$(INC_DIR)/libalx/base/string/strgrep.h			\
		$(INC_DIR)/libalx/base/string/strchr.h			\
		$(INC_DIR)/libalx/base/string/strstr.h
STRGREP_SRC	=							\
		$(SRC_DIR)/base/string/strgrep.c
TST_STRGREP_INC	=							\
		$(INC_DIR)/libalx/base/string/strgrep.h			\
		$(INC_DIR)/libalx/../../test/test.h
TST_STRGREP_SRC	=							\
		$(SRC_DIR)/base/string/strgrep-test.c			\
		$(SRC_DIR)/base/string/strgrep.c

STRSTR_INC	=							\
		$(INC_DIR)/libalx/base/string/strstr.h			\
		$(INC_DIR)/libalx/base/stdint/types.h
STRSTR_SRC	=							\
		$(SRC_DIR)/base/string/strstr.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o))) $(OBJ_TST)


%.a.s:
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@
%-test.s:
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@


strchr.a.s: $(STRCHR_SRC) $(STRCHR_INC)
strchr.so.s: $(STRCHR_SRC) $(STRCHR_INC)

strgrep.a.s: $(STRGREP_SRC) $(STRGREP_INC)
strgrep.so.s: $(STRGREP_SRC) $(STRGREP_INC)
strgrep-test.s: $(TST_STRGREP_SRC) $(TST_STRGREP_INC)

strstr.a.s: $(STRSTR_SRC) $(STRSTR_INC)
strstr.so.s: $(STRSTR_SRC) $(STRSTR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
