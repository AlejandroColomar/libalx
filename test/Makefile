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
# libs
LIBS_PKG	= `pkg-config --libs libbsd-overlay`

LIBS		= $(LIBS_PKG)

export	LIBS

################################################################################
# target: dependencies
#	action

PHONY := all
all: string run


PHONY += math
math:
	$(Q)$(MAKE)	-C $(TST_DIR)/base/math/

PHONY += stdint
stdint:
	$(Q)$(MAKE)	-C $(TST_DIR)/base/stdint/

PHONY += stdio
stdio:
	$(Q)$(MAKE)	-C $(TST_DIR)/base/stdio/

PHONY += stdlib
stdlib:
	$(Q)$(MAKE)	-C $(TST_DIR)/base/stdlib/

PHONY += string
string:
	$(Q)$(MAKE)	-C $(TST_DIR)/base/string/

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	-C $(TST_DIR)/extra/ncurses/

PHONY += run
run: string
	@echo	"	TEST"
	$(Q)./run_tests


PHONY += clean
clean:
	$(Q)$(MAKE) clean	-C $(TST_DIR)/base/string/

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
