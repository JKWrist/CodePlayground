#命令是不区分大小写的。符号 # 后面的内容被认为是注释

#指定运行此配置文件所需的 CMake 的最低版本；
cmake_minimum_required (VERSION 2.8)

#项目的名称是 Demo1
project (Demo1)

#将名为 main.cc 的源文件编译成一个名称为 Demo 的可执行文件
add_executable (Demo main.cc)