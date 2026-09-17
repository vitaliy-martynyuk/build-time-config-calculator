#ifndef IS_CONFIG_VALID_H
#define IS_CONFIG_VALID_H

#include "constants.h"
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
}

#endif