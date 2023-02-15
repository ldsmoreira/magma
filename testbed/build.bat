REM Build script for testbed
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get list of all .cpp files
SET cppFilenames=
FOR /R %%f IN (*.cpp) DO (
    REM Append each .cpp file found to the cppFilenames variable
    SET cppFilenames=!cppFilenames! %%f
)

REM Echo the list of .cpp files

SET assembly=testbed
REM Set the compiler flags
SET compilerFlags=-g
REM Set the include paths
SET includeFlags=-Isrc -I../engine/src
SET linkerFlags=-LC:\Estudo\3D\magma\bin -lengine.a
SET defines=-D_DEBUG -DKEXPORT

ECHO "Building %assembly%%..."
ECHO clang++ %cppFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%
clang++ %linkerFlags% %cppFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags%