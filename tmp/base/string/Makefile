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
		memcpy.o						\
		memcpy-test.o						\
		strchr.o						\
		strgrep.o						\
		strgrep-test.o						\
		strstr.o

MEMCPY_INC	=							\
		$(INC_DIR)/libalx/base/string/memcpy.h
MEMCPY_SRC	=							\
		$(SRC_DIR)/base/string/memcpy.c
TST_MEMCPY_INC	=							\
		$(INC_DIR)/libalx/base/string/memcpy.h			\
		$(INC_DIR)/libalx/../../test/test.h
TST_MEMCPY_SRC	=							\
		$(SRC_DIR)/base/string/memcpy-test.c			\
		$(SRC_DIR)/base/string/memcpy.c

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
all: $(OBJ)


memcpy.s: $(MEMCPY_SRC) $(MEMCPY_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
memcpy.o: memcpy.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@
memcpy-test.s: $(TST_MEMCPY_SRC) $(TST_MEMCPY_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
memcpy-test.o: memcpy-test.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@

strchr.s: $(STRCHR_SRC) $(STRCHR_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strchr.o: strchr.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@

strgrep.s: $(STRGREP_SRC) $(STRGREP_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strgrep.o: strgrep.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@
strgrep-test.s: $(TST_STRGREP_SRC) $(TST_STRGREP_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strgrep-test.o: strgrep-test.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@

strstr.s: $(STRSTR_SRC) $(STRSTR_INC)
	@echo	"	CC	libalx/tmp/base/string/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
strstr.o: strstr.s
	@echo	"	AS	libalx/tmp/base/string/$@"
	$(Q)$(AS) $< -o $@


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
