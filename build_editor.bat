@echo off
setlocal

set OUTPUT=bin\editor\totalEditor.exe
set MINGW=C:\Users\chris\Documents\mingw64\mingw64\bin
set CXX=%MINGW%\g++.exe

set CXXFLAGS=-std=c++20 -Wall -Wextra -g

set INCLUDES=^
-Iengine ^
-Iengine/input/include ^
-Iengine/window/include ^
-Iengine/time/include ^
-Iengine/maths/include ^
-Ieditor/gui/include

set LIBS=-lgdi32 -luser32 -lkernel32

if not exist bin\editor mkdir bin\editor

echo Building EDITOR...

%CXX% ^
    %CXXFLAGS% ^
    %INCLUDES% ^
    editor/src/editorMain.cpp ^
    engine/core/src/core.cpp ^
    engine/window/src/thewindow.cpp ^
    engine/graphics/graphics.cpp ^
    engine/time/src/timeWin.cpp ^
    engine/input/src/input.cpp ^
    engine/maths/src/*.cpp ^
    editor/gui/src/*.cpp ^
    -o %OUTPUT% ^
    %LIBS%

echo Done.
pause