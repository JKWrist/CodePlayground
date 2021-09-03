.PHONY:all

VALUE1 = 111
VALUE2 = 222
V1 = 444 
V2 = 222

all:
ifneq ($(findstring $(VALUE1)$(VALUE2),V1 V2),)
	echo "|||||| right"
endif
	echo 555
