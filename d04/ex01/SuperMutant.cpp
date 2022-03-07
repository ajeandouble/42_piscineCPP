#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me wants smash head!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaaargh" << std::endl;
}

SuperMutant &SuperMutant::operator=(const SuperMutant &s)
{
	this->_hp = s.getHP();
	this->_type = s.getType();
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	if (damage <= 0)
		return ;
	this->_hp -= damage - 3;
	if (this->_hp <= 0)
		this->_hp = 0;
}
