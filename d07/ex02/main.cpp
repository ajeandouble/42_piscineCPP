#include <iostream>
#include "Array.hpp"

int	main()
{
	Array<int> zero;
	std::cout << zero.size() << std::endl;

	Array<int> two(2);
	std::cout << two.size() << std::endl;
	two[0] = 0x2a;
	two[1] = -0x2a;
	// std::cout << two[0] << ", " << two[1] << std::endl;
	return (0);
}