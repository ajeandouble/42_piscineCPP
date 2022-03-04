#include <iostream>
#include "Human.hpp"

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "You use melee Attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const &target)
{
	std::cout << "You use ranged Attack on " << target << std::endl;
}

void	Human::intimidatingAttack(std::string const &target)
{
	std::cout << "You use intimidating Attack on " << target << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	std::string actions[] =
	{
		"meleeAttack",
		"rangedAttack",
		"intimidatingAttack"
	};
	void	(Human::*action_ptr[])(std::string const &) =
	{
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingAttack
	};
	for (size_t i = 0; i < (sizeof(actions) / sizeof(actions[0])); ++i)
	{
		if (actions[i] == action_name)
			(this->*action_ptr[i])(target);
	}
}
