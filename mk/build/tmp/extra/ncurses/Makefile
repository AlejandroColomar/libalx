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
		common.o						\
		get.o							\
		menu.o							\
		perror.o

COMMON_INC	=							\
		$(INC_DIR)/libalx/extra/ncurses/common.h
COMMON_SRC	=							\
		$(SRC_DIR)/extra/ncurses/common.c

GET_INC		=							\
		$(INC_DIR)/libalx/base/stdio/sscan.h			\
		$(INC_DIR)/libalx/extra/ncurses/common.h		\
		$(INC_DIR)/libalx/extra/ncurses/perror.h		\
		$(INC_DIR)/libalx/extra/ncurses/get.h	
GET_SRC		=							\
		$(SRC_DIR)/extra/ncurses/get.c

MENU_INC	=							\
		$(INC_DIR)/libalx/extra/ncurses/common.h		\
		$(INC_DIR)/libalx/extra/ncurses/menu.h
MENU_SRC	=							\
		$(SRC_DIR)/extra/ncurses/menu.c

PERROR_INC	=							\
		$(INC_DIR)/libalx/extra/ncurses/perror.h
PERROR_SRC	=							\
		$(SRC_DIR)/extra/ncurses/perror.c

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags ncurses`
CFLAGS_SO	+= `pkg-config --cflags ncurses`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/ncurses/$@"
	$(Q)$(AS) $< -o $@


common.a.s: $(COMMON_SRC) $(COMMON_INC)
common.so.s: $(COMMON_SRC) $(COMMON_INC)

get.a.s: $(GET_SRC) $(GET_INC)
get.so.s: $(GET_SRC) $(GET_INC)

menu.a.s: $(MENU_SRC) $(MENU_INC)
menu.so.s: $(MENU_SRC) $(MENU_INC)

perror.a.s: $(PERROR_SRC) $(PERROR_INC)
perror.so.s: $(PERROR_SRC) $(PERROR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
