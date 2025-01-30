#!/usr/bin/env python3

#类方法

class Tool(object):
	count = 0
	# 此处和C++的静态函数类似，可以访问类属性
	@classmethod
	def show_tool_count(cls):
		print("工具对象的数量 %d" % cls.count)
	def __init__(self):
		# 类的属性值 +1
		Tool.count += 1 
		
t1 = Tool()
t2 = Tool()
t3 = Tool()

Tool.show_tool_count()