#ifndef TESTS_H
#define TESTS_H

#include "../tools/constants.h"
#include "../tools/buffer_size.h"
#include "../tools/version_checksum.h"
#include "../tools/is_config_valid.h"

static_assert(utils::bufferSize(64, 4) == 256);
static_assert(utils::bufferSize(2, 1) == 8);
static_assert(utils::bufferSize(500, 10) == 512);

static_assert(utils::versionChecksum(2, 5, 13) == 0x2050D);
static_assert(utils::getMajorVersion(0x2050D) == 2);
static_assert(utils::getMinorVersion(0x2050D) == 5);
static_assert(utils::getPatchVersion(0x2050D) == 13);

static_assert(!utils::isConfigValid(0, 0));
static_assert(utils::isConfigValid(constants::minBufferSize, constants::minVersion));
static_assert(utils::isConfigValid(constants::maxBufferSize, constants::maxVersion));
static_assert(!utils::isConfigValid(constants::maxBufferSize + 1, constants::maxVersion + 1));

#endif