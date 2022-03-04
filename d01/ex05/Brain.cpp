#include <iostream>
#include <sstream>
#include "Brain.hpp"

std::string	Brain::identify()
{
	std::stringstream ss;
	ss << std::hex << this;
	std::string addr(ss.str());
	return (addr);
}
