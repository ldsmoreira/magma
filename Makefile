# Define the compiler and compiler flags
CXX = clang++
CXXFLAGS = -fPIC -Wall -Werror -pedantic

CPP_STANDARD = -std=c++20

# Define the source files and object files
SRC = $(shell dir /B/S magma\src\*.cpp)
OBJ = $(SRC:.cpp=.o)

VULKAN_INCLUDE = -I$(VULKAN_SDK)/Include
VULKAN_LINKING_FLAGS = -L$(VULKAN_SDK)/Lib -lvulkan-1

# NOTE: Remember use cmake to mingw and then make and make install and copy the libglfw3.a to the root directory
# TODO: Build GLFW when the build directory doesn't exist
GLFW_INCLUDE = -I./external/glfw/include
# GLFW_LINKING_FLAGS = -L./external/glfw/build/src/Release -llibglfw3
GLFW_LINKING_FLAGS = -L./external/glfw/build/src -lglfw3

# Generate a string of -I flags for all subdirectories of the magma/src directory
MAGMA_INCLUDE = $(shell for /r "magma\src" /d %%i in (*) do @echo -I"%%i") -I./external/spdlog/include

# Define the name of the static library and the output directory
LIB_STATIC = magma.lib
LIBDIR_STATIC = ./bin/static

# Define the name of the dynamic library and the output directory
LIB_DYNAMIC = magma.dll
LIBDIR_DYNAMIC = ./bin/dynamic

# Testbed source files and object files
TESTBEDSOURCES := $(shell dir /s /b application\samples\*.cpp)
TESTBEDOBJECTS=$(TESTBEDSOURCES:.cpp=.o)

# Define the build rule for the static library
$(LIBDIR_STATIC)/$(LIB_STATIC): $(OBJ)
	ar rcs $@ $^

# Define the build rule for the dynamic library
$(LIBDIR_DYNAMIC)/$(LIB_DYNAMIC): $(OBJ)
	$(CXX) $(CPP_STANDARD) -shared $^ -o $@ $(VULKAN_LINKING_FLAGS) $(GLFW_LINKING_FLAGS) -luser32 -lgdi32

# Define the build rule for the object files
%.o: %.cpp
	$(CXX) $(CPP_STANDARD) $(CXXFLAGS) $(VULKAN_INCLUDE) $(MAGMA_INCLUDE) $(GLFW_INCLUDE) -c $< -o $@

# DLL needs to be at the same directory as the executable or in the PATH
dynamic_bed:
	$(CXX) $(CPP_STANDARD) -o ./bin/dynamic/dynamic_bed.exe  $(TESTBEDSOURCES) $(MAGMA_INCLUDE) $(GLFW_INCLUDE) $(GLFW_LINKING_FLAGS) -L./bin/dynamic -lmagma $(VULKAN_LINKING_FLAGS) -luser32 -lgdi32

static_bed:
	$(CXX) $(CPP_STANDARD) -o static_bed.exe  $(TESTBEDSOURCES) $(MAGMA_INCLUDE) $(GLFW_INCLUDE) -L./bin/static -lmagma $(VULKAN_LINKING_FLAGS) $(GLFW_LINKING_FLAGS) -luser32 -lgdi32

# Define the clean rule
clean:
	del /Q $(subst /,\,$(OBJ) $(LIBDIR_STATIC)\$(LIB_STATIC) $(LIBDIR_DYNAMIC)\$(LIB_DYNAMIC) bin/dynamic/dynamic_bed.exe static_bed.exe)

build_dependencies:
	if not exist "external\glfw\build" ( \
		echo Building dependencies... && \
		cd external\glfw && cmake -S . -B build -G "MinGW Makefiles" && cmake --build build --config Release && \
		echo Done. \
	)

# Define the all rule
all: build_dependencies $(LIBDIR_STATIC)/$(LIB_STATIC) $(LIBDIR_DYNAMIC)/$(LIB_DYNAMIC) static_bed dynamic_bed

.PHONY: all clean