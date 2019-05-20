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
# target: dependencies
#	action

PHONY := all
all: math stddef stdint stdio stdlib string ncurses


PHONY += math
math:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/math/

PHONY += stddef
stddef:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stddef/

PHONY += stdint
stdint:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdint/

PHONY += stdio
stdio:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdio/

PHONY += stdlib
stdlib:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdlib/

PHONY += string
string:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/string/

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/ncurses/


PHONY += clean
clean:
	@echo	"	RM	*.o *.s"
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
