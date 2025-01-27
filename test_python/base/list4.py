#!/usr/bin/env python3

l1 = [i.upper() for i in "hello"]
print(l1)

l2 = [i.upper() for i in "hello" if "o" != i]
print(l2)