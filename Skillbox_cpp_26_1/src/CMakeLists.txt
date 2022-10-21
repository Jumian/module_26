cmake_minimum_required(VERSION 3.23)

add_executable(Skillbox_cpp_26_1 main.cpp)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Skillbox_cpp_26_1 PUBLIC ${MY_INCLUDE})
