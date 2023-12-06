# Output File
OUTPUT 			= main

# Compiler and Flags
GCC 			= g++
GGC_FLAGS 		= -Wall

# Check the OS-SYSTEM to give the Right LIBS
#--------------------------------------------------------------------
ifeq ($(OS),Windows_NT)
    # Windows-specific settings or actions
	LIBS += -lole32 -lshell32 -lcomdlg32 -luuid
else
	UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
	GCC = g++
	LIBS += -lboost_log -lboost_system
    endif
endif
#------------------------------------------------------------------

# Directories
SRC_DIR 		= src
OBJ_DIR 		= program/obj
BIN_DIR 		= program/bin

# Source Files
SOURCES 		= $(wildcard $(SRC_DIR)/*.cpp) $(wildcard *.cpp)
OBJECTS 		= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE 		= $(BIN_DIR)/$(OUTPUT)

# Build Target
all: directories $(EXECUTABLE)

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(GCC) $(GGC_FLAGS) -o $@ $(OBJECTS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(GCC) $(GGC_FLAGS) -c -o $@ $<

# For Cleaning Up the Folder
clean:
	@echo clean...
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

# For Running Application
run: all
	@./$(EXECUTABLE)

# Check Memory Leak
check:
	@drmemory -logdir logs $(EXECUTABLE)
	
.PHONY: all clean directories run check
