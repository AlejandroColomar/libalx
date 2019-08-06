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
		imgproc.o						\
		ximgproc.o

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

XIMGPROC_INC	=							\
		$(INC_DIR)/libalx/extra/cv/ximgproc.hpp
XIMGPROC_SRC	=							\
		$(SRC_DIR)/extra/cv/ximgproc.cpp

################################################################################
# cflags
CXXFLAGS_A	+= `pkg-config --cflags opencv`
CXXFLAGS_SO	+= `pkg-config --cflags opencv`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CC) $(CXXFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CXX	libalx/tmp/extra/cv/$@"
	$(Q)$(CC) $(CXXFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/cv/$@"
	$(Q)$(AS) $< -o $@


alx.a.s: $(ALX_SRC) $(ALX_INC)
alx.so.s: $(ALX_SRC) $(ALX_INC)

core.a.s: $(CORE_SRC) $(CORE_INC)
core.so.s: $(CORE_SRC) $(CORE_INC)

highgui.a.s: $(HIGHGUI_SRC) $(HIGHGUI_INC)
highgui.so.s: $(HIGHGUI_SRC) $(HIGHGUI_INC)

imgproc.a.s: $(IMGPROC_SRC) $(IMGPROC_INC)
imgproc.so.s: $(IMGPROC_SRC) $(IMGPROC_INC)

ximgproc.a.s: $(XIMGPROC_SRC) $(XIMGPROC_INC)
ximgproc.so.s: $(XIMGPROC_SRC) $(XIMGPROC_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
