# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo3)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录, add_subdirectory 指明本项目包含一个子目录 math.
#这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理
add_subdirectory(math)

# 指定生成目标
add_executable(Demo main.cc)

# 添加链接库
# target_link_libraries 指明可执行文件 main 需要连接一个名为 MathFunctions 的链接库
target_link_libraries(Demo MathFunctions)
