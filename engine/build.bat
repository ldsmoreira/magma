REM Build script for the engine
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all .cpp files.
SET cppFilenames=
FOR /R %%f IN (*.cpp) DO (
    REM Append each .c file found to the cFilenames variable
    ECHO 'HELOOOOOO'
    ECHO %%f
    SET cppFilenames=!cppFilenames! %%f
)

ECHO 'TESTE'

REM Echo the list of .c files
REM echo "Files:" %cFilenames%

REM Set the assembly name
SET assembly=engine

REM Set the compiler flags
SET compilerFlags=-g -Wall -Werror
REM -Wall -Werror

REM Set the include paths
SET includeFlags=-Isrc -I%VULKAN_SDK%/include

REM Set the linker flags
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/lib

REM Set the preprocessor definitions
SET defines=

REM Display a message indicating the build process has started
ECHO "Building %assembly%%..."

REM Call the Clang compiler to compile the .c files and link them into a DLL
@REM clang++ -c %cppFilenames% %linkerFlags% %includeFlags% -o %assembly%.o
clang++ -c %cppFilenames% %includeFlags% -o %assembly%.lib.o
clang++ -c -fPIC %cppFilenames% %includeFlags% -o %assembly%.dll.o
ar rcs ../bin/%assembly%.lib %assembly%.lib.o
clang++ -shared %assembly%.dll.o ../bin/%assembly%.lib %linkerFlags% -L../bin -o ../bin/%assembly%.dll