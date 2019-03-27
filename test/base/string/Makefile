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

BIN		=							\
		strgrep-test						\
		memcpy-test

MEMCPY_DEPS	=							\
		$(TMP_DIR)/base/string/memcpy-test.o			\
		$(TMP_DIR)/base/string/memcpy.o				\
		$(LIB_DIR)/libalx/libalx-string.a
MEMCPY_LIBS	=							\
		-L $(LIB_DIR)/libalx/					\
		-l alx-string

STRGREP_DEPS	=							\
		$(TMP_DIR)/base/string/strgrep-test.o			\
		$(TMP_DIR)/base/string/strgrep.o			\
		$(LIB_DIR)/libalx/libalx-string.a
STRGREP_LIBS	=							\
		-L $(LIB_DIR)/libalx/					\
		-l alx-string

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BIN)


memcpy-test: $(MEMCPY_DEPS)
	@echo	"	CC	libalx/test/base/string/$@"
	$(Q)$(CC) $< -o $@ $(MEMCPY_LIBS) $(LIBS)

strgrep-test: $(STRGREP_DEPS)
	@echo	"	CC	libalx/test/base/string/$@"
	$(Q)$(CC) $< -o $@ $(STRGREP_LIBS) $(LIBS)


PHONY += clean
clean:
	@echo	"	RM	$(ALL)"
	$(Q)rm -f $(BIN)

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
