# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;
		unsigned int	_xp;
	public:
		AMateria(std::string const &type);
		~AMateria();
		AMateria &operator=(AMateria const &a);

		std::string const	&getType() const;
		unsigned int		getXP() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);
};

# endif
