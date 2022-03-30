#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	std::cout << "NinjaTrap constructor" << std::endl;
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor_damage_reduction = 0;
}

void	NinjaTrap::ninjaShoeBox(FragTrap &trap)
{
	std::cout << "Ninja attacks " << trap.getName() << std::endl;
}

void	NinjaTrap::ninjaShoeBox(ScavTrap &trap)
{
	std::cout << "Ninja attacks " << trap.getName() << std::endl;
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap &trap)
{
	std::cout << "Ninja attacks " << trap.getName() << std::endl;
}

std::string	NinjaTrap::getName()
{
	return (this->_name);
}

void	NinjaTrap::takeDamage(int amount)
{
	if (amount <= 0)
		return ;
	amount -= this->_armor_damage_reduction;
	if (amount <= 0)
	{
		std::cout << this->_name << " takes no damage, leaving him with still ";
		std::cout << this->_energy_points << " HP." << std::endl;
	}
	else if ((this->_energy_points - amount) <= 0)
	{
		std::cout << this->_name << " takes " << amount << " points of damage." << std::endl;
		std::cout << this->_name << " is now dead!" << std::endl;
		this->_energy_points = 0;
	}
	else
	{
		std::cout << this->_name << " takes " << amount << " points of damage. Leaving him with ";
		this->_energy_points = this->_energy_points - amount;
		std::cout << this->_energy_points << " HP." << std::endl;
	}
}

void NinjaTrap::rangedAttack(std::string const &target)
{;
	std::cout << "N1NJ4-TP " << this->_name << " attacks " << target << " at range, causing ";
	std::cout << this->_ranged_attack_damage << " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "N1NJ4-TP " << this->_name << " attacks " << target << " melee-style, causing ";
	std::cout << this->_melee_attack_damage << " points of damage!" << std::endl;
}

NinjaTrap::~NinjaTrap() {
	
}