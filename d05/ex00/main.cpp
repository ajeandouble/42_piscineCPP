#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat jim = Bureaucrat("Jim", 150);
	try {
		jim.incGrade();
	}
	catch (std::exception const &e)
	{
		std::cout << jim << std::endl;
		std::cout << e.what() << std::endl;
	}
	Bureaucrat bob = Bureaucrat("Bob", 1);
	try {
		bob.decGrade();
	}
	catch (std::exception const &e)
	{
		std::cout << bob << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat eva = Bureaucrat("Eva", -12);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
