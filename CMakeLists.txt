cmake_minimum_required(VERSION 3.15)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_definitions(-std=gnu++17 -U__STRICT_ANSI__)

set(LINKER_FLAGS1 -lcygwin)
set(LINKER_FLAGS2 -lSDL2main)
set(LINKER_FLAGS3 -lSDL2)
set(LINKER_FLAGS4 -mwindows)

add_subdirectory(googletest)

include_directories(googletest/googletest/include/gtest/gtest.h)

set(SOURCE_FILES lib.cpp)

add_executable(untitled6 main.cpp lib.cpp)
add_executable(tests tests.cpp lib.cpp)

target_link_libraries(tests gtest)