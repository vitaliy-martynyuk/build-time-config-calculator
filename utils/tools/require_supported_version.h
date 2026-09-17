#ifndef REQUIRE_SUPPORTED_VERSION_H
#define REQUIRE_SUPPORTED_VERSION_H

#include "constants.h"
#include "version_checksum.h"
#include <cstdint>

namespace utils
{
	consteval bool requireSupportedVersion(int major, int minor, int patch)
	{
		using namespace constants;

		if (major < minMajorVersion || major > maxMajorVersion)
			return false;

		if (minor < minMinorVersion || minor > maxMinorVersion)
			return false;

		if (patch < minPatchVersion || patch > maxPatchVersion)
			return false;

		return true;
	}
}

#endif