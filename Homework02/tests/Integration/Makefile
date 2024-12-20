CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wpedantic -Werror
SRC = IntegrationTest.cpp ../../src/integration/Integration.cpp  
HEADERS = ../../src/integration/Integration.hpp 
TARGET = ../../build/IntegrationTest

# Rule to build the target
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Phony target for cleaning the build
.PHONY: clean
clean:
	rm -f $(TARGET)