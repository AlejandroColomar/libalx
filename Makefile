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
# Make variables (CC, etc...)
  CC		= gcc
  AS		= as
  AR		= ar

export	CC
export	AS
export	AR

################################################################################
# cflags
CFLAGS_STD	= -std=c11

CFLAGS_OPT	= -O3
CFLAGS_OPT     += -march=native

CFLAGS_W	= -Wall
CFLAGS_W       += -Wextra
CFLAGS_W       += -Wstrict-prototypes
CFLAGS_W       += -Werror
CFLAGS_W       += -Wno-format-truncation
CFLAGS_W       += -Wno-format-zero-length
#CFLAGS_W       += -Wno-unused-function

CFLAGS_PKG	= `pkg-config --cflags ncurses`

CFLAGS_D	= -D PROG_VERSION=\"$(PROGRAMVERSION)\"
CFLAGS_D       += -D INSTALL_SHARE_DIR=\"$(INSTALL_SHARE_DIR)\"
CFLAGS_D       += -D SHARE_DIR=\"$(SHARE_DIR)\"
CFLAGS_D       += -D INSTALL_VAR_DIR=\"$(INSTALL_VAR_DIR)\"
CFLAGS_D       += -D VAR_DIR=\"$(VAR_DIR)\"

CFLAGS		= $(CFLAGS_STD)
CFLAGS         += $(CFLAGS_OPT)
CFLAGS         += $(CFLAGS_W)
CFLAGS         += $(CFLAGS_PKG)
CFLAGS         += $(CFLAGS_D)

export	CFLAGS

################################################################################
# directories

TMP_DIR = $(LIBALX_DIR)/tmp/
LIB_DIR = $(LIBALX_DIR)/lib/


# target: dependencies
#	action

all:
	$(Q)cd $(TMP_DIR) && $(MAKE) && cd ..
	$(Q)cd $(LIB_DIR) && $(MAKE) && cd ..


clean:
	$(Q)find . -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.s' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.a' -exec rm '{}' '+'
	@echo  "Clean libalx"
