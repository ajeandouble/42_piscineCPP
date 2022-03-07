#include <iostream>
#include "Victim.hpp"

Victim::Victim(std::string name)
{
	this->_name = name;
	std::cout << "Some random victim called " << name << " just popped!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(const Victim &rhs)
{
	this->_name = rhs.getName();
	return	*this;
}

std::string Victim::getName() const
{
	return (this->_name);
}

void Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Victim &v)
{
	os << "I am " << v.getName() << " and I like otters!" << std::endl;
	return	(os);
}
