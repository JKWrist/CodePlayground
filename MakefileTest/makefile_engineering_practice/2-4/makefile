.PHONY:all

#DEBUG = true
ifeq ($(DEBUG),tr\"ue)
VERSION = debug
CC = gcc -g
else
VERSION = release
CC = gcc
endif

hello:hello.c
	@echo "111  $(DEBUG)"
#	@echo "222  tr\%ue"
	@echo "build $(VERSION) mode"
	$(CC) -o $@ $^

clean:
	rm hello
