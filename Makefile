NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS)

all: project

%.o: %.c
	echo compiling $< into $@
	$(CC) -c $(CFLAGS) $<

project: project.o
	$(CC) $(CFLAGS) project.o -o project

test_project: test.o
	$(CC) $(CFLAGS) test.o -o test_project

structure: structure.o
	$(CC) $(CFLAGS) project.o -o project


clean:
	rm -f project test_project *.o *~
