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
		$(INC_DIR)/libalx/base/stdlib/average.h			\
		$(INC_DIR)/libalx/extra/gsl/distributions/uniform.h
UNIFORM_SRC	=							\
		$(SRC_DIR)/extra/gsl/distributions/uniform.c

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags gsl`
CFLAGS_SO	+= `pkg-config --cflags gsl`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/gsl/distributions/$@"
	$(Q)$(AS) $< -o $@


binomial.a.s: $(BINOMIAL_SRC) $(BINOMIAL_INC)
binomial.so.s: $(BINOMIAL_SRC) $(BINOMIAL_INC)

exponential.a.s: $(EXPONENTIAL_SRC) $(EXPONENTIAL_INC)
exponential.so.s: $(EXPONENTIAL_SRC) $(EXPONENTIAL_INC)

geometric.a.s: $(GEOMETRIC_SRC) $(GEOMETRIC_INC)
geometric.so.s: $(GEOMETRIC_SRC) $(GEOMETRIC_INC)

normal.a.s: $(NORMAL_SRC) $(NORMAL_INC)
normal.so.s: $(NORMAL_SRC) $(NORMAL_INC)

poisson.a.s: $(POISSON_SRC) $(POISSON_INC)
poisson.so.s: $(POISSON_SRC) $(POISSON_INC)

uniform.a.s: $(UNIFORM_SRC) $(UNIFORM_INC)
uniform.so.s: $(UNIFORM_SRC) $(UNIFORM_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
