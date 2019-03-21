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
		strgrep-test

STATIC_LIBS_FILES	=						\
		$(LIB_DIR)/libalx/libalx-string.a
STATIC_LIBS	=							\
		-L $(LIB_DIR)/libalx/					\
		-l alx-string

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BIN)


strgrep-test: $(TMP_DIR)/string/strgrep-test.o $(LIB_FILES)
	@echo	"	CC	libalx/test/string/$@"
	$(Q)$(CC) $< -o $@ $(STATIC_LIBS) $(LIBS)


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
