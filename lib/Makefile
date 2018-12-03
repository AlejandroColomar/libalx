#!/usr/bin/make -f

# MACRO = substitute with this

# directories

LIBALX_TMP_DIR	= $(LIBALX_DIR)/tmp/

INC_DIR = $(LIBALX_DIR)/inc/
SRC_DIR = $(LIBALX_DIR)/src/

# dependencies

_BASE	= alx_cmp.o alx_file.o alx_input.o alx_mask.o alx_math.o alx_seed.o
_CURSES	= alx_ncur.o
BASE	= libalx-base.a
CURSES	= libalx-curses.a

LIBALX_OBJS_BASE	= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_BASE))
LIBALX_OBJS_CURSES	= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_CURSES))

# target: dependencies
#	action

all: $(BASE)
	@echo  ""

base: $(BASE)
	@echo  ""

curses: $(CURSES)
	@echo  ""


libalx-base.a: $(LIBALX_OBJS_BASE)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"

libalx-curses.a: $(LIBALX_OBJS_CURSES)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"
