# 查找当前目录下的所有子目录中的 Makefile
SUBDIRS := $(shell find . -type f -name Makefile ! -path './Makefile' -exec dirname {} \;)

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
