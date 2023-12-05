NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 -O0 $(MUNIFICENCE_FLAGS) -Isrc -Itst
BUILD_DIR = ./build
SRC_DIR = ./src


all: project
	./project

%.o: %.c
	echo compiling $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

project: src/project.o  src/color.o  src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token.o src/market.o src/guild.o src/stack.o src/permutation.o
	$(CC) $(CFLAGS) $^ -o project


token: $src/token.o
	$(CC) $(CFLAGS) token.o -o token

test:tst/test.o tst/test_main.o src/color.o  src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token.o src/market.o src/guild.o src/stack.o
	$(CC) $(CFLAGS) $^ -o test
	./test



clean:
	rm -f project test_project *.o *~
	rm -f src/*.o *~
	rm -f tst/*.o *~
	rm -f test*
