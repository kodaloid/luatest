# Lua Test

This is an example of how to setup a C++ application that uses GCC/CMake on Windows.
It has been a bug bear of mine for a few years not knowing how to do it. So this is
the result of me finally figuring it out.

CMakeLists.txt is set-up to use C++ 17, links to a statically loaded binary of Lua,
and compiles the main.cpp file in the src folder. Compiling produces a TestLua.exe
in the build folder (gets created if not there after a git pull).

## To run the build, you will need the following:
- GCC (I used the 32bit version of MinGW-64 via WinBuilds)
- CMake (Again the 32bit version)
- Lua 5.3.5 (32bit W6 build) - static variant.
- Make sure GCC and CMake bin folders are present in the global Environmental Path.

## To build
Either open the project in VS Code, and use the built in CMake extension. Or to do
it manually, launch a terminal and navigate to the build folder (create it if
missing). Then type:

```cmake ../```

If successful, you should should be able to run the app by typing ```./TestLua.exe```

## Things to watch out for with GCC and CMake

1. The executables that GCC builds often fails to report missing DLL files, which
   causes the app to exit immediately. If you run bash or power shell no error will
   be outputted. However windows CMD for some reason will tell you what is wrong!

   I found the solution was to make sure the winbuilds\bin folder was added to 
   the path environment variable, however copying the missing DLL's into the same
   folder did the trick too.

2. To link to Lua or any other 3rd party library in CMake, you need to pick the
   correct binaries for the platform. I struggled for hours with this as there are
   many builds of Lua.
   
   In the end linking to the Dynamic 32bit W6 build worked, which also meant I needed
   to have Lua53.dll findable (either in same path, or env variable) for it to work.