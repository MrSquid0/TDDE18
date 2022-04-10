cmake_minimum_required(VERSION 3.20)
project(Lab2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lab2 Time.cpp Time.h Tests/Tests.cpp)
#target_link_libraries(Lab2 "${PROJECT_SOURCE_DIR}/Tests/test_main.o")
