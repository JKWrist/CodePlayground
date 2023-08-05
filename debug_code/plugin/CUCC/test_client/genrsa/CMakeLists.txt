cmake_minimum_required(VERSION 3.10)
project(genrsa)

#set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/opt/openssl@1.1/include /usr/local/opt/boost/include)
link_directories(/usr/local/opt/openssl@1.1/lib /usr/local/opt/boost/lib)

link_libraries(libcrypto.a libssl.a)

add_executable(a.out genrsa.c)