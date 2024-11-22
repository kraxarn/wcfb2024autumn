#include <iostream>
#include <ostream>

auto main() -> int
{
	int value;
	std::cin >> value;
	std::cout << ((value + 5) * 3) - 10 << std::endl;
	return 0;
}
