#!/usr/bin/env python3

# count 是类属性，用来记录和类相关的特征
# 不会用记录和具体对象的特征

class Tool(object):
	count = 0
	def __init__(self):
		# 类的属性值 +1
		Tool.count += 1 # 此处和C++的静态成员变量类似
		

t1 = Tool()
t2 = Tool()

t2 = Tool()
t2 = Tool()

print(Tool.count)

#读取属性值 向上查找
#print(t2.count) #不推荐使用这种方式

t3 = Tool()
#设置属性值
t3.count = 99
print(t3.count)