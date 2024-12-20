# Compiler and flags
CXX = g++
CPPFLAGS = -I../../include/boost_1_86_0
CXXFLAGS = -std=c++17 -Wall -Wpedantic -Werror 
SRC = Custom_analysis.cpp ../../src/statistics/CSVParser.cpp ../../src/statistics/Statistics.cpp 
HEADERS = ../../src/statistics/CellType.hpp ../../src/statistics/CSVParser.hpp ../../src/statistics/Statistics.hpp
TARGET = ../../build/Custom_analysis

#Rule to build the target
$(TARGET): $(SRC) 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Phony target for cleaning the build
.PHONY: clean
clean:
	rm -f $(TARGET)