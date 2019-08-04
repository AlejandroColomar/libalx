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
# CFLAGS
CXXFLAGS       += `pkg-config --cflags tesseract`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


ocr.s: $(OCR_SRC) $(OCR_INC)
	@echo	"	CXX	libalx/tmp/extra/ocr/$@"
	$(Q)$(CC) $(CFLAGS) -I $(INC_DIR) -S $< -o $@
ocr.o: ocr.s
	@echo	"	AS	libalx/tmp/extra/ocr/$@"
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
