# ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		void    setZombieType(Zombie &z, std::string type);
		Zombie  *newZombie(std::string name);
};

#endif
