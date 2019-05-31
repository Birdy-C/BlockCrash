cmake_minimum_required(VERSION 3.14)
project(BlockCrash)
project(BlockCrash_autotest)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlockCrash main.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
add_executable(BlockCrash_autotest main.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
