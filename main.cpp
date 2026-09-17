#include "utils/utils.h"
#include <iostream>

int main()
{
	constexpr auto size1{ utils::bufferSize(64, 4) };
	constexpr auto size2{ utils::bufferSize(2, 1) };
	constexpr auto size3{ utils::bufferSize(500, 10) };

	std::cout << size1 << ' ' << size2 << ' ' << size3 << '\n';

	return 0;
}