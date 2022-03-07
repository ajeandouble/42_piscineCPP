#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &p)
{
	this->_name = p.getName();
	this->_apcost = p.getAPCost();
	this->_damage = p.getDamage();
	return (*this);
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuuu piouuu piouuu *" << std::endl;
}
