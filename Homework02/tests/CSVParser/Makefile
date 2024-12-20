CXX = g++
CPPFLAGS = -I../../include/boost_1_86_0
CXXFLAGS = -std=c++17 -Wall -Wpedantic -Werror
SRC = CSVParserTest.cpp ../../src/statistics/CSVParser.cpp 
HEADERS = ../../src/statistics/CellType.hpp ../../src/statistics/CSVParser.hpp 
TARGET = ../../build/CSVParserTest

# Rule to build the target
$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Phony target for cleaning the build
.PHONY: clean
clean:
	rm -f $(TARGET)
