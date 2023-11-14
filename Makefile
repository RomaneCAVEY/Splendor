NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS) -Isrc -Itst
BUILD_DIR = ./build

all: project
tests: test_token_use test_token

%.o: %.c
	echo compiling $< into $@
	$(CC) $(CFLAGS) -c $< -o $@

project: src/project.o src/color.o src/manipulation.o src/token.o
	$(CC) $(CFLAGS) $^ -o project

test_token_use: tst/test_token_use.o src/token.o src/color.o src/manipulation.o
	$(CC) $(CFLAGS) $^ -o $@

test_project:tst /test_project.o src/color.o src/manipulation.o src/token.o src/game.o src/player.o src/builder.o
	$(CC) $(CFLAGS) test.o -o test_project

token: $src/token.o
	$(CC) $(CFLAGS) token.o -o token

test_token: tst/test_token.o src/manipulation.o src/color.o
	$(CC) $(CFLAGS) $^ -o $@

test_builder: tst/test_builder.o src/builder.o src/token.o src/color.o
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -f project test_project *.o *~
