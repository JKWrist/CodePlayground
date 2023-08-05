cmake_minimum_required(VERSION 3.10)
project(scram_test)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/opt/openssl@1.1/include /usr/local/opt/boost/include)
link_directories(/usr/local/opt/openssl@1.1/lib /usr/local/opt/boost/lib)

link_libraries(libcrypto.a)

add_executable(scram_test scram.cpp)