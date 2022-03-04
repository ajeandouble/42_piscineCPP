# ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		int _hit_points;
		int _max_hit_points;
		int _energy_points;
		int _max_energy_points;
		unsigned int    _level;
		std::string _name;
		int _melee_attack_damage;
		int _ranged_attack_damage;
		int _armor_damage_reduction;
		int _random(int min, int max);
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void    rangedAttack(std::string const &target);
		void    meleeAttack(std::string const &target);
		void    takeDamage(int amount);
		void    beRepaired(int amout);
};

# endif
