#!/usr/bin/env python3

class Gamer(object):
	top_score = 0
	def __init__(self, player_name):
		self.player_name = player_name

	@staticmethod
	def show_help():
		print("帮助信息： 1111")

	@classmethod
	def show_top_score(cls):
		print("历史最高分 %d" % cls.top_score)

	def start_game(self):
		print("%s 开始游戏了" % self.player_name)

Gamer.show_help()
Gamer.show_top_score()

g1 = Gamer("xiaobai")
g1.start_game()

