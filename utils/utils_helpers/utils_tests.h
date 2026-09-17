#ifndef UTILS_TESTS_H
#define UTILS_TESTS_H

#include "../utils_tools/utils_tools.h"

using namespace utils;

static_assert(bufferSize(64, 4) == 256);
static_assert(bufferSize(2, 1) == 8);
static_assert(bufferSize(500, 10) == 512);

#endif