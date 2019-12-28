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
		bst.o							\
		dyn-array.o						\
		dyn-buffer.o						\
		llist.o							\
		node.o

BST_INC		=							\
		$(INC_DIR)/libalx/extra/alx/data-structures/llist.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/node.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/bst.h
BST_SRC		=							\
		$(SRC_DIR)/extra/alx/data-structures/bst.c

DYNARR_INC	=							\
		$(INC_DIR)/libalx/base/assert/assert.h			\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/llist.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/dyn-array.h
DYNARR_SRC	=							\
		$(SRC_DIR)/extra/alx/data-structures/dyn-array.c

DYNBUF_INC	=							\
		$(INC_DIR)/libalx/base/assert/assert.h			\
		$(INC_DIR)/libalx/base/stdlib/minimum.h			\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.h	\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocs.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/reallocs.h		\
		$(INC_DIR)/libalx/extra/alx/data-structures/dyn-buffer.h
DYNBUF_SRC	=							\
		$(SRC_DIR)/extra/alx/data-structures/dyn-buffer.c

LLIST_INC	=							\
		$(INC_DIR)/libalx/base/compiler/unused.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.h	\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocs.h		\
		$(INC_DIR)/libalx/extra/alx/data-structures/dyn-array.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/dyn-buffer.h\
		$(INC_DIR)/libalx/extra/alx/data-structures/node.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/llist.h
LLIST_SRC	=							\
		$(SRC_DIR)/extra/alx/data-structures/llist.c

NODE_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.h	\
		$(INC_DIR)/libalx/extra/alx/data-structures/dyn-buffer.h\
		$(INC_DIR)/libalx/extra/alx/data-structures/node.h
NODE_SRC	=							\
		$(SRC_DIR)/extra/alx/data-structures/node.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	libalx/tmp/extra/alx/data-structures/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	libalx/tmp/extra/alx/data-structures/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	libalx/tmp/extra/alx/data-structures/$@"
	$(Q)$(AS) $< -o $@


bst.a.s: $(BST_SRC) $(BST_INC)
bst.so.s: $(BST_SRC) $(BST_INC)

dyn-array.a.s: $(DYNARR_SRC) $(DYNARR_INC)
dyn-array.so.s: $(DYNARR_SRC) $(DYNARR_INC)

dyn-buffer.a.s: $(DYNBUF_SRC) $(DYNBUF_INC)
dyn-buffer.so.s: $(DYNBUF_SRC) $(DYNBUF_INC)

llist.a.s: $(LLIST_SRC) $(LLIST_INC)
llist.so.s: $(LLIST_SRC) $(LLIST_INC)

node.a.s: $(NODE_SRC) $(NODE_INC)
node.so.s: $(NODE_SRC) $(NODE_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
