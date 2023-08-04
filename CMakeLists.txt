cmake_minimum_required(VERSION 3.24)
project(cs_app)

set(CMAKE_CXX_STANDARD 11)

add_executable(cs_app main.cpp)

add_executable(show_bytes chapter02/255_show_bytes.cpp)
add_executable(test1 chapter02/test.cpp)
add_executable(_is_little_enidan chapter02/258_is_little_enidan.cpp)
add_executable(compose_num chapter02/259_compose_num.cpp)
