NUM_COLORS ?= 5
NUM_LEVELS ?= 2
NUM_TOKENS ?= 25
MUNIFICENCE_FLAGS = -DNUM_COLORS=$(NUM_COLORS) -DNUM_LEVELS=$(NUM_LEVELS) -DNUM_TOKENS=$(NUM_TOKENS)
CFLAGS = -Wall -Wextra -std=c99 -g3 $(MUNIFICENCE_FLAGS) -Isrc

all: project

%.o: %.c
	echo compiling $< into $@
	$(CC) -c $(CFLAGS) $<

project: project.o
	$(CC) $(CFLAGS) project.o -o project


test_manipulation: tst/test_manipulation.o src/structure.o src/color.o src/manipulation.o
	$(CC) $(CFLAGS) $^ -o test_manipulation

test_project: test_structure.o test_manipulation.o
	$(CC) $(CFLAGS) test.o -o test_project

structure: structure.o
	$(CC) $(CFLAGS) structure.o -o structure

test_structure: tst/test_structure.o src/manipulation.o
	$(CC) $(CFLAGS) test_structure.o -o test_structure


clean:
	rm -f project test_project *.o *~
