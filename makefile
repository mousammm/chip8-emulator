CFLAGS=-std=c17 -Wall -Wextra -Werror

all:
	gcc chip8.c -o chip8 $(CFLAGS) `pkg-config --cflags --libs sdl2`
