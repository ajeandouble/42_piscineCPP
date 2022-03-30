#include <iostream>
#include <exception>
#include <array>

int	main()
{
	std::array<int, 12> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	std::cout << easyfind(arr, 10) << std::endl;
	try {
		std::cout << easyfind(arr, -0x2a) << std::endl;
	} catch(std::exception e) {}
	
	return (0);
}