
#include "Sorcerer.hpp"

#include <iostream>

Sorcerer::Sorcerer(std::string name, std::string title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
	this->_name = name;
	this->_title = title;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &rhs)
{
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return	*this;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
	return (this->_name);
}

std::string Sorcerer::getTitle() const
{
	return (this->_title);
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &s)
{
	os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;
	return	(os);
}

void Sorcerer::polymorph(Victim const &v)
{
	v.getPolymorphed();
}

void Sorcerer::polymorph(Peon const &p)
{
	p.getPolymorphed();
}
