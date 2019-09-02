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
		arithmetic.o						\
		cmp.o							\
		division.o						\
		exp.o							\
		get.o							\
		init_set.o						\
		root.o							\
		set.o							\
		theoretic.o

ARITHMETIC_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/arithmetic.h
ARITHMETIC_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/arithmetic.c

CMP_INC		=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/cmp.h
CMP_SRC		=							\
		$(SRC_DIR)/extra/gmp/mpz/cmp.c

DIVISION_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/division.h
DIVISION_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/division.c

EXP_INC		=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/exp.h
EXP_SRC		=							\
		$(SRC_DIR)/extra/gmp/mpz/exp.c

GET_INC		=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/get.h
GET_SRC		=							\
		$(SRC_DIR)/extra/gmp/mpz/get.c

INITSET_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/init_set.h
INITSET_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/init_set.c

ROOT_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/root.h
ROOT_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/root.c

SET_INC		=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/set.h
SET_SRC		=							\
		$(SRC_DIR)/extra/gmp/mpz/set.c

THEORETIC_INC	=							\
		$(INC_DIR)/libalx/extra/gmp/mpz/theoretic.h
THEORETIC_SRC	=							\
		$(SRC_DIR)/extra/gmp/mpz/theoretic.c

################################################################################
# cflags
#CFLAGS_A	+=
#CFLAGS_SO	+=

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/gmp/mpz/$@"
	$(Q)$(AS) $< -o $@


arithmetic.a.s: $(ARITHMETIC_SRC) $(ARITHMETIC_INC)
arithmetic.so.s: $(ARITHMETIC_SRC) $(ARITHMETIC_INC)

cmp.a.s: $(CMP_SRC) $(CMP_INC)
cmp.so.s: $(CMP_SRC) $(CMP_INC)

division.a.s: $(DIVISION_SRC) $(DIVISION_INC)
division.so.s: $(DIVISION_SRC) $(DIVISION_INC)

exp.a.s: $(EXP_SRC) $(EXP_INC)
exp.so.s: $(EXP_SRC) $(EXP_INC)

get.a.s: $(GET_SRC) $(GET_INC)
get.so.s: $(GET_SRC) $(GET_INC)

init_set.a.s: $(INITSET_SRC) $(INITSET_INC)
init_set.so.s: $(INITSET_SRC) $(INITSET_INC)

root.a.s: $(ROOT_SRC) $(ROOT_INC)
root.so.s: $(ROOT_SRC) $(ROOT_INC)

set.a.s: $(SET_SRC) $(SET_INC)
set.so.s: $(SET_SRC) $(SET_INC)

theoretic.a.s: $(THEORETIC_SRC) $(THEORETIC_INC)
theoretic.so.s: $(THEORETIC_SRC) $(THEORETIC_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
