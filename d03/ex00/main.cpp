#include <iostream>
#include "FragTrap.hpp"

int main()
{
	{
		FragTrap Yo("Yo");
		Yo.rangedAttack("Tata");
		Yo.meleeAttack("Tata");
		Yo.takeDamage(12);
		Yo.takeDamage(12);
		Yo.takeDamage(12);
		Yo.takeDamage(12);
		Yo.takeDamage(3);
		Yo.beRepaired(3);
		Yo.takeDamage(300);
		Yo.beRepaired(400);
		Yo.vaulthunter_dot_exe("Bla");
	}
	return (0);
}
