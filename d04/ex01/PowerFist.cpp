#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(const PowerFist &p)
{
	this->_name = p.getName();
	this->_apcost = p.getAPCost();
	this->_damage = p.getDamage();
	return (*this);
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}


