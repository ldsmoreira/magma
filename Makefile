# Define the compiler and compiler flags
CXX = clang++
CXXFLAGS = -fPIC -Wall -Werror -pedantic

CPP_STANDARD = -std=c++20

# Define the source files and object files
SRC = $(shell dir /B/S engine\src\*.cpp)
OBJ = $(SRC:.cpp=.o)

VULKAN_INCLUDE = -I$(VULKAN_SDK)/Include
VULKAN_LINKING_FLAGS = -L$(VULKAN_SDK)/Lib -lvulkan-1

MAGMA_INCLUDE = -I./engine/src/core -I./engine/src -I./external/spdlog/include

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
	$(CXX) $(CPP_STANDARD) -shared $^ -o $@ $(VULKAN_LINKING_FLAGS)

# Define the build rule for the object files
%.o: %.cpp
	$(CXX) $(CPP_STANDARD) $(CXXFLAGS) $(VULKAN_INCLUDE) $(MAGMA_INCLUDE) -c $< -o $@

# DLL needs to be at the same directory as the executable or in the PATH
dynamic_bed:
	$(CXX) $(CPP_STANDARD) -o ./bin/dynamic/dynamic_bed.exe $(TESTBEDSOURCES) $(MAGMA_INCLUDE) -L./bin/dynamic -lmagma -L$(VULKAN_SDK)/Lib -lvulkan-1 -luser32

static_bed:
	$(CXX) $(CPP_STANDARD) -o static_bed.exe $(TESTBEDSOURCES) $(MAGMA_INCLUDE) -L./bin/static -lmagma -L$(VULKAN_SDK)/Lib -lvulkan-1 -luser32

# Define the clean rule
clean:
	del /Q $(subst /,\,$(OBJ) $(LIBDIR_STATIC)\$(LIB_STATIC) $(LIBDIR_DYNAMIC)\$(LIB_DYNAMIC) bin/dynamic/dynamic_bed.exe static_bed.exe)

# Define the all rule
all: $(LIBDIR_STATIC)/$(LIB_STATIC) $(LIBDIR_DYNAMIC)/$(LIB_DYNAMIC) static_bed dynamic_bed

.PHONY: all clean