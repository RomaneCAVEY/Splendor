NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS) -Isrc -Itst
BUILD_DIR = ./build
SRC_DIR = ./src


all: project
test: test_builder test_token_use test_display test_main
	./test_builder
	./test_token_use
	./test_display
	./test_main

%.o: %.c
	echo compiling $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

project: src/project.o  src/color.o  src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token.o
	$(CC) $(CFLAGS) $^ -o project

test_token_use: tst/test_token_use.o src/token.o src/color.o src/second_token
	$(CC) $(CFLAGS) $^ -o $@

test_main: tst/test_main.o src/token.o src/color.o  src/game.o src/player.o src/builder.o src/second_builder.o src/second_token
	$(CC) $(CFLAGS) $^ -o $@

test_display: tst/test_display.o src/color.o src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token
	$(CC) $(CFLAGS) $^ -o $@

token: $src/token.o
	$(CC) $(CFLAGS) token.o -o token

test_builder: tst/test_builder.o src/builder.o src/token.o src/color.o src/second_builder.o src/second_token
	$(CC) $(CFLAGS) $^ -o $@

test_init: tst/test_init.o src/color.o src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token
	$(CC) $(CFLAGS) $^ -o $@



clean:
	rm -f project test_project *.o *~
	rm -f src/*.o *~
	rm -f tst/*.o *~
	rm -f test*
