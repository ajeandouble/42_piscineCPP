#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(/* args */)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaaargh!" << std::endl;
}

ISpaceMarine *TacticalMarine::clone() const
{
	return (new TacticalMarine());
}

void	TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void	TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}
