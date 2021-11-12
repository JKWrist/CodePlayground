cmake_minimum_required (VERSION 2.8)

project (a.out)

#message(FATAL_ERROR "FATAL_ERROR to display")
message(SEND_ERROR "SEND_ERROR to display")
message(WARNING "WARNING message to display")
message(AUTHOR_WARNING "AUTHOR_WARNING message to display")
message(STATUS "STATUS message to display")
message(DEBUG "DEBUG message to display")
message(TRACE "TRACE message to display")

add_executable(a.out main.cc)