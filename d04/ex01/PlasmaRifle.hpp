# ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

#include "AWeapon.hpp"
#include <string>

class PlasmaRifle : public AWeapon
{
	private:
	public:
		PlasmaRifle(/* args */);
		~PlasmaRifle();
		PlasmaRifle &operator=(const PlasmaRifle &p);

		void	attack() const;
};

# endif
