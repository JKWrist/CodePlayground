#!/usr/bin/env python3

class HouseItem:
	def __init__(self, name, area):
		self.name = name
		self.area = area

	def __str__(self):
		return "名字:%s 面积:%.2f" % (self.name, self.area)

class House:
	def __init__(self, host_type, area):
		self.hose_type = host_type
		self.area = area
		self.freearea = area
		self.item_list = []

	def __str__(self):
		return ("户型:%s 面积:%.2f 剩余面积:%.2f 家具:%s" 
				% (self.hose_type, 
					self.area, self.freearea, self.item_list))
	def add_item(self, item):
		print("要添加 %s" % item)
		# 1 判断家具面积
		if self.freearea < item.area:
			print("%s 的面积太大了无法添加" % item.name)
			return
		# 2 将家具面积添加到列表中
		self.item_list.append(item.name)
		# 3 计算剩余面积
		self.freearea -= item.area
		

bed   = HouseItem("床", 40)
chest = HouseItem("衣柜", 42)
table = HouseItem("餐桌", 1.5)

print(bed)
print(chest)
print(table)

h1 = House("三室一厅", 80)
h1.add_item(bed)
h1.add_item(chest)
h1.add_item(table)
print(h1)