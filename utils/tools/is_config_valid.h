#ifndef IS_CONFIG_VALID_H
#define IS_CONFIG_VALID_H

#include "constants.h"
#include "buffer_size.h"
#include "version_checksum.h"
#include <cstdint>

namespace utils
{
	constexpr bool isConfigValid(std::uint16_t bufferSize, std::uint32_t version)
	{
		using namespace constants;

		return (
			((bufferSize >= minBufferSize) && (bufferSize <= maxBufferSize))
			&& ((version >= minVersion) && (version <= maxVersion))
			);
	}

	constexpr bool isConfigValid(int baseUnit, int scaleFactor, std::uint32_t version)
	{
		return isConfigValid(bufferSize(baseUnit, scaleFactor), version);
	}

	constexpr bool isConfigValid(std::uint16_t bufferSize, int major, int minor, int patch)
	{
		return isConfigValid(bufferSize, versionChecksum(major, minor, patch));
	}
}

#endif