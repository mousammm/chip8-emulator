CFLAGS=-std=c17 -Wall -Wextra -Werror

all:
	gcc src/main.c src/sdl/sdl.c -o chip8 $(CFLAGS) `pkg-config --cflags --libs sdl2`
