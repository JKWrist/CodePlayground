#!/usr/bin/env python3

#key 不可以重复，会导致异常
d = {}
d1 = {"北京":22, "上海":23, "上海":24}
print(d1)

print("查找")
print(d1["上海"])
print(d1.get("上海" , -1))


print("修改")
d2 = {"北京":22, "上海":23}
d2["北京"] = 50
print(d2)
print(d2.setdefault("北京" , 20))
print(d2)

print("增加")
d3 = {"北京":22, "上海":23}
d3["广州"] = 90
print(d3)
#print(d3.update("重庆", 40))
print(d3)


print("删除")
d4 = {"北京":22, "上海":23}
d4.pop("北京")
#d4.clear()
print(d4)

#获取字典的长度
len(d)

#把字典转换为字符串
str(d2)
print(d2)

#判断指定的key是否包含在字典中
"广州" in d
"广州" not in d