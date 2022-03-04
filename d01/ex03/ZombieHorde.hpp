# ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include <iostream>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(unsigned int N);
		~ZombieHorde();

	private:
		unsigned int N;
		Zombie *zArray;
		std::string randomChump();
};

# endif
