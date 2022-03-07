# ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	protected:
	public:
		Cure();
		~Cure();
		Cure &operator=(Cure const &Cure);

		AMateria*	clone() const;
};

# endif
