#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat jim = Bureaucrat("Jim", 150);
	Bureaucrat jim2 = Bureaucrat("Jim2", 12);
	Form f("Form1", 12);
	try
	{
		jim.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	jim2.signForm(f);
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
