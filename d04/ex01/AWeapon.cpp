
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	this->_name = name;
	this->_apcost = apcost;
	this->_damage = damage;
}

AWeapon::~AWeapon()
{
	
}

AWeapon	&AWeapon::operator=(const AWeapon &aWeapon)
{
	this->_name = aWeapon.getName();
	this->_apcost = aWeapon.getAPCost();
	this->_damage = aWeapon.getDamage();
	return (*this);
}

std::string AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getAPCost() const
{
    return (this->_apcost);
}

int AWeapon::getDamage() const
{
    return (this->_damage);
}
