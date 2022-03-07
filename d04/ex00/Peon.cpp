#include <iostream>
#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	this->_name = Victim::_name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(const Peon &rhs)
{
	this->_name = rhs.getName();
	return	*this;
}

std::string Peon::getName() const
{
	return (this->_name);
}

void Peon::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Peon &p)
{
	os << "I am " << p.getName() << " and I like otters!" << std::endl;
	return (os);
}
