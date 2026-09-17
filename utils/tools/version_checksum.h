#ifndef VERSION_CHECKSUM_H
#define VERSION_CHECKSUM_H

#include <cstdint>
#include <limits>

namespace utils
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

	constexpr std::uint32_t versionChecksum(int major, int minor, int patch)
	{
		const auto clampedMajor{ clamp8BitInt(major) };
		const auto clampedMinor{ clamp8BitInt(minor) };
		const auto clampedPatch{ clamp8BitInt(patch) };

		std::uint32_t version{ 0b0000'0000'0000'0000'0000'0000'0000'0000 };

		return version | clampedPatch | (clampedMinor << 8) | (clampedMajor << 16);
	}

	constexpr std::uint8_t getMajorVersion(std::uint32_t version)
	{
		constexpr std::uint32_t majorMask{ 0b0000'0000'1111'1111'0000'0000'0000'0000 };

		return static_cast<std::uint8_t>((version & majorMask) >> 16);
	}

	constexpr std::uint8_t getMinorVersion(std::uint32_t version)
	{
		constexpr std::uint32_t minorMask{ 0b0000'0000'0000'0000'1111'1111'0000'0000 };

		return static_cast<std::uint8_t>((version & minorMask) >> 8);
	}

	constexpr std::uint8_t getPatchVersion(std::uint32_t version)
	{
		constexpr std::uint32_t patchMask{ 0b0000'0000'0000'0000'0000'0000'1111'1111 };

		return static_cast<std::uint8_t>(version & patchMask);
	}
}

#endif