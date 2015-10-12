cmake_minimum_required(VERSION 3.3)
project(course_sol)

set(SOURCE_FILES main.cpp)
add_executable(course_sol ${SOURCE_FILES})
set_property(TARGET course_sol PROPERTY CXX_STANDARD 14)