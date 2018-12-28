# -*- MakeFile -*-

# MACRO = substitute with this

# directories

INC_DIR = $(LIBALX_DIR)/inc/
SRC_DIR = $(LIBALX_DIR)/src/

# dependencies

BASE	= alx_cmp.o alx_mask.o alx_math.o alx_seed.o
IO	= alx_file.o alx_input.o
CURSES	= alx_ncur.o

CMP_INC		= alx_cmp.h
CMP_DEPS	= $(SRC_DIR)/alx_cmp.c $(patsubst %,$(INC_DIR)/%,$(CMP_INC))
CMP_INC_DIRS	= -I $(INC_DIR)

FILE_INC	= alx_file.h
FILE_DEPS	= $(SRC_DIR)/alx_file.c $(patsubst %,$(INC_DIR)/%,$(FILE_INC))
FILE_INC_DIRS	= -I $(INC_DIR)

INPUT_INC	= alx_input.h
INPUT_DEPS	= $(SRC_DIR)/alx_input.c $(patsubst %,$(INC_DIR)/%,$(INPUT_INC))
INPUT_INC_DIRS	= -I $(INC_DIR)

MASK_INC	= alx_mask.h
MASK_DEPS	= $(SRC_DIR)/alx_mask.c $(patsubst %,$(INC_DIR)/%,$(MASK_INC))
MASK_INC_DIRS	= -I $(INC_DIR)

MATH_INC	= alx_math.h
MATH_DEPS	= $(SRC_DIR)/alx_math.c $(patsubst %,$(INC_DIR)/%,$(MATH_INC))
MATH_INC_DIRS	= -I $(INC_DIR)

NCUR_INC	= alx_ncur.h	alx_input.h
NCUR_DEPS	= $(SRC_DIR)/alx_ncur.c $(patsubst %,$(INC_DIR)/%,$(NCUR_INC))
NCUR_INC_DIRS	= -I $(INC_DIR)

SEED_INC	= alx_seed.h
SEED_DEPS	= $(SRC_DIR)/alx_seed.c $(patsubst %,$(INC_DIR)/%,$(SEED_INC))
SEED_INC_DIRS	= -I $(INC_DIR)

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


alx_cmp.s: $(CMP_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(CMP_INC_DIRS) -S $< -o $@
alx_cmp.o: alx_cmp.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_file.s: $(FILE_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(FILE_INC_DIRS) -S $< -o $@
alx_file.o: alx_file.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_input.s: $(INPUT_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(INPUT_INC_DIRS) -S $< -o $@
alx_input.o: alx_input.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_mask.s: $(MASK_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(MASK_INC_DIRS) -S $< -o $@
alx_mask.o: alx_mask.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_math.s: $(MATH_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(MATH_INC_DIRS) -S $< -o $@
alx_math.o: alx_math.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_ncur.s: $(NCUR_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) `pkg-config --cflags ncurses` $(NCUR_INC_DIRS) -S $< -o $@
alx_ncur.o: alx_ncur.s
	@echo	"	AS	$@"
	$(Q)$(AS) $< -o $@

alx_seed.s: $(SEED_DEPS)
	@echo	"	CC	$@"
	$(Q)$(CC) $(CFLAGS) $(SEED_INC_DIRS) -S $< -o $@
alx_seed.o: alx_seed.s
	@echo	"	AS	$@"
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
