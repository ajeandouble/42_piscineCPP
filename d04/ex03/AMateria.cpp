
#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	this->_xp = 0;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &a)
{
	this->_type = a.getType();
	this->_xp = a.getXP();
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

unsigned int	AMateria::getXP() const
{
	return (this->_xp);
}

void	AMateria::use(ICharacter &target)
{
	this->_xp += 10;
}
