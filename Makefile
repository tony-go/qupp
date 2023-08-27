# Makefile for wrapping CMake commands

# Variables
BUILD_DIR=build
EXECUTABLE=qupp_example

# Default target
all: build

# Create the build directory and run CMake
configure:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

# Build the project
build: configure
	cd $(BUILD_DIR) && make

# Run the example
example: build
	./$(BUILD_DIR)/examples/qupp_example

# Run the tests
test: build
	cd $(BUILD_DIR) && ctest

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean and rebuild the project
rebuild: clean build

# Phony targets
.PHONY: all configure build run test clean rebuild

