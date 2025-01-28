#!/usr/bin/env python3

# 实现打印一个月的日历功能

# 1 用户输入年月
# 2 根据年月计算每个月多少天
# 3 每个月从周几开始
# 4 逐行打印，周日换行

# 根据年月日计算星期几
def get_week_with_date(y, m, d):
	''' 根据年月日计算星期几 '''
	# 把 1、2 月当做上一年的 13、14 月使用
	y = y - 1 if m == 1 or m == 2 else y
	if m == 1:
		m = 13
	elif m == 2:
		m = 14

	# 使用公式计算出星期几并返回
	w = (d + 2 * m + 3 * (m + 1) // 5 + y + y // 4 - y // 100 + y // 400) % 7 + 1
	return w

def is_leap_year(y):
	if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
		return True
	return False


def days_of_Ferbrary(y):
	if is_leap_year(y):
		return 29
	return 28

def get_days_in_month(y, m):
	if m in [1, 3, 5, 7, 8, 10, 12]:
		return 31
	elif m in [4, 6, 9, 11]:
		return 31
	else:
		return days_of_Ferbrary(y)
		
	
# 1 用户输入年月
#year = int(input("请输入年份:"))
#mon  = int(input("请输入月份:"))

year = 2025
mon  = 1
day  = 28

# 2 根据月日计算要打印多少天
days = get_days_in_month(year, mon)

# 3 每个月从周几开始
print("一  二  三  四 五 六  日")
print("="*7*3) 

for i in range(1, days + 1):
	w = get_week_with_date(year, mon, i)
	if 1 == i:
		print(" "*(w-1)*3, end="") 
	else:
		if 1 == w:
			print("")
	print(f"{i:3d}", end="")

#print(get_days_in_month(year, mon))

# 4 逐行打印，周日换行