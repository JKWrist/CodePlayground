#!/usr/bin/env python3

#列表推导式练习2

#同时找出出现在 l1 和 l2中的元素

l = ['food', 'moon', 'loop']
l2 = []
for i in l:
	l2.append(i[0])

print(l2)

l3 = [j[0] for j in l]
s = "".join(l3)
print(s)