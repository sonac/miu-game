cmake_minimum_required(VERSION 3.20)
project(foo)

set(CMAKE_CXX_STANDARD 20)

add_executable(foo main.cpp test.cpp miu_game.cpp miu_game.h test.h)
