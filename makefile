# Determine the operating system
ifeq ($(OS),Windows_NT)
    # Windows-specific compiler and flags
    CC = x86_64-w64-mingw32-g++
    CFLAGS = -static-libgcc -static-libstdc++
    LDFLAGS = -lsqlite3 -lole32 -lshell32 -lcomdlg32 -luuid
else
    # Linux-specific compiler and flags
    CC = g++
    CFLAGS =
    LDFLAGS = -lsqlite3 # Add Linux-specific linker flags here
endif

# Common compiler flags and source files
CFLAGS += -Wall
SOURCES = test.cpp

# Output executable name
OUTPUT = main

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
