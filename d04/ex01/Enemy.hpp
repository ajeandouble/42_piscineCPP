# ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class	Enemy
{
	protected:
		std::string	_type;
		int	_hp;
	public:
		Enemy(int hp, std::string const &type);
		~Enemy();
		Enemy &operator=(const Enemy &e);

		std::string	getType() const;
		int	getHP() const;

		virtual void takeDamage(int);
};

# endif
