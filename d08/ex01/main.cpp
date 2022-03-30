#include <iostream>
#include "span.hpp"

int	main()
{
	Span test(12);
	try {
		test.shortestSpan();
	} catch(std::exception e)
	{
		std::cerr << e.what() << ": " << typeid(e).name() << std::endl;
	}
	test.addNumber(2147483624);
	test.addNumber(42);

	test.addNumber(2147483641);
	test.addNumber(-1);
	for (int i = 0; i < 4; ++i)
	{
		std::cout << test[i] << std::endl;
	}
	
	
	for (int i = 0; i < 4; ++i)
	{
		std::cout << test[i] << std::endl;
	}try {
		test[7] = 49;
	} catch(std::exception e)
	{
		std::cerr << e.what() << ": " << typeid(e).name() << std::endl;
	}
	std::cout << test.shortestSpan() << ", " << test.longestSpan() << std::endl;
}
