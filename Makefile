# Define the compiler and compiler flags
CXX = clang++
CXXFLAGS = -fPIC -Wall -Werror -pedantic

# Define the source files and object files
SRC = $(wildcard engine/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

VULKAN_INCLUDE = -I$(VULKAN_SDK)/Include
VULKAN_LINKING_FLAGS = -L$(VULKAN_SDK)/Lib -lvulkan-1

# Define the name of the static library and the output directory
LIB_STATIC = magma.lib
LIBDIR_STATIC = ./bin/static

# Define the name of the dynamic library and the output directory
LIB_DYNAMIC = magma.dll
LIBDIR_DYNAMIC = ./bin/dynamic

# Testbed source files and object files
TESTBEDSOURCES=$(wildcard testbed/src/*.cpp)
TESTBEDOBJECTS=$(TESTBEDSOURCES:.cpp=.o)

# Define the build rule for the static library
$(LIBDIR_STATIC)/$(LIB_STATIC): $(OBJ)
	ar rcs $@ $^

# Define the build rule for the dynamic library
$(LIBDIR_DYNAMIC)/$(LIB_DYNAMIC): $(OBJ)
	$(CXX) -v -shared $^ -o $@ $(VULKAN_LINKING_FLAGS)

# Define the build rule for the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(VULKAN_INCLUDE) -c $< -o $@

# DLL needs to be at the same directory as the executable or in the PATH
dynamic_bed:
	$(CXX) -o ./bin/dynamic/dynamic_bed.exe $(TESTBEDSOURCES) -I./engine/src -L./bin/dynamic -lmagma -L$(VULKAN_SDK)/Lib -lvulkan-1

static_bed:
	$(CXX) -o static_bed.exe $(TESTBEDSOURCES) -I./engine/src -L./bin/static -lmagma -L$(VULKAN_SDK)/Lib -lvulkan-1

# Define the clean rule
clean:
	del /Q $(subst /,\,$(OBJ) $(LIBDIR)\$(LIB) $(LIBDIR_DYNAMIC)\$(LIB_DYNAMIC) dynamic_bed.exe static_bed.exe)

# Define the all rule
all: $(LIBDIR_STATIC)/$(LIB_STATIC) $(LIBDIR_DYNAMIC)/$(LIB_DYNAMIC) static_bed dynamic_bed

.PHONY: all clean