#!/usr/bin/make -f

# MACRO = substitute with this

# directories

LIBALX_TMP_DIR	= $(LIBALX_DIR)/tmp/

INC_DIR = $(LIBALX_DIR)/inc/
SRC_DIR = $(LIBALX_DIR)/src/

# dependencies

_BASE	= alx_cmp.o alx_mask.o alx_math.o alx_seed.o
_IO	= alx_input.o alx_file.o
_CURSES	= alx_ncur.o
BASE	= libalx-base.a
IO	= libalx-io.a
CURSES	= libalx-curses.a

LIBALX_OBJS_BASE	= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_BASE))
LIBALX_OBJS_IO		= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_IO))
LIBALX_OBJS_CURSES	= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_CURSES))

# target: dependencies
#	action

PHONY := all
all: base io curses

PHONY += base
base: $(BASE)

PHONY += io
io: $(IO)

PHONY += curses
curses: $(CURSES)


libalx-base.a: $(LIBALX_OBJS_BASE)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"

libalx-io.a: $(LIBALX_OBJS_IO)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"

libalx-curses.a: $(LIBALX_OBJS_CURSES)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"


PHONY += clean
clean:
	$(Q)rm -f *.a

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
