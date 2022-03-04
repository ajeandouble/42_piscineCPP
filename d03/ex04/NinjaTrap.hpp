# ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class NinjaTrap : protected ClapTrap
{
	public:
		NinjaTrap(std::string name);
		~NinjaTrap();
		void ninjaShoeBox(FragTrap &trap);
		void ninjaShoeBox(ScavTrap &trap);
		void ninjaShoeBox(NinjaTrap &trap);
		void    takeDamage(int amount);
		std::string	getName();
};

# endif
