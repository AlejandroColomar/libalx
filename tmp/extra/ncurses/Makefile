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
		$(INC_DIR)/libalx/extra/ncurses/get.h			\
		$(INC_DIR)/libalx/base/stdio/sscan.h			\
		$(INC_DIR)/libalx/extra/ncurses/common.h		\
		$(INC_DIR)/libalx/extra/ncurses/perror.h	
GET_SRC		=							\
		$(SRC_DIR)/extra/ncurses/get.c

MENU_INC	=							\
		$(INC_DIR)/libalx/extra/ncurses/menu.h			\
		$(INC_DIR)/libalx/extra/ncurses/common.h
MENU_SRC	=							\
		$(SRC_DIR)/extra/ncurses/menu.c

PERROR_INC	=							\
		$(INC_DIR)/libalx/extra/ncurses/perror.h
PERROR_SRC	=							\
		$(SRC_DIR)/extra/ncurses/perror.c

################################################################################
# CFLAGS
CFLAGS	+= `pkg-config --cflags ncurses`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


common.s: $(COMMON_SRC) $(COMMON_INC)
	@echo	"	CC	libalx/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
common.o: common.s
	@echo	"	AS	libalx/tmp/extra/ncurses/$@"
	$(Q)$(AS) $< -o $@

get.s: $(GET_SRC) $(GET_INC)
	@echo	"	CC	libalx/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
get.o: get.s
	@echo	"	AS	libalx/tmp/extra/ncurses/$@"
	$(Q)$(AS) $< -o $@

menu.s: $(MENU_SRC) $(MENU_INC)
	@echo	"	CC	libalx/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
menu.o: menu.s
	@echo	"	AS	libalx/tmp/extra/ncurses/$@"
	$(Q)$(AS) $< -o $@

perror.s: $(PERROR_SRC) $(PERROR_INC)
	@echo	"	CC	libalx/tmp/extra/ncurses/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
perror.o: perror.s
	@echo	"	AS	libalx/tmp/extra/ncurses/$@"
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
