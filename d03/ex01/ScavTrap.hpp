# ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <string>

class ScavTrap
{
	private:
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
		void    _funny1(std::string const &target);
		void    _funny2(std::string const &target);
		void    _funny3(std::string const &target);
		void    _funny4(std::string const &target);
		void    _funny5(std::string const &target);
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void    rangedAttack(std::string const &target);
		void    meleeAttack(std::string const &target);
		void    takeDamage(int amount);
		void    beRepaired(int amout);
		void	challengeNewcomer(std::string const &target);
};

# endif
