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
		ocr.o

OCR_INC	=								\
		$(INC_DIR)/libalx/extra/ocr/ocr.h
OCR_SRC	=								\
		$(SRC_DIR)/extra/ocr/ocr.c

################################################################################
# cflags
CFLAGS_A	+= `pkg-config --cflags tesseract`
CFLAGS_SO	+= `pkg-config --cflags tesseract`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/ocr/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/ocr/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/ocr/$@"
	$(Q)$(AS) $< -o $@


ocr.a.s: $(OCR_SRC) $(OCR_INC)
ocr.so.s: $(OCR_SRC) $(OCR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
