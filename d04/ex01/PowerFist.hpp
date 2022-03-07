# ifndef POWER_FIST_HPP
# define POWER_FIST_HPP

#include "AWeapon.hpp"
#include <string>

class PowerFist : public AWeapon
{
	private:
	public:
		PowerFist();
		~PowerFist();
		PowerFist &operator=(const PowerFist &p);

		void	attack() const;
};

# endif
