# gopl/Makefile

CHAPTERS := $(wildcard chapter*/)

.PHONY: all clean generate $(CHAPTERS)

all: $(CHAPTERS)
	@echo "✅ Build complete."

$(CHAPTERS):
	$(MAKE) -C $@

clean:
	for dir in $(CHAPTERS); do \
		$(MAKE) -C $$dir clean; \
	done

generate:
	@echo "🔧 Generating Makefiles for all examples..."
	python3 generate_makefiles.py
