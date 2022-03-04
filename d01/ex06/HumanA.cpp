#include "HumanA.hpp"

HumanA::HumanA(std::string name)
{
	this->name = name;
}

HumanA::HumanA(std::string name, Weapon &w)
{
	this->name = name;
	this->w = &w;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << w->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &w)
{
	this->w = &w;
}

