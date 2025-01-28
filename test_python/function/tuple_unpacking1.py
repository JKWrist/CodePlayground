#!/usr/bin/env python3

a, b ,*c, d = (4, 5, 6, 7, 8, 9)
print("1111", a, b, c, d)

a, b ,*c, d = [4, 5, 6, 7, 8, 9]
print("1112", a, b, c, d)

a, b ,*c, d = '123456789'
print("1113", a, b, c, d)

a, b ,*c, d = range(10)
print(type(range(1)))
print("1114", a, b, c, d)

a, *b = {'a' : 1, 'b' : 2, 'c' : 3}
print("1115", a, b)

a, *b = {'a' : 1, 'b' : 2, 'c' : 3}.values()
print("1116", a, b)

a, *b = {'a' : 1, 'b' : 2, 'c' : 3}.items()
print("1116", a, b)