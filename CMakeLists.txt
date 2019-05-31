cmake_minimum_required(VERSION 3.11)
project(BlockCrash)
project(BlockCrash_autotest)
project(BlockCrash_GUI)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set (CMAKE_PREFIX_PATH "G:\\Qt\\Qt5.6.1\\5.6\\msvc2015_64\\lib\\cmake")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
add_executable(BlockCrash main.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
add_executable(BlockCrash_autotest maintest.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
add_executable(BlockCrash_GUI mainGUI.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h  ui/widget.ui  ui/widget.h ui/widget.cpp)

target_link_libraries(BlockCrash_GUI Qt5::Widgets)