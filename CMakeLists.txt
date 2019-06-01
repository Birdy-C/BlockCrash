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

set(CMAKE_AUTORCC ON) # if you have any .qrc files

set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.12.3/lib/cmake")
# set (CMAKE_PREFIX_PATH "G:\\Qt\\Qt5.6.1\\5.6\\msvc2015_64\\lib\\cmake")
# I don't know how to link the dll file so I copied it to the system file
#qt5_add_resources(RESOURCES res.qrc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#if(APPLE)
#     set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
#else()
#     set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#endif()

find_package(Qt5Widgets REQUIRED)
add_executable(BlockCrash main.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
add_executable(BlockCrash_autotest maintest.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h)
add_executable(BlockCrash_GUI mainGUI.cpp BlockGenerate.cpp BlockGenerate.h Board.cpp Board.h  widget.ui  widget.h widget.cpp res.qrc)

target_link_libraries(BlockCrash_GUI Qt5::Widgets)