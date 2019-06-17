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
		median.o

MEDIAN_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/rstat/median.h		\
		$(INC_DIR)/libalx/base/stdlib/average.h			\
		$(INC_DIR)/libalx/base/stdlib/compare.h
MEDIAN_SRC	=							\
		$(SRC_DIR)/extra/gsl/rstat/median.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


median.s: $(MEDIAN_SRC) $(MEDIAN_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/rstat/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
median.o: median.s
	@echo	"	AS	libalx/tmp/extra/gsl/rstat/$@"
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
