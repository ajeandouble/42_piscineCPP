#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

#include <string>

class   SuperTrap : public  FragTrap, public NinjaTrap
{
	public:
		SuperTrap(std::string name);
		void    meleeAttack(std::string const &target);
		void    rangedAttack(std::string const &target);
};
