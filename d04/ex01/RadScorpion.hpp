# ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
		/* data */
	public:
		RadScorpion(/* args */);
		~RadScorpion();
		RadScorpion &operator=(RadScorpion const &s);
};

# endif
