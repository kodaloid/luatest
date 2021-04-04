# Specify the minimum CMake version.
cmake_minimum_required(VERSION 3.20)

# Set the C++ Standard Library Requirement.
set(CMAKE_CXX_STANDARD 17)

# Setup the project.
project(LuaTest VERSION 0.0.0)

# Add files that can be used by the include command in C++
include_directories("M:/Lib/Static/lua-5.3.5_Win32_mingw6_lib/include/")

# Load in the code files from src folder.
file(GLOB SOURCES "src/*.cpp")

# Create an executable
add_executable(LuaTest ${SOURCES})

# Link our libraries.
target_link_libraries(LuaTest "M:/Lib/Static/lua-5.3.5_Win32_mingw6_lib/liblua53.a")