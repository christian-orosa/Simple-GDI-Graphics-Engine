@echo off
setlocal

set OUTPUT=bin\game\game.exe
set MINGW=C:\Users\chris\Documents\mingw64\mingw64\bin
set CXX=%MINGW%\g++.exe

set CXXFLAGS=-std=c++20 -Wall -Wextra -g

set INCLUDES=^
-Iengine ^
-Iengine/window/include ^
-Iengine/time/include ^
-Iengine/maths/include ^
-Iruntime/game/include

set LIBS=-lgdi32 -luser32 -lkernel32

if not exist bin\game mkdir bin\game

echo Building GAME...

%CXX% ^
    %CXXFLAGS% ^
    %INCLUDES% ^
    runtime/src/gameMain.cpp ^
    runtime/game/src/*.cpp ^
    engine/core/src/core.cpp ^
    engine/window/src/thewindow.cpp ^
    engine/graphics/graphics.cpp ^
    engine/time/src/timeWin.cpp ^
    engine/input/src/input.cpp ^
    engine/maths/src/*.cpp ^
    -o %OUTPUT% ^
    %LIBS%

echo Done.
pause