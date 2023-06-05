cmake_minimum_required(VERSION 3.25)
project(rpgGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(rpgGame main.cpp constants/Constants.h field/Field.h field/Field.cpp main_loop/MainLoop.h main_loop/MainLoop.cpp player/Player.h player/Player.cpp)
