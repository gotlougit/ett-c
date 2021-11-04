SRC_FILES = main.c

CC_FLAGS = -Wall -Wextra -o2 --std=c11 -lm `pkg-config --cflags --libs libnotify`
CC = gcc

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o ett
