#include <iostream>
#include <ostream>

auto main() -> int
{
	std::string value;
	std::getline(std::cin, value);

	std::cout
		<< (value.ends_with("eh?")
			? "Canadian!"
			: "Imposter!")
		<< '\n';

	return 0;
}
