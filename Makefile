# -*- MakeFile -*-

# MACRO = substitute with this

# directories

TMP_DIR = $(LIBALX_DIR)/tmp/


# target: dependencies
#	action

all:
	$(Q)cd $(TMP_DIR) && $(MAKE) && cd ..


clean:
	$(Q)find . -type f -name '*.o' -exec rm '{}' '+'
	$(Q)find . -type f -name '*.s' -exec rm '{}' '+'
	@echo  "Clean libalx"
