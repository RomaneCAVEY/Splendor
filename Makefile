NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS) -Isrc -Itst
BUILD_DIR = ./build
SRC_DIR = ./src


all: project
test: test_token_use test_display
	./test_token_use
	./test_display

%.o: %.c
	echo compiling $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

project: src/project.o  src/color.o  src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token.o
	$(CC) $(CFLAGS) $^ -o project


token: $src/token.o
	$(CC) $(CFLAGS) token.o -o token

<<<<<<< HEAD
test: tst/test_token.o src/color.o
	$(CC) $(CFLAGS) $^ -o $@

test_builder: tst/test_builder.o src/builder.o src/token.o src/color.o
	$(CC) $(CFLAGS) $^ -o $@
=======
test:tst/test.o tst/test_main.o src/color.o  src/token.o src/game.o src/player.o src/builder.o src/second_builder.o src/second_token.o
	$(CC) $(CFLAGS) $^ -o test

>>>>>>> master


clean:
	rm -f project test_project *.o *~
	rm -f src/*.o *~
	rm -f tst/*.o *~
	rm -f test*
