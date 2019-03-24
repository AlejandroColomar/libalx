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
all: math stddef stdint stdio stdlib string curses


PHONY += math
math:
	$(Q)$(MAKE)	-C $(TMP_DIR)/math/

PHONY += stddef
stddef:
	$(Q)$(MAKE)	-C $(TMP_DIR)/stddef/

PHONY += stdint
stdint:
	$(Q)$(MAKE)	-C $(TMP_DIR)/stdint/

PHONY += stdio
stdio:
	$(Q)$(MAKE)	-C $(TMP_DIR)/stdio/

PHONY += stdlib
stdlib:
	$(Q)$(MAKE)	-C $(TMP_DIR)/stdlib/

PHONY += string
string:
	$(Q)$(MAKE)	-C $(TMP_DIR)/string/

PHONY += curses
curses:
	$(Q)$(MAKE)	-C $(TMP_DIR)/curses/


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
