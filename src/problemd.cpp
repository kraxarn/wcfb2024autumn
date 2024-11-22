#include <iostream>
#include <ostream>

auto main() -> int
{
	int value;
	std::cin >> value;

	for (auto i = 0; i < value; i++)
	{
		char dir;
		int diff;
		int hour;
		int minute;

		std::cin >> dir;
		std::cin >> diff;
		std::cin >> hour;
		std::cin >> minute;

		int mod = 0;
		if (dir == 'F')
		{
			mod = 1;
		} else if (dir == 'B')
		{
			mod = -1;
		}

		auto time = ((hour * 60) + minute) + (diff * mod);

		if (time < 0)
		{
			time += 24 * 60;
		}

		std::cout << (time / 60) % 24 << ' ' << time % 60 << '\n';
	}

	return 0;
}
