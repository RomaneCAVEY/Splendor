NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS) -Isrc -Itst

all: project

%.o: %.c
	echo compiling $< into $@
	$(CC) -c $(CFLAGS) $<

project: project.o
	$(CC) $(CFLAGS) project.o -o project


test_manipulation: tst/test_manipulation.o src/token.o src/color.o src/manipulation.o
	$(CC) $(CFLAGS) test_manipulation.o -o test_manipulation

test_project: test_project.o
	$(CC) $(CFLAGS) test.o -o test_project

token: token.o
	$(CC) $(CFLAGS) token.o -o token

test_token: tst/test_token.o src/manipulation.o
	$(CC) $(CFLAGS) test_token.o -o test_token


clean:
	rm -f project test_project *.o *~
