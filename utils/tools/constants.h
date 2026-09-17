#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>

namespace constants
{
	constexpr std::uint8_t minBufferSize{ 8 };
	constexpr std::uint16_t maxBufferSize{ 512 };

	constexpr std::uint8_t minVersion{ 1 };
	constexpr std::uint32_t maxVersion{ 0xFFFFFF };

	constexpr std::uint8_t minMajorVersion{ 1 };
	constexpr std::uint8_t minMinorVersion{ 0 };
	constexpr std::uint8_t minPatchVersion{ 0 };
}

#endif