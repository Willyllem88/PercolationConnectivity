# Variables
CXX = g++
CXXFLAGS = -Wall -O2 -g -O2

# Definir el directorio de origen y de objetos
SRC_DIR = ./src
OBJ_DIR = ./obj

# Targets
TARGET1 = main
TARGET2 = runner

# Source files
SOURCES1 = $(SRC_DIR)/main.cpp $(SRC_DIR)/graph.cpp
SOURCES2 = $(SRC_DIR)/runner.cpp

# Object files
OBJECTS1 = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES1))
OBJECTS2 = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES2))

# Default target
all: $(TARGET1) $(TARGET2)

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile rules
$(TARGET1): $(OBJ_DIR) $(OBJECTS1)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS1)

$(TARGET2): $(OBJ_DIR) $(OBJECTS2)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS2)

# Rule for building object files and placing them in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(TARGET1) $(TARGET2)
