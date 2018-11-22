# -*- MakeFile -*-

# MACRO = substitute with this

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
