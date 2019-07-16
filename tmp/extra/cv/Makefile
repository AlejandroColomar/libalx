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
		alx.o							\
		core.o							\
		highgui.o						\
		imgproc.o

ALX_INC	=								\
		$(INC_DIR)/libalx/extra/cv/alx.hpp
ALX_SRC	=								\
		$(SRC_DIR)/extra/cv/alx.cpp

CORE_INC	=							\
		$(INC_DIR)/libalx/extra/cv/core.hpp
CORE_SRC	=							\
		$(SRC_DIR)/extra/cv/core.cpp

HIGHGUI_INC	=							\
		$(INC_DIR)/libalx/extra/cv/highgui.hpp
HIGHGUI_SRC	=							\
		$(SRC_DIR)/extra/cv/highgui.cpp

IMGPROC_INC	=							\
		$(INC_DIR)/libalx/extra/cv/imgproc.hpp
IMGPROC_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc.cpp

################################################################################
# CFLAGS
CXXFLAGS       += `pkg-config --cflags opencv`
CXXFLAGS       += `pkg-config --cflags zbar`
CXXFLAGS       += `pkg-config --cflags tesseract`
CXXFLAGS       += `pkg-config --cflags lept`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(OBJ)


alx.s: $(ALX_SRC) $(ALX_INC)
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CXX) $(CXXFLAGS) -I $(INC_DIR) -S $< -o $@
alx.o: alx.s
	@echo	"	AS	libalx/tmp/extra/cv/$@"
	$(Q)$(AS) $< -o $@

core.s: $(CORE_SRC) $(CORE_INC)
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CXX) $(CXXFLAGS) -I $(INC_DIR) -S $< -o $@
core.o: core.s
	@echo	"	AS	libalx/tmp/extra/cv/$@"
	$(Q)$(AS) $< -o $@

highgui.s: $(HIGHGUI_SRC) $(HIGHGUI_INC)
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CXX) $(CXXFLAGS) -I $(INC_DIR) -S $< -o $@
highgui.o: highgui.s
	@echo	"	AS	libalx/tmp/extra/cv/$@"
	$(Q)$(AS) $< -o $@

imgproc.s: $(IMGPROC_SRC) $(IMGPROC_INC)
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CXX) $(CXXFLAGS) -I $(INC_DIR) -S $< -o $@
imgproc.o: imgproc.s
	@echo	"	AS	libalx/tmp/extra/cv/$@"
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
