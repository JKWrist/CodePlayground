#!/usr/bin/env python3

#提示用户输入5个数，组成一个列表
sum = 0

l = []
for i in range(5):
	num = input(f"请输入第{i + 1}个数:")
	num = int(num)
	sum += num
	l.append(num)
	

print(f"输入的5个数是:{l}")
print(f"和是:{sum}")
