#include "utils/utils.h"
#include <iostream>
#include <iomanip>

int main()
{
	constexpr auto size1{ utils::bufferSize(64, 4) };
	constexpr auto size2{ utils::bufferSize(2, 1) };
	constexpr auto size3{ utils::bufferSize(500, 10) };
	constexpr auto ver1{ utils::versionChecksum(2, 5, 13) };
	constexpr auto majorVer1{ utils::getMajorVersion(ver1) };
	constexpr auto minorVer1{ utils::getMinorVersion(ver1) };
	constexpr auto patchVer1{ utils::getPatchVersion(ver1) };

	std::cout << size1 << ' ' << size2 << ' ' << size3 << '\n';
	std::cout << ver1 << '\n';
	std::cout << static_cast<int>(majorVer1) << '\n';
	std::cout << static_cast<int>(minorVer1) << '\n';
	std::cout << static_cast<int>(patchVer1) << '\n';

	return 0;
}