#ifndef TESTS_H
#define TESTS_H

#include "../tools/buffer_size.h"

static_assert(utils::bufferSize(64, 4) == 256);
static_assert(utils::bufferSize(2, 1) == 8);
static_assert(utils::bufferSize(500, 10) == 512);

#endif