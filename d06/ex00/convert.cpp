#include <iostream>
#include <string>
#include <limits>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << "number" << std::endl;
		return (0);
	}

	std::string	number(av[1]);
	long double	d;
	// if (number == "-inff")
	// 	d = -1 * static_cast<double>(std::numeric_limits<float>::infinity());
	// else if (number == "inff")
	// 	d = static_cast<double>(std::numeric_limits<float>::infinity());
	// else if (number == "-inf")
	// 	d = -1 * static_cast<double>(std::numeric_limits<double>::infinity());
	// else if (number == "inf")
	// 	d = static_cast<double>(std::numeric_limits<double>::infinity());
	try {
		size_t	i;
		d = std::stod(number, &i);
		// std::cout << "i=" << i << " " << number.length() << std::endl;
		if (i != number.length())
			throw std::exception();
	}
	catch (std::exception e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (-1);
	}
	// char conversion
	if (int(d) != d)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint((char)d))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << (char)d << std::endl;

	// int conversion
	if (
			int(d) != d
			|| static_cast<double>(std::numeric_limits<int>::max()) < d
			|| static_cast<double>(std::numeric_limits<int>::min()) > d
		)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int(d) << std::endl;

	// float conversion
	if (d == std::numeric_limits<float>::infinity())
		std::cout << "float: inf" << std::endl;
	else if (d == -1 * std::numeric_limits<float>::infinity())
		std::cout << "float: -inf" << std::endl;
	else if (
		static_cast<long double>(std::numeric_limits<float>::max()) < d
		|| static_cast<long double>(std::numeric_limits<float>::min()) > d
	)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << float(d) << "f" << std::endl;

	// double conversion
	if (d == std::numeric_limits<double>::infinity())
		std::cout << "double: inff" << std::endl;
	else if (d == -1 * std::numeric_limits<double>::infinity())
		std::cout << "double: -inff" << std::endl;
	else if (
		static_cast<long double >(std::numeric_limits<long double>::max()) < d
		|| static_cast<long double>(std::numeric_limits<long double>::min()) > d
	)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << double(d) << std::endl;

	return (0);
}
