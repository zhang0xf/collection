WORKDIR = .
BINARY = $(WORKDIR)/bin/parser
ENTRY  = $(WORKDIR)/main.go

default: build

build:
	@echo "Building parser..."
	@go build -o $(BINARY) $(ENTRY)

clean:
	@echo "Cleaning build artifacts..."
	@rm -f $(BINARY)

fmt:
	@echo "Formatting source code..."
	@go fmt ./...

tidy:
	@echo "Tidying go.mod and go.sum..."
	@go mod tidy

test:
	@echo "Running tests..."
	@go test ./...

.PHONY: default build clean fmt tidy test
