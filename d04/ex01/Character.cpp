#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name)
{
	this->_name = name;
	this->_ap = 40;
	this->_aweapon = nullptr;
	this->_enemy = nullptr;
}

Character::~Character()
{
}

Character &Character::operator=(const Character &c)
{
	this->_name = c.getName();
	this->_ap = c.getAPCost();
	this->_aweapon = c.getAWeapon();
	return (*this);
}

std::string Character::getName() const
{
	return (this->_name);
}

int	Character::getAPCost() const
{
	return (this->_ap);
}

int	Character::getHP() const
{
	return (this->_hp);
}

AWeapon *Character::getAWeapon() const
{
	return (this->_aweapon);
}

void Character::recoverAP()
{
	if (this->_ap + 10 < 40)
		this->_ap += 10;
}

void Character::equip(AWeapon *aweapon)
{
	this->_aweapon = aweapon;
}

void Character::attack(Enemy *enemy)
{
	this->_ap -= this->_aweapon->getAPCost();
	if (this->_ap <= 0 || !this->_aweapon)
	{
		if (this->_ap < 0)
			this->_ap = 0;
		return ;
	}
	enemy->takeDamage(this->_aweapon->getDamage());
	std::cout << this->_name << " attacks " << enemy->getType();
	std::cout << " with a weapon " << this->_aweapon->getName() << std::endl;
	this->_aweapon->attack();
}

std::ostream &operator<<(std::ostream &os, const Character &c)
{
	if (c.getAWeapon())
	{
		os << c.getName() << " has number " << c.getAPCost();
		os << " AP and wields a " << c.getAWeapon()->getName() << std::endl;
	}
	else
		os << c.getName() << " has number " << c.getAPCost() << " AP and his unarmed" << std::endl;
	return (os);
}
