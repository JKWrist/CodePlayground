cmake_minimum_required(VERSION 3.16)

project(foobar)
set(CMAKE_SKIP_RPATH TRUE)

include_directories(${CMAKE_SOURCE_DIR})

add_library(foo SHARED foo_1.cpp)

add_library(bar SHARED bar_2.cpp)
#target_link_libraries(bar PUBLIC foo)
#target_link_libraries(bar INTERFACE foo)
target_link_libraries(bar PRIVATE foo)

add_executable(app app.cpp)
target_link_libraries(app bar)
