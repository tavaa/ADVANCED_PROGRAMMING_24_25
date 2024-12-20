CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wpedantic -Werror

CPPFLAGS = -I../../include/muparserx-4.0.12/parser
LDFLAGS = -L../../include
LDLIBS = -lmuparserx

SRC = CustomIntegration.cpp ../../src/integration/Integration.cpp  

BUILD_DIR = ../../build
OUTPUT = $(BUILD_DIR)/CustomIntegration

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	mkdir -p $(BUILD_DIR) 
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o $(OUTPUT)
