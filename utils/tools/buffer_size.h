#ifndef BUFFER_SIZE_H
#define BUFFER_SIZE_H

#include "constants.h"
#include <cstdint>

namespace utils
{
	constexpr std::uint16_t bufferSize(int baseUnit, int scaleFactor)
	{
		using namespace constants;

		if (baseUnit < 0 || scaleFactor < 0)
			return minBufferSize;

		const std::uint64_t rawSize{
			static_cast<std::uint64_t>(baseUnit)
			* static_cast<std::uint64_t>(scaleFactor) };

		if (rawSize < minBufferSize)
			return static_cast<std::uint16_t>(minBufferSize);

		if (rawSize > maxBufferSize)
			return static_cast<std::uint16_t>(maxBufferSize);

		return static_cast<std::uint16_t>(rawSize);
	}
}

#endif