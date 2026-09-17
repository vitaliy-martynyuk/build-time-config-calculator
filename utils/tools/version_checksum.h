#ifndef VERSION_CHECKSUM_H
#define VERSION_CHECKSUM_H

#include "internal_utils.h"
#include <cstdint>

namespace utils
{
	constexpr std::uint32_t versionChecksum(int major, int minor, int patch)
	{
		using namespace utils::internal;

		const auto clampedMajor{ clamp8BitInt(major) };
		const auto clampedMinor{ clamp8BitInt(minor) };
		const auto clampedPatch{ clamp8BitInt(patch) };

		constexpr std::uint32_t version{ 0b0000'0000'0000'0000'0000'0000'0000'0000 };

		return version | clampedPatch | (clampedMinor << 8) | (clampedMajor << 16);
	}

	template <int MAJOR, int MINOR, int PATCH>
	consteval std::uint32_t vversionChecksum()
	{
		return versionChecksum(MAJOR, MINOR, PATCH);
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