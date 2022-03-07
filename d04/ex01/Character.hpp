# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

#include <iostream>

class Character
{
	private:
		std::string	_name;
		int	_ap;
		int	_hp;
		AWeapon *_aweapon;
		Enemy *_enemy;
	public:
		Character(std::string const &name);
		~Character();
		Character &operator=(const Character &c);

		std::string	getName() const;
		int	getAPCost() const;
		int	getHP() const;
		AWeapon	*getAWeapon() const;

		void	recoverAP();
		void	equip(AWeapon *aweapon);
		void	attack(Enemy *enemy);
};

std::ostream &operator<<(std::ostream &os, const Character &c);

# endif