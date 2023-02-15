# Compiler and compiler flags
CC=clang++
CFLAGS=-Wall -Werror -O2 -I./engine

# Linker flags
LDFLAGS=-L./bin/lib/static -L./bin/lib/dynamic -L"$(VULKAN_SDK)\Lib"
LIBS=-luser32 -lvulkan-1 -lmagmaengine 

# Include directories
INCLUDES=-I./engine/src -I"$(VULKAN_SDK)\Include"

# Source files and object files for the engine directory
ENGINESOURCES=$(wildcard engine/src/*.cpp)
ENGINEOBJECTS=$(ENGINESOURCES:.cpp=.o)

# Testbed source files and object files
TESTBEDSOURCES=$(wildcard testbed/src/*.cpp)
TESTBEDOBJECTS=$(TESTBEDSOURCES:.cpp=.o)

# Build target
all: static dynamic testbed.exe

# Build the static library
static: $(ENGINEOBJECTS)
	ar rcs bin/lib/static/magmaengine.lib $(ENGINEOBJECTS)

# Build the dynamic library
dynamic: $(ENGINEOBJECTS)
	$(CC) -shared $(ENGINEOBJECTS) $(LIBS) $(LDFLAGS) -o bin/lib/dynamic/magmaengine.dll


# Compile .cpp files into object files
%.o: %.cpp
	$(CC) -fPIC $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link the application from the object files
testbed.exe: $(TESTBEDOBJECTS)
	$(CC) $(CFLAGS) $(ENGINEOBJECTS) $(TESTBEDOBJECTS) $(LIBS) $(LDFLAGS) -o $@

# Clean up object files and executable
clean:
	rm -f $(ENGINEOBJECTS) testbed.exe