#A = $(B)
#B = $(A)


x := before
y := $(x) bar
x := later
#在终端输入make are you ok cmdgoals
ifeq ("$(MAKECMDGOALS)","are you ok cmdgoals")
who="you"
endif

are:
	@echo "are"
you:
	@echo "you"
ok:
	@echo "ok"
cmdgoals:
	@echo "MAKECMDGOALS:$(MAKECMDGOALS)"
	@echo "who are $(who)"

clean:
	#echo $(A) # 取消注释 *** Recursive variable `A' references itself (eventually).  Stop)
	echo $(x) 
	echo $(y)
