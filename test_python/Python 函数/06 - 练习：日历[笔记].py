
''' 扩展可以用的特殊符号 (自己复制使用即可):
╔═╦╗ ┏━┳┓
║A║║ ┃B┃┃
╚═╩╝ ┗━┻┛
'''

def get_week_with_date(y, m, d):
    ''' 根据年月日计算星期几 '''
    # 把 1、2 月当做上一年的 13、14 月使用
    y = y - 1 if m == 1 or m == 2 else y
    m = 13 if m == 1 else (14 if m == 2 else m)
    # 使用公式计算出星期几并返回
    w = (d + 2 * m + 3 * (m + 1) // 5 + y + y // 4 - y // 100 + y // 400) % 7 + 1
    return w

def is_leap_year(y):
    ''' 判断一个年份是否是闰年 '''
    if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
        return True
    return False

def get_days_in_month(y, m):
    ''' 获取指定月份的天数 '''
    if m in [1, 3, 5, 7, 8, 10, 12]:
        # 1, 3, 5, 7, 8, 10, 12 月返回 31 天
        return 31
    elif m in [4, 6, 9, 11]:
        # 4, 6, 9, 11 月返回 30 天
        return 30
    else:
        # 2 月返回 29 天 (闰年) 或 28 天 (平年)
        return 29 if is_leap_year(y) else 28

''' 1. 提示用户输入年月 '''
year = int(input("请输入年份: "))
month = int(input("请输入月份: "))

''' 2. 计算这个月有多少天 '''
days = get_days_in_month(year, month)

''' 3. 按照指定格式显示日期 '''
# 显示日历标题
print("一 二 三 四 五 六 日")
print("-" * 20)
# 显示指定月份所有日期
for i in range(1, days + 1):
    # 计算当前日期是星期几
    w = get_week_with_date(year, month, i)
    if i == 1:
        # 在本月第一天打印之前, 用额外的空格进行缩进
        print(f"{' ' * (w - 1) * 3}", end="")
    else:
        if w == 1:
            # 每到周一换行显示
            print("")
    print(f"{i:2d}", end=" ")
# 日历打印完毕后换行
print("")
