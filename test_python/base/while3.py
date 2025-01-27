#!/usr/bin/env python3

l = []

i = ""
while i != "q":
	i = input("请输入你的计划， q退出:")
#	if i != "q":
#		l.append(i)
	if i == "q":
		break
	l.append(i)
print(l)
