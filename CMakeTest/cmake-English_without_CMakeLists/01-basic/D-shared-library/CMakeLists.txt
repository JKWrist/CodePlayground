cmake_minimum_required(VERSION 3.5)

project(hello_library)

add_library(hello_library SHARED src/Hello.cpp)

target_include_directories(hello_library PUBLIC $(PROJECT_SOURCE_DIR)/include)

add_executable(a.out src/main.cpp)

target_link_libraries(a.out PUBLIC hello_library)