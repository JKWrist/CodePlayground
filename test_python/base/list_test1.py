#!/usr/bin/env python3

#列表推导式练习1

#获取 ['food', 'moon', 'loop']中每个元素的首字母，并将三个首字母组成一个新的字符串

l = ['food', 'moon', 'loop']
l2 = []
for i in l:
	l2.append(i[0])

print(l2)

l3 = [j[0] for j in l]
s = "".join(l3)
print(s)