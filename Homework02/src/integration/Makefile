# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wpedantic -Werror -O2 -fPIC -std=c++17 -I../../include/muparserx-4.0.12
LDFLAGS = -shared

# Directories
BUILD_DIR = ../../build
LIB_DIR = ../../lib

# Library names
LIB_STATISTICS = $(LIB_DIR)/libintegration.so

# Source and object files
SRC_FILES = Integration.cpp 
OBJ_FILES = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target: build the library
all: $(BUILD_DIR) $(LIB_DIR) $(LIB_STATISTICS)

# Ensure the build and library directories exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Rule to build the Statistics library
$(LIB_STATISTICS): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

# Generic rule to compile .cpp files into .o files (in the build directory)
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ_FILES)
	rm -f $(LIB_STATISTICS)
	rmdir --ignore-fail-on-non-empty $(BUILD_DIR) $(LIB_DIR)

.PHONY: all clean
