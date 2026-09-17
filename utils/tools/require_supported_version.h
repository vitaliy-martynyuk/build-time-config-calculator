#ifndef REQUIRE_SUPPORTED_VERSION_H
#define REQUIRE_SUPPORTED_VERSION_H

#include "constants.h"
#include "version_checksum.h"
#include <cstdint>
#include <cassert>

namespace utils
{
	consteval void requireSupportedVersion(int major, int minor, int patch)
	{
		using namespace constants;

		const bool isVersionValid{ versionChecksum(major, minor, patch)
			>= versionChecksum(minMajorVersion, minMinorVersion, minPatchVersion) };

		assert(isVersionValid && "min build version is 2.0.0");
	}
}

#endif