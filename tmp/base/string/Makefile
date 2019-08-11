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
		strchr							\
		strstr

OBJ		=							\
		strchr/strnchr.o					\
		strchr/strnrchr.o					\
		strgrep.o						\
		strstr/strncasestr.o					\
		strstr/strscasestr.o					\
		strstr/strsstr.o

OBJ_TST		=							\
		strgrep-test.o

STRCHR_N_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strnchr.h
STRCHR_N_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strnchr.c

STRCHR_NR_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strnrchr.h
STRCHR_NR_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strnrchr.c

STRGREP_INC	=							\
		$(INC_DIR)/libalx/base/string/strgrep.h			\
		$(INC_DIR)/libalx/base/string/strchr.h			\
		$(INC_DIR)/libalx/base/string/strstr/strncasestr.h	\
		$(INC_DIR)/libalx/base/string/strstr/strscasestr.h	\
		$(INC_DIR)/libalx/base/string/strstr/strsstr.h
STRGREP_SRC	=							\
		$(SRC_DIR)/base/string/strgrep.c
TST_STRGREP_INC	=							\
		$(INC_DIR)/libalx/base/string/strgrep.h			\
		$(INC_DIR)/libalx/../../test/test.h
TST_STRGREP_SRC	=							\
		$(SRC_DIR)/base/string/strgrep-test.c			\
		$(SRC_DIR)/base/string/strgrep.c

STRSTR_NCASE_INC	=						\
		$(INC_DIR)/libalx/base/string/strstr/strncasestr.h
STRSTR_NCASE_SRC	=						\
		$(SRC_DIR)/base/string/strstr/strncasestr.c

STRSTR_SCASE_INC	=						\
		$(INC_DIR)/libalx/base/string/strstr/strscasestr.h
STRSTR_SCASE_SRC	=						\
		$(SRC_DIR)/base/string/strstr/strscasestr.c

STRSTR_S_INC	=							\
		$(INC_DIR)/libalx/base/string/strstr/strsstr.h
STRSTR_S_SRC	=							\
		$(SRC_DIR)/base/string/strstr/strsstr.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(DIRS) $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o))) $(OBJ_TST)


$(DIRS):
	@echo	"	MKDIR	libalx/tmp/base/string/$@"
	$(Q)mkdir -p		$@/


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


strchr/strnchr.a.s: $(STRCHR_N_SRC) $(STRCHR_N_INC)
strchr/strnchr.so.s: $(STRCHR_N_SRC) $(STRCHR_N_INC)

strchr/strnrchr.a.s: $(STRCHR_NR_SRC) $(STRCHR_NR_INC)
strchr/strnrchr.so.s: $(STRCHR_NR_SRC) $(STRCHR_NR_INC)

strgrep.a.s: $(STRGREP_SRC) $(STRGREP_INC)
strgrep.so.s: $(STRGREP_SRC) $(STRGREP_INC)
strgrep-test.s: $(TST_STRGREP_SRC) $(TST_STRGREP_INC)

strstr/strncasestr.a.s: $(STRSTR_NCASE_SRC) $(STRSTR_NCASE_INC)
strstr/strncasestr.so.s: $(STRSTR_NCASE_SRC) $(STRSTR_NCASE_INC)

strstr/strscasestr.a.s: $(STRSTR_SCASE_SRC) $(STRSTR_SCASE_INC)
strstr/strscasestr.so.s: $(STRSTR_SCASE_SRC) $(STRSTR_SCASE_INC)

strstr/strsstr.a.s: $(STRSTR_S_SRC) $(STRSTR_S_INC)
strstr/strsstr.so.s: $(STRSTR_S_SRC) $(STRSTR_S_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
