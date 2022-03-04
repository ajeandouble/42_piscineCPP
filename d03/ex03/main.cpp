#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	{
		ClapTrap CP("CP");
		CP.rangedAttack("Test");
	}
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
	{
		ScavTrap Ya("Yu");
		Ya.rangedAttack("Tata");
		Ya.meleeAttack("Tata");
		Ya.takeDamage(12);
		Ya.takeDamage(12);
		Ya.takeDamage(12);
		Ya.takeDamage(3);
		Ya.beRepaired(3);
		Ya.takeDamage(300);
		Ya.beRepaired(400);
		Ya.challengeNewcomer("Bla");		
	}
	{
		ScavTrap sv("Scav Trap");
		FragTrap ft("FragTrap_whatever_it_is");
		NinjaTrap Nin("Nin");
		NinjaTrap Nin2("Dark ninja");
		Nin.takeDamage(20);
		Nin.ninjaShoeBox(sv);
		Nin.ninjaShoeBox(Nin2);
		Nin.ninjaShoeBox(ft);
	}
	return (0);
}
