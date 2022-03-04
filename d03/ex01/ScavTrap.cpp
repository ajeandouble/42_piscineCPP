#include "ScavTrap.hpp"

#include <iostream>
#include <random>

ScavTrap::ScavTrap(std::string name)
{
	std::cerr << "ScavTrap constructor has been called" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor_damage_reduction = 5;
}

ScavTrap::~ScavTrap()
{
	std::cerr << "ScavTrap destructor has been called" << std::endl;	
}

void ScavTrap::rangedAttack(std::string const &target)
{
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " at range, causing ";
	std::cout << this->_hit_points << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	this->_hit_points = this->_random(0, this->_max_hit_points);
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << " melee-style, causing ";
	if (this->_hit_points == 0)
		std::cout << "no points of damage!" << std::endl;
	else
		std::cout << this->_hit_points << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(int amount)
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

void ScavTrap::beRepaired(int amount)
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

int ScavTrap::_random(int min, int max)
{
	static  std::random_device   rd;
    static std::mt19937    gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return (distr(gen));
}

void ScavTrap::_funny1(std::string const &target)
{	
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with a sausage." << std::endl;
}

void ScavTrap::_funny2(std::string const &target)
{	
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with a teapot." << std::endl;
}

void ScavTrap::_funny3(std::string const &target)
{	
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with a matches box." << std::endl;
}

void ScavTrap::_funny4(std::string const &target)
{
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with a sock." << std::endl;
}

void ScavTrap::_funny5(std::string const &target)
{	
	std::cout << "SC4V-TP " << this->_name << " challenges " << target << " with a riddle." << std::endl;   
}

void ScavTrap::challengeNewcomer(std::string const &target)
{
	void (ScavTrap::*fptrs[])(std::string const &) =
	{
		&ScavTrap::_funny1,
		&ScavTrap::_funny2,
		&ScavTrap::_funny3,
		&ScavTrap::_funny4,
		&ScavTrap::_funny5,
	};
	int	r = this->_random(0, (sizeof(fptrs) / sizeof(fptrs[0])) - 1);
	(this->*fptrs[r])(target);
}
