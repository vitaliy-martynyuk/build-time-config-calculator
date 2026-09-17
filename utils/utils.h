#ifndef UTILS_H
#define UTILS_H

#include <cstdint>


namespace utils
{
	constexpr int bufferSize(int baseUnit, int scaleFactor)
	{
		constexpr std::uint8_t minBufferSize{ 8 };
		constexpr std::uint16_t maxBufferSize{ 512 };

		if (baseUnit < 0 || scaleFactor < 0)
			return minBufferSize;

		const std::uint64_t rawSize{
			static_cast<std::uint64_t>(baseUnit)
			* static_cast<std::uint64_t>(scaleFactor) };

		if (rawSize < minBufferSize)
			return static_cast<int>(minBufferSize);

		if (rawSize > maxBufferSize)
			return static_cast<int>(maxBufferSize);

		return static_cast<int>(rawSize);
	}
}

#endif 