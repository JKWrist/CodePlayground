cmake_minimum_required(VERSION 3.5)

project(hello_library)

add_library(hello_library STATIC src/Hello.cpp)

target_include_directories(hello_library PUBLIC ${PROJECT_SOURCE_DIR}/include)

#message(STATUS "$(PROJECT_SOURCE_DIR)/include")

add_executable(a.out src/main.cpp)

#message(STATUS "src/main.cpp")

target_link_libraries(a.out PUBLIC hello_library)


# cmake_minimum_required(VERSION 3.5)

# project(hello_library)

# ############################################################
# # Create a library
# ############################################################

# #Generate the static library from the library sources
# add_library(hello_library STATIC 
#     src/Hello.cpp
# )

# target_include_directories(hello_library
#     PUBLIC 
#         ${PROJECT_SOURCE_DIR}/include
# )


# ############################################################
# # Create an executable
# ############################################################

# # Add an executable with the above sources
# add_executable(hello_binary 
#     src/main.cpp
# )

# # link the new hello_library target with the hello_binary target
# target_link_libraries( hello_binary
#     PRIVATE 
#         hello_library
# )
