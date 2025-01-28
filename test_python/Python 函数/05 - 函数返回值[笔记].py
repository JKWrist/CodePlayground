

''' 函数的返回值, 就是调用函数后获取到的结果 '''
def get_max_value(a, b):
    # 下边 3 行 if 代码可以简写成一行: max_value = a if a > b else b
    max_value = a
    if b > a:
        max_value = b
    # 定义函数时, 用 return 关键字返回结果
    return max_value
# 调用带有返回值的函数, 可以用变量接收函数的返回值
n = get_max_value(6, 8)  # n = 8
print(f"n = {n}")
# 当然, 如果不接收返回值也不会报错, 是否需要接收根据代码的功能需求决定
get_max_value(12, 19)

''' if 语句在某些情况下可以简写 '''
a = 5
b = 12
# 如果 a > b, 那么 c = a; 否则 c = b
c = a if a > b else b
# 上边一行就相当于下边的 if 语句
if a > b:
    c = a
else:
    c = b

''' 没有返回值, 定义函数时可以不写 return 或者 return None '''
# 函数如果没有返回值, 就不需要写 return
def print_something():
    print("HOHO~")
# 调用没有返回值的函数, 就不能接收函数的值, 只能直接调用
print_something()
# 如果硬要接收返回值, 会得到一个 None 值, 也就是 "空" 的意思
v = print_something()  # v = None, 也就是 v 没有任何值, 是空的
print(f"v = {v}")  # 显示出来的 v 的值是空, None
# 这就和我们要接收 print() 函数的值一样
m = print("python")  # m = None
# print() 函数的作用是在控制台上显示指定内容, 但函数本身没有返回值
# 所以强制接收它的值, 得到的是 None
print(f"m = {m}")  # 变量 m 的值是空, None
# 在定义函数时, 也可以使用 return None 表示函数没有返回值
def say_something():
    print("Hello!")
    # return None 也是没有返回值的意思
    return None
# 或者直接一个 return 也表示没有返回值
def say_Hi():
    print("Hi")
    # 只写一个 return 后边没有任何值, 也是没有返回值
    return

''' 函数也可以同时返回多个值 '''
def func(a, b):
    # 多个返回值依次写在 return 后边, 中间用逗号隔开
    return a + b, a - b, a * b
# 调用函数时, 可以使用相同数量的变量接收返回值
x, y, z = func(4, 8)
print(f"x = {x}, y = {y}, z = {z}")
# 或者只用 1 个变量接收多个返回值, 此时变量会是元组类型, 返回值是里面的元素
t = func(12, 7)
print(f"t 的类型是 {type(t)}, t = {t}")
# 除此以外, 如果接收的变量和返回值数量不同, 会报错
# 这行代码报错, 是因为函数有 3 个返回值, 但是只有两个变量接收
# x, y = func(4, 6)

''' return 也可以用来提前结束整个函数 '''
# 定义一个函数, 参数是用户的年龄
def your_age(age):
    if type(age) != int:
        # 判断参数 age 是否是整数类型
        print("你输入的不是整数")
        # 如果不是整数类型, 直接 return 结束整个函数
        return
    elif age < 0:
        # 判断参数 age 是否是负数
        print("年龄不能为负数")
        # 如果是负数, 也会直接 return 结束整个函数
        return
    # 如果程序能执行到这, 说明前边没有执行过 return 所以参数是正常的
    print(f"你今年 {age} 岁啦")
# 调用三次, 分别使用不同的参数
your_age("Hello")
your_age(-15)
your_age(18)
