#!/usr/bin/make -f

################################################################################
# *AUTHOR*

# EMAIL		"1903716@gmail.com"
# FULL NAME	"Alejandro Colomar Andrés"

################################################################################
# Beautify output
# ---------------------------------------------------------------------------
# Prefix commands with $(Q) - that's useful
# for commands that shall be hidden in non-verbose mode.
#
#	$(Q)some command here
#
# If BUILD_VERBOSE equals 0 then the above command will be hidden.
# If BUILD_VERBOSE equals 1 then the above command is displayed.
#
# To put more focus on warnings, be less verbose as default
# Use 'make V=1' to see the full commands

ifeq ("$(origin V)","command line")
  BUILD_VERBOSE = $(V)
endif
ifndef BUILD_VERBOSE
  BUILD_VERBOSE = 0
endif

ifeq ($(BUILD_VERBOSE), 1)
  Q =
else
  Q = @
endif

# If the user is running make -s (silent mode), suppress echoing of
# commands

ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
  Q = @
endif

export	Q
export	BUILD_VERBOSE

################################################################################
# Do not print "Entering directory ...",
# but we want to display it when entering to the output directory
# so that IDEs/editors are able to understand relative filenames.
MAKEFLAGS += --no-print-directory

################################################################################
# directories

LIBALX_DIR	= $(CURDIR)

TMP_DIR	= $(LIBALX_DIR)/tmp/
LIB_DIR = $(LIBALX_DIR)/lib/

export	LIBALX_DIR

################################################################################
# target: dependencies
#	action

PHONY := all
all: base io curses


PHONY += base
base:
	@echo  "	MAKE	base"
	$(Q)$(MAKE) base	-C $(TMP_DIR)
	$(Q)$(MAKE) base	-C $(LIB_DIR)

PHONY += io
io:
	@echo  "	MAKE	io"
	$(Q)$(MAKE) io		-C $(TMP_DIR)
	$(Q)$(MAKE) io		-C $(LIB_DIR)

PHONY += curses
curses:
	@echo  "	MAKE	curses"
	$(Q)$(MAKE) curses	-C $(TMP_DIR)
	$(Q)$(MAKE) curses	-C $(LIB_DIR)


PHONY += clean
clean:
	@echo  "	RM	*.o *.s *.a"
	$(Q)find . -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.s' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.a' -exec rm '{}' '+'

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
