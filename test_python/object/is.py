#!/usr/bin/env python3

a = [1, 2, 3]
print(id(a))

b = [1,2]
print(id(b))

b.append(3)

# 判断两个对象的内存地址是否一致
print(a is b)

print(a == b)