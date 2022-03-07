#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &cure)
{
	this->_type = cure.getType();
	this->_xp = cure.getXP();
	return (*this);
}

AMateria *Cure::clone() const
{
	Cure *newCure = new Cure();
	return (newCure);
}
