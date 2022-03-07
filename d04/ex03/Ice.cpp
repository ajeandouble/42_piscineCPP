#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &ice)
{
	this->_type = ice.getType();
	this->_xp = ice.getXP();
	return (*this);
}

AMateria *Ice::clone() const
{
	Ice *newIce = new Ice();
	return (newIce);
}
