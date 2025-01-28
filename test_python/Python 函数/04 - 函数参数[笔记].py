

''' 定义参数, 可以在调用函数时, 向函数体内传递数据 '''
# 首先要在定义函数的括号中, 填写参数名, 不需要指定参数类型
# 这个括号, 叫做参数列表
# 参数名要遵循变量的命名规则
def say_goodbye(user_name):
    # 在函数体内可以使用参数, 就和使用正常的变量一样
    print(f"拜拜{user_name}, 客官下次再来哟~")
# 其次, 在调用函数时, 要在括号内填写具体的值, 给参数赋值
say_goodbye("老王") # 拜拜老王, 客官下次再来哟~

''' 定义函数参数时, 可以定义多个参数 '''
# 根据函数的功能需要, 如果要传递多个数值到函数体内, 可以定义多个参数
# 参数名之间用逗号隔开就好
# 这个函数 print_sum 作用是计算并显示两个数的和, 有两个参数 a 和 b
def print_sum(a, b):
    print(f"a + b = {a + b}")
# 在调用函数时, 也要写两个值, 分别赋值给参数 a 和 b
# 此时在函数体内, 参数 a = 10, 参数 b = 25
print_sum(10, 25)   # 35
# 如果参数值反过来赋值, 那么在函数体内, 参数 a = 25, 参数 b = 10
# 也就是说, 调用函数时, 给定的值是按照顺序, 依次给所有参数赋值的
print_sum(25, 10)   # 35

''' 定义函数参数时可以指定参数类型 '''
# 在参数列表中, 参数名后加冒号, 然后填写这个参数的类型
def split_with_space(user_name: str):
    # 指定了类型, 在函数体内就会有代码提示了, 可以提示字符串的 split 方法
    l = user_name.split(" ")
    print(f"使用空格分割字符串: {l}")
# 调用函数时, 和普通函数没有任何区别
split_with_space("北京 上海 广州 深圳 成都 杭州")

''' 但是要注意!!! 哪怕定义函数时指定了类型, 在调用时也可以用其它类型的参数值 '''
# 定义一个函数进行整数加法运算
# 在此, 参数列表中指定的参数 a 和 b 的类型为整数 int
def add_int(a: int, b: int):
    print(f"a + b = {a + b}")
# 调用时, 可以给两个整数
add_int(5, 9)   # 14
# 调用时, 也可以给两个小数
add_int(5.6, 9.8)   # 15.4
# 调用时, 甚至可以给两个字符串
add_int("Hello", "world")   # Helloworld
# 也就是说, 指定参数类型, 对调用是没有限制的, 只不过可以在函数体内有代码提示

''' 可以使用文档注释, 说明函数的功能, 以及参数和返回值的作用 '''
def func(a, b):
    '''
    func() 函数的功能是...

    参数 a: ...

    参数 b: ...

    返回值: ...
    '''
    pass
