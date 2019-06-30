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
		assert.o

ASSERT_INC	=							\
		$(INC_DIR)/libalx/base/assert/assert.h
ASSERT_SRC	=							\
		$(SRC_DIR)/base/assert/assert.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


assert.s: $(ASSERT_SRC) $(ASSERT_INC)
	@echo	"	CC	libalx/tmp/base/assert/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
assert.o: assert.s
	@echo	"	AS	libalx/tmp/base/assert/$@"
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
