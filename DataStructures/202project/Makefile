# Using chat GPT 3.5 we made this Makefile

# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
# Dependency files
DEPS := $(OBJS:.o=.d)

# Targets
TARGET := main

# Include directories
INC_FLAGS := -I$(INC_DIR)

# Linker flags
LDFLAGS :=

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Compile sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -MMD -MP -c $< -o $@

# Include dependencies
-include $(DEPS)

.PHONY: clean

# Clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)
