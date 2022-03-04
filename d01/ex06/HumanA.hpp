# ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
        Weapon *w;
	public:
		HumanA(std::string name);
		HumanA(std::string name, Weapon &w);
        void    setWeapon(Weapon &w);
        void    attack();
};

# endif
