# gopl/chapter01/Makefile
GOFILES := $(wildcard *.go)
BINARIES := $(GOFILES:.go=)

.PHONY: all clean

all: $(BINARIES)

%: %.go
	go build -o $@ $<

clean:
	rm -f $(BINARIES)
