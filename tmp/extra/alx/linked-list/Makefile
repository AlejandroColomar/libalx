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
		llist.o

LLIST_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.h	\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocs.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/reallocs.h		\
		$(INC_DIR)/libalx/extra/alx/linked-list/llist.h
LLIST_SRC	=							\
		$(SRC_DIR)/extra/alx/linked-list/llist.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/alx/linked-list/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/alx/linked-list/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/alx/linked-list/$@"
	$(Q)$(AS) $< -o $@


llist.a.s: $(LLIST_SRC) $(LLIST_INC)
llist.so.s: $(LLIST_SRC) $(LLIST_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
