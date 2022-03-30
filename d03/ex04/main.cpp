#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	FragTrap ct("Clap");
	SuperTrap st("Hi");
	st.meleeAttack("Target1");
	st.rangedAttack("Target1");
	st.vaulthunter_dot_exe("Target1");
	st.ninjaShoeBox(ct);
	return (0);
}
