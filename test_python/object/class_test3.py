#!/usr/bin/env python3

class Gun:
	def __init__(self, model, bullet_count):
		self.model = model
		self.bullet_count = bullet_count
	def add_bullet(self, count):
		self.bullet_count += count
	def shoot(self):
		if self.bullet_count - 5 < 0:
			print("每次要射击至少5发子弹")
			return
		else:
			self.bullet_count -= 5
			print("%d" % self.bullet_count)

g1 = Gun("AK47", 200)
#g1.shoot()
#g1.shoot()

class Soldier:
	def __init__(self, name):
	# 1 姓名
		self.name = name
	# 2 枪   一个对象的属性可以是另一个类创建的对象
		self.gun = None
	def fire(self):
	# 1 判断士兵是否有枪
#		if self.gun == None:
		if self.gun is None:
			print("%s 没有枪" % self.name)
			return
	# 2 高喊口号
		print("冲啊")
	# 3 让枪装子弹
		self.gun.add_bullet(1)
	# 4 让枪发射子弹
		self.gun.shoot()
		

s1 = Soldier("许三多")
s1.gun = g1
s1.fire()
print(s1.gun)
s1.fire()
s1.fire()
s1.fire()
s1.fire()