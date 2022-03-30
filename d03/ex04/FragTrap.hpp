# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
	private:
		void    _funny1(std::string const &target);
		void    _funny2(std::string const &target);
		void    _funny3(std::string const &target);
		void    _funny4(std::string const &target);
		void    _funny5(std::string const &target);
	public:
		FragTrap(std::string name);
		~FragTrap();
		void    rangedAttack(std::string const &target);
		void    meleeAttack(std::string const &target);
		void    takeDamage(int amount);
		void    beRepaired(int amout);
		void	vaulthunter_dot_exe(std::string const & target);
		std::string	getName();
};

# endif
