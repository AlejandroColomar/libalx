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
# If BUILD_VERBOSE equals 2 then the above command is displayed.
#
# To put more focus on warnings, be less verbose as default
# Use 'make V=1' to see some verbose output
# Use 'make V=2' to see the full commands

ifeq ("$(origin V)","command line")
  BUILD_VERBOSE = $(V)
endif
ifndef BUILD_VERBOSE
  BUILD_VERBOSE = 0
endif

ifeq ($(BUILD_VERBOSE), 2)
  Q =
  v = -v
else ifeq ($(BUILD_VERBOSE), 1)
  Q = @
  v = -v
else
  Q = @
  v =
endif

# If the user is running make -s (silent mode), suppress echoing of
# commands

ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
  Q = @
  v =
endif

export	Q
export	BUILD_VERBOSE

################################################################################
# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

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

# XXX: Set local or not local when building a package
LOCAL			= local
INSTALL_INC_DIR		= /usr/$(LOCAL)/include/
INSTALL_LIB_DIR		= /usr/$(LOCAL)/lib/
INSTALL_SHARE_DIR	= /usr/$(LOCAL)/share/
INSTALL_PKGCONFIG_DIR	= /usr/$(LOCAL)/lib/pkgconfig/

export	INSTALL_INC_DIR
export	INSTALL_LIB_DIR
export	INSTALL_SHARE_DIR
export	INSTALL_PKGCONFIG_DIR

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

CFLAGS_OPT	= -O3
CFLAGS_OPT     += -march=native
CFLAGS_OPT     += -flto

CFLAGS_W	= -Wall
CFLAGS_W       += -Wextra
CFLAGS_W       += -Wstrict-prototypes
CFLAGS_W       += -Werror

CFLAGS_D	= -D _GNU_SOURCE
CFLAGS_D       += -D _POSIX_C_SOURCE=200809L

CFLAGS_PKG	= `pkg-config --cflags libbsd-overlay`

CFLAGS_I	= -I $(INC_DIR)

CFLAGS		= $(CFLAGS_STD)
CFLAGS         += $(CFLAGS_OPT)
CFLAGS         += $(CFLAGS_W)
CFLAGS         += $(CFLAGS_D)
CFLAGS         += $(CFLAGS_PKG)
CFLAGS         += $(CFLAGS_I)

export	CFLAGS

CFLAGS_A	= $(CFLAGS)
CFLAGS_SO	= $(CFLAGS) -fpic

export	CFLAGS_A
export	CFLAGS_SO

################################################################################
# c++flags
CXXFLAGS_STD	= -std=gnu++17

CXXFLAGS_OPT	= -O3
CXXFLAGS_OPT   += -march=native
CXXFLAGS_OPT   += -flto

CXXFLAGS_W	= -Wall
CXXFLAGS_W     += -Wextra
CXXFLAGS_W     += -Werror

CXXFLAGS_D	= -D _GNU_SOURCE
CXXFLAGS_D     += -D _POSIX_C_SOURCE=200809L

CXXFLAGS_PKG	= `pkg-config --cflags libbsd-overlay`

CXXFLAGS_I	= -I $(INC_DIR)

CXXFLAGS	= $(CXXFLAGS_STD)
CXXFLAGS       += $(CXXFLAGS_OPT)
CXXFLAGS       += $(CXXFLAGS_W)
CXXFLAGS       += $(CXXFLAGS_D)
CXXFLAGS       += $(CXXFLAGS_PKG)
CXXFLAGS       += $(CXXFLAGS_I)

export	CXXFLAGS

CXXFLAGS_A	= $(CXXFLAGS)
CXXFLAGS_SO	= $(CXXFLAGS) -fpic

export	CXXFLAGS_A
export	CXXFLAGS_SO

################################################################################
# libs
LDFLAGS_OPT	= -O3
LDFLAGS_OPT    += -march=native
LDFLAGS_OPT    += -flto
LDFLAGS_OPT    += -fuse-linker-plugin

LDFLAGS_L	= -L $(LIB_DIR)/libalx/

LDFLAGS		= -shared
LDFLAGS        += $(LDFLAGS_OPT)
LDFLAGS        += $(LDFLAGS_L)

