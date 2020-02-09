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
		fclose.o						\
		feof.o							\
		fgetc.o							\
		fgets.o							\
		fopen.o							\
		fread.o							\
		init.o							\
		internal.o						\
		rewind.o						\
		ungetc.o						\
		URL_FILE.o


FCLOSE_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fclose.h
FCLOSE_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/fclose.c

FEOF_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/feof.h
FEOF_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/feof.c

FGETC_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fgetc.h
FGETC_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/fgetc.c

FGETS_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/base/stdlib/minimum.h			\
		$(INC_DIR)/libalx/base/string/memchr/memchrend.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fgets.h
FGETS_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/fgets.c

FOPEN_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/base/compiler/unused.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/callocs.h		\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fopen.h
FOPEN_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/fopen.c

FREAD_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/base/stdlib/minimum.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/fread.h
FREAD_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/fread.c

INIT_INC	=							\
		$(INC_DIR)/libalx/extra/curl/fcurl/init.h
INIT_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/init.c

INTERNAL_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/base/stdlib/maximum.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h
INTERNAL_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/internal.c

REWIND_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(SRC_DIR)/extra/curl/fcurl/internal.h			\
		$(INC_DIR)/libalx/extra/curl/fcurl/rewind.h
REWIND_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/rewind.c

UNGETC_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h		\
		$(INC_DIR)/libalx/extra/curl/fcurl/ungetc.h
UNGETC_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/ungetc.c

URLFILE_INC	=							\
		$(INC_DIR)/libalx/alx/data-structures/dyn-buffer.h	\
		$(INC_DIR)/libalx/extra/curl/fcurl/URL_FILE.h
URLFILE_SRC	=							\
		$(SRC_DIR)/extra/curl/fcurl/URL_FILE.c

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
	@echo	"	CC	build/tmp/extra/curl/fcurl/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/extra/curl/fcurl/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/curl/fcurl/$@"
	$(Q)$(AS) $< -o $@


fclose.a.s: $(FCLOSE_SRC) $(FCLOSE_INC)
fclose.so.s: $(FCLOSE_SRC) $(FCLOSE_INC)

feof.a.s: $(FEOF_SRC) $(FEOF_INC)
feof.so.s: $(FEOF_SRC) $(FEOF_INC)

fgetc.a.s: $(FGETC_SRC) $(FGETC_INC)
fgetc.so.s: $(FGETC_SRC) $(FGETC_INC)

fgets.a.s: $(FGETS_SRC) $(FGETS_INC)
fgets.so.s: $(FGETS_SRC) $(FGETS_INC)

fopen.a.s: $(FOPEN_SRC) $(FOPEN_INC)
fopen.so.s: $(FOPEN_SRC) $(FOPEN_INC)

fread.a.s: $(FREAD_SRC) $(FREAD_INC)
fread.so.s: $(FREAD_SRC) $(FREAD_INC)

init.a.s: $(INIT_SRC) $(INIT_INC)
init.so.s: $(INIT_SRC) $(INIT_INC)

internal.a.s: $(INTERNAL_SRC) $(INTERNAL_INC)
internal.so.s: $(INTERNAL_SRC) $(INTERNAL_INC)

rewind.a.s: $(REWIND_SRC) $(REWIND_INC)
rewind.so.s: $(REWIND_SRC) $(REWIND_INC)

ungetc.a.s: $(UNGETC_SRC) $(UNGETC_INC)
ungetc.so.s: $(UNGETC_SRC) $(UNGETC_INC)

URL_FILE.a.s: $(URLFILE_SRC) $(URLFILE_INC)
URL_FILE.so.s: $(URLFILE_SRC) $(URLFILE_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
