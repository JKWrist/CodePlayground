cmake_minimum_required (VERSION 2.8)

project (out)

aux_source_directory (. DIR_SRCS)

add_executable (a.out ${DIR_SRCS})