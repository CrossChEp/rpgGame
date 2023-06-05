cmake_minimum_required(VERSION 3.25)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp constants/Constants.h field/Field.cpp field/Field.h controls/Controls.h player/Player.h player/Player.cpp)
