#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include "Pony.hpp"

tm	    Pony::getBirthDate()
{
	return	(this->birthDate);
}

bool    Pony::setBirthDate(std::string birthDate)
{
	std::regex	txt_regex("(0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[01])[- /.](19|20)[0-9]{2}");
	std::cout << "Insert date of birth (mm/dd/yy) :\t";
	if (std::regex_match(birthDate, txt_regex))
	{
		std::cerr << "ok\n";
		int	month = std::stoi(birthDate.substr(0, 2));
		int	day = std::stoi(birthDate.substr(3, 2));
		int	year = std::stoi(birthDate.substr(6, 4));
		this->birthDate.tm_mon = month;
		this->birthDate.tm_mday = day;
		this->birthDate.tm_year = year;
		return (true);
	}
	else
		std::cout << "bad\n";
	return (false);
}

bool	Pony::setName(std::string name)
{
	this->name = name;
	return (true);
}

Pony::Pony() = default;

Pony::~Pony()
{
}
