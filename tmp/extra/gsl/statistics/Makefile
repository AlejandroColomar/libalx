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
		mean.o

MEAN_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/statistics/mean.h
MEAN_SRC	=							\
		$(SRC_DIR)/extra/gsl/statistics/mean.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


mean.s: $(MEAN_SRC) $(MEAN_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/statistics/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
mean.o: mean.s
	@echo	"	AS	libalx/tmp/extra/gsl/statistics/$@"
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
