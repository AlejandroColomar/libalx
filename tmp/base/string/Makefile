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
		strcat							\
		strchr							\
		strcpy							\
		strstr

OBJ		=							\
		strcat/strscat.o					\
		strchr/strcasechr.o					\
		strchr/strcasechrnul.o					\
		strchr/strncasechr.o					\
		strchr/strncasechrnul.o					\
		strchr/strnchr.o					\
		strchr/strnchrnul.o					\
		strchr/strnrcasechr.o					\
		strchr/strnrcasechrnul.o				\
		strchr/strnrchr.o					\
		strchr/strnrchrnul.o					\
		strchr/strrcasechr.o					\
		strchr/strrcasechrnul.o					\
		strchr/strrchrnul.o					\
		strcpy/strscpy.o					\
		strgrep.o						\
		strstr/strncasestr.o					\
		strstr/strscasestr.o					\
		strstr/strsstr.o

OBJ_TST		=							\
		strgrep-test.o

STRCAT_S_INC	=							\
		$(INC_DIR)/libalx/base/string/strcat/strscat.h
STRCAT_S_SRC	=							\
		$(SRC_DIR)/base/string/strcat/strscat.c

STRCHR_CASE_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strcasechr.h
STRCHR_CASE_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strcasechr.c

STRCHR_CASENUL_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strcasechrnul.h
STRCHR_CASENUL_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strcasechrnul.c

STRCHR_NCASE_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strncasechr.h
STRCHR_NCASE_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strncasechr.c

STRCHR_NCASENUL_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strncasechrnul.h
STRCHR_NCASENUL_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strncasechrnul.c

STRCHR_N_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strnchr.h
STRCHR_N_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strnchr.c

STRCHR_NNUL_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strnchrnul.h
STRCHR_NNUL_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strnchrnul.c

STRCHR_NRCASE_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strnrcasechr.h
STRCHR_NRCASE_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strnrcasechr.c

STRCHR_NRCASENUL_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strnrcasechrnul.h
STRCHR_NRCASENUL_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strnrcasechrnul.c

STRCHR_NR_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strnrchr.h
STRCHR_NR_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strnrchr.c

STRCHR_NRNUL_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strnrchrnul.h
STRCHR_NRNUL_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strnrchrnul.c

STRCHR_RCASE_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strrcasechr.h
STRCHR_RCASE_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strrcasechr.c

STRCHR_RCASENUL_INC	=						\
		$(INC_DIR)/libalx/base/string/strchr/strrcasechrnul.h
STRCHR_RCASENUL_SRC	=						\
		$(SRC_DIR)/base/string/strchr/strrcasechrnul.c

STRCHR_RNUL_INC	=							\
		$(INC_DIR)/libalx/base/string/strchr/strrchrnul.h
STRCHR_RNUL_SRC	=							\
		$(SRC_DIR)/base/string/strchr/strrchrnul.c

STRCPY_S_INC	=							\
		$(INC_DIR)/libalx/base/string/strcpy/strscpy.h
STRCPY_S_SRC	=							\
		$(SRC_DIR)/base/string/strcpy/strscpy.c

STRGREP_INC	=							\
		$(INC_DIR)/libalx/base/string/strgrep.h			\
		$(INC_DIR)/libalx/base/string/strchr/strnchrnul.h	\
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


strcat/strscat.a.s: $(STRCAT_S_SRC) $(STRCAT_S_INC)
strcat/strscat.so.s: $(STRCAT_S_SRC) $(STRCAT_S_INC)

strchr/strcasechr.a.s: $(STRCHR_CASE_SRC) $(STRCHR_CASE_INC)
strchr/strcasechr.so.s: $(STRCHR_CASE_SRC) $(STRCHR_CASE_INC)

strchr/strcasechrnul.a.s: $(STRCHR_CASENUL_SRC) $(STRCHR_CASENUL_INC)
strchr/strcasechrnul.so.s: $(STRCHR_CASENUL_SRC) $(STRCHR_CASENUL_INC)

strchr/strncasechr.a.s: $(STRCHR_NCASE_SRC) $(STRCHR_NCASE_INC)
strchr/strncasechr.so.s: $(STRCHR_NCASE_SRC) $(STRCHR_NCASE_INC)

strchr/strncasechrnul.a.s: $(STRCHR_NCASENUL_SRC) $(STRCHR_NCASENUL_INC)
strchr/strncasechrnul.so.s: $(STRCHR_NCASENUL_SRC) $(STRCHR_NCASENUL_INC)

strchr/strnchr.a.s: $(STRCHR_N_SRC) $(STRCHR_N_INC)
strchr/strnchr.so.s: $(STRCHR_N_SRC) $(STRCHR_N_INC)

strchr/strnchrnul.a.s: $(STRCHR_NNUL_SRC) $(STRCHR_NNUL_INC)
strchr/strnchrnul.so.s: $(STRCHR_NNUL_SRC) $(STRCHR_NNUL_INC)

strchr/strnrcasechr.a.s: $(STRCHR_NRCASE_SRC) $(STRCHR_NRCASE_INC)
strchr/strnrcasechr.so.s: $(STRCHR_NRCASE_SRC) $(STRCHR_NRCASE_INC)

strchr/strnrcasechrnul.a.s: $(STRCHR_NRCASENUL_SRC) $(STRCHR_NRCASENUL_INC)
strchr/strnrcasechrnul.so.s: $(STRCHR_NRCASENUL_SRC) $(STRCHR_NRCASENUL_INC)

strchr/strnrchr.a.s: $(STRCHR_NR_SRC) $(STRCHR_NR_INC)
strchr/strnrchr.so.s: $(STRCHR_NR_SRC) $(STRCHR_NR_INC)

strchr/strnrchrnul.a.s: $(STRCHR_NRNUL_SRC) $(STRCHR_NRNUL_INC)
strchr/strnrchrnul.so.s: $(STRCHR_NRNUL_SRC) $(STRCHR_NRNUL_INC)

strchr/strrcasechr.a.s: $(STRCHR_RCASE_SRC) $(STRCHR_RCASE_INC)
strchr/strrcasechr.so.s: $(STRCHR_RCASE_SRC) $(STRCHR_RCASE_INC)

strchr/strrcasechrnul.a.s: $(STRCHR_RCASENUL_SRC) $(STRCHR_RCASENUL_INC)
strchr/strrcasechrnul.so.s: $(STRCHR_RCASENUL_SRC) $(STRCHR_RCASENUL_INC)

strchr/strrchrnul.a.s: $(STRCHR_RNUL_SRC) $(STRCHR_RNUL_INC)
strchr/strrchrnul.so.s: $(STRCHR_RNUL_SRC) $(STRCHR_RNUL_INC)

strcpy/strscpy.a.s: $(STRCPY_S_SRC) $(STRCPY_S_INC)
strcpy/strscpy.so.s: $(STRCPY_S_SRC) $(STRCPY_S_INC)

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
