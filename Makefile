# Variables
CXX = g++
CXXFLAGS = -Wall -O2

# Targets
TARGET1 = test
TARGET2 = test2

# Source files
SOURCES1 = test.cpp graph.cpp
SOURCES2 = main.cpp graph.cpp

# Object files
OBJECTS1 = $(SOURCES1:.cpp=.o)
OBJECTS2 = $(SOURCES2:.cpp=.o)

# Default target
all: $(TARGET1) $(TARGET2)

# Compile rules
$(TARGET1): $(OBJECTS1)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET2): $(OBJECTS2)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET1) $(OBJECTS1) $(TARGET2) $(OBJECTS2)
