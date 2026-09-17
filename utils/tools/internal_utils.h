#ifndef INTERNAL_UTILS_H
#define INTERNAL_UTILS_H

#include <cstdint>

namespace internal_utils
{
	constexpr std::uint8_t clamp8BitInt(int v)
	{
		constexpr std::uint8_t min{ 0 };
		constexpr std::uint8_t max{ 255 };

		if (v < min)
			return min;

		if (v > max)
			return max;

		return static_cast<std::uint8_t>(v);
	}
}

#endif