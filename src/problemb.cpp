#include <iostream>
#include <ostream>

auto main() -> int
{
	int num_kings;
	int num_queens;
	int num_rooks;
	int num_bishops;
	int num_knights;
	int num_pawns;

	std::cin >> num_kings;
	std::cin >> num_queens;
	std::cin >> num_rooks;
	std::cin >> num_bishops;
	std::cin >> num_knights;
	std::cin >> num_pawns;

	std::cout
		<< 1 - num_kings << ' '
		<< 1 - num_queens << ' '
		<< 2 - num_rooks << ' '
		<< 2 - num_bishops << ' '
		<< 2 - num_knights << ' '
		<< 8 - num_pawns << ' ';

	return 0;
}
