# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <string>

class FragTrap
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
		FragTrap(std::string name);
		~FragTrap();
		void    rangedAttack(std::string const &target);
		void    meleeAttack(std::string const &target);
		void    takeDamage(int amount);
		void    beRepaired(int amout);
		void	vaulthunter_dot_exe(std::string const & target);
};

# endif
