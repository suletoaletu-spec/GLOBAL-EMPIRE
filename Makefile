.PHONY: all build run clean help

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2
TARGET = empire
SOURCES = Main Ui/Components/U
OBJECTS = $(SOURCES:.cpp=.o)

all: build

build: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS) core

make-dir:
	mkdir -p build

help:
	@echo "Available targets:"
	@echo "  make build   - Build the project"
	@echo "  make run     - Build and run the project"
	@echo "  make clean   - Remove build artifacts"
	@echo "  make help    - Show this help message"
