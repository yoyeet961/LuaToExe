# LuaToExe
## Description
A simple program to convert Lua files to EXE files. The result is a folder with 3 files in it: the program, lua53.dll, and an unreadable version of the Lua script. The Lua version is 5.3.5.

Currently only supported on Windows x64.

## How to Use
To use the program, open LuaToExe.exe, type the **full** path into it and press Enter. Now there will be an `output` folder in the same directory as the executable, containing your Lua program.

## How to Compile
1. Install vcpkg and Visual Studio 2022
2. Open the solution file (LuaToExe.sln) in Visual Studio 2022, and install `termcolor` through vcpkg.
3. Now you can compile the program by pressing Ctrl+B. After doing this, there will be an `x64` directory in the solution folder, inside of it will be another folder (`Debug`/`Release`), and inside that folder will be the program.