.PHONY:all

VALUE1 = 111
VALUE2 = 222
V1 = 444 
V2 = 222

#此处A要写在上面，写在定义在18行会报错
#A = aaa
#${A}

ifeq ($A, aaa)
V3 = "aaa ($A)"
else ifeq ($A, bbb)
V3 = "bbb"
else ifeq ($A, ccc)
V3 = "ccc"
else
V3 = "ddd ($A)"
endif

ifeq ($(A), "aaa")
V3 = "aaa"
elif ($(A), "bbb")
V3 = "bbb"
elif ($(A), "ccc")
V3 = "ccc"
else
V3 = "ddd"
endif


all:

ifneq ($(findstring $(VALUE1)$(VALUE2),V1 V2),)
	echo "|||||| right"
endif
	echo 555
	echo $(V3)
	
ifeq ($A, aaa)
	echo "aaa ($A)"
else ifeq ($A, bbb)
	echo "bbb"
else ifeq ($A, ccc)
	echo "ccc"
else
	echo "ddd ($A)"
endif

ifeq ($(A), "aaa")
	V3 "aaa"
elif ($(A), "bbb")
	echo "bbb"
elif ($(A), "ccc")
	echo "ccc"
else
	echo "ddd"
endif

