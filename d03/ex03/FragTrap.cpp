#include "FragTrap.hpp"

#include <iostream>
#include <random>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cerr << "FragTrap constructor has been called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cerr << "FragTrap destructor has been called" << std::endl;	
}

void FragTrap::rangedAttack(std::string const &target)
{;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing ";
	std::cout << this->_ranged_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " melee-style, causing ";
	std::cout << this->_melee_attack_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(int amount)
{
	if (amount <= 0)
		return ;
	amount -= this->_armor_damage_reduction;
	if (amount <= 0)
	{
		std::cout << this->_name << " takes no damage, leaving him with still ";
		std::cout << this->_hit_points << " HP." << std::endl;
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

void FragTrap::beRepaired(int amount)
{
	if (amount <= 0)
		return ;
	std::cout << this->_name << " gets healed with " << amount << " energy points." << std::endl;
	if (this->_energy_points + amount >= 100)
		this->_energy_points = 100;
	else
		this->_energy_points += amount;
	std::cout << this->_name << " has now " << this->_energy_points << " HP." << std::endl;
}

void FragTrap::_funny1(std::string const &target)
{	
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with a sausage, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;    
}

void FragTrap::_funny2(std::string const &target)
{	
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with a teapot, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;    
}

void FragTrap::_funny3(std::string const &target)
{	
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with a matches box, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;    
}

void FragTrap::_funny4(std::string const &target)
{	
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with a sock, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;    
}

void FragTrap::_funny5(std::string const &target)
{	
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with a phonebook, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;    
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	void (FragTrap::*fptrs[])(std::string const &) =
	{
		&FragTrap::_funny1,
		&FragTrap::_funny2,
		&FragTrap::_funny3,
		&FragTrap::_funny4,
		&FragTrap::_funny5,
	};
	int	r = this->_random(0, (sizeof(fptrs) / sizeof(fptrs[0])) - 1);
	(this->*fptrs[r])(target);
}

std::string	FragTrap::getName()
{
	return (this->_name);
}
