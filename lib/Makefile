# -*- MakeFile -*-

# MACRO = substitute with this

# directories

LIBALX_TMP_DIR	= $(LIBALX_DIR)/tmp/

INC_DIR = $(LIBALX_DIR)/inc/
SRC_DIR = $(LIBALX_DIR)/src/

# dependencies

_ALL	= alx_cmp.o alx_file.o alx_input.o alx_mask.o alx_math.o alx_ncur.o alx_seed.o
ALL	= libalx.a

LIBALX_OBJS	= $(patsubst %,$(LIBALX_TMP_DIR)/%,$(_ALL))

# target: dependencies
#	action

all: $(ALL)


libalx.a: $(LIBALX_OBJS)
	$(Q)$(AR) -r -c -s -o $@ $^
	@echo  "	AR	$@"
	@echo  ""
