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
all: base extra


PHONY += base
base:
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/assert/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/compiler/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/errno/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/float/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/math/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdint/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdio/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/stdlib/
	$(Q)$(MAKE)	-C $(TMP_DIR)/base/string/


PHONY += extra
extra: gsl ncurses


PHONY += gsl
gsl:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/distributions/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/rstat/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/statistics/

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
