#!/usr/bin/env python3

#列表推导式练习3

#找出同时出现在 l1 和 l2 中的元素
l1 = [1,2,4,5,690,6,7]
l2 = [5,8,9,3,4]

r = [i for i in l1 if i in l2]
print(r)