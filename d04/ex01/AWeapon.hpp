# ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

#include <string>

class AWeapon
{
	protected:
		std::string	_name;
		int	_apcost;
		int	_damage;
	public:
		AWeapon(std::string const &name, int apcost, int damage);
		virtual ~AWeapon();
		AWeapon &operator=(const AWeapon &aWeapon);
		std::string	getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;
};

# endif
