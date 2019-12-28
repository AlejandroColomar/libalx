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


PHONY += alx
alx: data-structures npcomplete

PHONY += data-structures
data-structures:
	$(Q)$(MAKE)	-C $(TMP_DIR)/alx/data-structures/

PHONY += npcomplete
npcomplete:
	$(Q)$(MAKE)	-C $(TMP_DIR)/alx/npcomplete/


PHONY += extra
extra: cv gmp gsl ncurses ocr zbar

PHONY += cv
cv:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/cv/

PHONY += gmp
gmp:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gmp/mpq/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gmp/mpz/

PHONY += gsl
gsl:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/distributions/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/rstat/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/statistics/
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/gsl/units/

PHONY += ncurses
ncurses:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/ncurses/

PHONY += ocr
ocr:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/ocr/

PHONY += zbar
zbar:
	$(Q)$(MAKE)	-C $(TMP_DIR)/extra/zbar/


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
