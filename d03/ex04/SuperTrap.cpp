#include <iostream>
#include <iostream>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    std::cout << "Supertrap constructor!" << std::endl;
    std::cout << "Name: " << (this->_name = name) << std::endl;
    std::cout << (this->_hit_points = FragTrap::_hit_points) << std::endl;
    std::cout << (this->_max_hit_points = FragTrap::_max_hit_points) << std::endl;
    std::cout << (this->_energy_points = NinjaTrap::_energy_points) << std::endl;
    std::cout << (this->_max_energy_points = NinjaTrap::_max_energy_points) << std::endl;
    std::cout << (this->_level = 1) << std::endl;
    std::cout << (this->_melee_attack_damage = NinjaTrap::_melee_attack_damage) << std::endl;
    std::cout << (this->_ranged_attack_damage = FragTrap::_ranged_attack_damage) << std::endl;
    std::cout << (this->_armor_damage_reduction = FragTrap::_armor_damage_reduction) << std::endl;
}

void    SuperTrap::meleeAttack(std::string const &target)
{
    NinjaTrap::meleeAttack(target);
}

void    SuperTrap::rangedAttack(std::string const &target)
{
    FragTrap::rangedAttack(target);
}
