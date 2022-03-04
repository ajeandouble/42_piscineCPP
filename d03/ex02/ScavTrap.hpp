# ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	private:
		void    _funny1(std::string const &target);
		void    _funny2(std::string const &target);
		void    _funny3(std::string const &target);
		void    _funny4(std::string const &target);
		void    _funny5(std::string const &target);
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void    rangedAttack(std::string const &target);
		void    meleeAttack(std::string const &target);
		void    takeDamage(int amount);
		void    beRepaired(int amout);
		void	challengeNewcomer(std::string const &target);
};

# endif
