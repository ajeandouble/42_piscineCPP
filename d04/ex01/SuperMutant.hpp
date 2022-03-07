# ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
		/* data */
	public:
		SuperMutant(/* args */);
		~SuperMutant();
		SuperMutant &operator=(const SuperMutant &s);

		void takeDamage(int damage);
};

# endif
