cmake_minimum_required(VERSION 3.20)

project(format_boolean)
find_package(xtd REQUIRED)
add_sources(README.md src/format_boolean.cpp)
target_type(CONSOLE_APPLICATION)
