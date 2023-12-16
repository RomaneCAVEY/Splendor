#include <assert.h>
#include <stdio.h>

#include "builder.h"

struct builder_t {
  unsigned int points;
  unsigned int level;
  struct set_t provide;
  struct set_t require;
};

static struct builder_t builders[MAX_BUILDERS];

void init_builders(unsigned int seed)
{
  (void) seed;

  unsigned int blue2[NUM_COLORS] = { 0, 2 };
  unsigned int black2[NUM_COLORS] = { 2, 0 };
  unsigned int blue3[NUM_COLORS] = { 0, 3 };
  unsigned int black3[NUM_COLORS] = { 3, 0 };
  unsigned int blue5[NUM_COLORS] = { 0, 5 };
  unsigned int black5[NUM_COLORS] = { 5, 0 };

  builders[0] =
    (struct builder_t){ .points = 1,
                        .level = 0,
                        .provide = create_simple_set(BLACK),
                        .require = create_complex_set(blue3) };
  builders[1] =
    (struct builder_t){ .points = 1,
                        .level = 0,
                        .provide = create_simple_set(BLUE),
                        .require = create_complex_set(black3) };
  builders[2] =
    (struct builder_t){ .points = 1,
                        .level = 0,
                        .provide = create_simple_set(BLACK),
                        .require = create_complex_set(blue3) };
  builders[3] =
    (struct builder_t){ .points = 1,
                        .level = 0,
                        .provide = create_simple_set(BLUE),
                        .require = create_complex_set(black3) };
#if NUM_LEVELS > 1
  builders[4] =
    (struct builder_t){ .points = 2,
                        .level = 1,
                        .provide = create_complex_set(black2),
                        .require = create_complex_set(blue5) };
  builders[5] =
    (struct builder_t){ .points = 2,
                        .level = 0,
                        .provide = create_complex_set(blue2),
                        .require = create_complex_set(black5) };
#else
  builders[4] =
    (struct builder_t){ .points = 2,
                        .level = 1,
                        .provide = create_complex_set(black2),
                        .require = create_complex_set(blue5) };
  builders[5] =
    (struct builder_t){ .points = 2,
                        .level = 0,
                        .provide = create_complex_set(blue2),
                        .require = create_complex_set(black5) };
#endif
}

unsigned int num_builders()
{
  int effective_builders = 6;
  return effective_builders <= MAX_BUILDERS ? effective_builders : MAX_BUILDERS;
}

struct builder_t *make_builder(unsigned int index)
{
	assert(index <= num_builders());
	return &builders[index];
}

unsigned int builder_level(const struct builder_t *g)
{
	return g->level;
}

unsigned int builder_points(const struct builder_t *g)
{
	return g->points;
}

struct set_t builder_requires(const struct builder_t *g)
{
	return g->require;
}

struct set_t builder_provides(const struct builder_t *g)
{
	return g->provide;
}

void builder_display(const struct builder_t *g, const char *prefix)
{
	printf("%sC(level=%d, points=%d, require=", prefix, g->level,
	       g->points);
	printf(", provide=");
	printf(")\n");
}
