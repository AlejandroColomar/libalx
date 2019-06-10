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
# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

################################################################################
# Make variables (CC, etc...)
  CC	= gcc
  CXX	= g++
  AS	= as
  AR	= ar
  LD	= ld
  SZ	= size

export	CC
export	CXX
export	AS
export	AR
export	LD
export	SZ

################################################################################
# cflags
CFLAGS_STD	= -std=gnu17
#CFLAGS_STD    += -Wpedantic

CFLAGS_MEM	= -mcmodel=large

CFLAGS_BSD	= `pkg-config --cflags libbsd-overlay`

CFLAGS_OPT	= -O3
CFLAGS_OPT     += -march=native
CFLAGS_OPT     += -flto

CFLAGS_W	= -Wall
CFLAGS_W       += -Wextra
CFLAGS_W       += -Wstrict-prototypes
CFLAGS_W       += -Werror
CFLAGS_W       += -Wno-error=pedantic
CFLAGS_W       += -Wno-error=unused-function

CFLAGS_D	= -D _GNU_SOURCE

CFLAGS		= $(CFLAGS_STD)
CFLAGS         += $(CFLAGS_MEM)
CFLAGS         += $(CFLAGS_BSD)
CFLAGS         += $(CFLAGS_OPT)
CFLAGS         += $(CFLAGS_W)
CFLAGS         += $(CFLAGS_D)

export	CFLAGS

################################################################################
# c++flags
CXXFLAGS_STD	= -std=gnu++17
#CXXFLAGS_STD  += -Wpedantic

CXXFLAGS_MEM	= -mcmodel=large

CXXFLAGS_BSD	= `pkg-config --cflags libbsd-overlay`

CXXFLAGS_OPT	= -O3
CXXFLAGS_OPT   += -march=native
CXXFLAGS_OPT   += -flto

CXXFLAGS_W	= -Wall
CXXFLAGS_W     += -Wextra
CXXFLAGS_W     += -Werror

CXXFLAGS_D	= -D _GNU_SOURCE

CXXFLAGS	= $(CXXFLAGS_STD)
CXXFLAGS       += $(CXXFLAGS_MEM)
CXXFLAGS       += $(CXXFLAGS_BSD)
CXXFLAGS       += $(CXXFLAGS_OPT)
CXXFLAGS       += $(CXXFLAGS_W)
CXXFLAGS       += $(CXXFLAGS_D)

export	CXXFLAGS

################################################################################
# directories

LIBALX_DIR	= $(CURDIR)

INC_DIR = $(LIBALX_DIR)/inc/
SRC_DIR = $(LIBALX_DIR)/src/
TMP_DIR	= $(LIBALX_DIR)/tmp/
LIB_DIR = $(LIBALX_DIR)/lib/
TST_DIR = $(LIBALX_DIR)/test/

export	LIBALX_DIR
export	INC_DIR
export	SRC_DIR
export	TMP_DIR
export	LIB_DIR
export	TST_DIR

################################################################################

################################################################################
# target: dependencies
#	action

PHONY := all
all: base extra


PHONY += math
math:
	@echo	"	MAKE	math"
	$(Q)$(MAKE) math	-C $(TMP_DIR)
	$(Q)$(MAKE) math	-C $(LIB_DIR)

PHONY += stddef
stddef:
	@echo	"	MAKE	stddef"
	$(Q)$(MAKE) stddef	-C $(TMP_DIR)
	$(Q)$(MAKE) stddef	-C $(LIB_DIR)

PHONY += stdint
stdint:
	@echo	"	MAKE	stdint"
	$(Q)$(MAKE) stdint	-C $(TMP_DIR)
	$(Q)$(MAKE) stdint	-C $(LIB_DIR)

PHONY += stdio
stdio:
	@echo	"	MAKE	stdio"
	$(Q)$(MAKE) stdio	-C $(TMP_DIR)
	$(Q)$(MAKE) stdio	-C $(LIB_DIR)

PHONY += stdlib
stdlib:
	@echo	"	MAKE	stdlib"
	$(Q)$(MAKE) stdlib	-C $(TMP_DIR)
	$(Q)$(MAKE) stdlib	-C $(LIB_DIR)

PHONY += string
string:
	@echo	"	MAKE	string"
	$(Q)$(MAKE) string	-C $(TMP_DIR)
	$(Q)$(MAKE) string	-C $(LIB_DIR)

PHONY += base
base: math stddef stdint stdio stdlib string
	@echo	"	MAKE	base"
	$(Q)$(MAKE) base	-C $(LIB_DIR)

PHONY += ncurses
ncurses:
	@echo	"	MAKE	ncurses"
	$(Q)$(MAKE) ncurses	-C $(TMP_DIR)
	$(Q)$(MAKE) ncurses	-C $(LIB_DIR)

PHONY += extra
extra: ncurses
	@echo	"	MAKE	extra"
	$(Q)$(MAKE) extra	-C $(LIB_DIR)


PHONY += tst
tst: all
	@echo	"	MAKE	tst"
	$(Q)$(MAKE)		-C $(TST_DIR)


PHONY += clean
clean:
	@echo	"	RM	*.o *.s *.a *-test"
	$(Q)find $(TMP_DIR) -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find $(TMP_DIR) -type f -name '*.s' -exec rm '{}' '+'
	$(Q)find $(LIB_DIR) -type f -name '*.a' -exec rm '{}' '+'
	$(Q)find $(TST_DIR) -type f -name '*-test' -exec rm '{}' '+'

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
