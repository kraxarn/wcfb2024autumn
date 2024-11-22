#include <iostream>
#include <ostream>
#include <ranges>
#include <unordered_map>

namespace
{
	auto is_possible(const std::string &str) -> bool
	{
		std::unordered_map<char, uint32_t> chars;

		for (const char &chr: str)
		{
			if (chars.contains(chr))
			{
				chars.at(chr)++;
			} else
			{
				chars.insert({chr, 1});
			}
		}

		int count = 0;

		for (const uint32_t chr_count: chars | std::views::values)
		{
			if (chr_count % 2 == 1)
			{
				count++;
			}

			if (count > 1)
			{
				return false;
			}
		}

		return true;
	}

	void swap(std::string &str, const size_t idx1, const size_t idx2)
	{
		const char tmp = str.at(idx1);
		str.at(idx1) = str.at(idx2);
		str.at(idx2) = tmp;
	}
}

auto main() -> int
{
	int value;
	std::cin >> value;
	std::cin.ignore();

	for (auto i = 0; i < value; i++)
	{
		auto swaps = 0;

		std::string line;
		std::getline(std::cin, line);

		if (!is_possible(line))
		{
			std::cout << "Impossible\n";
			continue;
		}

		size_t l_idx = 0;
		size_t r_idx = line.size() - 1;

		while (l_idx < r_idx)
		{
			if (line.at(l_idx) == line.at(r_idx))
			{
				l_idx++;
				r_idx--;
				continue;
			}

			const size_t find_idx = line.rfind(line.at(l_idx), r_idx);
			if (find_idx == l_idx)
			{
				swap(line, l_idx, l_idx + 1);
				swaps++;
				continue;
			}

			for (size_t swp_idx = find_idx; swp_idx < r_idx; swp_idx++)
			{
				swap(line, swp_idx, swp_idx + 1);
				swaps++;
			}

			l_idx++;
			r_idx--;
		}

		std::cout << swaps << '\n';
	}

	return 0;
}
