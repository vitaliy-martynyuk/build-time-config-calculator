#ifndef TESTS_H
#define TESTS_H

#include "../tools/buffer_size.h"
#include "../tools/version_checksum.h"

static_assert(utils::bufferSize(64, 4) == 256);
static_assert(utils::bufferSize(2, 1) == 8);
static_assert(utils::bufferSize(500, 10) == 512);

static_assert(utils::versionChecksum(2, 5, 13) == 0x2050D);
static_assert(utils::getMajorVersion(0x2050D) == 2);
static_assert(utils::getMinorVersion(0x2050D) == 5);
static_assert(utils::getPatchVersion(0x2050D) == 13);

#endif