export	LDFLAGS

################################################################################
# target: dependencies
#	action

PHONY := all
all: base extra


PHONY += base
base:
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)

PHONY += extra
extra: cv gsl ncurses ocr zbar

PHONY += cv
cv: base gsl
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)

PHONY += gsl
gsl: base
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)

PHONY += ncurses
ncurses: base
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)

PHONY += ocr
ocr: base
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)

PHONY += zbar
zbar: base
	@echo	"	MAKE	$@"
	$(Q)$(MAKE) $@	-C $(TMP_DIR)
	$(Q)$(MAKE) $@	-C $(LIB_DIR)


PHONY += tst
tst: all
	@echo	"	MAKE	tst"
	$(Q)$(MAKE)	-C $(TST_DIR)


PHONY += install
install:
	@echo	"	Install:"
	@echo
	$(Q)$(MAKE)	install_base
	$(Q)$(MAKE)	install_extra
	$(Q)$(MAKE)	conf_ld
	@echo	"	Done"
	@echo

PHONY += install_base
install_base:
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	CP -r	./inc/libalx/base/*"
	$(Q)cp -rf $(v)		./inc/libalx/base/*			\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/base/
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	CP -r	./lib/libalx/libalx-base.*"
	$(Q)cp -rf $(v)		./lib/libalx/libalx-base.*		\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo	"	CP	./lib/pkgconfig/libalx-base.pc"
	$(Q)cp $(v)		./lib/pkgconfig/libalx-base.pc		\
					$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo	"	CP -r	./ect/ld.so.conf.d/*"
	$(Q)cp -rf $(v)		./etc/ld.so.conf.d/*			\
					$(DESTDIR)/etc/ld.so.conf.d/
	@echo

PHONY += install_extra
install_extra:
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	@echo	"	CP -r	./inc/libalx/extra/*"
	$(Q)cp -r -f $(v)	./inc/libalx/extra/*			\
					$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/extra/
	@echo	"	CP -r	./lib/libalx/*"
	$(Q)cp -r -f $(v)	./lib/libalx/*				\
					$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/extra/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/extra/
	@echo	"	CP -r	./share/libalx/extra/*"
	$(Q)cp -r -f $(v)	./share/libalx/extra/*			\
					$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/extra/
	@echo	"	MKDIR	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo	"	CP -r	./lib/pkgconfig/*"
	$(Q)cp -r -f $(v)	./lib/pkgconfig/*			\
					$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	@echo

PHONY += conf_ld
conf_ld:
	@echo	"	CP -r	./ect/ld.so.conf.d/*"
	$(Q)cp -r -f $(v)	./etc/ld.so.conf.d/*			\
					$(DESTDIR)/etc/ld.so.conf.d/
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo

PHONY += uninstall
uninstall:
	@echo	"	Clean old installations:"
	@echo
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_INC_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_LIB_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/"
	$(Q)rm -f -r		$(DESTDIR)/$(INSTALL_SHARE_DIR)/libalx/
	@echo	"	RM -rf	$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/libalx*.pc"
	$(Q)mkdir -p		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/
	$(Q)find		$(DESTDIR)/$(INSTALL_PKGCONFIG_DIR)/	\
				-type f -name 'libalx*.pc' -exec rm '{}' '+'
	@echo	"	RM	$(DESTDIR)/etc/ld.so.conf.d/libalx*.conf"
	$(Q)find		$(DESTDIR)/etc/ld.so.conf.d/		\
				-type f -name 'libalx*.conf' -exec rm '{}' '+'
	@echo	"	LDCONFIG"
	$(Q)ldconfig
	@echo	"	Done"
	@echo


PHONY += clean
clean:
	@echo	"	RM	*.o *.s *.a *.so *-test"
	$(Q)find $(TMP_DIR) -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find $(TMP_DIR) -type f -name '*.s' -exec rm '{}' '+'
	$(Q)find $(LIB_DIR) -type f -name '*.a' -exec rm '{}' '+'
	$(Q)find $(LIB_DIR) -type f -name '*.so' -exec rm '{}' '+'
	$(Q)find $(TST_DIR) -type f -name '*-test' -exec rm '{}' '+'

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
