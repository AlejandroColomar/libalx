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
		binomial.o						\
		exponential.o						\
		geometric.o						\
		normal.o						\
		poisson.o						\
		uniform.o

BINOMIAL_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/binomial.h
BINOMIAL_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/binomial.c

EXPONENTIAL_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/exponential.h
EXPONENTIAL_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/exponential.c

GEOMETRIC_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/geometric.h
GEOMETRIC_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/geometric.c

NORMAL_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/normal.h
NORMAL_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/normal.c

POISSON_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/poisson.h
POISSON_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/poisson.c

UNIFORM_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/distributions/uniform.h	\
		$(INC_DIR)/libalx/base/stdlib/average.h
UNIFORM_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/uniform.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


binomial.s: $(BINOMIAL_SRC) $(BINOMIAL_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
binomial.o: binomial.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@

exponential.s: $(EXPONENTIAL_SRC) $(EXPONENTIAL_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
exponential.o: exponential.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@

geometric.s: $(GEOMETRIC_SRC) $(GEOMETRIC_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
geometric.o: geometric.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@

normal.s: $(NORMAL_SRC) $(NORMAL_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
normal.o: normal.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@

poisson.s: $(POISSON_SRC) $(POISSON_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
poisson.o: poisson.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@

uniform.s: $(UNIFORM_SRC) $(UNIFORM_INC)
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
uniform.o: uniform.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
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
