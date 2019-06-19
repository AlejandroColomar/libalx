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
		restrict.o						\
		size.o

RESTRICT_INC	=							\
		$(INC_DIR)/libalx/base/stddef/restrict.hpp
RESTRICT_SRC	=							\
		$(SRC_DIR)/base/stddef/restrict.cpp

SIZE_INC	=							\
		$(INC_DIR)/libalx/base/stddef/size.h
SIZE_SRC	=							\
		$(SRC_DIR)/base/stddef/size.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


restrict.s: $(RESTRICT_SRC) $(RESTRICT_INC)
	@echo	"	CXX	libalx/tmp/base/stddef/$@"
	$(Q)$(CXX) $(CXXFLAGS) -S $< -o $@
restrict.o: restrict.s
	@echo	"	AS	libalx/tmp/base/stddef/$@"
	$(Q)$(AS) $< -o $@

size.s: $(SIZE_SRC) $(SIZE_INC)
	@echo	"	CC	libalx/tmp/base/stddef/$@"
	$(Q)$(CC) $(CFLAGS) -S $< -o $@
size.o: size.s
	@echo	"	AS	libalx/tmp/base/stddef/$@"
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
